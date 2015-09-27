/**
 *  @file oglplus/program.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PROGRAM_1509260923_HPP
#define OGLPLUS_PROGRAM_1509260923_HPP

#include "object/gl_name.hpp"
#include "utils/gl_func.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"

namespace oglplus {
namespace tag {

using program = gl_obj_tag<GL_PROGRAM>;

} // namespace tag

using program_name = object_name<tag::program>;
using program = object_owner<tag::program>;

template <>
struct obj_gen_del_ops<tag::program>
{
	static
	deferred_error_handler
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
			OGLPLUS_GLFUNC(DeleteProgram)(name);
			OGLPLUS_VERIFY_SIMPLE(DeleteProgram,severe);
		}
		return {};
	}

	static
	outcome<bool> _is_a(GLuint name)
	noexcept
	{
		GLboolean res = OGLPLUS_GLFUNC(IsProgram)(name);
		OGLPLUS_VERIFY_SIMPLE(IsProgram,warning);
		return res == GL_TRUE;
	}
};

} // namespace oglplus

#endif // include guard
