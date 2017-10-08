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
drawing_ops::
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
#if defined(GL_VERSION_4_2)
inline
outcome<void>
drawing_ops::
draw_arrays_instanced_base_instance(
	primitive_type mode,
	GLint first,
	GLsizei count,
	GLsizei primcount,
	GLuint baseinstance
) noexcept {
	OGLPLUS_GLFUNC(DrawArraysInstancedBaseInstance)(
		GLenum(mode),
		first,
		count,
		primcount,
		baseinstance
	);
	OGLPLUS_VERIFY(
		DrawArraysInstancedBaseInstance,
		gl_enum_value(mode),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
inline
outcome<void>
drawing_ops::
draw_arrays_indirect(
	primitive_type mode,
	const GLvoid* indirect
) noexcept {
	OGLPLUS_GLFUNC(DrawArraysIndirect)(GLenum(mode), indirect);
	OGLPLUS_VERIFY(
		DrawArraysIndirect,
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
#if defined(GL_VERSION_3_2)
inline
outcome<void>
drawing_ops::
draw_elements_base_vertex(
	primitive_type mode,
	GLsizei count,
	index_type type,
	const GLvoid* indices,
	GLint basevertex
) noexcept {
	OGLPLUS_GLFUNC(DrawElementsBaseVertex)(
		GLenum(mode),
		count,
		GLenum(type),
		indices,
		basevertex
	);
	OGLPLUS_VERIFY(
		DrawElementsBaseVertex,
		gl_enum_value(mode),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
drawing_ops::
draw_elements_base_vertex(
	primitive_type mode,
	GLsizei count,
	index_type type,
	GLint basevertex
) noexcept {
	return draw_elements_base_vertex(mode, count, type, nullptr, basevertex);
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_2)
inline
outcome<void>
drawing_ops::
draw_elements_instanced_base_instance(
	primitive_type mode,
	GLsizei count,
	index_type type,
	const GLvoid* indices,
	GLsizei primcount,
	GLuint baseinstance
) noexcept {
	OGLPLUS_GLFUNC(DrawElementsInstancedBaseInstance)(
		GLenum(mode),
		count,
		GLenum(type),
		indices,
		primcount,
		baseinstance
	);
	OGLPLUS_VERIFY(
		DrawElementsInstancedBaseInstance,
		gl_enum_value(mode),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
drawing_ops::
draw_elements_instanced_base_instance(
	primitive_type mode,
	GLsizei count,
	index_type type,
	GLsizei primcount,
	GLuint baseinstance
) noexcept {
	return draw_elements_instanced_base_instance(
		mode,
		count,
		type,
		nullptr,
		primcount,
		baseinstance
	);
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
inline
outcome<void>
drawing_ops::
draw_elements_indirect(
	primitive_type mode,
	index_type type,
	const GLvoid* indirect
) noexcept {
	OGLPLUS_GLFUNC(DrawElementsIndirect)(
		GLenum(mode),
		GLenum(type),
		indirect
	);
	OGLPLUS_VERIFY(
		DrawElementsIndirect,
		gl_enum_value(mode),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
