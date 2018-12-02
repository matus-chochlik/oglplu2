/**
 *  @file oglplus/program_pipeline.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/oper/numeric_queries.hpp>
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
inline outcome<void>
program_pipeline_ops::bind_program_pipeline(
  program_pipeline_name ppo) noexcept {
    OGLPLUS_GLFUNC(BindProgramPipeline)(get_raw_name(ppo));
    OGLPLUS_VERIFY(BindProgramPipeline, gl_object(ppo), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_pipeline_ops::use_program_stages(
  program_pipeline_name ppl,
  enum_bitfield<program_pipeline_stage> stages,
  program_name prog) noexcept {
    OGLPLUS_GLFUNC(UseProgramStages)
    (get_raw_name(ppl), GLbitfield(stages), get_raw_name(prog));
    OGLPLUS_VERIFY(UseProgramStages, gl_subject(prog).gl_object(ppl), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_pipeline_ops::active_shader_program(
  program_pipeline_name ppl, program_name prog) noexcept {
    OGLPLUS_GLFUNC(ActiveShaderProgram)(get_raw_name(ppl), get_raw_name(prog));
    OGLPLUS_VERIFY(
      ActiveShaderProgram, gl_subject(prog).gl_object(ppl), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_pipeline_ops::validate_program_pipeline(
  program_pipeline_name ppl) noexcept {
    OGLPLUS_GLFUNC(ValidateProgram)(get_raw_name(ppl));
    OGLPLUS_VERIFY(
      ValidateProgramPipeline, gl_object(ppl).info_log_of(ppl), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
program_pipeline_ops::report_program_pipeline_validate_error(
  program_pipeline_name ppl) noexcept {
    if(!get_program_pipeline_validate_status(ppl).value()) {
        OGLPLUS_REPORT_ERROR(
          ValidateProgramPipeline,
          GL_INVALID_OPERATION,
          info_log_of(ppl),
          always);
    }
    return {};
}
//------------------------------------------------------------------------------
inline outcome<program_pipeline_name>
program_pipeline_ops::program_pipeline_binding() noexcept {
#ifdef GL_PROGRAM_PIPELINE_BINDING
    GLint result = 0;
    return numeric_queries::get_integer_v(
             binding_query(GL_PROGRAM_PIPELINE_BINDING), {&result, 1})
      .add(program_pipeline_name(GLuint(result)));
#else
    return program_pipeline_name(0);
#endif
}
//------------------------------------------------------------------------------
inline outcome<void>
program_pipeline_ops::get_program_pipeline_iv(
  program_pipeline_name buf,
  oglplus::program_pipeline_parameter param,
  span<GLint> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetProgramPipelineiv)
    (get_raw_name(buf), GLenum(param), values.data());
    OGLPLUS_VERIFY(
      GetProgramPipelineiv, gl_object(buf).gl_enum_value(param), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename R, typename T>
inline outcome<R>
program_pipeline_ops::return_program_pipeline_i(
  program_pipeline_name ppl, program_pipeline_parameter parameter) noexcept {
    GLint result = 0;
    return get_program_pipeline_iv(ppl, parameter, {&result, 1}), R(T(result));
}
//------------------------------------------------------------------------------
inline outcome<boolean>
program_pipeline_ops::get_program_pipeline_validate_status(
  program_pipeline_name ppl) noexcept {
    return return_program_pipeline_i<boolean, GLboolean>(
      ppl, program_pipeline_parameter(GL_VALIDATE_STATUS));
}
//------------------------------------------------------------------------------
inline outcome<program_name>
program_pipeline_ops::get_program_pipeline_active_program(
  program_pipeline_name ppl) noexcept {
    return return_program_pipeline_i<program_name, GLuint>(
      ppl, program_pipeline_parameter(GL_ACTIVE_PROGRAM));
}
//------------------------------------------------------------------------------
inline outcome<GLsizei>
program_pipeline_ops::get_program_pipeline_info_log_length(
  program_pipeline_name ppl) noexcept {
    return return_program_pipeline_i<GLsizei, GLsizei>(
      ppl, program_pipeline_parameter(GL_INFO_LOG_LENGTH));
}
//------------------------------------------------------------------------------
inline outcome<span<char>>
program_pipeline_ops::get_program_pipeline_info_log(
  program_pipeline_name ppl, span<char> dest) noexcept {
    GLsizei reallen = 0;
    OGLPLUS_GLFUNC(GetProgramPipelineInfoLog)
    (get_raw_name(ppl), GLsizei(dest.size()), &reallen, dest.data());
    OGLPLUS_VERIFY(GetProgramPipelineInfoLog, gl_object(ppl), always);
    return {eagine::ranges::head(dest, reallen)};
}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
inline deferred_error_handler
obj_gen_del_ops<tag::program_pipeline>::_gen(span<GLuint> names) noexcept {
    OGLPLUS_GLFUNC(GenProgramPipelines)(GLsizei(names.size()), names.data());
    OGLPLUS_VERIFY_SIMPLE(GenProgramPipelines, debug);
    return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_create
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5)
inline deferred_error_handler
obj_gen_del_ops<tag::program_pipeline>::_create(span<GLuint> names) noexcept {
    OGLPLUS_GLFUNC(CreateProgramPipelines)(GLsizei(names.size()), names.data());
    OGLPLUS_VERIFY_SIMPLE(CreateProgramPipelines, debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline deferred_error_handler
obj_gen_del_ops<tag::program_pipeline>::_delete(span<GLuint> names) noexcept {
    OGLPLUS_GLFUNC(DeleteProgramPipelines)(GLsizei(names.size()), names.data());
    OGLPLUS_VERIFY_SIMPLE(DeleteProgramPipelines, debug);
    return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline outcome<boolean>
obj_gen_del_ops<tag::program_pipeline>::_is_a(GLuint name) noexcept {
    GLboolean res = OGLPLUS_GLFUNC(IsProgramPipeline)(name);
    OGLPLUS_VERIFY_SIMPLE(IsProgramPipeline, debug);
    return boolean(res);
}
#endif
//------------------------------------------------------------------------------
} // namespace oglplus
