/**
 *  @file eagine/unit/scaled_unit.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_SCALED_UNIT_1512222148_HPP
#define EAGINE_UNITS_SCALED_UNIT_1512222148_HPP

#include "dimension.hpp"
#include "base_scaled_unit.hpp"
#include "unit.hpp"
#include <cmath>

namespace eagine {
namespace units {

template <typename Dims, typename Scales, typename System>
struct scaled_dim_unit
{
	typedef Dims dimension;
	typedef Scales scales;
	typedef System system;
	typedef scaled_dim_unit type;

	struct scale
	{
		typedef scale type;

		typedef bits::_sc_unit_sc_hlp<Scales, System> _impl;
		typedef bits::dim_pow<nothing_t, int_constant<0>> _ndp;

		template <typename T>
		static constexpr inline
		auto mul(T v)
		{
			return _impl::_hlp(
				std::true_type(),
				v, bits::dims<_ndp, Dims>()
			);
		}

		template <typename T>
		static constexpr inline
		auto div(T v)
		{
			return _impl::_hlp(
				std::false_type(),
				v, bits::dims<_ndp, Dims>()
			);
		}
	};
};

// make_scaled_base_dim_unit
template <typename BaseScaledUnit, typename System>
struct make_scaled_base_dim_unit;

template <typename BaseScaledUnit, typename System>
using make_scaled_base_dim_unit_t =
	typename make_scaled_base_dim_unit<BaseScaledUnit, System>::type;

template <typename Scale, typename BaseUnit, typename System>
struct make_scaled_base_dim_unit<base::scaled_unit<Scale, BaseUnit>, System>
 : scaled_dim_unit<
	dimension<dimension_of_t<BaseUnit>, 1>,
	bits::unit_scales<
		bits::uni_sca<BaseUnit, Scale>,
		nothing_t
	>,
	System
> { };

template <typename Scale, typename UnitScales>
using add_none_unit_scale_t = bits::unit_scales<
	bits::uni_sca<nothing_t, Scale>,
	UnitScales
>;

// make_scaled_unit
template <typename Scale, typename Unit>
struct make_scaled_unit;

template <typename Scale, typename Unit>
using make_scaled_unit_t = typename make_scaled_unit<Scale, Unit>::type;

template <typename Scale, typename Dimension, typename System>
struct make_scaled_unit<Scale, unit<Dimension, System>>
 : scaled_dim_unit<
	Dimension,
	add_none_unit_scale_t<Scale, nothing_t>,
	System
> { };

// is_convertible
template <typename D, typename US, typename S>
struct is_convertible<scaled_dim_unit<D, US, S>, unit<D, S>>
 : std::true_type
{ };

template <typename D, typename US, typename S>
struct is_convertible<unit<D, S>, scaled_dim_unit<D, US, S>>
 : std::true_type
{ };

template <typename D, typename US, typename S>
struct is_convertible<scaled_dim_unit<D, US, S>, scaled_dim_unit<D, US, S>>
 : std::true_type
{ };

template <typename D, typename US1, typename US2, typename S>
struct is_convertible<scaled_dim_unit<D, US1, S>, scaled_dim_unit<D, US2, S>>
 : std::true_type
{ };

// value_conv
template <typename D, typename US, typename S>
struct value_conv<scaled_dim_unit<D, US, S>, unit<D, S>>
{
	template <typename T>
	constexpr inline
	auto operator()(T v) const
	{
		return scaled_dim_unit<D, US, S>::scale::mul(v);
	}
};

template <typename D, typename AS, typename US, typename System>
struct value_conv<
	scaled_dim_unit<D, add_none_unit_scale_t<AS, US>, System>,
	unit<D, System>
>
{
	template <typename T>
	constexpr inline
	auto operator()(T v) const
	{
		return AS::mul(v);
	}
};

template <typename D, typename US, typename S>
struct value_conv<unit<D, S>, scaled_dim_unit<D, US, S>>
{
	template <typename T>
	constexpr inline
	auto operator()(T v) const
	{
		return scaled_dim_unit<D, US, S>::scale::div(v);
	}
};

template <typename D, typename AS, typename US, typename System>
struct value_conv<
	unit<D, System>,
	scaled_dim_unit<D, add_none_unit_scale_t<AS, US>, System>
>
{
	template <typename T>
	constexpr inline
	auto operator()(T v) const
	{
		return AS::div(v);
	}
};

template <typename D, typename US, typename S>
struct value_conv<scaled_dim_unit<D, US, S>, scaled_dim_unit<D, US, S>>
 : trivial_value_conv
{ };

template <typename D, typename US1, typename US2, typename S>
struct value_conv<scaled_dim_unit<D, US1, S>, scaled_dim_unit<D, US2, S>>
{
	template <typename T>
	constexpr inline
	auto operator()(T v) const
	{
		return scaled_dim_unit<D, US2, S>::scale::div(
			scaled_dim_unit<D, US1, S>::scale::mul(v)
		);
	}
};

template <typename D, typename AS1, typename AS2, typename US, typename System>
struct value_conv<
	scaled_dim_unit<D, add_none_unit_scale_t<AS1, US>, System>,
	scaled_dim_unit<D, add_none_unit_scale_t<AS2, US>, System>
>
{
	template <typename T>
	constexpr inline
	auto operator()(T v) const
	{
		return AS2::div(AS1::mul(v));
	}
};

// lit_result
template <typename D, typename S>
struct lit_result<unit<D, S>>
 : scaled_dim_unit<D, bits::unit_scales<nothing_t, nothing_t>, S>
{ };

template <typename D, typename US, typename S>
struct lit_result<scaled_dim_unit<D, US, S>>
 : scaled_dim_unit<D, US, S>
{ };

// add_result
template <typename D, typename US, typename S>
struct add_result<scaled_dim_unit<D, US, S>, unit<D, S>>
 : unit<D, S>
{ };

template <typename D, typename US, typename S>
struct add_result<unit<D, S>, scaled_dim_unit<D, US, S>>
 : unit<D, S>
{ };

template <typename D, typename US, typename S>
struct add_result<scaled_dim_unit<D, US, S>, scaled_dim_unit<D, US, S>>
 : scaled_dim_unit<D, US, S>
{ };

template <typename D, typename US1, typename US2, typename S>
struct add_result<scaled_dim_unit<D, US1, S>, scaled_dim_unit<D, US2, S>>
 : scaled_dim_unit<D, US1, S>
{ };

// sub_result
template <typename D, typename US, typename S>
struct sub_result<scaled_dim_unit<D, US, S>, unit<D, S>>
 : unit<D, S>
{ };

template <typename D, typename US, typename S>
struct sub_result<unit<D, S>, scaled_dim_unit<D, US, S>>
 : unit<D, S>
{ };

template <typename D, typename US, typename S>
struct sub_result<scaled_dim_unit<D, US, S>, scaled_dim_unit<D, US, S>>
 : scaled_dim_unit<D, US, S>
{ };

template <typename D, typename US1, typename US2, typename S>
struct sub_result<scaled_dim_unit<D, US1, S>, scaled_dim_unit<D, US2, S>>
 : scaled_dim_unit<D, US1, S>
{ };

// mul_l_operand
template <typename D1, typename D2, typename US, typename S>
struct mul_l_operand<scaled_dim_unit<D1, US, S>, unit<D2, S>>
 : unit<D1, S>
{ };

template <typename D1, typename D2, typename US, typename S>
struct mul_l_operand<unit<D1, S>, scaled_dim_unit<D2, US, S>>
 : unit<D1, S>
{ };

template <typename D1, typename D2, typename US1, typename US2, typename S>
struct mul_l_operand<scaled_dim_unit<D1, US1, S>, scaled_dim_unit<D2, US2, S>>
 : scaled_dim_unit<D1, bits::merge_t<US1, US2>, S>
{ };

// mul_r_operand
template <typename D1, typename D2, typename US, typename S>
struct mul_r_operand<scaled_dim_unit<D1, US, S>, unit<D2, S>>
 : unit<D2, S>
{ };

template <typename D1, typename D2, typename US, typename S>
struct mul_r_operand<unit<D1, S>, scaled_dim_unit<D2, US, S>>
 : unit<D2, S>
{ };

template <typename D1, typename D2, typename US1, typename US2, typename S>
struct mul_r_operand<scaled_dim_unit<D1, US1, S>, scaled_dim_unit<D2, US2, S>>
 : scaled_dim_unit<D2, bits::merge_t<US1, US2>, S>
{ };

// mul_result
template <typename D1, typename D2, typename US, typename S>
struct mul_result<scaled_dim_unit<D1, US, S>, unit<D2, S>>
 : unit<bits::dim_add_t<D1, D2>, S>
{ };

template <typename D1, typename D2, typename US, typename S>
struct mul_result<unit<D1, S>, scaled_dim_unit<D2, US, S>>
 : unit<bits::dim_add_t<D1, D2>, S>
{ };

template <typename D1, typename D2, typename US1, typename US2, typename S>
struct mul_result<scaled_dim_unit<D1, US1, S>, scaled_dim_unit<D2, US2, S>>
 : scaled_dim_unit<bits::dim_add_t<D1, D2>, bits::merge_t<US1, US2>, S>
{ };

// div_result
template <typename D1, typename D2, typename US, typename S>
struct div_result<scaled_dim_unit<D1, US, S>, unit<D2, S>>
 : unit<bits::dim_sub_t<D1, D2>, S>
{ };

template <typename D1, typename D2, typename US, typename S>
struct div_result<unit<D1, S>, scaled_dim_unit<D2, US, S>>
 : unit<bits::dim_sub_t<D1, D2>, S>
{ };

template <typename D1, typename D2, typename US1, typename US2, typename S>
struct div_result<scaled_dim_unit<D1, US1, S>, scaled_dim_unit<D2, US2, S>>
 : scaled_dim_unit<bits::dim_sub_t<D1, D2>, bits::merge_t<US1, US2>, S>
{ };

} // namespace units
} // namespace eagine

#endif //include guard

