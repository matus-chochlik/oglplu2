/// @file eagine/units/unit/si/electrical_conductance.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_UNIT_SI_ELECTRICAL_CONDUCTANCE_HPP
#define EAGINE_UNITS_UNIT_SI_ELECTRICAL_CONDUCTANCE_HPP

#include "../../dim/electrical_conductance.hpp"
#include "common.hpp"
#include "electric_current.hpp"
#include "electric_tension.hpp"

namespace eagine::units {

// siemens
using siemens = unit<electrical_conductance, si>;

template <>
struct name_of<siemens> {
    static constexpr const char mp_str[] = "siemens";
};

template <>
struct symbol_of<siemens> {
    static constexpr const char mp_str[] = "S";
};

// derived
using millisiemens = make_scaled_unit_t<scales::milli, siemens>;
// TODO

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_ELECTRICAL_CONDUCTANCE_HPP
