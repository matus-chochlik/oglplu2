/**
 *  @file eagine/shape/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPE_DRAWING_1509260923_HPP
#define EAGINE_SHAPE_DRAWING_1509260923_HPP

namespace eagine {
namespace shape {

enum class primitive_type
{
	points,
	lines,
	line_strip,
	line_loop,
	triangles,
	triangle_strip,
	triangle_fan
};

struct draw_operation
{
	primitive_type mode;
	unsigned first;
	unsigned count;
	unsigned phase;
	unsigned primitive_restart_index;
	bool primitive_restart;
	bool indexed;

	constexpr
	draw_operation(void)
	noexcept
	 : mode(primitive_type::points)
	 , first(0)
	 , count(0)
	 , phase(0)
	 , primitive_restart_index(0)
	 , primitive_restart(false)
	 , indexed(false)
	{ }
};

} // namespace shape
} // namespace eagine

#endif // include guard
