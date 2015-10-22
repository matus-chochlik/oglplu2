/**
 *  @file oglplus/ctxt/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_DRAWING_1509260923_HPP
#define OGLPLUS_CTXT_DRAWING_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum_types.hpp"

namespace oglplus {
namespace ctxt {

struct drawing_ops
{
	static
	outcome<void>
	draw_arrays(primitive_type mode, GLint first, GLsizei count)
	noexcept
	{
		OGLPLUS_GLFUNC(DrawArrays)(GLenum(mode), first, count);
		OGLPLUS_VERIFY(DrawArrays, gl_enum_value(mode), debug);
		return {};
	}

	static
	outcome<void>
	draw_elements(primitive_type mode, GLsizei count, index_type type)
	noexcept
	{
		OGLPLUS_GLFUNC(DrawElements)(
			GLenum(mode),
			count,
			GLenum(type),
			nullptr
		);
		OGLPLUS_VERIFY(DrawElements, gl_enum_value(mode), debug);
		return {};
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
