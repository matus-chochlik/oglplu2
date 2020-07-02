/**
 *  @file eagine/units/unit/si/electric_current.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_ELECTRIC_CURRENT_HPP
#define EAGINE_UNITS_UNIT_SI_ELECTRIC_CURRENT_HPP

#include "common.hpp"

namespace eagine::units {
namespace base {

// ampere
struct ampere : unit<electric_current, ampere> {};

} // namespace base

template <>
struct name_of<base::ampere> {
    static constexpr const char mp_str[] = "ampere";
};
template <>
struct symbol_of<base::ampere> {
    static constexpr const char mp_str[] = "A";
};

// si::base_unit<electric_current>
template <>
struct si::base_unit<base::electric_current> : base::ampere {};

// kiloampere
using ampere = unit<electric_current, si>;

// derived
using kiloampere = make_scaled_base_dim_unit_t<
  base::scaled_unit<scales::kilo, base::ampere>,
  si>;

using milliampere = make_scaled_base_dim_unit_t<
  base::scaled_unit<scales::milli, base::ampere>,
  si>;

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_ELECTRIC_CURRENT_HPP
