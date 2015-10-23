/**
 *  @file oglplus/oper/compat_matrix.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_COMPAT_MATRIX_1509260923_HPP
#define OGLPLUS_OPER_COMPAT_MATRIX_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/array_view.hpp"
#include "../utils/angles.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct compatibility_matrix
{
#ifdef GL_ARB_compatibility
	static
	outcome<void>
	matrix_mode(old_matrix_mode mode)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixMode)(GLenum(mode));
		OGLPLUS_VERIFY_SIMPLE(MatrixMode,debug);
		return {};
	}

	static
	outcome<void>
	push_matrix(void)
	noexcept
	{
		OGLPLUS_GLFUNC(PushMatrix)();
		OGLPLUS_VERIFY_SIMPLE(PushMatrix,debug);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	push_matrix(old_matrix_mode mode)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixPushEXT)(GLenum(mode));
		OGLPLUS_VERIFY_SIMPLE(MatrixPushEXT,debug);
		return {};
	}
#endif

	static
	outcome<void>
	pop_matrix(void)
	noexcept
	{
		OGLPLUS_GLFUNC(PopMatrix)();
		OGLPLUS_VERIFY_SIMPLE(PopMatrix,debug);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	pop_matrix(old_matrix_mode mode)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixPopEXT)(GLenum(mode));
		OGLPLUS_VERIFY_SIMPLE(MatrixPopEXT,debug);
		return {};
	}
#endif

	static
	outcome<void>
	load_identity(void)
	noexcept
	{
		OGLPLUS_GLFUNC(LoadIdentity)();
		OGLPLUS_VERIFY_SIMPLE(LoadIdentity,debug);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	load_identity(old_matrix_mode mode)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixLoadIdentityEXT)(GLenum(mode));
		OGLPLUS_VERIFY_SIMPLE(MatrixLoadIdentityEXT,debug);
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
		OGLPLUS_VERIFY_SIMPLE(LoadMatrixf,debug);
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
		OGLPLUS_VERIFY_SIMPLE(MatrixLoadfEXT,debug);
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
		OGLPLUS_VERIFY_SIMPLE(LoadTransposeMatrixf,debug);
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
		OGLPLUS_VERIFY_SIMPLE(MatrixLoadTransposefEXT,debug);
		return {};
	}
#endif

	static
	outcome<void>
	load_matrix(array_view<const GLdouble> mat)
	noexcept
	{
		OGLPLUS_GLFUNC(LoadMatrixd)(mat.data());
		OGLPLUS_VERIFY_SIMPLE(LoadMatrixd,debug);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	load_matrix(old_matrix_mode mode, array_view<const GLdouble> mat)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixLoaddEXT)(GLenum(mode), mat.data());
		OGLPLUS_VERIFY_SIMPLE(MatrixLoaddEXT,debug);
		return {};
	}
#endif

	static
	outcome<void>
	load_transpose_matrix(array_view<const GLdouble> mat)
	noexcept
	{
		OGLPLUS_GLFUNC(LoadTransposeMatrixd)(mat.data());
		OGLPLUS_VERIFY_SIMPLE(LoadTransposeMatrixd,debug);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	load_transpose_matrix(old_matrix_mode mode, array_view<const GLdouble> mat)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixLoadTransposedEXT)(GLenum(mode), mat.data());
		OGLPLUS_VERIFY_SIMPLE(MatrixLoadTransposedEXT,debug);
		return {};
	}
#endif

	static
	outcome<void>
	translate_f(GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(Translatef)(x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Translatef,debug);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	translate_f(old_matrix_mode mode, GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixTranslatefEXT)(GLenum(mode), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixTranslatefEXT,debug);
		return {};
	}
#endif

	static
	outcome<void>
	translate_d(GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(Translated)(x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Translated,debug);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	translate_d(old_matrix_mode mode, GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixTranslatedEXT)(GLenum(mode), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixTranslatedEXT,debug);
		return {};
	}
#endif

	static
	outcome<void>
	rotate_f(degrees_t<GLfloat> a, GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(Rotatef)(GLfloat(a), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Rotatef,debug);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	rotate_f(old_matrix_mode mode, degrees_t<GLfloat> a, GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixRotatefEXT)(GLenum(mode), GLfloat(a), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixRotatefEXT,debug);
		return {};
	}
#endif

	static
	outcome<void>
	rotate_d(degrees_t<GLdouble> a, GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(Rotated)(GLdouble(a), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Rotated,debug);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	rotate_d(old_matrix_mode mode, degrees_t<GLdouble> a, GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixRotatedEXT)(GLenum(mode), GLdouble(a), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixRotatedEXT,debug);
		return {};
	}
#endif

	static
	outcome<void>
	scale_f(GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(Scalef)(x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Scalef,debug);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	scale_f(old_matrix_mode mode, GLfloat x, GLfloat y, GLfloat z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixScalefEXT)(GLenum(mode), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixScalefEXT,debug);
		return {};
	}
#endif

	static
	outcome<void>
	scale_d(GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(Scaled)(x, y, z);
		OGLPLUS_VERIFY_SIMPLE(Scaled,debug);
		return {};
	}

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	scale_d(old_matrix_mode mode, GLdouble x, GLdouble y, GLdouble z)
	noexcept
	{
		OGLPLUS_GLFUNC(MatrixScaledEXT)(GLenum(mode), x, y, z);
		OGLPLUS_VERIFY_SIMPLE(MatrixScaledEXT,debug);
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
		OGLPLUS_VERIFY_SIMPLE(Ortho,always);
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
		OGLPLUS_VERIFY_SIMPLE(MatrixOrthoEXT,always);
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
		OGLPLUS_VERIFY_SIMPLE(Frustum,always);
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
		OGLPLUS_VERIFY_SIMPLE(MatrixFrustumEXT,always);
		return {};
	}
#endif

#endif // ARB_compatibility
};

} // namespace oper
} // namespace oglplus

#endif // include guard
