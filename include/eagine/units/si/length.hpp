/**
 *  @file eagine/unit/si/length.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_SI_LENGTH_1512222148_HPP
#define EAGINE_UNITS_SI_LENGTH_1512222148_HPP

#include "common.hpp"

namespace eagine {
namespace units {
namespace base {

// meter
struct meter : unit<length, meter> { };

template <>
struct unit_name<meter>
{
	static constexpr const char mp_str[] = "meter";
};
template <>
struct unit_symbol<meter>
{
	static constexpr const char mp_str[] = "m";
};

} // namespace base

// si::base_unit<length>
template <>
struct si::base_unit<base::length> : base::meter { };

// kilometer
typedef unit<length, si> meter;

// derived
typedef make_scaled_unit_t<
	base::scaled_unit<scales::kilo, base::meter>,
	si
> kilometer;

typedef make_scaled_unit_t<
	base::scaled_unit<scales::centi, base::meter>,
	si
> centimeter;

typedef make_scaled_unit_t<
	base::scaled_unit<scales::milli, base::meter>,
	si
> millimeter;

} // namespace units
} // namespace eagine

#endif //include guard

