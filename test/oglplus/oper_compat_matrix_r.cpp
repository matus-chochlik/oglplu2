/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_oper_compat_matrix
#include <boost/test/unit_test.hpp>

#include <oglplus/gl.hpp>
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

OGLPLUS_MOCK_GLFUNC(LoadMatrixd, void(const GLdouble*));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixLoaddEXT, void(GLenum, const GLdouble*));
#endif

OGLPLUS_MOCK_GLFUNC(LoadTransposeMatrixd, void(const GLdouble*));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixLoadTransposedEXT, void(GLenum, const GLdouble*));
#endif

OGLPLUS_MOCK_GLFUNC(Translatef, void(GLfloat, GLfloat, GLfloat));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixTranslatefEXT, void(GLenum, GLfloat, GLfloat, GLfloat));
#endif

OGLPLUS_MOCK_GLFUNC(Translated, void(GLdouble, GLdouble, GLdouble));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixTranslatedEXT, void(GLenum, GLdouble, GLdouble, GLdouble));
#endif

OGLPLUS_MOCK_GLFUNC(Rotatef, void(GLfloat, GLfloat, GLfloat, GLfloat));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixRotatefEXT, void(GLenum, GLfloat, GLfloat, GLfloat, GLfloat));
#endif

OGLPLUS_MOCK_GLFUNC(Rotated, void(GLdouble, GLdouble, GLdouble, GLdouble));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixRotatedEXT, void(GLenum, GLdouble, GLdouble, GLdouble, GLdouble));
#endif

OGLPLUS_MOCK_GLFUNC(Scalef, void(GLfloat, GLfloat, GLfloat));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixScalefEXT, void(GLenum, GLfloat, GLfloat, GLfloat));
#endif

OGLPLUS_MOCK_GLFUNC(Scaled, void(GLdouble, GLdouble, GLdouble));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixScaledEXT, void(GLenum, GLdouble, GLdouble, GLdouble));
#endif

OGLPLUS_MOCK_GLFUNC(Ortho, void(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixOrthoEXT, void(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble));
#endif

OGLPLUS_MOCK_GLFUNC(Frustum, void(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble));
#ifdef GL_EXT_direct_state_access
OGLPLUS_MOCK_GLFUNC(MatrixFrustumEXT, void(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble));
#endif

#include <oglplus/oper/compat_matrix.hpp>
#include <oglplus/enum/values.hpp>
#include <cstring>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(compat_matrix)

#if	defined(GL_MODELVIEW) &&\
	defined(GL_PROJECTION) &&\
	defined(GL_ARB_compatibility)

template <typename T>
static T get(void)
{
	return T(std::rand());
}

BOOST_AUTO_TEST_CASE(compat_matrix_mode)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixMode.reset_params(GLenum(m));
		BOOST_CHECK(!mock_glMatrixMode.all_ok_exclusive());
		gl.matrix_mode(m);
		BOOST_CHECK( mock_glMatrixMode.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glMatrixMode.was_called());
}

