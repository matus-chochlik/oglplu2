//  File implement/oglplus/vertex_attrib_get_set.inl
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the the 'source/misc/make_code.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#include <eagine/assert.hpp>

namespace oglplus {

template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLfloat> {

    static outcome<void> set(
      identity<GLfloat>,
      vertex_attrib_location va,
      bool ge,
      GLfloat v0) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib1f)(va.index(), v0);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib1f, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLfloat>,
      vertex_attrib_location va,
      bool ge,
      GLfloat v0,
      GLfloat v1) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib2f)(va.index(), v0, v1);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib2f, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLfloat>,
      vertex_attrib_location va,
      bool ge,
      GLfloat v0,
      GLfloat v1,
      GLfloat v2) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib3f)(va.index(), v0, v1, v2);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib3f, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLfloat>,
      vertex_attrib_location va,
      bool ge,
      GLfloat v0,
      GLfloat v1,
      GLfloat v2,
      GLfloat v3) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib4f)(va.index(), v0, v1, v2, v3);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4f, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLfloat[1]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLfloat> v) noexcept {
        EAGINE_ASSERT(v.size() >= 1);
        OGLPLUS_GLFUNC(VertexAttrib1fv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib1fv, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLfloat[2]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLfloat> v) noexcept {
        EAGINE_ASSERT(v.size() >= 2);
        OGLPLUS_GLFUNC(VertexAttrib2fv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib2fv, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLfloat[3]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLfloat> v) noexcept {
        EAGINE_ASSERT(v.size() >= 3);
        OGLPLUS_GLFUNC(VertexAttrib3fv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib3fv, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLfloat[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLfloat> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4fv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4fv, debug);
        }
        return {};
    }
};
#if defined(GL_VERSION_3_0)
template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLbyte> {

    static outcome<void> set(
      identity<GLbyte[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLbyte> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4bv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4bv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLbyte[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLbyte> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttribI4bv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI4bv, debug);
        }
        return {};
    }

    static outcome<void> setN(
      identity<GLbyte[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLbyte> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4Nbv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4Nbv, debug);
        }
        return {};
    }
};

template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLubyte> {

    static outcome<void> set(
      identity<GLubyte[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLubyte> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4ubv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4ubv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLubyte[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLubyte> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttribI4ubv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI4ubv, debug);
        }
        return {};
    }

    static outcome<void> setN(
      identity<GLubyte[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLubyte> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4Nubv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4Nubv, debug);
        }
        return {};
    }
};

template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLshort> {

    static outcome<void> set(
      identity<GLshort>,
      vertex_attrib_location va,
      bool ge,
      GLshort v0) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib1s)(va.index(), v0);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib1s, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLshort>,
      vertex_attrib_location va,
      bool ge,
      GLshort v0,
      GLshort v1) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib2s)(va.index(), v0, v1);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib2s, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLshort>,
      vertex_attrib_location va,
      bool ge,
      GLshort v0,
      GLshort v1,
      GLshort v2) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib3s)(va.index(), v0, v1, v2);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib3s, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLshort>,
      vertex_attrib_location va,
      bool ge,
      GLshort v0,
      GLshort v1,
      GLshort v2,
      GLshort v3) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib4s)(va.index(), v0, v1, v2, v3);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4s, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLshort[1]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLshort> v) noexcept {
        EAGINE_ASSERT(v.size() >= 1);
        OGLPLUS_GLFUNC(VertexAttrib1sv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib1sv, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLshort[2]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLshort> v) noexcept {
        EAGINE_ASSERT(v.size() >= 2);
        OGLPLUS_GLFUNC(VertexAttrib2sv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib2sv, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLshort[3]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLshort> v) noexcept {
        EAGINE_ASSERT(v.size() >= 3);
        OGLPLUS_GLFUNC(VertexAttrib3sv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib3sv, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLshort[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLshort> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4sv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4sv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLshort[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLshort> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttribI4sv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI4sv, debug);
        }
        return {};
    }

    static outcome<void> setN(
      identity<GLshort[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLshort> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4Nsv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4Nsv, debug);
        }
        return {};
    }
};
template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLushort> {

    static outcome<void> set(
      identity<GLushort[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLushort> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4usv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4usv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLushort[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLushort> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttribI4usv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI4usv, debug);
        }
        return {};
    }

    static outcome<void> setN(
      identity<GLushort[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLushort> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4Nusv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4Nusv, debug);
        }
        return {};
    }
};

