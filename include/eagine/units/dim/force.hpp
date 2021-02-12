/// @file eagine/unit/dim/force.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIM_FORCE_HPP
#define EAGINE_UNITS_DIM_FORCE_HPP

#include "acceleration.hpp"

namespace eagine::units {

using force = decltype(acceleration() * mass());

template <>
struct name_of<force> {
    static constexpr const char mp_str[] = "force";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_FORCE_HPP
