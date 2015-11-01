/**
 *  @file oglplus/buffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_BUFFER_1509260923_HPP
#define OGLPLUS_BUFFER_1509260923_HPP

#include "object/gl_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/buffer_data.hpp"
#include "utils/boolean.hpp"
#include "enum/types.hpp"

#ifndef GL_BUFFER
#define GL_BUFFER 0x82E0
#endif

namespace oglplus {
namespace tag {

using buffer = gl_obj_tag<GL_BUFFER>;

} // namespace tag

using buffer_name = object_name<tag::buffer>;

binding_query
get_binding_query(buffer_target tgt)
noexcept;

namespace oper {

struct buffer_ops
{
	static
	outcome<void>
	bind_buffer(buffer_target target, buffer_name buf)
	noexcept
	{
		OGLPLUS_GLFUNC(BindBuffer)(
			GLenum(target),
			get_raw_name(buf)
		);
		OGLPLUS_VERIFY(
			BindBuffer,
			gl_enum_value(target).
			gl_object(buf),
			debug
		);
		return {};
	}

	static
	outcome<buffer_name>
	buffer_binding(buffer_target target)
	noexcept;

	static
	outcome<void>
	data(
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
			gl_enum_value(target),
			debug
		);
		return {};
	}

};

} // namespace oper

template <>
struct obj_gen_del_ops<tag::buffer>
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

using buffer = object_owner<tag::buffer>;

static const object_zero_and_ops<tag::buffer>
	no_buffer = {};

} // namespace oglplus

#include <oglplus/buffer.inl>

#endif // include guard
