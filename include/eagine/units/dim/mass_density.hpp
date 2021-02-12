/// @file eagine/unit/dim/mass_density.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIM_MASS_DENSITY_HPP
#define EAGINE_UNITS_DIM_MASS_DENSITY_HPP

#include "volume.hpp"

namespace eagine::units {

using mass_density = decltype(mass() / volume());

template <>
struct name_of<mass_density> {
    static constexpr const char mp_str[] = "mass density";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_MASS_DENSITY_HPP
