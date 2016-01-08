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
typedef make_scaled_unit_t<scales::kilo, hertz> kilohertz;
typedef make_scaled_unit_t<scales::mega, hertz> megahertz;
typedef make_scaled_unit_t<scales::giga, hertz> gigahertz;
// TODO

} // namespace units
} // namespace eagine

#endif //include guard

