/**
 *  @file oglplus/math/matrix.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_MATH_MATRIX_HPP
#define OGLPLUS_MATH_MATRIX_HPP

#include "config.hpp"
#include <eagine/math/tmat.hpp>

namespace eagine {
namespace oglp {

using math::matrix;

template <
  typename T,
  unsigned C,
  unsigned R,
  bool RM = false,
  bool V = math_use_simd>
using tmat = math::tmat<T, C, R, RM, V>;

using mat2 = tmat<GLfloat, 2, 2>;
using mat2x3 = tmat<GLfloat, 2, 3>;
using mat2x4 = tmat<GLfloat, 2, 4>;

using mat3x2 = tmat<GLfloat, 3, 2>;
using mat3 = tmat<GLfloat, 3, 3>;
using mat3x4 = tmat<GLfloat, 3, 4>;

using mat4x2 = tmat<GLfloat, 4, 2>;
using mat4x3 = tmat<GLfloat, 4, 3>;
using mat4 = tmat<GLfloat, 4, 4>;

} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_MATH_MATRIX_HPP
