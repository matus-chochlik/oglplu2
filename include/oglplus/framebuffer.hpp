/**
 *  @file oglplus/framebuffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_FRAMEBUFFER_1509260923_HPP
#define OGLPLUS_FRAMEBUFFER_1509260923_HPP

#include "object/gl_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"

#ifndef GL_FRAMEBUFFER
#define GL_FRAMEBUFFER 0x8D40
#endif

namespace oglplus {
namespace tag {

using framebuffer = gl_obj_tag<GL_FRAMEBUFFER>;

} // namespace tag

using framebuffer_name = object_name<tag::framebuffer>;

template <>
struct obj_gen_del_ops<tag::framebuffer>
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

using framebuffer = object_owner<tag::framebuffer>;

static const object_zero_and_ops<tag::framebuffer>
	default_framebuffer = {};

} // namespace oglplus

#include <oglplus/framebuffer.inl>

#endif // include guard
