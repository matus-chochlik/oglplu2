/**
 *  @file eagine/units/unit/si/electric_tension.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_ELECTRIC_TENSION_HPP
#define EAGINE_UNITS_UNIT_SI_ELECTRIC_TENSION_HPP

#include "../../dim/electric_tension.hpp"
#include "common.hpp"
#include "electric_current.hpp"
#include "length.hpp"
#include "mass.hpp"
#include "time.hpp"

namespace eagine {
namespace units {

// volt
using volt = unit<electric_tension, si>;

template <>
struct name_of<volt> {
    static constexpr const char mp_str[] = "volt";
};

template <>
struct symbol_of<volt> {
    static constexpr const char mp_str[] = "V";
};

// derived
using millivolt = make_scaled_unit_t<scales::milli, volt>;
using kilovolt = make_scaled_unit_t<scales::kilo, volt>;
// TODO

} // namespace units
} // namespace eagine

#endif // EAGINE_UNITS_UNIT_SI_ELECTRIC_TENSION_HPP
