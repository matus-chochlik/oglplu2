/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_ctxt_compat_drawing
#include <boost/test/unit_test.hpp>

#include "helper/fake_gl_func.hpp"
#include <oglplus/gl.hpp>

static oglplus::fake_gl_func_tester<void, GLenum>
fake_glBegin("Begin");
static oglplus::fake_gl_func_tester<void>
fake_glEnd("End");


static oglplus::fake_gl_func_tester<void, GLshort, GLshort>
fake_glVertex2s("Vertex2s");
static oglplus::fake_gl_func_tester<void, GLshort, GLshort, GLshort>
fake_glVertex3s("Vertex3s");
static oglplus::fake_gl_func_tester<void, GLshort, GLshort, GLshort, GLshort>
fake_glVertex4s("Vertex4s");

static oglplus::fake_gl_func_tester<void, const GLshort*>
fake_glVertex2sv("Vertex2sv");
static oglplus::fake_gl_func_tester<void, const GLshort*>
fake_glVertex3sv("Vertex3sv");
static oglplus::fake_gl_func_tester<void, const GLshort*>
fake_glVertex4sv("Vertex4sv");

static oglplus::fake_gl_func_tester<void, GLint, GLint>
fake_glVertex2i("Vertex2i");
static oglplus::fake_gl_func_tester<void, GLint, GLint, GLint>
fake_glVertex3i("Vertex3i");
static oglplus::fake_gl_func_tester<void, GLint, GLint, GLint, GLint>
fake_glVertex4i("Vertex4i");

static oglplus::fake_gl_func_tester<void, const GLint*>
fake_glVertex2iv("Vertex2iv");
static oglplus::fake_gl_func_tester<void, const GLint*>
fake_glVertex3iv("Vertex3iv");
static oglplus::fake_gl_func_tester<void, const GLint*>
fake_glVertex4iv("Vertex4iv");

static oglplus::fake_gl_func_tester<void, GLfloat, GLfloat>
fake_glVertex2f("Vertex2f");
static oglplus::fake_gl_func_tester<void, GLfloat, GLfloat, GLfloat>
fake_glVertex3f("Vertex3f");
static oglplus::fake_gl_func_tester<void, GLfloat, GLfloat, GLfloat, GLfloat>
fake_glVertex4f("Vertex4f");

static oglplus::fake_gl_func_tester<void, const GLfloat*>
fake_glVertex2fv("Vertex2fv");
static oglplus::fake_gl_func_tester<void, const GLfloat*>
fake_glVertex3fv("Vertex3fv");
static oglplus::fake_gl_func_tester<void, const GLfloat*>
fake_glVertex4fv("Vertex4fv");

static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble>
fake_glVertex2d("Vertex2d");
static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble, GLdouble>
fake_glVertex3d("Vertex3d");
static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble, GLdouble, GLdouble>
fake_glVertex4d("Vertex4d");

static oglplus::fake_gl_func_tester<void, const GLdouble*>
fake_glVertex2dv("Vertex2dv");
static oglplus::fake_gl_func_tester<void, const GLdouble*>
fake_glVertex3dv("Vertex3dv");
static oglplus::fake_gl_func_tester<void, const GLdouble*>
fake_glVertex4dv("Vertex4dv");


static oglplus::fake_gl_func_tester<void, GLubyte, GLubyte, GLubyte>
fake_glColor3ub("Color3ub");
static oglplus::fake_gl_func_tester<void, GLubyte, GLubyte, GLubyte, GLubyte>
fake_glColor4ub("Color4ub");

static oglplus::fake_gl_func_tester<void, const GLubyte*>
fake_glColor3ubv("Color3ubv");
static oglplus::fake_gl_func_tester<void, const GLubyte*>
fake_glColor4ubv("Color4ubv");

static oglplus::fake_gl_func_tester<void, GLint, GLint, GLint>
fake_glColor3i("Color3i");
static oglplus::fake_gl_func_tester<void, GLint, GLint, GLint, GLint>
fake_glColor4i("Color4i");

static oglplus::fake_gl_func_tester<void, const GLint*>
fake_glColor3iv("Color3iv");
static oglplus::fake_gl_func_tester<void, const GLint*>
fake_glColor4iv("Color4iv");

