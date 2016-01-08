/**
 *  @file eagine/units/unit/si/magnetic_field_strength.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_UNIT_SI_MAGNETIC_FIELD_STRENGTH_1512222148_HPP
#define EAGINE_UNITS_UNIT_SI_MAGNETIC_FIELD_STRENGTH_1512222148_HPP

#include "common.hpp"
#include "mass.hpp"
#include "time.hpp"
#include "length.hpp"
#include "electric_current.hpp"
#include "../../dim/magnetic_field_strength.hpp"

namespace eagine {
namespace units {

// tesla
typedef unit<magnetic_field_strength, si> tesla;

template <>
struct unit_name<tesla>
{
	static constexpr const char mp_str[] = "tesla";
};

template <>
struct unit_symbol<tesla>
{
	static constexpr const char mp_str[] = "T";
};

// derived
typedef make_scaled_unit_t<scales::milli, tesla> millitesla;
// TODO

} // namespace units
} // namespace eagine

#endif //include guard

