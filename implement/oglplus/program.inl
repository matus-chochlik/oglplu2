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
				severe
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
		OGLPLUS_VERIFY_SIMPLE(DeleteProgram,severe);
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
	OGLPLUS_VERIFY_SIMPLE(IsProgram,warning);
	return {res == GL_TRUE};
}
//------------------------------------------------------------------------------
} // namespace oglplus
