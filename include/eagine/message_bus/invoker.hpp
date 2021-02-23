/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_INVOKER_HPP
#define EAGINE_MESSAGE_BUS_INVOKER_HPP

#include "../callable_ref.hpp"
#include "../serialize/block_sink.hpp"
#include "../serialize/block_source.hpp"
#include "endpoint.hpp"
#include "future.hpp"
#include "handler_map.hpp"
#include "serialize.hpp"
#include <array>
#include <tuple>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class result_context {
public:
    result_context(
      const message_context& msg_ctx,
      identifier_t src_id,
      message_sequence_t invc_id) noexcept
      : _msg_ctx{msg_ctx}
      , _source_id{src_id}
      , _invocation_id{invc_id} {}

    auto msg_context() const noexcept -> const message_context& {
        return _msg_ctx;
    }

    auto source_id() const noexcept {
        return _source_id;
    }

    auto invocation_id() const noexcept {
        return _invocation_id;
    }

private:
    const message_context& _msg_ctx;
    identifier_t _source_id{0U};
    message_sequence_t _invocation_id{0};
};
//------------------------------------------------------------------------------
template <typename Result, typename Deserializer, typename Source, bool NoExcept>
class callback_invoker_base {

public:
    auto fulfill_by(const message_context& msg_ctx, stored_message& response)
      -> bool {
        Result result{};

        _source.reset(response.content());
        Deserializer read_backend(_source);

        if(response.has_serializer_id(read_backend.type_id())) {
            const auto errors{deserialize(result, read_backend)};
            if(!errors) {
                const result_context res_ctx{
                  msg_ctx, response.source_id, response.sequence_no};
                _callback(res_ctx, std::move(result));
            }
        }
        return true;
    }

protected:
    using _callback_t =
      callable_ref<void(const result_context&, Result&&) noexcept(NoExcept)>;
    _callback_t _callback{};

private:
    Source _source{};
};
//------------------------------------------------------------------------------
template <typename Deserializer, typename Source, bool NoExcept>
class callback_invoker_base<void, Deserializer, Source, NoExcept> {

public:
    auto fulfill_by(const message_context& msg_ctx, stored_message& response)
      -> bool {
        const result_context res_ctx{
          msg_ctx, response.source_id, response.sequence_no};
        _callback();
        return true;
    }

protected:
    using _callback_t = basic_callable_ref<void() noexcept(NoExcept), NoExcept>;
    _callback_t _callback{};
};
//------------------------------------------------------------------------------
template <
  typename Signature,
  typename Serializer,
  typename Deserializer,
  typename Sink,
  typename Source,
  std::size_t MaxDataSize>
class callback_invoker
  : public callback_invoker_base<
      std::remove_cv_t<std::remove_reference_t<std::invoke_result_t<Signature>>>,
      Deserializer,
      Source,
      is_noexcept_function_v<Signature>> {

    using _result_t =
      std::remove_cv_t<std::remove_reference_t<std::invoke_result_t<Signature>>>;
    using base = callback_invoker_base<
      _result_t,
      Deserializer,
      Source,
      is_noexcept_function_v<Signature>>;
    using _callback_t = typename base::_callback_t;

public:
    using base::base;

    template <typename Class, typename MfcT, MfcT Mfc>
    auto operator()(Class* that, member_function_constant<MfcT, Mfc> func)
      -> callback_invoker& {
        this->_callback = _callback_t{that, func};
        return *this;
    }

    template <typename Class, typename MfcT, MfcT Mfc>
    auto operator()(const Class* that, member_function_constant<MfcT, Mfc> func)
      -> callback_invoker& {
        this->_callback = _callback_t{that, func};
        return *this;
    }

    template <typename... Args>
    auto invoke_on(
      endpoint& bus,
      identifier_t target_id,
      message_id msg_id,
      memory::block buffer,
      Args&&... args) -> bool {
        auto tupl{std::tie(std::forward<Args>(args)...)};

        _sink.reset(buffer);
        Serializer write_backend(_sink);

        const auto errors = serialize(tupl, write_backend);
        if(!errors) {
            message_view message{_sink.done()};
            message.set_serializer_id(write_backend.type_id());
            message.set_target_id(target_id);
            bus.post(msg_id, message);

            return true;
        }
        return false;
    }

    template <typename... Args>
    auto invoke_on(
      endpoint& bus,
      identifier_t target_id,
      message_id msg_id,
      Args&&... args) -> bool {
        std::array<byte, MaxDataSize> temp{};
        return invoke_on(
          bus, target_id, msg_id, cover(temp), std::forward<Args>(args)...);
    }

    constexpr auto map_fulfill_by(message_id msg_id) noexcept {
        return std::
          tuple<base*, message_handler_map<EAGINE_MEM_FUNC_T(base, fulfill_by)>>(
            this, msg_id);
    }

    constexpr auto operator[](message_id msg_id) noexcept {
        return map_fulfill_by(msg_id);
    }

private:
    Sink _sink{};
};
//------------------------------------------------------------------------------
template <typename Result, typename Deserializer, typename Source>
class invoker_base {
public:
    auto fulfill_by(const message_context&, stored_message& message) -> bool {
        const auto invocation_id = message.sequence_no;
        std::remove_cv_t<std::remove_reference_t<Result>> result{};

        _source.reset(message.content());
        Deserializer read_backend(_source);

        if(message.has_serializer_id(read_backend.type_id())) {
            const auto errors{deserialize(result, read_backend)};
            if(!errors) {
                _results.fulfill(invocation_id, result);
            }
        }
        return true;
    }

