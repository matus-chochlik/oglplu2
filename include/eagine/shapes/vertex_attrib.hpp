/**
 *  @file eagine/shapes/vertex_attrib.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_VERTEX_ATTRIB_1509260923_HPP
#define EAGINE_SHAPES_VERTEX_ATTRIB_1509260923_HPP

#include "../bitfield.hpp"

namespace eagine {
namespace shapes {

enum class vertex_attrib_kind : unsigned
{
	position       = 1 <<  0,
	normal         = 1 <<  1,
	tangential     = 1 <<  2,
	bitangential   = 1 <<  3,
	box_coord      = 1 <<  4,
	tex_coord      = 1 <<  5
};

typedef bitfield<vertex_attrib_kind> vertex_attrib_bits;

static inline
vertex_attrib_bits
operator | (vertex_attrib_kind a, vertex_attrib_kind b)
noexcept
{
	return {a, b};
}

static inline
unsigned
attrib_values_per_vertex(vertex_attrib_kind attr)
noexcept
{
	switch(attr)
	{
		case vertex_attrib_kind::position:
		case vertex_attrib_kind::normal:
		case vertex_attrib_kind::tangential:
		case vertex_attrib_kind::bitangential:
		case vertex_attrib_kind::box_coord:
			return 3u;
		case vertex_attrib_kind::tex_coord:
			return 2u;
	}
	return 0u;
}

} // namespace shapes
} // namespace eagine

#endif // include guard
