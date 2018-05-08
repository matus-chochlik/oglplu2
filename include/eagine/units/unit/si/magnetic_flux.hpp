/**
 *  @file eagine/units/unit/si/magnetic_flux.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_MAGNETIC_FLUX_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_MAGNETIC_FLUX_1512222148_HPP

#include "../../dim/magnetic_flux.hpp"
#include "common.hpp"
#include "electric_current.hpp"
#include "length.hpp"
#include "mass.hpp"
#include "time.hpp"

namespace eagine {
namespace units {

// weber
typedef unit<magnetic_flux, si> weber;

template <>
struct unit_name<weber> {
    static constexpr const char mp_str[] = "weber";
};

template <>
struct unit_symbol<weber> {
    static constexpr const char mp_str[] = "Wb";
};

// derived
typedef make_scaled_unit_t<scales::milli, weber> milliweber;
typedef make_scaled_unit_t<scales::kilo, weber> kiloweber;
// TODO

} // namespace units
} // namespace eagine

#endif // include guard
