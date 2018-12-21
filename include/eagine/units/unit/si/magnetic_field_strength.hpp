/**
 *  @file eagine/units/unit/si/magnetic_field_strength.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_MAGNETIC_FIELD_STRENGTH_HPP
#define EAGINE_UNITS_UNIT_SI_MAGNETIC_FIELD_STRENGTH_HPP

#include "../../dim/magnetic_field_strength.hpp"
#include "common.hpp"
#include "electric_current.hpp"
#include "length.hpp"
#include "mass.hpp"
#include "time.hpp"

namespace eagine {
namespace units {

// tesla
using tesla = unit<magnetic_field_strength, si>;

template <>
struct unit_name<tesla> {
    static constexpr const char mp_str[] = "tesla";
};

template <>
struct unit_symbol<tesla> {
    static constexpr const char mp_str[] = "T";
};

// derived
using millitesla = make_scaled_unit_t<scales::milli, tesla>;
// TODO

} // namespace units
} // namespace eagine

#endif // EAGINE_UNITS_UNIT_SI_MAGNETIC_FIELD_STRENGTH_HPP
