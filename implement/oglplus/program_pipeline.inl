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
inline
outcome<program_pipeline_name>
program_pipeline_ops::
program_pipeline_binding(void)
noexcept
{
#ifdef GL_PROGRAM_PIPELINE_BINDING
	GLint result;
	return numeric_queries::get_integer_v(
		binding_query(GL_PROGRAM_PIPELINE_BINDING),
		{&result, 1}
	), program_pipeline_name(GLuint(result));
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
	array_view<GLint> values
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
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::program_pipeline>::
_gen(array_view<GLuint> names)
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
_delete(array_view<GLuint> names)
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
//------------------------------------------------------------------------------
} // namespace oglplus
