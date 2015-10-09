/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_ctxt_compat_matrix
#include <boost/test/unit_test.hpp>

#include <oglplus/gl.hpp>
#include "helper/fake_gl_func.hpp"

static oglplus::fake_gl_func_tester<void, GLenum>
fake_glMatrixMode("MatrixMode");

static oglplus::fake_gl_func_tester<void>
fake_glPushMatrix("PushMatrix");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum>
fake_glMatrixPushEXT("MatrixPushEXT");
#endif

static oglplus::fake_gl_func_tester<void>
fake_glPopMatrix("PopMatrix");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum>
fake_glMatrixPopEXT("MatrixPopEXT");
#endif

static oglplus::fake_gl_func_tester<void>
fake_glLoadIdentity("LoadIdentity");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum>
fake_glMatrixLoadIdentityEXT("MatrixLoadIdentityEXT");
#endif

static oglplus::fake_gl_func_tester<void, const GLfloat*>
fake_glLoadMatrixf("LoadMatrixf");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, const GLfloat*>
fake_glMatrixLoadfEXT("MatrixLoadfEXT");
#endif

static oglplus::fake_gl_func_tester<void, const GLfloat*>
fake_glLoadTransposeMatrixf("LoadTransposeMatrixf");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, const GLfloat*>
fake_glMatrixLoadTransposefEXT("MatrixLoadTransposefEXT");
#endif

static oglplus::fake_gl_func_tester<void, const GLdouble*>
fake_glLoadMatrixd("LoadMatrixd");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, const GLdouble*>
fake_glMatrixLoaddEXT("MatrixLoaddEXT");
#endif

static oglplus::fake_gl_func_tester<void, const GLdouble*>
fake_glLoadTransposeMatrixd("LoadTransposeMatrixd");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, const GLdouble*>
fake_glMatrixLoadTransposedEXT("MatrixLoadTransposedEXT");
#endif

static oglplus::fake_gl_func_tester<void, GLfloat, GLfloat, GLfloat>
fake_glTranslatef("Translatef");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, GLfloat, GLfloat, GLfloat>
fake_glMatrixTranslatefEXT("MatrixTranslatefEXT");
#endif

static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble, GLdouble>
fake_glTranslated("Translated");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, GLdouble, GLdouble, GLdouble>
fake_glMatrixTranslatedEXT("MatrixTranslatedEXT");
#endif

static oglplus::fake_gl_func_tester<void, GLfloat, GLfloat, GLfloat, GLfloat>
fake_glRotatef("Rotatef");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, GLfloat, GLfloat, GLfloat, GLfloat>
fake_glMatrixRotatefEXT("MatrixRotatefEXT");
#endif

static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble, GLdouble, GLdouble>
fake_glRotated("Rotated");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, GLdouble, GLdouble, GLdouble, GLdouble>
fake_glMatrixRotatedEXT("MatrixRotatedEXT");
#endif

static oglplus::fake_gl_func_tester<void, GLfloat, GLfloat, GLfloat>
fake_glScalef("Scalef");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, GLfloat, GLfloat, GLfloat>
fake_glMatrixScalefEXT("MatrixScalefEXT");
#endif

static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble, GLdouble>
fake_glScaled("Scaled");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, GLdouble, GLdouble, GLdouble>
fake_glMatrixScaledEXT("MatrixScaledEXT");
#endif

static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble>
fake_glOrtho("Ortho");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble>
fake_glMatrixOrthoEXT("MatrixOrthoEXT");
#endif

static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble>
fake_glFrustum("Frustum");
#ifdef GL_EXT_direct_state_access
static oglplus::fake_gl_func_tester<void, GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble>
fake_glMatrixFrustumEXT("MatrixFrustumEXT");
#endif

#include <oglplus/ctxt/compat_matrix.hpp>
#include <oglplus/enum_values.hpp>
#include <cstring>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(compat_matrix)

template <typename T>
static T get(void)
{
	return T(std::rand());
}

