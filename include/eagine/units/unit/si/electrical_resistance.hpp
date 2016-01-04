/**
 *  @file eagine/units/unit/si/electrical_resistance.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_ELECTRICAL_RESISTANCE_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_ELECTRICAL_RESISTANCE_1512222148_HPP

#include "common.hpp"
#include "electric_current.hpp"
#include "electric_tension.hpp"
#include "../../dim/electrical_resistance.hpp"

namespace eagine {
namespace units {

// ohm
typedef unit<electrical_resistance, si> ohm;

template <>
struct unit_name<ohm>
{
	static constexpr const char mp_str[] = "ohm";
};

template <>
struct unit_symbol<ohm>
{
	static constexpr const char mp_str[] = {char(0xCE),char(0xA9),'\0'};
};

// derived
typedef make_scaled_unit_t<scales::milli, ohm> milliohm;
typedef make_scaled_unit_t<scales::kilo, ohm> kiloohm;
// TODO

} // namespace units
} // namespace eagine

#endif //include guard

