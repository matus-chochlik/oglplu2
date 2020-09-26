/**
 *  @file oglplus/texgen/data_type.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_DATA_TYPE_HPP
#define OGLPLUS_TEXGEN_DATA_TYPE_HPP

#include "../config/basic.hpp"
#include <eagine/string_span.hpp>
#include <eagine/types.hpp>
#include <eagine/valid_if/between.hpp>
#include <iosfwd>

namespace eagine::oglp::texgen {

enum class slot_data_type {
    float_,
    float_2,
    float_3,
    float_4,
    int_,
    int_2,
    int_3,
    int_4,
    bool_,
    bool_2,
    bool_3,
    bool_4
};

enum class scalar_data_type : int { bool_ = 1, int_ = 2, float_ = 3 };

template <typename T>
struct get_data_type;

template <typename T>
struct get_data_type<T[1]> : get_data_type<T> {};

template <>
struct get_data_type<bool>
  : std::integral_constant<slot_data_type, slot_data_type::bool_> {};

template <>
struct get_data_type<bool[2]>
  : std::integral_constant<slot_data_type, slot_data_type::bool_2> {};

template <>
struct get_data_type<bool[3]>
  : std::integral_constant<slot_data_type, slot_data_type::bool_3> {};

template <>
struct get_data_type<bool[4]>
  : std::integral_constant<slot_data_type, slot_data_type::bool_4> {};

template <>
struct get_data_type<int>
  : std::integral_constant<slot_data_type, slot_data_type::int_> {};

template <>
struct get_data_type<int[2]>
  : std::integral_constant<slot_data_type, slot_data_type::int_2> {};

template <>
struct get_data_type<int[3]>
  : std::integral_constant<slot_data_type, slot_data_type::int_3> {};

template <>
struct get_data_type<int[4]>
  : std::integral_constant<slot_data_type, slot_data_type::int_4> {};

template <>
struct get_data_type<float>
  : std::integral_constant<slot_data_type, slot_data_type::float_> {};

template <>
struct get_data_type<float[2]>
  : std::integral_constant<slot_data_type, slot_data_type::float_2> {};

template <>
struct get_data_type<float[3]>
  : std::integral_constant<slot_data_type, slot_data_type::float_3> {};

template <>
struct get_data_type<float[4]>
  : std::integral_constant<slot_data_type, slot_data_type::float_4> {};

template <typename T>
constexpr slot_data_type get_data_type_v = get_data_type<T>::value;

string_view data_type_name(slot_data_type) noexcept;

scalar_data_type elem_data_type(slot_data_type) noexcept;

span_size_t data_type_dims(slot_data_type) noexcept;

slot_data_type make_data_type(
  scalar_data_type type,
  const valid_if_between<span_size_t, 1, 4>& dims) noexcept;

scalar_data_type common_elem_type(slot_data_type a, slot_data_type b) noexcept;

span_size_t common_dims(slot_data_type a, slot_data_type b) noexcept;

slot_data_type common_data_type(slot_data_type a, slot_data_type b) noexcept;

std::ostream&
conversion_prefix(std::ostream& out, slot_data_type from, slot_data_type to);

std::ostream&
conversion_suffix(std::ostream& out, slot_data_type from, slot_data_type to);

std::ostream& conversion_suffix(
  std::ostream& out,
  slot_data_type from,
  slot_data_type to,
  string_view x,
  string_view y,
  string_view z,
  string_view w);

namespace expr {

struct conversion_prefix {
    slot_data_type from{};
    slot_data_type to{};
};
std::ostream& operator<<(std::ostream&, conversion_prefix);

struct conversion_suffix {
    slot_data_type from{};
    slot_data_type to{};
};
std::ostream& operator<<(std::ostream&, conversion_suffix);

struct conversion_suffix_v {
    slot_data_type from{};
    slot_data_type to{};
    string_view val[4]{};
};
std::ostream& operator<<(std::ostream&, conversion_suffix_v);

} // namespace expr
} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/data_type.inl>
#endif

#endif // OGLPLUS_TEXGEN_DATA_TYPE_HPP
