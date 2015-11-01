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
#include "enum/types.hpp"
#include "enum/indexed_types.hpp"

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

static inline
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

static inline
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

static inline
texture_name_and_target
make_texture_name_or_target(texture_name_and_target tnt)
noexcept
{
	return tnt;
}

static inline
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

	static
	outcome<void>
	get_texture_level_parameter_i(
		texture_target_only tnt,
		GLint level,
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

	static
	outcome<void>
	get_texture_level_parameter_i(
		texture_name_only tnt,
		GLint level,
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

	static
	outcome<void>
	get_texture_level_parameter_i(
		texture_name_and_target tnt,
		GLint level,
		oglplus::texture_parameter param,
		array_view<GLint> values
	) noexcept;
#endif

	template <typename R, typename T, typename TNT>
	static
	outcome<R>
	return_texture_parameter_i(
		TNT tnt, 
		oglplus::texture_parameter parameter
	) noexcept
	{
		GLint result;
		return get_texture_parameter_i(
			make_texture_name_or_target(tnt),
			parameter,
			{&result, 1}
		), R(T(result));
	}

	template <typename R, typename T, typename TNT>
	static
	outcome<R>
	return_texture_level_parameter_i(
		TNT tnt, 
		GLint level,
		oglplus::texture_parameter parameter
	) noexcept
	{
		GLint result;
		return get_texture_level_parameter_i(
			make_texture_name_or_target(tnt),
			level,
			parameter,
			{&result, 1}
		), R(T(result));
	}

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_width(TNT tnt, GLint level = 0)
	noexcept
	{
		return return_texture_level_parameter_i<GLsizei, GLsizei>(
			tnt, 
			level,
			oglplus::texture_parameter(GL_TEXTURE_WIDTH)
		);
	}

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_height(TNT tnt, GLint level = 0)
	noexcept
	{
		return return_texture_level_parameter_i<GLsizei, GLsizei>(
			tnt, 
			level,
			oglplus::texture_parameter(GL_TEXTURE_HEIGHT)
		);
	}

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_depth(TNT tnt, GLint level = 0)
	noexcept
	{
		return return_texture_level_parameter_i<GLsizei, GLsizei>(
			tnt, 
			level,
			oglplus::texture_parameter(GL_TEXTURE_DEPTH)
		);
	}

	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_red_type(TNT tnt)
	noexcept
	{
		return return_texture_parameter_i<pixel_data_type, GLenum>(
			tnt,
			oglplus::texture_parameter(GL_TEXTURE_RED_TYPE)
		);
	}

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_red_size(TNT tnt, GLint level = 0)
	noexcept
	{
		return return_texture_level_parameter_i<GLsizei, GLsizei>(
			tnt, 
			level,
			oglplus::texture_parameter(GL_TEXTURE_RED_SIZE)
		);
	}

	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_green_type(TNT tnt)
	noexcept
	{
		return return_texture_parameter_i<pixel_data_type, GLenum>(
			tnt,
			oglplus::texture_parameter(GL_TEXTURE_GREEN_TYPE)
		);
	}

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_green_size(TNT tnt, GLint level = 0)
	noexcept
	{
		return return_texture_level_parameter_i<GLsizei, GLsizei>(
			tnt, 
			level,
			oglplus::texture_parameter(GL_TEXTURE_GREEN_SIZE)
		);
	}

	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_blue_type(TNT tnt)
	noexcept
	{
		return return_texture_parameter_i<pixel_data_type, GLenum>(
			tnt,
			oglplus::texture_parameter(GL_TEXTURE_BLUE_TYPE)
		);
	}

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_blue_size(TNT tnt, GLint level = 0)
	noexcept
	{
		return return_texture_level_parameter_i<GLsizei, GLsizei>(
			tnt, 
			level,
			oglplus::texture_parameter(GL_TEXTURE_BLUE_SIZE)
		);
	}

	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_alpha_type(TNT tnt)
	noexcept
	{
		return return_texture_parameter_i<pixel_data_type, GLenum>(
			tnt,
			oglplus::texture_parameter(GL_TEXTURE_ALPHA_TYPE)
		);
	}

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_alpha_size(TNT tnt, GLint level = 0)
	noexcept
	{
		return return_texture_level_parameter_i<GLsizei, GLsizei>(
			tnt, 
			level,
			oglplus::texture_parameter(GL_TEXTURE_ALPHA_SIZE)
		);
	}

	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_depth_type(TNT tnt)
	noexcept
	{
		return return_texture_parameter_i<pixel_data_type, GLenum>(
			tnt,
			oglplus::texture_parameter(GL_TEXTURE_DEPTH_TYPE)
		);
	}

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_depth_size(TNT tnt, GLint level = 0)
	noexcept
	{
		return return_texture_level_parameter_i<GLsizei, GLsizei>(
			tnt, 
			level,
			oglplus::texture_parameter(GL_TEXTURE_DEPTH_SIZE)
		);
	}

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_stencil_size(TNT tnt, GLint level = 0)
	noexcept
	{
		return return_texture_level_parameter_i<GLsizei, GLsizei>(
			tnt, 
			level,
			oglplus::texture_parameter(GL_TEXTURE_STENCIL_SIZE)
		);
	}

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_shared_size(TNT tnt, GLint level = 0)
	noexcept
	{
		return return_texture_level_parameter_i<GLsizei, GLsizei>(
			tnt, 
			level,
			oglplus::texture_parameter(GL_TEXTURE_SHARED_SIZE)
		);
	}

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
		return return_texture_parameter_i<
			oglplus::texture_min_filter,
			GLenum
		>(
			tnt,
			oglplus::texture_parameter(GL_TEXTURE_MIN_FILTER)
		);
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
		return return_texture_parameter_i<
			oglplus::texture_mag_filter,
			GLenum
		>(
			tnt,
			oglplus::texture_parameter(GL_TEXTURE_MAG_FILTER)
		);
	}

	template <typename TNT>
	static 
	outcome<void>
	texture_compare_func(
		TNT tnt,
		oglplus::compare_function value
	) noexcept
	{
		return texture_parameter_i(
			make_texture_name_or_target(tnt),
			oglplus::texture_parameter(GL_TEXTURE_COMPARE_FUNC),
			GLint(GLenum(value))
		);
	}

	template <typename TNT>
	static 
	outcome<oglplus::compare_function>
	texture_compare_func(TNT tnt)
	noexcept
	{
		return return_texture_parameter_i<
			oglplus::compare_function,
			GLenum
		>(
			tnt,
			oglplus::texture_parameter(GL_TEXTURE_COMPARE_FUNC)
		);
	}

	template <typename TNT>
	static 
	outcome<void>
	texture_compare_mode(
		TNT tnt,
		oglplus::texture_compare_mode value
	) noexcept
	{
		return texture_parameter_i(
			make_texture_name_or_target(tnt),
			oglplus::texture_parameter(GL_TEXTURE_COMPARE_MODE),
			GLint(GLenum(value))
		);
	}

	template <typename TNT>
	static 
	outcome<oglplus::texture_compare_mode>
	texture_compare_mode(TNT tnt)
	noexcept
	{
		return return_texture_parameter_i<
			oglplus::texture_compare_mode,
			GLenum
		>(
			tnt,
			oglplus::texture_parameter(GL_TEXTURE_COMPARE_MODE)
		);
	}
};

} // namespace oper

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)

