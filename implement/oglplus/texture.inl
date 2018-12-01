/**
 *  @file oglplus/texture.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/oper/numeric_queries.hpp>
#include <oglplus/utils/gl_func.hpp>

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include "enum/texture_target_bq.inl"
#endif

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::active_texture(texture_unit unit) noexcept {
#if !OGLPLUS_NO_LIMIT_CHECKS
    if(auto over_limit = failure(check_below_limit(unit))) {
        return std::move(over_limit);
    }
#endif
    OGLPLUS_GLFUNC(ActiveTexture)(GLenum(unit));
    OGLPLUS_VERIFY(ActiveTexture, gl_enum_value(unit), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<texture_unit>
texture_ops::get_active_texture(void) noexcept {
    GLint result = 0;
    return numeric_queries::get_integer_v(
             numeric_query(GL_ACTIVE_TEXTURE), {&result, 1})
      .add(texture_unit(GLenum(result)));
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::bind_texture(texture_target target, texture_name tex) noexcept {
    OGLPLUS_GLFUNC(BindTexture)(GLenum(target), get_raw_name(tex));
    OGLPLUS_VERIFY(BindTexture, gl_enum_value(target).gl_object(tex), debug);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5)
inline outcome<void>
texture_ops::bind_texture_unit(texture_unit unit, texture_name tex) noexcept {
    OGLPLUS_GLFUNC(BindTextureUnit)(GLenum(unit), get_raw_name(tex));
    OGLPLUS_VERIFY(BindTextureUnit, gl_enum_value(unit).gl_object(tex), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_4)
template <typename S>
inline outcome<void>
texture_ops::bind_textures(
  texture_unit first, const object_names<tag::texture, S>& textures) noexcept {
    OGLPLUS_GLFUNC(BindTextures)
    (GLuint(first.index()),
     GLsizei(textures.size()),
     get_raw_names(textures).data());
    OGLPLUS_VERIFY(
      BindTextures, gl_enum_value(first).gl_object(textures[0]), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<texture_name>
texture_ops::texture_binding(texture_target target) noexcept {
    GLint result = 0;
    return numeric_queries::get_integer_v(
             get_binding_query(target), {&result, 1})
      .add(texture_name(GLuint(result)));
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_4)
inline outcome<void>
texture_ops::bind_image_texture(
  texture_unit unit,
  texture_name_only tnt,
  GLint level,
  boolean layered,
  GLint layer,
  access_specifier access,
  pixel_data_format format) noexcept {
    OGLPLUS_GLFUNC(BindImageTexture)
    (GLenum(unit),
     get_raw_name(tnt._name),
     level,
     GLboolean(layered),
     layer,
     GLenum(access),
     GLenum(format));
    OGLPLUS_VERIFY(
      BindImageTexture, gl_object(tnt._name).gl_enum_value(format), always);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
inline outcome<void>
texture_ops::texture_storage_1d(
  texture_target_only tnt,
  GLsizei levels,
  pixel_data_internal_format iformat,
  GLsizei width) noexcept {
    OGLPLUS_GLFUNC(TexStorage1D)
    (GLenum(tnt._target), levels, GLenum(iformat), width);
    OGLPLUS_VERIFY(
      TexStorage1D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(iformat),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_storage_2d(
  texture_target_only tnt,
  GLsizei levels,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height) noexcept {
    OGLPLUS_GLFUNC(TexStorage2D)
    (GLenum(tnt._target), levels, GLenum(iformat), width, height);
    OGLPLUS_VERIFY(
      TexStorage2D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(iformat),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_storage_3d(
  texture_target_only tnt,
  GLsizei levels,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  GLsizei depth) noexcept {
    OGLPLUS_GLFUNC(TexStorage3D)
    (GLenum(tnt._target), levels, GLenum(iformat), width, height, depth);
    OGLPLUS_VERIFY(
      TexStorage3D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(iformat),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_3)
inline outcome<void>
texture_ops::texture_storage_2d_multisample(
  texture_target_only tnt,
  GLsizei samples,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  boolean fixed_locations) noexcept {
    OGLPLUS_GLFUNC(TexStorage2DMultisample)
    (GLenum(tnt._target),
     samples,
     GLenum(iformat),
     width,
     height,
     fixed_locations);
    OGLPLUS_VERIFY(
      TexStorage2DMultisample,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(iformat),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_storage_3d_multisample(
  texture_target_only tnt,
  GLsizei samples,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  GLsizei depth,
  boolean fixed_locations) noexcept {
    OGLPLUS_GLFUNC(TexStorage3DMultisample)
    (GLenum(tnt._target),
     samples,
     GLenum(iformat),
     width,
     height,
     depth,
     fixed_locations);
    OGLPLUS_VERIFY(
      TexStorage3DMultisample,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(iformat),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_3)
inline outcome<void>
invalidate_texture_image(texture_target_only tnt, GLint level) noexcept {
    OGLPLUS_GLFUNC(InvalidateTexImage)(GLenum(tnt._target), level);
    OGLPLUS_VERIFY(
      InvalidateTexImage,
      gl_object_binding(tag::texture(), tnt._target),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
invalidate_texture_sub_image(
  texture_target_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLint zoffset,
  GLsizei width,
  GLsizei height,
  GLsizei depth) noexcept {
    OGLPLUS_GLFUNC(InvalidateTexSubImage)
    (GLenum(tnt._target),
     level,
     xoffset,
     yoffset,
     zoffset,
     width,
     height,
     depth);
    OGLPLUS_VERIFY(
      InvalidateTexSubImage,
      gl_object_binding(tag::texture(), tnt._target),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_2_0)
inline outcome<void>
texture_ops::copy_texture_sub_image_1d(
  texture_target_only tnt,
  GLint level,
  GLint xoffset,
  GLint x,
  GLint y,
  GLsizei width) noexcept {
    OGLPLUS_GLFUNC(CopyTexSubImage1D)
    (GLenum(tnt._target), level, xoffset, x, y, width);
    OGLPLUS_VERIFY(
      CopyTexSubImage1D,
      gl_object_binding(tag::texture(), tnt._target),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::copy_texture_sub_image_2d(
  texture_target_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLint x,
  GLint y,
  GLsizei width,
  GLsizei height) noexcept {
    OGLPLUS_GLFUNC(CopyTexSubImage2D)
    (GLenum(tnt._target), level, xoffset, yoffset, x, y, width, height);
    OGLPLUS_VERIFY(
      CopyTexSubImage2D,
      gl_object_binding(tag::texture(), tnt._target),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::copy_texture_sub_image_3d(
  texture_target_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLint zoffset,
  GLint x,
  GLint y,
  GLsizei width,
  GLsizei height) noexcept {
    OGLPLUS_GLFUNC(CopyTexSubImage3D)
    (GLenum(tnt._target),
     level,
     xoffset,
     yoffset,
     zoffset,
     x,
     y,
     width,
     height);
    OGLPLUS_VERIFY(
      CopyTexSubImage3D,
      gl_object_binding(tag::texture(), tnt._target),
      always);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
inline outcome<void>
texture_ops::copy_texture_sub_image_1d(
  texture_name_only tnt,
  GLint level,
  GLint xoffset,
  GLint x,
  GLint y,
  GLsizei width) noexcept {
    OGLPLUS_GLFUNC(CopyTextureSubImage1D)
    (get_raw_name(tnt._name), level, xoffset, x, y, width);
    OGLPLUS_VERIFY(CopyTextureSubImage1D, gl_object(tnt._name), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::copy_texture_sub_image_2d(
  texture_name_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLint x,
  GLint y,
  GLsizei width,
  GLsizei height) noexcept {
    OGLPLUS_GLFUNC(CopyTextureSubImage2D)
    (get_raw_name(tnt._name), level, xoffset, yoffset, x, y, width, height);
    OGLPLUS_VERIFY(CopyTextureSubImage2D, gl_object(tnt._name), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::copy_texture_sub_image_3d(
  texture_name_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLint zoffset,
  GLint x,
  GLint y,
  GLsizei width,
  GLsizei height) noexcept {
    OGLPLUS_GLFUNC(CopyTextureSubImage3D)
    (get_raw_name(tnt._name),
     level,
     xoffset,
     yoffset,
     zoffset,
     x,
     y,
     width,
     height);
    OGLPLUS_VERIFY(CopyTexSubtureImage3D, gl_object(tnt._name), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_storage_1d(
  texture_name_only tnt,
  GLsizei levels,
  pixel_data_internal_format iformat,
  GLsizei width) noexcept {
    OGLPLUS_GLFUNC(TextureStorage1D)
    (get_raw_name(tnt._name), levels, GLenum(iformat), width);
    OGLPLUS_VERIFY(
      TextureStorage1D, gl_object(tnt._name).gl_enum_value(iformat), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_storage_2d(
  texture_name_only tnt,
  GLsizei levels,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height) noexcept {
    OGLPLUS_GLFUNC(TextureStorage2D)
    (get_raw_name(tnt._name), levels, GLenum(iformat), width, height);
    OGLPLUS_VERIFY(
      TextureStorage2D, gl_object(tnt._name).gl_enum_value(iformat), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_storage_3d(
  texture_name_only tnt,
  GLsizei levels,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  GLsizei depth) noexcept {
    OGLPLUS_GLFUNC(TextureStorage3D)
    (get_raw_name(tnt._name), levels, GLenum(iformat), width, height, depth);
    OGLPLUS_VERIFY(
      TextureStorage3D, gl_object(tnt._name).gl_enum_value(iformat), always);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
inline outcome<void>
texture_ops::texture_storage_2d_multisample(
  texture_name_only tnt,
  GLsizei samples,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  boolean fixed_locations) noexcept {
    OGLPLUS_GLFUNC(TextureStorage2DMultisample)
    (get_raw_name(tnt._name),
     samples,
     GLenum(iformat),
     width,
     height,
     fixed_locations);
    OGLPLUS_VERIFY(
      TextureStorage2DMultisample,
      gl_object(tnt._name).gl_enum_value(iformat),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_storage_3d_multisample(
  texture_name_only tnt,
  GLsizei samples,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  GLsizei depth,
  boolean fixed_locations) noexcept {
    OGLPLUS_GLFUNC(TextureStorage3DMultisample)
    (get_raw_name(tnt._name),
     samples,
     GLenum(iformat),
     width,
     height,
     depth,
     fixed_locations);
    OGLPLUS_VERIFY(
      TextureStorage3DMultisample,
      gl_object(tnt._name).gl_enum_value(iformat),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_4)
inline outcome<void>
texture_ops::clear_texture_image(
  texture_name_only tnt,
  GLint level,
  pixel_data_format format,
  pixel_data_type type,
  const buffer_data_spec& data) noexcept {
    OGLPLUS_GLFUNC(ClearTexImage)
    (get_raw_name(tnt._name), level, GLenum(format), GLenum(type), data.data());
    OGLPLUS_VERIFY(
      ClearTexImage, gl_object(tnt._name).gl_enum_value(format), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::clear_texture_sub_image(
  texture_name_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLint zoffset,
  GLsizei width,
  GLsizei height,
  GLsizei depth,
  pixel_data_format format,
  pixel_data_type type,
  const buffer_data_spec& data) noexcept {
    OGLPLUS_GLFUNC(ClearTexSubImage)
    (get_raw_name(tnt._name),
     level,
     xoffset,
     yoffset,
     zoffset,
     width,
     height,
     depth,
     GLenum(format),
     GLenum(type),
     data.data());
    OGLPLUS_VERIFY(
      ClearTexSubImage, gl_object(tnt._name).gl_enum_value(format), always);
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
#if defined(GL_VERSION_3_0)
inline outcome<void>
texture_ops::texture_image_1d(
  texture_target_only tnt,
  GLint level,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLint border,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TexImage1D)
    (GLenum(tnt._target),
     level,
     GLenum(iformat),
     width,
     border,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TexImage1D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_image_1d(
  texture_target_only tnt,
  const image_spec& img,
  GLint level,
  GLint border) noexcept {
    return texture_image_1d(
      tnt,
      level,
      img.internal_format(),
      img.width(),
      border,
      img.format(),
      img.type(),
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_1d(
  texture_target_only tnt,
  GLint level,
  GLint xoffset,
  GLsizei width,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TexSubImage1D)
    (GLenum(tnt._target),
     level,
     xoffset,
     width,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TexSubImage1D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_1d(
  texture_target_only tnt,
  GLint xoffset,
  const image_spec& img,
  GLint level) noexcept {
    return texture_sub_image_1d(
      tnt, level, xoffset, img.width(), img.format(), img.type(), img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::compressed_texture_sub_image_1d(
  texture_target_only tnt,
  GLint level,
  GLint xoffset,
  GLsizei width,
  pixel_data_format format,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(CompressedTexSubImage1D)
    (GLenum(tnt._target),
     level,
     xoffset,
     width,
     GLenum(format),
     GLsizei(pixels.size()),
     pixels.data());
    OGLPLUS_VERIFY(
      CompressedTexSubImage1D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_image_2d(
  texture_target_only tnt,
  GLint level,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  GLint border,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TexImage2D)
    (GLenum(tnt._target),
     level,
     GLenum(iformat),
     width,
     height,
     border,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TexImage2D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_image_2d(
  texture_target_only tnt,
  const image_spec& img,
  GLint level,
  GLint border) noexcept {
    return texture_image_2d(
      tnt,
      level,
      img.internal_format(),
      img.width(),
      img.height(),
      border,
      img.format(),
      img.type(),
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_2d(
  texture_target_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLsizei width,
  GLsizei height,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TexSubImage2D)
    (GLenum(tnt._target),
     level,
     xoffset,
     yoffset,
     width,
     height,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TexSubImage2D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_2)
inline outcome<void>
texture_ops::texture_image_2d_multisample(
  texture_target_only tnt,
  GLsizei samples,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  boolean fixed_locations) noexcept {
    OGLPLUS_GLFUNC(TexImage2DMultisample)
    (GLenum(tnt._target),
     samples,
     GLenum(iformat),
     width,
     height,
     GLboolean(fixed_locations));
    OGLPLUS_VERIFY(
      TexImage2DMultisample,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(iformat),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_2d(
  texture_target_only tnt,
  GLint xoffset,
  GLint yoffset,
  const image_spec& img,
  GLint level) noexcept {
    return texture_sub_image_2d(
      tnt,
      level,
      xoffset,
      yoffset,
      img.width(),
      img.height(),
      img.format(),
      img.type(),
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::compressed_texture_sub_image_2d(
  texture_target_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLsizei width,
  GLsizei height,
  pixel_data_format format,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(CompressedTexSubImage2D)
    (GLenum(tnt._target),
     level,
     xoffset,
     yoffset,
     width,
     height,
     GLenum(format),
     GLsizei(pixels.size()),
     pixels.data());
    OGLPLUS_VERIFY(
      CompressedTexSubImage2D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_image_3d(
  texture_target_only tnt,
  GLint level,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  GLsizei depth,
  GLint border,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TexImage3D)
    (GLenum(tnt._target),
     level,
     GLenum(iformat),
     width,
     height,
     depth,
     border,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TexImage3D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_image_3d(
  texture_target_only tnt,
  const image_spec& img,
  GLint level,
  GLint border) noexcept {
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
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_3d(
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
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TexSubImage3D)
    (GLenum(tnt._target),
     level,
     xoffset,
     yoffset,
     zoffset,
     width,
     height,
     depth,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TexSubImage3D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_2)
inline outcome<void>
texture_ops::texture_image_3d_multisample(
  texture_target_only tnt,
  GLsizei samples,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  GLsizei depth,
  boolean fixed_locations) noexcept {
    OGLPLUS_GLFUNC(TexImage3DMultisample)
    (GLenum(tnt._target),
     samples,
     GLenum(iformat),
     width,
     height,
     depth,
     GLboolean(fixed_locations));
    OGLPLUS_VERIFY(
      TexImage3DMultisample,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(iformat),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_3d(
  texture_target_only tnt,
  GLint xoffset,
  GLint yoffset,
  GLint zoffset,
  const image_spec& img,
  GLint level) noexcept {
    return texture_sub_image_3d(
      tnt,
      level,
      xoffset,
      yoffset,
      zoffset,
      img.width(),
      img.height(),
      img.depth(),
      img.format(),
      img.type(),
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::compressed_texture_sub_image_3d(
  texture_target_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLint zoffset,
  GLsizei width,
  GLsizei height,
  GLsizei depth,
  pixel_data_format format,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(CompressedTexSubImage3D)
    (GLenum(tnt._target),
     level,
     xoffset,
     yoffset,
     zoffset,
     width,
     height,
     depth,
     GLenum(format),
     GLsizei(pixels.size()),
     pixels.data());
    OGLPLUS_VERIFY(
      CompressedTexSubImage3D,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_EXT_direct_state_access)
#if defined(GL_VERSION_3_0)
inline outcome<void>
texture_ops::texture_image_1d(
  texture_name_and_target tnt,
  GLint level,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLint border,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TextureImage1DEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     level,
     GLenum(iformat),
     width,
     border,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TextureImage1DEXT,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_image_1d(
  texture_name_and_target tnt,
  const image_spec& img,
  GLint level,
  GLint border) noexcept {
    return texture_image_1d(
      tnt,
      level,
      img.internal_format(),
      img.width(),
      border,
      img.format(),
      img.type(),
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_1d(
  texture_name_and_target tnt,
  GLint level,
  GLint xoffset,
  GLsizei width,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TextureSubImage1DEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     level,
     xoffset,
     width,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TextureImage1DEXT,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_1d(
  texture_name_and_target tnt,
  GLint xoffset,
  const image_spec& img,
  GLint level) noexcept {
    return texture_sub_image_1d(
      tnt, level, xoffset, img.width(), img.format(), img.type(), img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::compressed_texture_sub_image_1d(
  texture_name_and_target tnt,
  GLint level,
  GLint xoffset,
  GLsizei width,
  pixel_data_format format,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(CompressedTextureSubImage1DEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     level,
     xoffset,
     width,
     GLenum(format),
     GLsizei(pixels.size()),
     pixels.data());
    OGLPLUS_VERIFY(
      CompressedTextureImage1DEXT,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
#endif // GL_VERSION_3_0
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_image_2d(
  texture_name_and_target tnt,
  GLint level,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  GLint border,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TextureImage2DEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     level,
     GLenum(iformat),
     width,
     height,
     border,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TextureImage2DEXT,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_image_2d(
  texture_name_and_target tnt,
  const image_spec& img,
  GLint level,
  GLint border) noexcept {
    return texture_image_2d(
      tnt,
      level,
      img.internal_format(),
      img.width(),
      img.height(),
      border,
      img.format(),
      img.type(),
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_2d(
  texture_name_and_target tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLsizei width,
  GLsizei height,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TextureSubImage2DEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     level,
     xoffset,
     yoffset,
     width,
     height,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TextureImage2DEXT,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_2d(
  texture_name_and_target tnt,
  GLint xoffset,
  GLint yoffset,
  const image_spec& img,
  GLint level) noexcept {
    return texture_sub_image_2d(
      tnt,
      level,
      xoffset,
      yoffset,
      img.width(),
      img.height(),
      img.format(),
      img.type(),
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::compressed_texture_sub_image_2d(
  texture_name_and_target tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLsizei width,
  GLsizei height,
  pixel_data_format format,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(CompressedTextureSubImage2DEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     level,
     xoffset,
     yoffset,
     width,
     height,
     GLenum(format),
     GLsizei(pixels.size()),
     pixels.data());
    OGLPLUS_VERIFY(
      CompressedTextureImage2DEXT,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_image_3d(
  texture_name_and_target tnt,
  GLint level,
  pixel_data_internal_format iformat,
  GLsizei width,
  GLsizei height,
  GLsizei depth,
  GLint border,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TextureImage3DEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     level,
     GLenum(iformat),
     width,
     height,
     depth,
     border,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TextureImage3DEXT,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_image_3d(
  texture_name_and_target tnt,
  const image_spec& img,
  GLint level,
  GLint border) noexcept {
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
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_3d(
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
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TextureSubImage3DEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     level,
     xoffset,
     yoffset,
     zoffset,
     width,
     height,
     depth,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TextureImage3DEXT,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_3d(
  texture_name_and_target tnt,
  GLint xoffset,
  GLint yoffset,
  GLint zoffset,
  const image_spec& img,
  GLint level) noexcept {
    return texture_sub_image_3d(
      tnt,
      level,
      xoffset,
      yoffset,
      zoffset,
      img.width(),
      img.height(),
      img.depth(),
      img.format(),
      img.type(),
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::compressed_texture_sub_image_3d(
  texture_name_and_target tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLint zoffset,
  GLsizei width,
  GLsizei height,
  GLsizei depth,
  pixel_data_format format,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(CompressedTextureSubImage3DEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     level,
     xoffset,
     yoffset,
     zoffset,
     width,
     height,
     depth,
     GLenum(format),
     GLsizei(pixels.size()),
     pixels.data());
    OGLPLUS_VERIFY(
      CompressedTextureImage3DEXT,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
inline outcome<void>
texture_ops::texture_sub_image_1d(
  texture_name_only tnt,
  GLint level,
  GLint xoffset,
  GLsizei width,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TextureSubImage1D)
    (get_raw_name(tnt._name),
     level,
     xoffset,
     width,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TextureSubImage1D, gl_object(tnt._name).gl_enum_value(format), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_1d(
  texture_name_only tnt,
  GLint xoffset,
  const image_spec& img,
  GLint level) noexcept {
    return texture_sub_image_1d(
      tnt, level, xoffset, img.width(), img.format(), img.type(), img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::compressed_texture_sub_image_1d(
  texture_name_only tnt,
  GLint level,
  GLint xoffset,
  GLsizei width,
  pixel_data_format format,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(CompressedTextureSubImage1D)
    (get_raw_name(tnt._name),
     level,
     xoffset,
     width,
     GLenum(format),
     GLsizei(pixels.size()),
     pixels.data());
    OGLPLUS_VERIFY(
      CompressedTextureSubImage1D,
      gl_object(tnt._name).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_2d(
  texture_name_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLsizei width,
  GLsizei height,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TextureSubImage2D)
    (get_raw_name(tnt._name),
     level,
     xoffset,
     yoffset,
     width,
     height,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TextureSubImage2D, gl_object(tnt._name).gl_enum_value(format), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_2d(
  texture_name_only tnt,
  GLint xoffset,
  GLint yoffset,
  const image_spec& img,
  GLint level) noexcept {
    return texture_sub_image_2d(
      tnt,
      level,
      xoffset,
      yoffset,
      img.width(),
      img.height(),
      img.format(),
      img.type(),
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::compressed_texture_sub_image_2d(
  texture_name_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLsizei width,
  GLsizei height,
  pixel_data_format format,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(CompressedTextureSubImage2D)
    (get_raw_name(tnt._name),
     level,
     xoffset,
     yoffset,
     width,
     height,
     GLenum(format),
     GLsizei(pixels.size()),
     pixels.data());
    OGLPLUS_VERIFY(
      CompressedTextureSubImage2D,
      gl_object(tnt._name).gl_enum_value(format),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_3d(
  texture_name_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLint zoffset,
  GLsizei width,
  GLsizei height,
  GLsizei depth,
  pixel_data_format format,
  pixel_data_type type,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(TextureSubImage3D)
    (get_raw_name(tnt._name),
     level,
     xoffset,
     yoffset,
     zoffset,
     width,
     height,
     depth,
     GLenum(format),
     GLenum(type),
     pixels.data());
    OGLPLUS_VERIFY(
      TextureSubImage3D, gl_object(tnt._name).gl_enum_value(format), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_sub_image_3d(
  texture_name_only tnt,
  GLint xoffset,
  GLint yoffset,
  GLint zoffset,
  const image_spec& img,
  GLint level) noexcept {
    return texture_sub_image_3d(
      tnt,
      level,
      xoffset,
      yoffset,
      zoffset,
      img.width(),
      img.height(),
      img.depth(),
      img.format(),
      img.type(),
      img.data());
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::compressed_texture_sub_image_3d(
  texture_name_only tnt,
  GLint level,
  GLint xoffset,
  GLint yoffset,
  GLint zoffset,
  GLsizei width,
  GLsizei height,
  GLsizei depth,
  pixel_data_format format,
  const_memory_block pixels) noexcept {
    OGLPLUS_GLFUNC(CompressedTextureSubImage3D)
    (get_raw_name(tnt._name),
     level,
     xoffset,
     yoffset,
     zoffset,
     width,
     height,
     depth,
     GLenum(format),
     GLsizei(pixels.size()),
     pixels.data());
    OGLPLUS_VERIFY(
      CompressedTextureSubImage3D,
      gl_object(tnt._name).gl_enum_value(format),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
#ifdef __clang__
#pragma clang diagnostic pop
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_1)
inline outcome<void>
texture_ops::texture_buffer(
  texture_target_only tnt,
  pixel_data_internal_format iformat,
  buffer_name buf) noexcept {
    OGLPLUS_GLFUNC(TexBuffer)
    (GLenum(tnt._target), GLenum(iformat), get_raw_name(buf));
    OGLPLUS_VERIFY(
      TexBuffer,
      gl_subject(buf)
        .gl_object_binding(tag::texture(), tnt._target)
        .gl_enum_value(iformat),
      always);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_EXT_direct_state_access)
inline outcome<void>
texture_ops::texture_buffer(
  texture_name_and_target tnt,
  pixel_data_internal_format iformat,
  buffer_name buf) noexcept {
    OGLPLUS_GLFUNC(TextureBufferEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     GLenum(iformat),
     get_raw_name(buf));
    OGLPLUS_VERIFY(
      TextureBufferEXT,
      gl_subject(buf).gl_object(tnt._name).gl_enum_value(iformat),
      always);
    return {};
}
#endif
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
inline outcome<void>
texture_ops::texture_buffer(
  texture_name_only tnt,
  pixel_data_internal_format iformat,
  buffer_name buf) noexcept {
    OGLPLUS_GLFUNC(TextureBuffer)
    (get_raw_name(tnt._name), GLenum(iformat), get_raw_name(buf));
    OGLPLUS_VERIFY(
      TextureBuffer,
      gl_subject(buf).gl_object(tnt._name).gl_enum_value(iformat),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_3)
inline outcome<void>
texture_ops::texture_buffer_range(
  texture_target_only tnt,
  pixel_data_internal_format iformat,
  buffer_name buf,
  buffer_size offset,
  buffer_size size) noexcept {
    OGLPLUS_GLFUNC(TexBufferRange)
    (GLenum(tnt._target),
     GLenum(iformat),
     get_raw_name(buf),
     GLintptr(offset),
     GLsizeiptr(size));
    OGLPLUS_VERIFY(
      TexBufferRange,
      gl_subject(buf)
        .gl_object_binding(tag::texture(), tnt._target)
        .gl_enum_value(iformat),
      always);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_EXT_direct_state_access)
inline outcome<void>
texture_ops::texture_buffer_range(
  texture_name_and_target tnt,
  pixel_data_internal_format iformat,
  buffer_name buf,
  buffer_size offset,
  buffer_size size) noexcept {
    OGLPLUS_GLFUNC(TextureBufferRangeEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     GLenum(iformat),
     get_raw_name(buf),
     GLintptr(offset),
     GLsizeiptr(size));
    OGLPLUS_VERIFY(
      TextureBufferRangeEXT,
      gl_subject(buf).gl_object(tnt._name).gl_enum_value(iformat),
      always);
    return {};
}
#endif
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
inline outcome<void>
texture_ops::texture_buffer_range(
  texture_name_only tnt,
  pixel_data_internal_format iformat,
  buffer_name buf,
  buffer_size offset,
  buffer_size size) noexcept {
    OGLPLUS_GLFUNC(TextureBufferRange)
    (get_raw_name(tnt._name),
     GLenum(iformat),
     get_raw_name(buf),
     GLintptr(offset),
     GLsizeiptr(size));
    OGLPLUS_VERIFY(
      TextureBufferRange,
      gl_subject(buf).gl_object(tnt._name).gl_enum_value(iformat),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_3)
inline outcome<void>
texture_ops::texture_view(
  texture_name newtex,
  texture_target target,
  texture_name origtex,
  pixel_data_internal_format iformat,
  GLuint minlevels,
  GLuint numlevels,
  GLuint minlayers,
  GLuint numlayers) noexcept {
    OGLPLUS_GLFUNC(TextureView)
    (get_raw_name(newtex),
     GLenum(target),
     get_raw_name(origtex),
     GLenum(iformat),
     minlevels,
     numlevels,
     minlayers,
     numlayers);
    OGLPLUS_VERIFY(
      TextureView,
      gl_subject(newtex).gl_object(newtex).gl_enum_value(target),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::generate_texture_mipmap(texture_target_only tnt) noexcept {
    OGLPLUS_GLFUNC(GenerateMipmap)(GLenum(tnt._target));
    OGLPLUS_VERIFY(
      GenerateMipmap, gl_object_binding(tag::texture(), tnt._target), always);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
inline outcome<void>
texture_ops::generate_texture_mipmap(texture_name_only tnt) noexcept {
    OGLPLUS_GLFUNC(GenerateTextureMipmap)(get_raw_name(tnt._name));
    OGLPLUS_VERIFY(GenerateTextureMipmap, gl_object(tnt._name), always);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_parameter_i(
  texture_target_only tnt,
  oglplus::texture_parameter param,
  GLint value) noexcept {
    OGLPLUS_GLFUNC(TexParameteri)(GLenum(tnt._target), GLenum(param), value);
    OGLPLUS_VERIFY(
      TexParameteri,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(param),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::get_texture_parameter_iv(
  texture_target_only tnt,
  oglplus::texture_parameter param,
  span<GLint> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetTexParameteriv)
    (GLenum(tnt._target), GLenum(param), values.data());
    OGLPLUS_VERIFY(
      GetTexParameteriv,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(param),
      always);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
inline outcome<void>
texture_ops::get_texture_level_parameter_iv(
  texture_target_only tnt,
  GLint level,
  oglplus::texture_parameter param,
  span<GLint> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetTexLevelParameteriv)
    (GLenum(tnt._target), level, GLenum(param), values.data());
    OGLPLUS_VERIFY(
      GetTexLevelParameteriv,
      gl_object_binding(tag::texture(), tnt._target)
        .gl_index(GLuint(level))
        .gl_enum_value(param),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_parameter_f(
  texture_target_only tnt,
  oglplus::texture_parameter param,
  GLfloat value) noexcept {
    OGLPLUS_GLFUNC(TexParameterf)(GLenum(tnt._target), GLenum(param), value);
    OGLPLUS_VERIFY(
      TexParameterf,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(param),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::get_texture_parameter_fv(
  texture_target_only tnt,
  oglplus::texture_parameter param,
  span<GLfloat> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetTexParameterfv)
    (GLenum(tnt._target), GLenum(param), values.data());
    OGLPLUS_VERIFY(
      GetTexParameterfv,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(param),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_parameter_fv(
  texture_target_only tnt,
  oglplus::texture_parameter param,
  span<const GLfloat> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(TexParameterfv)
    (GLenum(tnt._target), GLenum(param), values.data());
    OGLPLUS_VERIFY(
      TexParameterfv,
      gl_object_binding(tag::texture(), tnt._target).gl_enum_value(param),
      always);
    return {};
}
//------------------------------------------------------------------------------
#ifdef GL_VERSION_4_5
inline outcome<void>
texture_ops::texture_parameter_i(
  texture_name_only tnt,
  oglplus::texture_parameter param,
  GLint value) noexcept {
    OGLPLUS_GLFUNC(TextureParameteri)
    (get_raw_name(tnt._name), GLenum(param), value);
    OGLPLUS_VERIFY(
      TextureParameteri, gl_object(tnt._name).gl_enum_value(param), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::get_texture_parameter_iv(
  texture_name_only tnt,
  oglplus::texture_parameter param,
  span<GLint> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetTextureParameteriv)
    (get_raw_name(tnt._name), GLenum(param), values.data());
    OGLPLUS_VERIFY(
      GetTextureParameteriv, gl_object(tnt._name).gl_enum_value(param), always);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
inline outcome<void>
texture_ops::get_texture_level_parameter_iv(
  texture_name_only tnt,
  GLint level,
  oglplus::texture_parameter param,
  span<GLint> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetTextureLevelParameteriv)
    (get_raw_name(tnt._name), level, GLenum(param), values.data());
    OGLPLUS_VERIFY(
      GetTextureLevelParameteriv,
      gl_object(tnt._name).gl_index(GLuint(level)).gl_enum_value(param),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_parameter_f(
  texture_name_only tnt,
  oglplus::texture_parameter param,
  GLfloat value) noexcept {
    OGLPLUS_GLFUNC(TextureParameterf)
    (get_raw_name(tnt._name), GLenum(param), value);
    OGLPLUS_VERIFY(
      TextureParameterf, gl_object(tnt._name).gl_enum_value(param), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::get_texture_parameter_fv(
  texture_name_only tnt,
  oglplus::texture_parameter param,
  span<GLfloat> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetTextureParameterfv)
    (get_raw_name(tnt._name), GLenum(param), values.data());
    OGLPLUS_VERIFY(
      GetTextureParameterfv, gl_object(tnt._name).gl_enum_value(param), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_parameter_fv(
  texture_name_only tnt,
  oglplus::texture_parameter param,
  span<const GLfloat> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(TextureParameterfv)
    (get_raw_name(tnt._name), GLenum(param), values.data());
    OGLPLUS_VERIFY(
      TextureParameterfv, gl_object(tnt._name).gl_enum_value(param), always);
    return {};
}
#endif
//------------------------------------------------------------------------------
#ifdef GL_EXT_direct_state_access
inline outcome<void>
texture_ops::texture_parameter_i(
  texture_name_and_target tnt,
  oglplus::texture_parameter param,
  GLint value) noexcept {
    OGLPLUS_GLFUNC(TextureParameteriEXT)
    (get_raw_name(tnt._name), GLenum(tnt._target), GLenum(param), value);
    OGLPLUS_VERIFY(
      TextureParameteriEXT, gl_object(tnt._name).gl_enum_value(param), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::get_texture_parameter_iv(
  texture_name_and_target tnt,
  oglplus::texture_parameter param,
  span<GLint> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetTextureParameterivEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     GLenum(param),
     values.data());
    OGLPLUS_VERIFY(
      GetTextureParameterivEXT,
      gl_object(tnt._name).gl_enum_value(param),
      always);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
inline outcome<void>
texture_ops::get_texture_level_parameter_iv(
  texture_name_and_target tnt,
  GLint level,
  oglplus::texture_parameter param,
  span<GLint> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetTextureLevelParameterivEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     level,
     GLenum(param),
     values.data());
    OGLPLUS_VERIFY(
      GetTextureLevelParameterivEXT,
      gl_object(tnt._name).gl_index(GLuint(level)).gl_enum_value(param),
      always);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_parameter_f(
  texture_name_and_target tnt,
  oglplus::texture_parameter param,
  GLfloat value) noexcept {
    OGLPLUS_GLFUNC(TextureParameterfEXT)
    (get_raw_name(tnt._name), GLenum(tnt._target), GLenum(param), value);
    OGLPLUS_VERIFY(
      TextureParameterfEXT, gl_object(tnt._name).gl_enum_value(param), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::get_texture_parameter_fv(
  texture_name_and_target tnt,
  oglplus::texture_parameter param,
  span<GLfloat> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetTextureParameterfvEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     GLenum(param),
     values.data());
    OGLPLUS_VERIFY(
      GetTextureParameterfvEXT,
      gl_object(tnt._name).gl_enum_value(param),
      always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
texture_ops::texture_parameter_fv(
  texture_name_and_target tnt,
  oglplus::texture_parameter param,
  span<const GLfloat> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(TextureParameterfvEXT)
    (get_raw_name(tnt._name),
     GLenum(tnt._target),
     GLenum(param),
     values.data());
    OGLPLUS_VERIFY(
      TextureParameterfvEXT, gl_object(tnt._name).gl_enum_value(param), always);
    return {};
}
#endif
//------------------------------------------------------------------------------
template <typename R, typename P, typename N, typename T>
inline outcome<R>
texture_ops::return_texture_parameter_i(
  object_name_or_target<N, T> tnt,
  oglplus::texture_parameter parameter) noexcept {
    GLint result = 0;
    return get_texture_parameter_iv(tnt, parameter, {&result, 1}), R(P(result));
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
template <typename R, typename P, typename N, typename T>
inline outcome<R>
texture_ops::return_texture_level_parameter_i(
  object_name_or_target<N, T> tnt,
  GLint level,
  oglplus::texture_parameter parameter) noexcept {
    GLint result = 0;
    return get_texture_level_parameter_iv(tnt, level, parameter, {&result, 1}),
           R(P(result));
}
#endif
//------------------------------------------------------------------------------
template <typename R, typename N, typename T>
inline outcome<R>
texture_ops::return_texture_parameter_f(
  object_name_or_target<N, T> tnt,
  oglplus::texture_parameter parameter) noexcept {
    GLfloat result = 0;
    return get_texture_parameter_fv(tnt, parameter, {&result, 1}), R(result);
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0) || defined(GL_ES_VERSION_3_1)
template <typename TNT>
inline outcome<GLsizei>
texture_ops::get_texture_width(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<GLsizei, GLsizei>(
      _wrap(tnt), level, oglplus::texture_parameter(GL_TEXTURE_WIDTH));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLsizei>
texture_ops::get_texture_height(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<GLsizei, GLsizei>(
      _wrap(tnt), level, oglplus::texture_parameter(GL_TEXTURE_HEIGHT));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLsizei>
texture_ops::get_texture_depth(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<GLsizei, GLsizei>(
      _wrap(tnt), level, oglplus::texture_parameter(GL_TEXTURE_DEPTH));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<pixel_data_type>
texture_ops::get_texture_red_type(const TNT& tnt) noexcept {
    return return_texture_parameter_i<pixel_data_type, GLenum>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_RED_TYPE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLsizei>
texture_ops::get_texture_red_size(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<GLsizei, GLsizei>(
      _wrap(tnt), level, oglplus::texture_parameter(GL_TEXTURE_RED_SIZE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<pixel_data_type>
texture_ops::get_texture_green_type(const TNT& tnt) noexcept {
    return return_texture_parameter_i<pixel_data_type, GLenum>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_GREEN_TYPE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLsizei>
texture_ops::get_texture_green_size(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<GLsizei, GLsizei>(
      _wrap(tnt), level, oglplus::texture_parameter(GL_TEXTURE_GREEN_SIZE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<pixel_data_type>
texture_ops::get_texture_blue_type(const TNT& tnt) noexcept {
    return return_texture_parameter_i<pixel_data_type, GLenum>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_BLUE_TYPE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLsizei>
texture_ops::get_texture_blue_size(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<GLsizei, GLsizei>(
      _wrap(tnt), level, oglplus::texture_parameter(GL_TEXTURE_BLUE_SIZE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<pixel_data_type>
texture_ops::get_texture_alpha_type(const TNT& tnt) noexcept {
    return return_texture_parameter_i<pixel_data_type, GLenum>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_ALPHA_TYPE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLsizei>
texture_ops::get_texture_alpha_size(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<GLsizei, GLsizei>(
      _wrap(tnt), level, oglplus::texture_parameter(GL_TEXTURE_ALPHA_SIZE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<pixel_data_type>
texture_ops::get_texture_depth_type(const TNT& tnt) noexcept {
    return return_texture_parameter_i<pixel_data_type, GLenum>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_DEPTH_TYPE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLsizei>
texture_ops::get_texture_depth_size(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<GLsizei, GLsizei>(
      _wrap(tnt), level, oglplus::texture_parameter(GL_TEXTURE_DEPTH_SIZE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLsizei>
texture_ops::get_texture_stencil_size(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<GLsizei, GLsizei>(
      _wrap(tnt), level, oglplus::texture_parameter(GL_TEXTURE_STENCIL_SIZE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLsizei>
texture_ops::get_texture_shared_size(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<GLsizei, GLsizei>(
      _wrap(tnt), level, oglplus::texture_parameter(GL_TEXTURE_SHARED_SIZE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<boolean>
texture_ops::is_texture_compressed(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<boolean, GLboolean>(
      _wrap(tnt), level, oglplus::texture_parameter(GL_TEXTURE_COMPRESSED));
}
//------------------------------------------------------------------------------
#if defined(GL_TEXTURE_COMPRESSED_IMAGE_SIZE)
template <typename TNT>
inline outcome<GLsizei>
texture_ops::get_texture_compressed_image_size(
  const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<GLsizei, GLsizei>(
      _wrap(tnt),
      level,
      oglplus::texture_parameter(GL_TEXTURE_COMPRESSED_IMAGE_SIZE));
}
#endif
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<oglplus::pixel_data_internal_format>
texture_ops::get_texture_internal_format(const TNT& tnt, GLint level) noexcept {
    return return_texture_level_parameter_i<
      oglplus::pixel_data_internal_format,
      GLenum>(
      _wrap(tnt),
      level,
      oglplus::texture_parameter(GL_TEXTURE_INTERNAL_FORMAT));
}
#endif
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<void>
texture_ops::texture_min_filter(
  const TNT& tnt, oglplus::texture_min_filter value) noexcept {
    return texture_parameter_i(
      _wrap(tnt),
      oglplus::texture_parameter(GL_TEXTURE_MIN_FILTER),
      GLint(GLenum(value)));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<oglplus::texture_min_filter>
texture_ops::get_texture_min_filter(const TNT& tnt) noexcept {
    return return_texture_parameter_i<oglplus::texture_min_filter, GLenum>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_MIN_FILTER));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<void>
texture_ops::texture_mag_filter(
  const TNT& tnt, oglplus::texture_mag_filter value) noexcept {
    return texture_parameter_i(
      _wrap(tnt),
      oglplus::texture_parameter(GL_TEXTURE_MAG_FILTER),
      GLint(GLenum(value)));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<oglplus::texture_mag_filter>
texture_ops::get_texture_mag_filter(const TNT& tnt) noexcept {
    return return_texture_parameter_i<oglplus::texture_mag_filter, GLenum>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_MAG_FILTER));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<void>
texture_ops::texture_compare_func(
  const TNT& tnt, oglplus::compare_function value) noexcept {
    return texture_parameter_i(
      _wrap(tnt),
      oglplus::texture_parameter(GL_TEXTURE_COMPARE_FUNC),
      GLint(GLenum(value)));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<oglplus::compare_function>
texture_ops::get_texture_compare_func(const TNT& tnt) noexcept {
    return return_texture_parameter_i<oglplus::compare_function, GLenum>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_COMPARE_FUNC));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<void>
texture_ops::texture_compare_mode(
  const TNT& tnt, oglplus::texture_compare_mode value) noexcept {
    return texture_parameter_i(
      _wrap(tnt),
      oglplus::texture_parameter(GL_TEXTURE_COMPARE_MODE),
      GLint(GLenum(value)));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<oglplus::texture_compare_mode>
texture_ops::get_texture_compare_mode(const TNT& tnt) noexcept {
    return return_texture_parameter_i<oglplus::texture_compare_mode, GLenum>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_COMPARE_MODE));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<void>
texture_ops::texture_wrap(
  const TNT& tnt, texture_wrap_coord coord, texture_wrap_mode value) noexcept {
    return texture_parameter_i(
      _wrap(tnt),
      oglplus::texture_parameter(GLenum(coord)),
      GLint(GLenum(value)));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<texture_wrap_mode>
texture_ops::get_texture_wrap(
  const TNT& tnt, texture_wrap_coord coord) noexcept {
    return return_texture_parameter_i<texture_wrap_mode, GLenum>(
      _wrap(tnt), oglplus::texture_parameter(GLenum(coord)));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<void>
texture_ops::texture_swizzle(
  const TNT& tnt,
  texture_swizzle_coord coord,
  texture_swizzle_mode value) noexcept {
    return texture_parameter_i(
      _wrap(tnt),
      oglplus::texture_parameter(GLenum(coord)),
      GLint(GLenum(value)));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<texture_swizzle_mode>
texture_ops::get_texture_swizzle(
  const TNT& tnt, texture_swizzle_coord coord) noexcept {
    return return_texture_parameter_i<texture_swizzle_mode, GLenum>(
      _wrap(tnt), oglplus::texture_parameter(GLenum(coord)));
}
//------------------------------------------------------------------------------
#if defined(GL_TEXTURE_LOD_BIAS)
template <typename TNT>
inline outcome<void>
texture_ops::texture_lod_bias(const TNT& tnt, GLfloat value) noexcept {
    return texture_parameter_f(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_LOD_BIAS), value);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLfloat>
texture_ops::get_texture_lod_bias(const TNT& tnt) noexcept {
    return return_texture_parameter_f<GLfloat>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_LOD_BIAS));
}
#endif
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<void>
texture_ops::texture_min_lod(const TNT& tnt, GLfloat value) noexcept {
    return texture_parameter_f(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_MIN_LOD), value);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLfloat>
texture_ops::get_texture_min_lod(const TNT& tnt) noexcept {
    return return_texture_parameter_f<GLfloat>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_MIN_LOD));
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<void>
texture_ops::texture_max_lod(const TNT& tnt, GLfloat value) noexcept {
    return texture_parameter_f(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_MAX_LOD), value);
}
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<GLfloat>
texture_ops::get_texture_max_lod(const TNT& tnt) noexcept {
    return return_texture_parameter_f<GLfloat>(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_MAX_LOD));
}
//------------------------------------------------------------------------------
#if defined(GL_TEXTURE_BORDER_COLOR)
template <typename TNT>
inline outcome<void>
texture_ops::texture_border_color(
  const TNT& tnt, span<const GLfloat> c) noexcept {
    assert(c.size() >= 4);
    return texture_parameter_fv(
      _wrap(tnt), oglplus::texture_parameter(GL_TEXTURE_BORDER_COLOR), c);
}
#endif
//------------------------------------------------------------------------------
template <typename TNT>
inline outcome<void>
texture_ops::texture_border_color(
  const TNT& tnt, GLfloat r, GLfloat g, GLfloat b, GLfloat a) noexcept {
    const GLfloat c[4] = {r, g, b, a};
    return texture_border_color(tnt, c);
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline deferred_error_handler
obj_gen_del_ops<tag::texture>::_gen(span<GLuint> names) noexcept {
    OGLPLUS_GLFUNC(GenTextures)(GLsizei(names.size()), names.data());
    OGLPLUS_VERIFY_SIMPLE(GenTextures, debug);
    return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_create
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5)
inline deferred_error_handler
obj_gen_del_ops<tag::texture>::_create(
  texture_target target, span<GLuint> names) noexcept {
    OGLPLUS_GLFUNC(CreateTextures)
    (GLenum(target), GLsizei(names.size()), names.data());
    OGLPLUS_VERIFY(CreateTextures, gl_enum_value(target), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline deferred_error_handler
obj_gen_del_ops<tag::texture>::_delete(span<GLuint> names) noexcept {
    OGLPLUS_GLFUNC(DeleteTextures)(GLsizei(names.size()), names.data());
    OGLPLUS_VERIFY_SIMPLE(DeleteTextures, debug);
    return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline outcome<boolean>
obj_gen_del_ops<tag::texture>::_is_a(GLuint name) noexcept {
    GLboolean res = OGLPLUS_GLFUNC(IsTexture)(name);
    OGLPLUS_VERIFY_SIMPLE(IsTexture, debug);
    return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
//------------------------------------------------------------------------------
