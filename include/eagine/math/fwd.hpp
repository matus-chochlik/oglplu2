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

template <typename T, unsigned R, unsigned C, bool RM, bool V>
struct tmat;

} // namespace math
} // namespace eagine

#endif //include guard

