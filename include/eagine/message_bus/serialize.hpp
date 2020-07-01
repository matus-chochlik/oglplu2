/**
 *  @file eagine/message_bus/serialize.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SERIALIZE_HPP
#define EAGINE_MESSAGE_BUS_SERIALIZE_HPP

#include "../extract.hpp"
#include "../message_id.hpp"
#include "../serialize/block_sink.hpp"
#include "../serialize/block_source.hpp"
#include "../serialize/read.hpp"
#include "../serialize/string_backend.hpp"
#include "../serialize/write.hpp"
#include "message.hpp"
#include <array>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
using default_serializer_backend = string_serializer_backend;
using default_deserializer_backend = string_deserializer_backend;
//------------------------------------------------------------------------------
template <typename Backend>
std::enable_if_t<
  std::is_base_of_v<serializer_backend, Backend>,
  serialization_errors>
serialize_message(
  message_id msg_id, const message_view& msg, Backend& backend) {

    auto message_params = std::make_tuple(
      msg_id.class_(),
      msg_id.method(),
      msg.source_id,
      msg.target_id,
      msg.serializer_id,
      msg.sequence_no,
      msg.hop_count,
      msg.priority,
      msg.crypto_flags);
    serialization_errors errors = serialize(message_params, backend);

    if(!errors) {
        if(auto sink = backend.sink()) {
            errors |= extract(sink).write(msg.data);
        } else {
            errors |= serialization_error_code::backend_error;
        }
    }

    return errors;
}
//------------------------------------------------------------------------------
template <typename Backend>
std::enable_if_t<
  std::is_base_of_v<deserializer_backend, Backend>,
  deserialization_errors>
deserialize_message(
  identifier& class_id,
  identifier& method_id,
  stored_message& msg,
  Backend& backend) {

    auto message_params = std::tie(
      class_id,
      method_id,
      msg.source_id,
      msg.target_id,
      msg.serializer_id,
      msg.sequence_no,
      msg.hop_count,
      msg.priority,
      msg.crypto_flags);
    deserialization_errors errors = deserialize(message_params, backend);

    if(!errors) {
        if(auto source = backend.source()) {
            msg.fetch_all_from(extract(source));
        } else {
            errors |= deserialization_error_code::backend_error;
        }
    }

    return errors;
}
//------------------------------------------------------------------------------
template <typename Backend>
std::enable_if_t<
  std::is_base_of_v<deserializer_backend, Backend>,
  deserialization_errors>
deserialize_message(message_id& msg_id, stored_message& msg, Backend& backend) {
    identifier class_id{};
    identifier method_id{};
    deserialization_errors errors =
      deserialize_message(class_id, method_id, msg, backend);
    if(!errors) {
        msg_id = {class_id, method_id};
    }
    return errors;
}
//------------------------------------------------------------------------------
// default_serialize
//------------------------------------------------------------------------------
template <typename T>
inline serialization_result<memory::const_block> default_serialize(
  T& value, memory::block blk) {
    block_data_sink sink(blk);
    default_serializer_backend backend(sink);
    auto errors = serialize(value, backend);
    return {sink.done(), errors};
}
//------------------------------------------------------------------------------
inline auto default_serialize_message_type(
  message_id msg_id, memory::block blk) {
    const auto value{msg_id.id_tuple()};
    return default_serialize(value, blk);
}
//------------------------------------------------------------------------------
// default_deserialize
//------------------------------------------------------------------------------
template <typename T>
inline deserialization_result<memory::const_block> default_deserialize(
  T& value, memory::const_block blk) {
    block_data_source source(blk);
    default_deserializer_backend backend(source);
    auto errors = deserialize(value, backend);
    return {source.remaining(), errors};
}
//------------------------------------------------------------------------------
inline auto default_deserialize_message_type(
  message_id& msg_id, memory::const_block blk) {
    std::tuple<identifier, identifier> value{};
    auto result = default_deserialize(value, blk);
    if(result) {
        msg_id = {value};
    }
    return result;
}
//------------------------------------------------------------------------------
template <typename Backend, typename Value>
inline bool stored_message::do_store_value(
  const Value& value, span_size_t max_size) {
    _buffer.resize(max_size);
    block_data_sink sink(cover(_buffer));
    Backend backend(sink);
    auto errors = serialize(value, backend);
    if(!errors) {
        set_serializer_id(backend.type_id());
        _buffer.resize(sink.done().size());
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
template <typename Value>
inline bool stored_message::store_value(
  const Value& value, span_size_t max_size) {
    return do_store_value<default_serializer_backend>(value, max_size);
}
//------------------------------------------------------------------------------
template <typename Backend, typename Value>
inline bool stored_message::do_fetch_value(Value& value) {
    block_data_source source(view(_buffer));
    Backend backend(source);
    auto errors = deserialize(value, backend);
    return !errors;
}
//------------------------------------------------------------------------------
template <typename Value>
inline bool stored_message::fetch_value(Value& value) {
    return do_fetch_value<default_deserializer_backend>(value);
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERIALIZE_HPP

