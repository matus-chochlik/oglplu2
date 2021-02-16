/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIM_ENERGY_HPP
#define EAGINE_UNITS_DIM_ENERGY_HPP

#include "force.hpp"

namespace eagine::units {

using energy = decltype(force() * length());

template <>
struct name_of<energy> {
    static constexpr const char mp_str[] = "energy";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_ENERGY_HPP
