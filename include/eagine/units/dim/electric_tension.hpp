/// @file eagine/unit/dim/electric_tension.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIM_ELECTRIC_TENSION_HPP
#define EAGINE_UNITS_DIM_ELECTRIC_TENSION_HPP

#include "power.hpp"

namespace eagine::units {

using electric_tension = decltype(power() / electric_current());

template <>
struct name_of<electric_tension> {
    static constexpr const char mp_str[] = "electric tension";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_ELECTRIC_TENSION_HPP
