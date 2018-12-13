/**
 *  @file eagine/units/unit/si/force.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_FORCE_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_FORCE_1512222148_HPP

#include "../../dim/force.hpp"
#include "common.hpp"
#include "length.hpp"
#include "mass.hpp"
#include "time.hpp"

namespace eagine {
namespace units {

// newton
using newton = unit<force, si>;

template <>
struct unit_name<newton> {
    static constexpr const char mp_str[] = "newton";
};

template <>
struct unit_symbol<newton> {
    static constexpr const char mp_str[] = "N";
};

// derived
using kilonewton = make_scaled_unit_t<scales::kilo, newton>;
using meganewton = make_scaled_unit_t<scales::mega, newton>;
// TODO

} // namespace units
} // namespace eagine

#endif // include guard
