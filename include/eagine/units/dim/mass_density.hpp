/**
 *  @file eagine/unit/dim/mass_density.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_MASS_DENSITY_1512222148_HPP
#define EAGINE_UNITS_DIM_MASS_DENSITY_1512222148_HPP

#include "volume.hpp"

namespace eagine {
namespace units {

typedef decltype(mass() / volume()) mass_density;

template <>
struct dim_name<mass_density> {
    static constexpr const char mp_str[] = "mass density";
};

} // namespace units
} // namespace eagine

#endif // include guard
