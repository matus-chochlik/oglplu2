/**
 *  @file eagine/unit/unit.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNIT_UNIT_1308281038_HPP
#define EAGINE_UNIT_UNIT_1308281038_HPP

#include "fwd.hpp"
#include "traits.hpp"
#include "detail.hpp"

namespace eagine {
namespace units {

template <typename Dims, typename System>
struct unit
{
	typedef Dims dimension;
	typedef System system;
	typedef scales::one scale;
	typedef unit type;
};

// value conv
template <typename D1, typename D2, typename S>
struct value_conv<unit<D1, S>, unit<D2, S>>
{
	typedef value_conv type;

	template <typename T>
	static constexpr inline T apply(T v)
	{
		return v;
	}
};

// add_result
template <typename D, typename S>
struct add_result<unit<D, S>, unit<D, S>>
 : unit<D, S>
{ };

// sub_result
template <typename D, typename S>
struct sub_result<unit<D, S>, unit<D, S>>
 : unit<D, S>
{ };

// mul_result
template <typename D1, typename D2, typename S>
struct mul_result<unit<D1, S>, unit<D2, S>>
 : unit<bits::dim_add_t<D1, D2>, S>
{ };

// div_result
template <typename D1, typename D2, typename S>
struct div_result<unit<D1, S>, unit<D2, S>>
 : unit<bits::dim_sub_t<D1, D2>, S>
{ };

// quotation
template <typename U>
static constexpr inline
std::enable_if_t<
	is_unit_v<U>,
	lit_result_t<U>
> operator !(U) noexcept { return {}; }

// addition
template <typename U1, typename U2>
static constexpr inline
std::enable_if_t<
	is_unit_v<U1> && is_unit_v<U2>,
	add_result_t<U1, U2>
> operator + (U1, U2) noexcept { return {}; }

// subtraction
template <typename U1, typename U2>
static constexpr inline
std::enable_if_t<
	is_unit_v<U1> && is_unit_v<U2>,
	sub_result_t<U1, U2>
> operator - (U1, U2) noexcept { return {}; }

// multiplication
template <typename U1, typename U2>
static constexpr inline
std::enable_if_t<
	is_unit_v<U1> && is_unit_v<U2>,
	mul_result_t<U1, U2>
> operator * (U1, U2) noexcept { return {}; }

// division
template <typename U1, typename U2>
static constexpr inline
std::enable_if_t<
	is_unit_v<U1> && is_unit_v<U2>,
	div_result_t<U1, U2>
> operator / (U1, U2) noexcept { return {}; }

} // namespace units
} // namespace eagine

#endif //include guard

