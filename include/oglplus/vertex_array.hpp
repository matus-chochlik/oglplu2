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
#include "vertex_attrib.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"

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

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	enable_vertex_array_attrib(vertex_array_name, vertex_attrib_location)
	noexcept;

	static
	outcome<void>
	disable_vertex_array_attrib(vertex_array_name, vertex_attrib_location)
	noexcept;
#endif
};

} // namespace oper

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
template <>
struct obj_dsa_ops<vertex_array_name>
 : obj_zero_dsa_ops<vertex_array_name>
{
	typedef oper::vertex_array_ops _ops;

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
};
#endif

template <>
struct obj_gen_del_ops<tag::vertex_array>
{
	static
	deferred_error_handler
	_gen(array_view<GLuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(array_view<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using vertex_array = object_owner<tag::vertex_array>;

static const object_zero_and_ops<tag::vertex_array>
	no_vertex_array = {};

} // namespace oglplus

#include <oglplus/vertex_array.inl>

#endif // include guard
