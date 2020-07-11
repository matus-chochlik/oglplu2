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
class skeleton;
//------------------------------------------------------------------------------
template <
  typename Result,
  typename... Params,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class skeleton<Result(Params...), Serializer, Deserializer, MaxDataSize> {
public:
    bool call(
      endpoint& bus,
      const stored_message& msg_in,
      message_id msg_id,
      memory::block buffer,
      callable_ref<Result(Params...)> func) {
        std::tuple<std::remove_cv_t<std::remove_reference_t<Params>>...> tupl{};

        block_data_source source(msg_in.content());
        Deserializer read_backend(source);

        if(msg_in.has_serializer_id(read_backend.type_id())) {
            const auto read_errors = deserialize(tupl, read_backend);
            if(!read_errors) {
                const auto result{std::apply(func, tupl)};
                block_data_sink sink(buffer);
                Serializer write_backend(sink);

                const auto errors = serialize(result, write_backend);
                EAGINE_ASSERT(!errors);
                message_view msg_out{sink.done()};
                msg_out.set_serializer_id(write_backend.type_id());
                bus.respond_to(msg_in, msg_id, msg_out);
                return true;
            }
        }
        return false;
    }

    bool call(
      endpoint& bus,
      const stored_message& msg_in,
      message_id msg_id,
      callable_ref<Result(Params...)> func) {
        std::array<byte, MaxDataSize> buffer{};
        return call(bus, msg_in, msg_id, cover(buffer), func);
    }
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
      : _default_timeout{default_timeout} {
    }

    bool enqueue(
      const stored_message& msg_in,
      message_id msg_id,
      callable_ref<Result(Params...)> func) {
        auto [pos, emplaced] = _pending.try_emplace(msg_in.sequence_no);

        if(emplaced) {
            block_data_source source(msg_in.content());
            Deserializer read_backend(source);

            if(msg_in.has_serializer_id(read_backend.type_id())) {
                auto& call = pos->second;
                const auto read_errors = deserialize(call.args, read_backend);
                if(!read_errors) {
                    call.too_late.reset(_default_timeout);
                    call.msg_id = msg_id;
                    call.invoker_id = msg_in.source_id;
                    call.func = func;
                    return true;
                }
            }
            _pending.erase(pos);
        }
        return false;
    }

    bool handle_one(endpoint& bus, memory::block buffer) {
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
                message_view msg_out{sink.done()};
                msg_out.set_serializer_id(write_backend.type_id());
                msg_out.set_target_id(call.invoker_id);
                msg_out.set_sequence_no(invocation_id);
                bus.send(call.msg_id, msg_out);
                break;
            }
        }
        if(bgn != pos) {
            _pending.erase(bgn, pos);
            return true;
        }
        return false;
    }

    bool handle_one(endpoint& bus) {
        std::array<byte, MaxDataSize> buffer{};
        return handle_one(bus, cover(buffer));
    }

private:
    std::chrono::milliseconds _default_timeout{1000};

    struct lazy_call {
        message_id msg_id{};
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

    bool enqueue(
      const stored_message& msg_in,
      message_id msg_id,
      callable_ref<Result(Params...)> func,
      workshop& workers) {
        auto [pos, emplaced] = _pending.try_emplace(msg_in.sequence_no);

        if(emplaced) {
            block_data_source source(msg_in.content());
            Deserializer read_backend(source);

            if(msg_in.has_serializer_id(read_backend.type_id())) {
                auto& call = pos->second;
                const auto read_errors = deserialize(call.args, read_backend);
                if(!read_errors) {
                    call.msg_id = msg_id;
                    call.invoker_id = msg_in.source_id;
                    call.func = func;
                    workers.enqueue(call);
                    return true;
                }
            }
            _pending.erase(pos);
        }
        return false;
    }

    bool handle_one(endpoint& bus, memory::block buffer) {
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
                    bus.send(call.msg_id, msg_out);
                }
                _pending.erase(pos);
                return true;
            }
            ++pos;
        }
        return false;
    }

    bool handle_one(endpoint& bus) {
        std::array<byte, MaxDataSize> buffer{};
        return handle_one(bus, cover(buffer));
    }

private:
    struct async_call : work_unit {
        message_id msg_id{};
        std::tuple<std::remove_cv_t<std::remove_reference_t<Params>>...> args{};
        Result result{};
        callable_ref<Result(Params...)> func{};
        identifier_t invoker_id{};
        bool finished{false};

        bool do_it() final {
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

