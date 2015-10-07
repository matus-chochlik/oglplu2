/**
 *  @file oglplus/ctxt/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_VIEWPORT_1509260923_HPP
#define OGLPLUS_CTXT_VIEWPORT_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum_types.hpp"

namespace oglplus {
namespace ctxt {

struct viewport_state
{
	static
	outcome<void>
	viewport(GLint x, GLint y, GLsizei w, GLsizei h)
	noexcept
	{
		OGLPLUS_GLFUNC(Viewport)(x, y, w, h);
		OGLPLUS_VERIFY_SIMPLE(Viewport,warning);
		return {};
	}

	static
	outcome<void>
	viewport(GLsizei w, GLsizei h)
	noexcept
	{
		OGLPLUS_GLFUNC(Viewport)(0, 0, w, h);
		OGLPLUS_VERIFY_SIMPLE(Viewport,warning);
		return {};
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
