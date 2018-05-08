/**
 *  @file eagine/units/unit/si/power.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_POWER_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_POWER_1512222148_HPP

#include "../../dim/power.hpp"
#include "common.hpp"
#include "length.hpp"
#include "mass.hpp"
#include "time.hpp"

namespace eagine {
namespace units {

// watt
typedef unit<power, si> watt;

template <>
struct unit_name<watt> {
    static constexpr const char mp_str[] = "watt";
};

template <>
struct unit_symbol<watt> {
    static constexpr const char mp_str[] = "W";
};

// derived
typedef make_scaled_unit_t<scales::kilo, watt> kilowatt;
typedef make_scaled_unit_t<scales::mega, watt> megawatt;
// TODO

} // namespace units
} // namespace eagine

#endif // include guard
