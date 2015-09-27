/**
 *  @file oglplus/sampler.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_SAMPLER_1509260923_HPP
#define OGLPLUS_SAMPLER_1509260923_HPP

#include "object/gl_name.hpp"
#include "utils/gl_func.hpp"
#include "error/handling.hpp"

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
	noexcept
	{
		OGLPLUS_GLFUNC(GenSamplers)(
			GLsizei(names.size()),
			names.data()
		);
		OGLPLUS_VERIFY_SIMPLE(GenSamplers,severe);
		return {};
	}

	static
	deferred_error_handler
	_delete(array_view<GLuint> names)
	noexcept
	{
		OGLPLUS_GLFUNC(DeleteSamplers)(
			GLsizei(names.size()),
			names.data()
		);
		OGLPLUS_VERIFY_SIMPLE(DeleteSamplers,severe);
		return {};
	}

	static
	outcome<bool> _is_a(GLuint name)
	noexcept
	{
		GLboolean res = OGLPLUS_GLFUNC(IsSampler)(name);
		OGLPLUS_VERIFY_SIMPLE(IsSampler,warning);
		return res == GL_TRUE;
	}
};

} // namespace oglplus

#endif // include guard
