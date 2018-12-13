/**
 *  @file eagine/unit/dim/angular_velocity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_ANGULAR_VELOCITY_1512222148_HPP
#define EAGINE_UNITS_DIM_ANGULAR_VELOCITY_1512222148_HPP

#include "../dimension.hpp"

namespace eagine {
namespace units {

using angular_velocity = decltype(angle() / time());

template <>
struct dim_name<angular_velocity> {
    static constexpr const char mp_str[] = "angular velocity";
};

} // namespace units
} // namespace eagine

#endif // include guard
