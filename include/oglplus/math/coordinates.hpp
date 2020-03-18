/**
 *  @file oglplus/math/coordinates.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_MATH_COORDINATES_HPP
#define OGLPLUS_MATH_COORDINATES_HPP

#include "config.hpp"
#include <eagine/math/coordinates.hpp>

namespace eagine {
namespace oglp {

using unit_spherical_coordinates =
  math::unit_spherical_coordinates<GLfloat, math_use_simd>;

using math::to_cartesian;
using math::to_unit_spherical;

} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_MATH_COORDINATES_HPP
