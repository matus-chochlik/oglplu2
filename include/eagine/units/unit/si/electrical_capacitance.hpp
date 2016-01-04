/**
 *  @file eagine/units/unit/si/electrical_capacitance.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_ELECTRICAL_CAPACITANCE_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_ELECTRICAL_CAPACITANCE_1512222148_HPP

#include "common.hpp"
#include "electric_charge.hpp"
#include "electric_tension.hpp"
#include "../../dim/electrical_capacitance.hpp"

namespace eagine {
namespace units {

// farad
typedef unit<electrical_capacitance, si> farad;

template <>
struct unit_name<farad>
{
	static constexpr const char mp_str[] = "farad";
};

template <>
struct unit_symbol<farad>
{
	static constexpr const char mp_str[] = "F";
};

// derived
typedef make_scaled_unit_t<scales::micro, farad> microfarad;
typedef make_scaled_unit_t<scales::milli, farad> millifarad;
typedef make_scaled_unit_t<scales::kilo, farad> kilofarad;
// TODO

} // namespace units
} // namespace eagine

#endif //include guard

