/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_oper_compat_drawing
#include <boost/test/unit_test.hpp>

#include <oglplus/gl.hpp>
#include "helper/mock_gl_func.hpp"

OGLPLUS_MOCK_GLFUNC(Begin, void(GLenum));
OGLPLUS_MOCK_GLFUNC(End, void(void));


OGLPLUS_MOCK_GLFUNC(Vertex2s, void(GLshort, GLshort));
OGLPLUS_MOCK_GLFUNC(Vertex3s, void(GLshort, GLshort, GLshort));
OGLPLUS_MOCK_GLFUNC(Vertex4s, void(GLshort, GLshort, GLshort, GLshort));

OGLPLUS_MOCK_GLFUNC(Vertex2sv, void(const GLshort*));
OGLPLUS_MOCK_GLFUNC(Vertex3sv, void(const GLshort*));
OGLPLUS_MOCK_GLFUNC(Vertex4sv, void(const GLshort*));

OGLPLUS_MOCK_GLFUNC(Vertex2i, void(GLint, GLint));
OGLPLUS_MOCK_GLFUNC(Vertex3i, void(GLint, GLint, GLint));
OGLPLUS_MOCK_GLFUNC(Vertex4i, void(GLint, GLint, GLint, GLint));

OGLPLUS_MOCK_GLFUNC(Vertex2iv, void(const GLint*));
OGLPLUS_MOCK_GLFUNC(Vertex3iv, void(const GLint*));
OGLPLUS_MOCK_GLFUNC(Vertex4iv, void(const GLint*));

OGLPLUS_MOCK_GLFUNC(Vertex2f, void(GLfloat, GLfloat));
OGLPLUS_MOCK_GLFUNC(Vertex3f, void(GLfloat, GLfloat, GLfloat));
OGLPLUS_MOCK_GLFUNC(Vertex4f, void(GLfloat, GLfloat, GLfloat, GLfloat));

OGLPLUS_MOCK_GLFUNC(Vertex2fv, void(const GLfloat*));
OGLPLUS_MOCK_GLFUNC(Vertex3fv, void(const GLfloat*));
OGLPLUS_MOCK_GLFUNC(Vertex4fv, void(const GLfloat*));

OGLPLUS_MOCK_GLFUNC(Vertex2d, void(GLdouble, GLdouble));
OGLPLUS_MOCK_GLFUNC(Vertex3d, void(GLdouble, GLdouble, GLdouble));
OGLPLUS_MOCK_GLFUNC(Vertex4d, void(GLdouble, GLdouble, GLdouble, GLdouble));

