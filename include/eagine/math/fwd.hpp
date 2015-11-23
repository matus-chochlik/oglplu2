/**
 *  @file eagine/math/fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_FWD_1509260923_HPP
#define EAGINE_MATH_FWD_1509260923_HPP

#include "../type_traits.hpp"

namespace eagine {
namespace math {

template <typename T, unsigned N, bool V>
struct scalar;

template <typename T, unsigned N, bool V>
struct vector;

template <typename T, unsigned N, bool V>
struct tvec;

template <typename T, unsigned R, unsigned C, bool RM, bool V>
struct matrix;

template <typename X>
struct is_row_major;

template <typename T, unsigned R, unsigned C, bool RM, bool V>
struct tmat;

template <typename T1, typename T2>
struct are_multiplicable
 : std::false_type
{ };

template <typename T1, typename T2>
struct multiplication_result;

} // namespace math
} // namespace eagine

#endif //include guard

