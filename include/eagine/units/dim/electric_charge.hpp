/// @file eagine/unit/dim/electric_charge.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIM_ELECTRIC_CHARGE_HPP
#define EAGINE_UNITS_DIM_ELECTRIC_CHARGE_HPP

#include "../dimension.hpp"

namespace eagine::units {

using electric_charge = decltype(electric_current() * time());

template <>
struct name_of<electric_charge> {
    static constexpr const char mp_str[] = "electric charge";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_ELECTRIC_CHARGE_HPP
