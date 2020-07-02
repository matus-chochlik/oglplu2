/**
 *  @file eagine/units/unit/si/force.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_FORCE_HPP
#define EAGINE_UNITS_UNIT_SI_FORCE_HPP

#include "../../dim/force.hpp"
#include "common.hpp"
#include "length.hpp"
#include "mass.hpp"
#include "time.hpp"

namespace eagine::units {

// newton
using newton = unit<force, si>;

template <>
struct name_of<newton> {
    static constexpr const char mp_str[] = "newton";
};

template <>
struct symbol_of<newton> {
    static constexpr const char mp_str[] = "N";
};

// derived
using kilonewton = make_scaled_unit_t<scales::kilo, newton>;
using meganewton = make_scaled_unit_t<scales::mega, newton>;
// TODO

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_FORCE_HPP
