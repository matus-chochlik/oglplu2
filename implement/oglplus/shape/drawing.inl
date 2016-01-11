/**
 *  @file oglplus/shape/drawing.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace oglplus {
namespace shape {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
GLenum translate_primitive_type(eagine::shape::primitive_type mode)
noexcept
{
	using eagine::shape::primitive_type;
	switch(mode)
	{
		case primitive_type::points:
			return GL_POINTS;
		case primitive_type::lines:
			return GL_LINES;
		case primitive_type::line_strip:
			return GL_LINE_STRIP;
		case primitive_type::line_loop:
			return GL_LINE_LOOP;
		case primitive_type::triangles:
			return GL_TRIANGLES;
		case primitive_type::triangle_strip:
			return GL_TRIANGLE_STRIP;
		case primitive_type::triangle_fan:
			return GL_TRIANGLE_FAN;
	}
	return GL_NONE;
}
//------------------------------------------------------------------------------
} // namespace shape
} // namespace oglplus
//------------------------------------------------------------------------------

