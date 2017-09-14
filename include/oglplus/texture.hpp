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

static inline
texture_target_only
wrap_object_name_or_target(texture_target target)
noexcept { return {target}; }

namespace oper {

struct texture_ops
{
private:
	static
	texture_target_only _wrap(texture_target tgt)
	noexcept { return {tgt}; }

	template <typename X>
	static
	auto _wrap(const X& x)
	noexcept { return wrap_object_name_or_target(x); }

	template <typename X>
	using _disable_if_target = std::enable_if_t<
		!std::is_convertible_v<X, texture_target>
	>;
public:

	static
	outcome<void>
	active_texture(texture_unit unit)
	noexcept;

	static
	outcome<texture_unit>
	get_active_texture(void)
	noexcept;

	static
	outcome<void>
	bind_texture(texture_target target, texture_name tex)
	noexcept;

#if defined(GL_VERSION_4_5)
	static
	outcome<void>
	bind_texture_unit(texture_unit unit, texture_name tex)
	noexcept;
#endif

#if defined(GL_VERSION_4_4)
	template <typename S>
	static
	outcome<void>
	bind_textures(
		texture_unit first,
		const object_names<tag::texture, S>& textures
	) noexcept;
#endif

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

#if defined(GL_VERSION_3_0)
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
	texture_sub_image_1d(
		texture_target_only tnt,
		GLint level,
		GLint xoffset,
		GLsizei width,
		pixel_data_format format,
		pixel_data_type type,
		const_memory_block data
	) noexcept;

	static
	outcome<void>
	texture_sub_image_1d(
		texture_target_only tnt,
		GLint xoffset,
		const image_spec& img,
		GLint level = 0
	) noexcept;
#endif // GL_VERSION_3_0

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
	texture_sub_image_2d(
		texture_target_only tnt,
		GLint level,
		GLint xoffset,
		GLint yoffset,
		GLsizei width,
		GLsizei height,
		pixel_data_format format,
		pixel_data_type type,
		const_memory_block data
	) noexcept;

	static
	outcome<void>
	texture_sub_image_2d(
		texture_target_only tnt,
		GLint xoffset,
		GLint yoffset,
		const image_spec& img,
		GLint level = 0
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
	texture_sub_image_3d(
		texture_target_only tnt,
		GLint level,
		GLint xoffset,
		GLint yoffset,
		GLint zoffset,
		GLsizei width,
		GLsizei height,
		GLsizei depth,
		pixel_data_format format,
		pixel_data_type type,
		const_memory_block data
	) noexcept;

	static
	outcome<void>
	texture_sub_image_3d(
		texture_target_only tnt,
		GLint xoffset,
		GLint yoffset,
		GLint zoffset,
		const image_spec& img,
		GLint level = 0
	) noexcept;

#if defined(GL_EXT_direct_state_access)
#if defined(GL_VERSION_3_0)
	static
	outcome<void>
	texture_image_1d(
		texture_name_and_target tnt,
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
		texture_name_and_target tnt,
		const image_spec& img,
		GLint level = 0,
		GLint border = 0
	) noexcept;

	static
	outcome<void>
	texture_sub_image_1d(
		texture_name_and_target tnt,
		GLint level,
		GLint xoffset,
		GLsizei width,
		pixel_data_format format,
		pixel_data_type type,
		const_memory_block data
	) noexcept;

	static
	outcome<void>
	texture_sub_image_1d(
		texture_name_and_target tnt,
		GLint xoffset,
		const image_spec& img,
		GLint level = 0
	) noexcept;
#endif

	static
	outcome<void>
	texture_image_2d(
		texture_name_and_target tnt,
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
		texture_name_and_target tnt,
		const image_spec& img,
		GLint level = 0,
		GLint border = 0
	) noexcept;

	static
	outcome<void>
	texture_sub_image_2d(
		texture_name_and_target tnt,
		GLint level,
		GLint xoffset,
		GLint yoffset,
		GLsizei width,
		GLsizei height,
		pixel_data_format format,
		pixel_data_type type,
		const_memory_block data
	) noexcept;

	static
	outcome<void>
	texture_sub_image_2d(
		texture_name_and_target tnt,
		GLint xoffset,
		GLint yoffset,
		const image_spec& img,
		GLint level = 0
	) noexcept;

	static
	outcome<void>
	texture_image_3d(
		texture_name_and_target tnt,
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
		texture_name_and_target tnt,
		const image_spec& img,
		GLint level = 0,
		GLint border = 0
	) noexcept;

	static
	outcome<void>
	texture_sub_image_3d(
		texture_name_and_target tnt,
		GLint level,
		GLint xoffset,
		GLint yoffset,
		GLint zoffset,
		GLsizei width,
		GLsizei height,
		GLsizei depth,
		pixel_data_format format,
		pixel_data_type type,
		const_memory_block data
	) noexcept;

	static
	outcome<void>
	texture_sub_image_3d(
		texture_name_and_target tnt,
		GLint xoffset,
		GLint yoffset,
		GLint zoffset,
		const image_spec& img,
		GLint level = 0
	) noexcept;
#endif // GL_EXT_direct_state_access

	static
	outcome<void>
	generate_texture_mipmap(texture_target_only tnt)
	noexcept;


#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	static
	outcome<void>
	generate_texture_mipmap(texture_name_only tnt)
	noexcept;
#endif

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
		span<GLint> values
	) noexcept;

#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
	static
	outcome<void>
	get_texture_level_parameter_iv(
		texture_target_only tnt,
		GLint level,
		oglplus::texture_parameter param,
		span<GLint> values
	) noexcept;
#endif

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
		span<GLfloat> values
	) noexcept;

