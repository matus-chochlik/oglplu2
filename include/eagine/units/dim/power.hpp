/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIM_POWER_HPP
#define EAGINE_UNITS_DIM_POWER_HPP

#include "energy.hpp"

namespace eagine::units {

using power = decltype(energy() / time());

template <>
struct name_of<power> {
    static constexpr const char mp_str[] = "power";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_POWER_HPP
