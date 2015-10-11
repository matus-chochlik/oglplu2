/**
 *  @file oglplus/ctxt/vertex_attrib.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_VERTEX_ATTRIB_1509260923_HPP
#define OGLPLUS_CTXT_VERTEX_ATTRIB_1509260923_HPP

#include "../vertex_attrib.hpp"


namespace oglplus {
namespace ctxt {

struct vertex_attrib_ops
{
	static
	outcome<void>
	enable_array(vertex_attrib_location va)
	noexcept
	{
		OGLPLUS_GLFUNC(EnableVertexAttribArray)(va.index());
		OGLPLUS_VERIFY(
			EnableVertexAttribArray,
			index(va.index()),
			always
		);
		return {};
	}

	static
	outcome<void>
	disable_array(vertex_attrib_location va)
	noexcept
	{
		OGLPLUS_GLFUNC(DisableVertexAttribArray)(va.index());
		OGLPLUS_VERIFY(
			DisableVertexAttribArray,
			index(va.index()),
			always
		);
		return {};
	}

	// TODO

#ifdef GL_VERSION_3_3
	static
	outcome<void>
	divisor(vertex_attrib_location va, GLuint div)
	noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribDivisor)(
			va.index(),
			div
		);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribDivisor, always);
		return {};
	}
#endif
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