	static
	outcome<void>
	texture_parameter_fv(
		texture_target_only tnt,
		oglplus::texture_parameter param,
		span<const GLfloat> values
	) noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
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
		span<GLint> values
	) noexcept;

#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
	static
	outcome<void>
	get_texture_level_parameter_iv(
		texture_name_only tnt,
		GLint level,
		oglplus::texture_parameter param,
		span<GLint> values
	) noexcept;
#endif

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
		span<GLfloat> values
	) noexcept;

	static
	outcome<void>
	texture_parameter_fv(
		texture_name_only tnt,
		oglplus::texture_parameter param,
		span<const GLfloat> values
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
		span<GLint> values
	) noexcept;

#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
	static
	outcome<void>
	get_texture_level_parameter_iv(
		texture_name_and_target tnt,
		GLint level,
		oglplus::texture_parameter param,
		span<GLint> values
	) noexcept;
#endif

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
		span<GLfloat> values
	) noexcept;

	static
	outcome<void>
	texture_parameter_fv(
		texture_name_and_target tnt,
		oglplus::texture_parameter param,
		span<const GLfloat> values
	) noexcept;

#endif

	template <typename R, typename P, typename N, typename T>
	static
	outcome<R>
	return_texture_parameter_i(
		object_name_or_target<N, T> tnt,
		oglplus::texture_parameter parameter
	) noexcept;

#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
	template <typename R, typename P, typename N, typename T>
	static
	outcome<R>
	return_texture_level_parameter_i(
		object_name_or_target<N, T> tnt,
		GLint level,
		oglplus::texture_parameter parameter
	) noexcept;
#endif

	template <typename R, typename N, typename T>
	static
	outcome<R>
	return_texture_parameter_f(
		object_name_or_target<N, T> tnt,
		oglplus::texture_parameter parameter
	) noexcept;

