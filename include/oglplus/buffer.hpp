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

#ifdef GL_BUFFER

namespace oglplus {
namespace tag {

using buffer = gl_obj_tag<GL_BUFFER>;

} // namespace tag

using buffer_name = object_name<tag::buffer>;
using buffer = object_owner<tag::buffer>;

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
	outcome<bool> _is_a(GLuint name)
	noexcept;
};

} // namespace oglplus

#include <oglplus/buffer.inl>

#endif // GL_BUFFER

#endif // include guard
