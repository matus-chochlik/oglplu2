/**
 *  @file oglplus/ctxt/buffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_BUFFER_1509260923_HPP
#define OGLPLUS_CTXT_BUFFER_1509260923_HPP

#include "../buffer.hpp"
#include "../enum_values.hpp"
#include "../utils/buffer_data.hpp"


namespace oglplus {
namespace ctxt {

struct buffer_ops
{
	static
	outcome<void>
	bind(buffer_target target, buffer_name buf)
	noexcept
	{
		OGLPLUS_GLFUNC(BindBuffer)(
			GLenum(target),
			get_raw_name(buf)
		);
		OGLPLUS_VERIFY(
			BindBuffer,
			enum_value(target).
			gl_object(buf),
			debug
		);
		return {};
	}

	static
	outcome<void>
	buffer_data(
		buffer_target target,
		buffer_data data,
		buffer_usage usage
	)
	noexcept
	{
		OGLPLUS_GLFUNC(BufferData)(
			GLenum(target),
			GLsizei(data.size()),
			data.data(),
			GLenum(usage)
		);
		OGLPLUS_VERIFY(
			BufferData,
			enum_value(target),
			debug
		);
		return {};
	}

};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
