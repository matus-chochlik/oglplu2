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

#include "texture_name.hpp"
#include "object/owner.hpp"
#include "object/name_or_target.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"
#include "utils/image_spec.hpp"
#include "enum/indexed_types.hpp"

namespace eagine {

template <>
struct object_subtype<oglplus::tag::texture>
{
	typedef oglplus::texture_target type;
};

} // namespace eagine

namespace oglplus {

binding_query
get_binding_query(texture_target tgt)
noexcept;

typedef object_target_only<tag::texture> texture_target_only;
typedef object_name_only<tag::texture> texture_name_only;
typedef object_name_and_target<tag::texture> texture_name_and_target;

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
	noexcept;

	static
	outcome<texture_name>
	texture_binding(texture_target target)
	noexcept;

#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
	static
	outcome<void>
	texture_storage_1d(
		texture_target_only tnt,
		GLsizei levels,
		pixel_data_internal_format iformat,
		GLsizei width
	) noexcept;

	static
	outcome<void>
	texture_storage_2d(
		texture_target_only tnt,
		GLsizei levels,
		pixel_data_internal_format iformat,
		GLsizei width,
		GLsizei height
	) noexcept;

	static
	outcome<void>
	texture_storage_3d(
		texture_target_only tnt,
		GLsizei levels,
		pixel_data_internal_format iformat,
		GLsizei width,
		GLsizei height,
		GLsizei depth
	) noexcept;
#endif

#if defined(GL_VERSION_4_5)
	static
	outcome<void>
	texture_storage_1d(
		texture_name_only tnt,
		GLsizei levels,
		pixel_data_internal_format iformat,
		GLsizei width
	) noexcept;

	static
	outcome<void>
	texture_storage_2d(
		texture_name_only tnt,
		GLsizei levels,
		pixel_data_internal_format iformat,
		GLsizei width,
		GLsizei height
	) noexcept;

	static
	outcome<void>
	texture_storage_3d(
		texture_name_only tnt,
		GLsizei levels,
		pixel_data_internal_format iformat,
		GLsizei width,
		GLsizei height,
		GLsizei depth
	) noexcept;
#endif

	static
	outcome<void>
	texture_image_1d(
		texture_target_only tnt,
		GLint level,
		pixel_data_internal_format iformat,
		GLsizei width,
		GLint border,
		pixel_data_format format,
		pixel_data_type type,
		const_memory_block data
	) noexcept;

	static
	outcome<void>
	texture_image_1d(
		texture_target_only tnt,
		const image_spec& img,
		GLint level = 0,
		GLint border = 0
	) noexcept;

	static
	outcome<void>
	texture_image_2d(
		texture_target_only tnt,
		GLint level,
		pixel_data_internal_format iformat,
		GLsizei width,
		GLsizei height,
		GLint border,
		pixel_data_format format,
		pixel_data_type type,
		const_memory_block data
	) noexcept;

	static
	outcome<void>
	texture_image_2d(
		texture_target_only tnt,
		const image_spec& img,
		GLint level = 0,
		GLint border = 0
	) noexcept;

	static
	outcome<void>
	texture_image_3d(
		texture_target_only tnt,
		GLint level,
		pixel_data_internal_format iformat,
		GLsizei width,
		GLsizei height,
		GLsizei depth,
		GLint border,
		pixel_data_format format,
		pixel_data_type type,
		const_memory_block data
	) noexcept;

	static
	outcome<void>
	texture_image_3d(
		texture_target_only tnt,
		const image_spec& img,
		GLint level = 0,
		GLint border = 0
	) noexcept;

	static
	outcome<void>
	texture_parameter_i(
		texture_target_only tnt,
		oglplus::texture_parameter param,
		GLint value
	) noexcept;

	static
	outcome<void>
	get_texture_parameter_iv(
		texture_target_only tnt,
		oglplus::texture_parameter param,
		array_view<GLint> values
	) noexcept;

	static
	outcome<void>
	get_texture_level_parameter_iv(
		texture_target_only tnt,
		GLint level,
		oglplus::texture_parameter param,
		array_view<GLint> values
	) noexcept;

	static
	outcome<void>
	texture_parameter_f(
		texture_target_only tnt,
		oglplus::texture_parameter param,
		GLfloat value
	) noexcept;

