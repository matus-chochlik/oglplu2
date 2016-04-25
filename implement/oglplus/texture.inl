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
	GLint result = 0;
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
	GLint result = 0;
	return numeric_queries::get_integer_v(
		get_binding_query(target),
		{&result, 1}
	), texture_name(GLuint(result));
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
inline
outcome<void>
texture_ops::
texture_storage_1d(
	texture_target_only tnt,
	GLsizei levels,
	pixel_data_internal_format iformat,
	GLsizei width
) noexcept
{
	OGLPLUS_GLFUNC(TexStorage1D)(
		GLenum(tnt._target),
		levels,
		GLenum(iformat),
		width
	);
	OGLPLUS_VERIFY(
		TexStorage1D,
		gl_object_binding(tag::texture(), tnt._target).
		gl_enum_value(iformat),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_storage_2d(
	texture_target_only tnt,
	GLsizei levels,
	pixel_data_internal_format iformat,
	GLsizei width,
	GLsizei height
) noexcept
{
	OGLPLUS_GLFUNC(TexStorage2D)(
		GLenum(tnt._target),
		levels,
		GLenum(iformat),
		width,
		height
	);
	OGLPLUS_VERIFY(
		TexStorage2D,
		gl_object_binding(tag::texture(), tnt._target).
		gl_enum_value(iformat),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_storage_3d(
	texture_target_only tnt,
	GLsizei levels,
	pixel_data_internal_format iformat,
	GLsizei width,
	GLsizei height,
	GLsizei depth
) noexcept
{
	OGLPLUS_GLFUNC(TexStorage3D)(
		GLenum(tnt._target),
		levels,
		GLenum(iformat),
		width,
		height,
		depth
	);
	OGLPLUS_VERIFY(
		TexStorage3D,
		gl_object_binding(tag::texture(), tnt._target).
		gl_enum_value(iformat),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
inline
outcome<void>
texture_ops::
texture_storage_1d(
	texture_name_only tnt,
	GLsizei levels,
	pixel_data_internal_format iformat,
	GLsizei width
) noexcept
{
	OGLPLUS_GLFUNC(TextureStorage1D)(
		get_raw_name(tnt._name),
		levels,
		GLenum(iformat),
		width
	);
	OGLPLUS_VERIFY(
		TextureStorage1D,
		gl_object(tnt._name).
		gl_enum_value(iformat),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_storage_2d(
	texture_name_only tnt,
	GLsizei levels,
	pixel_data_internal_format iformat,
	GLsizei width,
	GLsizei height
) noexcept
{
	OGLPLUS_GLFUNC(TextureStorage2D)(
		get_raw_name(tnt._name),
		levels,
		GLenum(iformat),
		width,
		height
	);
	OGLPLUS_VERIFY(
		TextureStorage2D,
		gl_object(tnt._name).
		gl_enum_value(iformat),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_storage_3d(
	texture_name_only tnt,
	GLsizei levels,
	pixel_data_internal_format iformat,
	GLsizei width,
	GLsizei height,
	GLsizei depth
) noexcept
{
	OGLPLUS_GLFUNC(TextureStorage3D)(
		get_raw_name(tnt._name),
		levels,
		GLenum(iformat),
		width,
		height,
		depth
	);
	OGLPLUS_VERIFY(
		TextureStorage3D,
		gl_object(tnt._name).
		gl_enum_value(iformat),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
// TODO throw this out once the type of internalformat in GLEW is fixed
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_image_1d(
	texture_target_only tnt,
	GLint level,
	pixel_data_internal_format iformat,
	GLsizei width,
	GLint border,
	pixel_data_format format,
	pixel_data_type type,
	const_memory_block pixels
) noexcept
{
	OGLPLUS_GLFUNC(TexImage1D)(
		GLenum(tnt._target),
		level,
		GLenum(iformat),
		width,
		border,
		GLenum(format),
		GLenum(type),
		pixels.data()
	);
	OGLPLUS_VERIFY(
		TexImage1D,
		gl_object_binding(tag::texture(), tnt._target).
		gl_enum_value(iformat),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_image_1d(
	texture_target_only tnt,
	const image_spec& img,
	GLint level,
	GLint border
) noexcept
{
	return texture_image_1d(
		tnt,
		level,
		img.internal_format(),
		img.width(),
		border,
		img.format(),
		img.type(),
		img.data()
	);
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_image_2d(
	texture_target_only tnt,
	GLint level,
	pixel_data_internal_format iformat,
	GLsizei width,
	GLsizei height,
	GLint border,
	pixel_data_format format,
	pixel_data_type type,
	const_memory_block pixels
) noexcept
{
	OGLPLUS_GLFUNC(TexImage2D)(
		GLenum(tnt._target),
		level,
		GLenum(iformat),
		width,
		height,
		border,
		GLenum(format),
		GLenum(type),
		pixels.data()
	);
	OGLPLUS_VERIFY(
		TexImage2D,
		gl_object_binding(tag::texture(), tnt._target).
		gl_enum_value(iformat),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_image_2d(
	texture_target_only tnt,
	const image_spec& img,
	GLint level,
	GLint border
) noexcept
{
	return texture_image_2d(
		tnt,
		level,
		img.internal_format(),
		img.width(),
		img.height(),
		border,
		img.format(),
		img.type(),
		img.data()
	);
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
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
	const_memory_block pixels
) noexcept
{
	OGLPLUS_GLFUNC(TexImage3D)(
		GLenum(tnt._target),
		level,
		GLenum(iformat),
		width,
		height,
		depth,
		border,
		GLenum(format),
		GLenum(type),
		pixels.data()
	);
	OGLPLUS_VERIFY(
		TexImage3D,
		gl_object_binding(tag::texture(), tnt._target).
		gl_enum_value(iformat),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_image_3d(
	texture_target_only tnt,
	const image_spec& img,
	GLint level,
	GLint border
) noexcept
{
	return texture_image_3d(
		tnt,
		level,
		img.internal_format(),
		img.width(),
		img.height(),
		img.depth(),
		border,
		img.format(),
		img.type(),
		img.data()
	);
}
//------------------------------------------------------------------------------
#if defined(GL_EXT_direct_state_access)
inline
outcome<void>
texture_ops::
texture_image_1d(
	texture_name_and_target tnt,
	GLint level,
	pixel_data_internal_format iformat,
	GLsizei width,
	GLint border,
	pixel_data_format format,
	pixel_data_type type,
	const_memory_block pixels
) noexcept
{
	OGLPLUS_GLFUNC(TextureImage1DEXT)(
		get_raw_name(tnt._name),
		GLenum(tnt._target),
		level,
		GLenum(iformat),
		width,
		border,
		GLenum(format),
		GLenum(type),
		pixels.data()
	);
	OGLPLUS_VERIFY(
		TextureImage1DEXT,
		gl_object_binding(tag::texture(), tnt._target).
		gl_enum_value(iformat),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_image_1d(
	texture_name_and_target tnt,
	const image_spec& img,
	GLint level,
	GLint border
) noexcept
{
	return texture_image_1d(
		tnt,
		level,
		img.internal_format(),
		img.width(),
		border,
		img.format(),
		img.type(),
		img.data()
	);
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_image_2d(
	texture_name_and_target tnt,
	GLint level,
	pixel_data_internal_format iformat,
	GLsizei width,
	GLsizei height,
	GLint border,
	pixel_data_format format,
	pixel_data_type type,
	const_memory_block pixels
) noexcept
{
	OGLPLUS_GLFUNC(TextureImage2DEXT)(
		get_raw_name(tnt._name),
		GLenum(tnt._target),
		level,
		GLenum(iformat),
		width,
		height,
		border,
		GLenum(format),
		GLenum(type),
		pixels.data()
	);
	OGLPLUS_VERIFY(
		TextureImage2DEXT,
		gl_object_binding(tag::texture(), tnt._target).
		gl_enum_value(iformat),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_image_2d(
	texture_name_and_target tnt,
	const image_spec& img,
	GLint level,
	GLint border
) noexcept
{
	return texture_image_2d(
		tnt,
		level,
		img.internal_format(),
		img.width(),
		img.height(),
		border,
		img.format(),
		img.type(),
		img.data()
	);
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
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
	const_memory_block pixels
) noexcept
{
	OGLPLUS_GLFUNC(TextureImage3DEXT)(
		get_raw_name(tnt._name),
		GLenum(tnt._target),
		level,
		GLenum(iformat),
		width,
		height,
		depth,
		border,
		GLenum(format),
		GLenum(type),
		pixels.data()
	);
	OGLPLUS_VERIFY(
		TextureImage3DEXT,
		gl_object_binding(tag::texture(), tnt._target).
		gl_enum_value(iformat),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_image_3d(
	texture_name_and_target tnt,
	const image_spec& img,
	GLint level,
	GLint border
) noexcept
{
	return texture_image_3d(
		tnt,
		level,
		img.internal_format(),
		img.width(),
		img.height(),
		img.depth(),
		border,
		img.format(),
		img.type(),
		img.data()
	);
}
#endif
//------------------------------------------------------------------------------
#ifdef __clang__
#pragma clang diagnostic pop
#endif
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
		gl_object_binding(tag::texture(), tnt._target).
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
	span<GLint> values
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
		gl_object_binding(tag::texture(), tnt._target).
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
	span<GLint> values
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
		gl_object_binding(tag::texture(), tnt._target).
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
		gl_object_binding(tag::texture(), tnt._target).
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
	span<GLfloat> values
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
		gl_object_binding(tag::texture(), tnt._target).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_parameter_fv(
	texture_target_only tnt,
	oglplus::texture_parameter param,
	span<const GLfloat> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(TexParameterfv)(
		GLenum(tnt._target),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		TexParameterfv,
		gl_object_binding(tag::texture(), tnt._target).
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
	span<GLint> values
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
	span<GLint> values
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
	span<GLfloat> values
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
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_parameter_fv(
	texture_name_only tnt,
	oglplus::texture_parameter param,
	span<const GLfloat> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(TextureParameterfv)(
		get_raw_name(tnt._name),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		TextureParameterfv,
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
	span<GLint> values
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
	span<GLint> values
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
	span<GLfloat> values
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
//------------------------------------------------------------------------------
inline
outcome<void>
texture_ops::
texture_parameter_fv(
	texture_name_and_target tnt,
	oglplus::texture_parameter param,
	span<const GLfloat> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(TextureParameterfvEXT)(
		get_raw_name(tnt._name),
		GLenum(tnt._target),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		TextureParameterfvEXT,
		gl_object(tnt._name).
		gl_enum_value(param),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
template <typename R, typename P, typename N, typename T>
inline
outcome<R>
texture_ops::
return_texture_parameter_i(
	object_name_or_target<N, T> tnt,
	oglplus::texture_parameter parameter
) noexcept
{
	GLint result = 0;
	return get_texture_parameter_iv(
		tnt,
		parameter,
		{&result, 1}
	), R(P(result));
}
//------------------------------------------------------------------------------
template <typename R, typename P, typename N, typename T>
inline
outcome<R>
texture_ops::
return_texture_level_parameter_i(
	object_name_or_target<N, T> tnt,
	GLint level,
	oglplus::texture_parameter parameter
) noexcept
{
	GLint result = 0;
	return get_texture_level_parameter_iv(
		tnt,
		level,
		parameter,
		{&result, 1}
	), R(P(result));
}
//------------------------------------------------------------------------------
template <typename R, typename N, typename T>
inline
outcome<R>
texture_ops::
return_texture_parameter_f(
	object_name_or_target<N, T> tnt,
	oglplus::texture_parameter parameter
) noexcept
{
	GLfloat result = 0;
	return get_texture_parameter_fv(
		tnt,
		parameter,
		{&result, 1}
	), R(result);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_width(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_WIDTH)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_height(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_HEIGHT)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_depth(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_DEPTH)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<pixel_data_type>
texture_ops::
texture_red_type(const TNT& tnt)
noexcept
{
	return return_texture_parameter_i<pixel_data_type, GLenum>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_RED_TYPE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_red_size(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_RED_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<pixel_data_type>
texture_ops::
texture_green_type(const TNT& tnt)
noexcept
{
	return return_texture_parameter_i<pixel_data_type, GLenum>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_GREEN_TYPE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_green_size(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_GREEN_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<pixel_data_type>
texture_ops::
texture_blue_type(const TNT& tnt)
noexcept
{
	return return_texture_parameter_i<pixel_data_type, GLenum>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_BLUE_TYPE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_blue_size(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_BLUE_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<pixel_data_type>
texture_ops::
texture_alpha_type(const TNT& tnt)
noexcept
{
	return return_texture_parameter_i<pixel_data_type, GLenum>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_ALPHA_TYPE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_alpha_size(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_ALPHA_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<pixel_data_type>
texture_ops::
texture_depth_type(const TNT& tnt)
noexcept
{
	return return_texture_parameter_i<pixel_data_type, GLenum>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_DEPTH_TYPE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_depth_size(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_DEPTH_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_stencil_size(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_STENCIL_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_shared_size(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_SHARED_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<boolean>
texture_ops::
texture_compressed(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<
		boolean,
		GLboolean
	>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_COMPRESSED)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLsizei>
texture_ops::
texture_compressed_image_size(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<GLsizei, GLsizei>(
		_wrap(tnt),
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
texture_internal_format(const TNT& tnt, GLint level)
noexcept
{
	return return_texture_level_parameter_i<
		oglplus::pixel_data_internal_format,
		GLenum
	>(
		_wrap(tnt),
		level,
		oglplus::texture_parameter(GL_TEXTURE_INTERNAL_FORMAT)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_min_filter(const TNT& tnt, oglplus::texture_min_filter value)
noexcept
{
	return texture_parameter_i(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_MIN_FILTER),
		GLint(GLenum(value))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<oglplus::texture_min_filter>
texture_ops::
texture_min_filter(const TNT& tnt)
noexcept
{
	return return_texture_parameter_i<oglplus::texture_min_filter, GLenum>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_MIN_FILTER)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_mag_filter(const TNT& tnt, oglplus::texture_mag_filter value)
noexcept
{
	return texture_parameter_i(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_MAG_FILTER),
		GLint(GLenum(value))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<oglplus::texture_mag_filter>
texture_ops::
texture_mag_filter(const TNT& tnt)
noexcept
{
	return return_texture_parameter_i<oglplus::texture_mag_filter, GLenum>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_MAG_FILTER)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_compare_func(
	const TNT& tnt,
	oglplus::compare_function value
) noexcept
{
	return texture_parameter_i(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_COMPARE_FUNC),
		GLint(GLenum(value))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<oglplus::compare_function>
texture_ops::
texture_compare_func(const TNT& tnt)
noexcept
{
	return return_texture_parameter_i<oglplus::compare_function, GLenum>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_COMPARE_FUNC)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_compare_mode(
	const TNT& tnt,
	oglplus::texture_compare_mode value
) noexcept
{
	return texture_parameter_i(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_COMPARE_MODE),
		GLint(GLenum(value))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<oglplus::texture_compare_mode>
texture_ops::
texture_compare_mode(const TNT& tnt)
noexcept
{
	return return_texture_parameter_i<
		oglplus::texture_compare_mode,
		GLenum
	>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_COMPARE_MODE)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_wrap(
	const TNT& tnt,
	texture_wrap_coord coord,
	texture_wrap_mode value
) noexcept
{
	return texture_parameter_i(
		_wrap(tnt),
		oglplus::texture_parameter(GLenum(coord)),
		GLint(GLenum(value))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<texture_wrap_mode>
texture_ops::
texture_wrap(const TNT& tnt, texture_wrap_coord coord)
noexcept
{
	return return_texture_parameter_i<texture_wrap_mode, GLenum>(
		_wrap(tnt),
		oglplus::texture_parameter(GLenum(coord))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_swizzle(
	const TNT& tnt,
	texture_swizzle_coord coord,
	texture_swizzle_mode value
) noexcept
{
	return texture_parameter_i(
		_wrap(tnt),
		oglplus::texture_parameter(GLenum(coord)),
		GLint(GLenum(value))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<texture_swizzle_mode>
texture_ops::
texture_swizzle(const TNT& tnt, texture_swizzle_coord coord)
noexcept
{
	return return_texture_parameter_i<texture_swizzle_mode, GLenum>(
		_wrap(tnt),
		oglplus::texture_parameter(GLenum(coord))
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_lod_bias(const TNT& tnt, GLfloat value)
noexcept
{
	return texture_parameter_f(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_LOD_BIAS),
		value
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLfloat>
texture_ops::
texture_lod_bias(const TNT& tnt)
noexcept
{
	return return_texture_parameter_f<GLfloat>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_LOD_BIAS)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_min_lod(const TNT& tnt, GLfloat value)
noexcept
{
	return texture_parameter_f(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_MIN_LOD),
		value
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLfloat>
texture_ops::
texture_min_lod(const TNT& tnt)
noexcept
{
	return return_texture_parameter_f<GLfloat>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_MIN_LOD)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_max_lod(const TNT& tnt, GLfloat value)
noexcept
{
	return texture_parameter_f(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_MAX_LOD),
		value
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<GLfloat>
texture_ops::
texture_max_lod(const TNT& tnt)
noexcept
{
	return return_texture_parameter_f<GLfloat>(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_MAX_LOD)
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_border_color(const TNT& tnt, span<const GLfloat> c)
noexcept
{
	assert(c.size() >= 4);
	return texture_parameter_fv(
		_wrap(tnt),
		oglplus::texture_parameter(GL_TEXTURE_BORDER_COLOR),
		c
	);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline
outcome<void>
texture_ops::
texture_border_color(const TNT& tnt, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
noexcept
{
	const GLfloat c[4] = {r, g, b, a};
	return texture_border_color(tnt, c);
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::texture>::
_gen(span<GLuint> names)
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
_delete(span<GLuint> names)
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

