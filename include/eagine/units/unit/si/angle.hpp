/**
 *  @file eagine/units/unit/si/angle.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_ANGLE_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_ANGLE_1512222148_HPP

#include "common.hpp"

namespace eagine {

struct qty_radians_tag;
struct qty_degrees_tag;

namespace units {
namespace base {

// radian
struct radian : unit<angle, radian> { };

template <>
struct unit_name<radian>
{
	static constexpr const char mp_str[] = "radian";
};

template <>
struct unit_symbol<radian>
{
	static constexpr const char mp_str[] = "rad";
};

// degree
typedef scaled_unit<
	scales::divided<scales::pi, scales::constant<180>>,
	radian
> degree;

template <>
struct unit_name<degree>
{
	static constexpr const char mp_str[] = "degree";
};

template <>
struct unit_symbol<degree>
{
	static constexpr const char mp_str[] = {char(0xC2),char(0xB0),'\0'};
};

// gradian
typedef scaled_unit<
	scales::divided<scales::pi, scales::constant<200>>,
	radian
> gradian;

template <>
struct unit_name<gradian>
{
	static constexpr const char mp_str[] = "gradian";
};

template <>
struct unit_symbol<gradian>
{
	static constexpr const char mp_str[] = "grad";
};

// quarter
typedef scaled_unit<
	scales::multiplied<scales::pi, scales::rational<1, 2>>,
	radian
> quarter;

template <>
struct unit_name<quarter>
{
	static constexpr const char mp_str[] = "quarter";
};

template <>
struct unit_symbol<quarter>
{
	static constexpr const char mp_str[] = "Q";
};

// turn
typedef scaled_unit<
	scales::multiplied<scales::constant<2>, scales::pi>,
	radian
> turn;

template <>
struct unit_name<turn>
{
	static constexpr const char mp_str[] = "turn";
};

template <>
struct unit_symbol<turn>
{
	static constexpr const char mp_str[] = "r";
};

} // namespace base

// si::base_unit<angle>
template <>
struct si::base_unit<base::angle> : base::radian { };

// radian
typedef unit<angle, si> radian;

// derived
typedef make_scaled_unit_t<base::degree, si> degree;
typedef make_scaled_unit_t<base::gradian, si> gradian;
typedef make_scaled_unit_t<base::quarter, si> quarter;
typedef make_scaled_unit_t<base::turn, si> turn;

typedef make_scaled_unit_t<
	base::scaled_unit<scales::pi, base::radian>,
	si
> pi_rad;

// conversions
template <>
struct is_convertible<radian, qty_radians_tag>
 : std::true_type
{ };

template <>
struct value_conv<radian, qty_radians_tag>
 : trivial_value_conv
{ };

template <>
struct is_convertible<degree, qty_degrees_tag>
 : std::true_type
{ };

template <>
struct value_conv<degree, qty_degrees_tag>
 : trivial_value_conv
{ };

template <typename US>
struct is_convertible<scaled_unit<angle, US, si>, qty_radians_tag>
 : std::true_type
{ };

template <typename US>
struct value_conv<scaled_unit<angle, US, si>, qty_radians_tag>
{
	template <typename T>
	constexpr inline
	auto operator()(T v) const
	{
		return v*scaled_unit<angle, US, si>::scale::value;
	}
};

} // namespace units
} // namespace eagine

#endif //include guard

