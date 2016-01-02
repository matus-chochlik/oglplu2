/**
 *  @file eagine/units/unit/si/frequency.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_FREQUENCY_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_FREQUENCY_1512222148_HPP

#include "common.hpp"
#include "../../dim/frequency.hpp"

namespace eagine {
namespace units {
namespace base {

struct count_of_cycles : unit<number_of_cycles, count_of_cycles> { };

} // namespace base

// si::base_unit<angle>
template <>
struct si::base_unit<base::number_of_cycles> : base::count_of_cycles { };

// hertz
typedef unit<frequency, si> hertz;

template <>
struct unit_name<hertz>
{
	static constexpr const char mp_str[] = "hertz";
};

template <>
struct unit_symbol<hertz>
{
	static constexpr const char mp_str[] = "Hz";
};

// derived
typedef scaled_unit<
	bits::dims<
		bits::dim_pow<nothing_t, int_constant<1>>,
		frequency
	>,
	bits::unit_scales<
		bits::uni_sca<nothing_t, scales::kilo>,
		nothing_t
	>, si
> kilohertz;
// TODO

} // namespace units
} // namespace eagine

#endif //include guard

