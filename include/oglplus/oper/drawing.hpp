/**
 *  @file oglplus/oper/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_DRAWING_1509260923_HPP
#define OGLPLUS_OPER_DRAWING_1509260923_HPP

#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"
#include "../transform_feedback_name.hpp"

namespace oglplus {
namespace oper {

struct drawing_state
{
#if defined(GL_VERSION_3_1)
	static
	outcome<void>
	primitive_restart_index(GLuint index)
	noexcept;
#endif

#if defined(GL_VERSION_4_0)
	static
	outcome<void>
	patch_parameter_i(oglplus::patch_parameter param, GLint value)
	noexcept;

	static
	outcome<void>
	patch_parameter(
		oglplus::patch_parameter param,
		span<const GLfloat> values
	) noexcept;
#endif
};

struct drawing_ops
{
	static
	outcome<void>
	draw_arrays(primitive_type mode, GLint first, GLsizei count)
	noexcept;

#if defined(GL_VERSION_3_0)
	static
	outcome<void>
	multi_draw_arrays(
		primitive_type mode,
		span<const GLint> first,
		span<const GLsizei> count
	) noexcept;
#endif

#if defined(GL_VERSION_3_1)
	static
	outcome<void>
	draw_arrays_instanced(
		primitive_type mode,
		GLint first,
		GLsizei count,
		GLsizei primcount
	) noexcept;
#endif

#if defined(GL_VERSION_4_2)
	static
	outcome<void>
	draw_arrays_instanced_base_instance(
		primitive_type mode,
		GLint first,
		GLsizei count,
		GLsizei primcount,
		GLuint baseinstance
	) noexcept;
#endif

#if defined(GL_VERSION_4_0)
	static
	outcome<void>
	draw_arrays_indirect(
		primitive_type mode,
		const GLvoid* indirect
	) noexcept;
#endif

	static
	outcome<void>
	draw_elements(
		primitive_type mode,
		GLsizei count,
		index_type type,
		const GLvoid* indices
	) noexcept;

	static
	outcome<void>
	draw_elements(
		primitive_type mode,
		GLsizei count,
		index_type type
	) noexcept;

#if defined(GL_VERSION_3_0)
	static
	outcome<void>
	multi_draw_elements(
		primitive_type mode,
		span<const GLsizei> count,
		index_type type,
		span<const GLvoid*> indices
	) noexcept;
#endif

	static
	outcome<void>
	draw_range_elements(
		primitive_type mode,
		GLuint start,
		GLuint end,
		GLsizei count,
		index_type type,
		const GLvoid* indices
	) noexcept;

	static
	outcome<void>
	draw_range_elements(
		primitive_type mode,
		GLuint start,
		GLuint end,
		GLsizei count,
		index_type type
	) noexcept;

#if defined(GL_VERSION_3_1)
	static
	outcome<void>
	draw_elements_instanced(
		primitive_type mode,
		GLsizei count,
		index_type type,
		const GLvoid* indices,
		GLsizei primcount
	) noexcept;

	static
	outcome<void>
	draw_elements_instanced(
		primitive_type mode,
		GLsizei count,
		index_type type,
		GLsizei primcount
	) noexcept;
#endif

#if defined(GL_VERSION_3_2)
	static
	outcome<void>
	draw_elements_base_vertex(
		primitive_type mode,
		GLsizei count,
		index_type type,
		const GLvoid* indices,
		GLint basevertex
	) noexcept;

	static
	outcome<void>
	draw_elements_base_vertex(
		primitive_type mode,
		GLsizei count,
		index_type type,
		GLint basevertex
	) noexcept;

	static
	outcome<void>
	multi_draw_elements_base_vertex(
		primitive_type mode,
		span<const GLsizei> count,
		index_type type,
		span<const GLvoid*> indices,
		span<const GLint> basevertex
	) noexcept;

	static
	outcome<void>
	draw_range_elements_base_vertex(
		primitive_type mode,
		GLuint start,
		GLuint end,
		GLsizei count,
		index_type type,
		const GLvoid* indices,
		GLint basevertex
	) noexcept;

	static
	outcome<void>
	draw_range_elements_base_vertex(
		primitive_type mode,
		GLuint start,
		GLuint end,
		GLsizei count,
		index_type type,
		GLint basevertex
	) noexcept;

	static
	outcome<void>
	draw_elements_instanced_base_vertex(
		primitive_type mode,
		GLsizei count,
		index_type type,
		const GLvoid* indices,
		GLsizei primcount,
		GLint basevertex
	) noexcept;

	static
	outcome<void>
	draw_elements_instanced_base_vertex(
		primitive_type mode,
		GLsizei count,
		index_type type,
		GLsizei primcount,
		GLint basevertex
	) noexcept;
#endif

#if defined(GL_VERSION_4_2)
	static
	outcome<void>
	draw_elements_instanced_base_instance(
		primitive_type mode,
		GLsizei count,
		index_type type,
		const GLvoid* indices,
		GLsizei primcount,
		GLuint baseinstance
	) noexcept;

	static
	outcome<void>
	draw_elements_instanced_base_instance(
		primitive_type mode,
		GLsizei count,
		index_type type,
		GLsizei primcount,
		GLuint baseinstance
	) noexcept;

	static
	outcome<void>
	draw_elements_instanced_base_vertex_base_instance(
		primitive_type mode,
		GLsizei count,
		index_type type,
		const GLvoid* indices,
		GLsizei primcount,
		GLint basevertex,
		GLuint baseinstance
	) noexcept;

	static
	outcome<void>
	draw_elements_instanced_base_vertex_base_instance(
		primitive_type mode,
		GLsizei count,
		index_type type,
		GLsizei primcount,
		GLint basevertex,
		GLuint baseinstance
	) noexcept;
#endif

#if defined(GL_VERSION_4_0)
	static
	outcome<void>
	draw_elements_indirect(
		primitive_type mode,
		index_type type,
		const GLvoid* indirect
	) noexcept;

	static
	outcome<void>
	draw_transform_feedback(
		primitive_type mode,
		transform_feedback_name xfb
	) noexcept;

	static
	outcome<void>
	draw_transform_feedback_stream(
		primitive_type mode,
		transform_feedback_name xfb,
		GLuint stream
	) noexcept;
#endif

#if defined(GL_VERSION_4_2)
	static
	outcome<void>
	draw_transform_feedback_instanced(
		primitive_type mode,
		transform_feedback_name xfb,
		GLsizei primcount
	) noexcept;

	static
	outcome<void>
	draw_transform_feedback_stream_instanced(
		primitive_type mode,
		transform_feedback_name xfb,
		GLuint stream,
		GLsizei primcount
	) noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/drawing.inl>

#endif // include guard
