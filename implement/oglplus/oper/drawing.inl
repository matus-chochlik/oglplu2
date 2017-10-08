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
#if defined(GL_VERSION_3_1)
inline
outcome<void>
drawing_state::
primitive_restart_index(GLuint index)
noexcept {
	OGLPLUS_GLFUNC(PrimitiveRestartIndex)(index);
	OGLPLUS_VERIFY(
		PrimitiveRestartIndex,
		gl_index(index),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
drawing_ops::
draw_arrays(primitive_type mode, GLint first, GLsizei count)
noexcept {
	OGLPLUS_GLFUNC(DrawArrays)(GLenum(mode), first, count);
	OGLPLUS_VERIFY(
		DrawArrays,
		gl_enum_value(mode),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_1)
inline
outcome<void>
draw_arrays_instanced(
	primitive_type mode,
	GLint first,
	GLsizei count,
	GLsizei primcount
) noexcept {
	OGLPLUS_GLFUNC(DrawArraysInstanced)(
		GLenum(mode),
		first,
		count,
		primcount
	);
	OGLPLUS_VERIFY(
		DrawArraysInstanced,
		gl_enum_value(mode),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
drawing_ops::
draw_elements(
	primitive_type mode,
	GLsizei count,
	index_type type,
	const GLvoid* indices
) noexcept {
	OGLPLUS_GLFUNC(DrawElements)(
		GLenum(mode),
		count,
		GLenum(type),
		indices
	);
	OGLPLUS_VERIFY(
		DrawElements,
		gl_enum_value(mode),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
drawing_ops::
draw_elements(primitive_type mode, GLsizei count, index_type type)
noexcept {
	return draw_elements(mode, count, type, nullptr);
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_1)
inline
outcome<void>
drawing_ops::
draw_elements_instanced(
	primitive_type mode,
	GLsizei count,
	index_type type,
	const GLvoid* indices,
	GLsizei primcount
) noexcept {
	OGLPLUS_GLFUNC(DrawElementsInstanced)(
		GLenum(mode),
		count,
		GLenum(type),
		indices,
		primcount
	);
	OGLPLUS_VERIFY(
		DrawElementsInstanced,
		gl_enum_value(mode),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
drawing_ops::
draw_elements_instanced(
	primitive_type mode,
	GLsizei count,
	index_type type,
	GLsizei primcount
) noexcept {
	return draw_elements_instanced(mode, count, type, nullptr, primcount);
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
