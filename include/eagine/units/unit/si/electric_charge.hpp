/**
 *  @file eagine/units/unit/si/electric_charge.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_ELECTRIC_CHARGE_HPP
#define EAGINE_UNITS_UNIT_SI_ELECTRIC_CHARGE_HPP

#include "../../dim/electric_charge.hpp"
#include "common.hpp"
#include "electric_current.hpp"
#include "time.hpp"

namespace eagine::units {

// coulomb
using coulomb = unit<electric_charge, si>;

template <>
struct name_of<coulomb> {
    static constexpr const char mp_str[] = "coulomb";
};

template <>
struct symbol_of<coulomb> {
    static constexpr const char mp_str[] = "C";
};

// derived
using millicoulomb = make_scaled_unit_t<scales::milli, coulomb>;
using kilocoulomb = make_scaled_unit_t<scales::kilo, coulomb>;
// TODO

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_ELECTRIC_CHARGE_HPP
