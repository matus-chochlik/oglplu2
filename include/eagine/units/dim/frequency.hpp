/**
 *  @file eagine/unit/dim/frequency.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_FREQUENCY_1512222148_HPP
#define EAGINE_UNITS_DIM_FREQUENCY_1512222148_HPP

#include "../dimension.hpp"

namespace eagine {
namespace units {

typedef decltype(number_of_cycles()/time()) frequency;

template <>
struct dim_name<frequency>
{
	static constexpr const char mp_str[] = "frequency";
};

} // namespace units
} // namespace eagine

#endif //include guard

