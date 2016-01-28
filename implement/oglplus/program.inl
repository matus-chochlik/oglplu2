/**
 *  @file oglplus/program.inl
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
outcome<void>
program_ops::
attach_shader(program_name prog, shader_name shdr)
noexcept
{
	OGLPLUS_GLFUNC(AttachShader)(
		get_raw_name(prog),
		get_raw_name(shdr)
	);
	OGLPLUS_VERIFY(
		AttachShader,
		gl_subject(prog).
		gl_object(shdr),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
program_ops::
detach_shader(program_name prog, shader_name shdr)
noexcept
{
	OGLPLUS_GLFUNC(DetachShader)(
		get_raw_name(prog),
		get_raw_name(shdr)
	);
	OGLPLUS_VERIFY(
		DetachShader,
		gl_subject(prog).
		gl_object(shdr),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
program_ops::
link_program(program_name prog)
noexcept
{
	OGLPLUS_GLFUNC(LinkProgram)(get_raw_name(prog));
	OGLPLUS_VERIFY(
		LinkProgram,
		gl_object(prog).
		info_log_of(prog),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
program_ops::
report_program_link_error(program_name prog)
noexcept
{
	if(!program_link_status(prog).value())
	{
		OGLPLUS_REPORT_ERROR(
			LinkProgram,
			GL_INVALID_OPERATION,
			info_log_of(prog),
			always
		);
	}
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
program_ops::
use_program(program_name prog)
noexcept
{
	OGLPLUS_GLFUNC(UseProgram)(get_raw_name(prog));
	OGLPLUS_VERIFY(
		UseProgram,
		gl_object(prog).
		info_log_of(prog),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<program_name>
program_ops::
current_program(void)
noexcept
{
#ifdef GL_CURRENT_PROGRAM
	GLint result = 0;
	return numeric_queries::get_integer_v(
		binding_query(GL_CURRENT_PROGRAM),
		{&result, 1}
	), program_name(GLuint(result));
#else
	return program_name(0);
#endif
}
//------------------------------------------------------------------------------
inline
outcome<void>
program_ops::
get_program_iv(
	program_name prog,
	program_parameter para,
	span<GLint> values
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
template <typename R, typename T>
inline
outcome<R>
program_ops::
return_program_parameter_i(program_name prog, program_parameter parameter)
noexcept
{
	GLint result = 0;
	return get_program_iv(
		prog,
		parameter,
		{&result, 1}
	), R(T(result));
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
program_ops::
program_delete_status(program_name prog)
noexcept
{
	return return_program_parameter_i<boolean, GLboolean>(
		prog,
		program_parameter(GL_DELETE_STATUS)
	);
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
program_ops::
program_link_status(program_name prog)
noexcept
{
	return return_program_parameter_i<boolean, GLboolean>(
		prog,
		program_parameter(GL_LINK_STATUS)
	);
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
program_ops::
program_info_log_length(program_name prog)
noexcept
{
	return return_program_parameter_i<GLsizei, GLsizei>(
		prog,
		program_parameter(GL_INFO_LOG_LENGTH)
	);
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
program_ops::
program_info_log(program_name prog, span<char> dest)
noexcept
{
	GLsizei reallen = 0;
	OGLPLUS_GLFUNC(GetProgramInfoLog)(
		get_raw_name(prog),
		GLsizei(dest.size()),
		&reallen,
		dest.data()
	);
	OGLPLUS_VERIFY(
		GetProgramInfoLog,
		gl_object(prog),
		always
	);
	return {reallen};
}
//------------------------------------------------------------------------------
inline
outcome<GLuint>
program_ops::
program_active_attributes(program_name prog)
noexcept
{
	return return_program_parameter_i<GLuint, GLuint>(
		prog,
		program_parameter(GL_ACTIVE_ATTRIBUTES)
	);
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
program_ops::
program_active_attribute_max_length(program_name prog)
noexcept
{
	return return_program_parameter_i<GLsizei, GLsizei>(
		prog,
		program_parameter(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH)
	);
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
program_ops::
get_active_attrib(
	program_name prog,
	GLuint index,
	span<char> name,
	GLint& size,
	sl_data_type& type
) noexcept
{
	GLenum sl_type = GL_NONE;
	GLsizei reallen = 0;
	OGLPLUS_GLFUNC(GetActiveAttrib)(
		get_raw_name(prog),
		index,
		GLsizei(name.size()),
		&reallen,
		&size,
		&sl_type,
		name.data()
	);
	OGLPLUS_VERIFY(
		GetActiveAttrib,
		gl_object(prog).
		gl_index(index),
		always
	);
	type = sl_data_type(sl_type);
	return {reallen};
}
//------------------------------------------------------------------------------
inline
outcome<GLuint>
program_ops::
program_active_uniforms(program_name prog)
noexcept
{
	return return_program_parameter_i<GLuint, GLuint>(
		prog,
		program_parameter(GL_ACTIVE_UNIFORMS)
	);
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
program_ops::
program_active_uniform_max_length(program_name prog)
noexcept
{
	return return_program_parameter_i<GLsizei, GLsizei>(
		prog,
		program_parameter(GL_ACTIVE_UNIFORM_MAX_LENGTH)
	);
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
program_ops::
get_active_uniform(
	program_name prog,
	GLuint index,
	span<char> name,
	GLint& size,
	sl_data_type& type
) noexcept
{
	GLenum sl_type = GL_NONE;
	GLsizei reallen = 0;
	OGLPLUS_GLFUNC(GetActiveUniform)(
		get_raw_name(prog),
		index,
		GLsizei(name.size()),
		&reallen,
		&size,
		&sl_type,
		name.data()
	);
	OGLPLUS_VERIFY(
		GetActiveUniform,
		gl_object(prog).
		gl_index(index),
		always
	);
	type = sl_data_type(sl_type);
	return {reallen};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::program>::
_gen(span<GLuint> names)
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
_delete(span<GLuint> names)
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
outcome<boolean>
obj_gen_del_ops<tag::program>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsProgram)(name);
	OGLPLUS_VERIFY_SIMPLE(IsProgram,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
