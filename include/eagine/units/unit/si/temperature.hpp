/**
 *  @file eagine/units/unit/si/temperature.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_MASS_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_MASS_1512222148_HPP

#include "common.hpp"

namespace eagine {
namespace units {
namespace base {

// kelvin
struct kelvin : unit<temperature, kelvin> { };

template <>
struct unit_name<kelvin>
{
	static constexpr const char mp_str[] = "kelvin";
};
template <>
struct unit_symbol<kelvin>
{
	static constexpr const char mp_str[] = "K";
};

} // namespace base

// si::base_unit<temperature>
template <>
struct si::base_unit<base::temperature> : base::kelvin { };

} // namespace units
} // namespace eagine

#endif //include guard

