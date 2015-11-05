/**
 *  @file oglplus/texture.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>
#include <oglplus/oper/numeric_queries.hpp>

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include "enum/texture_target_bq.inl"
#endif

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
active_texture(texture_unit unit)
noexcept
{
#if !OGLPLUS_NO_LIMIT_CHECKS
	if(auto over_limit = failure(check_below_limit(unit)))
	{
		return std::move(over_limit);
	}
#endif
	OGLPLUS_GLFUNC(ActiveTexture)(GLenum(unit));
	OGLPLUS_VERIFY(
		ActiveTexture,
		gl_enum_value(unit),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<texture_unit>
texture_ops::
active_texture(void)
noexcept
{
	GLint result;
	return numeric_queries::get_integer_v(
		numeric_query(GL_ACTIVE_TEXTURE),
		{&result, 1}
	), texture_unit(GLenum(result));
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
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
//------------------------------------------------------------------------------
inline
outcome<texture_name>
texture_ops::
texture_binding(texture_target target)
noexcept
{
	GLint result;
	return numeric_queries::get_integer_v(
		get_binding_query(target),
		{&result, 1}
	), texture_name(GLuint(result));
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_parameter_i(
	texture_target_only tnt,
	oglplus::texture_parameter param,
	GLint value
) noexcept
{
	OGLPLUS_GLFUNC(TexParameteri)(
		GLenum(tnt._target),
		GLenum(param),
		value
	);
	OGLPLUS_VERIFY(
		TexParameteri,
		//gl_object(texture_binding(target)). TODO
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
get_texture_parameter_iv(
	texture_target_only tnt,
	oglplus::texture_parameter param,
	array_view<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTexParameteriv)(
		GLenum(tnt._target),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTexParameteriv,
		//gl_object(texture_binding(target)). TODO
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
get_texture_level_parameter_iv(
	texture_target_only tnt,
	GLint level,
	oglplus::texture_parameter param,
	array_view<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTexLevelParameteriv)(
		GLenum(tnt._target),
		level,
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTexLevelParameteriv,
		//gl_object(texture_binding(target)). TODO
		gl_index(GLuint(level)).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_parameter_f(
	texture_target_only tnt,
	oglplus::texture_parameter param,
	GLfloat value
) noexcept
{
	OGLPLUS_GLFUNC(TexParameterf)(
		GLenum(tnt._target),
		GLenum(param),
		value
	);
	OGLPLUS_VERIFY(
		TexParameterf,
		//gl_object(texture_binding(target)). TODO
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
get_texture_parameter_fv(
	texture_target_only tnt,
	oglplus::texture_parameter param,
	array_view<GLfloat> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTexParameterfv)(
		GLenum(tnt._target),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTexParameterfv,
		//gl_object(texture_binding(target)). TODO
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
#ifdef GL_VERSION_4_5
inline
outcome<void>
texture_ops::
texture_parameter_i(
	texture_name_only tnt,
	oglplus::texture_parameter param,
	GLint value
) noexcept
{
	OGLPLUS_GLFUNC(TextureParameteri)(
		get_raw_name(tnt._name),
		GLenum(param),
		value
	);
	OGLPLUS_VERIFY(
		TextureParameteri,
		gl_object(tnt._name).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
get_texture_parameter_iv(
	texture_name_only tnt,
	oglplus::texture_parameter param,
	array_view<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTextureParameteriv)(
		get_raw_name(tnt._name),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTextureParameteriv,
		gl_object(tnt._name).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
get_texture_level_parameter_iv(
	texture_name_only tnt,
	GLint level,
	oglplus::texture_parameter param,
	array_view<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTextureLevelParameteriv)(
		get_raw_name(tnt._name),
		level,
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTextureLevelParameteriv,
		gl_object(tnt._name).
		gl_index(GLuint(level)).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_parameter_f(
	texture_name_only tnt,
	oglplus::texture_parameter param,
	GLfloat value
) noexcept
{
	OGLPLUS_GLFUNC(TextureParameterf)(
		get_raw_name(tnt._name),
		GLenum(param),
		value
	);
	OGLPLUS_VERIFY(
		TextureParameterf,
		gl_object(tnt._name).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
get_texture_parameter_fv(
	texture_name_only tnt,
	oglplus::texture_parameter param,
	array_view<GLfloat> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTextureParameterfv)(
		get_raw_name(tnt._name),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTextureParameterfv,
		gl_object(tnt._name).
		gl_enum_value(param),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline
outcome<void>
texture_ops::
texture_parameter_i(
	texture_name_and_target tnt,
	oglplus::texture_parameter param,
	GLint value
) noexcept
{
	OGLPLUS_GLFUNC(TextureParameteriEXT)(
		get_raw_name(tnt._name),
		GLenum(tnt._target),
		GLenum(param),
		value
	);
	OGLPLUS_VERIFY(
		TextureParameteriEXT,
		gl_object(tnt._name).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
get_texture_parameter_iv(
	texture_name_and_target tnt,
	oglplus::texture_parameter param,
	array_view<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTextureParameterivEXT)(
		get_raw_name(tnt._name),
		GLenum(tnt._target),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTextureParameterivEXT,
		gl_object(tnt._name).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
get_texture_level_parameter_iv(
	texture_name_and_target tnt,
	GLint level,
	oglplus::texture_parameter param,
	array_view<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTextureLevelParameterivEXT)(
		get_raw_name(tnt._name),
		GLenum(tnt._target),
		level,
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTextureLevelParameterivEXT,
		gl_object(tnt._name).
		gl_index(GLuint(level)).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_parameter_f(
	texture_name_and_target tnt,
	oglplus::texture_parameter param,
	GLfloat value
) noexcept
{
	OGLPLUS_GLFUNC(TextureParameterfEXT)(
		get_raw_name(tnt._name),
		GLenum(tnt._target),
		GLenum(param),
		value
	);
	OGLPLUS_VERIFY(
		TextureParameterfEXT,
		gl_object(tnt._name).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
get_texture_parameter_fv(
	texture_name_and_target tnt,
	oglplus::texture_parameter param,
	array_view<GLfloat> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTextureParameterfvEXT)(
		get_raw_name(tnt._name),
		GLenum(tnt._target),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTextureParameterfvEXT,
		gl_object(tnt._name).
		gl_enum_value(param),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
template <typename R, typename T, typename TNT>
inline
outcome<R>
texture_ops::
return_texture_parameter_i(
	TNT tnt, 
	oglplus::texture_parameter parameter
) noexcept
{
	GLint result;
	return get_texture_parameter_iv(
		make_texture_name_or_target(tnt),
		parameter,
		{&result, 1}
	), R(T(result));
}
//------------------------------------------------------------------------------
template <typename R, typename T, typename TNT>
inline
outcome<R>
texture_ops::
return_texture_level_parameter_i(
	TNT tnt, 
	GLint level,
	oglplus::texture_parameter parameter
) noexcept
{
	GLint result;
	return get_texture_level_parameter_iv(
		make_texture_name_or_target(tnt),
		level,
		parameter,
		{&result, 1}
	), R(T(result));
}
//------------------------------------------------------------------------------
template <typename R, typename TNT>
inline
outcome<R>
texture_ops::
return_texture_parameter_f(
	TNT tnt, 
	oglplus::texture_parameter parameter
) noexcept
{
	GLfloat result;
	return get_texture_parameter_fv(
		make_texture_name_or_target(tnt),
		parameter,
		{&result, 1}
	), R(result);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_width(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		tnt, 
		level,
		oglplus::texture_parameter(GL_TEXTURE_WIDTH)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_height(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		tnt, 
		level,
		oglplus::texture_parameter(GL_TEXTURE_HEIGHT)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_depth(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		tnt, 
		level,
		oglplus::texture_parameter(GL_TEXTURE_DEPTH)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<pixel_data_type>
texture_ops::
texture_red_type(TNT tnt)
noexcept
{
	return return_texture_parameter_i<pixel_data_type, GLenum>(
		tnt,
		oglplus::texture_parameter(GL_TEXTURE_RED_TYPE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_red_size(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		tnt, 
		level,
		oglplus::texture_parameter(GL_TEXTURE_RED_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<pixel_data_type>
texture_ops::
texture_green_type(TNT tnt)
noexcept
{
	return return_texture_parameter_i<pixel_data_type, GLenum>(
		tnt,
		oglplus::texture_parameter(GL_TEXTURE_GREEN_TYPE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_green_size(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		tnt, 
		level,
		oglplus::texture_parameter(GL_TEXTURE_GREEN_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<pixel_data_type>
texture_ops::
texture_blue_type(TNT tnt)
noexcept
{
	return return_texture_parameter_i<pixel_data_type, GLenum>(
		tnt,
		oglplus::texture_parameter(GL_TEXTURE_BLUE_TYPE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_blue_size(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		tnt, 
		level,
		oglplus::texture_parameter(GL_TEXTURE_BLUE_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<pixel_data_type>
texture_ops::
texture_alpha_type(TNT tnt)
noexcept
{
	return return_texture_parameter_i<pixel_data_type, GLenum>(
		tnt,
		oglplus::texture_parameter(GL_TEXTURE_ALPHA_TYPE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_alpha_size(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		tnt, 
		level,
		oglplus::texture_parameter(GL_TEXTURE_ALPHA_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<pixel_data_type>
texture_ops::
texture_depth_type(TNT tnt)
noexcept
{
	return return_texture_parameter_i<pixel_data_type, GLenum>(
		tnt,
		oglplus::texture_parameter(GL_TEXTURE_DEPTH_TYPE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_depth_size(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		tnt, 
		level,
		oglplus::texture_parameter(GL_TEXTURE_DEPTH_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_stencil_size(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		tnt, 
		level,
		oglplus::texture_parameter(GL_TEXTURE_STENCIL_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_shared_size(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		tnt, 
		level,
		oglplus::texture_parameter(GL_TEXTURE_SHARED_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<boolean>
texture_ops::
texture_compressed(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<
		boolean,
		GLboolean
	>(
		tnt, 
		level,
		oglplus::texture_parameter(GL_TEXTURE_COMPRESSED)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_compressed_image_size(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		tnt, 
		level,
		oglplus::texture_parameter(
			GL_TEXTURE_COMPRESSED_IMAGE_SIZE
		)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<oglplus::pixel_data_internal_format>
texture_ops::
texture_internal_format(TNT tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<
		oglplus::pixel_data_internal_format,
		GLenum
	>(
		tnt,
		level,
		oglplus::texture_parameter(GL_TEXTURE_INTERNAL_FORMAT)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_min_filter(TNT tnt, oglplus::texture_min_filter value)
noexcept
{
	return texture_parameter_i(
		make_texture_name_or_target(tnt),
		oglplus::texture_parameter(GL_TEXTURE_MIN_FILTER),
		GLint(GLenum(value))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<oglplus::texture_min_filter>
texture_ops::
texture_min_filter(TNT tnt)
noexcept
{
	return return_texture_parameter_i<oglplus::texture_min_filter, GLenum>(
		tnt,
		oglplus::texture_parameter(GL_TEXTURE_MIN_FILTER)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_mag_filter(TNT tnt, oglplus::texture_mag_filter value)
noexcept
{
	return texture_parameter_i(
		make_texture_name_or_target(tnt),
		oglplus::texture_parameter(GL_TEXTURE_MAG_FILTER),
		GLint(GLenum(value))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<oglplus::texture_mag_filter>
texture_ops::
texture_mag_filter(TNT tnt)
noexcept
{
	return return_texture_parameter_i<oglplus::texture_mag_filter, GLenum>(
		tnt,
		oglplus::texture_parameter(GL_TEXTURE_MAG_FILTER)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_compare_func(TNT tnt, oglplus::compare_function value)
noexcept
{
	return texture_parameter_i(
		make_texture_name_or_target(tnt),
		oglplus::texture_parameter(GL_TEXTURE_COMPARE_FUNC),
		GLint(GLenum(value))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<oglplus::compare_function>
texture_ops::
texture_compare_func(TNT tnt)
noexcept
{
	return return_texture_parameter_i<oglplus::compare_function, GLenum>(
		tnt,
		oglplus::texture_parameter(GL_TEXTURE_COMPARE_FUNC)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_compare_mode(TNT tnt, oglplus::texture_compare_mode value)
noexcept
{
	return texture_parameter_i(
		make_texture_name_or_target(tnt),
		oglplus::texture_parameter(GL_TEXTURE_COMPARE_MODE),
		GLint(GLenum(value))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<oglplus::texture_compare_mode>
texture_ops::
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
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_lod_bias(TNT tnt, GLfloat value)
noexcept
{
	return texture_parameter_f(
		make_texture_name_or_target(tnt),
		oglplus::texture_parameter(GL_TEXTURE_LOD_BIAS),
		value
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLfloat>
texture_ops::
texture_lod_bias(TNT tnt)
noexcept
{
	return return_texture_parameter_f<GLfloat>(
		tnt,
		oglplus::texture_parameter(GL_TEXTURE_LOD_BIAS)
	);
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::texture>::
_gen(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(GenTextures)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenTextures,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::texture>::
_delete(array_view<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteTextures)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteTextures,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::texture>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsTexture)(name);
	OGLPLUS_VERIFY_SIMPLE(IsTexture,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
//------------------------------------------------------------------------------

