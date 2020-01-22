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
#include "../serialize/block_sink.hpp"
#include "../serialize/block_source.hpp"
#include "../serialize/read.hpp"
#include "../serialize/string_backend.hpp"
#include "../serialize/write.hpp"
#include "message.hpp"
#include <array>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
using default_serializer_backend = string_serializer_backend;
using default_deserializer_backend = string_deserializer_backend;
//------------------------------------------------------------------------------
template <typename Backend>
std::enable_if_t<
  std::is_base_of_v<serializer_backend, Backend>,
  serialization_errors>
serialize_message(
  identifier_t class_id,
  identifier_t method_id,
  const message_view& msg,
  Backend& backend) {

    auto message_params = std::make_tuple(
      identifier(class_id),
      identifier(method_id),
      msg.source_id,
      msg.target_id,
      msg.serializer_id,
      msg.priority,
      msg.hop_count);
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
template <identifier_t ClassId, identifier_t MethodId, typename Backend>
std::enable_if_t<
  std::is_base_of_v<serializer_backend, Backend>,
  serialization_errors>
serialize_message(
  message_id<ClassId, MethodId>, const message_view& msg, Backend& backend) {
    return serialize_message(ClassId, MethodId, msg, backend);
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
      msg.priority,
      msg.hop_count);
    deserialization_errors errors = deserialize(message_params, backend);

    if(!errors) {
        if(auto source = backend.source()) {
            msg.data.clear();
            extract(source).fetch_all(msg.data);
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
deserialize_message(
  identifier_t& class_id,
  identifier_t& method_id,
  stored_message& msg,
  Backend& backend) {
    identifier class_ident{};
    identifier method_ident{};
    deserialization_errors errors =
      deserialize_message(class_ident, method_ident, msg, backend);
    if(!errors) {
        class_id = class_ident.value();
        method_id = method_ident.value();
    }
    return errors;
}
//------------------------------------------------------------------------------
// default_serialize
//------------------------------------------------------------------------------
template <typename T>
serialization_result<memory::const_block> default_serialize(
  T& value, memory::block blk) {
    block_data_sink sink(blk);
    default_serializer_backend backend(sink);
    auto errors = serialize(value, backend);
    return {sink.done(), errors};
}
//------------------------------------------------------------------------------
auto default_serialize(identifier_t class_id, identifier_t method_id) {
    auto value{std::tie(class_id, method_id)};
    std::array<byte, 64> temp{};
    return default_serialize(value, cover(temp));
}
//------------------------------------------------------------------------------
// default_deserialize
//------------------------------------------------------------------------------
template <typename T>
deserialization_result<memory::const_block> default_deserialize(
  T& value, memory::const_block blk) {
    block_data_source source(blk);
    default_deserializer_backend backend(source);
    auto errors = deserialize(value, backend);
    return {source.remaining(), errors};
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_SERIALIZE_HPP

