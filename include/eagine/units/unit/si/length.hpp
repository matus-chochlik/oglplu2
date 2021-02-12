/// @file eagine/units/unit/si/length.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_UNIT_SI_LENGTH_HPP
#define EAGINE_UNITS_UNIT_SI_LENGTH_HPP

#include "common.hpp"

namespace eagine::units {
namespace base {

// meter
struct meter : unit<length, meter> {};

} // namespace base

template <>
struct name_of<base::meter> {
    static constexpr const char mp_str[] = "meter";
};
template <>
struct symbol_of<base::meter> {
    static constexpr const char mp_str[] = "m";
};

// si::base_unit<length>
template <>
struct si::base_unit<base::length> : base::meter {};

// kilometer
using meter = unit<length, si>;

// derived
using kilometer =
  make_scaled_base_dim_unit_t<base::scaled_unit<scales::kilo, base::meter>, si>;

using decimeter =
  make_scaled_base_dim_unit_t<base::scaled_unit<scales::deci, base::meter>, si>;

using centimeter =
  make_scaled_base_dim_unit_t<base::scaled_unit<scales::centi, base::meter>, si>;

using millimeter =
  make_scaled_base_dim_unit_t<base::scaled_unit<scales::milli, base::meter>, si>;

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_LENGTH_HPP
