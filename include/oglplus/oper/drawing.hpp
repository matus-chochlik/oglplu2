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
};

struct drawing_ops
{
	static
	outcome<void>
	draw_arrays(primitive_type mode, GLint first, GLsizei count)
	noexcept;

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
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/drawing.inl>

#endif // include guard
