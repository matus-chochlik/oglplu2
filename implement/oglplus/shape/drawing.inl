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
primitive_type
draw_operation::
_translate(eagine::shape::primitive_type mode)
noexcept
{
	switch(mode)
	{
		case eagine::shape::primitive_type::points:
			return primitive_type(GL_POINTS);
		case eagine::shape::primitive_type::lines:
			return primitive_type(GL_LINES);
		case eagine::shape::primitive_type::line_strip:
			return primitive_type(GL_LINE_STRIP);
		case eagine::shape::primitive_type::line_loop:
			return primitive_type(GL_LINE_LOOP);
		case eagine::shape::primitive_type::triangles:
			return primitive_type(GL_TRIANGLES);
		case eagine::shape::primitive_type::triangle_strip:
			return primitive_type(GL_TRIANGLE_STRIP);
		case eagine::shape::primitive_type::triangle_fan:
			return primitive_type(GL_TRIANGLE_FAN);
	}
	return primitive_type(GL_NONE);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
data_type
draw_operation::
_translate(eagine::shape::index_type type)
noexcept
{
	switch(type)
	{
		case eagine::shape::index_type::unsigned_int:
			return data_type(GL_UNSIGNED_INT);
		case eagine::shape::index_type::unsigned_short
			return data_type(GL_UNSIGNED_SHORT);
		case eagine::shape::index_type::unsigned_byte:
			return data_type(GL_UNSIGNED_BYTE);
		case eagine::shape::index_type::none:
			break;
	}
	return data_type(GL_NONE);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
GLuint
draw_operation::
_byte_mult(eagine::shape::index_type)
noexcept
{
	switch(type)
	{
		case eagine::shape::index_type::unsigned_int:
			return sizeof(GLuint);
		case eagine::shape::index_type::unsigned_short
			return sizeof(GLushort);
		case eagine::shape::index_type::unsigned_byte:
			return sizeof(GLubyte);
		case eagine::shape::index_type::none:
			break;
	}
	return 1u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
draw_operation::
draw_operation(const eagine::shape::draw_operation& draw_op)
noexcept
 : _mode(_translate(draw_op.mode))
 , _idx_type(_translate(draw_op.idx_type))
 , _first(draw_op.first*_byte_mult(draw_op.idx_type))
 , _count(draw_op.count)
 , _phase(draw_op.phase)
 , _primitive_restart_index(draw_op.primitive_restart_index)
 , _primitive_restart(draw_op.primitive_restart)
 , _indexed(draw_op.indexed)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
draw_operation::
indexed(void) const
noexcept
{
	return GLenum(_idx_type) != GL_NONE;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
outcome<void>
draw_operation::
draw(void) const
noexcept
{
	if(indexed())
	{
		OGLPLUS_GLFUNC(DrawElements)(
			GLenum(_mode),
			_count,
			GLenum(_idx_type),
			static_cast<GLubyte*>(0)+_first
		);
		OGLPLUS_VERIFY(DrawElements, gl_enum_value(mode), debug);
	}
	else
	{
		OGLPLUS_GLFUNC(DrawArrays)(
			GLenum(_mode),
			_first,
			_count
		);
		OGLPLUS_VERIFY(DrawArrays, gl_enum_value(_mode), debug);
	}
	return {};
}
//------------------------------------------------------------------------------
} // namespace shape
} // namespace oglplus
//------------------------------------------------------------------------------

