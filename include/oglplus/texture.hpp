/**
 *  @file oglplus/texture.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXTURE_1509260923_HPP
#define OGLPLUS_TEXTURE_1509260923_HPP

#include "object/gl_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "enum/types.hpp"

#ifndef GL_TEXTURE
#define GL_TEXTURE 0x1702
#endif

namespace oglplus {
namespace tag {

using texture = gl_obj_tag<GL_TEXTURE>;

} // namespace tag
} // namespace oglplus

namespace eagine {

template <>
struct object_subtype<oglplus::tag::texture>
{
	typedef oglplus::texture_target type;
};

} // namespace eagine

namespace oglplus {

using texture_name = object_name<tag::texture>;

namespace oper {

struct texture_ops
{
	static
	outcome<void>
	bind_texture(texture_target target, texture_name tex)
	noexcept
	{
		OGLPLUS_GLFUNC(BindTexture)(
			GLenum(target),
			get_raw_name(tex)
		);
		OGLPLUS_VERIFY(
			BindTexture,
			gl_enum_value(target).
			gl_object(tex),
			debug
		);
		return {};
	}
};

} // namespace oper

template <>
struct obj_gen_del_ops<tag::texture>
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

using texture = object_owner<tag::texture>;

static const object_zero_and_ops<tag::texture>
	default_texture = {};

} // namespace oglplus

#include <oglplus/texture.inl>

#endif // include guard
