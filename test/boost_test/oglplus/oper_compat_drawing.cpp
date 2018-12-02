/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include <oglplus/gl.hpp>
#define BOOST_TEST_MODULE OGLPLUS_oper_compat_drawing
#include "../unit_test_begin.inl"

#include "helper/mock_gl_func.hpp"
// clang-format on

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

#if defined(GL_DOUBLE)
OGLPLUS_MOCK_GLFUNC(Vertex2d, void(GLdouble, GLdouble));
OGLPLUS_MOCK_GLFUNC(Vertex3d, void(GLdouble, GLdouble, GLdouble));
OGLPLUS_MOCK_GLFUNC(Vertex4d, void(GLdouble, GLdouble, GLdouble, GLdouble));

OGLPLUS_MOCK_GLFUNC(Vertex2dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(Vertex3dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(Vertex4dv, void(const GLdouble*));
#endif

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

#if defined(GL_DOUBLE)
OGLPLUS_MOCK_GLFUNC(Color3d, void(GLdouble, GLdouble, GLdouble));
OGLPLUS_MOCK_GLFUNC(Color4d, void(GLdouble, GLdouble, GLdouble, GLdouble));

OGLPLUS_MOCK_GLFUNC(Color3dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(Color4dv, void(const GLdouble*));
#endif

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

#if defined(GL_DOUBLE)
OGLPLUS_MOCK_GLFUNC(TexCoord1d, void(GLdouble));
OGLPLUS_MOCK_GLFUNC(TexCoord2d, void(GLdouble, GLdouble));
OGLPLUS_MOCK_GLFUNC(TexCoord3d, void(GLdouble, GLdouble, GLdouble));
OGLPLUS_MOCK_GLFUNC(TexCoord4d, void(GLdouble, GLdouble, GLdouble, GLdouble));

OGLPLUS_MOCK_GLFUNC(TexCoord1dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(TexCoord2dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(TexCoord3dv, void(const GLdouble*));
OGLPLUS_MOCK_GLFUNC(TexCoord4dv, void(const GLdouble*));
#endif

#include <cstring>
#include <oglplus/oper/compat_drawing.hpp>

BOOST_AUTO_TEST_SUITE(compat_drawing_tests)

#if defined(GL_ARB_compatibility)

static eagine::test_random_generator rg;

template <typename T>
static T
get(void) {
    return rg.get_any<T>();
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_s) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLshort x = get<GLshort>();
        GLshort y = get<GLshort>();

        auto test_glVertex2s = make_aoe_test(mock_glVertex2s, x, y);
        gl.vertex_s(x, y);
        BOOST_CHECK(test_glVertex2s);
    }
    {
        GLshort x = get<GLshort>();
        GLshort y = get<GLshort>();
        GLshort z = get<GLshort>();

        auto test_glVertex3s = make_aoe_test(mock_glVertex3s, x, y, z);
        gl.vertex_s(x, y, z);
        BOOST_CHECK(test_glVertex3s);
    }
    {
        GLshort x = get<GLshort>();
        GLshort y = get<GLshort>();
        GLshort z = get<GLshort>();
        GLshort w = get<GLshort>();

        auto test_glVertex4s = make_aoe_test(mock_glVertex4s, x, y, z, w);
        gl.vertex_s(x, y, z, w);
        BOOST_CHECK(test_glVertex4s);
    }

    BOOST_CHECK(mock_glVertex2s.was_called());
    BOOST_CHECK(mock_glVertex3s.was_called());
    BOOST_CHECK(mock_glVertex4s.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_sv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLshort v[2] = {get<GLshort>(), get<GLshort>()};

        auto test_glVertex2sv = make_aoe_test(mock_glVertex2sv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex2sv);
    }
    {
        const GLshort v[3] = {get<GLshort>(), get<GLshort>(), get<GLshort>()};

        auto test_glVertex3sv = make_aoe_test(mock_glVertex3sv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex3sv);
    }
    {
        const GLshort v[4] = {
          get<GLshort>(), get<GLshort>(), get<GLshort>(), get<GLshort>()};

        auto test_glVertex4sv = make_aoe_test(mock_glVertex4sv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex4sv);
    }

    BOOST_CHECK(mock_glVertex2sv.was_called());
    BOOST_CHECK(mock_glVertex3sv.was_called());
    BOOST_CHECK(mock_glVertex4sv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_i) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLint x = get<GLint>();
        GLint y = get<GLint>();

        auto test_glVertex2i = make_aoe_test(mock_glVertex2i, x, y);
        gl.vertex_i(x, y);
        BOOST_CHECK(test_glVertex2i);
    }
    {
        GLint x = get<GLint>();
        GLint y = get<GLint>();
        GLint z = get<GLint>();

        auto test_glVertex3i = make_aoe_test(mock_glVertex3i, x, y, z);
        gl.vertex_i(x, y, z);
        BOOST_CHECK(test_glVertex3i);
    }
    {
        GLint x = get<GLint>();
        GLint y = get<GLint>();
        GLint z = get<GLint>();
        GLint w = get<GLint>();

        auto test_glVertex4i = make_aoe_test(mock_glVertex4i, x, y, z, w);
        gl.vertex_i(x, y, z, w);
        BOOST_CHECK(test_glVertex4i);
    }

    BOOST_CHECK(mock_glVertex2i.was_called());
    BOOST_CHECK(mock_glVertex3i.was_called());
    BOOST_CHECK(mock_glVertex4i.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_iv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLint v[2] = {get<GLint>(), get<GLint>()};

        auto test_glVertex2iv = make_aoe_test(mock_glVertex2iv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex2iv);
    }
    {
        const GLint v[3] = {get<GLint>(), get<GLint>(), get<GLint>()};

        auto test_glVertex3iv = make_aoe_test(mock_glVertex3iv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex3iv);
    }
    {
        const GLint v[4] = {
          get<GLint>(), get<GLint>(), get<GLint>(), get<GLint>()};

        auto test_glVertex4iv = make_aoe_test(mock_glVertex4iv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex4iv);
    }

    BOOST_CHECK(mock_glVertex2iv.was_called());
    BOOST_CHECK(mock_glVertex3iv.was_called());
    BOOST_CHECK(mock_glVertex4iv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_f) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLint x = get<GLint>();
        GLint y = get<GLint>();

        auto test_glVertex2f = make_aoe_test(mock_glVertex2f, x, y);
        gl.vertex_f(x, y);
        BOOST_CHECK(test_glVertex2f);
    }
    {
        GLint x = get<GLint>();
        GLint y = get<GLint>();
        GLint z = get<GLint>();

        auto test_glVertex3f = make_aoe_test(mock_glVertex3f, x, y, z);
        gl.vertex_f(x, y, z);
        BOOST_CHECK(test_glVertex3f);
    }
    {
        GLint x = get<GLint>();
        GLint y = get<GLint>();
        GLint z = get<GLint>();
        GLint w = get<GLint>();

        auto test_glVertex4f = make_aoe_test(mock_glVertex4f, x, y, z, w);
        gl.vertex_f(x, y, z, w);
        BOOST_CHECK(test_glVertex4f);
    }

    BOOST_CHECK(mock_glVertex2f.was_called());
    BOOST_CHECK(mock_glVertex3f.was_called());
    BOOST_CHECK(mock_glVertex4f.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_fv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLfloat v[2] = {get<GLfloat>(), get<GLfloat>()};

        auto test_glVertex2fv = make_aoe_test(mock_glVertex2fv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex2fv);
    }
    {
        const GLfloat v[3] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

        auto test_glVertex3fv = make_aoe_test(mock_glVertex3fv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex3fv);
    }
    {
        const GLfloat v[4] = {
          get<GLfloat>(), get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

        auto test_glVertex4fv = make_aoe_test(mock_glVertex4fv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex4fv);
    }

    BOOST_CHECK(mock_glVertex2fv.was_called());
    BOOST_CHECK(mock_glVertex3fv.was_called());
    BOOST_CHECK(mock_glVertex4fv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_d) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLint x = get<GLint>();
        GLint y = get<GLint>();

        auto test_glVertex2d = make_aoe_test(mock_glVertex2d, x, y);
        gl.vertex_d(x, y);
        BOOST_CHECK(test_glVertex2d);
    }
    {
        GLint x = get<GLint>();
        GLint y = get<GLint>();
        GLint z = get<GLint>();

        auto test_glVertex3d = make_aoe_test(mock_glVertex3d, x, y, z);
        gl.vertex_d(x, y, z);
        BOOST_CHECK(test_glVertex3d);
    }
    {
        GLint x = get<GLint>();
        GLint y = get<GLint>();
        GLint z = get<GLint>();
        GLint w = get<GLint>();

        auto test_glVertex4d = make_aoe_test(mock_glVertex4d, x, y, z, w);
        gl.vertex_d(x, y, z, w);
        BOOST_CHECK(test_glVertex4d);
    }

    BOOST_CHECK(mock_glVertex2d.was_called());
    BOOST_CHECK(mock_glVertex3d.was_called());
    BOOST_CHECK(mock_glVertex4d.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_vertex_dv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLdouble v[2] = {get<GLdouble>(), get<GLdouble>()};

        auto test_glVertex2dv = make_aoe_test(mock_glVertex2dv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex2dv);
    }
    {
        const GLdouble v[3] = {
          get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

        auto test_glVertex3dv = make_aoe_test(mock_glVertex3dv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex3dv);
    }
    {
        const GLdouble v[4] = {
          get<GLdouble>(), get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

        auto test_glVertex4dv = make_aoe_test(mock_glVertex4dv, v);
        gl.vertex(v);
        BOOST_CHECK(test_glVertex4dv);
    }

    BOOST_CHECK(mock_glVertex2dv.was_called());
    BOOST_CHECK(mock_glVertex3dv.was_called());
    BOOST_CHECK(mock_glVertex4dv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_ub) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLubyte r = get<GLubyte>();
        GLubyte g = get<GLubyte>();
        GLubyte b = get<GLubyte>();

        auto test_glColor3ub = make_aoe_test(mock_glColor3ub, r, g, b);
        gl.color_ub(r, g, b);
        BOOST_CHECK(test_glColor3ub);
    }
    {
        GLubyte r = get<GLubyte>();
        GLubyte g = get<GLubyte>();
        GLubyte b = get<GLubyte>();
        GLubyte a = get<GLubyte>();

        auto test_glColor4ub = make_aoe_test(mock_glColor4ub, r, g, b, a);
        gl.color_ub(r, g, b, a);
        BOOST_CHECK(test_glColor4ub);
    }

    BOOST_CHECK(mock_glColor3ub.was_called());
    BOOST_CHECK(mock_glColor4ub.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_ubv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLubyte v[3] = {get<GLubyte>(), get<GLubyte>(), get<GLubyte>()};

        auto test_glColor3ubv = make_aoe_test(mock_glColor3ubv, v);
        gl.color(v);
        BOOST_CHECK(test_glColor3ubv);
    }
    {
        const GLubyte v[4] = {
          get<GLubyte>(), get<GLubyte>(), get<GLubyte>(), get<GLubyte>()};

        auto test_glColor4ubv = make_aoe_test(mock_glColor4ubv, v);
        gl.color(v);
        BOOST_CHECK(test_glColor4ubv);
    }

    BOOST_CHECK(mock_glColor3ubv.was_called());
    BOOST_CHECK(mock_glColor4ubv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_i) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLint r = get<GLint>();
        GLint g = get<GLint>();
        GLint b = get<GLint>();

        auto test_glColor3i = make_aoe_test(mock_glColor3i, r, g, b);
        gl.color_i(r, g, b);
        BOOST_CHECK(test_glColor3i);
    }
    {
        GLint r = get<GLint>();
        GLint g = get<GLint>();
        GLint b = get<GLint>();
        GLint a = get<GLint>();

        auto test_glColor4i = make_aoe_test(mock_glColor4i, r, g, b, a);
        gl.color_i(r, g, b, a);
        BOOST_CHECK(test_glColor4i);
    }

    BOOST_CHECK(mock_glColor3i.was_called());
    BOOST_CHECK(mock_glColor4i.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_iv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLint v[3] = {get<GLint>(), get<GLint>(), get<GLint>()};

        auto test_glColor3iv = make_aoe_test(mock_glColor3iv, v);
        gl.color(v);
        BOOST_CHECK(test_glColor3iv);
    }
    {
        const GLint v[4] = {
          get<GLint>(), get<GLint>(), get<GLint>(), get<GLint>()};

        auto test_glColor4iv = make_aoe_test(mock_glColor4iv, v);
        gl.color(v);
        BOOST_CHECK(test_glColor4iv);
    }

    BOOST_CHECK(mock_glColor3iv.was_called());
    BOOST_CHECK(mock_glColor4iv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_f) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLfloat r = get<GLfloat>();
        GLfloat g = get<GLfloat>();
        GLfloat b = get<GLfloat>();

        auto test_glColor3f = make_aoe_test(mock_glColor3f, r, g, b);
        gl.color_f(r, g, b);
        BOOST_CHECK(test_glColor3f);
    }
    {
        GLfloat r = get<GLfloat>();
        GLfloat g = get<GLfloat>();
        GLfloat b = get<GLfloat>();
        GLfloat a = get<GLfloat>();

        auto test_glColor4f = make_aoe_test(mock_glColor4f, r, g, b, a);
        gl.color_f(r, g, b, a);
        BOOST_CHECK(test_glColor4f);
    }

    BOOST_CHECK(mock_glColor3f.was_called());
    BOOST_CHECK(mock_glColor4f.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_fv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLfloat v[3] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

        auto test_glColor3fv = make_aoe_test(mock_glColor3fv, v);
        gl.color(v);
        BOOST_CHECK(test_glColor3fv);
    }
    {
        const GLfloat v[4] = {
          get<GLfloat>(), get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

        auto test_glColor4fv = make_aoe_test(mock_glColor4fv, v);
        gl.color(v);
        BOOST_CHECK(test_glColor4fv);
    }

    BOOST_CHECK(mock_glColor3fv.was_called());
    BOOST_CHECK(mock_glColor4fv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_d) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLdouble r = get<GLdouble>();
        GLdouble g = get<GLdouble>();
        GLdouble b = get<GLdouble>();

        auto test_glColor3d = make_aoe_test(mock_glColor3d, r, g, b);
        gl.color_d(r, g, b);
        BOOST_CHECK(test_glColor3d);
    }
    {
        GLdouble r = get<GLdouble>();
        GLdouble g = get<GLdouble>();
        GLdouble b = get<GLdouble>();
        GLdouble a = get<GLdouble>();

        auto test_glColor4d = make_aoe_test(mock_glColor4d, r, g, b, a);
        gl.color_d(r, g, b, a);
        BOOST_CHECK(test_glColor4d);
    }

    BOOST_CHECK(mock_glColor3d.was_called());
    BOOST_CHECK(mock_glColor4d.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_color_dv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLdouble v[3] = {
          get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

        auto test_glColor3dv = make_aoe_test(mock_glColor3dv, v);
        gl.color(v);
        BOOST_CHECK(test_glColor3dv);
    }
    {
        const GLdouble v[4] = {
          get<GLdouble>(), get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

        auto test_glColor4dv = make_aoe_test(mock_glColor4dv, v);
        gl.color(v);
        BOOST_CHECK(test_glColor4dv);
    }

    BOOST_CHECK(mock_glColor3dv.was_called());
    BOOST_CHECK(mock_glColor4dv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_s) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLshort s = get<GLshort>();

        auto test_glTexCoord1s = make_aoe_test(mock_glTexCoord1s, s);
        gl.tex_coord_s(s);
        BOOST_CHECK(test_glTexCoord1s);
    }
    {
        GLshort s = get<GLshort>();
        GLshort t = get<GLshort>();

        auto test_glTexCoord2s = make_aoe_test(mock_glTexCoord2s, s, t);
        gl.tex_coord_s(s, t);
        BOOST_CHECK(test_glTexCoord2s);
    }
    {
        GLshort s = get<GLshort>();
        GLshort t = get<GLshort>();
        GLshort r = get<GLshort>();

        auto test_glTexCoord3s = make_aoe_test(mock_glTexCoord3s, s, t, r);
        gl.tex_coord_s(s, t, r);
        BOOST_CHECK(test_glTexCoord3s);
    }
    {
        GLshort s = get<GLshort>();
        GLshort t = get<GLshort>();
        GLshort r = get<GLshort>();
        GLshort q = get<GLshort>();

        auto test_glTexCoord4s = make_aoe_test(mock_glTexCoord4s, s, t, r, q);
        gl.tex_coord_s(s, t, r, q);
        BOOST_CHECK(test_glTexCoord4s);
    }

    BOOST_CHECK(mock_glTexCoord1s.was_called());
    BOOST_CHECK(mock_glTexCoord2s.was_called());
    BOOST_CHECK(mock_glTexCoord3s.was_called());
    BOOST_CHECK(mock_glTexCoord4s.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_sv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLshort v[1] = {get<GLshort>()};

        auto test_glTexCoord1sv = make_aoe_test(mock_glTexCoord1sv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord1sv);
    }
    {
        const GLshort v[2] = {get<GLshort>(), get<GLshort>()};

        auto test_glTexCoord2sv = make_aoe_test(mock_glTexCoord2sv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord2sv);
    }
    {
        const GLshort v[3] = {get<GLshort>(), get<GLshort>(), get<GLshort>()};

        auto test_glTexCoord3sv = make_aoe_test(mock_glTexCoord3sv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord3sv);
    }
    {
        const GLshort v[4] = {
          get<GLshort>(), get<GLshort>(), get<GLshort>(), get<GLshort>()};

        auto test_glTexCoord4sv = make_aoe_test(mock_glTexCoord4sv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord4sv);
    }

    BOOST_CHECK(mock_glTexCoord1sv.was_called());
    BOOST_CHECK(mock_glTexCoord2sv.was_called());
    BOOST_CHECK(mock_glTexCoord3sv.was_called());
    BOOST_CHECK(mock_glTexCoord4sv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_i) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLint s = get<GLint>();

        auto test_glTexCoord1i = make_aoe_test(mock_glTexCoord1i, s);
        gl.tex_coord_i(s);
        BOOST_CHECK(test_glTexCoord1i);
    }
    {
        GLint s = get<GLint>();
        GLint t = get<GLint>();

        auto test_glTexCoord2i = make_aoe_test(mock_glTexCoord2i, s, t);
        gl.tex_coord_i(s, t);
        BOOST_CHECK(test_glTexCoord2i);
    }
    {
        GLint s = get<GLint>();
        GLint t = get<GLint>();
        GLint r = get<GLint>();

        auto test_glTexCoord3i = make_aoe_test(mock_glTexCoord3i, s, t, r);
        gl.tex_coord_i(s, t, r);
        BOOST_CHECK(test_glTexCoord3i);
    }
    {
        GLint s = get<GLint>();
        GLint t = get<GLint>();
        GLint r = get<GLint>();
        GLint q = get<GLint>();

        auto test_glTexCoord4i = make_aoe_test(mock_glTexCoord4i, s, t, r, q);
        gl.tex_coord_i(s, t, r, q);
        BOOST_CHECK(test_glTexCoord4i);
    }

    BOOST_CHECK(mock_glTexCoord1i.was_called());
    BOOST_CHECK(mock_glTexCoord2i.was_called());
    BOOST_CHECK(mock_glTexCoord3i.was_called());
    BOOST_CHECK(mock_glTexCoord4i.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_iv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLint v[1] = {get<GLint>()};

        auto test_glTexCoord1iv = make_aoe_test(mock_glTexCoord1iv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord1iv);
    }
    {
        const GLint v[2] = {get<GLint>(), get<GLint>()};

        auto test_glTexCoord2iv = make_aoe_test(mock_glTexCoord2iv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord2iv);
    }
    {
        const GLint v[3] = {get<GLint>(), get<GLint>(), get<GLint>()};

        auto test_glTexCoord3iv = make_aoe_test(mock_glTexCoord3iv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord3iv);
    }
    {
        const GLint v[4] = {
          get<GLint>(), get<GLint>(), get<GLint>(), get<GLint>()};

        auto test_glTexCoord4iv = make_aoe_test(mock_glTexCoord4iv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord4iv);
    }

    BOOST_CHECK(mock_glTexCoord1iv.was_called());
    BOOST_CHECK(mock_glTexCoord2iv.was_called());
    BOOST_CHECK(mock_glTexCoord3iv.was_called());
    BOOST_CHECK(mock_glTexCoord4iv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_f) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLfloat s = get<GLfloat>();

        auto test_glTexCoord1f = make_aoe_test(mock_glTexCoord1f, s);
        gl.tex_coord_f(s);
        BOOST_CHECK(test_glTexCoord1f);
    }
    {
        GLfloat s = get<GLfloat>();
        GLfloat t = get<GLfloat>();

        auto test_glTexCoord2f = make_aoe_test(mock_glTexCoord2f, s, t);
        gl.tex_coord_f(s, t);
        BOOST_CHECK(test_glTexCoord2f);
    }
    {
        GLfloat s = get<GLfloat>();
        GLfloat t = get<GLfloat>();
        GLfloat r = get<GLfloat>();

        auto test_glTexCoord3f = make_aoe_test(mock_glTexCoord3f, s, t, r);
        gl.tex_coord_f(s, t, r);
        BOOST_CHECK(test_glTexCoord3f);
    }
    {
        GLfloat s = get<GLfloat>();
        GLfloat t = get<GLfloat>();
        GLfloat r = get<GLfloat>();
        GLfloat q = get<GLfloat>();

        auto test_glTexCoord4f = make_aoe_test(mock_glTexCoord4f, s, t, r, q);
        gl.tex_coord_f(s, t, r, q);
        BOOST_CHECK(test_glTexCoord4f);
    }

    BOOST_CHECK(mock_glTexCoord1f.was_called());
    BOOST_CHECK(mock_glTexCoord2f.was_called());
    BOOST_CHECK(mock_glTexCoord3f.was_called());
    BOOST_CHECK(mock_glTexCoord4f.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_fv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLfloat v[1] = {get<GLfloat>()};

        auto test_glTexCoord1fv = make_aoe_test(mock_glTexCoord1fv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord1fv);
    }
    {
        const GLfloat v[2] = {get<GLfloat>(), get<GLfloat>()};

        auto test_glTexCoord2fv = make_aoe_test(mock_glTexCoord2fv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord2fv);
    }
    {
        const GLfloat v[3] = {get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

        auto test_glTexCoord3fv = make_aoe_test(mock_glTexCoord3fv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord3fv);
    }
    {
        const GLfloat v[4] = {
          get<GLfloat>(), get<GLfloat>(), get<GLfloat>(), get<GLfloat>()};

        auto test_glTexCoord4fv = make_aoe_test(mock_glTexCoord4fv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord4fv);
    }

    BOOST_CHECK(mock_glTexCoord1fv.was_called());
    BOOST_CHECK(mock_glTexCoord2fv.was_called());
    BOOST_CHECK(mock_glTexCoord3fv.was_called());
    BOOST_CHECK(mock_glTexCoord4fv.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_d) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        GLdouble s = get<GLdouble>();

        auto test_glTexCoord1d = make_aoe_test(mock_glTexCoord1d, s);
        gl.tex_coord_d(s);
        BOOST_CHECK(test_glTexCoord1d);
    }
    {
        GLdouble s = get<GLdouble>();
        GLdouble t = get<GLdouble>();

        auto test_glTexCoord2d = make_aoe_test(mock_glTexCoord2d, s, t);
        gl.tex_coord_d(s, t);
        BOOST_CHECK(test_glTexCoord2d);
    }
    {
        GLdouble s = get<GLdouble>();
        GLdouble t = get<GLdouble>();
        GLdouble r = get<GLdouble>();

        auto test_glTexCoord3d = make_aoe_test(mock_glTexCoord3d, s, t, r);
        gl.tex_coord_d(s, t, r);
        BOOST_CHECK(test_glTexCoord3d);
    }
    {
        GLdouble s = get<GLdouble>();
        GLdouble t = get<GLdouble>();
        GLdouble r = get<GLdouble>();
        GLdouble q = get<GLdouble>();

        auto test_glTexCoord4d = make_aoe_test(mock_glTexCoord4d, s, t, r, q);
        gl.tex_coord_d(s, t, r, q);
        BOOST_CHECK(test_glTexCoord4d);
    }

    BOOST_CHECK(mock_glTexCoord1d.was_called());
    BOOST_CHECK(mock_glTexCoord2d.was_called());
    BOOST_CHECK(mock_glTexCoord3d.was_called());
    BOOST_CHECK(mock_glTexCoord4d.was_called());
}

