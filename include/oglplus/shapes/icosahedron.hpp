/**
 *  @file oglplus/shapes/icosahedron.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_ICOSAHEDRON_1509260923_HPP
#define OGLPLUS_SHAPES_ICOSAHEDRON_1509260923_HPP

#include <eagine/shapes/icosahedron.hpp>
#include "adapted_gen.hpp"

namespace oglplus {
namespace shapes {

typedef concrete_adapted_generator<eagine::shapes::unit_icosahedron_gen>
  unit_icosahedron_gen;

} // namespace shapes
} // namespace oglplus

#endif // include guard
