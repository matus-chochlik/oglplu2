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
struct scaled_unit
{
	typedef Dims dimension;
	typedef Scales scales;
	typedef System system;
	typedef scaled_unit type;

	struct scale
	{
		typedef scale type;

		template <typename ... DimPow>
		struct _impl : bits::_sc_unit_sc_hlp<Scales, System>
		{
			typedef _impl type;

			template <typename T>
			friend constexpr inline
			auto operator * (T v, _impl i)
			noexcept
			{
				return i._hlp(
					std::true_type(),
					v, DimPow()...
				);
			}

			template <typename T>
			friend constexpr inline
			auto operator / (T v, _impl i)
			noexcept
			{
				return i._hlp(
					std::false_type(),
					v, DimPow()...
				);
			}
		};

		static constexpr bits::apply_t<
			_impl,
			Dims
		> value = {};
	};
};

// make_scaled_unit
template <typename BaseScaledUnit, typename System>
struct make_scaled_unit;

template <typename BaseScaledUnit, typename System>
using make_scaled_unit_t =
	typename make_scaled_unit<BaseScaledUnit, System>::type;

template <typename Scale, typename BaseUnit, typename System>
struct make_scaled_unit<base::scaled_unit<Scale, BaseUnit>, System>
 : scaled_unit<
	dimension<typename BaseUnit::dimension, 1>,
	bits::unit_scales<
		bits::uni_sca<BaseUnit, Scale>,
		nothing_t
	>,
	System
>
{ };

template <typename D1, typename D2, typename US, typename S>
struct value_conv<scaled_unit<D1, US, S>, unit<D2, S>>
{
	typedef value_conv type;

	template <typename T>
	static constexpr inline T apply(T v)
	{
		return T(v*scaled_unit<D1, US, S>::scale::value);
	}
};

template <typename D1, typename D2, typename US, typename S>
struct value_conv<unit<D1, S>, scaled_unit<D2, US, S>>
{
	typedef value_conv type;

	template <typename T>
	static constexpr inline T apply(T v)
	{
		return v/scaled_unit<D1, US, S>::scale::value;
	}
};

template <typename D1, typename D2, typename US1, typename US2, typename S>
struct value_conv<scaled_unit<D1, US1, S>, scaled_unit<D2, US2, S>>
{
	typedef value_conv type;

	template <typename T>
	static constexpr inline T apply(T v)
	{
		return v*
			scaled_unit<D1, US1, S>::scale::value/
			scaled_unit<D1, US2, S>::scale::value;
	}
};

template <typename D, typename S>
struct lit_result<unit<D, S>>
 : scaled_unit<D, bits::unit_scales<nothing_t, nothing_t>, S>
{ };

template <typename D, typename US, typename S>
struct lit_result<scaled_unit<D, US, S>>
 : scaled_unit<D, US, S>
{ };

template <typename D, typename US, typename S>
struct add_result<scaled_unit<D, US, S>, unit<D, S>>
 : unit<D, S>
{ };

template <typename D, typename US, typename S>
struct add_result<unit<D, S>, scaled_unit<D, US, S>>
 : unit<D, S>
{ };

template <typename D, typename US1, typename US2, typename S>
struct add_result<scaled_unit<D, US1, S>, scaled_unit<D, US2, S>>
 : scaled_unit<D, US1, S>
{ };

template <typename D, typename US, typename S>
struct sub_result<scaled_unit<D, US, S>, unit<D, S>>
 : unit<D, S>
{ };

template <typename D, typename US, typename S>
struct sub_result<unit<D, S>, scaled_unit<D, US, S>>
 : unit<D, S>
{ };

template <typename D, typename US1, typename US2, typename S>
struct sub_result<scaled_unit<D, US1, S>, scaled_unit<D, US2, S>>
 : scaled_unit<D, US1, S>
{ };

template <typename D1, typename D2, typename US, typename S>
struct mul_result<scaled_unit<D1, US, S>, unit<D2, S>>
 : unit<bits::dim_add_t<D1, D2>, S>
{ };

template <typename D1, typename D2, typename US, typename S>
struct mul_result<unit<D1, S>, scaled_unit<D2, US, S>>
 : unit<bits::dim_add_t<D1, D2>, S>
{ };

template <typename D1, typename D2, typename US1, typename US2, typename S>
struct mul_result<scaled_unit<D1, US1, S>, scaled_unit<D2, US2, S>>
 : scaled_unit<bits::dim_add_t<D1, D2>, bits::merge_t<US1, US2>, S>
{ };

template <typename D1, typename D2, typename US, typename S>
struct div_result<scaled_unit<D1, US, S>, unit<D2, S>>
 : unit<bits::dim_sub_t<D1, D2>, S>
{ };

template <typename D1, typename D2, typename US, typename S>
struct div_result<unit<D1, S>, scaled_unit<D2, US, S>>
 : unit<bits::dim_sub_t<D1, D2>, S>
{ };

template <typename D1, typename D2, typename US1, typename US2, typename S>
struct div_result<scaled_unit<D1, US1, S>, scaled_unit<D2, US2, S>>
 : scaled_unit<bits::dim_sub_t<D1, D2>, bits::merge_t<US1, US2>, S>
{ };

} // namespace units
} // namespace eagine

#endif //include guard

