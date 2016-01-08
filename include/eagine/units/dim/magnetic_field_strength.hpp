/**
 *  @file eagine/unit/dim/magnetic_field_strength.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_MAGNETIC_FIELD_STRENGTH_1512222148_HPP
#define EAGINE_UNITS_DIM_MAGNETIC_FIELD_STRENGTH_1512222148_HPP

#include "magnetic_flux.hpp"
#include "area.hpp"

namespace eagine {
namespace units {

typedef decltype(magnetic_flux()/area()) magnetic_field_strength;

template <>
struct dim_name<magnetic_field_strength>
{
	static constexpr const char mp_str[] = "magnetic field strength";
};

} // namespace units
} // namespace eagine

#endif //include guard

