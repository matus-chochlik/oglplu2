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
noexcept {
	OGLPLUS_GLFUNC(BindVertexArray)(get_raw_name(vao));
	OGLPLUS_VERIFY(BindVertexArray, gl_object(vao), debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<vertex_array_name>
vertex_array_ops::
vertex_array_binding(void)
noexcept {
#ifdef GL_VERTEX_ARRAY_BINDING
	GLint result = 0;
	return numeric_queries::get_integer_v(
		binding_query(GL_VERTEX_ARRAY_BINDING),
		{&result, 1}
	).add(vertex_array_name(GLuint(result)));
#else
	return vertex_array_name(0);
#endif
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
enable_vertex_array_attrib(vertex_attrib_location va)
noexcept {
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
noexcept {
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
noexcept {
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
noexcept {
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
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_pointer(
	vertex_attrib_location loc,
	GLint values_per_vertex,
	data_type type,
	boolean normalized,
	GLsizei stride,
	const void* pointer
) noexcept {
	OGLPLUS_GLFUNC(VertexAttribPointer)(
		loc.index(),
		values_per_vertex,
		GLenum(type),
		normalized,
		stride,
		pointer
	);
	OGLPLUS_VERIFY(
		VertexAttribPointer,
		gl_enum_value(type).
		gl_index(loc.index()),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_i_pointer(
	vertex_attrib_location loc,
	GLint values_per_vertex,
	data_type type,
	GLsizei stride,
	const void* pointer
) noexcept {
	OGLPLUS_GLFUNC(VertexAttribIPointer)(
		loc.index(),
		values_per_vertex,
		GLenum(type),
		stride,
		pointer
	);
	OGLPLUS_VERIFY(
		VertexAttribIPointer,
		gl_enum_value(type).
		gl_index(loc.index()),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_3) || defined(GL_ARB_vertex_attrib_binding)
inline
outcome<void>
vertex_array_ops::
vertex_array_vertex_buffer(
	GLuint binding_index,
	buffer_name buf,
	buffer_size offset,
	buffer_size stride
) noexcept {
	OGLPLUS_GLFUNC(BindVertexBuffer)(
		binding_index,
		get_raw_name(buf),
		GLintptr(offset),
		GLsizei(stride)
	);
	OGLPLUS_VERIFY(
		BindVertexBuffer,
		gl_subject(buf).
		gl_index(binding_index),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_binding(
	vertex_attrib_location loc,
	GLuint binding_index
) noexcept {
	OGLPLUS_GLFUNC(VertexAttribBinding)(
		loc.index(),
		binding_index
	);
	OGLPLUS_VERIFY(
		VertexAttribBinding,
		gl_index(binding_index),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_binding_divisor(
	GLuint binding_index,
	GLuint divisor
) noexcept {
	OGLPLUS_GLFUNC(VertexBindingDivisor)(
		binding_index,
		divisor
	);
	OGLPLUS_VERIFY(
		VertexBindingDivisor,
		gl_index(binding_index),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_format(
	vertex_attrib_location loc,
	GLint values_per_vertex,
	data_type type,
	boolean normalized,
	GLuint relative_offset
) noexcept {
	OGLPLUS_GLFUNC(VertexAttribFormat)(
		loc.index(),
		values_per_vertex,
		GLenum(type),
		normalized,
		relative_offset
	);
	OGLPLUS_VERIFY(
		VertexAttribFormat,
		gl_enum_value(type).
		gl_index(loc.index()),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_i_format(
	vertex_attrib_location loc,
	GLint values_per_vertex,
	data_type type,
	GLuint relative_offset
) noexcept {
	OGLPLUS_GLFUNC(VertexAttribIFormat)(
		loc.index(),
		values_per_vertex,
		GLenum(type),
		relative_offset
	);
	OGLPLUS_VERIFY(
		VertexAttribIFormat,
		gl_enum_value(type).
		gl_index(loc.index()),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_l_format(
	vertex_attrib_location loc,
	GLint values_per_vertex,
	data_type type,
	GLuint relative_offset
) noexcept {
	OGLPLUS_GLFUNC(VertexAttribLFormat)(
		loc.index(),
		values_per_vertex,
		GLenum(type),
		relative_offset
	);
	OGLPLUS_VERIFY(
		VertexAttribLFormat,
		gl_enum_value(type).
		gl_index(loc.index()),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5)
inline
outcome<void>
vertex_array_ops::
vertex_array_vertex_buffer(
	vertex_array_name vao,
	vertex_attrib_location loc,
	buffer_name buf,
	GLintptr offset,
	GLsizei stride
) noexcept {
	OGLPLUS_GLFUNC(VertexArrayVertexBuffer)(
		get_raw_name(vao),
		loc.index(),
		get_raw_name(buf),
		offset,
		stride
	);
	OGLPLUS_VERIFY(
		VertexArrayVertexBuffer,
		gl_object(vao).
		gl_subject(buf).
		gl_index(loc.index()),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_vertex_buffer(
	vertex_array_name vao,
	GLuint binding_index,
	buffer_name buf,
	buffer_size offset,
	buffer_size stride
) noexcept {
	OGLPLUS_GLFUNC(VertexArrayVertexBuffer)(
		get_raw_name(vao),
		binding_index,
		get_raw_name(buf),
		GLintptr(offset),
		GLsizei(stride)
	);
	OGLPLUS_VERIFY(
		VertexArrayVertexBuffer,
		gl_subject(buf).
		gl_object(vao).
		gl_index(binding_index),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_binding(
	vertex_array_name vao,
	vertex_attrib_location loc,
	GLuint binding_index
) noexcept {
	OGLPLUS_GLFUNC(VertexArrayAttribBinding)(
		get_raw_name(vao),
		loc.index(),
		binding_index
	);
	OGLPLUS_VERIFY(
		VertexArrayAttribBinding,
		gl_object(vao).
		gl_index(binding_index),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_binding_divisor(
	vertex_array_name vao,
	GLuint binding_index,
	GLuint divisor
) noexcept {
	OGLPLUS_GLFUNC(VertexArrayBindingDivisor)(
		get_raw_name(vao),
		binding_index,
		divisor
	);
	OGLPLUS_VERIFY(
		VertexArrayBindingDivisor,
		gl_object(vao).
		gl_index(binding_index),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_format(
	vertex_array_name vao,
	vertex_attrib_location loc,
	GLint values_per_vertex,
	data_type type,
	boolean normalized,
	GLuint relative_offset
) noexcept {
	OGLPLUS_GLFUNC(VertexArrayAttribFormat)(
		get_raw_name(vao),
		loc.index(),
		values_per_vertex,
		GLenum(type),
		normalized,
		relative_offset
	);
	OGLPLUS_VERIFY(
		VertexAttribFormat,
		gl_object(vao).
		gl_enum_value(type).
		gl_index(loc.index()),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_i_format(
	vertex_array_name vao,
	vertex_attrib_location loc,
	GLint values_per_vertex,
	data_type type,
	GLuint relative_offset
) noexcept {
	OGLPLUS_GLFUNC(VertexArrayAttribIFormat)(
		get_raw_name(vao),
		loc.index(),
		values_per_vertex,
		GLenum(type),
		relative_offset
	);
	OGLPLUS_VERIFY(
		VertexAttribIFormat,
		gl_object(vao).
		gl_enum_value(type).
		gl_index(loc.index()),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_l_format(
	vertex_array_name vao,
	vertex_attrib_location loc,
	GLint values_per_vertex,
	data_type type,
	GLuint relative_offset
) noexcept {
	OGLPLUS_GLFUNC(VertexArrayAttribLFormat)(
		get_raw_name(vao),
		loc.index(),
		values_per_vertex,
		GLenum(type),
		relative_offset
	);
	OGLPLUS_VERIFY(
		VertexAttribLFormat,
		gl_object(vao).
		gl_enum_value(type).
		gl_index(loc.index()),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_EXT_direct_state_access)
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_offset(
	vertex_array_name vao,
	buffer_name buf,
	vertex_attrib_location loc,
	GLint values_per_vertex,
	data_type type,
	boolean normalized,
	GLsizei stride,
	GLintptr offset
) noexcept {
	OGLPLUS_GLFUNC(VertexArrayVertexAttribOffsetEXT)(
		get_raw_name(vao),
		get_raw_name(buf),
		loc.index(),
		values_per_vertex,
		GLenum(type),
		normalized,
		stride, offset
	);
	OGLPLUS_VERIFY(
		VertexArrayVertexAttribOffsetEXT,
		gl_object(vao).
		gl_subject(buf).
		gl_enum_value(type).
		gl_index(loc.index()),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
vertex_array_ops::
vertex_array_attrib_i_offset(
	vertex_array_name vao,
	buffer_name buf,
	vertex_attrib_location loc,
	GLint values_per_vertex,
	data_type type,
	GLsizei stride,
	GLintptr offset
) noexcept {
	OGLPLUS_GLFUNC(VertexArrayVertexAttribIOffsetEXT)(
		get_raw_name(vao),
		get_raw_name(buf),
		loc.index(),
		values_per_vertex,
		GLenum(type),
		stride, offset
	);
	OGLPLUS_VERIFY(
		VertexArrayVertexAttribIOffsetEXT,
		gl_object(vao).
		gl_subject(buf).
		gl_enum_value(type).
		gl_index(loc.index()),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_NV_vertex_buffer_unified_memory)
inline
outcome<void>
vertex_array_ops::
buffer_address_range(
	unified_array_address_nv uba,
	GLuint index,
	buffer_address addr,
	GLsizei length
) noexcept {
	OGLPLUS_GLFUNC(BufferAddressRangeNV)(
		GLenum(uba),
		index,
		get_raw_address(addr),
		length
	);
	OGLPLUS_VERIFY(
		BufferAddressRangeNV,
		gl_index(index).
		gl_enum_value(uba),
		debug
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
_gen(span<GLuint> names)
noexcept {
	OGLPLUS_GLFUNC(GenVertexArrays)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenVertexArrays,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_create
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5)
inline
deferred_error_handler
obj_gen_del_ops<tag::vertex_array>::
_create(span<GLuint> names)
noexcept {
	OGLPLUS_GLFUNC(CreateVertexArrays)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(CreateVertexArrays, debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::vertex_array>::
_delete(span<GLuint> names)
noexcept {
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
noexcept {
	GLboolean res = OGLPLUS_GLFUNC(IsVertexArray)(name);
	OGLPLUS_VERIFY_SIMPLE(IsVertexArray,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
