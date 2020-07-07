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

#include "../serialize/block_sink.hpp"
#include "../serialize/block_source.hpp"
#include "endpoint.hpp"
#include "serialize.hpp"
#include <array>
#include <tuple>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <
  typename Signature,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize = 8192 - 128>
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
      callable_ref<Result(Params...)> func) {
        std::tuple<std::remove_cv_t<std::remove_reference_t<Params>>...> tupl{};

        block_data_source source(msg_in.content());
        Deserializer read_backend(source);

        if(msg_in.has_serializer_id(read_backend.type_id())) {
            const auto read_errors = deserialize(tupl, read_backend);
            if(!read_errors) {
                const auto result{std::apply(func, tupl)};
                std::array<byte, MaxDataSize> buffer{};
                block_data_sink sink(cover(buffer));
                Serializer write_backend(sink);

                const auto errors = serialize(result, write_backend);
                if(!errors) {
                    message_view msg_out{sink.done()};
                    msg_out.set_serializer_id(write_backend.type_id());
                    bus.respond_to(msg_in, msg_id, msg_out);
                    return true;
                }
            }
        }
        return false;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SKELETON_HPP

