/// @file eagine/units/unit/si/common.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_UNITS_UNIT_SI_COMMON_HPP
#define EAGINE_UNITS_UNIT_SI_COMMON_HPP

#include "../../base_dim.hpp"
#include "../../base_scaled_unit.hpp"
#include "../../base_unit.hpp"
#include "../../scaled_unit.hpp"
#include "../../unit.hpp"

namespace eagine::units {

// international system of units
struct si {
    template <typename BaseDim>
    struct base_unit;
};

template <>
struct system_id<si> : int_constant<0> {};

template <>
struct si::base_unit<nothing_t> : nothing_t {};

template <typename Dim>
struct si::base_unit<base::dimension<Dim>> : si::base_unit<Dim> {};

} // namespace eagine::units

#endif // EAGINE_UNITS_UNIT_SI_COMMON_HPP
