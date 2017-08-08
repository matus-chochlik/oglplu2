/**
 *  @file oglplus/program_pipeline.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>
#include <oglplus/oper/numeric_queries.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
inline
outcome<void>
program_pipeline_ops::
bind_program_pipeline(program_pipeline_name ppo)
noexcept
{
	OGLPLUS_GLFUNC(BindProgramPipeline)(get_raw_name(ppo));
	OGLPLUS_VERIFY(BindProgramPipeline, gl_object(ppo), debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<program_pipeline_name>
program_pipeline_ops::
program_pipeline_binding(void)
noexcept
{
#ifdef GL_PROGRAM_PIPELINE_BINDING
	GLint result = 0;
	return numeric_queries::get_integer_v(
		binding_query(GL_PROGRAM_PIPELINE_BINDING),
		{&result, 1}
	).add(program_pipeline_name(GLuint(result)));
#else
	return program_pipeline_name(0);
#endif
}
//------------------------------------------------------------------------------
inline
outcome<void>
program_pipeline_ops::
get_program_pipeline_iv(
	program_pipeline_name buf,
	oglplus::program_pipeline_parameter param,
	span<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetProgramPipelineiv)(
		get_raw_name(buf),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetProgramPipelineiv,
		gl_object(buf).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
template <typename R, typename T>
inline
outcome<R>
program_pipeline_ops::
return_program_pipeline_i(
	program_pipeline_name ppl,
	program_pipeline_parameter parameter
) noexcept
{
	GLint result = 0;
	return get_program_pipeline_iv(
		ppl,
		parameter,
		{&result, 1}
	), R(T(result));
}
//------------------------------------------------------------------------------
inline
outcome<program_name>
program_pipeline_ops::
program_pipeline_active_program(program_pipeline_name ppl)
noexcept
{
	return return_program_pipeline_i<program_name, GLuint>(
		ppl,
		program_pipeline_parameter(GL_ACTIVE_PROGRAM)
	);
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
program_pipeline_ops::
program_pipeline_info_log_length(program_pipeline_name ppl)
noexcept
{
	return return_program_pipeline_i<GLsizei, GLsizei>(
		ppl,
		program_pipeline_parameter(GL_INFO_LOG_LENGTH)
	);
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
inline
deferred_error_handler
obj_gen_del_ops<tag::program_pipeline>::
_gen(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(GenProgramPipelines)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenProgramPipelines,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::program_pipeline>::
_delete(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteProgramPipelines)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteProgramPipelines,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::program_pipeline>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsProgramPipeline)(name);
	OGLPLUS_VERIFY_SIMPLE(IsProgramPipeline,debug);
	return boolean(res);
}
#endif
//------------------------------------------------------------------------------
} // namespace oglplus