template <>
#if defined(GL_VERSION_4_5)
struct obj_dsa_ops<texture_name>
 : obj_zero_dsa_ops<texture_name>
#elif defined(GL_EXT_direct_state_access)
struct obj_zero_dsa_ops<texture_name>
 : texture_name
#endif
{
#if defined(GL_VERSION_4_5)
	obj_zero_dsa_ops<texture_name>::obj_zero_dsa_ops;

	texture_name_only _get_tnt(void) const
	noexcept
	{
		return {*this};
	}
#elif defined(GL_EXT_direct_state_access)
	texture_target target;

	obj_zero_dsa_ops(void)
	noexcept
	 : texture_name(0)
	{ }

	texture_name_and_target _get_tnt(void) const
	noexcept
	{
		return {*this, target};
	}
#endif

	outcome<GLsizei>
	width(GLint level = 0) const
	noexcept
	{
		return oper::texture_ops::texture_width(_get_tnt(), level);
	}

	outcome<GLsizei>
	height(GLint level = 0) const
	noexcept
	{
		return oper::texture_ops::texture_height(_get_tnt(), level);
	}

	outcome<GLsizei>
	depth(GLint level = 0) const
	noexcept
	{
		return oper::texture_ops::texture_depth(_get_tnt(), level);
	}

	outcome<pixel_data_type>
	red_type(void) const
	noexcept
	{
		return oper::texture_ops::texture_red_type(_get_tnt());
	}

	outcome<GLsizei>
	red_size(GLint level = 0) const
	noexcept
	{
		return oper::texture_ops::texture_red_size(_get_tnt(), level);
	}

	outcome<pixel_data_type>
	green_type(void) const
	noexcept
	{
		return oper::texture_ops::texture_green_type(_get_tnt());
	}

	outcome<GLsizei>
	green_size(GLint level = 0) const
	noexcept
	{
		return oper::texture_ops::texture_green_size(_get_tnt(), level);
	}

	outcome<pixel_data_type>
	blue_type(void) const
	noexcept
	{
		return oper::texture_ops::texture_blue_type(_get_tnt());
	}

	outcome<GLsizei>
	blue_size(GLint level = 0) const
	noexcept
	{
		return oper::texture_ops::texture_blue_size(_get_tnt(), level);
	}

	outcome<pixel_data_type>
	alpha_type(void) const
	noexcept
	{
		return oper::texture_ops::texture_alpha_type(_get_tnt());
	}

	outcome<GLsizei>
	alpha_size(GLint level = 0) const
	noexcept
	{
		return oper::texture_ops::texture_alpha_size(_get_tnt(), level);
	}

	outcome<pixel_data_type>
	depth_type(void) const
	noexcept
	{
		return oper::texture_ops::texture_depth_type(_get_tnt());
	}

	outcome<GLsizei>
	depth_size(GLint level = 0) const
	noexcept
	{
		return oper::texture_ops::texture_depth_size(_get_tnt(), level);
	}

	outcome<GLsizei>
	stencil_size(GLint level = 0) const
	noexcept
	{
		return oper::texture_ops::texture_stencil_size(
			_get_tnt(),
			level
		);
	}

	outcome<GLsizei>
	shared_size(GLint level = 0) const
	noexcept
	{
		return oper::texture_ops::texture_shared_size(
			_get_tnt(),
			level
		);
	}

	outcome<void>
	min_filter(oglplus::texture_min_filter value)
	noexcept
	{
		return oper::texture_ops::texture_min_filter(
			_get_tnt(),
			value
		);
	}

	outcome<oglplus::texture_min_filter>
	min_filter(void) const
	noexcept
	{
		return oper::texture_ops::texture_min_filter(_get_tnt());
	}

	outcome<void>
	mag_filter(oglplus::texture_mag_filter value)
	noexcept
	{
		return oper::texture_ops::texture_mag_filter(
			_get_tnt(),
			value
		);
	}

	outcome<oglplus::texture_mag_filter>
	mag_filter(void) const
	noexcept
	{
		return oper::texture_ops::texture_mag_filter(_get_tnt());
	}

	outcome<void>
	compare_func(oglplus::compare_function value)
	noexcept
	{
		return oper::texture_ops::texture_compare_func(
			_get_tnt(),
			value
		);
	}

	outcome<oglplus::compare_function>
	compare_func(void) const
	noexcept
	{
		return oper::texture_ops::texture_compare_func(_get_tnt());
	}

	outcome<void>
	compare_mode(oglplus::texture_compare_mode value)
	noexcept
	{
		return oper::texture_ops::texture_compare_mode(
			_get_tnt(),
			value
		);
	}

	outcome<oglplus::texture_compare_mode>
	compare_mode(void) const
	noexcept
	{
		return oper::texture_ops::texture_compare_mode(_get_tnt());
	}
};

#endif // GL_VERSION_4_5 || GL_EXT_direct_state_access


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
