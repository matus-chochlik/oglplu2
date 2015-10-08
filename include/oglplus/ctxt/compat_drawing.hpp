/**
 *  @file oglplus/ctxt/compat_drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_COMPAT_DRAWING_1509260923_HPP
#define OGLPLUS_CTXT_COMPAT_DRAWING_1509260923_HPP

#ifdef GL_ARB_compatibility
#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum_types.hpp"

#include "compat_matrix.hpp"
#endif // ARB_compatibility

namespace oglplus {
namespace ctxt {

struct compatibility_drawing
{
#ifdef GL_ARB_compatibility
	static
	outcome<void>
	begin(old_primitive_type mode)
	noexcept
	{
		OGLPLUS_GLFUNC(Begin)(GLenum(mode));
		return {};
	}

	static
	outcome<void>
	end(void)
	noexcept
	{
		OGLPLUS_GLFUNC(End)();
		OGLPLUS_VERIFY_SIMPLE(End, warning);
		return {};
	}

	static
	outcome<void>
	vertex_i(GLint x, GLint y)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex2i)(x, y);
		return {};
	}

	static
	outcome<void>
	vertex_i(GLint x, GLint y, GLint z)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex3i)(x, y, z);
		return {};
	}

	static
	outcome<void>
	vertex_i(GLint x, GLint y, GLint z, GLint w)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex4i)(x, y, z, w);
		return {};
	}

	static
	outcome<void>
	vertex_f(GLfloat x, GLfloat y)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex2f)(x, y);
		return {};
	}

	static
	outcome<void>
	vertex_f(GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex3f)(x, y, z);
		return {};
	}

	static
	outcome<void>
	vertex_f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex4f)(x, y, z, w);
		return {};
	}

	static
	outcome<void>
	vertex_d(GLdouble x, GLdouble y)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex2d)(x, y);
		return {};
	}

	static
	outcome<void>
	vertex_d(GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex3d)(x, y, z);
		return {};
	}

	static
	outcome<void>
	vertex_d(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex4d)(x, y, z, w);
		return {};
	}

	static
	outcome<void>
	color_ub(GLubyte r, GLubyte g, GLubyte b)
	noexcept
	{
		OGLPLUS_GLFUNC(Color3ub)(r, g, b);
		return {};
	}

	static
	outcome<void>
	color_ub(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
	noexcept
	{
		OGLPLUS_GLFUNC(Color4ub)(r, g, b, a);
		return {};
	}

	static
	outcome<void>
	color_i(GLint r, GLint g, GLint b)
	noexcept
	{
		OGLPLUS_GLFUNC(Color3i)(r, g, b);
		return {};
	}

	static
	outcome<void>
	color_i(GLint r, GLint g, GLint b, GLint a)
	noexcept
	{
		OGLPLUS_GLFUNC(Color4i)(r, g, b, a);
		return {};
	}

	static
	outcome<void>
	color_f(GLfloat r, GLfloat g, GLfloat b)
	noexcept
	{
		OGLPLUS_GLFUNC(Color3f)(r, g, b);
		return {};
	}

	static
	outcome<void>
	color_f(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
	noexcept
	{
		OGLPLUS_GLFUNC(Color4f)(r, g, b, a);
		return {};
	}

	static
	outcome<void>
	color_d(GLdouble r, GLdouble g, GLdouble b)
	noexcept
	{
		OGLPLUS_GLFUNC(Color3d)(r, g, b);
		return {};
	}

	static
	outcome<void>
	color_d(GLdouble r, GLdouble g, GLdouble b, GLdouble a)
	noexcept
	{
		OGLPLUS_GLFUNC(Color4d)(r, g, b, a);
		return {};
	}
#endif // ARB_compatibility
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
