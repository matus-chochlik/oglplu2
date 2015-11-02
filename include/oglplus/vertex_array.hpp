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
	noexcept
	{
		OGLPLUS_GLFUNC(BindVertexArray)(get_raw_name(vao));
		OGLPLUS_VERIFY(BindVertexArray, gl_object(vao), debug);
		return {};
	}

	static
	outcome<vertex_array_name>
	vertex_array_binding(void)
	noexcept;
};

} // namespace oper

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
