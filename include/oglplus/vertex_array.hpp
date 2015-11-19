/**
 *  @file oglplus/vertex_array.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_VERTEX_ARRAY_1509260923_HPP
#define OGLPLUS_VERTEX_ARRAY_1509260923_HPP

#include "vertex_array_name.hpp"
#include "buffer_name.hpp"
#include "vertex_attrib.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"

#if defined(GL_VERSION_4_5) ||\
	defined(GL_ARB_direct_state_access) ||\
	defined(GL_EXT_direct_state_access)
#define OGLPLUS_DSA_VERTEX_ARRAY 1
#endif

namespace oglplus {
namespace oper {

struct vertex_array_ops
{
	static
	outcome<void>
	bind_vertex_array(vertex_array_name vao)
	noexcept;

	static
	outcome<vertex_array_name>
	vertex_array_binding(void)
	noexcept;

	static
	outcome<void>
	enable_vertex_array_attrib(vertex_attrib_location va)
	noexcept;

	static
	outcome<void>
	disable_vertex_array_attrib(vertex_attrib_location va)
	noexcept;

#ifdef OGLPLUS_DSA_VERTEX_ARRAY
	static
	outcome<void>
	enable_vertex_array_attrib(vertex_array_name, vertex_attrib_location)
	noexcept;

	static
	outcome<void>
	disable_vertex_array_attrib(vertex_array_name, vertex_attrib_location)
	noexcept;
#endif

	static
	outcome<void>
	vertex_array_attrib_pointer(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		boolean normalized,
		GLsizei stride,
		const void* pointer
	) noexcept;

	static
	outcome<void>
	vertex_array_attrib_i_pointer(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLsizei stride,
		const void* pointer
	) noexcept;

#if defined(GL_VERSION_4_3) || defined(GL_ARB_vertex_attrib_binding)
	static
	outcome<void>
	vertex_array_attrib_format(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		boolean normalized,
		GLuint relative_offset
	) noexcept;

	static
	outcome<void>
	vertex_array_attrib_i_format(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLuint relative_offset
	) noexcept;

	static
	outcome<void>
	vertex_array_attrib_l_format(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLuint relative_offset
	) noexcept;
#endif

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	static
	outcome<void>
	vertex_array_vertex_buffer(
		vertex_array_name vao,
		vertex_attrib_location loc,
		buffer_name buf,
		GLintptr offset,
		GLsizei stride
	) noexcept;

	static
	outcome<void>
	vertex_array_attrib_format(
		vertex_array_name vao,
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		boolean normalized,
		GLuint relative_offset
	) noexcept;

	static
	outcome<void>
	vertex_array_attrib_i_format(
		vertex_array_name vao,
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLuint relative_offset
	) noexcept;

	static
	outcome<void>
	vertex_array_attrib_l_format(
		vertex_array_name vao,
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLuint relative_offset
	) noexcept;
#endif

#if defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	vertex_array_attrib_offset(
		vertex_array_name vao,
		buffer_name buf,
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		boolean normalized,
		GLsizei stride,
		GLintptr offset
	) noexcept;

	static
	outcome<void>
	vertex_array_attrib_i_offset(
		vertex_array_name vao,
		buffer_name buf,
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLsizei stride,
		GLintptr offset
	) noexcept;
#endif
};

} // namespace oper

template <>
struct object_binding<tag::vertex_array>
{
	typedef oper::vertex_array_ops _ops;

	outcome<object_binding&>
	enable_attrib(vertex_attrib_location loc)
	noexcept
	{
		return {_ops::enable_vertex_array_attrib(loc), *this};
	}

	outcome<object_binding&>
	disable_attrib(vertex_attrib_location loc)
	noexcept
	{
		return {_ops::disable_vertex_array_attrib(loc), *this};
	}

	outcome<object_binding&>
	attrib_pointer(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		boolean normalized,
		GLsizei stride,
		const void* pointer
	) noexcept
	{
		return {_ops::vertex_array_attrib_pointer(
			loc,
			values_per_vertex, type,
			normalized, stride,
			pointer
		), *this};
	}

	outcome<object_binding&>
	attrib_i_pointer(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLsizei stride,
		const void* pointer
	) noexcept
	{
		return {_ops::vertex_array_attrib_i_pointer(
			loc,
			values_per_vertex, type,
			stride,
			pointer
		), *this};
	}

#if defined(GL_VERSION_4_3) || defined(GL_ARB_vertex_attrib_binding)
	outcome<object_binding&>
	attrib_format(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		boolean normalized,
		GLuint relative_offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_format(
			loc,
			values_per_vertex, type,
			normalized, relative_offset
		), *this};
	}

	outcome<object_binding&>
	attrib_i_format(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLuint relative_offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_i_format(
			loc,
			values_per_vertex, type,
			relative_offset
		), *this};
	}

	outcome<object_binding&>
	attrib_l_format(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLuint relative_offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_l_format(
			loc,
			values_per_vertex, type,
			relative_offset
		), *this};
	}
#endif
};

#ifdef OGLPLUS_DSA_VERTEX_ARRAY
template <>
struct obj_dsa_ops<tag::vertex_array>
 : obj_zero_dsa_ops<tag::vertex_array>
{
	typedef oper::vertex_array_ops _ops;

	using obj_zero_dsa_ops<tag::vertex_array>::obj_zero_dsa_ops;

	outcome<obj_dsa_ops&>
	enable_attrib(vertex_attrib_location loc)
	noexcept
	{
		return {_ops::enable_vertex_array_attrib(*this, loc), *this};
	}

	outcome<obj_dsa_ops&>
	disable_attrib(vertex_attrib_location loc)
	noexcept
	{
		return {_ops::disable_vertex_array_attrib(*this, loc), *this};
	}

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	outcome<obj_dsa_ops&>
	vertex_buffer(
		vertex_attrib_location loc,
		buffer_name buf,
		GLintptr offset,
		GLsizei stride
	) noexcept
	{
		return {_ops::vertex_array_vertex_buffer(
			*this, loc,
			buf,
			offset, stride
		), *this};
	}

	outcome<obj_dsa_ops&>
	attrib_format(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		boolean normalized,
		GLuint relative_offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_format(
			*this, loc,
			values_per_vertex,
			type, normalized,
			relative_offset
		), *this};
	}

	outcome<obj_dsa_ops&>
	attrib_i_format(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLuint relative_offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_i_format(
			*this, loc,
			values_per_vertex,
			type,
			relative_offset
		), *this};
	}

	outcome<obj_dsa_ops&>
	attrib_l_format(
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLuint relative_offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_l_format(
			*this, loc,
			values_per_vertex,
			type,
			relative_offset
		), *this};
	}
#endif

#if defined(GL_EXT_direct_state_access)
	outcome<obj_dsa_ops&>
	attrib_offset(
		buffer_name buf,
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		boolean normalized,
		GLsizei stride,
		GLintptr offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_offset(
			*this, buf, loc,
			values_per_vertex,
			type, normalized,
			stride, offset
		), *this};
	}

	outcome<obj_dsa_ops&>
	attrib_i_offset(
		buffer_name buf,
		vertex_attrib_location loc,
		GLint values_per_vertex,
		data_type type,
		GLsizei stride,
		GLintptr offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_i_offset(
			*this, buf, loc,
			values_per_vertex,
			type,
			stride, offset
		), *this};
	}
#endif
};

class vertex_array_attrib
{
private:
	vertex_array_name _vao;
	vertex_attrib_location _loc;

	typedef oper::vertex_array_ops _ops;
public:
	vertex_array_attrib(
		vertex_array_name vao,
		vertex_attrib_location loc
	) noexcept
	 : _vao(vao)
	 , _loc(loc)
	{ }

	outcome<vertex_array_attrib&>
	enable(void)
	noexcept
	{
		return {_ops::enable_vertex_array_attrib(_vao,_loc), *this};
	}

	outcome<vertex_array_attrib&>
	disable(void)
	noexcept
	{
		return {_ops::disable_vertex_array_attrib(_vao,_loc), *this};
	}

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	outcome<vertex_array_attrib&>
	vertex_buffer(buffer_name buf, GLintptr offset, GLsizei stride)
	noexcept
	{
		return {_ops::vertex_array_vertex_buffer(
			_vao,_loc,
			buf,
			offset, stride
		), *this};
	}

	outcome<vertex_array_attrib&>
	format(
		GLint values_per_vertex,
		data_type type,
		boolean normalized,
		GLuint relative_offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_format(
			_vao,_loc,
			values_per_vertex,
			type, normalized,
			relative_offset
		), *this};
	}

	outcome<vertex_array_attrib&>
	i_format(
		GLint values_per_vertex,
		data_type type,
		GLuint relative_offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_i_format(
			_vao,_loc,
			values_per_vertex,
			type,
			relative_offset
		), *this};
	}

	outcome<vertex_array_attrib&>
	l_format(
		GLint values_per_vertex,
		data_type type,
		GLuint relative_offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_l_format(
			_vao,_loc,
			values_per_vertex,
			type,
			relative_offset
		), *this};
	}
#endif

#if defined(GL_EXT_direct_state_access)
	outcome<vertex_array_attrib&>
	offset(
		buffer_name buf,
		GLint values_per_vertex,
		data_type type,
		boolean normalized,
		GLsizei stride,
		GLintptr offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_offset(
			_vao, buf,_loc,
			values_per_vertex,
			type, normalized,
			stride, offset
		), *this};
	}

	outcome<vertex_array_attrib&>
	i_offset(
		buffer_name buf,
		GLint values_per_vertex,
		data_type type,
		GLsizei stride,
		GLintptr offset
	) noexcept
	{
		return {_ops::vertex_array_attrib_i_offset(
			_vao, buf,_loc,
			values_per_vertex,
			type,
			stride, offset
		), *this};
	}
#endif
};
#endif

template <>
struct obj_gen_del_ops<tag::vertex_array>
{
	static
	deferred_error_handler
	_gen(span<GLuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(span<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using vertex_array = object_owner<tag::vertex_array>;
using bound_vertex_array = object_binding<tag::vertex_array>;
template <std::size_t N>
using vertex_array_array = object_array_owner<tag::vertex_array, N>;

static const object_zero_and_ops<tag::vertex_array>
	no_vertex_array = {};

} // namespace oglplus

#include <oglplus/vertex_array.inl>

#ifdef OGLPLUS_DSA_VERTEX_ARRAY
#undef OGLPLUS_DSA_VERTEX_ARRAY
#endif

#endif // include guard
