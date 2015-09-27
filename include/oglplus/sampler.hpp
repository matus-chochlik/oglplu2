/**
 *  @file oglplus/sampler.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_SAMPLER_1509260923_HPP
#define OGLPLUS_SAMPLER_1509260923_HPP

#include "object/gl_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"

#ifdef GL_SAMPLER

namespace oglplus {
namespace tag {

using sampler = gl_obj_tag<GL_SAMPLER>;

} // namespace tag

using sampler_name = object_name<tag::sampler>;
using sampler = object_owner<tag::sampler>;

template <>
struct obj_gen_del_ops<tag::sampler>
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

#include <oglplus/sampler.inl>

#endif // GL_SAMPLER

#endif // include guard
