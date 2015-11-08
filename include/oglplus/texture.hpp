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
private:
	static
	texture_target_only _wrap(texture_target tgt)
	noexcept
	{
		return {tgt};
	}

	template <typename X>
	static
	auto _wrap(X& x)
	noexcept
	{
		return wrap_texture_name_or_target(x);
	}

	template <typename X>
	using _disable_if_target = typename std::enable_if<
		!std::is_convertible<X, texture_target>::value
	>::type;
public:

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

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
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

	template <typename R, typename P, typename N, typename T>
	static
	outcome<R>
	return_texture_parameter_i(
		object_name_or_target<N, T> tnt, 
		oglplus::texture_parameter parameter
	) noexcept;

	template <typename R, typename P, typename N, typename T>
	static
	outcome<R>
	return_texture_level_parameter_i(
		object_name_or_target<N, T> tnt, 
		GLint level,
		oglplus::texture_parameter parameter
	) noexcept;

	template <typename R, typename N, typename T>
	static
	outcome<R>
	return_texture_parameter_f(
		object_name_or_target<N, T> tnt, 
		oglplus::texture_parameter parameter
	) noexcept;

	// texture_width
	template <typename N, typename T>
	static 
	outcome<GLsizei>
	texture_width(object_name_or_target<N, T> tnt, GLint level = 0)
	noexcept;

	static 
	outcome<GLsizei>
	texture_width(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_width(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLsizei>
	texture_width(X& tex, GLint level = 0)
	noexcept
	{ return texture_width(_wrap(tex), level); }

	// texture_height
	template <typename N, typename T>
	static 
	outcome<GLsizei>
	texture_height(object_name_or_target<N, T> tnt, GLint level = 0)
	noexcept;

	static 
	outcome<GLsizei>
	texture_height(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_height(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLsizei>
	texture_height(X& tex, GLint level = 0)
	noexcept
	{ return texture_height(_wrap(tex), level); }

	// texture_depth
	template <typename N, typename T>
	static 
	outcome<GLsizei>
	texture_depth(object_name_or_target<N, T> tnt, GLint level = 0)
	noexcept;

	static 
	outcome<GLsizei>
	texture_depth(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_depth(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLsizei>
	texture_depth(X& tex, GLint level = 0)
	noexcept
	{ return texture_depth(_wrap(tex), level); }

	// texture_red_type
	template <typename N, typename T>
	static 
	outcome<pixel_data_type>
	texture_red_type(object_name_or_target<N, T> tnt)
	noexcept;

	static 
	outcome<pixel_data_type>
	texture_red_type(texture_target tgt)
	noexcept
	{ return texture_red_type(_wrap(tgt)); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<pixel_data_type>
	texture_red_type(X& tex)
	noexcept
	{ return texture_red_type(_wrap(tex)); }

	// texture_red_size
	template <typename N, typename T>
	static 
	outcome<GLsizei>
	texture_red_size(object_name_or_target<N, T> tnt, GLint level = 0)
	noexcept;

	static 
	outcome<GLsizei>
	texture_red_size(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_red_size(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLsizei>
	texture_red_size(X& tex, GLint level = 0)
	noexcept
	{ return texture_red_size(_wrap(tex), level); }

	// texture_green_type
	template <typename N, typename T>
	static 
	outcome<pixel_data_type>
	texture_green_type(object_name_or_target<N, T> tnt)
	noexcept;

	static 
	outcome<pixel_data_type>
	texture_green_type(texture_target tgt)
	noexcept
	{ return texture_green_type(_wrap(tgt)); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<pixel_data_type>
	texture_green_type(X& tex)
	noexcept
	{ return texture_green_type(_wrap(tex)); }

	// texture_green_size
	template <typename N, typename T>
	static 
	outcome<GLsizei>
	texture_green_size(object_name_or_target<N, T> tnt, GLint level = 0)
	noexcept;

	static 
	outcome<GLsizei>
	texture_green_size(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_green_size(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLsizei>
	texture_green_size(X& tex, GLint level = 0)
	noexcept
	{ return texture_green_size(_wrap(tex), level); }

	// texture_blue_type
	template <typename N, typename T>
	static 
	outcome<pixel_data_type>
	texture_blue_type(object_name_or_target<N, T> tnt)
	noexcept;

	static 
	outcome<pixel_data_type>
	texture_blue_type(texture_target tgt)
	noexcept
	{ return texture_blue_type(_wrap(tgt)); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<pixel_data_type>
	texture_blue_type(X& tex)
	noexcept
	{ return texture_blue_type(_wrap(tex)); }

	// texture_blue_size
	template <typename N, typename T>
	static 
	outcome<GLsizei>
	texture_blue_size(object_name_or_target<N, T> tnt, GLint level = 0)
	noexcept;

	static 
	outcome<GLsizei>
	texture_blue_size(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_blue_size(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLsizei>
	texture_blue_size(X& tex, GLint level = 0)
	noexcept
	{ return texture_blue_size(_wrap(tex), level); }

	// texture_alpha_type
	template <typename N, typename T>
	static 
	outcome<pixel_data_type>
	texture_alpha_type(object_name_or_target<N, T> tnt)
	noexcept;

	static 
	outcome<pixel_data_type>
	texture_alpha_type(texture_target tgt)
	noexcept
	{ return texture_alpha_type(_wrap(tgt)); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<pixel_data_type>
	texture_alpha_type(X& tex)
	noexcept
	{ return texture_alpha_type(_wrap(tex)); }

	// texture_alpha_size
	template <typename N, typename T>
	static 
	outcome<GLsizei>
	texture_alpha_size(object_name_or_target<N, T> tnt, GLint level = 0)
	noexcept;

	static 
	outcome<GLsizei>
	texture_alpha_size(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_alpha_size(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLsizei>
	texture_alpha_size(X& tex, GLint level = 0)
	noexcept
	{ return texture_alpha_size(_wrap(tex), level); }

	// texture_depth_type
	template <typename N, typename T>
	static 
	outcome<pixel_data_type>
	texture_depth_type(object_name_or_target<N, T> tnt)
	noexcept;

	static 
	outcome<pixel_data_type>
	texture_depth_type(texture_target tgt)
	noexcept
	{ return texture_depth_type(_wrap(tgt)); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<pixel_data_type>
	texture_depth_type(X& tex)
	noexcept
	{ return texture_depth_type(_wrap(tex)); }

	// texture_depth_size
	template <typename N, typename T>
	static 
	outcome<GLsizei>
	texture_depth_size(object_name_or_target<N, T> tnt, GLint level = 0)
	noexcept;

	static 
	outcome<GLsizei>
	texture_depth_size(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_depth_size(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLsizei>
	texture_depth_size(X& tex, GLint level = 0)
	noexcept
	{ return texture_depth_size(_wrap(tex), level); }

	// texture_stencil_size
	template <typename N, typename T>
	static 
	outcome<GLsizei>
	texture_stencil_size(object_name_or_target<N, T> tnt, GLint level = 0)
	noexcept;

	static 
	outcome<GLsizei>
	texture_stencil_size(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_stencil_size(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLsizei>
	texture_stencil_size(X& tex, GLint level = 0)
	noexcept
	{ return texture_stencil_size(_wrap(tex), level); }

	// texture_shared_size
	template <typename N, typename T>
	static 
	outcome<GLsizei>
	texture_shared_size(object_name_or_target<N, T> tnt, GLint level = 0)
	noexcept;

	static 
	outcome<GLsizei>
	texture_shared_size(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_shared_size(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLsizei>
	texture_shared_size(X& tex, GLint level = 0)
	noexcept
	{ return texture_shared_size(_wrap(tex), level); }

	// texture_compressed
	template <typename N, typename T>
	static 
	outcome<boolean>
	texture_compressed(object_name_or_target<N, T> tnt, GLint level = 0)
	noexcept;

	static 
	outcome<boolean>
	texture_compressed(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_compressed(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<boolean>
	texture_compressed(X& tex, GLint level = 0)
	noexcept
	{ return texture_compressed(_wrap(tex), level); }

	// texture_compressed_image_size
	template <typename N, typename T>
	static 
	outcome<GLsizei>
	texture_compressed_image_size(
		object_name_or_target<N, T> tnt,
		GLint level = 0
	) noexcept;

	static 
	outcome<GLsizei>
	texture_compressed_image_size(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_compressed_image_size(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLsizei>
	texture_compressed_image_size(X& tex, GLint level = 0)
	noexcept
	{ return texture_compressed_image_size(_wrap(tex), level); }

	// texture_internal_format
	template <typename N, typename T>
	static 
	outcome<oglplus::pixel_data_internal_format>
	texture_internal_format(
		object_name_or_target<N, T> tnt,
		GLint level = 0
	) noexcept;

	static 
	outcome<oglplus::pixel_data_internal_format>
	texture_internal_format(texture_target tgt, GLint level = 0)
	noexcept
	{ return texture_internal_format(_wrap(tgt), level); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<oglplus::pixel_data_internal_format>
	texture_internal_format(X& tex, GLint level = 0)
	noexcept
	{ return texture_internal_format(_wrap(tex), level); }

	// texture_min_filter
	template <typename N, typename T>
	static 
	outcome<void>
	texture_min_filter(
		object_name_or_target<N, T> tnt,
		oglplus::texture_min_filter value
	) noexcept;

	static 
	outcome<void>
	texture_min_filter(
		texture_target tgt,
		oglplus::texture_min_filter value
	) noexcept
	{ return texture_min_filter(_wrap(tgt), value); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<void>
	texture_min_filter(
		X& tex,
		oglplus::texture_min_filter value
	) noexcept
	{ return texture_min_filter(_wrap(tex), value); }

	template <typename N, typename T>
	static 
	outcome<oglplus::texture_min_filter>
	texture_min_filter(object_name_or_target<N, T> tnt)
	noexcept;

	static 
	outcome<oglplus::texture_min_filter>
	texture_min_filter(texture_target tgt)
	noexcept
	{ return texture_min_filter(_wrap(tgt)); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<oglplus::texture_min_filter>
	texture_min_filter(X& tex)
	noexcept
	{ return texture_min_filter(_wrap(tex)); }

	// texture_mag_filter
	template <typename N, typename T>
	static 
	outcome<void>
	texture_mag_filter(
		object_name_or_target<N, T> tnt,
		oglplus::texture_mag_filter value
	) noexcept;

	static 
	outcome<void>
	texture_mag_filter(
		texture_target tgt,
		oglplus::texture_mag_filter value
	) noexcept
	{ return texture_mag_filter(_wrap(tgt), value); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<void>
	texture_mag_filter(
		X& tex,
		oglplus::texture_mag_filter value
	) noexcept
	{ return texture_mag_filter(_wrap(tex), value); }

	template <typename N, typename T>
	static 
	outcome<oglplus::texture_mag_filter>
	texture_mag_filter(object_name_or_target<N, T> tnt)
	noexcept;

	static 
	outcome<oglplus::texture_mag_filter>
	texture_mag_filter(texture_target tgt)
	noexcept
	{ return texture_mag_filter(_wrap(tgt)); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<oglplus::texture_mag_filter>
	texture_mag_filter(X& tex)
	noexcept
	{ return texture_mag_filter(_wrap(tex)); }

	// texture_compare_func
	template <typename N, typename T>
	static 
	outcome<void>
	texture_compare_func(
		object_name_or_target<N, T> tnt,
		oglplus::compare_function value
	) noexcept;

	static 
	outcome<void>
	texture_compare_func(
		texture_target tgt,
		oglplus::compare_function value
	) noexcept
	{ return texture_compare_func(_wrap(tgt), value); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<void>
	texture_compare_func(
		X& tex,
		oglplus::compare_function value
	) noexcept
	{ return texture_compare_func(_wrap(tex), value); }

	template <typename N, typename T>
	static 
	outcome<oglplus::compare_function>
	texture_compare_func(object_name_or_target<N, T> tnt)
	noexcept;

	static 
	outcome<oglplus::compare_function>
	texture_compare_func(texture_target tgt)
	noexcept
	{ return texture_compare_func(_wrap(tgt)); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<oglplus::compare_function>
	texture_compare_func(X& tex)
	noexcept
	{ return texture_compare_func(_wrap(tex)); }

	// texture_compare_mode
	template <typename N, typename T>
	static 
	outcome<void>
	texture_compare_mode(
		object_name_or_target<N, T> tnt,
		oglplus::texture_compare_mode value
	) noexcept;

	static 
	outcome<void>
	texture_compare_mode(
		texture_target tgt,
		oglplus::texture_compare_mode value
	) noexcept
	{ return texture_compare_mode(_wrap(tgt), value); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<void>
	texture_compare_mode(
		X& tex,
		oglplus::texture_compare_mode value
	) noexcept
	{ return texture_compare_mode(_wrap(tex), value); }

	template <typename N, typename T>
	static 
	outcome<oglplus::texture_compare_mode>
	texture_compare_mode(object_name_or_target<N, T> tnt)
	noexcept;

	static 
	outcome<oglplus::texture_compare_mode>
	texture_compare_mode(texture_target tgt)
	noexcept
	{ return texture_compare_mode(_wrap(tgt)); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<oglplus::texture_compare_mode>
	texture_compare_mode(X& tex)
	noexcept
	{ return texture_compare_mode(_wrap(tex)); }

	// texture_lod_bias
	template <typename N, typename T>
	static 
	outcome<void>
	texture_lod_bias(object_name_or_target<N, T> tnt, GLfloat value)
	noexcept;

	static 
	outcome<void>
	texture_lod_bias(texture_target tgt, GLfloat value)
	noexcept
	{ return texture_lod_bias(_wrap(tgt), value); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<void>
	texture_lod_bias(X& tex, GLfloat value)
	noexcept
	{ return texture_lod_bias(_wrap(tex), value); }

	template <typename N, typename T>
	static 
	outcome<GLfloat>
	texture_lod_bias(object_name_or_target<N, T> tnt)
	noexcept;

	static 
	outcome<GLfloat>
	texture_lod_bias(texture_target tgt)
	noexcept
	{ return texture_lod_bias(_wrap(tgt)); }

	template <typename X, typename = _disable_if_target<X>>
	static 
	outcome<GLfloat>
	texture_lod_bias(X& tex)
	noexcept
	{ return texture_lod_bias(_wrap(tex)); }
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

	operator texture_name_and_target (void) const
	noexcept
	{
		return _get_tnt();
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

static inline
auto wrap_texture_name_or_target(const texture& tex)
noexcept
{
	return tex._get_tnt();
}

static const object_zero_and_ops<tag::texture>
	default_texture = {};

} // namespace oglplus

#include <oglplus/texture.inl>

#endif // include guard
