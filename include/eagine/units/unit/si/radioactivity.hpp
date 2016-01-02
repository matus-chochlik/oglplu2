/**
 *  @file eagine/units/unit/si/radioactivity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_RADIOACTIVITY_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_RADIOACTIVITY_1512222148_HPP

#include "common.hpp"
#include "../../dim/radioactivity.hpp"

namespace eagine {
namespace units {
namespace base {

struct count_of_decays : unit<number_of_decays, count_of_decays> { };

} // namespace base

// si::base_unit<angle>
template <>
struct si::base_unit<base::number_of_decays> : base::count_of_decays { };

// count of decays
typedef unit<number_of_decays, si> count_of_decays;

// becquerel
typedef unit<radioactivity, si> becquerel;

template <>
struct unit_name<becquerel>
{
	static constexpr const char mp_str[] = "becquerel";
};

template <>
struct unit_symbol<becquerel>
{
	static constexpr const char mp_str[] = "Bq";
};

// derived
typedef scaled_unit<
	bits::dims<
		bits::dim_pow<nothing_t, int_constant<1>>,
		radioactivity
	>,
	bits::unit_scales<
		bits::uni_sca<nothing_t, scales::kilo>,
		nothing_t
	>, si
> kilobecquerel;

typedef scaled_unit<
	bits::dims<
		bits::dim_pow<nothing_t, int_constant<1>>,
		radioactivity
	>,
	bits::unit_scales<
		bits::uni_sca<nothing_t, scales::mega>,
		nothing_t
	>, si
> megabecquerel;
// TODO

} // namespace units
} // namespace eagine

#endif //include guard

