/// @file eagine/unit/dimension.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_DIMENSION_HPP
#define EAGINE_UNITS_DIMENSION_HPP

#include "base_dim.hpp"
#include "detail.hpp"
#include "traits.hpp"

namespace eagine::units {

// multiplication
template <typename D1, typename D2>
static inline auto operator*(D1, D2) noexcept -> std::enable_if_t<
  is_dimension_v<D1> && is_dimension_v<D2>,
  bits::dim_add_t<D1, D2>> {
    return {};
}

// division
template <typename D1, typename D2>
static inline auto operator/(D1, D2) noexcept -> std::enable_if_t<
  is_dimension_v<D1> && is_dimension_v<D2>,
  bits::dim_sub_t<D1, D2>> {
    return {};
}

// base_dimension_power
template <typename Dim, typename BaseDim>
using base_dimension_power = bits::get_pow<Dim, BaseDim>;

// basic dimensions
using angle = dimension<base::angle, 1>;
using solid_angle = dimension<base::solid_angle, 1>;

using length = dimension<base::length, 1>;
using mass = dimension<base::mass, 1>;
using time = dimension<base::time, 1>;

using temperature = dimension<base::temperature, 1>;
using electric_current = dimension<base::electric_current, 1>;
using number_of_cycles = dimension<base::number_of_cycles, 1>;
using number_of_decays = dimension<base::number_of_decays, 1>;
using luminous_intensity = dimension<base::luminous_intensity, 1>;
using amount_of_substance = dimension<base::amount_of_substance, 1>;
using amount_of_information = dimension<base::amount_of_information, 1>;

} // namespace eagine::units

#endif // EAGINE_UNITS_DIMENSION_HPP
