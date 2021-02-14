/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIM_ELECTRICAL_CAPACITANCE_HPP
#define EAGINE_UNITS_DIM_ELECTRICAL_CAPACITANCE_HPP

#include "electric_charge.hpp"
#include "electric_tension.hpp"

namespace eagine::units {

using electrical_capacitance = decltype(electric_charge() / electric_tension());

template <>
struct name_of<electrical_capacitance> {
    static constexpr const char mp_str[] = "electrical capacitance";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_ELECTRICAL_CAPACITANCE_HPP
