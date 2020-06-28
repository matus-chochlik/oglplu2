/**
 *  @file eagine/units/unit/si/electrical_resistance.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_ELECTRICAL_RESISTANCE_HPP
#define EAGINE_UNITS_UNIT_SI_ELECTRICAL_RESISTANCE_HPP

#include "../../dim/electrical_resistance.hpp"
#include "common.hpp"
#include "electric_current.hpp"
#include "electric_tension.hpp"

namespace eagine {
namespace units {

// ohm
using ohm = unit<electrical_resistance, si>;

template <>
struct name_of<ohm> {
    static constexpr const char mp_str[] = "ohm";
};

template <>
struct symbol_of<ohm> {
    static constexpr const char mp_str[] = {char(0xCE), char(0xA9), '\0'};
};

// derived
using milliohm = make_scaled_unit_t<scales::milli, ohm>;
using kiloohm = make_scaled_unit_t<scales::kilo, ohm>;
// TODO

} // namespace units
} // namespace eagine

#endif // EAGINE_UNITS_UNIT_SI_ELECTRICAL_RESISTANCE_HPP
