/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIM_MOMENTUM_HPP
#define EAGINE_UNITS_DIM_MOMENTUM_HPP

#include "velocity.hpp"

namespace eagine::units {

using momentum = decltype(velocity() * mass());

template <>
struct name_of<momentum> {
    static constexpr const char mp_str[] = "momentum";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_MOMENTUM_HPP
