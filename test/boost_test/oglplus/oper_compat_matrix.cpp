/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#define BOOST_TEST_MODULE OGLPLUS_oper_compat_matrix
#include "../unit_test_begin.inl"

#include "helper/mock_gl_func.hpp"

OGLPLUS_MOCK_GLFUNC(MatrixMode, void(GLenum));

OGLPLUS_MOCK_GLFUNC(PushMatrix, void(void));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixPushEXT, void(GLenum));
#endif

OGLPLUS_MOCK_GLFUNC(PopMatrix, void(void));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixPopEXT, void(GLenum));
#endif

OGLPLUS_MOCK_GLFUNC(LoadIdentity, void(void));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixLoadIdentityEXT, void(GLenum));
#endif

OGLPLUS_MOCK_GLFUNC(LoadMatrixf, void(const GLfloat*));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixLoadfEXT, void(GLenum, const GLfloat*));
#endif

OGLPLUS_MOCK_GLFUNC(LoadTransposeMatrixf, void(const GLfloat*));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixLoadTransposefEXT, void(GLenum, const GLfloat*));
#endif

#if defined(GL_DOUBLE)
OGLPLUS_MOCK_GLFUNC(LoadMatrixd, void(const GLdouble*));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixLoaddEXT, void(GLenum, const GLdouble*));
#endif

OGLPLUS_MOCK_GLFUNC(LoadTransposeMatrixd, void(const GLdouble*));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixLoadTransposedEXT, void(GLenum, const GLdouble*));
#endif
#endif // GL_DOUBLE

OGLPLUS_MOCK_GLFUNC(Translatef, void(GLfloat, GLfloat, GLfloat));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixTranslatefEXT, void(GLenum, GLfloat, GLfloat, GLfloat));
#endif

#if defined(GL_DOUBLE)
OGLPLUS_MOCK_GLFUNC(Translated, void(GLdouble, GLdouble, GLdouble));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixTranslatedEXT, void(GLenum, GLdouble, GLdouble, GLdouble));
#endif
#endif // GL_DOUBLE

OGLPLUS_MOCK_GLFUNC(Rotatef, void(GLfloat, GLfloat, GLfloat, GLfloat));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixRotatefEXT, void(GLenum, GLfloat, GLfloat, GLfloat, GLfloat));
#endif

#if defined(GL_DOUBLE)
OGLPLUS_MOCK_GLFUNC(Rotated, void(GLdouble, GLdouble, GLdouble, GLdouble));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixRotatedEXT, void(GLenum, GLdouble, GLdouble, GLdouble, GLdouble));
#endif
#endif // GL_DOUBLE

OGLPLUS_MOCK_GLFUNC(Scalef, void(GLfloat, GLfloat, GLfloat));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixScalefEXT, void(GLenum, GLfloat, GLfloat, GLfloat));
#endif

#if defined(GL_DOUBLE)
OGLPLUS_MOCK_GLFUNC(Scaled, void(GLdouble, GLdouble, GLdouble));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixScaledEXT, void(GLenum, GLdouble, GLdouble, GLdouble));
#endif

OGLPLUS_MOCK_GLFUNC(Ortho, void(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble));
OGLPLUS_MOCK_GLFUNC(Orthof, void(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixOrthoEXT, void(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble));
#endif

OGLPLUS_MOCK_GLFUNC(Frustum, void(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixFrustumEXT, void(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble));
#endif
#endif // GL_DOUBLE

#include <oglplus/oper/compat_matrix.hpp>
#include <oglplus/enum/values.hpp>
#include <cstring>

BOOST_AUTO_TEST_SUITE(compat_matrix_tests)

#if	defined(GL_MODELVIEW) &&\
	defined(GL_PROJECTION) &&\
	defined(GL_ARB_compatibility)

static eagine::test_random_generator rg;

template <typename T>
static T get(void)
{
	return rg.get_any<T>();
}

BOOST_AUTO_TEST_CASE(compat_matrix_mode)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixMode = make_aoe_test(
			mock_glMatrixMode,
			GLenum(m)
		);
		gl.matrix_mode(m);
		BOOST_CHECK(test_glMatrixMode);
	}

	BOOST_CHECK(mock_glMatrixMode.was_called());
}

