/**
 *  @file oglplus/query.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_QUERY_1509260923_HPP
#define OGLPLUS_QUERY_1509260923_HPP

#include "object/gl_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/boolean.hpp"

#ifndef GL_QUERY
#define GL_QUERY 0x82E3
#endif

namespace oglplus {
namespace tag {

using query = gl_obj_tag<GL_QUERY>;

} // namespace tag

using query_name = object_name<tag::query>;

template <>
struct obj_gen_del_ops<tag::query>
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

using query = object_owner<tag::query>;

} // namespace oglplus

#include <oglplus/query.inl>

#endif // include guard
