/**
 *  @file oglplus/ctxt/compat_matrix.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_COMPAT_MATRIX_1509260923_HPP
#define OGLPLUS_CTXT_COMPAT_MATRIX_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/array_view.hpp"
#include "../enum_types.hpp"

namespace oglplus {
namespace ctxt {

struct compatibility_matrix
{
#ifdef GL_ARB_compatibility
	static
	outcome<void>
	matrix_mode(old_matrix_mode mode)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixMode)(GLenum(mode));
		OGLPLUS_VERIFY_SIMPLE(MatrixMode,warning);
		return {};
	}

	static
	outcome<void>
	push_matrix(void)
	noexcept
	{
		OGLPLUS_GLFUNC(PushMatrix)();
		OGLPLUS_VERIFY_SIMPLE(PushMatrix,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	push_matrix(old_matrix_mode mode)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixPushEXT)(GLenum(mode));
		OGLPLUS_VERIFY_SIMPLE(MatrixPushEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	pop_matrix(void)
	noexcept
	{
		OGLPLUS_GLFUNC(PopMatrix)();
		OGLPLUS_VERIFY_SIMPLE(PopMatrix,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	pop_matrix(old_matrix_mode mode)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixPopEXT)(GLenum(mode));
		OGLPLUS_VERIFY_SIMPLE(MatrixPopEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	load_identity(void)
	noexcept
	{
		OGLPLUS_GLFUNC(LoadIdentity)();
		OGLPLUS_VERIFY_SIMPLE(LoadIdentity,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	load_identity(old_matrix_mode mode)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixLoadIdentityEXT)(GLenum(mode));
		OGLPLUS_VERIFY_SIMPLE(MatrixLoadIdentityEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	load_matrix(array_view<const GLfloat> mat)
	noexcept
	{
		assert(mat.size() >= 16);
		OGLPLUS_GLFUNC(LoadMatrixf)(mat.data());
		OGLPLUS_VERIFY_SIMPLE(LoadMatrixf,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	load_matrix(old_matrix_mode mode, array_view<const GLfloat> mat)
	noexcept
	{
		assert(mat.size() >= 16);
		OGLPLUS_GLFUNC(MatrixLoadfEXT)(GLenum(mode), mat.data());
		OGLPLUS_VERIFY_SIMPLE(MatrixLoadfEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	load_transpose_matrix(array_view<const GLfloat> mat)
	noexcept
	{
		assert(mat.size() >= 16);
		OGLPLUS_GLFUNC(LoadTransposeMatrixf)(mat.data());
		OGLPLUS_VERIFY_SIMPLE(LoadTransposeMatrixf,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	load_transpose_matrix(old_matrix_mode mode, array_view<const GLfloat> mat)
	noexcept
	{
		assert(mat.size() >= 16);
		OGLPLUS_GLFUNC(MatrixLoadTransposefEXT)(GLenum(mode), mat.data());
		OGLPLUS_VERIFY_SIMPLE(MatrixLoadTransposefEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	load_matrix(array_view<const GLdouble> mat)
	noexcept
	{
		OGLPLUS_GLFUNC(LoadMatrixd)(mat.data());
		OGLPLUS_VERIFY_SIMPLE(LoadMatrixd,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	load_matrix(old_matrix_mode mode, array_view<const GLdouble> mat)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixLoaddEXT)(GLenum(mode), mat.data());
		OGLPLUS_VERIFY_SIMPLE(MatrixLoaddEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	load_transpose_matrix(array_view<const GLdouble> mat)
	noexcept
	{
		OGLPLUS_GLFUNC(LoadTransposeMatrixd)(mat.data());
		OGLPLUS_VERIFY_SIMPLE(LoadTransposeMatrixd,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	load_transpose_matrix(old_matrix_mode mode, array_view<const GLdouble> mat)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixLoadTransposedEXT)(GLenum(mode), mat.data());
		OGLPLUS_VERIFY_SIMPLE(MatrixLoadTransposedEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	translate_f(GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(Translatef)(x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Translatef,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	translate_f(old_matrix_mode mode, GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixTranslatefEXT)(GLenum(mode), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixTranslatefEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	translate_d(GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(Translated)(x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Translated,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	translate_d(old_matrix_mode mode, GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixTranslatedEXT)(GLenum(mode), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixTranslatedEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	rotate_f(GLfloat a, GLfloat x, GLfloat y, GLfloat z) // TODO angle ?
	noexcept
	{
		OGLPLUS_GLFUNC(Rotatef)(a, x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Rotatef,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	rotate_f(old_matrix_mode mode, GLfloat a, GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixRotatefEXT)(GLenum(mode), a, x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixRotatefEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	rotate_d(GLdouble a, GLdouble x, GLdouble y, GLdouble z) // TODO angle ?
	noexcept
	{
		OGLPLUS_GLFUNC(Rotated)(a, x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Rotated,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	rotate_d(old_matrix_mode mode, GLdouble a, GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixRotatedEXT)(GLenum(mode), a, x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixRotatedEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	scale_f(GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(Scalef)(x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Scalef,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	scale_f(old_matrix_mode mode, GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixScalefEXT)(GLenum(mode), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixScalefEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	scale_d(GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(Scaled)(x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Scaled,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	scale_d(old_matrix_mode mode, GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixScaledEXT)(GLenum(mode), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixScaledEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	ortho(
		GLdouble l,
		GLdouble r,
		GLdouble b,
		GLdouble t,
		GLdouble n,
		GLdouble f
	)
	noexcept
	{
		OGLPLUS_GLFUNC(Ortho)(l, r, b, t, n, f);
		OGLPLUS_VERIFY_SIMPLE(Ortho,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	ortho(
		old_matrix_mode mode,
		GLdouble l,
		GLdouble r,
		GLdouble b,
		GLdouble t,
		GLdouble n,
		GLdouble f
	)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixOrthoEXT)(GLenum(mode), l, r, b, t, n, f);
		OGLPLUS_VERIFY_SIMPLE(MatrixOrthoEXT,warning);
		return {};
	}
#endif

	static
	outcome<void>
	frustum(
		GLdouble l,
		GLdouble r,
		GLdouble b,
		GLdouble t,
		GLdouble n,
		GLdouble f
	)
	noexcept
	{
		OGLPLUS_GLFUNC(Frustum)(l, r, b, t, n, f);
		OGLPLUS_VERIFY_SIMPLE(Frustum,warning);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	frustum(
		old_matrix_mode mode,
		GLdouble l,
		GLdouble r,
		GLdouble b,
		GLdouble t,
		GLdouble n,
		GLdouble f
	)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixFrustumEXT)(GLenum(mode), l, r, b, t, n, f);
		OGLPLUS_VERIFY_SIMPLE(MatrixFrustumEXT,warning);
		return {};
	}
#endif

#endif // ARB_compatibility
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