BOOST_AUTO_TEST_CASE(compat_drawing_tex_coord_dv) {
    using namespace oglplus;

    oper::compatibility_drawing gl;

    {
        const GLdouble v[1] = {get<GLdouble>()};

        auto test_glTexCoord1dv = make_aoe_test(mock_glTexCoord1dv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord1dv);
    }
    {
        const GLdouble v[2] = {get<GLdouble>(), get<GLdouble>()};

        auto test_glTexCoord2dv = make_aoe_test(mock_glTexCoord2dv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord2dv);
    }
    {
        const GLdouble v[3] = {
          get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

        auto test_glTexCoord3dv = make_aoe_test(mock_glTexCoord3dv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord3dv);
    }
    {
        const GLdouble v[4] = {
          get<GLdouble>(), get<GLdouble>(), get<GLdouble>(), get<GLdouble>()};

        auto test_glTexCoord4dv = make_aoe_test(mock_glTexCoord4dv, v);
        gl.tex_coord(v);
        BOOST_CHECK(test_glTexCoord4dv);
    }

    BOOST_CHECK(mock_glTexCoord1dv.was_called());
    BOOST_CHECK(mock_glTexCoord2dv.was_called());
    BOOST_CHECK(mock_glTexCoord3dv.was_called());
    BOOST_CHECK(mock_glTexCoord4dv.was_called());
}

#else
BOOST_AUTO_TEST_CASE(compat_drawing_dummy) {
}
#endif

BOOST_AUTO_TEST_SUITE_END()