static oglplus::fake_gl_func_tester<void, GLfloat, GLfloat, GLfloat>
fake_glColor3f("Color3f");
static oglplus::fake_gl_func_tester<void, GLfloat, GLfloat, GLfloat, GLfloat>
fake_glColor4f("Color4f");

static oglplus::fake_gl_func_tester<void, const GLfloat*>
fake_glColor3fv("Color3fv");
static oglplus::fake_gl_func_tester<void, const GLfloat*>
fake_glColor4fv("Color4fv");

static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble, GLdouble>
fake_glColor3d("Color3d");
static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble, GLdouble, GLdouble>
fake_glColor4d("Color4d");

static oglplus::fake_gl_func_tester<void, const GLdouble*>
fake_glColor3dv("Color3dv");
static oglplus::fake_gl_func_tester<void, const GLdouble*>
fake_glColor4dv("Color4dv");


static oglplus::fake_gl_func_tester<void, GLshort>
fake_glTexCoord1s("TexCoord1s");
static oglplus::fake_gl_func_tester<void, GLshort, GLshort>
fake_glTexCoord2s("TexCoord2s");
static oglplus::fake_gl_func_tester<void, GLshort, GLshort, GLshort>
fake_glTexCoord3s("TexCoord3s");
static oglplus::fake_gl_func_tester<void, GLshort, GLshort, GLshort, GLshort>
fake_glTexCoord4s("TexCoord4s");

static oglplus::fake_gl_func_tester<void, const GLshort*>
fake_glTexCoord1sv("TexCoord1sv");
static oglplus::fake_gl_func_tester<void, const GLshort*>
fake_glTexCoord2sv("TexCoord2sv");
static oglplus::fake_gl_func_tester<void, const GLshort*>
fake_glTexCoord3sv("TexCoord3sv");
static oglplus::fake_gl_func_tester<void, const GLshort*>
fake_glTexCoord4sv("TexCoord4sv");

static oglplus::fake_gl_func_tester<void, GLint>
fake_glTexCoord1i("TexCoord1i");
static oglplus::fake_gl_func_tester<void, GLint, GLint>
fake_glTexCoord2i("TexCoord2i");
static oglplus::fake_gl_func_tester<void, GLint, GLint, GLint>
fake_glTexCoord3i("TexCoord3i");
static oglplus::fake_gl_func_tester<void, GLint, GLint, GLint, GLint>
fake_glTexCoord4i("TexCoord4i");

static oglplus::fake_gl_func_tester<void, const GLint*>
fake_glTexCoord1iv("TexCoord1iv");
static oglplus::fake_gl_func_tester<void, const GLint*>
fake_glTexCoord2iv("TexCoord2iv");
static oglplus::fake_gl_func_tester<void, const GLint*>
fake_glTexCoord3iv("TexCoord3iv");
static oglplus::fake_gl_func_tester<void, const GLint*>
fake_glTexCoord4iv("TexCoord4iv");

static oglplus::fake_gl_func_tester<void, GLfloat>
fake_glTexCoord1f("TexCoord1f");
static oglplus::fake_gl_func_tester<void, GLfloat, GLfloat>
fake_glTexCoord2f("TexCoord2f");
static oglplus::fake_gl_func_tester<void, GLfloat, GLfloat, GLfloat>
fake_glTexCoord3f("TexCoord3f");
static oglplus::fake_gl_func_tester<void, GLfloat, GLfloat, GLfloat, GLfloat>
fake_glTexCoord4f("TexCoord4f");

static oglplus::fake_gl_func_tester<void, const GLfloat*>
fake_glTexCoord1fv("TexCoord1fv");
static oglplus::fake_gl_func_tester<void, const GLfloat*>
fake_glTexCoord2fv("TexCoord2fv");
static oglplus::fake_gl_func_tester<void, const GLfloat*>
fake_glTexCoord3fv("TexCoord3fv");
static oglplus::fake_gl_func_tester<void, const GLfloat*>
fake_glTexCoord4fv("TexCoord4fv");

