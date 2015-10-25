/**
 *  @file oglplus/buffer.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>
#include <oglplus/oper/numeric_queries.hpp>

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include "enum/buffer_target_bq.inl"
#endif
//------------------------------------------------------------------------------
namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<buffer_name>
buffer_ops::
buffer_binding(buffer_target target)
noexcept
{
	GLint result;
	return numeric_queries::get_integer_v(
		get_binding_query(target),
		{&result, 1}
	), buffer_name(GLuint(result));
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::buffer>::
_gen(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(GenBuffers)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenBuffers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::buffer>::
_delete(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteBuffers)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteBuffers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<bool>
obj_gen_del_ops<tag::buffer>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsBuffer)(name);
	OGLPLUS_VERIFY_SIMPLE(IsBuffer,debug);
	return res == GL_TRUE;
}
//------------------------------------------------------------------------------
} // namespace oglplus

