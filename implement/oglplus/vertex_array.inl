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
outcome<void>
vertex_array_ops::
bind_vertex_array(vertex_array_name vao)
noexcept
{
	OGLPLUS_GLFUNC(BindVertexArray)(get_raw_name(vao));
	OGLPLUS_VERIFY(BindVertexArray, gl_object(vao), debug);
	return {};
}
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
inline
outcome<void>
vertex_array_ops::
enable_vertex_array_attrib(vertex_attrib_location va)
noexcept
{
	OGLPLUS_GLFUNC(EnableVertexAttribArray)(va.index());
	OGLPLUS_VERIFY(
		EnableVertexAttribArray,
		gl_index(va.index()),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
disable_vertex_array_attrib(vertex_attrib_location va)
noexcept
{
	OGLPLUS_GLFUNC(DisableVertexAttribArray)(va.index());
	OGLPLUS_VERIFY(
		DisableVertexAttribArray,
		gl_index(va.index()),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<void>
vertex_array_ops::
enable_vertex_array_attrib(vertex_array_name vao, vertex_attrib_location va)
noexcept
{
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(EnableVertexArrayAttrib)(
#else
	OGLPLUS_GLFUNC(EnableVertexArrayAttribEXT)(
#endif
		get_raw_name(vao),
		va.index()
	);
	OGLPLUS_VERIFY_STR(
		OGLPLUS_GL_DSA_FUNC_NAME(EnableVertexArrayAttrib),
		gl_object(vao).
		gl_index(va.index()),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
disable_vertex_array_attrib(vertex_array_name vao, vertex_attrib_location va)
noexcept
{
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(DisableVertexArrayAttrib)(
#else
	OGLPLUS_GLFUNC(DisableVertexArrayAttribEXT)(
#endif
		get_raw_name(vao),
		va.index()
	);
	OGLPLUS_VERIFY_STR(
		OGLPLUS_GL_DSA_FUNC_NAME(DisableVertexArrayAttrib),
		gl_object(vao).
		gl_index(va.index()),
		always
	);
	return {};
}
#endif
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
