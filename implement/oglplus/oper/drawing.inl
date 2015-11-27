/**
 *  @file oglplus/oper/drawing.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<void>
drawing_ops::
draw_arrays(primitive_type mode, GLint first, GLsizei count)
noexcept
{
	OGLPLUS_GLFUNC(DrawArrays)(GLenum(mode), first, count);
	OGLPLUS_VERIFY(DrawArrays, gl_enum_value(mode), debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
drawing_ops::
draw_elements(primitive_type mode, GLsizei count, index_type type)
noexcept
{
	OGLPLUS_GLFUNC(DrawElements)(
		GLenum(mode),
		count,
		GLenum(type),
		nullptr
	);
	OGLPLUS_VERIFY(DrawElements, gl_enum_value(mode), debug);
	return {};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
