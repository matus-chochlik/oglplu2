/**
 *  @file oglplus/path_nv_array.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
template <typename S>
inline outcome<void>
path_nv_array_ops::path_glyphs(const object_names<tag::path_nv, S>& paths,
  path_font_target_nv font_target,
  cstr_ref font_name,
  enum_bitfield<path_font_style_nv> font_style,
  cstring_span char_codes,
  path_missing_glyph_nv handle_missing_glyphs,
  GLuint parameter_template,
  GLfloat em_scale) noexcept {
    OGLPLUS_GLFUNC(PathGlyphsNV)
    (get_raw_name(paths),
      GLenum(font_target),
      static_cast<const void*>(font_name.data()),
      GLbitfield(font_style),
      GLsizei(char_codes.size()),
      GLenum(GL_UTF8_NV),
      static_cast<const void*>(char_codes.data()),
      GLenum(handle_missing_glyphs),
      parameter_template,
      em_scale);
    OGLPLUS_VERIFY(
      PathGlyphsNV, gl_enum_value(font_target).gl_object(paths[0]), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S, typename T>
inline outcome<void>
path_nv_array_ops::path_glyphs(const object_names<tag::path_nv, S>& paths,
  path_font_target_nv font_target,
  cstr_ref font_name,
  enum_bitfield<path_font_style_nv> font_style,
  span<T> char_codes,
  path_missing_glyph_nv handle_missing_glyphs,
  GLuint parameter_template,
  GLfloat em_scale) noexcept {
    OGLPLUS_GLFUNC(PathGlyphsNV)
    (get_raw_name(paths),
      GLenum(font_target),
      static_cast<const void*>(font_name.data()),
      GLbitfield(font_style),
      GLsizei(char_codes.size()),
      GLenum(get_data_type<T>()),
      static_cast<const void*>(char_codes.data()),
      GLenum(handle_missing_glyphs),
      parameter_template,
      em_scale);
    OGLPLUS_VERIFY(
      PathGlyphsNV, gl_enum_value(font_target).gl_object(paths[0]), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S>
inline outcome<void>
path_nv_array_ops::path_glyph_range(const object_names<tag::path_nv, S>& paths,
  path_font_target_nv font_target,
  cstr_ref font_name,
  enum_bitfield<path_font_style_nv> font_style,
  GLuint first_glyph,
  GLsizei num_glyphs,
  path_missing_glyph_nv handle_missing_glyphs,
  GLuint parameter_template,
  GLfloat em_scale) noexcept {
    OGLPLUS_GLFUNC(PathGlyphRangeNV)
    (get_raw_name(paths),
      GLenum(font_target),
      static_cast<const void*>(font_name.data()),
      GLbitfield(font_style),
      first_glyph,
      num_glyphs,
      GLenum(handle_missing_glyphs),
      parameter_template,
      em_scale);
    OGLPLUS_VERIFY(
      PathGlyphRangeNV, gl_enum_value(font_target).gl_object(paths[0]), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S, typename T>
inline outcome<void>
path_nv_array_ops::get_path_spacing(path_list_mode_nv list_mode,
  span<T> indices,
  const object_names<tag::path_nv, S>& paths,
  GLfloat advance_scale,
  GLfloat kerning_scale,
  path_transform_type_nv transform_type,
  span<GLfloat> returned_values) noexcept {
    assert(indices.size() <= returned_values.size());

    OGLPLUS_GLFUNC(GetPathSpacingNV)
    (GLenum(list_mode),
      GLsizei(indices.size()),
      GLenum(get_data_type<T>()),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      advance_scale,
      kerning_scale,
      GLenum(transform_type),
      returned_values.data());
    OGLPLUS_VERIFY(
      GetPathSpacingNV, gl_enum_value(list_mode).gl_object(paths[0]), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S>
inline outcome<void>
path_nv_array_ops::get_path_spacing(path_list_mode_nv list_mode,
  cstring_span indices,
  const object_names<tag::path_nv, S>& paths,
  GLfloat advance_scale,
  GLfloat kerning_scale,
  path_transform_type_nv transform_type,
  span<GLfloat> returned_values) noexcept {
    OGLPLUS_GLFUNC(GetPathSpacingNV)
    (GLenum(list_mode),
      GLsizei(indices.size() + 1),
      GLenum(GL_UTF8_NV),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      advance_scale,
      kerning_scale,
      GLenum(transform_type),
      returned_values.data());
    OGLPLUS_VERIFY(
      GetPathSpacingNV, gl_enum_value(list_mode).gl_object(paths[0]), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S, typename T>
inline outcome<void>
path_nv_array_ops::get_path_metrics(
  enum_bitfield<path_metric_query_nv> query_mask,
  span<T> indices,
  const object_names<tag::path_nv, S>& paths,
  GLsizei stride,
  span<GLfloat> returned_values) noexcept {
    assert(indices.size() <= returned_values.size());

    OGLPLUS_GLFUNC(GetPathMetricsNV)
    (GLbitfield(query_mask),
      GLsizei(indices.size()),
      GLenum(get_data_type<T>()),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      stride,
      returned_values.data());
    OGLPLUS_VERIFY(GetPathMetricsNV, gl_object(paths[0]), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S>
inline outcome<void>
path_nv_array_ops::get_path_metrics(
  enum_bitfield<path_metric_query_nv> query_mask,
  cstring_span indices,
  const object_names<tag::path_nv, S>& paths,
  GLsizei stride,
  span<GLfloat> returned_values) noexcept {
    OGLPLUS_GLFUNC(GetPathMetricsNV)
    (GLbitfield(query_mask),
      GLsizei(indices.size()),
      GLenum(GL_UTF8_NV),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      stride,
      returned_values.data());
    OGLPLUS_VERIFY(GetPathMetricsNV, gl_object(paths[0]), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S>
inline outcome<void>
path_nv_array_ops::get_path_metric_range(
  enum_bitfield<path_metric_query_nv> query_mask,
  const object_names<tag::path_nv, S>& paths,
  GLsizei num_paths,
  GLsizei stride,
  span<GLfloat> returned_values) noexcept {
    OGLPLUS_GLFUNC(GetPathMetricRangeNV)
    (GLbitfield(query_mask),
      get_raw_name(paths),
      num_paths,
      stride,
      returned_values.data());
    OGLPLUS_VERIFY(GetPathMetricRangeNV, gl_object(paths[0]), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S, typename T>
inline outcome<void>
path_nv_array_ops::stencil_fill_path_instanced(span<T> indices,
  const object_names<tag::path_nv, S>& paths,
  path_fill_mode_nv mode,
  GLuint mask,
  path_transform_type_nv transform_type,
  span<const GLfloat> transform_values) noexcept {
    OGLPLUS_GLFUNC(StencilFillPathInstancedNV)
    (GLsizei(indices.size()),
      GLenum(get_data_type<T>()),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      GLenum(mode),
      mask,
      GLenum(transform_type),
      transform_values.data());
    OGLPLUS_VERIFY(StencilFillPathInstancedNV,
      gl_enum_value(mode).gl_object(paths[0]),
      always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S>
inline outcome<void>
path_nv_array_ops::stencil_fill_path_instanced(cstring_span indices,
  const object_names<tag::path_nv, S>& paths,
  path_fill_mode_nv mode,
  GLuint mask,
  path_transform_type_nv transform_type,
  span<const GLfloat> transform_values) noexcept {
    OGLPLUS_GLFUNC(StencilFillPathInstancedNV)
    (GLsizei(indices.size()),
      GLenum(GL_UTF8_NV),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      GLenum(mode),
      mask,
      GLenum(transform_type),
      transform_values.data());
    OGLPLUS_VERIFY(StencilFillPathInstancedNV,
      gl_enum_value(mode).gl_object(paths[0]),
      always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S, typename T>
inline outcome<void>
path_nv_array_ops::cover_fill_path_instanced(span<T> indices,
  const object_names<tag::path_nv, S>& paths,
  path_fill_cover_mode_nv mode,
  path_transform_type_nv transform_type,
  span<const GLfloat> transform_values) noexcept {
    OGLPLUS_GLFUNC(CoverFillPathInstancedNV)
    (GLsizei(indices.size()),
      GLenum(get_data_type<T>()),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      GLenum(mode),
      GLenum(transform_type),
      transform_values.data());
    OGLPLUS_VERIFY(CoverFillPathInstancedNV,
      gl_enum_value(mode).gl_object(paths[0]),
      always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S>
inline outcome<void>
path_nv_array_ops::cover_fill_path_instanced(cstring_span indices,
  const object_names<tag::path_nv, S>& paths,
  path_fill_cover_mode_nv mode,
  path_transform_type_nv transform_type,
  span<const GLfloat> transform_values) noexcept {
    OGLPLUS_GLFUNC(CoverFillPathInstancedNV)
    (GLsizei(indices.size()),
      GLenum(GL_UTF8_NV),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      GLenum(mode),
      GLenum(transform_type),
      transform_values.data());
    OGLPLUS_VERIFY(CoverFillPathInstancedNV,
      gl_enum_value(mode).gl_object(paths[0]),
      always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S, typename T>
inline outcome<void>
path_nv_array_ops::stencil_stroke_path_instanced(span<T> indices,
  const object_names<tag::path_nv, S>& paths,
  GLint reference,
  GLuint mask,
  path_transform_type_nv transform_type,
  span<const GLfloat> transform_values) noexcept {
    OGLPLUS_GLFUNC(StencilStrokePathInstancedNV)
    (GLsizei(indices.size()),
      GLenum(get_data_type<T>()),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      reference,
      mask,
      GLenum(transform_type),
      transform_values.data());
    OGLPLUS_VERIFY(StencilStrokePathInstancedNV, gl_object(paths[0]), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S>
inline outcome<void>
path_nv_array_ops::stencil_stroke_path_instanced(cstring_span indices,
  const object_names<tag::path_nv, S>& paths,
  GLint reference,
  GLuint mask,
  path_transform_type_nv transform_type,
  span<const GLfloat> transform_values) noexcept {
    OGLPLUS_GLFUNC(StencilStrokePathInstancedNV)
    (GLsizei(indices.size()),
      GLenum(GL_UTF8_NV),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      reference,
      mask,
      GLenum(transform_type),
      transform_values.data());
    OGLPLUS_VERIFY(StencilStrokePathInstancedNV, gl_object(paths[0]), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S, typename T>
inline outcome<void>
path_nv_array_ops::cover_stroke_path_instanced(span<T> indices,
  const object_names<tag::path_nv, S>& paths,
  path_stroke_cover_mode_nv mode,
  path_transform_type_nv transform_type,
  span<const GLfloat> transform_values) noexcept {
    OGLPLUS_GLFUNC(CoverStrokePathInstancedNV)
    (GLsizei(indices.size()),
      GLenum(get_data_type<T>()),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      GLenum(mode),
      GLenum(transform_type),
      transform_values.data());
    OGLPLUS_VERIFY(CoverStrokePathInstancedNV,
      gl_enum_value(mode).gl_object(paths[0]),
      always);
    return {};
}
//------------------------------------------------------------------------------
template <typename S>
inline outcome<void>
path_nv_array_ops::cover_stroke_path_instanced(cstring_span indices,
  const object_names<tag::path_nv, S>& paths,
  path_stroke_cover_mode_nv mode,
  path_transform_type_nv transform_type,
  span<const GLfloat> transform_values) noexcept {
    OGLPLUS_GLFUNC(CoverStrokePathInstancedNV)
    (GLsizei(indices.size()),
      GLenum(GL_UTF8_NV),
      static_cast<const void*>(indices.data()),
      get_raw_name(paths),
      GLenum(mode),
      GLenum(transform_type),
      transform_values.data());
    OGLPLUS_VERIFY(CoverStrokePathInstancedNV,
      gl_enum_value(mode).gl_object(paths[0]),
      always);
    return {};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