BOOST_AUTO_TEST_CASE(compat_matrix_push_pop)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	{
		auto test_glPushMatrix = make_aoe_test(mock_glPushMatrix);
		gl.push_matrix();
		BOOST_CHECK(test_glPushMatrix);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixPushEXT = make_aoe_test(
			mock_glMatrixPushEXT,
			GLenum(m)
		);
		gl.push_matrix(m);
		BOOST_CHECK(test_glMatrixPushEXT);
	}
#endif

	{
		auto test_glPopMatrix = make_aoe_test(mock_glPopMatrix);
		gl.pop_matrix();
		BOOST_CHECK(test_glPopMatrix);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.modelview;
		auto test_glMatrixPopEXT = make_aoe_test(
			mock_glMatrixPopEXT,
			GLenum(m)
		);
		gl.pop_matrix(m);
		BOOST_CHECK(test_glMatrixPopEXT);
	}
#endif

	BOOST_CHECK(mock_glPushMatrix.was_called());
	BOOST_CHECK(mock_glPopMatrix.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixPushEXT.was_called());
	BOOST_CHECK(mock_glMatrixPopEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_load_identity)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	{
		auto test_glLoadIdentity = make_aoe_test(mock_glLoadIdentity);
		gl.load_identity();
		BOOST_CHECK(test_glLoadIdentity);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixLoadIdentityEXT = make_aoe_test(
			mock_glMatrixLoadIdentityEXT,
			GLenum(m)
		);
		gl.load_identity(m);
		BOOST_CHECK(test_glMatrixLoadIdentityEXT);
	}
#endif

	BOOST_CHECK(mock_glLoadIdentity.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixLoadIdentityEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_load_f)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLfloat v[16];

	for(GLfloat& c : v)
	{
		c = get<GLfloat>();
	}

	{
		auto test_glLoadMatrixf = make_aoe_test(
			mock_glLoadMatrixf,
			v
		);
		gl.load_matrix(v);
		BOOST_CHECK(test_glLoadMatrixf);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixLoadfEXT = make_aoe_test(
			mock_glMatrixLoadfEXT,
			GLenum(m), v
		);
		gl.load_matrix(m, v);
		BOOST_CHECK(test_glMatrixLoadfEXT);
	}
#endif

	{
		auto test_glLoadTransposeMatrixf = make_aoe_test(
			mock_glLoadTransposeMatrixf,
			v
		);
		gl.load_transpose_matrix(v);
		BOOST_CHECK(test_glLoadTransposeMatrixf);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixLoadTransposefEXT = make_aoe_test(
			mock_glMatrixLoadTransposefEXT,
			GLenum(m), v
		);
		gl.load_transpose_matrix(m, v);
		BOOST_CHECK(test_glMatrixLoadTransposefEXT);
	}
#endif

	BOOST_CHECK(mock_glLoadMatrixf.was_called());
	BOOST_CHECK(mock_glLoadTransposeMatrixf.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixLoadfEXT.was_called());
	BOOST_CHECK(mock_glMatrixLoadTransposefEXT.was_called());
#endif
}

#if defined(GL_DOUBLE)
BOOST_AUTO_TEST_CASE(compat_matrix_load_d)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble v[16];

	for(GLdouble& c : v)
	{
		c = get<GLdouble>();
	}

	{
		auto test_glLoadMatrixd = make_aoe_test(
			mock_glLoadMatrixd,
			v
		);
		gl.load_matrix(v);
		BOOST_CHECK(test_glLoadMatrixd);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixLoaddEXT = make_aoe_test(
			mock_glMatrixLoaddEXT,
			GLenum(m), v
		);
		gl.load_matrix(m, v);
		BOOST_CHECK(test_glMatrixLoaddEXT);
	}