    constexpr auto map_fulfill_by(message_id msg_id) noexcept {
        return std::tuple<
          invoker_base*,
          message_handler_map<EAGINE_MEM_FUNC_T(invoker_base, fulfill_by)>>(
          this, msg_id);
    }

    constexpr auto operator[](message_id msg_id) noexcept {
        return map_fulfill_by(msg_id);
    }

    auto has_pending() const noexcept -> bool {
        return _results.has_some();
    }

    auto is_done() const noexcept -> bool {
        return _results.has_none();
    }

protected:
    pending_promises<Result> _results{};

private:
    Source _source{};
};
//------------------------------------------------------------------------------
template <
  typename Signature,
  typename Serializer,
  typename Deserializer,
  typename Sink,
  typename Source,
  std::size_t MaxDataSize>
class invoker;
//------------------------------------------------------------------------------
template <
  typename Result,
  typename... Params,
  typename Serializer,
  typename Deserializer,
  typename Sink,
  typename Source,
  std::size_t MaxDataSize>
class invoker<Result(Params...), Serializer, Deserializer, Sink, Source, MaxDataSize>
  : public invoker_base<Result, Deserializer, Source> {
public:
    auto invoke_on(
      endpoint& bus,
      identifier_t target_id,
      message_id msg_id,
      memory::block buffer,
      std::add_lvalue_reference_t<std::add_const_t<Params>>... args)
      -> future<Result> {
        auto [invocation_id, result] = this->_results.make();

        auto tupl{std::tie(args...)};

        block_data_sink sink(buffer);
        Serializer write_backend(sink);

        const auto errors = serialize(tupl, write_backend);
        if(!errors) {
            message_view message{sink.done()};
            message.set_serializer_id(write_backend.type_id());
            message.set_target_id(target_id);
            message.set_sequence_no(invocation_id);
            bus.post(msg_id, message);

            return result;
        }
        return nothing;
    }

    auto invoke_on(
      endpoint& bus,
      identifier_t target_id,
      message_id msg_id,
      std::add_lvalue_reference_t<std::add_const_t<Params>>... args)
      -> future<Result> {
        std::array<byte, MaxDataSize> buffer{};
        return invoke_on(bus, target_id, msg_id, cover(buffer), args...);
    }

    auto invoke(
      endpoint& bus,
      message_id msg_id,
      std::add_lvalue_reference_t<std::add_const_t<Params>>... args)
      -> future<Result> {
        return invoke_on(bus, broadcast_endpoint_id(), msg_id, args...);
    }
};
//------------------------------------------------------------------------------
template <
  typename Result,
  typename Serializer,
  typename Deserializer,
  typename Sink,
  typename Source,
  std::size_t MaxDataSize>
class invoker<Result(), Serializer, Deserializer, Sink, Source, MaxDataSize>
  : public invoker_base<Result, Deserializer, Source> {
public:
    auto invoke_on(
      endpoint& bus,
      identifier_t target_id,
      message_id msg_id,
      memory::block) -> future<Result> {
        auto [invocation_id, result] = this->_results.make();

        message_view message{};
        message.set_target_id(target_id);
        message.set_sequence_no(invocation_id);
        bus.post(msg_id, message);

        return result;
    }

    auto invoke_on(endpoint& bus, identifier_t target_id, message_id msg_id)
      -> future<Result> {
        return invoke_on(bus, target_id, msg_id, {});
    }

    auto invoke(endpoint& bus, message_id msg_id) -> future<Result> {
        return invoke_on(bus, broadcast_endpoint_id(), msg_id);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_INVOKER_HPP
