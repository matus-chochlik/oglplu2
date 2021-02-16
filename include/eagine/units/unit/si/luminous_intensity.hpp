/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_UNIT_SI_LUMINOUS_INTENSITY_HPP
#define EAGINE_UNITS_UNIT_SI_LUMINOUS_INTENSITY_HPP

#include "common.hpp"

namespace eagine::units {
namespace base {

// candela
struct candela : unit<luminous_intensity, candela> {};

} // namespace base

template <>
struct name_of<base::candela> {
    static constexpr const char mp_str[] = "candela";
};

template <>
struct symbol_of<base::candela> {
    static constexpr const char mp_str[] = "cd";
};

// si::base_unit<luminous_intensity>
template <>
struct si::base_unit<base::luminous_intensity> : base::candela {};

// candela
using candela = unit<luminous_intensity, si>;

// derived
using kilocandela =
  make_scaled_base_dim_unit_t<base::scaled_unit<scales::kilo, base::candela>, si>;

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_LUMINOUS_INTENSITY_HPP
