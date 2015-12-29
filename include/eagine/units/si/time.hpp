/**
 *  @file eagine/unit/si/time.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_SI_TIME_1512222148_HPP
#define EAGINE_UNITS_SI_TIME_1512222148_HPP

#include "common.hpp"

namespace eagine {
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
typedef scaled_unit<scales::rational<60, 1>, second> minute;

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
typedef scaled_unit<scales::rational<3600, 1>, second> hour;

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
typedef scaled_unit<scales::rational<86400, 1>, second> day;

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
typedef make_scaled_unit<base::minute, si>::type minute;
typedef make_scaled_unit<base::hour, si>::type hour;
typedef make_scaled_unit<base::day, si>::type day;

} // namespace units
} // namespace eagine

#endif //include guard

