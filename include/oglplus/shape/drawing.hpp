/**
 *  @file oglplus/shape/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPE_DRAWING_1509260923_HPP
#define OGLPLUS_SHAPE_DRAWING_1509260923_HPP

#include <eagine/shapes/drawing.hpp>
#include <oglplus/config/basic.hpp>

namespace oglplus {
namespace shape {

GLenum translate_primitive_type(eagine::shape::primitive_type)
noexcept;

struct draw_operation
{
	GLenum mode;
	GLuint first;
	GLuint count;
	GLuint phase;
	GLuint primitive_restart_index;
	bool primitive_restart;
	bool indexed;

	draw_operation(void)
	 : mode(GL_NONE)
	 , first(0)
	 , count(0)
	 , phase(0)
	 , primitive_restart_index(0)
	 , primitive_restart(false)
	 , indexed(false)
	{ }

	draw_operation(const eagine::shape::draw_operation& draw_op)
	 : mode(translate_primitive_type(draw_op.mode))
	 , first(draw_op.first)
	 , count(draw_op.count)
	 , phase(draw_op.phase)
	 , primitive_restart_index(draw_op.primitive_restart_index)
	 , primitive_restart(draw_op.primitive_restart)
	 , indexed(draw_op.indexed)
	{ }

};

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/shape/drawing.inl>
#endif

} // namespace shape
} // namespace oglplus

#endif // include guard
