/// @file eagine/units/unit/si/amount_of_substance.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_UNIT_SI_AMOUNT_OF_SUBSTANCE_HPP
#define EAGINE_UNITS_UNIT_SI_AMOUNT_OF_SUBSTANCE_HPP

#include "common.hpp"

namespace eagine::units {
namespace base {

// mole
struct mole : unit<amount_of_substance, mole> {};

} // namespace base

template <>
struct name_of<base::mole> {
    static constexpr const char mp_str[] = "mole";
};
template <>
struct symbol_of<base::mole> {
    static constexpr const char mp_str[] = "mol";
};

// si::base_unit<amount_of_substance>
template <>
struct si::base_unit<base::amount_of_substance> : base::mole {};

using mole = unit<amount_of_substance, si>;

using kilomole =
  make_scaled_base_dim_unit_t<base::scaled_unit<scales::kilo, base::mole>, si>;

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_AMOUNT_OF_SUBSTANCE_HPP
