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

namespace eagine {
namespace units {
namespace bits {

template <typename Head, typename Tail>
struct dims;

template <typename Dims1, typename Dims2>
struct dim_add;

template <typename Dims1, typename Dims2>
struct dim_sub;

} // namespace bits

namespace base {

template <typename Derived>
struct dimension;

template <typename Dimension, typename Derived>
struct unit;

template <typename Unit>
struct unit_name;

template <typename Unit>
struct unit_symbol;

template <typename Scale, typename Unit>
struct scaled_unit;

template <typename Dimension>
struct dim_num;

} // base

struct si;

template <typename System>
struct system_id;

template <typename Unit>
struct dim_name;

template <typename Unit>
struct unit_name;

template <typename Unit>
struct unit_symbol;

template <typename Dims, typename System>
struct unit;

template <typename Dims, typename Scales, typename System>
struct scaled_unit;

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
struct mul_result;

template <typename U1, typename U2>
using mul_result_t = typename mul_result<U1, U2>::type;

template <typename U1, typename U2>
struct div_result;

template <typename U1, typename U2>
using div_result_t = typename div_result<U1, U2>::type;

template <typename U1, typename U2>
struct is_convertible;

template <typename U1, typename U2>
constexpr bool is_convertible_v = is_convertible<U1, U2>::value;

} // namespace units
} // namespace eagine

#endif //include guard

