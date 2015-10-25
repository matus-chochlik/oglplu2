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
#include "utils/nothing.hpp"
#include "utils/gl_func.hpp"
#include "constants.hpp"

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

binding_query
get_binding_query(texture_target tgt)
noexcept;

template <typename Name, typename Target>
struct texture_name_or_target;

template <typename Name, typename Target>
static constexpr inline
texture_name_or_target<Name, Target>
make_texture_name_and_target(texture_name_or_target<Name, Target> tnt)
noexcept
{
	return tnt;
}

template <>
struct texture_name_or_target<nothing_t, texture_target>
{
	texture_target _target;

	constexpr inline
	texture_name_or_target(texture_target target)
	noexcept
	 : _target(target)
	{ }
};

typedef texture_name_or_target<nothing_t, texture_target> texture_target_only;

static constexpr inline
texture_target_only
make_texture_name_or_target(texture_target target)
noexcept
{
	return {target};
}

template <>
struct texture_name_or_target<texture_name, nothing_t>
{
	texture_name _name;

	constexpr inline
	texture_name_or_target(texture_name name)
	noexcept
	 : _name(name)
	{ }
};

typedef texture_name_or_target<texture_name, nothing_t> texture_name_only;

static constexpr inline
texture_name_only
make_texture_name_or_target(texture_name name)
noexcept
{
	return {name};
}

template <>
struct texture_name_or_target<texture_name, texture_target>
{
	texture_name _name;
	texture_target _target;

	constexpr inline
	texture_name_or_target(
		texture_name name,
		texture_target target
	) noexcept
	 : _name(name)
	 , _target(target)
	{ }
};

typedef texture_name_or_target<texture_name, texture_target> texture_name_and_target;

static constexpr inline
texture_name_and_target
make_texture_name_or_target(texture_name name, texture_target target)
noexcept
{
	return {name, target};
}

namespace oper {

struct texture_ops
{
	static
	outcome<void>
	active_texture(texture_unit unit)
	noexcept;

	static
	outcome<texture_unit>
	active_texture(void)
	noexcept;

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

	static
	outcome<texture_name>
	texture_binding(texture_target target)
	noexcept;

	static
	outcome<void>
	texture_parameter_i(
		texture_target_only tnt,
		oglplus::texture_parameter param,
		GLint value
	) noexcept;

	static
	outcome<void>
	get_texture_parameter_i(
		texture_target_only tnt,
		oglplus::texture_parameter param,
		array_view<GLint> values
	) noexcept;

#ifdef GL_VERSION_4_5
	static
	outcome<void>
	texture_parameter_i(
		texture_name_only tnt,
		oglplus::texture_parameter param,
		GLint value
	) noexcept;

	static
	outcome<void>
	get_texture_parameter_i(
		texture_name_only tnt,
		oglplus::texture_parameter param,
		array_view<GLint> values
	) noexcept;
#endif

#ifdef GL_EXT_direct_state_access
	static
	outcome<void>
	texture_parameter_i(
		texture_name_and_target tnt,
		oglplus::texture_parameter param,
		GLint value
	) noexcept;

	static
	outcome<void>
	get_texture_parameter_i(
		texture_name_and_target tnt,
		oglplus::texture_parameter param,
		array_view<GLint> values
	) noexcept;
#endif

	template <typename TNT>
	static 
	outcome<void>
	texture_min_filter(
		TNT tnt,
		oglplus::texture_min_filter value
	) noexcept
	{
		return texture_parameter_i(
			make_texture_name_or_target(tnt),
			oglplus::texture_parameter(GL_TEXTURE_MIN_FILTER),
			GLint(GLenum(value))
		);
	}

	template <typename TNT>
	static 
	outcome<oglplus::texture_min_filter>
	texture_min_filter(TNT tnt)
	noexcept
	{
		GLint result;
		return get_texture_parameter_i(
			make_texture_name_or_target(tnt),
			oglplus::texture_parameter(GL_TEXTURE_MIN_FILTER),
			{&result, 1}
		), oglplus::texture_min_filter(GLenum(result));
	}

	template <typename TNT>
	static 
	outcome<void>
	texture_mag_filter(
		TNT tnt,
		oglplus::texture_mag_filter value
	) noexcept
	{
		return texture_parameter_i(
			make_texture_name_or_target(tnt),
			oglplus::texture_parameter(GL_TEXTURE_MAG_FILTER),
			GLint(GLenum(value))
		);
	}

	template <typename TNT>
	static 
	outcome<oglplus::texture_mag_filter>
	texture_mag_filter(TNT tnt)
	noexcept
	{
		GLint result;
		return get_texture_parameter_i(
			make_texture_name_or_target(tnt),
			oglplus::texture_parameter(GL_TEXTURE_MAG_FILTER),
			{&result, 1}
		), oglplus::texture_mag_filter(GLenum(result));
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
