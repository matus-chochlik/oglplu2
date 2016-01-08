/**
 *  @file eagine/unit/dim/area.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_AREA_1512222148_HPP
#define EAGINE_UNITS_DIM_AREA_1512222148_HPP

#include "../dimension.hpp"

namespace eagine {
namespace units {

typedef decltype(length()*length()) area;

template <>
struct dim_name<area>
{
	static constexpr const char mp_str[] = "area";
};

} // namespace units
} // namespace eagine

#endif //include guard

