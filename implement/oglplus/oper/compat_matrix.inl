/**
 *  @file oglplus/oper/compat_matrix.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifdef GL_ARB_compatibility
#include <cassert>
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::matrix_mode(old_matrix_mode mode) noexcept {
    OGLPLUS_GLFUNC(MatrixMode)(GLenum(mode));
    OGLPLUS_VERIFY_SIMPLE(MatrixMode, debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::push_matrix(void) noexcept {
    OGLPLUS_GLFUNC(PushMatrix)();
    OGLPLUS_VERIFY_SIMPLE(PushMatrix, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::push_matrix(old_matrix_mode mode) noexcept {
    OGLPLUS_GLFUNC(MatrixPushEXT)(GLenum(mode));
    OGLPLUS_VERIFY_SIMPLE(MatrixPushEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::pop_matrix(void) noexcept {
    OGLPLUS_GLFUNC(PopMatrix)();
    OGLPLUS_VERIFY_SIMPLE(PopMatrix, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::pop_matrix(old_matrix_mode mode) noexcept {
    OGLPLUS_GLFUNC(MatrixPopEXT)(GLenum(mode));
    OGLPLUS_VERIFY_SIMPLE(MatrixPopEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::load_identity(void) noexcept {
    OGLPLUS_GLFUNC(LoadIdentity)();
    OGLPLUS_VERIFY_SIMPLE(LoadIdentity, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::load_identity(old_matrix_mode mode) noexcept {
    OGLPLUS_GLFUNC(MatrixLoadIdentityEXT)(GLenum(mode));
    OGLPLUS_VERIFY_SIMPLE(MatrixLoadIdentityEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::load_matrix(span<const GLfloat> mat) noexcept {
    assert(mat.size() >= 16);
    OGLPLUS_GLFUNC(LoadMatrixf)(mat.data());
    OGLPLUS_VERIFY_SIMPLE(LoadMatrixf, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::load_matrix(
  old_matrix_mode mode, span<const GLfloat> mat) noexcept {
    assert(mat.size() >= 16);
    OGLPLUS_GLFUNC(MatrixLoadfEXT)(GLenum(mode), mat.data());
    OGLPLUS_VERIFY_SIMPLE(MatrixLoadfEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::load_transpose_matrix(span<const GLfloat> mat) noexcept {
    assert(mat.size() >= 16);
    OGLPLUS_GLFUNC(LoadTransposeMatrixf)(mat.data());
    OGLPLUS_VERIFY_SIMPLE(LoadTransposeMatrixf, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::load_transpose_matrix(
  old_matrix_mode mode, span<const GLfloat> mat) noexcept {
    assert(mat.size() >= 16);
    OGLPLUS_GLFUNC(MatrixLoadTransposefEXT)(GLenum(mode), mat.data());
    OGLPLUS_VERIFY_SIMPLE(MatrixLoadTransposefEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::load_matrix(span<const GLdouble> mat) noexcept {
    assert(mat.size() >= 16);
    OGLPLUS_GLFUNC(LoadMatrixd)(mat.data());
    OGLPLUS_VERIFY_SIMPLE(LoadMatrixd, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::load_matrix(
  old_matrix_mode mode, span<const GLdouble> mat) noexcept {
    assert(mat.size() >= 16);
    OGLPLUS_GLFUNC(MatrixLoaddEXT)(GLenum(mode), mat.data());
    OGLPLUS_VERIFY_SIMPLE(MatrixLoaddEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::load_transpose_matrix(span<const GLdouble> mat) noexcept {
    assert(mat.size() >= 16);
    OGLPLUS_GLFUNC(LoadTransposeMatrixd)(mat.data());
    OGLPLUS_VERIFY_SIMPLE(LoadTransposeMatrixd, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::load_transpose_matrix(
  old_matrix_mode mode, span<const GLdouble> mat) noexcept {
    OGLPLUS_GLFUNC(MatrixLoadTransposedEXT)(GLenum(mode), mat.data());
    OGLPLUS_VERIFY_SIMPLE(MatrixLoadTransposedEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::translate_f(GLfloat x, GLfloat y, GLfloat z) noexcept {
    OGLPLUS_GLFUNC(Translatef)(x, y, z);
    OGLPLUS_VERIFY_SIMPLE(Translatef, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::translate_f(
  old_matrix_mode mode, GLfloat x, GLfloat y, GLfloat z) noexcept {
    OGLPLUS_GLFUNC(MatrixTranslatefEXT)(GLenum(mode), x, y, z);
    OGLPLUS_VERIFY_SIMPLE(MatrixTranslatefEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::translate_d(GLdouble x, GLdouble y, GLdouble z) noexcept {
    OGLPLUS_GLFUNC(Translated)(x, y, z);
    OGLPLUS_VERIFY_SIMPLE(Translated, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::translate_d(
  old_matrix_mode mode, GLdouble x, GLdouble y, GLdouble z) noexcept {
    OGLPLUS_GLFUNC(MatrixTranslatedEXT)(GLenum(mode), x, y, z);
    OGLPLUS_VERIFY_SIMPLE(MatrixTranslatedEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::rotate_f(
  degrees_t<GLfloat> a, GLfloat x, GLfloat y, GLfloat z) noexcept {
    OGLPLUS_GLFUNC(Rotatef)(GLfloat(a), x, y, z);
    OGLPLUS_VERIFY_SIMPLE(Rotatef, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::rotate_f(
  old_matrix_mode mode,
  degrees_t<GLfloat> a,
  GLfloat x,
  GLfloat y,
  GLfloat z) noexcept {
    OGLPLUS_GLFUNC(MatrixRotatefEXT)(GLenum(mode), GLfloat(a), x, y, z);
    OGLPLUS_VERIFY_SIMPLE(MatrixRotatefEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::rotate_d(
  degrees_t<GLdouble> a, GLdouble x, GLdouble y, GLdouble z) noexcept {
    OGLPLUS_GLFUNC(Rotated)(GLdouble(a), x, y, z);
    OGLPLUS_VERIFY_SIMPLE(Rotated, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::rotate_d(
  old_matrix_mode mode,
  degrees_t<GLdouble> a,
  GLdouble x,
  GLdouble y,
  GLdouble z) noexcept {
    OGLPLUS_GLFUNC(MatrixRotatedEXT)(GLenum(mode), GLdouble(a), x, y, z);
    OGLPLUS_VERIFY_SIMPLE(MatrixRotatedEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::scale_f(GLfloat x, GLfloat y, GLfloat z) noexcept {
    OGLPLUS_GLFUNC(Scalef)(x, y, z);
    OGLPLUS_VERIFY_SIMPLE(Scalef, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::scale_f(
  old_matrix_mode mode, GLfloat x, GLfloat y, GLfloat z) noexcept {
    OGLPLUS_GLFUNC(MatrixScalefEXT)(GLenum(mode), x, y, z);
    OGLPLUS_VERIFY_SIMPLE(MatrixScalefEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::scale_d(GLdouble x, GLdouble y, GLdouble z) noexcept {
    OGLPLUS_GLFUNC(Scaled)(x, y, z);
    OGLPLUS_VERIFY_SIMPLE(Scaled, debug);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::scale_d(
  old_matrix_mode mode, GLdouble x, GLdouble y, GLdouble z) noexcept {
    OGLPLUS_GLFUNC(MatrixScaledEXT)(GLenum(mode), x, y, z);
    OGLPLUS_VERIFY_SIMPLE(MatrixScaledEXT, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::ortho(
  GLdouble l,
  GLdouble r,
  GLdouble b,
  GLdouble t,
  GLdouble n,
  GLdouble f) noexcept {
    OGLPLUS_GLFUNC(Ortho)(l, r, b, t, n, f);
    OGLPLUS_VERIFY_SIMPLE(Ortho, always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::ortho_f(
  GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) noexcept {
    OGLPLUS_GLFUNC(Orthof)(l, r, b, t, n, f);
    OGLPLUS_VERIFY_SIMPLE(Orthof, always);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::ortho(
  old_matrix_mode mode,
  GLdouble l,
  GLdouble r,
  GLdouble b,
  GLdouble t,
  GLdouble n,
  GLdouble f) noexcept {
    OGLPLUS_GLFUNC(MatrixOrthoEXT)(GLenum(mode), l, r, b, t, n, f);
    OGLPLUS_VERIFY_SIMPLE(MatrixOrthoEXT, always);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
compatibility_matrix::frustum(
  GLdouble l,
  GLdouble r,
  GLdouble b,
  GLdouble t,
  GLdouble n,
  GLdouble f) noexcept {
    OGLPLUS_GLFUNC(Frustum)(l, r, b, t, n, f);
    OGLPLUS_VERIFY_SIMPLE(Frustum, always);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
compatibility_matrix::frustum(
  old_matrix_mode mode,
  GLdouble l,
  GLdouble r,
  GLdouble b,
  GLdouble t,
  GLdouble n,
  GLdouble f) noexcept {
    OGLPLUS_GLFUNC(MatrixFrustumEXT)(GLenum(mode), l, r, b, t, n, f);
    OGLPLUS_VERIFY_SIMPLE(MatrixFrustumEXT, always);
    return {};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
#endif
