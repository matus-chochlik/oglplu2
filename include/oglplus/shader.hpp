/**
 *  @file oglplus/shader.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_SHADER_1509260923_HPP
#define OGLPLUS_SHADER_1509260923_HPP

#include "object/gl_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "enum_types.hpp"

#ifdef GL_SHADER

namespace oglplus {
namespace tag {

using shader = gl_obj_tag<GL_SHADER>;

} // namespace tag

using shader_name = object_name<tag::shader>;
using shader = object_owner<tag::shader>;

template <>
struct object_subtype<tag::shader>
{
	typedef shader_type type;
};

template <>
struct obj_gen_del_ops<tag::shader>
{
	static
	deferred_error_handler
	_gen(array_view<GLuint> names, shader_type type)
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

#include <oglplus/shader.inl>

#endif // GL_SHADER

#endif // include guard