static oglplus::fake_gl_func_tester<void, GLdouble>
fake_glTexCoord1d("TexCoord1d");
static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble>
fake_glTexCoord2d("TexCoord2d");
static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble, GLdouble>
fake_glTexCoord3d("TexCoord3d");
static oglplus::fake_gl_func_tester<void, GLdouble, GLdouble, GLdouble, GLdouble>
fake_glTexCoord4d("TexCoord4d");

static oglplus::fake_gl_func_tester<void, const GLdouble*>
fake_glTexCoord1dv("TexCoord1dv");
static oglplus::fake_gl_func_tester<void, const GLdouble*>
fake_glTexCoord2dv("TexCoord2dv");
static oglplus::fake_gl_func_tester<void, const GLdouble*>
fake_glTexCoord3dv("TexCoord3dv");
static oglplus::fake_gl_func_tester<void, const GLdouble*>
fake_glTexCoord4dv("TexCoord4dv");


#include <oglplus/ctxt/compat_drawing.hpp>
#include <cstring>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(compat_drawing)

template <typename T>
static T get(void)
{
	return T(std::rand());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_s)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLshort x = get<GLshort>();
		GLshort y = get<GLshort>();

		fake_glVertex2s.reset_params(x, y);
		BOOST_CHECK(!fake_glVertex2s.all_ok_exclusive());
		gl.vertex_s(x, y);
		BOOST_CHECK( fake_glVertex2s.all_ok_exclusive());
	}
	{
		GLshort x = get<GLshort>();
		GLshort y = get<GLshort>();
		GLshort z = get<GLshort>();

		fake_glVertex3s.reset_params(x, y, z);
		BOOST_CHECK(!fake_glVertex3s.all_ok_exclusive());
		gl.vertex_s(x, y, z);
		BOOST_CHECK( fake_glVertex3s.all_ok_exclusive());
	}
	{
		GLshort x = get<GLshort>();
		GLshort y = get<GLshort>();
		GLshort z = get<GLshort>();
		GLshort w = get<GLshort>();

		fake_glVertex4s.reset_params(x, y, z, w);
		BOOST_CHECK(!fake_glVertex4s.all_ok_exclusive());
		gl.vertex_s(x, y, z, w);
		BOOST_CHECK( fake_glVertex4s.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glVertex2s.was_called());
	BOOST_CHECK(fake_glVertex3s.was_called());
	BOOST_CHECK(fake_glVertex4s.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_sv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLshort v[2] = {get<GLshort>(), get<GLshort>()};

		fake_glVertex2sv.reset_params(v);
		BOOST_CHECK(!fake_glVertex2sv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex2sv.all_ok_exclusive());
	}
	{
		const GLshort v[3] = {get<GLshort>(), get<GLshort>(), get<GLshort>()};

		fake_glVertex3sv.reset_params(v);
		BOOST_CHECK(!fake_glVertex3sv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex3sv.all_ok_exclusive());
	}
	{
		const GLshort v[4] = {get<GLshort>(), get<GLshort>(), get<GLshort>(), get<GLshort>()};

		fake_glVertex4sv.reset_params(v);
		BOOST_CHECK(!fake_glVertex4sv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex4sv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glVertex2sv.was_called());
	BOOST_CHECK(fake_glVertex3sv.was_called());
	BOOST_CHECK(fake_glVertex4sv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_i)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();

		fake_glVertex2i.reset_params(x, y);
		BOOST_CHECK(!fake_glVertex2i.all_ok_exclusive());
		gl.vertex_i(x, y);
		BOOST_CHECK( fake_glVertex2i.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();

		fake_glVertex3i.reset_params(x, y, z);
		BOOST_CHECK(!fake_glVertex3i.all_ok_exclusive());
		gl.vertex_i(x, y, z);
		BOOST_CHECK( fake_glVertex3i.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();
		GLint w = get<GLint>();

		fake_glVertex4i.reset_params(x, y, z, w);
		BOOST_CHECK(!fake_glVertex4i.all_ok_exclusive());
		gl.vertex_i(x, y, z, w);
		BOOST_CHECK( fake_glVertex4i.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glVertex2i.was_called());
	BOOST_CHECK(fake_glVertex3i.was_called());
	BOOST_CHECK(fake_glVertex4i.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_iv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLint v[2] = {get<GLint>(), get<GLint>()};

		fake_glVertex2iv.reset_params(v);
		BOOST_CHECK(!fake_glVertex2iv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex2iv.all_ok_exclusive());
	}
	{
		const GLint v[3] = {get<GLint>(), get<GLint>(), get<GLint>()};

		fake_glVertex3iv.reset_params(v);
		BOOST_CHECK(!fake_glVertex3iv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex3iv.all_ok_exclusive());
	}
	{
		const GLint v[4] = {get<GLint>(), get<GLint>(), get<GLint>(), get<GLint>()};

		fake_glVertex4iv.reset_params(v);
		BOOST_CHECK(!fake_glVertex4iv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex4iv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glVertex2iv.was_called());
	BOOST_CHECK(fake_glVertex3iv.was_called());
	BOOST_CHECK(fake_glVertex4iv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_f)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();

		fake_glVertex2f.reset_params(x, y);
		BOOST_CHECK(!fake_glVertex2f.all_ok_exclusive());
		gl.vertex_f(x, y);
		BOOST_CHECK( fake_glVertex2f.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();

		fake_glVertex3f.reset_params(x, y, z);
		BOOST_CHECK(!fake_glVertex3f.all_ok_exclusive());
		gl.vertex_f(x, y, z);
		BOOST_CHECK( fake_glVertex3f.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();
		GLint w = get<GLint>();

		fake_glVertex4f.reset_params(x, y, z, w);
		BOOST_CHECK(!fake_glVertex4f.all_ok_exclusive());
		gl.vertex_f(x, y, z, w);
		BOOST_CHECK( fake_glVertex4f.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glVertex2f.was_called());
	BOOST_CHECK(fake_glVertex3f.was_called());
	BOOST_CHECK(fake_glVertex4f.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_fv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLfloat v[2] = {get<GLfloat>(), get<GLfloat>()};

		fake_glVertex2fv.reset_params(v);
		BOOST_CHECK(!fake_glVertex2fv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex2fv.all_ok_exclusive());
	}
	{
		const GLfloat v[3] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		fake_glVertex3fv.reset_params(v);
		BOOST_CHECK(!fake_glVertex3fv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex3fv.all_ok_exclusive());
	}
	{
		const GLfloat v[4] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		fake_glVertex4fv.reset_params(v);
		BOOST_CHECK(!fake_glVertex4fv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex4fv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glVertex2fv.was_called());
	BOOST_CHECK(fake_glVertex3fv.was_called());
	BOOST_CHECK(fake_glVertex4fv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_d)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();

		fake_glVertex2d.reset_params(x, y);
		BOOST_CHECK(!fake_glVertex2d.all_ok_exclusive());
		gl.vertex_d(x, y);
		BOOST_CHECK( fake_glVertex2d.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();

		fake_glVertex3d.reset_params(x, y, z);
		BOOST_CHECK(!fake_glVertex3d.all_ok_exclusive());
		gl.vertex_d(x, y, z);
		BOOST_CHECK( fake_glVertex3d.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();
		GLint w = get<GLint>();

		fake_glVertex4d.reset_params(x, y, z, w);
		BOOST_CHECK(!fake_glVertex4d.all_ok_exclusive());
		gl.vertex_d(x, y, z, w);
		BOOST_CHECK( fake_glVertex4d.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glVertex2d.was_called());
	BOOST_CHECK(fake_glVertex3d.was_called());
	BOOST_CHECK(fake_glVertex4d.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_dv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLdouble v[2] = {get<GLdouble>(), get<GLdouble>()};

		fake_glVertex2dv.reset_params(v);
		BOOST_CHECK(!fake_glVertex2dv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex2dv.all_ok_exclusive());
	}
	{
		const GLdouble v[3] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		fake_glVertex3dv.reset_params(v);
		BOOST_CHECK(!fake_glVertex3dv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex3dv.all_ok_exclusive());
	}
	{
		const GLdouble v[4] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		fake_glVertex4dv.reset_params(v);
		BOOST_CHECK(!fake_glVertex4dv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( fake_glVertex4dv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glVertex2dv.was_called());
	BOOST_CHECK(fake_glVertex3dv.was_called());
	BOOST_CHECK(fake_glVertex4dv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_ub)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLubyte r = get<GLubyte>();
		GLubyte g = get<GLubyte>();
		GLubyte b = get<GLubyte>();

		fake_glColor3ub.reset_params(r, g, b);
		BOOST_CHECK(!fake_glColor3ub.all_ok_exclusive());
		gl.color_ub(r, g, b);
		BOOST_CHECK( fake_glColor3ub.all_ok_exclusive());
	}
	{
		GLubyte r = get<GLubyte>();
		GLubyte g = get<GLubyte>();
		GLubyte b = get<GLubyte>();
		GLubyte a = get<GLubyte>();

		fake_glColor4ub.reset_params(r, g, b, a);
		BOOST_CHECK(!fake_glColor4ub.all_ok_exclusive());
		gl.color_ub(r, g, b, a);
		BOOST_CHECK( fake_glColor4ub.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glColor3ub.was_called());
	BOOST_CHECK(fake_glColor4ub.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_ubv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLubyte v[3] = {get<GLubyte>(), get<GLubyte>(), get<GLubyte>()};

		fake_glColor3ubv.reset_params(v);
		BOOST_CHECK(!fake_glColor3ubv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( fake_glColor3ubv.all_ok_exclusive());
	}
	{
		const GLubyte v[4] = {get<GLubyte>(), get<GLubyte>(), get<GLubyte>(), get<GLubyte>()};

		fake_glColor4ubv.reset_params(v);
		BOOST_CHECK(!fake_glColor4ubv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( fake_glColor4ubv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glColor3ubv.was_called());
	BOOST_CHECK(fake_glColor4ubv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_i)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLint r = get<GLint>();
		GLint g = get<GLint>();
		GLint b = get<GLint>();

		fake_glColor3i.reset_params(r, g, b);
		BOOST_CHECK(!fake_glColor3i.all_ok_exclusive());
		gl.color_i(r, g, b);
		BOOST_CHECK( fake_glColor3i.all_ok_exclusive());
	}
	{
		GLint r = get<GLint>();
		GLint g = get<GLint>();
		GLint b = get<GLint>();
		GLint a = get<GLint>();

		fake_glColor4i.reset_params(r, g, b, a);
		BOOST_CHECK(!fake_glColor4i.all_ok_exclusive());
		gl.color_i(r, g, b, a);
		BOOST_CHECK( fake_glColor4i.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glColor3i.was_called());
	BOOST_CHECK(fake_glColor4i.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_iv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLint v[3] = {get<GLint>(), get<GLint>(), get<GLint>()};

		fake_glColor3iv.reset_params(v);
		BOOST_CHECK(!fake_glColor3iv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( fake_glColor3iv.all_ok_exclusive());
	}
	{
		const GLint v[4] = {get<GLint>(), get<GLint>(), get<GLint>(), get<GLint>()};

		fake_glColor4iv.reset_params(v);
		BOOST_CHECK(!fake_glColor4iv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( fake_glColor4iv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glColor3iv.was_called());
	BOOST_CHECK(fake_glColor4iv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_f)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLfloat r = get<GLfloat>();
		GLfloat g = get<GLfloat>();
		GLfloat b = get<GLfloat>();

		fake_glColor3f.reset_params(r, g, b);
		BOOST_CHECK(!fake_glColor3f.all_ok_exclusive());
		gl.color_f(r, g, b);
		BOOST_CHECK( fake_glColor3f.all_ok_exclusive());
	}
	{
		GLfloat r = get<GLfloat>();
		GLfloat g = get<GLfloat>();
		GLfloat b = get<GLfloat>();
		GLfloat a = get<GLfloat>();

		fake_glColor4f.reset_params(r, g, b, a);
		BOOST_CHECK(!fake_glColor4f.all_ok_exclusive());
		gl.color_f(r, g, b, a);
		BOOST_CHECK( fake_glColor4f.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glColor3f.was_called());
	BOOST_CHECK(fake_glColor4f.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_fv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLfloat v[3] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		fake_glColor3fv.reset_params(v);
		BOOST_CHECK(!fake_glColor3fv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( fake_glColor3fv.all_ok_exclusive());
	}
	{
		const GLfloat v[4] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		fake_glColor4fv.reset_params(v);
		BOOST_CHECK(!fake_glColor4fv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( fake_glColor4fv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glColor3fv.was_called());
	BOOST_CHECK(fake_glColor4fv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_d)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLdouble r = get<GLdouble>();
		GLdouble g = get<GLdouble>();
		GLdouble b = get<GLdouble>();

		fake_glColor3d.reset_params(r, g, b);
		BOOST_CHECK(!fake_glColor3d.all_ok_exclusive());
		gl.color_d(r, g, b);
		BOOST_CHECK( fake_glColor3d.all_ok_exclusive());
	}
	{
		GLdouble r = get<GLdouble>();
		GLdouble g = get<GLdouble>();
		GLdouble b = get<GLdouble>();
		GLdouble a = get<GLdouble>();

		fake_glColor4d.reset_params(r, g, b, a);
		BOOST_CHECK(!fake_glColor4d.all_ok_exclusive());
		gl.color_d(r, g, b, a);
		BOOST_CHECK( fake_glColor4d.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glColor3d.was_called());
	BOOST_CHECK(fake_glColor4d.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_dv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLdouble v[3] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		fake_glColor3dv.reset_params(v);
		BOOST_CHECK(!fake_glColor3dv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( fake_glColor3dv.all_ok_exclusive());
	}
	{
		const GLdouble v[4] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		fake_glColor4dv.reset_params(v);
		BOOST_CHECK(!fake_glColor4dv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( fake_glColor4dv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glColor3dv.was_called());
	BOOST_CHECK(fake_glColor4dv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_s)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLshort s = get<GLshort>();

		fake_glTexCoord1s.reset_params(s);
		BOOST_CHECK(!fake_glTexCoord1s.all_ok_exclusive());
		gl.tex_coord_s(s);
		BOOST_CHECK( fake_glTexCoord1s.all_ok_exclusive());
	}
	{
		GLshort s = get<GLshort>();
		GLshort t = get<GLshort>();

		fake_glTexCoord2s.reset_params(s, t);
		BOOST_CHECK(!fake_glTexCoord2s.all_ok_exclusive());
		gl.tex_coord_s(s, t);
		BOOST_CHECK( fake_glTexCoord2s.all_ok_exclusive());
	}
	{
		GLshort s = get<GLshort>();
		GLshort t = get<GLshort>();
		GLshort r = get<GLshort>();

		fake_glTexCoord3s.reset_params(s, t, r);
		BOOST_CHECK(!fake_glTexCoord3s.all_ok_exclusive());
		gl.tex_coord_s(s, t, r);
		BOOST_CHECK( fake_glTexCoord3s.all_ok_exclusive());
	}
	{
		GLshort s = get<GLshort>();
		GLshort t = get<GLshort>();
		GLshort r = get<GLshort>();
		GLshort q = get<GLshort>();

		fake_glTexCoord4s.reset_params(s, t, r, q);
		BOOST_CHECK(!fake_glTexCoord4s.all_ok_exclusive());
		gl.tex_coord_s(s, t, r, q);
		BOOST_CHECK( fake_glTexCoord4s.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glTexCoord1s.was_called());
	BOOST_CHECK(fake_glTexCoord2s.was_called());
	BOOST_CHECK(fake_glTexCoord3s.was_called());
	BOOST_CHECK(fake_glTexCoord4s.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_sv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLshort v[1] = {get<GLshort>()};

		fake_glTexCoord1sv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord1sv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord1sv.all_ok_exclusive());
	}
	{
		const GLshort v[2] = {get<GLshort>(), get<GLshort>()};

		fake_glTexCoord2sv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord2sv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord2sv.all_ok_exclusive());
	}
	{
		const GLshort v[3] = {get<GLshort>(), get<GLshort>(), get<GLshort>()};

		fake_glTexCoord3sv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord3sv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord3sv.all_ok_exclusive());
	}
	{
		const GLshort v[4] = {get<GLshort>(), get<GLshort>(), get<GLshort>(), get<GLshort>()};

		fake_glTexCoord4sv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord4sv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord4sv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glTexCoord1sv.was_called());
	BOOST_CHECK(fake_glTexCoord2sv.was_called());
	BOOST_CHECK(fake_glTexCoord3sv.was_called());
	BOOST_CHECK(fake_glTexCoord4sv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_i)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLint s = get<GLint>();

		fake_glTexCoord1i.reset_params(s);
		BOOST_CHECK(!fake_glTexCoord1i.all_ok_exclusive());
		gl.tex_coord_i(s);
		BOOST_CHECK( fake_glTexCoord1i.all_ok_exclusive());
	}
	{
		GLint s = get<GLint>();
		GLint t = get<GLint>();

		fake_glTexCoord2i.reset_params(s, t);
		BOOST_CHECK(!fake_glTexCoord2i.all_ok_exclusive());
		gl.tex_coord_i(s, t);
		BOOST_CHECK( fake_glTexCoord2i.all_ok_exclusive());
	}
	{
		GLint s = get<GLint>();
		GLint t = get<GLint>();
		GLint r = get<GLint>();

		fake_glTexCoord3i.reset_params(s, t, r);
		BOOST_CHECK(!fake_glTexCoord3i.all_ok_exclusive());
		gl.tex_coord_i(s, t, r);
		BOOST_CHECK( fake_glTexCoord3i.all_ok_exclusive());
	}
	{
		GLint s = get<GLint>();
		GLint t = get<GLint>();
		GLint r = get<GLint>();
		GLint q = get<GLint>();

		fake_glTexCoord4i.reset_params(s, t, r, q);
		BOOST_CHECK(!fake_glTexCoord4i.all_ok_exclusive());
		gl.tex_coord_i(s, t, r, q);
		BOOST_CHECK( fake_glTexCoord4i.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glTexCoord1i.was_called());
	BOOST_CHECK(fake_glTexCoord2i.was_called());
	BOOST_CHECK(fake_glTexCoord3i.was_called());
	BOOST_CHECK(fake_glTexCoord4i.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_iv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLint v[1] = {get<GLint>()};

		fake_glTexCoord1iv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord1iv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord1iv.all_ok_exclusive());
	}
	{
		const GLint v[2] = {get<GLint>(), get<GLint>()};

		fake_glTexCoord2iv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord2iv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord2iv.all_ok_exclusive());
	}
	{
		const GLint v[3] = {get<GLint>(), get<GLint>(), get<GLint>()};

		fake_glTexCoord3iv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord3iv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord3iv.all_ok_exclusive());
	}
	{
		const GLint v[4] = {get<GLint>(), get<GLint>(), get<GLint>(), get<GLint>()};

		fake_glTexCoord4iv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord4iv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord4iv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glTexCoord1iv.was_called());
	BOOST_CHECK(fake_glTexCoord2iv.was_called());
	BOOST_CHECK(fake_glTexCoord3iv.was_called());
	BOOST_CHECK(fake_glTexCoord4iv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_f)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLfloat s = get<GLfloat>();

		fake_glTexCoord1f.reset_params(s);
		BOOST_CHECK(!fake_glTexCoord1f.all_ok_exclusive());
		gl.tex_coord_f(s);
		BOOST_CHECK( fake_glTexCoord1f.all_ok_exclusive());
	}
	{
		GLfloat s = get<GLfloat>();
		GLfloat t = get<GLfloat>();

		fake_glTexCoord2f.reset_params(s, t);
		BOOST_CHECK(!fake_glTexCoord2f.all_ok_exclusive());
		gl.tex_coord_f(s, t);
		BOOST_CHECK( fake_glTexCoord2f.all_ok_exclusive());
	}
	{
		GLfloat s = get<GLfloat>();
		GLfloat t = get<GLfloat>();
		GLfloat r = get<GLfloat>();

		fake_glTexCoord3f.reset_params(s, t, r);
		BOOST_CHECK(!fake_glTexCoord3f.all_ok_exclusive());
		gl.tex_coord_f(s, t, r);
		BOOST_CHECK( fake_glTexCoord3f.all_ok_exclusive());
	}
	{
		GLfloat s = get<GLfloat>();
		GLfloat t = get<GLfloat>();
		GLfloat r = get<GLfloat>();
		GLfloat q = get<GLfloat>();

		fake_glTexCoord4f.reset_params(s, t, r, q);
		BOOST_CHECK(!fake_glTexCoord4f.all_ok_exclusive());
		gl.tex_coord_f(s, t, r, q);
		BOOST_CHECK( fake_glTexCoord4f.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glTexCoord1f.was_called());
	BOOST_CHECK(fake_glTexCoord2f.was_called());
	BOOST_CHECK(fake_glTexCoord3f.was_called());
	BOOST_CHECK(fake_glTexCoord4f.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_fv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLfloat v[1] = {get<GLfloat>()};

		fake_glTexCoord1fv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord1fv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord1fv.all_ok_exclusive());
	}
	{
		const GLfloat v[2] = {get<GLfloat>(), get<GLfloat>()};

		fake_glTexCoord2fv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord2fv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord2fv.all_ok_exclusive());
	}
	{
		const GLfloat v[3] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		fake_glTexCoord3fv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord3fv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord3fv.all_ok_exclusive());
	}
	{
		const GLfloat v[4] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		fake_glTexCoord4fv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord4fv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord4fv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glTexCoord1fv.was_called());
	BOOST_CHECK(fake_glTexCoord2fv.was_called());
	BOOST_CHECK(fake_glTexCoord3fv.was_called());
	BOOST_CHECK(fake_glTexCoord4fv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_d)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		GLdouble s = get<GLdouble>();

		fake_glTexCoord1d.reset_params(s);
		BOOST_CHECK(!fake_glTexCoord1d.all_ok_exclusive());
		gl.tex_coord_d(s);
		BOOST_CHECK( fake_glTexCoord1d.all_ok_exclusive());
	}
	{
		GLdouble s = get<GLdouble>();
		GLdouble t = get<GLdouble>();

		fake_glTexCoord2d.reset_params(s, t);
		BOOST_CHECK(!fake_glTexCoord2d.all_ok_exclusive());
		gl.tex_coord_d(s, t);
		BOOST_CHECK( fake_glTexCoord2d.all_ok_exclusive());
	}
	{
		GLdouble s = get<GLdouble>();
		GLdouble t = get<GLdouble>();
		GLdouble r = get<GLdouble>();

		fake_glTexCoord3d.reset_params(s, t, r);
		BOOST_CHECK(!fake_glTexCoord3d.all_ok_exclusive());
		gl.tex_coord_d(s, t, r);
		BOOST_CHECK( fake_glTexCoord3d.all_ok_exclusive());
	}
	{
		GLdouble s = get<GLdouble>();
		GLdouble t = get<GLdouble>();
		GLdouble r = get<GLdouble>();
		GLdouble q = get<GLdouble>();

		fake_glTexCoord4d.reset_params(s, t, r, q);
		BOOST_CHECK(!fake_glTexCoord4d.all_ok_exclusive());
		gl.tex_coord_d(s, t, r, q);
		BOOST_CHECK( fake_glTexCoord4d.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glTexCoord1d.was_called());
	BOOST_CHECK(fake_glTexCoord2d.was_called());
	BOOST_CHECK(fake_glTexCoord3d.was_called());
	BOOST_CHECK(fake_glTexCoord4d.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_dv)
{
	using namespace oglplus;

	ctxt::compatibility_drawing gl;

	{
		const GLdouble v[1] = {get<GLdouble>()};

		fake_glTexCoord1dv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord1dv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord1dv.all_ok_exclusive());
	}
	{
		const GLdouble v[2] = {get<GLdouble>(), get<GLdouble>()};

		fake_glTexCoord2dv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord2dv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord2dv.all_ok_exclusive());
	}
	{
		const GLdouble v[3] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		fake_glTexCoord3dv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord3dv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord3dv.all_ok_exclusive());
	}
	{
		const GLdouble v[4] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		fake_glTexCoord4dv.reset_params(v);
		BOOST_CHECK(!fake_glTexCoord4dv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( fake_glTexCoord4dv.all_ok_exclusive());
	}

	BOOST_CHECK(fake_glTexCoord1dv.was_called());
	BOOST_CHECK(fake_glTexCoord2dv.was_called());
	BOOST_CHECK(fake_glTexCoord3dv.was_called());
	BOOST_CHECK(fake_glTexCoord4dv.was_called());
}

BOOST_AUTO_TEST_SUITE_END()
