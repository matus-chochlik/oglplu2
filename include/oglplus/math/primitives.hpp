/**
 *  @file oglplus/math/primitives.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_MATH_PRIMITIVES_HPP
#define OGLPLUS_MATH_PRIMITIVES_HPP

#include "config.hpp"
#include <eagine/math/primitives.hpp>

namespace oglplus {

using line = eagine::math::line<GLfloat, math_use_simd>;
using sphere = eagine::math::sphere<GLfloat, math_use_simd>;

} // namespace oglplus

#endif // OGLPLUS_MATH_PRIMITIVES_HPP
