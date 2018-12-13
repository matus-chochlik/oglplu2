/**
 *  @file eagine/units/unit/si/temperature.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_TEMPERATURE_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_TEMPERATURE_1512222148_HPP

#include "common.hpp"

namespace eagine {
namespace units {
namespace base {

// kelvin
struct kelvin : unit<temperature, kelvin> {};

template <>
struct unit_name<kelvin> {
    static constexpr const char mp_str[] = "kelvin";
};
template <>
struct unit_symbol<kelvin> {
    static constexpr const char mp_str[] = "K";
};

} // namespace base

// si::base_unit<temperature>
template <>
struct si::base_unit<base::temperature> : base::kelvin {};

// kelvin
using kelvin = unit<temperature, si>;

// derived
using millikelvin = make_scaled_base_dim_unit_t<
  base::scaled_unit<scales::milli, base::kelvin>,
  si>;

using kilokelvin = make_scaled_base_dim_unit_t<
  base::scaled_unit<scales::kilo, base::kelvin>,
  si>;

} // namespace units
} // namespace eagine

#endif // include guard
