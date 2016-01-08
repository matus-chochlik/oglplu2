/**
 *  @file eagine/unit/dim/magnetic_flux.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_MAGNETIC_FLUX_1512222148_HPP
#define EAGINE_UNITS_DIM_MAGNETIC_FLUX_1512222148_HPP

#include "energy.hpp"

namespace eagine {
namespace units {

typedef decltype(energy()/electric_current()) magnetic_flux;

template <>
struct dim_name<magnetic_flux>
{
	static constexpr const char mp_str[] = "magnetic flux";
};

} // namespace units
} // namespace eagine

#endif //include guard

