/**
 *  @file oglplus/math/vector.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_MATH_VECTOR_1509260923_HPP
#define OGLPLUS_MATH_VECTOR_1509260923_HPP

#include <eagine/math/tvec.hpp>

namespace oglplus {

using eagine::math::vector;
using eagine::math::tvec;

template <typename T, bool V = true>
using vec2 = tvec<T, 2, V>;

template <typename T, bool V = true>
using vec3 = tvec<T, 3, V>;

template <typename T, bool V = true>
using vec4 = tvec<T, 4, V>;

} // namespace oglplus

#endif // include guard
