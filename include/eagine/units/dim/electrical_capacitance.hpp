/**
 *  @file eagine/unit/dim/electrical_capacitance.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIM_ELECTRICAL_CAPACITANCE_1512222148_HPP
#define EAGINE_UNITS_DIM_ELECTRICAL_CAPACITANCE_1512222148_HPP

#include "electric_charge.hpp"
#include "electric_tension.hpp"

namespace eagine {
namespace units {

using electrical_capacitance = decltype(electric_charge() / electric_tension());

template <>
struct dim_name<electrical_capacitance> {
    static constexpr const char mp_str[] = "electrical capacitance";
};

} // namespace units
} // namespace eagine

#endif // include guard
