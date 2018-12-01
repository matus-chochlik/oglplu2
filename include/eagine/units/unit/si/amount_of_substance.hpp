/**
 *  @file eagine/units/unit/si/amount_of_substance.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_AMOUNT_OF_SUBSTANCE_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_AMOUNT_OF_SUBSTANCE_1512222148_HPP

#include "common.hpp"

namespace eagine {
namespace units {
namespace base {

// mole
struct mole : unit<amount_of_substance, mole> {};

template <>
struct unit_name<mole> {
    static constexpr const char mp_str[] = "mole";
};
template <>
struct unit_symbol<mole> {
    static constexpr const char mp_str[] = "mol";
};

} // namespace base

// si::base_unit<amount_of_substance>
template <>
struct si::base_unit<base::amount_of_substance> : base::mole {};

typedef unit<amount_of_substance, si> mole;

typedef make_scaled_base_dim_unit_t<
  base::scaled_unit<scales::kilo, base::mole>,
  si>
  kilomole;

} // namespace units
} // namespace eagine

#endif // include guard
