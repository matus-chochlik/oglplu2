/**
 *  @file oglplus/oper/named_string.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifdef GL_ARB_shading_language_include
#include <eagine/assert.hpp>
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline outcome<void> named_string_state::named_string(
  oglplus::named_string_type type,
  string_view name,
  string_view value) noexcept {
    OGLPLUS_GLFUNC(NamedStringARB)
    (GLenum(type),
     GLint(name.size()),
     name.data(),
     GLint(value.size()),
     value.data());
    OGLPLUS_VERIFY_SIMPLE(NamedStringARB, always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> named_string_state::delete_named_string(
  string_view name) noexcept {
    OGLPLUS_GLFUNC(DeleteNamedStringARB)(GLint(name.size()), name.data());
    OGLPLUS_VERIFY_SIMPLE(DeleteNamedStringARB, always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<boolean> named_string_state::is_named_string(
  string_view name) noexcept {
    GLboolean result =
      OGLPLUS_GLFUNC(IsNamedStringARB)(GLint(name.size()), name.data());
    OGLPLUS_VERIFY_SIMPLE(IsNamedStringARB, always);
    return {boolean(result)};
}
//------------------------------------------------------------------------------
inline outcome<void> named_string_state::get_named_string_iv(
  string_view name, named_string_param param, span<GLint> values) noexcept {
    EAGINE_ASSERT(values.size() > 0);
    OGLPLUS_GLFUNC(GetNamedStringivARB)
    (GLint(name.size()), name.data(), GLenum(param), values.data());
    OGLPLUS_VERIFY_SIMPLE(GetNamedStringivARB, always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<GLint> named_string_state::get_named_string_length(
  string_view name) noexcept {
    GLint result = 0;
    return get_named_string_iv(
             name, named_string_param(GL_NAMED_STRING_LENGTH_ARB), {&result, 1})
      .add(result);
}
//------------------------------------------------------------------------------
inline outcome<named_string_type> named_string_state::get_named_string_type(
  string_view name) noexcept {
    GLint result = 0;
    return get_named_string_iv(
             name, named_string_param(GL_NAMED_STRING_TYPE_ARB), {&result, 1})
      .add(oglplus::named_string_type(GLenum(result)));
}
//------------------------------------------------------------------------------
inline outcome<GLint> named_string_state::get_named_string(
  string_view name, span<GLchar> buf) noexcept {
    GLint reallen = 0;
    OGLPLUS_GLFUNC(GetNamedStringARB)
    (GLint(name.size()),
     name.data(),
     GLsizei(buf.size()),
     &reallen,
     buf.data());
    OGLPLUS_VERIFY_SIMPLE(GetNamedStringARB, always);
    return {reallen};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
#endif