#endif

	{
		auto test_glLoadTransposeMatrixd = make_aoe_test(
			mock_glLoadTransposeMatrixd,
			v
		);
		gl.load_transpose_matrix(v);
		BOOST_CHECK(test_glLoadTransposeMatrixd);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixLoadTransposedEXT = make_aoe_test(
			mock_glMatrixLoadTransposedEXT,
			GLenum(m), v
		);
		gl.load_transpose_matrix(m, v);
		BOOST_CHECK(test_glMatrixLoadTransposedEXT);
	}
#endif

	BOOST_CHECK(mock_glLoadMatrixd.was_called());
	BOOST_CHECK(mock_glLoadTransposeMatrixd.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixLoaddEXT.was_called());
	BOOST_CHECK(mock_glMatrixLoadTransposedEXT.was_called());
#endif
}
#endif // GL_DOUBLE

BOOST_AUTO_TEST_CASE(compat_matrix_translate_f)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLfloat x = get<GLfloat>();
	GLfloat y = get<GLfloat>();
	GLfloat z = get<GLfloat>();

	{
		auto test_glTranslatef = make_aoe_test(
			mock_glTranslatef,
			x, y, z
		);
		gl.translate_f(x, y, z);
		BOOST_CHECK(test_glTranslatef);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixTranslatefEXT = make_aoe_test(
			mock_glMatrixTranslatefEXT,
			GLenum(m), x, y, z
		);
		gl.translate_f(m, x, y, z);
		BOOST_CHECK(test_glMatrixTranslatefEXT);
	}
#endif

	BOOST_CHECK(mock_glTranslatef.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixTranslatefEXT.was_called());
#endif
}

#if defined(GL_DOUBLE)
BOOST_AUTO_TEST_CASE(compat_matrix_translate_d)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble x = get<GLdouble>();
	GLdouble y = get<GLdouble>();
	GLdouble z = get<GLdouble>();

	{
		auto test_glTranslated = make_aoe_test(
			mock_glTranslated,
			x, y, z
		);
		gl.translate_d(x, y, z);
		BOOST_CHECK(test_glTranslated);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixTranslatedEXT = make_aoe_test(
			mock_glMatrixTranslatedEXT,
			GLenum(m), x, y, z
		);
		gl.translate_d(m, x, y, z);
		BOOST_CHECK(test_glMatrixTranslatedEXT);
	}
#endif

	BOOST_CHECK(mock_glTranslated.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixTranslatedEXT.was_called());
#endif
}
#endif // GL_DOUBLE

BOOST_AUTO_TEST_CASE(compat_matrix_rotate_f)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLfloat a = get<GLfloat>();
	GLfloat x = get<GLfloat>();
	GLfloat y = get<GLfloat>();
	GLfloat z = get<GLfloat>();

	{
		auto test_glRotatef = make_aoe_test(
			mock_glRotatef,
			a, x, y, z
		);
		gl.rotate_f(degrees_(a), x, y, z);
		BOOST_CHECK(test_glRotatef);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixRotatefEXT = make_aoe_test(
			mock_glMatrixRotatefEXT,
			GLenum(m), a, x, y, z
		);
		gl.rotate_f(m, degrees_(a), x, y, z);
		BOOST_CHECK(test_glMatrixRotatefEXT);
	}
#endif

	BOOST_CHECK(mock_glRotatef.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixRotatefEXT.was_called());
#endif
}

#if defined(GL_DOUBLE)
BOOST_AUTO_TEST_CASE(compat_matrix_rotate_d)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble a = get<GLdouble>();
	GLdouble x = get<GLdouble>();
	GLdouble y = get<GLdouble>();
	GLdouble z = get<GLdouble>();

	{
		auto test_glRotated = make_aoe_test(
			mock_glRotated,
			a, x, y, z
		);
		gl.rotate_d(degrees_(a), x, y, z);
		BOOST_CHECK(test_glRotated);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixRotatedEXT = make_aoe_test(
			mock_glMatrixRotatedEXT,
			GLenum(m), a, x, y, z
		);
		gl.rotate_d(m, degrees_(a), x, y, z);
		BOOST_CHECK(test_glMatrixRotatedEXT);
	}
