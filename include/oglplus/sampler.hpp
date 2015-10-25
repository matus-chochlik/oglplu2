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
#include "utils/gl_func.hpp"
#include "enum/indexed_types.hpp"

#ifndef GL_SAMPLER
#define GL_SAMPLER 0x82E6
#endif

namespace oglplus {
namespace tag {

using sampler = gl_obj_tag<GL_SAMPLER>;

} // namespace tag

using sampler_name = object_name<tag::sampler>;

namespace oper {

struct sampler_ops
{
	static
	outcome<void>
	bind_sampler(texture_unit unit, sampler_name sam)
	noexcept
	{
		OGLPLUS_GLFUNC(BindFramebuffer)(
			GLenum(unit),
			get_raw_name(sam)
		);
		OGLPLUS_VERIFY(
			BindFramebuffer,
			gl_enum_value(unit).
			gl_object(sam),
			debug
		);
		return {};
	}

	static
	outcome<sampler_name>
	sampler_binding(texture_unit unit)
	noexcept;
};

} // namespace oper

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

using sampler = object_owner<tag::sampler>;

static const object_zero_and_ops<tag::sampler>
	no_sampler = {};

} // namespace oglplus

#include <oglplus/sampler.inl>

#endif // include guard
