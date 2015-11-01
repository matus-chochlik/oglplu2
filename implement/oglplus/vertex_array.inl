/**
 *  @file oglplus/vertex_array.inl
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
outcome<vertex_array_name>
vertex_array_ops::
vertex_array_binding(void)
noexcept
{
#ifdef GL_VERTEX_ARRAY_BINDING
	GLint result;
	return numeric_queries::get_integer_v(
		binding_query(GL_VERTEX_ARRAY_BINDING),
		{&result, 1}
	), vertex_array_name(GLuint(result));
#else
	return vertex_array_name(0);
#endif
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::vertex_array>::
_gen(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(GenVertexArrays)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenVertexArrays,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::vertex_array>::
_delete(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteVertexArrays)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteVertexArrays,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::vertex_array>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsVertexArray)(name);
	OGLPLUS_VERIFY_SIMPLE(IsVertexArray,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
