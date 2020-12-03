/**
 *  @file eagine/serialize/data_buffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_DATA_BUFFER_HPP
#define EAGINE_SERIALIZE_DATA_BUFFER_HPP

#include "../int_constant.hpp"
#include "../types.hpp"
#include <array>
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T, identifier_t SerializerId>
struct get_serialize_buffer_size;

template <typename T, identifier_t SerializerId>
constexpr const auto serialize_buffer_size_v =
  get_serialize_buffer_size<T, SerializerId>::value;
//------------------------------------------------------------------------------
template <typename T, identifier_t Sid>
struct get_serialize_buffer_size<T&, Sid>
  : get_serialize_buffer_size<T, Sid> {};

template <typename T, identifier_t Sid>
struct get_serialize_buffer_size<const T, Sid>
  : get_serialize_buffer_size<T, Sid> {};

template <typename T, identifier_t Sid>
struct get_serialize_buffer_size<const T&, Sid>
  : get_serialize_buffer_size<T, Sid> {};
//------------------------------------------------------------------------------
template <identifier_t Sid>
struct get_serialize_buffer_size<bool, Sid> : size_constant<8> {};

template <identifier_t Sid>
struct get_serialize_buffer_size<byte, Sid> : size_constant<4> {};

template <identifier_t Sid>
struct get_serialize_buffer_size<char, Sid> : size_constant<4> {};

template <identifier_t Sid>
struct get_serialize_buffer_size<std::int16_t, Sid> : size_constant<6> {};

template <identifier_t Sid>
struct get_serialize_buffer_size<std::uint16_t, Sid> : size_constant<6> {};

template <identifier_t Sid>
struct get_serialize_buffer_size<std::int32_t, Sid> : size_constant<12> {};

template <identifier_t Sid>
struct get_serialize_buffer_size<std::uint32_t, Sid> : size_constant<12> {};

template <identifier_t Sid>
struct get_serialize_buffer_size<std::int64_t, Sid> : size_constant<24> {};

template <identifier_t Sid>
struct get_serialize_buffer_size<std::uint64_t, Sid> : size_constant<24> {};
//------------------------------------------------------------------------------
template <typename... T, identifier_t Sid>
struct get_serialize_buffer_size<std::tuple<T...>, Sid>
  : size_constant<(4 + ... + (2 + serialize_buffer_size_v<T, Sid>))> {};
//------------------------------------------------------------------------------
template <typename T, identifier_t SerializerId>
using serialize_buffer_t =
  std::array<byte, get_serialize_buffer_size<T, SerializerId>::value>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif
