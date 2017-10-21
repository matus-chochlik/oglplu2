/**
 *  @file oglplus/oper/viewport.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_VIEWPORT_1509260923_HPP
#define OGLPLUS_OPER_VIEWPORT_1509260923_HPP

#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"
#include "../utils/limited_value.hpp"

namespace oglplus {

#if defined(GL_VERSION_4_1)
using viewport_index = limited_value<GL_MAX_VIEWPORTS, GLuint>;
#endif

namespace oper {

struct viewport_extents {

	viewport_extents(GLfloat x, GLfloat y, GLfloat w, GLfloat h)
	noexcept {
		_v[0] = x;
		_v[1] = y;
		_v[2] = w;
		_v[3] = h;
	}

	viewport_extents(void)
	noexcept
	 : viewport_extents(0.f, 0.f, 0.f, 0.f)
	{ }

	GLfloat x(void) const
	noexcept { return _v[0]; }

	GLfloat y(void) const
	noexcept { return _v[1]; }

	GLfloat width(void) const
	noexcept { return _v[2]; }

	GLfloat height(void) const
	noexcept { return _v[3]; }

	GLfloat _v[4];
};

struct viewport_state {
	static
	outcome<void>
	viewport(GLint x, GLint y, GLsizei w, GLsizei h)
	noexcept;

	static
	outcome<void>
	viewport(GLsizei w, GLsizei h)
	noexcept;

	static
	outcome<viewport_extents>
	get_viewport(void)
	noexcept;

#if defined(GL_VERSION_4_1)
	static
	outcome<void>
	viewport(viewport_index index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
	noexcept;

	static
	outcome<void>
	viewport(viewport_index index, const viewport_extents& vpe)
	noexcept;

	static
	outcome<void>
	viewport_array(viewport_index first, span<const GLfloat> vpe)
	noexcept;

	static
	outcome<viewport_extents>
	get_viewport(viewport_index index)
	noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/viewport.inl>

#endif // include guard
