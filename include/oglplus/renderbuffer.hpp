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

#include "object/gl_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"

#ifndef GL_RENDERBUFFER
#define GL_RENDERBUFFER 0x8D41
#endif

namespace oglplus {
namespace tag {

using renderbuffer = gl_obj_tag<GL_RENDERBUFFER>;

} // namespace tag

using renderbuffer_name = object_name<tag::renderbuffer>;

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
	outcome<bool> _is_a(GLuint name)
	noexcept;
};

using renderbuffer = object_owner<tag::renderbuffer>;

static const object_zero_and_ops<tag::renderbuffer>
	no_renderbuffer = {};

} // namespace oglplus

#include <oglplus/renderbuffer.inl>

#endif // include guard
