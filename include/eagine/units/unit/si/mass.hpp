/**
 *  @file eagine/units/unit/si/mass.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_MASS_HPP
#define EAGINE_UNITS_UNIT_SI_MASS_HPP

#include "common.hpp"

namespace eagine::units {
namespace base {

// gram
struct gram : unit<mass, gram> {};

// tonne
using tonne = scaled_unit<scales::mega, gram>;

} // namespace base

template <>
struct name_of<base::gram> {
    static constexpr const char mp_str[] = "gram";
};
template <>
struct symbol_of<base::gram> {
    static constexpr const char mp_str[] = "g";
};

template <>
struct name_of<base::tonne> {
    static constexpr const char mp_str[] = "tonne";
};

template <>
struct symbol_of<base::tonne> {
    static constexpr const char mp_str[] = "t";
};

// si::base_unit<mass>
template <>
struct si::base_unit<base::mass>
  : base::scaled_unit<scales::kilo, base::gram> {};

// kilogram
using kilogram = unit<mass, si>;

// derived
using gram =
  make_scaled_base_dim_unit_t<base::scaled_unit<scales::one, base::gram>, si>;

using milligram =
  make_scaled_base_dim_unit_t<base::scaled_unit<scales::milli, base::gram>, si>;

using tonne = make_scaled_base_dim_unit_t<base::tonne, si>;

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_MASS_HPP
