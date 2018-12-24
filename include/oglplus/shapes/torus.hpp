/**
 *  @file oglplus/shapes/torus.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_TORUS_HPP
#define OGLPLUS_SHAPES_TORUS_HPP

#include "adapted_gen.hpp"
#include <eagine/shapes/torus.hpp>

namespace oglplus {
namespace shapes {

using unit_torus_gen =
  concrete_adapted_generator<eagine::shapes::unit_torus_gen>;

} // namespace shapes
} // namespace oglplus

#endif // OGLPLUS_SHAPES_TORUS_HPP
