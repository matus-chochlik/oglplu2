/**
 *  @file oglplus/shader.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/span_algo.hpp>
#include <oglplus/utils/gl_func.hpp>
#include <cassert>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_1)
inline outcome<void> shader_ops::release_shader_compiler() noexcept {
    OGLPLUS_GLFUNC(ReleaseShaderCompiler)();
    OGLPLUS_VERIFY_SIMPLE(ShaderSource, always);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void> shader_ops::shader_source(
  shader_name shdr, const glsl_source_ref& source) noexcept {
    OGLPLUS_GLFUNC(ShaderSource)
    (get_raw_name(shdr), source.count(), source.parts(), source.lengths());
    OGLPLUS_VERIFY(ShaderSource, gl_object(shdr), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> shader_ops::compile_shader(shader_name shdr) noexcept {
    OGLPLUS_GLFUNC(CompileShader)(get_raw_name(shdr));
    OGLPLUS_VERIFY(CompileShader, gl_object(shdr).info_log_of(shdr), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> shader_ops::report_shader_compile_error(
  shader_name shdr) noexcept {
    if(!get_shader_compile_status(shdr).value()) {
        OGLPLUS_REPORT_ERROR(
          CompileShader, GL_INVALID_OPERATION, info_log_of(shdr), always);
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> shader_ops::get_shader_iv(
  shader_name shdr, shader_parameter para, span<GLint> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetShaderiv)
    (get_raw_name(shdr), GLenum(para), values.data());
    OGLPLUS_VERIFY(GetShaderiv, gl_enum_value(para).gl_object(shdr), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename R, typename T>
inline outcome<R> shader_ops::return_shader_i(
  shader_name shdr, shader_parameter parameter) noexcept {
    GLint result = 0;
    return get_shader_iv(shdr, parameter, {&result, 1}).add(R(T(result)));
}
//------------------------------------------------------------------------------
inline outcome<shader_type> shader_ops::get_shader_type(
  shader_name shdr) noexcept {
    GLint result = GL_NONE;
    return get_shader_iv(shdr, shader_parameter(GL_SHADER_TYPE), {&result, 1})
      .add(oglplus::shader_type(GLenum(result)));
}
//------------------------------------------------------------------------------
inline outcome<boolean> shader_ops::get_shader_delete_status(
  shader_name shdr) noexcept {
    return return_shader_i<boolean, GLboolean>(
      shdr, shader_parameter(GL_DELETE_STATUS));
}
//------------------------------------------------------------------------------
inline outcome<boolean> shader_ops::get_shader_compile_status(
  shader_name shdr) noexcept {
    return return_shader_i<boolean, GLboolean>(
      shdr, shader_parameter(GL_COMPILE_STATUS));
}
//------------------------------------------------------------------------------
inline outcome<GLsizei> shader_ops::get_shader_source_length(
  shader_name shdr) noexcept {
    return return_shader_i<GLsizei, GLsizei>(
      shdr, shader_parameter(GL_SHADER_SOURCE_LENGTH));
}
//------------------------------------------------------------------------------
inline outcome<span<char>> shader_ops::get_shader_source(
  shader_name shdr, span<char> dest) noexcept {
    GLsizei reallen = 0;
    OGLPLUS_GLFUNC(GetShaderSource)
    (get_raw_name(shdr), GLsizei(dest.size()), &reallen, dest.data());
    OGLPLUS_VERIFY(GetShaderSource, gl_object(shdr), always);
    return {head(dest, reallen)};
}
//------------------------------------------------------------------------------
inline outcome<GLsizei> shader_ops::get_shader_info_log_length(
  shader_name shdr) noexcept {
    return return_shader_i<GLsizei, GLsizei>(
      shdr, shader_parameter(GL_INFO_LOG_LENGTH));
}
//------------------------------------------------------------------------------
inline outcome<span<char>> shader_ops::get_shader_info_log(
  shader_name shdr, span<char> dest) noexcept {
    GLsizei reallen = 0;
    OGLPLUS_GLFUNC(GetShaderInfoLog)
    (get_raw_name(shdr), GLsizei(dest.size()), &reallen, dest.data());
    OGLPLUS_VERIFY(GetShaderInfoLog, gl_object(shdr), always);
    return {head(dest, reallen)};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline deferred_error_handler obj_gen_del_ops<tag::shader>::_gen(
  span<GLuint> names, shader_type type) noexcept {
    for(auto b = names.begin(), i = b, e = names.end(); i != e; ++i) {
        *i = OGLPLUS_GLFUNC(CreateShader)(GLenum(type));
        GLenum error_code = OGLPLUS_GLFUNC(GetError)();
        if(error_code != GL_NO_ERROR) {
            for(auto j = b; j != i; ++j) {
                OGLPLUS_GLFUNC(DeleteShader)(*j);
                OGLPLUS_VERIFY_SIMPLE(DeleteShader, fatal);
            }
            OGLPLUS_RETURN_HANDLER_IF_GL_ERROR(
              error_code,
              gl_library_name("gl")
                .gl_function_name("CreateShader")
                .gl_enum_value(type),
              debug);
        }
    }
    return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline deferred_error_handler obj_gen_del_ops<tag::shader>::_create(
  shader_type type, span<GLuint> names) noexcept {
    return _gen(names, type);
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline deferred_error_handler obj_gen_del_ops<tag::shader>::_delete(
  span<GLuint> names) noexcept {
    for(auto& name : names) {
        OGLPLUS_GLFUNC(DeleteShader)(name);
        OGLPLUS_VERIFY_SIMPLE(DeleteShader, debug);
    }
    return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline outcome<boolean> obj_gen_del_ops<tag::shader>::_is_a(
  GLuint name) noexcept {
    GLboolean res = OGLPLUS_GLFUNC(IsShader)(name);
    OGLPLUS_VERIFY_SIMPLE(IsShader, debug);
    return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
