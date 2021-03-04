/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERIALIZE_HPP
#define EAGINE_MESSAGE_BUS_SERIALIZE_HPP

#include "../extract.hpp"
#include "../message_id.hpp"
#include "../serialize/block_sink.hpp"
#include "../serialize/block_source.hpp"
#include "../serialize/data_buffer.hpp"
#include "../serialize/packed_block_sink.hpp"
#include "../serialize/packed_block_source.hpp"
#include "../serialize/read.hpp"
#include "../serialize/string_backend.hpp"
#include "../serialize/write.hpp"
#include "message.hpp"
#include <array>

namespace eagine {

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, message_id, Selector>
  : get_serialize_buffer_size<Sid, message_id::base, Selector> {};
//------------------------------------------------------------------------------
namespace msgbus {

/// @brief Aloas for default serialization backend for bus messages.
/// @ingroup msgbus
/// @see default_deserializer_backend
using default_serializer_backend = string_serializer_backend;

/// @brief Aloas for default deserialization backend for bus messages.
/// @ingroup msgbus
/// @see default_serializer_backend
using default_deserializer_backend = string_deserializer_backend;

/// @brief Returns a suitable buffer for the serialization of the specified object.
/// @ingroup msgbus
template <typename T>
inline auto default_serialize_buffer_for(const T& inst) {
    return serialize_buffer_for<default_serializer_backend::id_value>(inst);
}
//------------------------------------------------------------------------------
/// @brief Serializes a bus message header with the specified serializer backend.
/// @ingroup msgbus
/// @see serialize_message
/// @see deserialize_message_header
template <typename Backend>
auto serialize_message_header(
  message_id msg_id,
  const message_view& msg,
  Backend& backend)
  -> std::enable_if_t<
    std::is_base_of_v<serializer_backend, Backend>,
    serialization_errors> {

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
    return serialize(message_params, backend);
}
//------------------------------------------------------------------------------
/// @brief Serializes a bus message with the specified serializer backend.
/// @ingroup msgbus
/// @see serialize_message_header
/// @see deserialize_message
/// @see default_serialize
template <typename Backend>
auto serialize_message(
  message_id msg_id,
  const message_view& msg,
  Backend& backend)
  -> std::enable_if_t<
    std::is_base_of_v<serializer_backend, Backend>,
    serialization_errors> {

    auto errors = serialize_message_header(msg_id, msg, backend);

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
/// @brief Deserializes a bus message header with the specified deserializer backend.
/// @ingroup msgbus
/// @see deserialize_message
/// @see serialize_message_header
template <typename Backend>
auto deserialize_message_header(
  identifier& class_id,
  identifier& method_id,
  stored_message& msg,
  Backend& backend)
  -> std::enable_if_t<
    std::is_base_of_v<deserializer_backend, Backend>,
    deserialization_errors> {

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
    return deserialize(message_params, backend);
}
//------------------------------------------------------------------------------
/// @brief Deserializes a bus message with the specified deserializer backend.
/// @ingroup msgbus
/// @see deserialize_message_header
/// @see serialize_message
/// @see default_deserialize
template <typename Backend>
auto deserialize_message(
  identifier& class_id,
  identifier& method_id,
  stored_message& msg,
  Backend& backend)
  -> std::enable_if_t<
    std::is_base_of_v<deserializer_backend, Backend>,
    deserialization_errors> {

    auto errors = deserialize_message_header(class_id, method_id, msg, backend);

    if(!errors) {
        if(auto source{backend.source()}) {
            msg.fetch_all_from(extract(source));
        } else {
            errors |= deserialization_error_code::backend_error;
        }
    }

    return errors;
}
//------------------------------------------------------------------------------
/// @brief Deserializes a bus message with the specified deserializer backend.
/// @ingroup msgbus
/// @see deserialize_message_header
/// @see serialize_message
template <typename Backend>
auto deserialize_message(
  message_id& msg_id,
  stored_message& msg,
  Backend& backend)
  -> std::enable_if_t<
    std::is_base_of_v<deserializer_backend, Backend>,
    deserialization_errors> {

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
/// @brief Uses the default backend to serialize a value into a memory block.
/// @see default_serializer_backend
/// @see default_serialize_packed
/// @see default_deserialize
/// @see serialize
template <typename T>
inline auto default_serialize(T& value, memory::block blk)
  -> serialization_result<memory::const_block> {
    block_data_sink sink(blk);
    default_serializer_backend backend(sink);
    auto errors = serialize(value, backend);
    return {sink.done(), errors};
}
//------------------------------------------------------------------------------
/// @brief Uses backend and compressor to serialize and pack a value into a memory block.
/// @see default_serializer_backend
/// @see default_serialize
/// @see default_deserialize_packed
/// @see data_compressor
/// @see serialize
template <typename T>
inline auto default_serialize_packed(
  T& value,
  memory::block blk,
  data_compressor compressor) -> serialization_result<memory::const_block> {
    packed_block_data_sink sink(std::move(compressor), blk);
    default_serializer_backend backend(sink);
    auto errors = serialize(value, backend);
    return {sink.done(), errors};
}
//------------------------------------------------------------------------------
/// @brief Default-serializes the specified message id into a memory block.
/// @ingroup msgbus
/// @see default_serializer_backend
/// @see default_serialize
/// @see message_id
inline auto
default_serialize_message_type(message_id msg_id, memory::block blk) {
    const auto value{msg_id.id_tuple()};
    return default_serialize(value, blk);
}
//------------------------------------------------------------------------------
// default_deserialize
//------------------------------------------------------------------------------
/// @brief Uses the default backend to deserialize a value from a memory block.
/// @see default_deserializer_backend
/// @see default_deserialize_packed
/// @see default_serialize
/// @see deserialize
template <typename T>
inline auto default_deserialize(T& value, memory::const_block blk)
  -> deserialization_result<memory::const_block> {
    block_data_source source(blk);
    default_deserializer_backend backend(source);
    auto errors = deserialize(value, backend);
    return {source.remaining(), errors};
}
//------------------------------------------------------------------------------
/// @brief Uses backend and compressor to deserialize and unpack a value from a block.
/// @see default_deserializer_backend
/// @see default_deserialize
/// @see default_serialize_packed
/// @see data_compressor
/// @see deserialize
template <typename T>
inline auto default_deserialize_packed(
  T& value,
  memory::const_block blk,
  data_compressor compressor) -> deserialization_result<memory::const_block> {
    packed_block_data_source source(std::move(compressor), blk);
    default_deserializer_backend backend(source);
    auto errors = deserialize(value, backend);
    return {source.remaining(), errors};
}
//------------------------------------------------------------------------------
/// @brief Default-deserializes the specified message id from a memory block.
/// @ingroup msgbus
/// @see default_deserializer_backend
/// @see default_deserialize
/// @see message_id
inline auto
default_deserialize_message_type(message_id& msg_id, memory::const_block blk) {
    std::tuple<identifier, identifier> value{};
    auto result = default_deserialize(value, blk);
    if(result) {
        msg_id = {value};
    }
    return result;
}
//------------------------------------------------------------------------------
template <typename Backend, typename Value>
inline auto
stored_message::do_store_value(const Value& value, span_size_t max_size)
  -> bool {
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
inline auto
stored_message::store_value(const Value& value, span_size_t max_size) -> bool {
    return do_store_value<default_serializer_backend>(value, max_size);
}
//------------------------------------------------------------------------------
template <typename Backend, typename Value>
inline auto stored_message::do_fetch_value(Value& value) -> bool {
    block_data_source source(view(_buffer));
    Backend backend(source);
    auto errors = deserialize(value, backend);
    return !errors;
}
//------------------------------------------------------------------------------
template <typename Value>
inline auto stored_message::fetch_value(Value& value) -> bool {
    return do_fetch_value<default_deserializer_backend>(value);
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_SERIALIZE_HPP
