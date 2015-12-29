/**
 *  @file eagine/unit/dimension.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIMENSION_1512222148_HPP
#define EAGINE_UNITS_DIMENSION_1512222148_HPP

#include "detail.hpp"
#include "base_dim.hpp"
#include "traits.hpp"

namespace eagine {
namespace units {

// dimension
template <typename BaseDim, int Pow>
using dimension = bits::dims<
	bits::dim_pow<BaseDim, int_constant<Pow>>,
	nothing_t
>;

// multiplication
template <typename D1, typename D2>
std::enable_if_t<
	is_dimension_v<D1> && is_dimension_v<D2>,
	bits::dim_add_t<D1, D2>
> operator * (D1, D2);

// division
template <typename D1, typename D2>
std::enable_if_t<
	is_dimension_v<D1> && is_dimension_v<D2>,
	bits::dim_sub_t<D1, D2>
> operator / (D1, D2);

// base_dimension_power
template <typename Dim, typename BaseDim>
using base_dimension_power = bits::get_pow<Dim, BaseDim>;

// basic dimensions
typedef dimension<base::angle,       1> angle;
typedef dimension<base::solid_angle, 1> solid_angle;

typedef dimension<base::length, 1> length;
typedef dimension<base::mass,   1> mass;
typedef dimension<base::time,   1> time;

typedef dimension<base::temperature,         1> temperature;
typedef dimension<base::electric_current,    1> electric_current;
typedef dimension<base::number_of_cycles,    1> number_of_cycles;
typedef dimension<base::number_of_decays,    1> number_of_decays;
typedef dimension<base::luminous_intensity,  1> luminous_intensity;
typedef dimension<base::amount_of_substance,   1> amount_of_substance;
typedef dimension<base::amount_of_information, 1> amount_of_information;

} // namespace units
} // namespace eagine

#endif //include guard

