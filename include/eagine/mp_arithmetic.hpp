/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MP_ARITHMETIC_HPP
#define EAGINE_MP_ARITHMETIC_HPP

#include <type_traits>

namespace eagine {

/// @brief Implementation of addition on types representing numbers.
/// @ingroup metaprogramming
/// @see mp_plus_t
template <typename T1, typename T2>
struct mp_plus;

/// @brief Addition operation on types representing numbers.
/// @ingroup metaprogramming
/// @see mp_plus_v
template <typename T1, typename T2>
using mp_plus_t = typename mp_plus<T1, T2>::type;

/// @brief Addition operation on types representing numbers.
/// @ingroup metaprogramming
/// @see mp_plus_t
template <typename T1, typename T2>
constexpr auto mp_plus_v = mp_plus<T1, T2>::value;

template <typename Int, Int I1, Int I2>
struct mp_plus<std::integral_constant<Int, I1>, std::integral_constant<Int, I2>>
  : std::integral_constant<Int, I1 + I2> {};

/// @brief Implementation of subtraction on types representing numbers.
/// @ingroup metaprogramming
/// @see mp_minus_t
template <typename T1, typename T2>
struct mp_minus;

/// @brief Subtraction operation on types representing numbers.
/// @ingroup metaprogramming
/// @see mp_minus_v
template <typename T1, typename T2>
using mp_minus_t = typename mp_minus<T1, T2>::type;

/// @brief Subtraction operation on types representing numbers.
/// @ingroup metaprogramming
/// @see mp_minus_t
template <typename T1, typename T2>
constexpr auto mp_minus_v = mp_minus<T1, T2>::value;

template <typename Int, Int I1, Int I2>
struct mp_minus<std::integral_constant<Int, I1>, std::integral_constant<Int, I2>>
  : std::integral_constant<Int, I1 - I2> {};

/// @brief Implementation of negation on types representing numbers.
/// @ingroup metaprogramming
/// @see mp_negate_t
template <typename T1>
struct mp_negate;

/// @brief Unary negation operation on types representing numbers.
/// @ingroup metaprogramming
/// @see mp_negate_v
template <typename T1>
using mp_negate_t = typename mp_negate<T1>::type;

/// @brief Unary negation operation on types representing numbers.
/// @ingroup metaprogramming
/// @see mp_negate_t
template <typename T1>
constexpr auto mp_negate_v = mp_negate<T1>::value;

template <typename Int, Int I1>
struct mp_negate<std::integral_constant<Int, I1>>
  : std::integral_constant<Int, -I1> {};

} // namespace eagine

#endif // EAGINE_MP_ARITHMETIC_HPP
