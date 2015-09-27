/**
 *  @file oglplus/shader.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_SHADER_1509260923_HPP
#define OGLPLUS_SHADER_1509260923_HPP

#include "object/gl_name.hpp"
#include "utils/gl_func.hpp"
#include "error/handling.hpp"
#include "enum_types.hpp"

namespace oglplus {
namespace tag {

using shader = gl_obj_tag<GL_SHADER>;

} // namespace tag

using shader_name = object_name<tag::shader>;
using shader = object_owner<tag::shader>;

template <>
struct object_subtype<tag::shader>
{
	typedef shader_type type;
};

template <>
struct obj_gen_del_ops<tag::shader>
{
	static
	deferred_error_handler
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
					severe
				);
			}
		}
		return {};
	}

	static
	deferred_error_handler
	_delete(array_view<GLuint> names)
	noexcept
	{
		for(auto& name : names)
		{
			OGLPLUS_GLFUNC(DeleteShader)(name);
			OGLPLUS_VERIFY_SIMPLE(DeleteShader,severe);
		}
		return {};
	}

	static
	outcome<bool> _is_a(GLuint name)
	noexcept
	{
		GLboolean res = OGLPLUS_GLFUNC(IsShader)(name);
		OGLPLUS_VERIFY_SIMPLE(IsShader,warning);
		return res == GL_TRUE;
	}
};

} // namespace oglplus

#endif // include guard