#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
	// texture_width
	template <typename TNT>
	static
	outcome<GLsizei>
	get_texture_width(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_height
	template <typename TNT>
	static
	outcome<GLsizei>
	get_texture_height(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_depth
	template <typename TNT>
	static
	outcome<GLsizei>
	get_texture_depth(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_red_type
	template <typename TNT>
	static
	outcome<pixel_data_type>
	get_texture_red_type(const TNT& tnt)
	noexcept;

	// texture_red_size
	template <typename TNT>
	static
	outcome<GLsizei>
	get_texture_red_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_green_type
	template <typename TNT>
	static
	outcome<pixel_data_type>
	get_texture_green_type(const TNT& tnt)
	noexcept;

	// texture_green_size
	template <typename TNT>
	static
	outcome<GLsizei>
	get_texture_green_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_blue_type
	template <typename TNT>
	static
	outcome<pixel_data_type>
	get_texture_blue_type(const TNT& tnt)
	noexcept;

	// texture_blue_size
	template <typename TNT>
	static
	outcome<GLsizei>
	get_texture_blue_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_alpha_type
	template <typename TNT>
	static
	outcome<pixel_data_type>
	get_texture_alpha_type(const TNT& tnt)
	noexcept;

	// texture_alpha_size
	template <typename TNT>
	static
	outcome<GLsizei>
	get_texture_alpha_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_depth_type
	template <typename TNT>
	static
	outcome<pixel_data_type>
	get_texture_depth_type(const TNT& tnt)
	noexcept;

	// texture_depth_size
	template <typename TNT>
	static
	outcome<GLsizei>
	get_texture_depth_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_stencil_size
	template <typename TNT>
	static
	outcome<GLsizei>
	get_texture_stencil_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_shared_size
	template <typename TNT>
	static
	outcome<GLsizei>
	get_texture_shared_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_compressed
	template <typename TNT>
	static
	outcome<boolean>
	is_texture_compressed(const TNT& tnt, GLint level = 0)
	noexcept;

#if defined(GL_TEXTURE_COMPRESSED_IMAGE_SIZE)
	// texture_compressed_image_size
	template <typename TNT>
	static
	outcome<GLsizei>
	get_texture_compressed_image_size(const TNT& tnt, GLint level = 0)
	noexcept;
#endif

	// texture_internal_format
	template <typename TNT>
	static
	outcome<oglplus::pixel_data_internal_format>
	get_texture_internal_format(const TNT& tnt, GLint level = 0)
	noexcept;
#endif

	// texture_min_filter
	template <typename TNT>
	static
	outcome<void>
	texture_min_filter(const TNT& tnt, oglplus::texture_min_filter value)
	noexcept;

	template <typename TNT>
	static
	outcome<oglplus::texture_min_filter>
	get_texture_min_filter(const TNT& tnt)
	noexcept;

	// texture_mag_filter
	template <typename TNT>
	static
	outcome<void>
	texture_mag_filter(const TNT& tnt, oglplus::texture_mag_filter value)
	noexcept;

	template <typename TNT>
	static
	outcome<oglplus::texture_mag_filter>
	get_texture_mag_filter(const TNT& tnt)
	noexcept;

	// texture_compare_func
	template <typename TNT>
	static
	outcome<void>
	texture_compare_func(const TNT& tnt, oglplus::compare_function value)
	noexcept;

	template <typename TNT>
	static
	outcome<oglplus::compare_function>
	get_texture_compare_func(const TNT& tnt)
	noexcept;

	// texture_compare_mode
	template <typename TNT>
	static
	outcome<void>
	texture_compare_mode(
		const TNT& tnt,
		oglplus::texture_compare_mode value
	) noexcept;

	template <typename TNT>
	static
	outcome<oglplus::texture_compare_mode>
	get_texture_compare_mode(const TNT& tnt)
	noexcept;

	// texture_wrap
	template <typename TNT>
	static
	outcome<void>
	texture_wrap(
		const TNT& tnt,
		texture_wrap_coord coord,
		texture_wrap_mode value
	) noexcept;

	template <typename TNT>
	static
	outcome<texture_wrap_mode>
	get_texture_wrap(const TNT& tnt, texture_wrap_coord coord)
	noexcept;

	// texture_swizzle
	template <typename TNT>
	static
	outcome<void>
	texture_swizzle(
		const TNT& tnt,
		texture_swizzle_coord coord,
		texture_swizzle_mode value
	) noexcept;

	template <typename TNT>
	static
	outcome<texture_swizzle_mode>
	get_texture_swizzle(
		const TNT& tnt,
		texture_swizzle_coord coord
	) noexcept;

#if defined(GL_TEXTURE_LOD_BIAS)
	// texture_lod_bias
	template <typename TNT>
	static
	outcome<void>
	texture_lod_bias(const TNT& tnt, GLfloat value)
	noexcept;

	template <typename TNT>
	static
	outcome<GLfloat>
	get_texture_lod_bias(const TNT& tnt)
	noexcept;
#endif

	// texture_min_lod
	template <typename TNT>
	static
	outcome<void>
	texture_min_lod(const TNT& tnt, GLfloat value)
	noexcept;

	template <typename TNT>
	static
	outcome<GLfloat>
	get_texture_min_lod(const TNT& tnt)
	noexcept;

	// texture_max_lod
	template <typename TNT>
	static
	outcome<void>
	texture_max_lod(const TNT& tnt, GLfloat value)
	noexcept;

	template <typename TNT>
	static
	outcome<GLfloat>
	get_texture_max_lod(const TNT& tnt)
	noexcept;

#if defined(GL_TEXTURE_BORDER_COLOR)
	// texture_border_color
	template <typename TNT>
	static
	outcome<void>
	texture_border_color(const TNT& tnt, span<const GLfloat> c)
	noexcept;
#endif

	template <typename TNT>
	static
	outcome<void>
	texture_border_color(
		const TNT& tnt,
		GLfloat r,
		GLfloat g,
		GLfloat b,
		GLfloat a
	) noexcept;
};

} // namespace oper

template <typename Derived, typename Base>
struct obj_member_ops<tag::texture, Derived, Base>
 : Base
{
private:
	typedef oper::texture_ops _ops;

	Derived& _self(void)
	noexcept { return *static_cast<Derived*>(this); }

	const Base& _base(void) const
	noexcept { return *static_cast<const Base*>(this); }

	static
	texture_target_only _do_get_tnt(texture_target tgt) {
		return {tgt};
	}

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	typedef std::conditional_t<
		std::is_same_v<Base, texture_target>,
		texture_target_only,
		texture_name_only
	> _tnt;

	static
	texture_name_only _do_get_tnt(texture_name name) {
		return {name};
	}
#elif defined(GL_EXT_direct_state_access)
	texture_target target;

	typedef std::conditional_t<
		std::is_same_v<Base, texture_target>,
		texture_target_only,
		texture_name_and_target
	> _tnt;

	texture_name_and_target _do_get_tnt(texture_name name) const
	noexcept { return {name, target}; }
#else
	typedef texture_target_only _tnt;
#endif
	_tnt _get_tnt(void) const
	noexcept { return _do_get_tnt(_base()); }

	friend inline
	_tnt
	wrap_object_name_or_target(const obj_member_ops& tex)
	noexcept { return tex._get_tnt(); }

protected:
	using Base::Base;
public:
#if defined(GL_VERSION_4_5)
	outcome<Derived&>
	bind_unit(texture_unit unit)
	noexcept {
		return {_ops::bind_texture_unit(unit, _get_tnt()), _self()};
	}
#endif

#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
	outcome<GLsizei>
	get_width(GLint level = 0) const
	noexcept { return _ops::get_texture_width(_get_tnt(), level); }

	outcome<GLsizei>
	get_height(GLint level = 0) const
	noexcept { return _ops::get_texture_height(_get_tnt(), level); }

	outcome<GLsizei>
	get_depth(GLint level = 0) const
	noexcept { return _ops::get_texture_depth(_get_tnt(), level); }

	outcome<pixel_data_type>
	get_red_type(void) const
	noexcept { return _ops::get_texture_red_type(_get_tnt()); }

	outcome<GLsizei>
	get_red_size(GLint level = 0) const
	noexcept { return _ops::get_texture_red_size(_get_tnt(), level); }

	outcome<pixel_data_type>
	get_green_type(void) const
	noexcept { return _ops::get_texture_green_type(_get_tnt()); }

	outcome<GLsizei>
	get_green_size(GLint level = 0) const
	noexcept { return _ops::get_texture_green_size(_get_tnt(), level); }

	outcome<pixel_data_type>
	get_blue_type(void) const
	noexcept { return _ops::get_texture_blue_type(_get_tnt()); }

	outcome<GLsizei>
	get_blue_size(GLint level = 0) const
	noexcept { return _ops::get_texture_blue_size(_get_tnt(), level); }

	outcome<pixel_data_type>
	get_alpha_type(void) const
	noexcept { return _ops::get_texture_alpha_type(_get_tnt()); }

	outcome<GLsizei>
	get_alpha_size(GLint level = 0) const
	noexcept { return _ops::get_texture_alpha_size(_get_tnt(), level); }

	outcome<pixel_data_type>
	get_depth_type(void) const
	noexcept { return _ops::get_texture_depth_type(_get_tnt()); }

	outcome<GLsizei>
	get_depth_size(GLint level = 0) const
	noexcept { return _ops::get_texture_depth_size(_get_tnt(), level); }

	outcome<GLsizei>
	get_stencil_size(GLint level = 0) const
	noexcept { return _ops::get_texture_stencil_size(_get_tnt(), level); }

	outcome<GLsizei>
	get_shared_size(GLint level = 0) const
	noexcept { return _ops::get_texture_shared_size(_get_tnt(), level); }

	outcome<boolean>
	is_compressed(GLint level = 0) const
	noexcept { return _ops::is_texture_compressed(_get_tnt(), level); }

#if defined(GL_TEXTURE_COMPRESSED_IMAGE_SIZE)
	outcome<GLsizei>
	get_compressed_image_size(GLint level = 0) const
	noexcept {
		return _ops::get_texture_compressed_image_size(_get_tnt(), level);
	}
#endif

	outcome<oglplus::pixel_data_internal_format>
	get_internal_format(GLint level = 0) const
	noexcept { return _ops::get_texture_internal_format(_get_tnt(), level); }
#endif

	outcome<Derived&>
	min_filter(oglplus::texture_min_filter value)
	noexcept {
		return {_ops::texture_min_filter(_get_tnt(), value), _self()};
	}

	outcome<oglplus::texture_min_filter>
	get_min_filter(void) const
	noexcept { return _ops::get_texture_min_filter(_get_tnt()); }

	outcome<Derived&>
	mag_filter(oglplus::texture_mag_filter value)
	noexcept {
		return {_ops::texture_mag_filter(_get_tnt(), value), _self()};
	}

	outcome<oglplus::texture_mag_filter>
	get_mag_filter(void) const
	noexcept { return _ops::get_texture_mag_filter(_get_tnt()); }

	outcome<Derived&>
	compare_func(oglplus::compare_function value)
	noexcept {
		return {
			_ops::texture_compare_func(_get_tnt(), value),
			_self()
		};
	}

	outcome<oglplus::compare_function>
	get_compare_func(void) const
	noexcept { return _ops::get_texture_compare_func(_get_tnt()); }

	outcome<Derived&>
	compare_mode(oglplus::texture_compare_mode value)
	noexcept {
		return {
			_ops::texture_compare_mode(_get_tnt(), value),
			_self()
		};
	}

	outcome<oglplus::texture_compare_mode>
	get_compare_mode(void) const
	noexcept { return _ops::get_texture_compare_mode(_get_tnt()); }

	outcome<Derived&>
	wrap(texture_wrap_coord coord, texture_wrap_mode value)
	noexcept {
		return {_ops::texture_wrap(_get_tnt(), coord, value), _self()};
	}

	outcome<texture_wrap_mode>
	get_wrap(texture_wrap_coord coord) const
	noexcept { return _ops::get_texture_wrap(_get_tnt(), coord); }

	outcome<Derived&>
	swizzle(texture_swizzle_coord coord, texture_swizzle_mode value)
	noexcept {
		return {
			_ops::texture_swizzle(_get_tnt(), coord, value),
			_self()
		};
	}

	outcome<texture_swizzle_mode>
	get_swizzle(texture_swizzle_coord coord) const
	noexcept { return _ops::get_texture_swizzle(_get_tnt(), coord); }

#if defined(GL_TEXTURE_LOD_BIAS)
	outcome<Derived&>
	lod_bias(GLfloat value)
	noexcept {
		return {_ops::texture_lod_bias(_get_tnt(), value), _self()};
	}

	outcome<GLfloat>
	get_lod_bias(void) const
	noexcept { return _ops::get_texture_lod_bias(_get_tnt()); }
#endif

	outcome<Derived&>
	min_lod(GLfloat value)
	noexcept {
		return {_ops::texture_min_lod(_get_tnt(), value), _self()};
	}

	outcome<GLfloat>
	get_min_lod(void) const
	noexcept { return _ops::get_texture_min_lod(_get_tnt()); }

	outcome<Derived&>
	max_lod(GLfloat value)
	noexcept {
		return {_ops::texture_max_lod(_get_tnt(), value), _self()};
	}

	outcome<GLfloat>
	get_max_lod(void) const
	noexcept { return _ops::get_texture_max_lod(_get_tnt()); }
};


template <>
struct object_binding<tag::texture>
 : obj_member_ops<
	tag::texture,
	object_binding<tag::texture>,
	texture_target
>
{
	using obj_member_ops<
		tag::texture,
		object_binding<tag::texture>,
		texture_target
	>::obj_member_ops;
};

#if defined(GL_VERSION_4_5) ||\
	 defined(GL_ARB_direct_state_access) ||\
	 defined(GL_EXT_direct_state_access)

template <>
#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
struct obj_dsa_ops<tag::texture>
 : obj_member_ops<
	tag::texture,
	obj_dsa_ops<tag::texture>,
	obj_zero_dsa_ops<tag::texture>
>
{
	using obj_member_ops<
		tag::texture,
		obj_dsa_ops<tag::texture>,
		obj_zero_dsa_ops<tag::texture>
	>::obj_member_ops;
};
#elif defined(GL_EXT_direct_state_access)
struct obj_zero_dsa_ops<tag::texture>
 : obj_member_ops<
	tag::texture,
	obj_zero_dsa_ops<tag::texture>,
	object_zero_name<tag::texture>
>
{
	using obj_member_ops<
		tag::texture,
		obj_zero_dsa_ops<tag::texture>,
		object_zero_name<tag::texture>
	>::obj_member_ops;
};
#endif

#endif // GL_VERSION_4_5 || GL_EXT_direct_state_access


template <>
struct obj_gen_del_ops<tag::texture>
{
	static
	deferred_error_handler
	_gen(span<GLuint> names)
	noexcept;

#if defined(GL_VERSION_4_5)
	static
	deferred_error_handler
	_create(texture_target target, span<GLuint> names)
	noexcept;
#endif

	static
	deferred_error_handler
	_delete(span<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using texture = object_owner<tag::texture>;
using bound_texture = object_binding<tag::texture>;
template <std::size_t N>
using texture_array = object_array_owner<tag::texture, N>;

static const object_zero_and_ops<tag::texture>
	default_texture = {};

} // namespace oglplus

#include <oglplus/texture.inl>

#endif // include guard
