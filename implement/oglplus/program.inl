/**
 *  @file oglplus/program.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace ctxt {
//------------------------------------------------------------------------------
inline
outcome<void>
program_ops::
get_program_iv(
	program_name prog,
	program_parameter para,
	array_view<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetProgramiv)(
		get_raw_name(prog),
		GLenum(para),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetProgramiv,
		gl_enum_value(para).
		gl_object(prog),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<true_false>
program_ops::
get_program_delete_status(program_name prog)
noexcept
{
	GLint result = GL_FALSE;
	return get_program_iv(
		prog,
		program_parameter(GL_DELETE_STATUS),
		{&result, 1}
	), true_false(GLboolean(result));
}
//------------------------------------------------------------------------------
inline
outcome<true_false>
program_ops::
get_program_link_status(program_name prog)
noexcept
{
	GLint result = GL_FALSE;
	return get_program_iv(
		prog,
		program_parameter(GL_LINK_STATUS),
		{&result, 1}
	), true_false(GLboolean(result));
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
program_ops::
get_program_info_log_length(program_name prog)
noexcept
{
	GLint result = 0;
	return get_program_iv(
		prog,
		program_parameter(GL_INFO_LOG_LENGTH),
		{&result, 1}
	), GLsizei(result);
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
program_ops::
get_program_info_log(program_name prog, array_view<char> dest)
noexcept
{
	GLsizei reallen = 0;
	OGLPLUS_GLFUNC(GetShaderInfoLog)(
		get_raw_name(prog),
		GLsizei(dest.size()),
		&reallen,
		dest.data()
	);
	OGLPLUS_VERIFY(
		GetShaderInfoLog,
		gl_object(prog),
		always
	);
	return {reallen};
}
//------------------------------------------------------------------------------
} // namespace ctxt
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::program>::
_gen(array_view<GLuint> names)
noexcept
{
	for(auto b=names.begin(), i=b, e=names.end(); i!=e; ++i)
	{
		*i = OGLPLUS_GLFUNC(CreateProgram)();
		GLenum error_code = OGLPLUS_GLFUNC(GetError)();
		if(error_code != GL_NO_ERROR)
		{
			for(auto j=b; j!=i; ++j)
			{
				OGLPLUS_GLFUNC(DeleteProgram)(*j);
				OGLPLUS_VERIFY_SIMPLE(DeleteProgram,fatal);
			}
			OGLPLUS_RETURN_HANDLER_IF_GL_ERROR(
				error_code,
				gl_library_name("gl").
				gl_function_name("CreateProgram"),
				debug
			);
		}
	}
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::program>::
_delete(array_view<GLuint> names)
noexcept
{
	for(auto& name : names)
	{
		OGLPLUS_GLFUNC(DeleteProgram)(name);
		OGLPLUS_VERIFY_SIMPLE(DeleteProgram,debug);
	}
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<bool>
obj_gen_del_ops<tag::program>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsProgram)(name);
	OGLPLUS_VERIFY_SIMPLE(IsProgram,debug);
	return {res == GL_TRUE};
}
//------------------------------------------------------------------------------
} // namespace oglplus
