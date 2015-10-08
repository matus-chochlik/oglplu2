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
#include "../utils/array_view.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum_types.hpp"

#include <cassert>
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
	vertex_s(GLshort x, GLshort y)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex2s)(x, y);
		return {};
	}

	static
	outcome<void>
	vertex_s(GLshort x, GLshort y, GLshort z)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex3s)(x, y, z);
		return {};
	}

	static
	outcome<void>
	vertex_s(GLshort x, GLshort y, GLshort z, GLshort w)
	noexcept
	{
		OGLPLUS_GLFUNC(Vertex4s)(x, y, z, w);
		return {};
	}

	static
	outcome<void>
	vertex(const array_view<const GLshort>& v, std::size_t n)
	noexcept
	{
		assert(n >= 2);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 2) OGLPLUS_GLFUNC(Vertex2sv)(v.data());
		if(n == 3) OGLPLUS_GLFUNC(Vertex3sv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(Vertex4sv)(v.data());
		return {};
	}

	static
	outcome<void>
	vertex(const array_view<const GLshort>& v)
	noexcept
	{
		return vertex(v, v.size());
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
	vertex(const array_view<const GLint>& v, std::size_t n)
	noexcept
	{
		assert(n >= 2);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 2) OGLPLUS_GLFUNC(Vertex2iv)(v.data());
		if(n == 3) OGLPLUS_GLFUNC(Vertex3iv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(Vertex4iv)(v.data());
		return {};
	}

	static
	outcome<void>
	vertex(const array_view<const GLint>& v)
	noexcept
	{
		return vertex(v, v.size());
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
	vertex(const array_view<const GLfloat>& v, std::size_t n)
	noexcept
	{
		assert(n >= 2);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 2) OGLPLUS_GLFUNC(Vertex2fv)(v.data());
		if(n == 3) OGLPLUS_GLFUNC(Vertex3fv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(Vertex4fv)(v.data());
		return {};
	}

	static
	outcome<void>
	vertex(const array_view<const GLfloat>& v)
	noexcept
	{
		return vertex(v, v.size());
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
	vertex(const array_view<const GLdouble>& v, std::size_t n)
	noexcept
	{
		assert(n >= 2);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 2) OGLPLUS_GLFUNC(Vertex2dv)(v.data());
		if(n == 3) OGLPLUS_GLFUNC(Vertex3dv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(Vertex4dv)(v.data());
		return {};
	}

	static
	outcome<void>
	vertex(const array_view<const GLdouble>& v)
	noexcept
	{
		return vertex(v, v.size());
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
	color(const array_view<const GLubyte>& v, std::size_t n)
	noexcept
	{
		assert(n >= 3);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 3) OGLPLUS_GLFUNC(Color3ubv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(Color4ubv)(v.data());
		return {};
	}

	static
	outcome<void>
	color(const array_view<const GLubyte>& v)
	noexcept
	{
		return color(v, v.size());
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
	color(const array_view<const GLint>& v, std::size_t n)
	noexcept
	{
		assert(n >= 3);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 3) OGLPLUS_GLFUNC(Color3iv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(Color4iv)(v.data());
		return {};
	}

	static
	outcome<void>
	color(const array_view<const GLint>& v)
	noexcept
	{
		return color(v, v.size());
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
	color(const array_view<const GLfloat>& v, std::size_t n)
	noexcept
	{
		assert(n >= 3);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 3) OGLPLUS_GLFUNC(Color3fv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(Color4fv)(v.data());
		return {};
	}

	static
	outcome<void>
	color(const array_view<const GLfloat>& v)
	noexcept
	{
		return color(v, v.size());
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

	static
	outcome<void>
	color(const array_view<const GLdouble>& v, std::size_t n)
	noexcept
	{
		assert(n >= 3);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 3) OGLPLUS_GLFUNC(Color3dv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(Color4dv)(v.data());
		return {};
	}

	static
	outcome<void>
	color(const array_view<const GLdouble>& v)
	noexcept
	{
		return color(v, v.size());
	}


	static
	outcome<void>
	tex_coord_s(GLshort s)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord1s)(s);
		return {};
	}

	static
	outcome<void>
	tex_coord_s(GLshort s, GLshort t)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord2s)(s, t);
		return {};
	}

	static
	outcome<void>
	tex_coord_s(GLshort s, GLshort t, GLshort r)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord3s)(s, t, r);
		return {};
	}

	static
	outcome<void>
	tex_coord_s(GLshort s, GLshort t, GLshort r, GLshort q)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord4s)(s, t, r, q);
		return {};
	}

	static
	outcome<void>
	tex_coord(const array_view<const GLshort>& v, std::size_t n)
	noexcept
	{
		assert(n >= 1);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 1) OGLPLUS_GLFUNC(TexCoord1sv)(v.data());
		if(n == 2) OGLPLUS_GLFUNC(TexCoord2sv)(v.data());
		if(n == 3) OGLPLUS_GLFUNC(TexCoord3sv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(TexCoord4sv)(v.data());
		return {};
	}

	static
	outcome<void>
	tex_coord(const array_view<const GLshort>& v)
	noexcept
	{
		return tex_coord(v, v.size());
	}


	static
	outcome<void>
	tex_coord_i(GLint s)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord1i)(s);
		return {};
	}

	static
	outcome<void>
	tex_coord_i(GLint s, GLint t)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord2i)(s, t);
		return {};
	}

	static
	outcome<void>
	tex_coord_i(GLint s, GLint t, GLint r)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord3i)(s, t, r);
		return {};
	}

	static
	outcome<void>
	tex_coord_i(GLint s, GLint t, GLint r, GLint q)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord4i)(s, t, r, q);
		return {};
	}

	static
	outcome<void>
	tex_coord(const array_view<const GLint>& v, std::size_t n)
	noexcept
	{
		assert(n >= 1);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 1) OGLPLUS_GLFUNC(TexCoord1iv)(v.data());
		if(n == 2) OGLPLUS_GLFUNC(TexCoord2iv)(v.data());
		if(n == 3) OGLPLUS_GLFUNC(TexCoord3iv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(TexCoord4iv)(v.data());
		return {};
	}

	static
	outcome<void>
	tex_coord(const array_view<const GLint>& v)
	noexcept
	{
		return tex_coord(v, v.size());
	}

	static
	outcome<void>
	tex_coord_f(GLfloat s)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord1f)(s);
		return {};
	}

	static
	outcome<void>
	tex_coord_f(GLfloat s, GLfloat t)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord2f)(s, t);
		return {};
	}

	static
	outcome<void>
	tex_coord_f(GLfloat s, GLfloat t, GLfloat r)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord3f)(s, t, r);
		return {};
	}

	static
	outcome<void>
	tex_coord_f(GLfloat s, GLfloat t, GLfloat r, GLfloat q)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord4f)(s, t, r, q);
		return {};
	}

	static
	outcome<void>
	tex_coord(const array_view<const GLfloat>& v, std::size_t n)
	noexcept
	{
		assert(n >= 1);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 1) OGLPLUS_GLFUNC(TexCoord1fv)(v.data());
		if(n == 2) OGLPLUS_GLFUNC(TexCoord2fv)(v.data());
		if(n == 3) OGLPLUS_GLFUNC(TexCoord3fv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(TexCoord4fv)(v.data());
		return {};
	}

	static
	outcome<void>
	tex_coord(const array_view<const GLfloat>& v)
	noexcept
	{
		return tex_coord(v, v.size());
	}

	static
	outcome<void>
	tex_coord_d(GLdouble s)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord1d)(s);
		return {};
	}

	static
	outcome<void>
	tex_coord_d(GLdouble s, GLdouble t)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord2d)(s, t);
		return {};
	}

	static
	outcome<void>
	tex_coord_d(GLdouble s, GLdouble t, GLdouble r)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord3d)(s, t, r);
		return {};
	}

	static
	outcome<void>
	tex_coord_d(GLdouble s, GLdouble t, GLdouble r, GLdouble q)
	noexcept
	{
		OGLPLUS_GLFUNC(TexCoord4d)(s, t, r, q);
		return {};
	}

	static
	outcome<void>
	tex_coord(const array_view<const GLdouble>& v, std::size_t n)
	noexcept
	{
		assert(n >= 1);
		assert(n <= 4);
		assert(n <= v.size());

		if(n == 1) OGLPLUS_GLFUNC(TexCoord1dv)(v.data());
		if(n == 2) OGLPLUS_GLFUNC(TexCoord2dv)(v.data());
		if(n == 3) OGLPLUS_GLFUNC(TexCoord3dv)(v.data());
		if(n == 4) OGLPLUS_GLFUNC(TexCoord4dv)(v.data());
		return {};
	}

	static
	outcome<void>
	tex_coord(const array_view<const GLdouble>& v)
	noexcept
	{
		return tex_coord(v, v.size());
	}
#endif // ARB_compatibility
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
