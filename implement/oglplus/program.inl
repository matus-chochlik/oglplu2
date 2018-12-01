/**
 *  @file oglplus/program.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/range_algo.hpp>
#include <oglplus/oper/numeric_queries.hpp>
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::attach_shader(program_name prog, shader_name shdr) noexcept {
    OGLPLUS_GLFUNC(AttachShader)(get_raw_name(prog), get_raw_name(shdr));
    OGLPLUS_VERIFY(AttachShader, gl_subject(prog).gl_object(shdr), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::detach_shader(program_name prog, shader_name shdr) noexcept {
    OGLPLUS_GLFUNC(DetachShader)(get_raw_name(prog), get_raw_name(shdr));
    OGLPLUS_VERIFY(DetachShader, gl_subject(prog).gl_object(shdr), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::link_program(program_name prog) noexcept {
    OGLPLUS_GLFUNC(LinkProgram)(get_raw_name(prog));
    OGLPLUS_VERIFY(LinkProgram, gl_object(prog).info_log_of(prog), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::report_program_link_error(program_name prog) noexcept {
    if(!get_program_link_status(prog).value()) {
        OGLPLUS_REPORT_ERROR(
          LinkProgram, GL_INVALID_OPERATION, info_log_of(prog), always);
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::validate_program(program_name prog) noexcept {
    OGLPLUS_GLFUNC(ValidateProgram)(get_raw_name(prog));
    OGLPLUS_VERIFY(ValidateProgram, gl_object(prog).info_log_of(prog), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::report_program_validate_error(program_name prog) noexcept {
    if(!get_program_validate_status(prog).value()) {
        OGLPLUS_REPORT_ERROR(
          ValidateProgram, GL_INVALID_OPERATION, info_log_of(prog), always);
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::use_program(program_name prog) noexcept {
    OGLPLUS_GLFUNC(UseProgram)(get_raw_name(prog));
    OGLPLUS_VERIFY(UseProgram, gl_object(prog).info_log_of(prog), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<program_name>
program_ops::current_program(void) noexcept {
#ifdef GL_CURRENT_PROGRAM
    GLint result = 0;
    return numeric_queries::get_integer_v(
             binding_query(GL_CURRENT_PROGRAM), {&result, 1})
      .add(program_name(GLuint(result)));
#else
    return program_name(0);
#endif
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_1)
inline outcome<void>
program_ops::program_parameter_i(
  program_name prog, program_parameter para, GLint value) noexcept {
    OGLPLUS_GLFUNC(ProgramParameteri)(get_raw_name(prog), GLenum(para), value);
    OGLPLUS_VERIFY(
      ProgramParameteri, gl_enum_value(para).gl_object(prog), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::program_binary_retrievable_hint(
  program_name prog, boolean value) noexcept {
    return program_parameter_i(
      prog,
      program_parameter(GL_PROGRAM_BINARY_RETRIEVABLE_HINT),
      GLboolean(value));
}
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::program_separable(program_name prog, boolean value) noexcept {
    return program_parameter_i(
      prog, program_parameter(GL_PROGRAM_SEPARABLE), GLboolean(value));
}
//------------------------------------------------------------------------------
inline outcome<GLsizei>
program_ops::get_program_binary_length(program_name prog) noexcept {
    return return_program_parameter_i<GLsizei, GLsizei>(
      prog, program_parameter(GL_PROGRAM_BINARY_LENGTH));
}
//------------------------------------------------------------------------------
inline outcome<memory_block>
program_ops::get_program_binary(
  program_name prog, GLenum& format, memory_block dest) noexcept {
    GLsizei reallen = 0;
    OGLPLUS_GLFUNC(GetProgramBinary)
    (get_raw_name(prog), GLsizei(dest.size()), &reallen, &format, dest.data());
    OGLPLUS_VERIFY(GetProgramBinary, gl_object(prog), always);
    return {eagine::ranges::head(dest, reallen)};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::program_binary(
  program_name prog, GLenum format, const_memory_block binary) noexcept {
    OGLPLUS_GLFUNC(ProgramBinary)
    (get_raw_name(prog), format, binary.data(), GLsizei(binary.size()));
    OGLPLUS_VERIFY(ProgramBinary, gl_object(prog), always);
    return {};
}
//------------------------------------------------------------------------------
#endif // GL_VERSION_4_1
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::get_program_iv(
  program_name prog, program_parameter para, span<GLint> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetProgramiv)
    (get_raw_name(prog), GLenum(para), values.data());
    OGLPLUS_VERIFY(GetProgramiv, gl_enum_value(para).gl_object(prog), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename R, typename T>
inline outcome<R>
program_ops::return_program_parameter_i(
  program_name prog, program_parameter parameter) noexcept {
    GLint result = 0;
    return get_program_iv(prog, parameter, {&result, 1}), R(T(result));
}
//------------------------------------------------------------------------------
inline outcome<boolean>
program_ops::get_program_delete_status(program_name prog) noexcept {
    return return_program_parameter_i<boolean, GLboolean>(
      prog, program_parameter(GL_DELETE_STATUS));
}
//------------------------------------------------------------------------------
inline outcome<boolean>
program_ops::get_program_link_status(program_name prog) noexcept {
    return return_program_parameter_i<boolean, GLboolean>(
      prog, program_parameter(GL_LINK_STATUS));
}
//------------------------------------------------------------------------------
inline outcome<boolean>
program_ops::get_program_validate_status(program_name prog) noexcept {
    return return_program_parameter_i<boolean, GLboolean>(
      prog, program_parameter(GL_VALIDATE_STATUS));
}
//------------------------------------------------------------------------------
inline outcome<GLsizei>
program_ops::get_program_info_log_length(program_name prog) noexcept {
    return return_program_parameter_i<GLsizei, GLsizei>(
      prog, program_parameter(GL_INFO_LOG_LENGTH));
}
//------------------------------------------------------------------------------
inline outcome<span<char>>
program_ops::get_program_info_log(program_name prog, span<char> dest) noexcept {
    GLsizei reallen = 0;
    OGLPLUS_GLFUNC(GetProgramInfoLog)
    (get_raw_name(prog), GLsizei(dest.size()), &reallen, dest.data());
    OGLPLUS_VERIFY(GetProgramInfoLog, gl_object(prog), always);
    return {eagine::ranges::head(dest, reallen)};
}
//------------------------------------------------------------------------------
inline outcome<GLuint>
program_ops::get_program_active_attributes(program_name prog) noexcept {
    return return_program_parameter_i<GLuint, GLuint>(
      prog, program_parameter(GL_ACTIVE_ATTRIBUTES));
}
//------------------------------------------------------------------------------
inline outcome<GLsizei>
program_ops::get_program_active_attribute_max_length(
  program_name prog) noexcept {
    return return_program_parameter_i<GLsizei, GLsizei>(
      prog, program_parameter(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH));
}
//------------------------------------------------------------------------------
inline outcome<GLsizei>
program_ops::get_active_attrib(
  program_name prog,
  GLuint index,
  span<char> name,
  GLint& size,
  sl_data_type& type) noexcept {
    GLenum sl_type = GL_NONE;
    GLsizei reallen = 0;
    OGLPLUS_GLFUNC(GetActiveAttrib)
    (get_raw_name(prog),
     index,
     GLsizei(name.size()),
     &reallen,
     &size,
     &sl_type,
     name.data());
    OGLPLUS_VERIFY(GetActiveAttrib, gl_object(prog).gl_index(index), always);
    type = sl_data_type(sl_type);
    return {reallen};
}
//------------------------------------------------------------------------------
inline outcome<GLuint>
program_ops::get_program_active_uniforms(program_name prog) noexcept {
    return return_program_parameter_i<GLuint, GLuint>(
      prog, program_parameter(GL_ACTIVE_UNIFORMS));
}
//------------------------------------------------------------------------------
inline outcome<GLsizei>
program_ops::get_program_active_uniform_max_length(program_name prog) noexcept {
    return return_program_parameter_i<GLsizei, GLsizei>(
      prog, program_parameter(GL_ACTIVE_UNIFORM_MAX_LENGTH));
}
//------------------------------------------------------------------------------
inline outcome<GLsizei>
program_ops::get_active_uniform(
  program_name prog,
  GLuint index,
  span<char> name,
  GLint& size,
  sl_data_type& type) noexcept {
    GLenum sl_type = GL_NONE;
    GLsizei reallen = 0;
    OGLPLUS_GLFUNC(GetActiveUniform)
    (get_raw_name(prog),
     index,
     GLsizei(name.size()),
     &reallen,
     &size,
     &sl_type,
     name.data());
    OGLPLUS_VERIFY(GetActiveUniform, gl_object(prog).gl_index(index), always);
    type = sl_data_type(sl_type);
    return {reallen};
}
//------------------------------------------------------------------------------
#if defined(GL_ACTIVE_ATOMIC_COUNTER_BUFFERS)
inline outcome<GLsizei>
program_ops::get_program_active_atomic_counter_buffers(
  program_name prog) noexcept {
    return return_program_parameter_i<GLsizei, GLsizei>(
      prog, program_parameter(GL_ACTIVE_ATOMIC_COUNTER_BUFFERS));
}
#endif
//------------------------------------------------------------------------------
inline outcome<transform_feedback_mode>
program_ops::get_program_transform_feedback_buffer_mode(
  program_name prog) noexcept {
    return return_program_parameter_i<transform_feedback_mode, GLenum>(
      prog, program_parameter(GL_TRANSFORM_FEEDBACK_BUFFER_MODE));
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_2)
inline outcome<GLsizei>
program_ops::get_program_geometry_vertices_out(program_name prog) noexcept {
    return return_program_parameter_i<GLsizei, GLsizei>(
      prog, program_parameter(GL_GEOMETRY_VERTICES_OUT));
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_2)
inline outcome<primitive_type>
program_ops::get_program_geometry_input_type(program_name prog) noexcept {
    return return_program_parameter_i<primitive_type, GLenum>(
      prog, program_parameter(GL_GEOMETRY_INPUT_TYPE));
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_2)
inline outcome<primitive_type>
program_ops::get_program_geometry_output_type(program_name prog) noexcept {
    return return_program_parameter_i<primitive_type, GLenum>(
      prog, program_parameter(GL_GEOMETRY_OUTPUT_TYPE));
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_3)
inline outcome<compute_work_group_size>
program_ops::get_program_compute_work_group_size(program_name prog) noexcept {
    compute_work_group_size result(0, 0, 0);
    return get_program_iv(
             prog,
             program_parameter(GL_COMPUTE_WORK_GROUP_SIZE),
             {result._v, 3})
      .add(result);
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
program_ops::bind_attrib_location(
  program_name prog, GLuint index, cstr_ref attr_name) noexcept {
    OGLPLUS_GLFUNC(BindAttribLocation)
    (get_raw_name(prog), index, attr_name.data());
    OGLPLUS_VERIFY(BindAttribLocation, gl_object(prog).gl_index(index), always);
    return {};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline deferred_error_handler
obj_gen_del_ops<tag::program>::_gen(span<GLuint> names) noexcept {
    for(auto b = names.begin(), i = b, e = names.end(); i != e; ++i) {
        *i = OGLPLUS_GLFUNC(CreateProgram)();
        GLenum error_code = OGLPLUS_GLFUNC(GetError)();
        if(error_code != GL_NO_ERROR) {
            for(auto j = b; j != i; ++j) {
                OGLPLUS_GLFUNC(DeleteProgram)(*j);
                OGLPLUS_VERIFY_SIMPLE(DeleteProgram, fatal);
            }
            OGLPLUS_RETURN_HANDLER_IF_GL_ERROR(
              error_code,
              gl_library_name("gl").gl_function_name("CreateProgram"),
              debug);
        }
    }
    return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_create
//------------------------------------------------------------------------------
inline deferred_error_handler
obj_gen_del_ops<tag::program>::_create(span<GLuint> names) noexcept {
    return _gen(names);
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline deferred_error_handler
obj_gen_del_ops<tag::program>::_delete(span<GLuint> names) noexcept {
    for(auto& name : names) {
        OGLPLUS_GLFUNC(DeleteProgram)(name);
        OGLPLUS_VERIFY_SIMPLE(DeleteProgram, debug);
    }
    return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline outcome<boolean>
obj_gen_del_ops<tag::program>::_is_a(GLuint name) noexcept {
    GLboolean res = OGLPLUS_GLFUNC(IsProgram)(name);
    OGLPLUS_VERIFY_SIMPLE(IsProgram, debug);
    return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
