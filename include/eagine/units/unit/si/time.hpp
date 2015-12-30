/**
 *  @file eagine/units/unit/si/time.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_TIME_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_TIME_1512222148_HPP

#include "common.hpp"

namespace eagine {

struct qty_seconds_tag;

namespace units {
namespace base {

// second
struct second : unit<time, second> { };

template <>
struct unit_name<second>
{
	static constexpr const char mp_str[] = "second";
};
template <>
struct unit_symbol<second>
{
	static constexpr const char mp_str[] = "s";
};

// minute
typedef scaled_unit<scales::constant<60>, second> minute;

template <>
struct unit_name<minute>
{
	static constexpr const char mp_str[] = "minute";
};
template <>
struct unit_symbol<minute>
{
	static constexpr const char mp_str[] = "min";
};

// hour
typedef scaled_unit<scales::constant<3600>, second> hour;

template <>
struct unit_name<hour>
{
	static constexpr const char mp_str[] = "hour";
};
template <>
struct unit_symbol<hour>
{
	static constexpr const char mp_str[] = "hr";
};

// day
typedef scaled_unit<scales::constant<86400>, second> day;

template <>
struct unit_name<day>
{
	static constexpr const char mp_str[] = "day";
};
template <>
struct unit_symbol<day>
{
	static constexpr const char mp_str[] = "D";
};

} // namespace base

// si::base_unit<time>
template <>
struct si::base_unit<base::time> : base::second { };

typedef unit<time, si> second;

// derived
typedef make_scaled_unit_t<
	base::scaled_unit<scales::milli, base::second>,
	si
> millisecond;
typedef make_scaled_unit_t<base::minute, si> minute;
typedef make_scaled_unit_t<base::hour, si> hour;
typedef make_scaled_unit_t<base::day, si> day;

// conversions
template <>
struct is_convertible<second, qty_seconds_tag>
 : std::true_type
{ };

template <>
struct value_conv<second, qty_seconds_tag>
 : trivial_value_conv
{ };

template <typename US>
struct is_convertible<scaled_unit<time, US, si>, qty_seconds_tag>
 : std::true_type
{ };

template <typename US>
struct value_conv<scaled_unit<time, US, si>, qty_seconds_tag>
{
	template <typename T>
	constexpr inline
	auto operator()(T v) const
	{
		return v*scaled_unit<time, US, si>::scale::value;
	}
};

} // namespace units
} // namespace eagine

#endif //include guard