BOOST_AUTO_TEST_CASE(compat_matrix_push_pop)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	{
		mock_glPushMatrix.reset_params();
		BOOST_CHECK(!mock_glPushMatrix.all_ok_exclusive());
		gl.push_matrix();
		BOOST_CHECK( mock_glPushMatrix.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixPushEXT.reset_params(GLenum(m));
		BOOST_CHECK(!mock_glMatrixPushEXT.all_ok_exclusive());
		gl.push_matrix(m);
		BOOST_CHECK( mock_glMatrixPushEXT.all_ok_exclusive());
	}
#endif

	{
		mock_glPopMatrix.reset_params();
		BOOST_CHECK(!mock_glPopMatrix.all_ok_exclusive());
		gl.pop_matrix();
		BOOST_CHECK( mock_glPopMatrix.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.modelview;
		mock_glMatrixPopEXT.reset_params(GLenum(m));
		BOOST_CHECK(!mock_glMatrixPopEXT.all_ok_exclusive());
		gl.pop_matrix(m);
		BOOST_CHECK( mock_glMatrixPopEXT.all_ok_exclusive());
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
		mock_glLoadIdentity.reset_params();
		BOOST_CHECK(!mock_glLoadIdentity.all_ok_exclusive());
		gl.load_identity();
		BOOST_CHECK( mock_glLoadIdentity.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixLoadIdentityEXT.reset_params(GLenum(m));
		BOOST_CHECK(!mock_glMatrixLoadIdentityEXT.all_ok_exclusive());
		gl.load_identity(m);
		BOOST_CHECK( mock_glMatrixLoadIdentityEXT.all_ok_exclusive());
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
		mock_glLoadMatrixf.reset_params(v);
		BOOST_CHECK(!mock_glLoadMatrixf.all_ok_exclusive());
		gl.load_matrix(v);
		BOOST_CHECK( mock_glLoadMatrixf.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixLoadfEXT.reset_params(GLenum(m), v);
		BOOST_CHECK(!mock_glMatrixLoadfEXT.all_ok_exclusive());
		gl.load_matrix(m, v);
		BOOST_CHECK( mock_glMatrixLoadfEXT.all_ok_exclusive());
	}
#endif

	{
		mock_glLoadTransposeMatrixf.reset_params(v);
		BOOST_CHECK(!mock_glLoadTransposeMatrixf.all_ok_exclusive());
		gl.load_transpose_matrix(v);
		BOOST_CHECK( mock_glLoadTransposeMatrixf.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixLoadTransposefEXT.reset_params(GLenum(m), v);
		BOOST_CHECK(!mock_glMatrixLoadTransposefEXT.all_ok_exclusive());
		gl.load_transpose_matrix(m, v);
		BOOST_CHECK( mock_glMatrixLoadTransposefEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(mock_glLoadMatrixf.was_called());
	BOOST_CHECK(mock_glLoadTransposeMatrixf.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixLoadfEXT.was_called());
	BOOST_CHECK(mock_glMatrixLoadTransposefEXT.was_called());
#endif
}

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
		mock_glLoadMatrixd.reset_params(v);
		BOOST_CHECK(!mock_glLoadMatrixd.all_ok_exclusive());
		gl.load_matrix(v);
		BOOST_CHECK( mock_glLoadMatrixd.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixLoaddEXT.reset_params(GLenum(m), v);
		BOOST_CHECK(!mock_glMatrixLoaddEXT.all_ok_exclusive());
		gl.load_matrix(m, v);
		BOOST_CHECK( mock_glMatrixLoaddEXT.all_ok_exclusive());
	}
#endif

	{
		mock_glLoadTransposeMatrixd.reset_params(v);
		BOOST_CHECK(!mock_glLoadTransposeMatrixd.all_ok_exclusive());
		gl.load_transpose_matrix(v);
		BOOST_CHECK( mock_glLoadTransposeMatrixd.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixLoadTransposedEXT.reset_params(GLenum(m), v);
		BOOST_CHECK(!mock_glMatrixLoadTransposedEXT.all_ok_exclusive());
		gl.load_transpose_matrix(m, v);
		BOOST_CHECK( mock_glMatrixLoadTransposedEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(mock_glLoadMatrixd.was_called());
	BOOST_CHECK(mock_glLoadTransposeMatrixd.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixLoaddEXT.was_called());
	BOOST_CHECK(mock_glMatrixLoadTransposedEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_translate_f)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLfloat x = get<GLfloat>();
	GLfloat y = get<GLfloat>();
	GLfloat z = get<GLfloat>();

	{
		mock_glTranslatef.reset_params(x, y, z);
		BOOST_CHECK(!mock_glTranslatef.all_ok_exclusive());
		gl.translate_f(x, y, z);
		BOOST_CHECK( mock_glTranslatef.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixTranslatefEXT.reset_params(GLenum(m), x, y, z);
		BOOST_CHECK(!mock_glMatrixTranslatefEXT.all_ok_exclusive());
		gl.translate_f(m, x, y, z);
		BOOST_CHECK( mock_glMatrixTranslatefEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(mock_glTranslatef.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixTranslatefEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_translate_d)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble x = get<GLdouble>();
	GLdouble y = get<GLdouble>();
	GLdouble z = get<GLdouble>();

	{
		mock_glTranslated.reset_params(x, y, z);
		BOOST_CHECK(!mock_glTranslated.all_ok_exclusive());
		gl.translate_d(x, y, z);
		BOOST_CHECK( mock_glTranslated.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixTranslatedEXT.reset_params(GLenum(m), x, y, z);
		BOOST_CHECK(!mock_glMatrixTranslatedEXT.all_ok_exclusive());
		gl.translate_d(m, x, y, z);
		BOOST_CHECK( mock_glMatrixTranslatedEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(mock_glTranslated.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixTranslatedEXT.was_called());
#endif
}

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
		mock_glRotatef.reset_params(a, x, y, z);
		BOOST_CHECK(!mock_glRotatef.all_ok_exclusive());
		gl.rotate_f(degrees(a), x, y, z);
		BOOST_CHECK( mock_glRotatef.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixRotatefEXT.reset_params(GLenum(m), a, x, y, z);
		BOOST_CHECK(!mock_glMatrixRotatefEXT.all_ok_exclusive());
		gl.rotate_f(m, degrees(a), x, y, z);
		BOOST_CHECK( mock_glMatrixRotatefEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(mock_glRotatef.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixRotatefEXT.was_called());
#endif
}

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
		mock_glRotated.reset_params(a, x, y, z);
		BOOST_CHECK(!mock_glRotated.all_ok_exclusive());
		gl.rotate_d(degrees(a), x, y, z);
		BOOST_CHECK( mock_glRotated.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixRotatedEXT.reset_params(GLenum(m), a, x, y, z);
		BOOST_CHECK(!mock_glMatrixRotatedEXT.all_ok_exclusive());
		gl.rotate_d(m, degrees(a), x, y, z);
		BOOST_CHECK( mock_glMatrixRotatedEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(mock_glRotated.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixRotatedEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_scale_f)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLfloat x = get<GLfloat>();
	GLfloat y = get<GLfloat>();
	GLfloat z = get<GLfloat>();

	{
		mock_glScalef.reset_params(x, y, z);
		BOOST_CHECK(!mock_glScalef.all_ok_exclusive());
		gl.scale_f(x, y, z);
		BOOST_CHECK( mock_glScalef.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixScalefEXT.reset_params(GLenum(m), x, y, z);
		BOOST_CHECK(!mock_glMatrixScalefEXT.all_ok_exclusive());
		gl.scale_f(m, x, y, z);
		BOOST_CHECK( mock_glMatrixScalefEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(mock_glScalef.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixScalefEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_scale_d)
{
	using namespace oglplus;

	oper::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble x = get<GLdouble>();
	GLdouble y = get<GLdouble>();
	GLdouble z = get<GLdouble>();

	{
		mock_glScaled.reset_params(x, y, z);
		BOOST_CHECK(!mock_glScaled.all_ok_exclusive());
		gl.scale_d(x, y, z);
		BOOST_CHECK( mock_glScaled.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixScaledEXT.reset_params(GLenum(m), x, y, z);
		BOOST_CHECK(!mock_glMatrixScaledEXT.all_ok_exclusive());
		gl.scale_d(m, x, y, z);
		BOOST_CHECK( mock_glMatrixScaledEXT.all_ok_exclusive());
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
		mock_glOrtho.reset_params(l, r, b, t, n, f);
		BOOST_CHECK(!mock_glOrtho.all_ok_exclusive());
		gl.ortho(l, r, b, t, n, f);
		BOOST_CHECK( mock_glOrtho.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixOrthoEXT.reset_params(GLenum(m), l, r, b, t, n, f);
		BOOST_CHECK(!mock_glMatrixOrthoEXT.all_ok_exclusive());
		gl.ortho(m, l, r, b, t, n, f);
		BOOST_CHECK( mock_glMatrixOrthoEXT.all_ok_exclusive());
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
		mock_glFrustum.reset_params(l, r, b, t, n, f);
		BOOST_CHECK(!mock_glFrustum.all_ok_exclusive());
		gl.frustum(l, r, b, t, n, f);
		BOOST_CHECK( mock_glFrustum.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		mock_glMatrixFrustumEXT.reset_params(GLenum(m), l, r, b, t, n, f);
		BOOST_CHECK(!mock_glMatrixFrustumEXT.all_ok_exclusive());
		gl.frustum(m, l, r, b, t, n, f);
		BOOST_CHECK( mock_glMatrixFrustumEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(mock_glFrustum.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(mock_glMatrixFrustumEXT.was_called());
#endif
}

#else
BOOST_AUTO_TEST_CASE(compat_matrix_dummy) { }
#endif

BOOST_AUTO_TEST_SUITE_END()
