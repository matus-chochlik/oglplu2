/// @file eagine/unit/dim/pressure.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIM_PRESSURE_HPP
#define EAGINE_UNITS_DIM_PRESSURE_HPP

#include "area.hpp"
#include "force.hpp"

namespace eagine::units {

using pressure = decltype(force() / area());

template <>
struct name_of<pressure> {
    static constexpr const char mp_str[] = "pressure";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_PRESSURE_HPP
