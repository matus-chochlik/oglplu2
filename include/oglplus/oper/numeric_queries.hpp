/**
 *  @file oglplus/oper/numeric_queries.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_NUMERIC_QUERIES_1509260923_HPP
#define OGLPLUS_OPER_NUMERIC_QUERIES_1509260923_HPP

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/boolean.hpp"
#include "../utils/gl_func.hpp"
#include "../utils/span.hpp"

namespace oglplus {
namespace oper {

struct numeric_queries {
    static outcome<void> get_integer_v(
      binding_query query, span<GLint> data) noexcept;

    static outcome<void> get_boolean_v(
      numeric_query query, span<GLboolean> data) noexcept;

    static outcome<boolean> get_boolean(numeric_query query) noexcept;

    static outcome<void> get_integer_v(
      numeric_query query, span<GLint> data) noexcept;

    static outcome<GLint> get_integer(numeric_query query) noexcept;

#if defined(GL_VERSION_3_2)
    static outcome<void> get_integer64_v(
      numeric_query query, span<GLint64> data) noexcept;

    static outcome<GLint64> get_integer64(numeric_query query) noexcept;
#endif

    static outcome<void> get_float_v(
      numeric_query query, span<GLfloat> data) noexcept;

    static outcome<GLfloat> get_float(numeric_query query) noexcept;

#if defined(GL_DOUBLE)
    static outcome<void> get_double_v(
      numeric_query query, span<GLdouble> data) noexcept;

    static outcome<GLdouble> get_double(numeric_query query) noexcept;
#endif

#if defined(GL_VERSION_3_0)
    static outcome<void> get_boolean_v(
      numeric_query query, GLuint index, span<GLboolean> data) noexcept;

    static outcome<boolean> get_boolean(
      numeric_query query, GLuint index) noexcept;

    static outcome<void> get_integer_v(
      numeric_query query, GLuint index, span<GLint> data) noexcept;

    static outcome<GLint> get_integer(
      numeric_query query, GLuint index) noexcept;
#endif

#if defined(GL_VERSION_3_2)
    static outcome<void> get_integer64_v(
      numeric_query query, GLuint index, span<GLint64> data) noexcept;

    static outcome<GLint64> get_integer64(
      numeric_query query, GLuint index) noexcept;
#endif

#if defined(GL_VERSION_4_1)
    static outcome<void> get_float_v(
      numeric_query query, GLuint index, span<GLfloat> data) noexcept;

    static outcome<GLfloat> get_float(
      numeric_query query, GLuint index) noexcept;

    static outcome<void> get_double_v(
      numeric_query query, GLuint index, span<GLdouble> data) noexcept;

    static outcome<GLdouble> get_double(
      numeric_query query, GLuint index) noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/numeric_queries.inl>

#endif // include guard
