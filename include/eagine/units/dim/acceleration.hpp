/**
 *  @file eagine/unit/dim/acceleration.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_ACCELERATION_1512222148_HPP
#define EAGINE_UNITS_DIM_ACCELERATION_1512222148_HPP

#include "velocity.hpp"

namespace eagine {
namespace units {

using acceleration = decltype(velocity() / time());

template <>
struct dim_name<acceleration> {
    static constexpr const char mp_str[] = "acceleration";
};

} // namespace units
} // namespace eagine

#endif // include guard