#endif

	BOOST_CHECK(mock_glRotated.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixRotatedEXT.was_called());
#endif
}
#endif // GL_DOUBLE

BOOST_AUTO_TEST_CASE(compat_matrix_scale_f)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLfloat x = get<GLfloat>();
	GLfloat y = get<GLfloat>();
	GLfloat z = get<GLfloat>();

	{
		auto test_glScalef = make_aoe_test(
			mock_glScalef,
			x, y, z
		);
		gl.scale_f(x, y, z);
		BOOST_CHECK(test_glScalef);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixScalefEXT = make_aoe_test(
			mock_glMatrixScalefEXT,
			GLenum(m), x, y, z
		);
		gl.scale_f(m, x, y, z);
		BOOST_CHECK(test_glMatrixScalefEXT);
	}
#endif

	BOOST_CHECK(mock_glScalef.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixScalefEXT.was_called());
#endif
}

#if defined(GL_DOUBLE)
BOOST_AUTO_TEST_CASE(compat_matrix_scale_d)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble x = get<GLdouble>();
	GLdouble y = get<GLdouble>();
	GLdouble z = get<GLdouble>();

	{
		auto test_glScaled = make_aoe_test(
			mock_glScaled,
			x, y, z
		);
		gl.scale_d(x, y, z);
		BOOST_CHECK(test_glScaled);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixScaledEXT = make_aoe_test(
			mock_glMatrixScaledEXT,
			GLenum(m), x, y, z
		);
		gl.scale_d(m, x, y, z);
		BOOST_CHECK(test_glMatrixScaledEXT);
	}
#endif

	BOOST_CHECK(mock_glScaled.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixScaledEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_ortho)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble l = get<GLdouble>();
	GLdouble r = get<GLdouble>();
	GLdouble b = get<GLdouble>();
	GLdouble t = get<GLdouble>();
	GLdouble n = get<GLdouble>();
	GLdouble f = get<GLdouble>();

	{
		auto test_glOrtho = make_aoe_test(
			mock_glOrtho,
			l, r, b, t, n, f
		);
		gl.ortho(l, r, b, t, n, f);
		BOOST_CHECK(test_glOrtho);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixOrthoEXT = make_aoe_test(
			mock_glMatrixOrthoEXT,
			GLenum(m), l, r, b, t, n, f
		);
		gl.ortho(m, l, r, b, t, n, f);
		BOOST_CHECK(test_glMatrixOrthoEXT);
	}
#endif

	BOOST_CHECK(mock_glOrtho.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixOrthoEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_frustum)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble l = get<GLdouble>();
	GLdouble r = get<GLdouble>();
	GLdouble b = get<GLdouble>();
	GLdouble t = get<GLdouble>();
	GLdouble n = get<GLdouble>();
	GLdouble f = get<GLdouble>();

	{
		auto test_glFrustum = make_aoe_test(
			mock_glFrustum,
			l, r, b, t, n, f
		);
		gl.frustum(l, r, b, t, n, f);
		BOOST_CHECK(test_glFrustum);
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		auto test_glMatrixFrustumEXT = make_aoe_test(
			mock_glMatrixFrustumEXT,
			GLenum(m), l, r, b, t, n, f
		);
		gl.frustum(m, l, r, b, t, n, f);
		BOOST_CHECK(test_glMatrixFrustumEXT);
	}
#endif

	BOOST_CHECK(mock_glFrustum.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixFrustumEXT.was_called());
#endif
}
#endif // GL_DOUBLE

#else
BOOST_AUTO_TEST_CASE(compat_matrix_dummy) { }
#endif

BOOST_AUTO_TEST_SUITE_END()