template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLint> {

    static outcome<void> set(
      identity<GLint[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4iv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4iv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLint[1]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 1);
        OGLPLUS_GLFUNC(VertexAttribI1iv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI1iv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLint[2]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 2);
        OGLPLUS_GLFUNC(VertexAttribI2iv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI2iv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLint[3]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 3);
        OGLPLUS_GLFUNC(VertexAttribI3iv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI3iv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLint[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttribI4iv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI4iv, debug);
        }
        return {};
    }

    static outcome<void> setN(
      identity<GLint[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4Niv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4Niv, debug);
        }
        return {};
    }
};
template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLuint> {

    static outcome<void> set(
      identity<GLuint[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLuint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4uiv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4uiv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLuint[1]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLuint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 1);
        OGLPLUS_GLFUNC(VertexAttribI1uiv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI1uiv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLuint[2]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLuint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 2);
        OGLPLUS_GLFUNC(VertexAttribI2uiv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI2uiv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLuint[3]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLuint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 3);
        OGLPLUS_GLFUNC(VertexAttribI3uiv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI3uiv, debug);
        }
        return {};
    }

    static outcome<void> setI(
      identity<GLuint[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLuint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttribI4uiv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribI4uiv, debug);
        }
        return {};
    }

    static outcome<void> setN(
      identity<GLuint[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLuint> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4Nuiv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4Nuiv, debug);
        }
        return {};
    }

    static outcome<void> setP1(
      identity<GLuint>,
      vertex_attrib_location va,
      bool ge,
      data_type type,
      boolean norm,
      GLuint val) noexcept {
        OGLPLUS_GLFUNC(VertexAttribP1ui)
        (va.index(), GLenum(type), GLboolean(norm), val);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribP1ui, debug);
        }
        return {};
    }

    static outcome<void> setP2(
      identity<GLuint>,
      vertex_attrib_location va,
      bool ge,
      data_type type,
      boolean norm,
      GLuint val) noexcept {
        OGLPLUS_GLFUNC(VertexAttribP2ui)
        (va.index(), GLenum(type), GLboolean(norm), val);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribP2ui, debug);
        }
        return {};
    }

    static outcome<void> setP3(
      identity<GLuint>,
      vertex_attrib_location va,
      bool ge,
      data_type type,
      boolean norm,
      GLuint val) noexcept {
        OGLPLUS_GLFUNC(VertexAttribP3ui)
        (va.index(), GLenum(type), GLboolean(norm), val);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribP3ui, debug);
        }
        return {};
    }

    static outcome<void> setP4(
      identity<GLuint>,
      vertex_attrib_location va,
      bool ge,
      data_type type,
      boolean norm,
      GLuint val) noexcept {
        OGLPLUS_GLFUNC(VertexAttribP4ui)
        (va.index(), GLenum(type), GLboolean(norm), val);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribP4ui, debug);
        }
        return {};
    }
};
#if defined(GL_VERSION_3_0)
template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLdouble> {

    static outcome<void> set(
      identity<GLdouble>,
      vertex_attrib_location va,
      bool ge,
      GLdouble v0) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib1d)(va.index(), v0);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib1d, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLdouble>,
      vertex_attrib_location va,
      bool ge,
      GLdouble v0,
      GLdouble v1) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib2d)(va.index(), v0, v1);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib2d, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLdouble>,
      vertex_attrib_location va,
      bool ge,
      GLdouble v0,
      GLdouble v1,
      GLdouble v2) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib3d)(va.index(), v0, v1, v2);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib3d, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLdouble>,
      vertex_attrib_location va,
      bool ge,
      GLdouble v0,
      GLdouble v1,
      GLdouble v2,
      GLdouble v3) noexcept {
        OGLPLUS_GLFUNC(VertexAttrib4d)(va.index(), v0, v1, v2, v3);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4d, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLdouble[1]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLdouble> v) noexcept {
        EAGINE_ASSERT(v.size() >= 1);
        OGLPLUS_GLFUNC(VertexAttrib1dv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib1dv, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLdouble[2]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLdouble> v) noexcept {
        EAGINE_ASSERT(v.size() >= 2);
        OGLPLUS_GLFUNC(VertexAttrib2dv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib2dv, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLdouble[3]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLdouble> v) noexcept {
        EAGINE_ASSERT(v.size() >= 3);
        OGLPLUS_GLFUNC(VertexAttrib3dv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib3dv, debug);
        }
        return {};
    }

    static outcome<void> set(
      identity<GLdouble[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLdouble> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttrib4dv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttrib4dv, debug);
        }
        return {};
    }
