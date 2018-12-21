/**
 *  @file eagine/mp_arithmetic.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MP_ARITHMETIC_HPP
#define EAGINE_MP_ARITHMETIC_HPP

#include <type_traits>

namespace eagine {

template <typename T1, typename T2>
struct mp_plus;

template <typename T1, typename T2>
using mp_plus_t = typename mp_plus<T1, T2>::type;

template <typename T1, typename T2>
constexpr auto mp_plus_v = mp_plus<T1, T2>::value;

template <typename Int, Int I1, Int I2>
struct mp_plus<std::integral_constant<Int, I1>, std::integral_constant<Int, I2>>
  : std::integral_constant<Int, I1 + I2> {};

template <typename T1, typename T2>
struct mp_minus;

template <typename T1, typename T2>
using mp_minus_t = typename mp_minus<T1, T2>::type;

template <typename T1, typename T2>
constexpr auto mp_minus_v = mp_minus<T1, T2>::value;

template <typename Int, Int I1, Int I2>
struct mp_minus<
  std::integral_constant<Int, I1>,
  std::integral_constant<Int, I2>> : std::integral_constant<Int, I1 - I2> {};

template <typename T1>
struct mp_negate;

template <typename T1>
using mp_negate_t = typename mp_negate<T1>::type;

template <typename T1>
constexpr auto mp_negate_v = mp_negate<T1>::value;

template <typename Int, Int I1>
struct mp_negate<std::integral_constant<Int, I1>>
  : std::integral_constant<Int, -I1> {};

} // namespace eagine

#endif // EAGINE_MP_ARITHMETIC_HPP
