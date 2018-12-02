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

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/gl_func.hpp"
#include "../utils/quantities.hpp"
#include "../utils/span.hpp"

namespace oglplus {
namespace oper {

struct compatibility_matrix {
#ifdef GL_ARB_compatibility
    static outcome<void> matrix_mode(old_matrix_mode mode) noexcept;

    static outcome<void> push_matrix() noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void> push_matrix(old_matrix_mode mode) noexcept;
#endif

    static outcome<void> pop_matrix() noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void> pop_matrix(old_matrix_mode mode) noexcept;
#endif

    static outcome<void> load_identity() noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void> load_identity(old_matrix_mode mode) noexcept;
#endif

    static outcome<void> load_matrix(span<const GLfloat> mat) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void>
    load_matrix(old_matrix_mode mode, span<const GLfloat> mat) noexcept;
#endif

    static outcome<void>
    load_transpose_matrix(span<const GLfloat> mat) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void> load_transpose_matrix(
      old_matrix_mode mode, span<const GLfloat> mat) noexcept;
#endif

    static outcome<void> load_matrix(span<const GLdouble> mat) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void>
    load_matrix(old_matrix_mode mode, span<const GLdouble> mat) noexcept;
#endif

    static outcome<void>
    load_transpose_matrix(span<const GLdouble> mat) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void> load_transpose_matrix(
      old_matrix_mode mode, span<const GLdouble> mat) noexcept;
#endif

    static outcome<void> translate_f(GLfloat x, GLfloat y, GLfloat z) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void>
    translate_f(old_matrix_mode mode, GLfloat x, GLfloat y, GLfloat z) noexcept;
#endif

    static outcome<void>
    translate_d(GLdouble x, GLdouble y, GLdouble z) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void> translate_d(
      old_matrix_mode mode, GLdouble x, GLdouble y, GLdouble z) noexcept;
#endif

    static outcome<void>
    rotate_f(degrees_t<GLfloat> a, GLfloat x, GLfloat y, GLfloat z) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void> rotate_f(
      old_matrix_mode mode,
      degrees_t<GLfloat> a,
      GLfloat x,
      GLfloat y,
      GLfloat z) noexcept;
#endif

    static outcome<void> rotate_d(
      degrees_t<GLdouble> a, GLdouble x, GLdouble y, GLdouble z) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void> rotate_d(
      old_matrix_mode mode,
      degrees_t<GLdouble> a,
      GLdouble x,
      GLdouble y,
      GLdouble z) noexcept;
#endif

    static outcome<void> scale_f(GLfloat x, GLfloat y, GLfloat z) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void>
    scale_f(old_matrix_mode mode, GLfloat x, GLfloat y, GLfloat z) noexcept;
#endif

    static outcome<void> scale_d(GLdouble x, GLdouble y, GLdouble z) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void>
    scale_d(old_matrix_mode mode, GLdouble x, GLdouble y, GLdouble z) noexcept;
#endif

    static outcome<void> ortho(
      GLdouble l,
      GLdouble r,
      GLdouble b,
      GLdouble t,
      GLdouble n,
      GLdouble f) noexcept;

    static outcome<void> ortho_f(
      GLfloat l,
      GLfloat r,
      GLfloat b,
      GLfloat t,
      GLfloat n,
      GLfloat f) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void> ortho(
      old_matrix_mode mode,
      GLdouble l,
      GLdouble r,
      GLdouble b,
      GLdouble t,
      GLdouble n,
      GLdouble f) noexcept;
#endif

    static outcome<void> frustum(
      GLdouble l,
      GLdouble r,
      GLdouble b,
      GLdouble t,
      GLdouble n,
      GLdouble f) noexcept;

#ifdef GL_EXT_direct_state_access
    static outcome<void> frustum(
      old_matrix_mode mode,
      GLdouble l,
      GLdouble r,
      GLdouble b,
      GLdouble t,
      GLdouble n,
      GLdouble f) noexcept;
#endif

#endif // ARB_compatibility
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/compat_matrix.inl>

#endif // include guard
