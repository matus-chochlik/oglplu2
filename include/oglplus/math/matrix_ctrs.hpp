/// @file oglplus/math/matrix_ctrs.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_MATH_MATRIX_CTRS_HPP
#define OGLPLUS_MATH_MATRIX_CTRS_HPP

#include <eagine/math/matrix_reflection.hpp>
#include <eagine/math/matrix_rotation.hpp>
#include <eagine/math/matrix_scale.hpp>
#include <eagine/math/matrix_translation.hpp>

#include <eagine/math/matrix_looking_at.hpp>
#include <eagine/math/matrix_orbiting.hpp>

#include <eagine/math/matrix_ortho.hpp>
#include <eagine/math/matrix_perspective.hpp>

#include "config.hpp"
#include <oglplus/gl_api/config.hpp>

namespace eagine::oglp {

using matrix_uniform_scale =
  math::matrix_uniform_scale<gl_types::float_type, math_use_simd>;

using matrix_scale = math::matrix_scale<gl_types::float_type, math_use_simd>;

using matrix_rotation_x =
  math::matrix_rotation_x<gl_types::float_type, math_use_simd>;

using matrix_rotation_y =
  math::matrix_rotation_y<gl_types::float_type, math_use_simd>;

using matrix_rotation_z =
  math::matrix_rotation_z<gl_types::float_type, math_use_simd>;

using matrix_translation =
  math::matrix_translation<gl_types::float_type, math_use_simd>;

using matrix_reflection_x =
  math::matrix_reflection_x<gl_types::float_type, math_use_simd>;

using matrix_reflection_y =
  math::matrix_reflection_y<gl_types::float_type, math_use_simd>;

using matrix_reflection_z =
  math::matrix_reflection_z<gl_types::float_type, math_use_simd>;

using matrix_orbiting_y_up =
  math::matrix_orbiting_y_up<gl_types::float_type, math_use_simd>;

using matrix_looking_at_y_up =
  math::matrix_looking_at_y_up<gl_types::float_type, math_use_simd>;

using matrix_ortho = math::matrix_ortho<gl_types::float_type, math_use_simd>;

using matrix_perspective =
  math::matrix_perspective<gl_types::float_type, math_use_simd>;

} // namespace eagine::oglp

#endif // OGLPLUS_MATH_MATRIX_CTRS_HPP
