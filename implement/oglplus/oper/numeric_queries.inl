/**
 *  @file oglplus/oper/numeric_queries.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline outcome<void> numeric_queries::get_integer_v(
  binding_query query, span<GLint> data) noexcept {
    EAGINE_ASSERT(data.size() > 0);
    OGLPLUS_GLFUNC(GetIntegerv)(GLenum(query), data.data());
    OGLPLUS_VERIFY(GetIntegerv, gl_enum_value(query), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> numeric_queries::get_boolean_v(
  numeric_query query, span<GLboolean> data) noexcept {
    EAGINE_ASSERT(data.size() > 0);
    OGLPLUS_GLFUNC(GetBooleanv)(GLenum(query), data.data());
    OGLPLUS_VERIFY(GetBooleanv, gl_enum_value(query), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<boolean> numeric_queries::get_boolean(
  numeric_query query) noexcept {
    GLboolean result = 0;
    return get_boolean_v(query, {&result, 1}).add(boolean(result));
}
//------------------------------------------------------------------------------
inline outcome<void> numeric_queries::get_integer_v(
  numeric_query query, span<GLint> data) noexcept {
    EAGINE_ASSERT(data.size() > 0);
    OGLPLUS_GLFUNC(GetIntegerv)(GLenum(query), data.data());
    OGLPLUS_VERIFY(GetIntegerv, gl_enum_value(query), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<GLint> numeric_queries::get_integer(
  numeric_query query) noexcept {
    GLint result = 0;
    return get_integer_v(query, {&result, 1}).add(result);
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_2)
inline outcome<void> numeric_queries::get_integer64_v(
  numeric_query query, span<GLint64> data) noexcept {
    EAGINE_ASSERT(data.size() > 0);
    OGLPLUS_GLFUNC(GetInteger64v)(GLenum(query), data.data());
    OGLPLUS_VERIFY(GetInteger64v, gl_enum_value(query), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<GLint64> numeric_queries::get_integer64(
  numeric_query query) noexcept {
    GLint64 result = 0;
    return get_integer64_v(query, {&result, 1}).add(result);
}
#endif
//------------------------------------------------------------------------------
inline outcome<void> numeric_queries::get_float_v(
  numeric_query query, span<GLfloat> data) noexcept {
    EAGINE_ASSERT(data.size() > 0);
    OGLPLUS_GLFUNC(GetFloatv)(GLenum(query), data.data());
    OGLPLUS_VERIFY(GetFloatv, gl_enum_value(query), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<GLfloat> numeric_queries::get_float(
  numeric_query query) noexcept {
    GLfloat result = 0;
    return get_float_v(query, {&result, 1}).add(result);
}
//------------------------------------------------------------------------------
#if defined(GL_DOUBLE)
inline outcome<void> numeric_queries::get_double_v(
  numeric_query query, span<GLdouble> data) noexcept {
    EAGINE_ASSERT(data.size() > 0);
    OGLPLUS_GLFUNC(GetDoublev)(GLenum(query), data.data());
    OGLPLUS_VERIFY(GetDoublev, gl_enum_value(query), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<GLdouble> numeric_queries::get_double(
  numeric_query query) noexcept {
    GLdouble result = 0;
    return get_double_v(query, {&result, 1}).add(result);
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0)
inline outcome<void> numeric_queries::get_boolean_v(
  numeric_query query, GLuint index, span<GLboolean> data) noexcept {
    EAGINE_ASSERT(data.size() > 0);
    OGLPLUS_GLFUNC(GetBooleani_v)(GLenum(query), index, data.data());
    OGLPLUS_VERIFY(GetBooleani_v, gl_enum_value(query).gl_index(index), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<boolean> numeric_queries::get_boolean(
  numeric_query query, GLuint index) noexcept {
    GLboolean result = 0;
    return get_boolean_v(query, index, {&result, 1}).add(boolean(result));
}
//------------------------------------------------------------------------------
inline outcome<void> numeric_queries::get_integer_v(
  numeric_query query, GLuint index, span<GLint> data) noexcept {
    EAGINE_ASSERT(data.size() > 0);
    OGLPLUS_GLFUNC(GetIntegeri_v)(GLenum(query), index, data.data());
    OGLPLUS_VERIFY(GetIntegeri_v, gl_enum_value(query).gl_index(index), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<GLint> numeric_queries::get_integer(
  numeric_query query, GLuint index) noexcept {
    GLint result = 0;
    return get_integer_v(query, index, {&result, 1}).add(result);
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_2)
inline outcome<void> numeric_queries::get_integer64_v(
  numeric_query query, GLuint index, span<GLint64> data) noexcept {
    EAGINE_ASSERT(data.size() > 0);
    OGLPLUS_GLFUNC(GetInteger64i_v)(GLenum(query), index, data.data());
    OGLPLUS_VERIFY(
      GetInteger64i_v, gl_enum_value(query).gl_index(index), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<GLint64> numeric_queries::get_integer64(
  numeric_query query, GLuint index) noexcept {
    GLint64 result = 0;
    return get_integer64_v(query, index, {&result, 1}).add(result);
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_1)
inline outcome<void> numeric_queries::get_float_v(
  numeric_query query, GLuint index, span<GLfloat> data) noexcept {
    EAGINE_ASSERT(data.size() > 0);
    OGLPLUS_GLFUNC(GetFloati_v)(GLenum(query), index, data.data());
    OGLPLUS_VERIFY(GetFloati_v, gl_enum_value(query).gl_index(index), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<GLfloat> numeric_queries::get_float(
  numeric_query query, GLuint index) noexcept {
    GLfloat result = 0;
    return get_float_v(query, index, {&result, 1}).add(result);
}
//------------------------------------------------------------------------------
inline outcome<void> numeric_queries::get_double_v(
  numeric_query query, GLuint index, span<GLdouble> data) noexcept {
    EAGINE_ASSERT(data.size() > 0);
    OGLPLUS_GLFUNC(GetDoublei_v)(GLenum(query), index, data.data());
    OGLPLUS_VERIFY(GetDoublei_v, gl_enum_value(query).gl_index(index), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<GLdouble> numeric_queries::get_double(
  numeric_query query, GLuint index) noexcept {
    GLdouble result = 0;
    return get_double_v(query, index, {&result, 1}).add(result);
}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
