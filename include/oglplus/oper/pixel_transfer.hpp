/**
 *  @file oglplus/oper/pixel_transfer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_PIXEL_TRANSFER_1509260923_HPP
#define OGLPLUS_OPER_PIXEL_TRANSFER_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct pixel_transfer_state
{
	static
	outcome<void>
	clamp_color(clamp_color_target target, boolean clamp)
	noexcept
	{
		OGLPLUS_GLFUNC(ClampColor)(GLenum(target), GLboolean(clamp));
		OGLPLUS_VERIFY(
			ClampColor,
			gl_enum_value(target),
			debug
		);
		return {};
	}
};

} // namespace oper
} // namespace oglplus

#endif // include guard
