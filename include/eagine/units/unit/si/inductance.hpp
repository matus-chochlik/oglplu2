/**
 *  @file eagine/units/unit/si/inductance.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_INDUCTANCE_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_INDUCTANCE_1512222148_HPP

#include "../../dim/inductance.hpp"
#include "common.hpp"
#include "electric_current.hpp"
#include "length.hpp"
#include "mass.hpp"
#include "time.hpp"

namespace eagine {
namespace units {

// henry
typedef unit<inductance, si> henry;

template <>
struct unit_name<henry> {
    static constexpr const char mp_str[] = "henry";
};

template <>
struct unit_symbol<henry> {
    static constexpr const char mp_str[] = "H";
};

// derived
typedef make_scaled_unit_t<scales::milli, henry> millihenry;
typedef make_scaled_unit_t<scales::kilo, henry> kilohenry;
// TODO

} // namespace units
} // namespace eagine

#endif // include guard
