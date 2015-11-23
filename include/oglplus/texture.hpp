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
noexcept
{
	return {target};
}

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
	auto _wrap(const X& x)
	noexcept
	{
		return wrap_object_name_or_target(x);
	}

	template <typename X>
	using _disable_if_target = std::enable_if_t<
		!std::is_convertible<X, texture_target>::value
	>;
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

#if defined(GL_EXT_direct_state_access)
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

	static
	outcome<void>
	get_texture_level_parameter_iv(
		texture_target_only tnt,
		GLint level,
		oglplus::texture_parameter param,
		span<GLint> values
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
		span<GLfloat> values
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

	static
	outcome<void>
	get_texture_level_parameter_iv(
		texture_name_only tnt,
		GLint level,
		oglplus::texture_parameter param,
		span<GLint> values
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
		span<GLfloat> values
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

	static
	outcome<void>
	get_texture_level_parameter_iv(
		texture_name_and_target tnt,
		GLint level,
		oglplus::texture_parameter param,
		span<GLint> values
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
		span<GLfloat> values
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
	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_width(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_height
	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_height(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_depth
	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_depth(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_red_type
	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_red_type(const TNT& tnt)
	noexcept;

	// texture_red_size
	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_red_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_green_type
	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_green_type(const TNT& tnt)
	noexcept;

	// texture_green_size
	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_green_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_blue_type
	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_blue_type(const TNT& tnt)
	noexcept;

	// texture_blue_size
	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_blue_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_alpha_type
	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_alpha_type(const TNT& tnt)
	noexcept;

	// texture_alpha_size
	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_alpha_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_depth_type
	template <typename TNT>
	static 
	outcome<pixel_data_type>
	texture_depth_type(const TNT& tnt)
	noexcept;

	// texture_depth_size
	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_depth_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_stencil_size
	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_stencil_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_shared_size
	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_shared_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_compressed
	template <typename TNT>
	static 
	outcome<boolean>
	texture_compressed(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_compressed_image_size
	template <typename TNT>
	static 
	outcome<GLsizei>
	texture_compressed_image_size(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_internal_format
	template <typename TNT>
	static 
	outcome<oglplus::pixel_data_internal_format>
	texture_internal_format(const TNT& tnt, GLint level = 0)
	noexcept;

	// texture_min_filter
	template <typename TNT>
	static 
	outcome<void>
	texture_min_filter(const TNT& tnt, oglplus::texture_min_filter value)
	noexcept;

	template <typename TNT>
	static 
	outcome<oglplus::texture_min_filter>
	texture_min_filter(const TNT& tnt)
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
	texture_mag_filter(const TNT& tnt)
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
	texture_compare_func(const TNT& tnt)
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
	texture_compare_mode(const TNT& tnt)
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
	texture_wrap(const TNT& tnt, texture_wrap_coord coord)
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
	texture_swizzle(
		const TNT& tnt,
		texture_swizzle_coord coord
	) noexcept;

	// texture_lod_bias
	template <typename TNT>
	static 
	outcome<void>
	texture_lod_bias(const TNT& tnt, GLfloat value)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLfloat>
	texture_lod_bias(const TNT& tnt)
	noexcept;

	// texture_min_lod
	template <typename TNT>
	static 
	outcome<void>
	texture_min_lod(const TNT& tnt, GLfloat value)
	noexcept;

	template <typename TNT>
	static 
	outcome<GLfloat>
	texture_min_lod(const TNT& tnt)
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
	texture_max_lod(const TNT& tnt)
	noexcept;
};

} // namespace oper

template <typename Derived, typename Base>
struct obj_member_ops<tag::texture, Derived, Base>
 : Base
{
private:
	typedef oper::texture_ops _ops;

	Derived& _self(void)
	noexcept
	{
		return *static_cast<Derived*>(this);
	}

	const Base& _base(void) const
	noexcept
	{
		return *static_cast<const Base*>(this);
	}

	static
	texture_target_only _do_get_tnt(texture_target tgt)
	{
		return {tgt};
	}

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	typedef std::conditional_t<
		std::is_same<Base, texture_target>::value,
		texture_target_only,
		texture_name_only
	> _tnt;

	static
	texture_name_only _do_get_tnt(texture_name name)
	{
		return {name};
	}
#elif defined(GL_EXT_direct_state_access)
	texture_target target;

	typedef std::conditional_t<
		std::is_same<Base, texture_target>::value,
		texture_target_only,
		texture_name_and_target
	> _tnt;

	texture_name_and_target _do_get_tnt(texture_name name) const
	noexcept
	{
		return {name, target};
	}
#endif
	_tnt _get_tnt(void) const
	noexcept
	{
		return _do_get_tnt(_base());
	}

	friend inline
	_tnt
	wrap_object_name_or_target(const obj_member_ops& tex)
	noexcept
	{
		return tex._get_tnt();
	}
protected:
	using Base::Base;
public:
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

	outcome<Derived&>
	min_filter(oglplus::texture_min_filter value)
	noexcept
	{
		return {_ops::texture_min_filter(_get_tnt(), value), _self()};
	}

	outcome<oglplus::texture_min_filter>
	min_filter(void) const
	noexcept
	{
		return _ops::texture_min_filter(_get_tnt());
	}

	outcome<Derived&>
	mag_filter(oglplus::texture_mag_filter value)
	noexcept
	{
		return {_ops::texture_mag_filter(_get_tnt(), value), _self()};
	}

	outcome<oglplus::texture_mag_filter>
	mag_filter(void) const
	noexcept
	{
		return _ops::texture_mag_filter(_get_tnt());
	}

	outcome<Derived&>
	compare_func(oglplus::compare_function value)
	noexcept
	{
		return {
			_ops::texture_compare_func(_get_tnt(), value),
			_self()
		};
	}

	outcome<oglplus::compare_function>
	compare_func(void) const
	noexcept
	{
		return _ops::texture_compare_func(_get_tnt());
	}

	outcome<Derived&>
	compare_mode(oglplus::texture_compare_mode value)
	noexcept
	{
		return {
			_ops::texture_compare_mode(_get_tnt(), value),
			_self()
		};
	}

	outcome<oglplus::texture_compare_mode>
	compare_mode(void) const
	noexcept
	{
		return _ops::texture_compare_mode(_get_tnt());
	}

	outcome<Derived&>
	wrap(texture_wrap_coord coord, texture_wrap_mode value)
	noexcept
	{
		return {_ops::texture_wrap(_get_tnt(), coord, value), _self()};
	}

	outcome<texture_wrap_mode>
	wrap(texture_wrap_coord coord) const
	noexcept
	{
		return _ops::texture_wrap(_get_tnt(), coord);
	}

	outcome<Derived&>
	swizzle(texture_swizzle_coord coord, texture_swizzle_mode value)
	noexcept
	{
		return {
			_ops::texture_swizzle(_get_tnt(), coord, value),
			_self()
		};
	}

	outcome<texture_swizzle_mode>
	swizzle(texture_swizzle_coord coord) const
	noexcept
	{
		return _ops::texture_swizzle(_get_tnt(), coord);
	}

	outcome<Derived&>
	lod_bias(GLfloat value)
	noexcept
	{
		return {_ops::texture_lod_bias(_get_tnt(), value), _self()};
	}

	outcome<GLfloat>
	lod_bias(void) const
	noexcept
	{
		return _ops::texture_lod_bias(_get_tnt());
	}

	outcome<Derived&>
	min_lod(GLfloat value)
	noexcept
	{
		return {_ops::texture_min_lod(_get_tnt(), value), _self()};
	}

	outcome<GLfloat>
	min_lod(void) const
	noexcept
	{
		return _ops::texture_min_lod(_get_tnt());
	}

	outcome<Derived&>
	max_lod(GLfloat value)
	noexcept
	{
		return {_ops::texture_max_lod(_get_tnt(), value), _self()};
	}

	outcome<GLfloat>
	max_lod(void) const
	noexcept
	{
		return _ops::texture_max_lod(_get_tnt());
	}
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
