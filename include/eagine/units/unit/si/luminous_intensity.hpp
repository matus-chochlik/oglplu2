/**
 *  @file eagine/units/unit/si/luminous_intensity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_LUMINOUS_INTENSITY_HPP
#define EAGINE_UNITS_UNIT_SI_LUMINOUS_INTENSITY_HPP

#include "common.hpp"

namespace eagine {
namespace units {
namespace base {

// candela
struct candela : unit<luminous_intensity, candela> {};

template <>
struct unit_name<candela> {
    static constexpr const char mp_str[] = "candela";
};

template <>
struct unit_symbol<candela> {
    static constexpr const char mp_str[] = "cd";
};

} // namespace base

// si::base_unit<luminous_intensity>
template <>
struct si::base_unit<base::luminous_intensity> : base::candela {};

// candela
using candela = unit<luminous_intensity, si>;

// derived
using kilocandela = make_scaled_base_dim_unit_t<
  base::scaled_unit<scales::kilo, base::candela>,
  si>;

} // namespace units
} // namespace eagine

#endif // EAGINE_UNITS_UNIT_SI_LUMINOUS_INTENSITY_HPP
