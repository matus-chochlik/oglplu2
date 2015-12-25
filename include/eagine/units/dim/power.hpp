/**
 *  @file eagine/unit/dim/power.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_POWER_1512222148_HPP
#define EAGINE_UNITS_DIM_POWER_1512222148_HPP

#include "force.hpp"

namespace eagine {
namespace units {

typedef decltype(energy()/time()) power;

template <>
struct dim_name<power>
{
	static constexpr const char mp_str[] = "power";
};

} // namespace units
} // namespace eagine

#endif //include guard

