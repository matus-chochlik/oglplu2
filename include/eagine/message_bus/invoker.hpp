/**
 *  @file eagine/message_bus/invoker.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

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
template <
  typename Signature,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class callback_invoker {
    using _callback_t =
      callable_ref<void(std::remove_cv_t<std::remove_reference_t<
                          std::invoke_result_t<Signature>>>)>;

public:
    callback_invoker() noexcept = default;
    callback_invoker(callable_ref<Signature> callback) noexcept
      : _callback{callback} {}

    template <typename Class, typename RV, typename... P>
    auto operator()(
      Class* that,
      RV (Class::*func)(P...) noexcept(
        is_noexcept_function_v<Signature>)) noexcept -> callback_invoker& {
        _callback = _callback_t{that, func};
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

        block_data_sink sink(buffer);
        Serializer write_backend(sink);

        const auto errors = serialize(tupl, write_backend);
        if(!errors) {
            message_view message{sink.done()};
            message.set_serializer_id(write_backend.type_id());
            message.set_target_id(target_id);
            bus.send(msg_id, message);

            return true;
        }
        return false;
    }

    auto fulfill_by(stored_message& message) -> bool {
        std::remove_cv_t<std::remove_reference_t<std::invoke_result_t<Signature>>>
          result{};

        block_data_source source(message.content());
        Deserializer read_backend(source);

        if(message.has_serializer_id(read_backend.type_id())) {
            const auto errors{deserialize(result, read_backend)};
            if(!errors) {
                _callback(std::move(result));
            }
        }
        return true;
    }

    constexpr auto map_fulfill_by(message_id msg_id) noexcept {
        return std::tuple<
          callback_invoker*,
          message_handler_map<EAGINE_MEM_FUNC_T(callback_invoker, fulfill_by)>>(
          this, msg_id);
    }

    constexpr auto operator[](message_id msg_id) noexcept {
        return map_fulfill_by(msg_id);
    }

private:
    _callback_t _callback{};
};
//------------------------------------------------------------------------------
template <
  typename Result,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class invoker_base {
public:
    auto fulfill_by(stored_message& message) -> bool {
        const auto invocation_id = message.sequence_no;
        std::remove_cv_t<std::remove_reference_t<Result>> result{};

        block_data_source source(message.content());
        Deserializer read_backend(source);

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
};
//------------------------------------------------------------------------------
template <
  typename Signature,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class invoker;
//------------------------------------------------------------------------------
template <
  typename Result,
  typename... Params,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class invoker<Result(Params...), Serializer, Deserializer, MaxDataSize>
  : public invoker_base<Result, Serializer, Deserializer, MaxDataSize> {
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
            bus.send(msg_id, message);

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
  std::size_t MaxDataSize>
class invoker<Result(), Serializer, Deserializer, MaxDataSize>
  : public invoker_base<Result, Serializer, Deserializer, MaxDataSize> {
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
        bus.send(msg_id, message);

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
