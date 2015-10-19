/**
 *  @file oglplus/ctxt/vertex_array.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_VERTEX_ARRAY_1509260923_HPP
#define OGLPLUS_CTXT_VERTEX_ARRAY_1509260923_HPP

#include "../vertex_array.hpp"


namespace oglplus {
namespace ctxt {

struct vertex_array_ops
{
	static
	outcome<void>
	bind(vertex_array_name vao)
	noexcept
	{
		OGLPLUS_GLFUNC(BindVertexArray)(get_raw_name(vao));
		OGLPLUS_VERIFY(BindVertexArray, gl_object(vao), debug);
		return {};
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
