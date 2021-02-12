/// @file eagine/unit/dim/velocity.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIM_VELOCITY_HPP
#define EAGINE_UNITS_DIM_VELOCITY_HPP

#include "../dimension.hpp"

namespace eagine::units {

using velocity = decltype(length() / time());

template <>
struct name_of<velocity> {
    static constexpr const char mp_str[] = "velocity";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_VELOCITY_HPP
