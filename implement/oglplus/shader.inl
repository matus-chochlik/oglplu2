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
namespace ctxt {
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
	OGLPLUS_VERIFY(CompileShader, gl_object(shdr), always);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
shader_ops::
get_shader_iv(shader_name shdr, shader_parameter para, array_view<GLint> values)
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
get_shader_type(shader_name shdr)
noexcept
{
	GLint result = GL_NONE;
	return get_shader_iv(
		shdr,
		shader_parameter(GL_SHADER_TYPE),
		{&result, 1}
	), shader_type(GLenum(result));
}
//------------------------------------------------------------------------------
inline
outcome<true_false>
shader_ops::
get_shader_delete_status(shader_name shdr)
noexcept
{
	GLint result = GL_FALSE;
	return get_shader_iv(
		shdr,
		shader_parameter(GL_DELETE_STATUS),
		{&result, 1}
	), true_false(GLboolean(result));
}
//------------------------------------------------------------------------------
inline
outcome<true_false>
shader_ops::
get_shader_compile_status(shader_name shdr)
noexcept
{
	GLint result = GL_FALSE;
	return get_shader_iv(
		shdr,
		shader_parameter(GL_COMPILE_STATUS),
		{&result, 1}
	), true_false(GLboolean(result));
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
shader_ops::
get_shader_info_log_length(shader_name shdr)
noexcept
{
	GLint result = 0;
	return get_shader_iv(
		shdr,
		shader_parameter(GL_INFO_LOG_LENGTH),
		{&result, 1}
	), GLsizei(result);
}
//------------------------------------------------------------------------------
inline
outcome<GLsizei>
shader_ops::
get_shader_info_log(shader_name shdr, array_view<char> dest)
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
} // namespace ctxt
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::shader>::
_gen(array_view<GLuint> names, shader_type type)
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
_delete(array_view<GLuint> names)
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
outcome<bool>
obj_gen_del_ops<tag::shader>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsShader)(name);
	OGLPLUS_VERIFY_SIMPLE(IsShader,debug);
	return res == GL_TRUE;
}
//------------------------------------------------------------------------------
} // namespace oglplus