BOOST_AUTO_TEST_CASE(compat_matrix_mode)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixMode.reset_params(GLenum(m));
		BOOST_CHECK(!fake_glMatrixMode.all_ok_exclusive());
		gl.matrix_mode(m);
		BOOST_CHECK( fake_glMatrixMode.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glMatrixMode.was_called());
}

BOOST_AUTO_TEST_CASE(compat_matrix_push_pop)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	{
		fake_glPushMatrix.reset_params();
		BOOST_CHECK(!fake_glPushMatrix.all_ok_exclusive());
		gl.push_matrix();
		BOOST_CHECK( fake_glPushMatrix.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixPushEXT.reset_params(GLenum(m));
		BOOST_CHECK(!fake_glMatrixPushEXT.all_ok_exclusive());
		gl.push_matrix(m);
		BOOST_CHECK( fake_glMatrixPushEXT.all_ok_exclusive());
	}
#endif

	{
		fake_glPopMatrix.reset_params();
		BOOST_CHECK(!fake_glPopMatrix.all_ok_exclusive());
		gl.pop_matrix();
		BOOST_CHECK( fake_glPopMatrix.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.modelview;
		fake_glMatrixPopEXT.reset_params(GLenum(m));
		BOOST_CHECK(!fake_glMatrixPopEXT.all_ok_exclusive());
		gl.pop_matrix(m);
		BOOST_CHECK( fake_glMatrixPopEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glPushMatrix.was_called());
	BOOST_CHECK(fake_glPopMatrix.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixPushEXT.was_called());
	BOOST_CHECK(fake_glMatrixPopEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_load_identity)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	{
		fake_glLoadIdentity.reset_params();
		BOOST_CHECK(!fake_glLoadIdentity.all_ok_exclusive());
		gl.load_identity();
		BOOST_CHECK( fake_glLoadIdentity.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixLoadIdentityEXT.reset_params(GLenum(m));
		BOOST_CHECK(!fake_glMatrixLoadIdentityEXT.all_ok_exclusive());
		gl.load_identity(m);
		BOOST_CHECK( fake_glMatrixLoadIdentityEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glLoadIdentity.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixLoadIdentityEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_load_f)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLfloat v[16];

	for(GLfloat& c : v)
	{
		c = get<GLfloat>();
	}

	{
		fake_glLoadMatrixf.reset_params(v);
		BOOST_CHECK(!fake_glLoadMatrixf.all_ok_exclusive());
		gl.load_matrix(v);
		BOOST_CHECK( fake_glLoadMatrixf.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixLoadfEXT.reset_params(GLenum(m), v);
		BOOST_CHECK(!fake_glMatrixLoadfEXT.all_ok_exclusive());
		gl.load_matrix(m, v);
		BOOST_CHECK( fake_glMatrixLoadfEXT.all_ok_exclusive());
	}
#endif

	{
		fake_glLoadTransposeMatrixf.reset_params(v);
		BOOST_CHECK(!fake_glLoadTransposeMatrixf.all_ok_exclusive());
		gl.load_transpose_matrix(v);
		BOOST_CHECK( fake_glLoadTransposeMatrixf.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixLoadTransposefEXT.reset_params(GLenum(m), v);
		BOOST_CHECK(!fake_glMatrixLoadTransposefEXT.all_ok_exclusive());
		gl.load_transpose_matrix(m, v);
		BOOST_CHECK( fake_glMatrixLoadTransposefEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glLoadMatrixf.was_called());
	BOOST_CHECK(fake_glLoadTransposeMatrixf.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixLoadfEXT.was_called());
	BOOST_CHECK(fake_glMatrixLoadTransposefEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_load_d)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble v[16];

	for(GLdouble& c : v)
	{
		c = get<GLdouble>();
	}

	{
		fake_glLoadMatrixd.reset_params(v);
		BOOST_CHECK(!fake_glLoadMatrixd.all_ok_exclusive());
		gl.load_matrix(v);
		BOOST_CHECK( fake_glLoadMatrixd.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixLoaddEXT.reset_params(GLenum(m), v);
		BOOST_CHECK(!fake_glMatrixLoaddEXT.all_ok_exclusive());
		gl.load_matrix(m, v);
		BOOST_CHECK( fake_glMatrixLoaddEXT.all_ok_exclusive());
	}
#endif

	{
		fake_glLoadTransposeMatrixd.reset_params(v);
		BOOST_CHECK(!fake_glLoadTransposeMatrixd.all_ok_exclusive());
		gl.load_transpose_matrix(v);
		BOOST_CHECK( fake_glLoadTransposeMatrixd.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixLoadTransposedEXT.reset_params(GLenum(m), v);
		BOOST_CHECK(!fake_glMatrixLoadTransposedEXT.all_ok_exclusive());
		gl.load_transpose_matrix(m, v);
		BOOST_CHECK( fake_glMatrixLoadTransposedEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glLoadMatrixd.was_called());
	BOOST_CHECK(fake_glLoadTransposeMatrixd.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixLoaddEXT.was_called());
	BOOST_CHECK(fake_glMatrixLoadTransposedEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_translate_f)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLfloat x = get<GLfloat>();
	GLfloat y = get<GLfloat>();
	GLfloat z = get<GLfloat>();

	{
		fake_glTranslatef.reset_params(x, y, z);
		BOOST_CHECK(!fake_glTranslatef.all_ok_exclusive());
		gl.translate_f(x, y, z);
		BOOST_CHECK( fake_glTranslatef.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixTranslatefEXT.reset_params(GLenum(m), x, y, z);
		BOOST_CHECK(!fake_glMatrixTranslatefEXT.all_ok_exclusive());
		gl.translate_f(m, x, y, z);
		BOOST_CHECK( fake_glMatrixTranslatefEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glTranslatef.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixTranslatefEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_translate_d)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble x = get<GLdouble>();
	GLdouble y = get<GLdouble>();
	GLdouble z = get<GLdouble>();

	{
		fake_glTranslated.reset_params(x, y, z);
		BOOST_CHECK(!fake_glTranslated.all_ok_exclusive());
		gl.translate_d(x, y, z);
		BOOST_CHECK( fake_glTranslated.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixTranslatedEXT.reset_params(GLenum(m), x, y, z);
		BOOST_CHECK(!fake_glMatrixTranslatedEXT.all_ok_exclusive());
		gl.translate_d(m, x, y, z);
		BOOST_CHECK( fake_glMatrixTranslatedEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glTranslated.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixTranslatedEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_rotate_f)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLfloat a = get<GLfloat>();
	GLfloat x = get<GLfloat>();
	GLfloat y = get<GLfloat>();
	GLfloat z = get<GLfloat>();

	{
		fake_glRotatef.reset_params(a, x, y, z);
		BOOST_CHECK(!fake_glRotatef.all_ok_exclusive());
		gl.rotate_f(a, x, y, z);
		BOOST_CHECK( fake_glRotatef.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixRotatefEXT.reset_params(GLenum(m), a, x, y, z);
		BOOST_CHECK(!fake_glMatrixRotatefEXT.all_ok_exclusive());
		gl.rotate_f(m, a, x, y, z);
		BOOST_CHECK( fake_glMatrixRotatefEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glRotatef.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixRotatefEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_rotate_d)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble a = get<GLdouble>();
	GLdouble x = get<GLdouble>();
	GLdouble y = get<GLdouble>();
	GLdouble z = get<GLdouble>();

	{
		fake_glRotated.reset_params(a, x, y, z);
		BOOST_CHECK(!fake_glRotated.all_ok_exclusive());
		gl.rotate_d(a, x, y, z);
		BOOST_CHECK( fake_glRotated.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixRotatedEXT.reset_params(GLenum(m), a, x, y, z);
		BOOST_CHECK(!fake_glMatrixRotatedEXT.all_ok_exclusive());
		gl.rotate_d(m, a, x, y, z);
		BOOST_CHECK( fake_glMatrixRotatedEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glRotated.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixRotatedEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_scale_f)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLfloat x = get<GLfloat>();
	GLfloat y = get<GLfloat>();
	GLfloat z = get<GLfloat>();

	{
		fake_glScalef.reset_params(x, y, z);
		BOOST_CHECK(!fake_glScalef.all_ok_exclusive());
		gl.scale_f(x, y, z);
		BOOST_CHECK( fake_glScalef.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixScalefEXT.reset_params(GLenum(m), x, y, z);
		BOOST_CHECK(!fake_glMatrixScalefEXT.all_ok_exclusive());
		gl.scale_f(m, x, y, z);
		BOOST_CHECK( fake_glMatrixScalefEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glScalef.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixScalefEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_scale_d)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble x = get<GLdouble>();
	GLdouble y = get<GLdouble>();
	GLdouble z = get<GLdouble>();

	{
		fake_glScaled.reset_params(x, y, z);
		BOOST_CHECK(!fake_glScaled.all_ok_exclusive());
		gl.scale_d(x, y, z);
		BOOST_CHECK( fake_glScaled.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixScaledEXT.reset_params(GLenum(m), x, y, z);
		BOOST_CHECK(!fake_glMatrixScaledEXT.all_ok_exclusive());
		gl.scale_d(m, x, y, z);
		BOOST_CHECK( fake_glMatrixScaledEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glScaled.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixScaledEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_ortho)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble l = get<GLdouble>();
	GLdouble r = get<GLdouble>();
	GLdouble b = get<GLdouble>();
	GLdouble t = get<GLdouble>();
	GLdouble n = get<GLdouble>();
	GLdouble f = get<GLdouble>();

	{
		fake_glOrtho.reset_params(l, r, b, t, n, f);
		BOOST_CHECK(!fake_glOrtho.all_ok_exclusive());
		gl.ortho(l, r, b, t, n, f);
		BOOST_CHECK( fake_glOrtho.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixOrthoEXT.reset_params(GLenum(m), l, r, b, t, n, f);
		BOOST_CHECK(!fake_glMatrixOrthoEXT.all_ok_exclusive());
		gl.ortho(m, l, r, b, t, n, f);
		BOOST_CHECK( fake_glMatrixOrthoEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glOrtho.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixOrthoEXT.was_called());
#endif
}

BOOST_AUTO_TEST_CASE(compat_matrix_frustum)
{
	using namespace oglplus;

	ctxt::compatibility_matrix gl;
	oglplus::enum_values GL;

	GLdouble l = get<GLdouble>();
	GLdouble r = get<GLdouble>();
	GLdouble b = get<GLdouble>();
	GLdouble t = get<GLdouble>();
	GLdouble n = get<GLdouble>();
	GLdouble f = get<GLdouble>();

	{
		fake_glFrustum.reset_params(l, r, b, t, n, f);
		BOOST_CHECK(!fake_glFrustum.all_ok_exclusive());
		gl.frustum(l, r, b, t, n, f);
		BOOST_CHECK( fake_glFrustum.all_ok_exclusive());
	}
#ifdef GL_EXT_direct_state_access
	{
		old_matrix_mode m = GL.projection;
		fake_glMatrixFrustumEXT.reset_params(GLenum(m), l, r, b, t, n, f);
		BOOST_CHECK(!fake_glMatrixFrustumEXT.all_ok_exclusive());
		gl.frustum(m, l, r, b, t, n, f);
		BOOST_CHECK( fake_glMatrixFrustumEXT.all_ok_exclusive());
	}
#endif

	BOOST_CHECK(fake_glFrustum.was_called());
#ifdef GL_EXT_direct_state_access
	BOOST_CHECK(fake_glMatrixFrustumEXT.was_called());
#endif
}

BOOST_AUTO_TEST_SUITE_END()
