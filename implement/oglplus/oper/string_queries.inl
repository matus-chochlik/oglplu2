/**
 *  @file oglplus/oper/string_queries.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline outcome<cstr_ref>
string_queries::get_string(string_query query) noexcept {
    const GLubyte* result = OGLPLUS_GLFUNC(GetString)(GLenum(query));
    OGLPLUS_VERIFY(GetString, gl_enum_value(query), always);
    return {cstr_ref(reinterpret_cast<const char*>(result))};
}
//------------------------------------------------------------------------------
inline outcome<cstr_ref>
string_queries::get_string(string_query query, GLuint index) noexcept {
    const GLubyte* result = OGLPLUS_GLFUNC(GetStringi)(GLenum(query), index);
    OGLPLUS_VERIFY(GetStringi, gl_enum_value(query).gl_index(index), always);
    return {cstr_ref(reinterpret_cast<const char*>(result))};
}
//------------------------------------------------------------------------------
inline outcome<cstr_ref>
string_queries::get_extension_name(GLuint index) noexcept {
    return get_string(string_query(GL_EXTENSIONS), index);
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