#if defined(GL_VERSION_4_1)

    static outcome<void> setL(
      identity<GLdouble>,
      vertex_attrib_location va,
      bool ge,
      GLdouble v0) noexcept {
        OGLPLUS_GLFUNC(VertexAttribL1d)(va.index(), v0);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribL1d, debug);
        }
        return {};
    }

    static outcome<void> setL(
      identity<GLdouble>,
      vertex_attrib_location va,
      bool ge,
      GLdouble v0,
      GLdouble v1) noexcept {
        OGLPLUS_GLFUNC(VertexAttribL2d)(va.index(), v0, v1);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribL2d, debug);
        }
        return {};
    }

    static outcome<void> setL(
      identity<GLdouble>,
      vertex_attrib_location va,
      bool ge,
      GLdouble v0,
      GLdouble v1,
      GLdouble v2) noexcept {
        OGLPLUS_GLFUNC(VertexAttribL3d)(va.index(), v0, v1, v2);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribL3d, debug);
        }
        return {};
    }

    static outcome<void> setL(
      identity<GLdouble>,
      vertex_attrib_location va,
      bool ge,
      GLdouble v0,
      GLdouble v1,
      GLdouble v2,
      GLdouble v3) noexcept {
        OGLPLUS_GLFUNC(VertexAttribL4d)(va.index(), v0, v1, v2, v3);
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribL4d, debug);
        }
        return {};
    }

    static outcome<void> setL(
      identity<GLdouble[1]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLdouble> v) noexcept {
        EAGINE_ASSERT(v.size() >= 1);
        OGLPLUS_GLFUNC(VertexAttribL1dv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribL1dv, debug);
        }
        return {};
    }

    static outcome<void> setL(
      identity<GLdouble[2]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLdouble> v) noexcept {
        EAGINE_ASSERT(v.size() >= 2);
        OGLPLUS_GLFUNC(VertexAttribL2dv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribL2dv, debug);
        }
        return {};
    }

    static outcome<void> setL(
      identity<GLdouble[3]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLdouble> v) noexcept {
        EAGINE_ASSERT(v.size() >= 3);
        OGLPLUS_GLFUNC(VertexAttribL3dv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribL3dv, debug);
        }
        return {};
    }

    static outcome<void> setL(
      identity<GLdouble[4]>,
      vertex_attrib_location va,
      bool ge,
      span<const GLdouble> v) noexcept {
        EAGINE_ASSERT(v.size() >= 4);
        OGLPLUS_GLFUNC(VertexAttribL4dv)(va.index(), v.data());
        if(ge) {
            OGLPLUS_VERIFY_SIMPLE(VertexAttribL4dv, debug);
        }
        return {};
    }
#endif // GL_VERSION_4_1
};
#endif // GL_DOUBLE
#endif // GL_VERSION_3_0
} // namespace oglplus