OGLPLUS_MOCK_GLFUNC(Vertex2dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(Vertex3dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(Vertex4dv, void(const GLdouble*));


OGLPLUS_MOCK_GLFUNC(Color3ub, void(GLubyte, GLubyte, GLubyte));
OGLPLUS_MOCK_GLFUNC(Color4ub, void(GLubyte, GLubyte, GLubyte, GLubyte));

OGLPLUS_MOCK_GLFUNC(Color3ubv, void(const GLubyte*));
OGLPLUS_MOCK_GLFUNC(Color4ubv, void(const GLubyte*));

OGLPLUS_MOCK_GLFUNC(Color3i, void(GLint, GLint, GLint));
OGLPLUS_MOCK_GLFUNC(Color4i, void(GLint, GLint, GLint, GLint));

OGLPLUS_MOCK_GLFUNC(Color3iv, void(const GLint*));
OGLPLUS_MOCK_GLFUNC(Color4iv, void(const GLint*));

OGLPLUS_MOCK_GLFUNC(Color3f, void(GLfloat, GLfloat, GLfloat));
OGLPLUS_MOCK_GLFUNC(Color4f, void(GLfloat, GLfloat, GLfloat, GLfloat));

OGLPLUS_MOCK_GLFUNC(Color3fv, void(const GLfloat*));
OGLPLUS_MOCK_GLFUNC(Color4fv, void(const GLfloat*));

OGLPLUS_MOCK_GLFUNC(Color3d, void(GLdouble, GLdouble, GLdouble));
OGLPLUS_MOCK_GLFUNC(Color4d, void(GLdouble, GLdouble, GLdouble, GLdouble));

OGLPLUS_MOCK_GLFUNC(Color3dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(Color4dv, void(const GLdouble*));


OGLPLUS_MOCK_GLFUNC(TexCoord1s, void(GLshort));
OGLPLUS_MOCK_GLFUNC(TexCoord2s, void(GLshort, GLshort));
OGLPLUS_MOCK_GLFUNC(TexCoord3s, void(GLshort, GLshort, GLshort));
OGLPLUS_MOCK_GLFUNC(TexCoord4s, void(GLshort, GLshort, GLshort, GLshort));

OGLPLUS_MOCK_GLFUNC(TexCoord1sv, void(const GLshort*));
OGLPLUS_MOCK_GLFUNC(TexCoord2sv, void(const GLshort*));
OGLPLUS_MOCK_GLFUNC(TexCoord3sv, void(const GLshort*));
OGLPLUS_MOCK_GLFUNC(TexCoord4sv, void(const GLshort*));

OGLPLUS_MOCK_GLFUNC(TexCoord1i, void(GLint));
OGLPLUS_MOCK_GLFUNC(TexCoord2i, void(GLint, GLint));
OGLPLUS_MOCK_GLFUNC(TexCoord3i, void(GLint, GLint, GLint));
OGLPLUS_MOCK_GLFUNC(TexCoord4i, void(GLint, GLint, GLint, GLint));

OGLPLUS_MOCK_GLFUNC(TexCoord1iv, void(const GLint*));
OGLPLUS_MOCK_GLFUNC(TexCoord2iv, void(const GLint*));
OGLPLUS_MOCK_GLFUNC(TexCoord3iv, void(const GLint*));
OGLPLUS_MOCK_GLFUNC(TexCoord4iv, void(const GLint*));

OGLPLUS_MOCK_GLFUNC(TexCoord1f, void(GLfloat));
OGLPLUS_MOCK_GLFUNC(TexCoord2f, void(GLfloat, GLfloat));
OGLPLUS_MOCK_GLFUNC(TexCoord3f, void(GLfloat, GLfloat, GLfloat));
OGLPLUS_MOCK_GLFUNC(TexCoord4f, void(GLfloat, GLfloat, GLfloat, GLfloat));

OGLPLUS_MOCK_GLFUNC(TexCoord1fv, void(const GLfloat*));
OGLPLUS_MOCK_GLFUNC(TexCoord2fv, void(const GLfloat*));
OGLPLUS_MOCK_GLFUNC(TexCoord3fv, void(const GLfloat*));
OGLPLUS_MOCK_GLFUNC(TexCoord4fv, void(const GLfloat*));

OGLPLUS_MOCK_GLFUNC(TexCoord1d, void(GLdouble));
OGLPLUS_MOCK_GLFUNC(TexCoord2d, void(GLdouble, GLdouble));
OGLPLUS_MOCK_GLFUNC(TexCoord3d, void(GLdouble, GLdouble, GLdouble));
OGLPLUS_MOCK_GLFUNC(TexCoord4d, void(GLdouble, GLdouble, GLdouble, GLdouble));

OGLPLUS_MOCK_GLFUNC(TexCoord1dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(TexCoord2dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(TexCoord3dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(TexCoord4dv, void(const GLdouble*));


#include <oglplus/oper/compat_drawing.hpp>
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

	oper::compatibility_drawing gl;

	{
		GLshort x = get<GLshort>();
		GLshort y = get<GLshort>();

		mock_glVertex2s.reset_params(x, y);
		BOOST_CHECK(!mock_glVertex2s.all_ok_exclusive());
		gl.vertex_s(x, y);
		BOOST_CHECK( mock_glVertex2s.all_ok_exclusive());
	}
	{
		GLshort x = get<GLshort>();
		GLshort y = get<GLshort>();
		GLshort z = get<GLshort>();

		mock_glVertex3s.reset_params(x, y, z);
		BOOST_CHECK(!mock_glVertex3s.all_ok_exclusive());
		gl.vertex_s(x, y, z);
		BOOST_CHECK( mock_glVertex3s.all_ok_exclusive());
	}
	{
		GLshort x = get<GLshort>();
		GLshort y = get<GLshort>();
		GLshort z = get<GLshort>();
		GLshort w = get<GLshort>();

		mock_glVertex4s.reset_params(x, y, z, w);
		BOOST_CHECK(!mock_glVertex4s.all_ok_exclusive());
		gl.vertex_s(x, y, z, w);
		BOOST_CHECK( mock_glVertex4s.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glVertex2s.was_called());
	BOOST_CHECK(mock_glVertex3s.was_called());
	BOOST_CHECK(mock_glVertex4s.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_sv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLshort v[2] = {get<GLshort>(), get<GLshort>()};

		mock_glVertex2sv.reset_params(v);
		BOOST_CHECK(!mock_glVertex2sv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex2sv.all_ok_exclusive());
	}
	{
		const GLshort v[3] = {get<GLshort>(), get<GLshort>(), get<GLshort>()};

		mock_glVertex3sv.reset_params(v);
		BOOST_CHECK(!mock_glVertex3sv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex3sv.all_ok_exclusive());
	}
	{
		const GLshort v[4] = {get<GLshort>(), get<GLshort>(), get<GLshort>(), get<GLshort>()};

		mock_glVertex4sv.reset_params(v);
		BOOST_CHECK(!mock_glVertex4sv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex4sv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glVertex2sv.was_called());
	BOOST_CHECK(mock_glVertex3sv.was_called());
	BOOST_CHECK(mock_glVertex4sv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_i)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();

		mock_glVertex2i.reset_params(x, y);
		BOOST_CHECK(!mock_glVertex2i.all_ok_exclusive());
		gl.vertex_i(x, y);
		BOOST_CHECK( mock_glVertex2i.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();

		mock_glVertex3i.reset_params(x, y, z);
		BOOST_CHECK(!mock_glVertex3i.all_ok_exclusive());
		gl.vertex_i(x, y, z);
		BOOST_CHECK( mock_glVertex3i.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();
		GLint w = get<GLint>();

		mock_glVertex4i.reset_params(x, y, z, w);
		BOOST_CHECK(!mock_glVertex4i.all_ok_exclusive());
		gl.vertex_i(x, y, z, w);
		BOOST_CHECK( mock_glVertex4i.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glVertex2i.was_called());
	BOOST_CHECK(mock_glVertex3i.was_called());
	BOOST_CHECK(mock_glVertex4i.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_iv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLint v[2] = {get<GLint>(), get<GLint>()};

		mock_glVertex2iv.reset_params(v);
		BOOST_CHECK(!mock_glVertex2iv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex2iv.all_ok_exclusive());
	}
	{
		const GLint v[3] = {get<GLint>(), get<GLint>(), get<GLint>()};

		mock_glVertex3iv.reset_params(v);
		BOOST_CHECK(!mock_glVertex3iv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex3iv.all_ok_exclusive());
	}
	{
		const GLint v[4] = {get<GLint>(), get<GLint>(), get<GLint>(), get<GLint>()};

		mock_glVertex4iv.reset_params(v);
		BOOST_CHECK(!mock_glVertex4iv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex4iv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glVertex2iv.was_called());
	BOOST_CHECK(mock_glVertex3iv.was_called());
	BOOST_CHECK(mock_glVertex4iv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_f)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();

		mock_glVertex2f.reset_params(x, y);
		BOOST_CHECK(!mock_glVertex2f.all_ok_exclusive());
		gl.vertex_f(x, y);
		BOOST_CHECK( mock_glVertex2f.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();

		mock_glVertex3f.reset_params(x, y, z);
		BOOST_CHECK(!mock_glVertex3f.all_ok_exclusive());
		gl.vertex_f(x, y, z);
		BOOST_CHECK( mock_glVertex3f.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();
		GLint w = get<GLint>();

		mock_glVertex4f.reset_params(x, y, z, w);
		BOOST_CHECK(!mock_glVertex4f.all_ok_exclusive());
		gl.vertex_f(x, y, z, w);
		BOOST_CHECK( mock_glVertex4f.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glVertex2f.was_called());
	BOOST_CHECK(mock_glVertex3f.was_called());
	BOOST_CHECK(mock_glVertex4f.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_fv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLfloat v[2] = {get<GLfloat>(), get<GLfloat>()};

		mock_glVertex2fv.reset_params(v);
		BOOST_CHECK(!mock_glVertex2fv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex2fv.all_ok_exclusive());
	}
	{
		const GLfloat v[3] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		mock_glVertex3fv.reset_params(v);
		BOOST_CHECK(!mock_glVertex3fv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex3fv.all_ok_exclusive());
	}
	{
		const GLfloat v[4] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		mock_glVertex4fv.reset_params(v);
		BOOST_CHECK(!mock_glVertex4fv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex4fv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glVertex2fv.was_called());
	BOOST_CHECK(mock_glVertex3fv.was_called());
	BOOST_CHECK(mock_glVertex4fv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_d)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();

		mock_glVertex2d.reset_params(x, y);
		BOOST_CHECK(!mock_glVertex2d.all_ok_exclusive());
		gl.vertex_d(x, y);
		BOOST_CHECK( mock_glVertex2d.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();

		mock_glVertex3d.reset_params(x, y, z);
		BOOST_CHECK(!mock_glVertex3d.all_ok_exclusive());
		gl.vertex_d(x, y, z);
		BOOST_CHECK( mock_glVertex3d.all_ok_exclusive());
	}
	{
		GLint x = get<GLint>();
		GLint y = get<GLint>();
		GLint z = get<GLint>();
		GLint w = get<GLint>();

		mock_glVertex4d.reset_params(x, y, z, w);
		BOOST_CHECK(!mock_glVertex4d.all_ok_exclusive());
		gl.vertex_d(x, y, z, w);
		BOOST_CHECK( mock_glVertex4d.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glVertex2d.was_called());
	BOOST_CHECK(mock_glVertex3d.was_called());
	BOOST_CHECK(mock_glVertex4d.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_dv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLdouble v[2] = {get<GLdouble>(), get<GLdouble>()};

		mock_glVertex2dv.reset_params(v);
		BOOST_CHECK(!mock_glVertex2dv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex2dv.all_ok_exclusive());
	}
	{
		const GLdouble v[3] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		mock_glVertex3dv.reset_params(v);
		BOOST_CHECK(!mock_glVertex3dv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex3dv.all_ok_exclusive());
	}
	{
		const GLdouble v[4] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		mock_glVertex4dv.reset_params(v);
		BOOST_CHECK(!mock_glVertex4dv.all_ok_exclusive());
		gl.vertex(v);
		BOOST_CHECK( mock_glVertex4dv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glVertex2dv.was_called());
	BOOST_CHECK(mock_glVertex3dv.was_called());
	BOOST_CHECK(mock_glVertex4dv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_ub)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		GLubyte r = get<GLubyte>();
		GLubyte g = get<GLubyte>();
		GLubyte b = get<GLubyte>();

		mock_glColor3ub.reset_params(r, g, b);
		BOOST_CHECK(!mock_glColor3ub.all_ok_exclusive());
		gl.color_ub(r, g, b);
		BOOST_CHECK( mock_glColor3ub.all_ok_exclusive());
	}
	{
		GLubyte r = get<GLubyte>();
		GLubyte g = get<GLubyte>();
		GLubyte b = get<GLubyte>();
		GLubyte a = get<GLubyte>();

		mock_glColor4ub.reset_params(r, g, b, a);
		BOOST_CHECK(!mock_glColor4ub.all_ok_exclusive());
		gl.color_ub(r, g, b, a);
		BOOST_CHECK( mock_glColor4ub.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glColor3ub.was_called());
	BOOST_CHECK(mock_glColor4ub.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_ubv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLubyte v[3] = {get<GLubyte>(), get<GLubyte>(), get<GLubyte>()};

		mock_glColor3ubv.reset_params(v);
		BOOST_CHECK(!mock_glColor3ubv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( mock_glColor3ubv.all_ok_exclusive());
	}
	{
		const GLubyte v[4] = {get<GLubyte>(), get<GLubyte>(), get<GLubyte>(), get<GLubyte>()};

		mock_glColor4ubv.reset_params(v);
		BOOST_CHECK(!mock_glColor4ubv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( mock_glColor4ubv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glColor3ubv.was_called());
	BOOST_CHECK(mock_glColor4ubv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_i)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		GLint r = get<GLint>();
		GLint g = get<GLint>();
		GLint b = get<GLint>();

		mock_glColor3i.reset_params(r, g, b);
		BOOST_CHECK(!mock_glColor3i.all_ok_exclusive());
		gl.color_i(r, g, b);
		BOOST_CHECK( mock_glColor3i.all_ok_exclusive());
	}
	{
		GLint r = get<GLint>();
		GLint g = get<GLint>();
		GLint b = get<GLint>();
		GLint a = get<GLint>();

		mock_glColor4i.reset_params(r, g, b, a);
		BOOST_CHECK(!mock_glColor4i.all_ok_exclusive());
		gl.color_i(r, g, b, a);
		BOOST_CHECK( mock_glColor4i.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glColor3i.was_called());
	BOOST_CHECK(mock_glColor4i.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_iv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLint v[3] = {get<GLint>(), get<GLint>(), get<GLint>()};

		mock_glColor3iv.reset_params(v);
		BOOST_CHECK(!mock_glColor3iv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( mock_glColor3iv.all_ok_exclusive());
	}
	{
		const GLint v[4] = {get<GLint>(), get<GLint>(), get<GLint>(), get<GLint>()};

		mock_glColor4iv.reset_params(v);
		BOOST_CHECK(!mock_glColor4iv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( mock_glColor4iv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glColor3iv.was_called());
	BOOST_CHECK(mock_glColor4iv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_f)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		GLfloat r = get<GLfloat>();
		GLfloat g = get<GLfloat>();
		GLfloat b = get<GLfloat>();

		mock_glColor3f.reset_params(r, g, b);
		BOOST_CHECK(!mock_glColor3f.all_ok_exclusive());
		gl.color_f(r, g, b);
		BOOST_CHECK( mock_glColor3f.all_ok_exclusive());
	}
	{
		GLfloat r = get<GLfloat>();
		GLfloat g = get<GLfloat>();
		GLfloat b = get<GLfloat>();
		GLfloat a = get<GLfloat>();

		mock_glColor4f.reset_params(r, g, b, a);
		BOOST_CHECK(!mock_glColor4f.all_ok_exclusive());
		gl.color_f(r, g, b, a);
		BOOST_CHECK( mock_glColor4f.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glColor3f.was_called());
	BOOST_CHECK(mock_glColor4f.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_fv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLfloat v[3] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		mock_glColor3fv.reset_params(v);
		BOOST_CHECK(!mock_glColor3fv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( mock_glColor3fv.all_ok_exclusive());
	}
	{
		const GLfloat v[4] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		mock_glColor4fv.reset_params(v);
		BOOST_CHECK(!mock_glColor4fv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( mock_glColor4fv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glColor3fv.was_called());
	BOOST_CHECK(mock_glColor4fv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_d)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		GLdouble r = get<GLdouble>();
		GLdouble g = get<GLdouble>();
		GLdouble b = get<GLdouble>();

		mock_glColor3d.reset_params(r, g, b);
		BOOST_CHECK(!mock_glColor3d.all_ok_exclusive());
		gl.color_d(r, g, b);
		BOOST_CHECK( mock_glColor3d.all_ok_exclusive());
	}
	{
		GLdouble r = get<GLdouble>();
		GLdouble g = get<GLdouble>();
		GLdouble b = get<GLdouble>();
		GLdouble a = get<GLdouble>();

		mock_glColor4d.reset_params(r, g, b, a);
		BOOST_CHECK(!mock_glColor4d.all_ok_exclusive());
		gl.color_d(r, g, b, a);
		BOOST_CHECK( mock_glColor4d.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glColor3d.was_called());
	BOOST_CHECK(mock_glColor4d.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_dv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLdouble v[3] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		mock_glColor3dv.reset_params(v);
		BOOST_CHECK(!mock_glColor3dv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( mock_glColor3dv.all_ok_exclusive());
	}
	{
		const GLdouble v[4] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		mock_glColor4dv.reset_params(v);
		BOOST_CHECK(!mock_glColor4dv.all_ok_exclusive());
		gl.color(v);
		BOOST_CHECK( mock_glColor4dv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glColor3dv.was_called());
	BOOST_CHECK(mock_glColor4dv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_s)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		GLshort s = get<GLshort>();

		mock_glTexCoord1s.reset_params(s);
		BOOST_CHECK(!mock_glTexCoord1s.all_ok_exclusive());
		gl.tex_coord_s(s);
		BOOST_CHECK( mock_glTexCoord1s.all_ok_exclusive());
	}
	{
		GLshort s = get<GLshort>();
		GLshort t = get<GLshort>();

		mock_glTexCoord2s.reset_params(s, t);
		BOOST_CHECK(!mock_glTexCoord2s.all_ok_exclusive());
		gl.tex_coord_s(s, t);
		BOOST_CHECK( mock_glTexCoord2s.all_ok_exclusive());
	}
	{
		GLshort s = get<GLshort>();
		GLshort t = get<GLshort>();
		GLshort r = get<GLshort>();

		mock_glTexCoord3s.reset_params(s, t, r);
		BOOST_CHECK(!mock_glTexCoord3s.all_ok_exclusive());
		gl.tex_coord_s(s, t, r);
		BOOST_CHECK( mock_glTexCoord3s.all_ok_exclusive());
	}
	{
		GLshort s = get<GLshort>();
		GLshort t = get<GLshort>();
		GLshort r = get<GLshort>();
		GLshort q = get<GLshort>();

		mock_glTexCoord4s.reset_params(s, t, r, q);
		BOOST_CHECK(!mock_glTexCoord4s.all_ok_exclusive());
		gl.tex_coord_s(s, t, r, q);
		BOOST_CHECK( mock_glTexCoord4s.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glTexCoord1s.was_called());
	BOOST_CHECK(mock_glTexCoord2s.was_called());
	BOOST_CHECK(mock_glTexCoord3s.was_called());
	BOOST_CHECK(mock_glTexCoord4s.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_sv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLshort v[1] = {get<GLshort>()};

		mock_glTexCoord1sv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord1sv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord1sv.all_ok_exclusive());
	}
	{
		const GLshort v[2] = {get<GLshort>(), get<GLshort>()};

		mock_glTexCoord2sv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord2sv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord2sv.all_ok_exclusive());
	}
	{
		const GLshort v[3] = {get<GLshort>(), get<GLshort>(), get<GLshort>()};

		mock_glTexCoord3sv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord3sv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord3sv.all_ok_exclusive());
	}
	{
		const GLshort v[4] = {get<GLshort>(), get<GLshort>(), get<GLshort>(), get<GLshort>()};

		mock_glTexCoord4sv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord4sv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord4sv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glTexCoord1sv.was_called());
	BOOST_CHECK(mock_glTexCoord2sv.was_called());
	BOOST_CHECK(mock_glTexCoord3sv.was_called());
	BOOST_CHECK(mock_glTexCoord4sv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_i)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		GLint s = get<GLint>();

		mock_glTexCoord1i.reset_params(s);
		BOOST_CHECK(!mock_glTexCoord1i.all_ok_exclusive());
		gl.tex_coord_i(s);
		BOOST_CHECK( mock_glTexCoord1i.all_ok_exclusive());
	}
	{
		GLint s = get<GLint>();
		GLint t = get<GLint>();

		mock_glTexCoord2i.reset_params(s, t);
		BOOST_CHECK(!mock_glTexCoord2i.all_ok_exclusive());
		gl.tex_coord_i(s, t);
		BOOST_CHECK( mock_glTexCoord2i.all_ok_exclusive());
	}
	{
		GLint s = get<GLint>();
		GLint t = get<GLint>();
		GLint r = get<GLint>();

		mock_glTexCoord3i.reset_params(s, t, r);
		BOOST_CHECK(!mock_glTexCoord3i.all_ok_exclusive());
		gl.tex_coord_i(s, t, r);
		BOOST_CHECK( mock_glTexCoord3i.all_ok_exclusive());
	}
	{
		GLint s = get<GLint>();
		GLint t = get<GLint>();
		GLint r = get<GLint>();
		GLint q = get<GLint>();

		mock_glTexCoord4i.reset_params(s, t, r, q);
		BOOST_CHECK(!mock_glTexCoord4i.all_ok_exclusive());
		gl.tex_coord_i(s, t, r, q);
		BOOST_CHECK( mock_glTexCoord4i.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glTexCoord1i.was_called());
	BOOST_CHECK(mock_glTexCoord2i.was_called());
	BOOST_CHECK(mock_glTexCoord3i.was_called());
	BOOST_CHECK(mock_glTexCoord4i.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_iv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLint v[1] = {get<GLint>()};

		mock_glTexCoord1iv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord1iv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord1iv.all_ok_exclusive());
	}
	{
		const GLint v[2] = {get<GLint>(), get<GLint>()};

		mock_glTexCoord2iv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord2iv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord2iv.all_ok_exclusive());
	}
	{
		const GLint v[3] = {get<GLint>(), get<GLint>(), get<GLint>()};

		mock_glTexCoord3iv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord3iv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord3iv.all_ok_exclusive());
	}
	{
		const GLint v[4] = {get<GLint>(), get<GLint>(), get<GLint>(), get<GLint>()};

		mock_glTexCoord4iv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord4iv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord4iv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glTexCoord1iv.was_called());
	BOOST_CHECK(mock_glTexCoord2iv.was_called());
	BOOST_CHECK(mock_glTexCoord3iv.was_called());
	BOOST_CHECK(mock_glTexCoord4iv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_f)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		GLfloat s = get<GLfloat>();

		mock_glTexCoord1f.reset_params(s);
		BOOST_CHECK(!mock_glTexCoord1f.all_ok_exclusive());
		gl.tex_coord_f(s);
		BOOST_CHECK( mock_glTexCoord1f.all_ok_exclusive());
	}
	{
		GLfloat s = get<GLfloat>();
		GLfloat t = get<GLfloat>();

		mock_glTexCoord2f.reset_params(s, t);
		BOOST_CHECK(!mock_glTexCoord2f.all_ok_exclusive());
		gl.tex_coord_f(s, t);
		BOOST_CHECK( mock_glTexCoord2f.all_ok_exclusive());
	}
	{
		GLfloat s = get<GLfloat>();
		GLfloat t = get<GLfloat>();
		GLfloat r = get<GLfloat>();

		mock_glTexCoord3f.reset_params(s, t, r);
		BOOST_CHECK(!mock_glTexCoord3f.all_ok_exclusive());
		gl.tex_coord_f(s, t, r);
		BOOST_CHECK( mock_glTexCoord3f.all_ok_exclusive());
	}
	{
		GLfloat s = get<GLfloat>();
		GLfloat t = get<GLfloat>();
		GLfloat r = get<GLfloat>();
		GLfloat q = get<GLfloat>();

		mock_glTexCoord4f.reset_params(s, t, r, q);
		BOOST_CHECK(!mock_glTexCoord4f.all_ok_exclusive());
		gl.tex_coord_f(s, t, r, q);
		BOOST_CHECK( mock_glTexCoord4f.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glTexCoord1f.was_called());
	BOOST_CHECK(mock_glTexCoord2f.was_called());
	BOOST_CHECK(mock_glTexCoord3f.was_called());
	BOOST_CHECK(mock_glTexCoord4f.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_fv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLfloat v[1] = {get<GLfloat>()};

		mock_glTexCoord1fv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord1fv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord1fv.all_ok_exclusive());
	}
	{
		const GLfloat v[2] = {get<GLfloat>(), get<GLfloat>()};

		mock_glTexCoord2fv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord2fv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord2fv.all_ok_exclusive());
	}
	{
		const GLfloat v[3] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		mock_glTexCoord3fv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord3fv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord3fv.all_ok_exclusive());
	}
	{
		const GLfloat v[4] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

		mock_glTexCoord4fv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord4fv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord4fv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glTexCoord1fv.was_called());
	BOOST_CHECK(mock_glTexCoord2fv.was_called());
	BOOST_CHECK(mock_glTexCoord3fv.was_called());
	BOOST_CHECK(mock_glTexCoord4fv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_d)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		GLdouble s = get<GLdouble>();

		mock_glTexCoord1d.reset_params(s);
		BOOST_CHECK(!mock_glTexCoord1d.all_ok_exclusive());
		gl.tex_coord_d(s);
		BOOST_CHECK( mock_glTexCoord1d.all_ok_exclusive());
	}
	{
		GLdouble s = get<GLdouble>();
		GLdouble t = get<GLdouble>();

		mock_glTexCoord2d.reset_params(s, t);
		BOOST_CHECK(!mock_glTexCoord2d.all_ok_exclusive());
		gl.tex_coord_d(s, t);
		BOOST_CHECK( mock_glTexCoord2d.all_ok_exclusive());
	}
	{
		GLdouble s = get<GLdouble>();
		GLdouble t = get<GLdouble>();
		GLdouble r = get<GLdouble>();

		mock_glTexCoord3d.reset_params(s, t, r);
		BOOST_CHECK(!mock_glTexCoord3d.all_ok_exclusive());
		gl.tex_coord_d(s, t, r);
		BOOST_CHECK( mock_glTexCoord3d.all_ok_exclusive());
	}
	{
		GLdouble s = get<GLdouble>();
		GLdouble t = get<GLdouble>();
		GLdouble r = get<GLdouble>();
		GLdouble q = get<GLdouble>();

		mock_glTexCoord4d.reset_params(s, t, r, q);
		BOOST_CHECK(!mock_glTexCoord4d.all_ok_exclusive());
		gl.tex_coord_d(s, t, r, q);
		BOOST_CHECK( mock_glTexCoord4d.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glTexCoord1d.was_called());
	BOOST_CHECK(mock_glTexCoord2d.was_called());
	BOOST_CHECK(mock_glTexCoord3d.was_called());
	BOOST_CHECK(mock_glTexCoord4d.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_dv)
{
	using namespace oglplus;

	oper::compatibility_drawing gl;

	{
		const GLdouble v[1] = {get<GLdouble>()};

		mock_glTexCoord1dv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord1dv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord1dv.all_ok_exclusive());
	}
	{
		const GLdouble v[2] = {get<GLdouble>(), get<GLdouble>()};

		mock_glTexCoord2dv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord2dv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord2dv.all_ok_exclusive());
	}
	{
		const GLdouble v[3] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		mock_glTexCoord3dv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord3dv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord3dv.all_ok_exclusive());
	}
	{
		const GLdouble v[4] = {get<GLdouble>(), get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

		mock_glTexCoord4dv.reset_params(v);
		BOOST_CHECK(!mock_glTexCoord4dv.all_ok_exclusive());
		gl.tex_coord(v);
		BOOST_CHECK( mock_glTexCoord4dv.all_ok_exclusive());
	}

	BOOST_CHECK(mock_glTexCoord1dv.was_called());
	BOOST_CHECK(mock_glTexCoord2dv.was_called());
	BOOST_CHECK(mock_glTexCoord3dv.was_called());
	BOOST_CHECK(mock_glTexCoord4dv.was_called());
}

BOOST_AUTO_TEST_SUITE_END()
