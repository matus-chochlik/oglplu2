/**
 *  @file eagine/unit/si/mass.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_SI_MASS_1512222148_HPP
#define EAGINE_UNITS_SI_MASS_1512222148_HPP

#include "common.hpp"

namespace eagine {
namespace units {
namespace base {

// gram
struct gram : unit<mass, gram> { };

template <>
struct unit_name<gram>
{
	static constexpr const char mp_str[] = "gram";
};
template <>
struct unit_symbol<gram>
{
	static constexpr const char mp_str[] = "g";
};

// tonne
typedef scaled_unit<scales::mega, gram> tonne;

template <>
struct unit_name<tonne>
{
	static constexpr const char mp_str[] = "tonne";
};

template <>
struct unit_symbol<tonne>
{
	static constexpr const char mp_str[] = "t";
};

} // namespace base

// si::base_unit<mass>
template <>
struct si::base_unit<base::mass>
 : base::scaled_unit<scales::kilo, base::gram>
{ };

// kilogram
typedef unit<mass, si> kilogram;

// derived
typedef make_scaled_unit_t<
	base::scaled_unit<scales::one, base::gram>,
	si
> gram;

typedef make_scaled_unit_t<
	base::scaled_unit<scales::milli, base::gram>,
	si
> milligram;

typedef make_scaled_unit_t<base::tonne, si> tonne;

} // namespace units
} // namespace eagine

#endif //include guard

