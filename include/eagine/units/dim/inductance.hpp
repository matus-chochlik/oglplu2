/**
 *  @file eagine/unit/dim/inductance.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_INDUCTANCE_1512222148_HPP
#define EAGINE_UNITS_DIM_INDUCTANCE_1512222148_HPP

#include "magnetic_flux.hpp"

namespace eagine {
namespace units {

using inductance = decltype(magnetic_flux() / electric_current());

template <>
struct dim_name<inductance> {
    static constexpr const char mp_str[] = "inductance";
};

} // namespace units
} // namespace eagine

#endif // include guard
