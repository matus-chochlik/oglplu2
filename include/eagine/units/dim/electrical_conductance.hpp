/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIM_ELECTRICAL_CONDUCTANCE_HPP
#define EAGINE_UNITS_DIM_ELECTRICAL_CONDUCTANCE_HPP

#include "electric_tension.hpp"

namespace eagine::units {

using electrical_conductance =
  decltype(electric_current() / electric_tension());

template <>
struct name_of<electrical_conductance> {
    static constexpr const char mp_str[] = "electrical conductance";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_ELECTRICAL_CONDUCTANCE_HPP
