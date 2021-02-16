/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_UNIT_SI_MAGNETIC_FLUX_HPP
#define EAGINE_UNITS_UNIT_SI_MAGNETIC_FLUX_HPP

#include "../../dim/magnetic_flux.hpp"
#include "common.hpp"
#include "electric_current.hpp"
#include "length.hpp"
#include "mass.hpp"
#include "time.hpp"

namespace eagine::units {

// weber
using weber = unit<magnetic_flux, si>;

template <>
struct name_of<weber> {
    static constexpr const char mp_str[] = "weber";
};

template <>
struct symbol_of<weber> {
    static constexpr const char mp_str[] = "Wb";
};

// derived
using milliweber = make_scaled_unit_t<scales::milli, weber>;
using kiloweber = make_scaled_unit_t<scales::kilo, weber>;
// TODO

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_MAGNETIC_FLUX_HPP