	static
	outcome<void>
	get_texture_parameter_fv(
		texture_target_only tnt,
		oglplus::texture_parameter param,
		array_view<GLfloat> values
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
	get_texture_parameter_iv(
		texture_name_only tnt,
		oglplus::texture_parameter param,
		array_view<GLint> values
	) noexcept;

	static
	outcome<void>
	get_texture_level_parameter_iv(
		texture_name_only tnt,
		GLint level,
		oglplus::texture_parameter param,
		array_view<GLint> values
	) noexcept;

	static
	outcome<void>
	texture_parameter_f(
		texture_name_only tnt,
		oglplus::texture_parameter param,
		GLfloat value
	) noexcept;

	static
	outcome<void>
	get_texture_parameter_fv(
		texture_name_only tnt,
		oglplus::texture_parameter param,
		array_view<GLfloat> values
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
	get_texture_parameter_iv(
		texture_name_and_target tnt,
		oglplus::texture_parameter param,
		array_view<GLint> values
	) noexcept;

	static
	outcome<void>
	get_texture_level_parameter_iv(
		texture_name_and_target tnt,
		GLint level,
		oglplus::texture_parameter param,
		array_view<GLint> values
	) noexcept;

	static
	outcome<void>
	texture_parameter_f(
		texture_name_and_target tnt,
		oglplus::texture_parameter param,
		GLfloat value
	) noexcept;

	static
	outcome<void>
	get_texture_parameter_fv(
		texture_name_and_target tnt,
		oglplus::texture_parameter param,
		array_view<GLfloat> values
	) noexcept;

#endif

	template <typename R, typename T, typename TNT>
	static
	outcome<R>
	return_texture_parameter_i(
		TNT tnt, 
		oglplus::texture_parameter parameter
	) noexcept;

	template <typename R, typename T, typename TNT>
	static
	outcome<R>
	return_texture_level_parameter_i(
		TNT tnt, 
		GLint level,
		oglplus::texture_parameter parameter
	) noexcept;

	template <typename R, typename TNT>
	static
	outcome<R>
	return_texture_parameter_f(
		TNT tnt, 
		oglplus::texture_parameter parameter
	) noexcept;

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_width(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_height(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_depth(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_red_type(TNT tnt)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_red_size(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_green_type(TNT tnt)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_green_size(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_blue_type(TNT tnt)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_blue_size(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_alpha_type(TNT tnt)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_alpha_size(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_depth_type(TNT tnt)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_depth_size(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_stencil_size(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_shared_size(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<boolean>
	texture_compressed(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_compressed_image_size(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<oglplus::pixel_data_internal_format>
	texture_internal_format(TNT tnt, GLint level = 0)
	noexcept;

	template <typename TNT>
	static 
	outcome<void>
	texture_min_filter(
		TNT tnt,
		oglplus::texture_min_filter value
	) noexcept;

	template <typename TNT>
	static 
	outcome<oglplus::texture_min_filter>
	texture_min_filter(TNT tnt)
	noexcept;

	template <typename TNT>
	static 
	outcome<void>
	texture_mag_filter(
		TNT tnt,
		oglplus::texture_mag_filter value
	) noexcept;

	template <typename TNT>
	static 
	outcome<oglplus::texture_mag_filter>
	texture_mag_filter(TNT tnt)
	noexcept;

	template <typename TNT>
	static 
	outcome<void>
	texture_compare_func(
		TNT tnt,
		oglplus::compare_function value
	) noexcept;

	template <typename TNT>
	static 
	outcome<oglplus::compare_function>
	texture_compare_func(TNT tnt)
	noexcept;

	template <typename TNT>
	static 
	outcome<void>
	texture_compare_mode(
		TNT tnt,
		oglplus::texture_compare_mode value
	) noexcept;

	template <typename TNT>
	static 
	outcome<oglplus::texture_compare_mode>
	texture_compare_mode(TNT tnt)
	noexcept;

	template <typename TNT>
	static 
	outcome<void>
	texture_lod_bias(TNT tnt, GLfloat value)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLfloat>
	texture_lod_bias(TNT tnt)
	noexcept;
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
	typedef oper::texture_ops _ops;

#if defined(GL_VERSION_4_5)
	typedef obj_dsa_ops _dsa_ops;

	using obj_zero_dsa_ops<texture_name>::obj_zero_dsa_ops;

	texture_name _get_tnt(void) const
	noexcept
	{
		return {*this};
	}
#elif defined(GL_EXT_direct_state_access)
	typedef obj_zero_dsa_ops _dsa_ops;

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
		return _ops::texture_width(_get_tnt(), level);
	}

	outcome<GLsizei>
	height(GLint level = 0) const
	noexcept
	{
		return _ops::texture_height(_get_tnt(), level);
	}

	outcome<GLsizei>
	depth(GLint level = 0) const
	noexcept
	{
		return _ops::texture_depth(_get_tnt(), level);
	}

	outcome<pixel_data_type>
	red_type(void) const
	noexcept
	{
		return _ops::texture_red_type(_get_tnt());
	}

	outcome<GLsizei>
	red_size(GLint level = 0) const
	noexcept
	{
		return _ops::texture_red_size(_get_tnt(), level);
	}

	outcome<pixel_data_type>
	green_type(void) const
	noexcept
	{
		return _ops::texture_green_type(_get_tnt());
	}

	outcome<GLsizei>
	green_size(GLint level = 0) const
	noexcept
	{
		return _ops::texture_green_size(_get_tnt(), level);
	}

	outcome<pixel_data_type>
	blue_type(void) const
	noexcept
	{
		return _ops::texture_blue_type(_get_tnt());
	}

	outcome<GLsizei>
	blue_size(GLint level = 0) const
	noexcept
	{
		return _ops::texture_blue_size(_get_tnt(), level);
	}

	outcome<pixel_data_type>
	alpha_type(void) const
	noexcept
	{
		return _ops::texture_alpha_type(_get_tnt());
	}

	outcome<GLsizei>
	alpha_size(GLint level = 0) const
	noexcept
	{
		return _ops::texture_alpha_size(_get_tnt(), level);
	}

	outcome<pixel_data_type>
	depth_type(void) const
	noexcept
	{
		return _ops::texture_depth_type(_get_tnt());
	}

	outcome<GLsizei>
	depth_size(GLint level = 0) const
	noexcept
	{
		return _ops::texture_depth_size(_get_tnt(), level);
	}

	outcome<GLsizei>
	stencil_size(GLint level = 0) const
	noexcept
	{
		return _ops::texture_stencil_size(_get_tnt(), level);
	}

	outcome<GLsizei>
	shared_size(GLint level = 0) const
	noexcept
	{
		return _ops::texture_shared_size(_get_tnt(), level);
	}

	outcome<boolean>
	compressed(GLint level = 0) const
	noexcept
	{
		return _ops::texture_compressed(_get_tnt(), level);
	}

	outcome<GLsizei>
	compressed_image_size(GLint level = 0) const
	noexcept
	{
		return _ops::texture_compressed_image_size(_get_tnt(), level);
	}

	outcome<oglplus::pixel_data_internal_format>
	internal_format(GLint level = 0) const
	noexcept
	{
		return _ops::texture_internal_format(_get_tnt(), level);
	}

	outcome<_dsa_ops&>
	min_filter(oglplus::texture_min_filter value)
	noexcept
	{
		return {_ops::texture_min_filter(_get_tnt(), value), *this};
	}

	outcome<oglplus::texture_min_filter>
	min_filter(void) const
	noexcept
	{
		return _ops::texture_min_filter(_get_tnt());
	}

	outcome<_dsa_ops&>
	mag_filter(oglplus::texture_mag_filter value)
	noexcept
	{
		return {_ops::texture_mag_filter(_get_tnt(), value), *this};
	}

	outcome<oglplus::texture_mag_filter>
	mag_filter(void) const
	noexcept
	{
		return _ops::texture_mag_filter(_get_tnt());
	}

	outcome<_dsa_ops&>
	compare_func(oglplus::compare_function value)
	noexcept
	{
		return {_ops::texture_compare_func(_get_tnt(), value), *this};
	}

	outcome<oglplus::compare_function>
	compare_func(void) const
	noexcept
	{
		return _ops::texture_compare_func(_get_tnt());
	}

	outcome<_dsa_ops&>
	compare_mode(oglplus::texture_compare_mode value)
	noexcept
	{
		return {_ops::texture_compare_mode(_get_tnt(), value), *this};
	}

	outcome<oglplus::texture_compare_mode>
	compare_mode(void) const
	noexcept
	{
		return _ops::texture_compare_mode(_get_tnt());
	}

	outcome<_dsa_ops&>
	lod_bias(GLfloat value)
	noexcept
	{
		return {_ops::texture_lod_bias(_get_tnt(), value), *this};
	}

	outcome<GLfloat>
	lod_bias(void) const
	noexcept
	{
		return _ops::texture_lod_bias(_get_tnt());
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
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using texture = object_owner<tag::texture>;

static const object_zero_and_ops<tag::texture>
	default_texture = {};

} // namespace oglplus

#include <oglplus/texture.inl>

#endif // include guard
