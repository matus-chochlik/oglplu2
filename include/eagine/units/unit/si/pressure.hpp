/**
 *  @file eagine/units/unit/si/pressure.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_PRESSURE_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_PRESSURE_1512222148_HPP

#include "common.hpp"
#include "mass.hpp"
#include "time.hpp"
#include "length.hpp"
#include "../../dim/pressure.hpp"

namespace eagine {
namespace units {

// pascal
typedef unit<pressure, si> pascal;

template <>
struct unit_name<pascal>
{
	static constexpr const char mp_str[] = "pascal";
};

template <>
struct unit_symbol<pascal>
{
	static constexpr const char mp_str[] = "Pa";
};

// derived
typedef make_scaled_unit_t<scales::kilo, pascal> kilopascal;
typedef make_scaled_unit_t<scales::mega, pascal> megapascal;
// TODO

} // namespace units
} // namespace eagine

#endif //include guard

