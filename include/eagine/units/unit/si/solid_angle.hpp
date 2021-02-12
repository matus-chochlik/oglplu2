/// @file eagine/units/unit/si/solid_angle.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_UNIT_SI_SOLID_ANGLE_HPP
#define EAGINE_UNITS_UNIT_SI_SOLID_ANGLE_HPP

#include "common.hpp"

namespace eagine::units {
namespace base {

// steradian
struct steradian : unit<solid_angle, steradian> {};

} // namespace base

template <>
struct name_of<base::steradian> {
    static constexpr const char mp_str[] = "steradian";
};

template <>
struct symbol_of<base::steradian> {
    static constexpr const char mp_str[] = "sr";
};

// si::base_unit<solid_angle>
template <>
struct si::base_unit<base::solid_angle> : base::steradian {};

// steradian
using steradian = unit<solid_angle, si>;

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_SOLID_ANGLE_HPP
