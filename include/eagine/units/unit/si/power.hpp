/**
 *  @file eagine/units/unit/si/power.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_POWER_HPP
#define EAGINE_UNITS_UNIT_SI_POWER_HPP

#include "../../dim/power.hpp"
#include "common.hpp"
#include "length.hpp"
#include "mass.hpp"
#include "time.hpp"

namespace eagine::units {

// watt
using watt = unit<power, si>;

template <>
struct name_of<watt> {
    static constexpr const char mp_str[] = "watt";
};

template <>
struct symbol_of<watt> {
    static constexpr const char mp_str[] = "W";
};

// derived
using kilowatt = make_scaled_unit_t<scales::kilo, watt>;
using megawatt = make_scaled_unit_t<scales::mega, watt>;
// TODO

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_POWER_HPP
