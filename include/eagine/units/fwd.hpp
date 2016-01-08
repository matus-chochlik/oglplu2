/**
 *  @file eagine/unit/fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_FWD_1512222148_HPP
#define EAGINE_UNITS_FWD_1512222148_HPP

#include "../type_traits.hpp"
#include "../nothing.hpp"

namespace eagine {
namespace units {
namespace bits {

template <typename Head, typename Tail>
struct dims;

template <typename Dim, typename Pow>
struct dim_pow;

template <typename Head, typename Tail>
struct unit_scales;

template <typename Unit, typename Scale>
struct uni_sca;

} // namespace bits

namespace base {

template <typename Derived>
struct dimension;

template <typename Dimension, typename Derived>
struct unit;

template <typename Scale, typename Unit>
struct scaled_unit;

} // base

struct si;

template <typename System>
struct system_id;

template <typename BaseDim, int Pow>
using dimension = bits::dims<
	bits::dim_pow<BaseDim, int_constant<Pow>>,
	nothing_t
>;

template <typename Dims, typename System>
struct unit;

template <typename Dims, typename Scales, typename System>
struct scaled_dim_unit;

template <typename UnitFrom, typename UnitTo>
struct value_conv;

template <typename U1>
struct lit_result;

template <typename U1>
using lit_result_t = typename lit_result<U1>::type;

template <typename U1, typename U2>
struct add_result;

template <typename U1, typename U2>
using add_result_t = typename add_result<U1, U2>::type;

template <typename U1, typename U2>
struct sub_result;

template <typename U1, typename U2>
using sub_result_t = typename sub_result<U1, U2>::type;

template <typename U1, typename U2>
struct mul_l_operand;

template <typename U1, typename U2>
using mul_l_operand_t = typename mul_l_operand<U1, U2>::type;

template <typename U1, typename U2>
struct mul_r_operand;

template <typename U1, typename U2>
using mul_r_operand_t = typename mul_r_operand<U1, U2>::type;

template <typename U1, typename U2>
struct mul_result;

template <typename U1, typename U2>
using mul_result_t = typename mul_result<U1, U2>::type;

template <typename U1, typename U2>
struct div_l_operand
 : mul_l_operand<U1, U2>
{ };

template <typename U1, typename U2>
using div_l_operand_t = typename div_l_operand<U1, U2>::type;

template <typename U1, typename U2>
struct div_r_operand
 : mul_r_operand<U1, U2>
{ };

template <typename U1, typename U2>
using div_r_operand_t = typename div_r_operand<U1, U2>::type;

template <typename U1, typename U2>
struct div_result;

template <typename U1, typename U2>
using div_result_t = typename div_result<U1, U2>::type;

template <typename X>
struct dimension_of
 : X::dimension
{ };

template <>
struct dimension_of<nothing_t>
 : nothing_t
{ };

template <typename X>
using dimension_of_t = typename dimension_of<X>::type;

template <typename X, typename Y>
struct same_dimension;

template <typename X, typename Y>
constexpr bool same_dimension_v = same_dimension<X, Y>::value;

template <typename X>
struct is_unit;

template <typename X>
constexpr bool is_unit_v = is_unit<X>::value;

template <typename U1, typename U2>
struct is_convertible;

template <typename U1, typename U2>
constexpr bool is_convertible_v = is_convertible<U1, U2>::value;

} // namespace units
} // namespace eagine

#endif //include guard

