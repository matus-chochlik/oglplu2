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
#include <oglplus/gl_api/config.hpp>

namespace eagine::oglp {

using unit_spherical_coordinates =
  math::unit_spherical_coordinates<gl_types::float_type, math_use_simd>;

using math::to_cartesian;
using math::to_unit_spherical;

} // namespace eagine::oglp

#endif // OGLPLUS_MATH_COORDINATES_HPP
