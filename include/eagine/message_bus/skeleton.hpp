/**
 *  @file eagine/message_bus/skeleton.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SKELETON_HPP
#define EAGINE_MESSAGE_BUS_SKELETON_HPP

#include "../callable_ref.hpp"
#include "../flat_map.hpp"
#include "../serialize/block_sink.hpp"
#include "../serialize/block_source.hpp"
#include "../workshop.hpp"
#include "endpoint.hpp"
#include "serialize.hpp"
#include <array>
#include <map>
#include <tuple>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <
  typename Signature,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class skeleton {
public:
    auto call(
      const message_context& msg_ctx,
      const stored_message& request,
      message_id response_id,
      memory::block buffer,
      callable_ref<Signature> func) -> bool {
        return _do_call(
          msg_ctx, request, response_id, buffer, func, func.argument_tuple());
    }

    auto call(
      const message_context& msg_ctx,
      const stored_message& request,
      message_id response_id,
      callable_ref<Signature> func) -> bool {
        std::array<byte, MaxDataSize> buffer{};
        return call(msg_ctx, request, response_id, cover(buffer), func);
    }

private:
    template <typename... Params>
    auto _do_call(
      const message_context& msg_ctx,
      const stored_message& request,
      message_id response_id,
      memory::block buffer,
      callable_ref<Signature> func,
      std::tuple<Params...> args) -> bool {

        block_data_source source(request.content());
        Deserializer read_backend(source);

        if(request.has_serializer_id(read_backend.type_id())) {
            const auto read_errors = deserialize(args, read_backend);
            if(!read_errors) {
                const auto result{std::apply(func, args)};
                block_data_sink sink(buffer);
                Serializer write_backend(sink);

                const auto errors = serialize(result, write_backend);
                EAGINE_ASSERT(!errors);
                EAGINE_MAYBE_UNUSED(errors);
                message_view msg_out{sink.done()};
                msg_out.set_serializer_id(write_backend.type_id());
                msg_ctx.bus().respond_to(request, response_id, msg_out);
                return true;
            }
        }
        return false;
    }

    auto _do_call(
      const message_context& msg_ctx,
      const stored_message& request,
      message_id response_id,
      memory::block buffer,
      callable_ref<Signature> func,
      std::tuple<>) -> bool {

        const auto result{func()};
        block_data_sink sink(buffer);
        Serializer write_backend(sink);

        const auto errors = serialize(result, write_backend);
        EAGINE_ASSERT(!errors);
        EAGINE_MAYBE_UNUSED(errors);
        message_view msg_out{sink.done()};
        msg_out.set_serializer_id(write_backend.type_id());
        msg_ctx.bus().respond_to(request, response_id, msg_out);
        return true;
    }
};
//------------------------------------------------------------------------------
template <
  typename Signature,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class function_skeleton
  : public skeleton<Signature, Serializer, Deserializer, MaxDataSize> {

    using _function_t = callable_ref<Signature>;

public:
    function_skeleton() noexcept = default;

    function_skeleton(
      message_id response_id,
      callable_ref<Signature> function) noexcept
      : _response_id{std::move(response_id)}
      , _function{std::move(function)} {}

    template <typename Class, typename MfcT, MfcT Mfc>
    auto operator()(
      message_id response_id,
      Class* that,
      member_function_constant<MfcT, Mfc> func) -> function_skeleton& {
        _response_id = std::move(response_id);
        _function = _function_t{that, func};
        return *this;
    }

    template <typename Class, typename MfcT, MfcT Mfc>
    auto operator()(
      message_id response_id,
      const Class* that,
      member_function_constant<MfcT, Mfc> func) -> function_skeleton& {
        _response_id = std::move(response_id);
        _function = _function_t{that, func};
        return *this;
    }

    auto invoke_by(const message_context& msg_ctx, stored_message& request)
      -> bool {
        return this->call(msg_ctx.bus(), request, _response_id, _function);
    }

    constexpr auto map_invoke_by(message_id msg_id) noexcept {
        return std::tuple<
          function_skeleton*,
          message_handler_map<EAGINE_MEM_FUNC_T(function_skeleton, invoke_by)>>(
          this, msg_id);
    }

    constexpr auto operator[](message_id msg_id) noexcept {
        return map_invoke_by(msg_id);
    }

private:
    message_id _response_id{};
    _function_t _function{};
};
//------------------------------------------------------------------------------
template <
  typename Signature,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class lazy_skeleton;
//------------------------------------------------------------------------------
template <
  typename Result,
  typename... Params,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class lazy_skeleton<Result(Params...), Serializer, Deserializer, MaxDataSize> {
public:
    using id_t = message_sequence_t;

    lazy_skeleton() noexcept = default;

    template <typename R, typename P>
    lazy_skeleton(std::chrono::duration<R, P> default_timeout) noexcept
      : _default_timeout{default_timeout} {}

    auto enqueue(
      const stored_message& request,
      message_id response_id,
      callable_ref<Result(Params...)> func) -> bool {
        auto [pos, emplaced] = _pending.try_emplace(request.sequence_no);

        if(emplaced) {
            block_data_source source(request.content());
            Deserializer read_backend(source);

            if(request.has_serializer_id(read_backend.type_id())) {
                auto& call = pos->second;
                const auto read_errors = deserialize(call.args, read_backend);
                if(!read_errors) {
                    call.too_late.reset(_default_timeout);
                    call.response_id = response_id;
                    call.invoker_id = request.source_id;
                    call.func = func;
                    return true;
                }
            }
            _pending.erase(pos);
        }
        return false;
    }

    auto handle_one(endpoint& bus, memory::block buffer) -> bool {
        const auto bgn = _pending.begin();
        auto pos = bgn;
        while(pos != _pending.end()) {
            const auto invocation_id = pos->first;
            const auto& call = pos->second;
            ++pos;
            if(!call.too_late) {
                const auto result{std::apply(call.func, call.args)};
                block_data_sink sink(cover(buffer));
                Serializer write_backend(sink);

                const auto errors = serialize(result, write_backend);
                EAGINE_ASSERT(!errors);
                EAGINE_MAYBE_UNUSED(errors);
                message_view msg_out{sink.done()};
                msg_out.set_serializer_id(write_backend.type_id());
                msg_out.set_target_id(call.invoker_id);
                msg_out.set_sequence_no(invocation_id);
                bus.send(call.response_id, msg_out);
                break;
            }
        }
        if(bgn != pos) {
            _pending.erase(bgn, pos);
            return true;
        }
        return false;
    }

    auto handle_one(endpoint& bus) -> bool {
        std::array<byte, MaxDataSize> buffer{};
        return handle_one(bus, cover(buffer));
    }

private:
    std::chrono::milliseconds _default_timeout{1000};

    struct lazy_call {
        message_id response_id{};
        std::tuple<std::remove_cv_t<std::remove_reference_t<Params>>...> args{};
        callable_ref<Result(Params...)> func{};
        timeout too_late{};
        identifier_t invoker_id{};
    };

    flat_map<id_t, lazy_call> _pending{};
};
//------------------------------------------------------------------------------
template <
  typename Signature,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class async_skeleton;
//------------------------------------------------------------------------------
template <
  typename Result,
  typename... Params,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class async_skeleton<Result(Params...), Serializer, Deserializer, MaxDataSize> {
public:
    using id_t = message_sequence_t;

    async_skeleton() noexcept = default;

    auto enqueue(
      const stored_message& request,
      message_id response_id,
      callable_ref<Result(Params...)> func,
      workshop& workers) -> bool {
        auto [pos, emplaced] = _pending.try_emplace(request.sequence_no);

        if(emplaced) {
            block_data_source source(request.content());
            Deserializer read_backend(source);

            if(request.has_serializer_id(read_backend.type_id())) {
                auto& call = pos->second;
                const auto read_errors = deserialize(call.args, read_backend);
                if(!read_errors) {
                    call.response_id = response_id;
                    call.invoker_id = request.source_id;
                    call.func = func;
                    workers.enqueue(call);
                    return true;
                }
            }
            _pending.erase(pos);
        }
        return false;
    }

    auto handle_one(endpoint& bus, memory::block buffer) -> bool {
        const auto bgn = _pending.begin();
        auto pos = bgn;
        while(pos != _pending.end()) {
            const auto invocation_id = pos->first;
            const auto& call = pos->second;
            if(call.finished) {
                block_data_sink sink(buffer);
                Serializer write_backend(sink);

                const auto errors = serialize(call.result, write_backend);
                if(!errors) {
                    message_view msg_out{sink.done()};
                    msg_out.set_serializer_id(write_backend.type_id());
                    msg_out.set_target_id(call.invoker_id);
                    msg_out.set_sequence_no(invocation_id);
                    bus.send(call.response_id, msg_out);
                }
                _pending.erase(pos);
                return true;
            }
            ++pos;
        }
        return false;
    }

    auto handle_one(endpoint& bus) -> bool {
        std::array<byte, MaxDataSize> buffer{};
        return handle_one(bus, cover(buffer));
    }

private:
    struct async_call : work_unit {
        message_id response_id{};
        std::tuple<std::remove_cv_t<std::remove_reference_t<Params>>...> args{};
        Result result{};
        callable_ref<Result(Params...)> func{};
        identifier_t invoker_id{};
        bool finished{false};

        auto do_it() -> bool final {
            result = std::apply(func, args);
            return true;
        }

        void deliver() final {
            finished = true;
        }
    };

    std::map<id_t, async_call> _pending{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SKELETON_HPP
