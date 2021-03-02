/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_MATH_MATRIX_HPP
#define OGLPLUS_MATH_MATRIX_HPP

#include "config.hpp"
#include <eagine/math/tmat.hpp>
#include <oglplus/gl_api/config.hpp>

namespace eagine::oglp {

/// @brief Alias for math::matrix.
/// @ingroup gl_utils
using math::matrix;

/// @brief Template alias for math::tmat.
/// @ingroup gl_utils
template <typename T, unsigned C, unsigned R, bool RM = false, bool V = math_use_simd>
using tmat = math::tmat<T, C, R, RM, V>;

/// @brief Alias for 2x2 matrix.
/// @ingroup gl_utils
using mat2 = tmat<gl_types::float_type, 2, 2>;

/// @brief Alias for 2x3 matrix.
/// @ingroup gl_utils
using mat2x3 = tmat<gl_types::float_type, 2, 3>;

/// @brief Alias for 2x4 matrix.
/// @ingroup gl_utils
using mat2x4 = tmat<gl_types::float_type, 2, 4>;

/// @brief Alias for 3x2 matrix.
/// @ingroup gl_utils
using mat3x2 = tmat<gl_types::float_type, 3, 2>;

/// @brief Alias for 3x3 matrix.
/// @ingroup gl_utils
using mat3 = tmat<gl_types::float_type, 3, 3>;

/// @brief Alias for 3x4 matrix.
/// @ingroup gl_utils
using mat3x4 = tmat<gl_types::float_type, 3, 4>;

/// @brief Alias for 4x2 matrix.
/// @ingroup gl_utils
using mat4x2 = tmat<gl_types::float_type, 4, 2>;

/// @brief Alias for 4x3 matrix.
/// @ingroup gl_utils
using mat4x3 = tmat<gl_types::float_type, 4, 3>;

/// @brief Alias for 4x4 matrix.
/// @ingroup gl_utils
using mat4 = tmat<gl_types::float_type, 4, 4>;

} // namespace eagine::oglp

#endif // OGLPLUS_MATH_MATRIX_HPP
