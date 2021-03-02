/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_MATH_VECTOR_HPP
#define OGLPLUS_MATH_VECTOR_HPP

#include "config.hpp"
#include <eagine/math/tvec.hpp>
#include <oglplus/gl_api/config.hpp>

namespace eagine::oglp {

/// @brief Alias for math::vector.
/// @ingroup gl_utils
using math::vector;

/// @brief Template alias for math::tvec.
/// @ingroup gl_utils
template <typename T, unsigned N, bool V = math_use_simd>
using tvec = math::tvec<T, N, V>;

/// @brief Alias for a 2D vector type.
/// @ingroup gl_utils
using vec2 = tvec<gl_types::float_type, 2>;

/// @brief Alias for a 3D vector type.
/// @ingroup gl_utils
using vec3 = tvec<gl_types::float_type, 3>;

/// @brief Alias for a 4D vector type.
/// @ingroup gl_utils
using vec4 = tvec<gl_types::float_type, 4>;

} // namespace eagine::oglp

#endif // OGLPLUS_MATH_VECTOR_HPP
