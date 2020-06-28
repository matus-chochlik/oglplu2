/**
 *  @file eagine/units/unit/si/energy.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_ENERGY_HPP
#define EAGINE_UNITS_UNIT_SI_ENERGY_HPP

#include "../../dim/energy.hpp"
#include "common.hpp"
#include "length.hpp"
#include "mass.hpp"
#include "time.hpp"

namespace eagine {
namespace units {

// joule
using joule = unit<energy, si>;

template <>
struct name_of<joule> {
    static constexpr const char mp_str[] = "joule";
};

template <>
struct symbol_of<joule> {
    static constexpr const char mp_str[] = "J";
};

// derived
using kilojoule = make_scaled_unit_t<scales::kilo, joule>;
using megajoule = make_scaled_unit_t<scales::mega, joule>;
// TODO

} // namespace units
} // namespace eagine

#endif // EAGINE_UNITS_UNIT_SI_ENERGY_HPP
