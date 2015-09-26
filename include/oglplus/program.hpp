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

namespace oglplus {
namespace tag {

using program = gl_obj_tag<GL_PROGRAM>;

} // namespace tag

using program_name = object_name<tag::program>;

template <>
struct obj_gen_del_ops<tag::program>
{
	deferred_error_handler
	static
	_gen(std::size_t count, GLuint* names)
	noexcept
	{
		assert(names != nullptr);

		for(std::size_t i=0; i<count; ++i)
		{
			names[i] = OGLPLUS_GLFUNC(CreateProgram)();
			GLenum error_code = OGLPLUS_GLFUNC(GetError)();
			if(error_code != GL_NO_ERROR)
			{
				for(std::size_t j=0; j<i; ++j)
				{
					OGLPLUS_GLFUNC(DeleteProgram)(names[j]);
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

	deferred_error_handler
	static
	_delete(std::size_t count, GLuint* names)
	noexcept
	{
		assert(names != nullptr);

		for(std::size_t i=0; i<count; ++i)
		{
			OGLPLUS_GLFUNC(DeleteProgram)(names[i]);
			OGLPLUS_VERIFY_SIMPLE(DeleteProgram,severe);
		}
		return {};
	}
};

} // namespace oglplus

#endif // include guard
