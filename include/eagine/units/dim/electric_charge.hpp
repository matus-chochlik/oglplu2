/**
 *  @file eagine/unit/dim/electric_charge.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_ELECTRIC_CHARGE_1512222148_HPP
#define EAGINE_UNITS_DIM_ELECTRIC_CHARGE_1512222148_HPP

#include "../dimension.hpp"

namespace eagine {
namespace units {

typedef decltype(electric_current()*time()) electric_charge;

template <>
struct dim_name<electric_charge>
{
	static constexpr const char mp_str[] = "electric charge";
};

} // namespace units
} // namespace eagine

#endif //include guard

