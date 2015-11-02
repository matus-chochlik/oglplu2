/**
 *  @file oglplus/renderbuffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_RENDERBUFFER_1509260923_HPP
#define OGLPLUS_RENDERBUFFER_1509260923_HPP

#include "renderbuffer_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"

namespace oglplus {

binding_query
get_binding_query(renderbuffer_target tgt)
noexcept;

namespace oper {

struct renderbuffer_ops
{
	static
	outcome<void>
	bind_renderbuffer(renderbuffer_target target, renderbuffer_name rbo)
	noexcept
	{
		OGLPLUS_GLFUNC(BindRenderbuffer)(
			GLenum(target),
			get_raw_name(rbo)
		);
		OGLPLUS_VERIFY(
			BindRenderbuffer,
			gl_enum_value(target).
			gl_object(rbo),
			debug
		);
		return {};
	}

	static
	outcome<renderbuffer_name>
	renderbuffer_binding(renderbuffer_target target)
	noexcept;
};

} // namespace oper

template <>
struct obj_gen_del_ops<tag::renderbuffer>
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

using renderbuffer = object_owner<tag::renderbuffer>;

static const object_zero_and_ops<tag::renderbuffer>
	no_renderbuffer = {};

} // namespace oglplus

#include <oglplus/renderbuffer.inl>

#endif // include guard
