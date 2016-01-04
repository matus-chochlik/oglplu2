/**
 *  @file eagine/units/unit/si/electric_tension.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_ELECTRIC_TENSION_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_ELECTRIC_TENSION_1512222148_HPP

#include "common.hpp"
#include "mass.hpp"
#include "time.hpp"
#include "length.hpp"
#include "electric_current.hpp"
#include "../../dim/electric_tension.hpp"

namespace eagine {
namespace units {

// volt
typedef unit<electric_tension, si> volt;

template <>
struct unit_name<volt>
{
	static constexpr const char mp_str[] = "volt";
};

template <>
struct unit_symbol<volt>
{
	static constexpr const char mp_str[] = "V";
};

// derived
typedef make_scaled_unit_t<scales::milli, volt> millivolt;
typedef make_scaled_unit_t<scales::kilo, volt> kilovolt;
// TODO

} // namespace units
} // namespace eagine

#endif //include guard

