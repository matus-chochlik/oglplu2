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

#include "../serialize/block_sink.hpp"
#include "../serialize/block_source.hpp"
#include "endpoint.hpp"
#include "future.hpp"
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
class invoker;
//------------------------------------------------------------------------------
template <
  typename Result,
  typename... Params,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class invoker<Result(Params...), Serializer, Deserializer, MaxDataSize> {
public:
    future<Result> invoke_on(
      endpoint& bus,
      identifier_t target_id,
      message_id msg_id,
      std::add_const_t<Params>... args) {
        auto [invocation_id, result] = _results.make();

        auto tupl{std::tie(args...)};

        std::array<byte, MaxDataSize> buffer{};
        block_data_sink sink(cover(buffer));
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

    future<Result> invoke(
      endpoint& bus, message_id msg_id, std::add_const_t<Params>... args) {
        return invoke_on(bus, broadcast_endpoint_id(), msg_id, args...);
    }

    void fulfill_by(const stored_message& message) {
        const auto invocation_id = message.sequence_no;
        std::remove_cv_t<std::remove_reference_t<Result>> result{};

        block_data_source source(message.content());
        Deserializer read_backend(source);

        if(message.has_serializer_id(read_backend.type_id())) {
            const auto errors = deserialize(result, read_backend);
            if(!errors) {
                _results.fulfill(invocation_id, result);
            }
        }
    }

    bool has_pending() const noexcept {
        return _results.has_some();
    }

    bool is_done() const noexcept {
        return _results.has_none();
    }

private:
    pending_promises<Result> _results{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_INVOKER_HPP

