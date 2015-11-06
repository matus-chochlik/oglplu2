/**
 *  @file oglplus/path_nv.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::path_nv>::
_gen(array_view<GLuint> names)
noexcept
{
	GLuint base = OGLPLUS_GLFUNC(GenPathsNV)(GLsizei(names.size()));
	for(std::size_t i=0; i<names.size(); ++i)
	{
		names[i] = base+GLuint(i);
	}
	OGLPLUS_VERIFY_SIMPLE(GenPathsNV,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::path_nv>::
_delete(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeletePathsNV)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeletePathsNV,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::path_nv>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsPathNV)(name);
	OGLPLUS_VERIFY_SIMPLE(IsPathNV,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
