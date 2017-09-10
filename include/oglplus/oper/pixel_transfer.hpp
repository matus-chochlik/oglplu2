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

#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct pixel_transfer_state
{
#if defined(GL_VERSION_3_0)
	static
	outcome<void>
	clamp_color(clamp_color_target target, boolean clamp)
	noexcept;
#endif
};

struct pixel_transfer_ops
{
	template <typename T>
	static
	outcome<void>
	read_pixels(
		GLint x, GLint y,
		GLsizei width, GLsizei height,
		pixel_data_format format,
		pixel_data_type type,
		span<T> data
	) noexcept;
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/pixel_transfer.inl>

#endif // include guard
