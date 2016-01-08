/**
 *  @file eagine/units/unit/si/solid_angle.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_SOLID_ANGLE_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_SOLID_ANGLE_1512222148_HPP

#include "common.hpp"

namespace eagine {
namespace units {
namespace base {

// steradian
struct steradian : unit<solid_angle, steradian> { };

template <>
struct unit_name<steradian>
{
	static constexpr const char mp_str[] = "steradian";
};

template <>
struct unit_symbol<steradian>
{
	static constexpr const char mp_str[] = "sr";
};

} // namespace base

// si::base_unit<solid_angle>
template <>
struct si::base_unit<base::solid_angle> : base::steradian { };

// steradian
typedef unit<solid_angle, si> steradian;

} // namespace units
} // namespace eagine

#endif //include guard

