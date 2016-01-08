/**
 *  @file eagine/unit/dim/electrical_conductance.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_ELECTRICAL_CONDUCTANCE_1512222148_HPP
#define EAGINE_UNITS_DIM_ELECTRICAL_CONDUCTANCE_1512222148_HPP

#include "electric_tension.hpp"

namespace eagine {
namespace units {

typedef decltype(electric_current()/electric_tension()) electrical_conductance;

template <>
struct dim_name<electrical_conductance>
{
	static constexpr const char mp_str[] = "electrical conductance";
};

} // namespace units
} // namespace eagine

#endif //include guard

