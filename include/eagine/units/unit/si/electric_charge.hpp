/**
 *  @file eagine/units/unit/si/electric_charge.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_ELECTRIC_CHARGE_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_ELECTRIC_CHARGE_1512222148_HPP

#include "../../dim/electric_charge.hpp"
#include "common.hpp"
#include "electric_current.hpp"
#include "time.hpp"

namespace eagine {
namespace units {

// coulomb
typedef unit<electric_charge, si> coulomb;

template <>
struct unit_name<coulomb> {
    static constexpr const char mp_str[] = "coulomb";
};

template <>
struct unit_symbol<coulomb> {
    static constexpr const char mp_str[] = "C";
};

// derived
typedef make_scaled_unit_t<scales::milli, coulomb> millicoulomb;
typedef make_scaled_unit_t<scales::kilo, coulomb> kilocoulomb;
// TODO

} // namespace units
} // namespace eagine

#endif // include guard
