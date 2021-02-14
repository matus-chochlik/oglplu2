/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_FWD_HPP
#define EAGINE_MATH_FWD_HPP

#include <type_traits>

namespace eagine::math {

template <typename T, int N, bool V>
struct scalar;

template <typename T, int N, bool V>
struct vector;

template <typename T, int N, bool V>
struct tvec;

template <typename T, int R, int C, bool RM, bool V>
struct matrix;

template <typename X>
struct is_row_major;

template <typename T, int R, int C, bool RM, bool V>
struct tmat;

template <typename T1, typename T2>
struct are_multiplicable : std::false_type {};

template <typename T1, typename T2>
struct multiplication_result;

} // namespace eagine::math

#endif // EAGINE_MATH_FWD_HPP
