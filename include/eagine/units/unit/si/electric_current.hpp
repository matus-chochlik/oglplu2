/**
 *  @file eagine/units/unit/si/electric_current.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_ELECTRIC_CURRENT_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_ELECTRIC_CURRENT_1512222148_HPP

#include "common.hpp"

namespace eagine {
namespace units {
namespace base {

// ampere
struct ampere : unit<electric_current, ampere> { };

template <>
struct unit_name<ampere>
{
	static constexpr const char mp_str[] = "ampere";
};
template <>
struct unit_symbol<ampere>
{
	static constexpr const char mp_str[] = "A";
};

} // namespace base

// si::base_unit<electric_current>
template <>
struct si::base_unit<base::electric_current> : base::ampere { };

// kiloampere
typedef unit<electric_current, si> ampere;

// derived
typedef make_scaled_base_dim_unit_t<
	base::scaled_unit<scales::kilo, base::ampere>,
	si
> kiloampere;

typedef make_scaled_base_dim_unit_t<
	base::scaled_unit<scales::milli, base::ampere>,
	si
> milliampere;

} // namespace units
} // namespace eagine

#endif //include guard

