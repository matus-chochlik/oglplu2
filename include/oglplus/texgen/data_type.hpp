/**
 *  @file oglplus/texgen/data_type.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_DATA_TYPE_1509260923_HPP
#define OGLPLUS_TEXGEN_DATA_TYPE_1509260923_HPP

#include "../config/basic.hpp"
#include "../utils/cstr_ref.hpp"
#include <eagine/valid_if.hpp>
#include <iosfwd>

namespace oglplus {
namespace texgen {

enum class slot_data_type
{
	float_, float_2, float_3, float_4,
	int_, int_2, int_3, int_4,
	bool_, bool_2, bool_3, bool_4 
};

enum class scalar_data_type : int
{
	bool_ = 1,
	int_ = 2,
	float_ = 3
};

template <typename T>
struct get_data_type;

template <typename T>
struct get_data_type<T[1]>
 : get_data_type<T>
{ };

template <> struct get_data_type<bool>
 : std::integral_constant<slot_data_type, slot_data_type::bool_>
{ };

template <> struct get_data_type<bool[2]>
 : std::integral_constant<slot_data_type, slot_data_type::bool_2>
{ };

template <> struct get_data_type<bool[3]>
 : std::integral_constant<slot_data_type, slot_data_type::bool_3>
{ };

template <> struct get_data_type<bool[4]>
 : std::integral_constant<slot_data_type, slot_data_type::bool_4>
{ };

template <> struct get_data_type<int>
 : std::integral_constant<slot_data_type, slot_data_type::int_>
{ };

template <> struct get_data_type<int[2]>
 : std::integral_constant<slot_data_type, slot_data_type::int_2>
{ };

template <> struct get_data_type<int[3]>
 : std::integral_constant<slot_data_type, slot_data_type::int_3>
{ };

template <> struct get_data_type<int[4]>
 : std::integral_constant<slot_data_type, slot_data_type::int_4>
{ };

template <> struct get_data_type<float>
 : std::integral_constant<slot_data_type, slot_data_type::float_>
{ };

template <> struct get_data_type<float[2]>
 : std::integral_constant<slot_data_type, slot_data_type::float_2>
{ };

template <> struct get_data_type<float[3]>
 : std::integral_constant<slot_data_type, slot_data_type::float_3>
{ };

template <> struct get_data_type<float[4]>
 : std::integral_constant<slot_data_type, slot_data_type::float_4>
{ };

template <typename T>
constexpr slot_data_type get_data_type_v = get_data_type<T>::value;

cstr_ref data_type_name(slot_data_type)
noexcept;

scalar_data_type elem_data_type(slot_data_type)
noexcept;

unsigned data_type_dims(slot_data_type)
noexcept;

slot_data_type make_data_type(
	scalar_data_type type,
	eagine::valid_if_between<unsigned, 1, 4> dims
) noexcept;

slot_data_type common_data_type(slot_data_type a, slot_data_type b)
noexcept;

std::ostream&
conversion_prefix(
	std::ostream& out,
	slot_data_type from,
	slot_data_type to
);

struct conversion_prefix_expr
{
	slot_data_type from;
	slot_data_type to;
};
std::ostream& operator << (std::ostream&, conversion_prefix_expr);

std::ostream&
conversion_suffix(
	std::ostream& out,
	slot_data_type from,
	slot_data_type to
);

struct conversion_suffix_expr
{
	slot_data_type from;
	slot_data_type to;
};
std::ostream& operator << (std::ostream&, conversion_suffix_expr);

std::ostream&
conversion_suffix(
	std::ostream& out,
	slot_data_type from,
	slot_data_type to,
	cstr_ref x, cstr_ref y, cstr_ref z, cstr_ref w
);

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/data_type.inl>
#endif

#endif // include guard
