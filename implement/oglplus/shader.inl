/**
 *  @file oglplus/shader.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>
#include <cassert>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<void>
shader_ops::
shader_source(shader_name shdr, const glsl_source_ref& source)
noexcept
{
	OGLPLUS_GLFUNC(ShaderSource)(
		get_raw_name(shdr),
		source.count(),
		source.parts(),
		source.lengths()
	);
	OGLPLUS_VERIFY(ShaderSource, gl_object(shdr), always);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
shader_ops::
compile_shader(shader_name shdr)
noexcept
{
	OGLPLUS_GLFUNC(CompileShader)(get_raw_name(shdr));
	OGLPLUS_VERIFY(
		CompileShader,
		gl_object(shdr).
		info_log_of(shdr),
		always);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
shader_ops::
report_shader_compile_error(shader_name shdr)
noexcept
{
	if(!shader_compile_status(shdr).value())
	{
		OGLPLUS_REPORT_ERROR(
			CompileShader,
			GL_INVALID_OPERATION,
			info_log_of(shdr),
			always
		);
	}
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
shader_ops::
get_shader_iv(shader_name shdr, shader_parameter para, span<GLint> values)
noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetShaderiv)(
		get_raw_name(shdr),
		GLenum(para),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetShaderiv,
		gl_enum_value(para).
		gl_object(shdr),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<shader_type>
shader_ops::
shader_type(shader_name shdr)
noexcept
{
	GLint result = GL_NONE;
	return get_shader_iv(
		shdr,
		shader_parameter(GL_SHADER_TYPE),
		{&result, 1}
	), oglplus::shader_type(GLenum(result));
}
//------------------------------------------------------------------------------
template <typename R, typename T>
inline
outcome<R>
shader_ops::
return_shader_i(shader_name shdr, shader_parameter parameter)
noexcept
{
	GLint result = 0;
	return get_shader_iv(
		shdr,
		parameter,
		{&result, 1}
	), R(T(result));
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
shader_ops::
shader_delete_status(shader_name shdr)
noexcept
{
	return return_shader_i<boolean, GLboolean>(
		shdr, 
		shader_parameter(GL_DELETE_STATUS)
	);
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
shader_ops::
shader_compile_status(shader_name shdr)
noexcept
{
	return return_shader_i<boolean, GLboolean>(
		shdr, 
		shader_parameter(GL_COMPILE_STATUS)
	);
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
shader_ops::
shader_info_log_length(shader_name shdr)
noexcept
{
	return return_shader_i<GLsizei, GLsizei>(
		shdr, 
		shader_parameter(GL_INFO_LOG_LENGTH)
	);
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
shader_ops::
shader_info_log(shader_name shdr, span<char> dest)
noexcept
{
	GLsizei reallen = 0;
	OGLPLUS_GLFUNC(GetShaderInfoLog)(
		get_raw_name(shdr),
		GLsizei(dest.size()),
		&reallen,
		dest.data()
	);
	OGLPLUS_VERIFY(
		GetShaderInfoLog,
		gl_object(shdr),
		always
	);
	return {reallen};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::shader>::
_gen(span<GLuint> names, shader_type type)
noexcept
{
	for(auto b=names.begin(), i=b, e=names.end(); i!=e; ++i)
	{
		*i = OGLPLUS_GLFUNC(CreateShader)(GLenum(type));
		GLenum error_code = OGLPLUS_GLFUNC(GetError)();
		if(error_code != GL_NO_ERROR)
		{
			for(auto j=b; j!=i; ++j)
			{
				OGLPLUS_GLFUNC(DeleteShader)(*j);
				OGLPLUS_VERIFY_SIMPLE(DeleteShader,fatal);
			}
			OGLPLUS_RETURN_HANDLER_IF_GL_ERROR(
				error_code,
				gl_library_name("gl").
				gl_function_name("CreateShader"),
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
obj_gen_del_ops<tag::shader>::
_delete(span<GLuint> names)
noexcept
{
	for(auto& name : names)
	{
		OGLPLUS_GLFUNC(DeleteShader)(name);
		OGLPLUS_VERIFY_SIMPLE(DeleteShader,debug);
	}
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::shader>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsShader)(name);
	OGLPLUS_VERIFY_SIMPLE(IsShader,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
