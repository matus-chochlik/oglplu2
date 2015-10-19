/**
 *  @file oglplus/ctxt/texture.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_TEXTURE_1509260923_HPP
#define OGLPLUS_CTXT_TEXTURE_1509260923_HPP

#include "../texture.hpp"
#include "../enum_values.hpp"

namespace oglplus {
namespace ctxt {

struct texture_ops
{
	static
	outcome<void>
	bind(texture_target target, texture_name tex)
	noexcept
	{
		OGLPLUS_GLFUNC(BindTexture)(
			GLenum(target),
			get_raw_name(tex)
		);
		OGLPLUS_VERIFY(
			BindTexture,
			enum_value(target).
			gl_object(tex),
			debug
		);
		return {};
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
