/**
 *  @file oglplus/path_nv.inl
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
template <typename T>
inline outcome<void>
path_nv_ops::path_commands(path_nv_name path,
  span<const GLubyte> commands,
  span<const T> coords) noexcept {
    OGLPLUS_GLFUNC(PathCommandsNV)
    (get_raw_name(path),
      GLsizei(commands.size()),
      commands.data(),
      GLsizei(coords.size()),
      GLenum(get_data_type<T>()),
      static_cast<const void*>(coords.data()));
    OGLPLUS_VERIFY(PathCommandsNV, gl_object(path), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename T>
inline outcome<void>
path_nv_ops::path_commands(
  path_nv_name path, const path_nv_spec<T>& spec) noexcept {
    return path_commands<T>(path, spec._commands, spec._coords);
}
//------------------------------------------------------------------------------
template <typename T>
inline outcome<void>
path_nv_ops::path_sub_commands(path_nv_name path,
  GLsizei command_start,
  GLsizei commands_to_delete,
  span<const GLubyte> commands,
  span<const T> coords) noexcept {
    OGLPLUS_GLFUNC(PathSubCommandsNV)
    (get_raw_name(path),
      command_start,
      commands_to_delete,
      GLsizei(commands.size()),
      commands.data(),
      GLsizei(coords.size()),
      GLenum(get_data_type<T>()),
      static_cast<const void*>(coords.data()));
    OGLPLUS_VERIFY(PathSubCommandsNV, gl_object(path), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename T>
inline outcome<void>
path_nv_ops::path_sub_commands(path_nv_name path,
  GLsizei command_start,
  GLsizei commands_to_delete,
  const path_nv_spec<T>& spec) noexcept {
    return path_sub_commands<T>(
      path, command_start, commands_to_delete, spec._commands, spec._coords);
}
//------------------------------------------------------------------------------
template <typename T>
inline outcome<void>
path_nv_ops::path_coords(path_nv_name path, span<const T> coords) noexcept {
    OGLPLUS_GLFUNC(PathCoordsNV)
    (get_raw_name(path),
      GLsizei(coords.size()),
      GLenum(get_data_type<T>()),
      static_cast<const void*>(coords.data()));
    OGLPLUS_VERIFY(PathCoordsNV, gl_object(path), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_string(path_nv_name path,
  path_format_nv format,
  span<const char> path_str) noexcept {
    OGLPLUS_GLFUNC(PathStringNV)
    (get_raw_name(path),
      GLenum(format),
      GLsizei(path_str.size()),
      static_cast<const void*>(path_str.data()));
    OGLPLUS_VERIFY(PathStringNV, gl_enum_value(format).gl_object(path), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_svg_string(path_nv_name path, span<const char> str) noexcept {
    return path_string(path, path_format_nv(GL_PATH_FORMAT_SVG_NV), str);
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_ps_string(path_nv_name path, span<const char> str) noexcept {
    return path_string(path, path_format_nv(GL_PATH_FORMAT_PS_NV), str);
}
//------------------------------------------------------------------------------
inline outcome<boolean>
path_nv_ops::is_point_in_fill_path(
  path_nv_name path, GLuint mask, GLfloat x, GLfloat y) noexcept {
    boolean result =
      OGLPLUS_GLFUNC(IsPointInFillPathNV)(get_raw_name(path), mask, x, y);
    OGLPLUS_VERIFY(IsPointInFillPathNV, gl_object(path), debug);
    return {result};
}
//------------------------------------------------------------------------------
inline outcome<boolean>
path_nv_ops::is_point_in_stroke_path(
  path_nv_name path, GLfloat x, GLfloat y) noexcept {
    boolean result =
      OGLPLUS_GLFUNC(IsPointInStrokePathNV)(get_raw_name(path), x, y);
    OGLPLUS_VERIFY(IsPointInStrokePathNV, gl_object(path), debug);
    return {result};
}
//------------------------------------------------------------------------------
inline outcome<GLfloat>
path_nv_ops::get_path_length(
  path_nv_name path, GLsizei start_segment, GLsizei num_segments) noexcept {
    GLfloat result = OGLPLUS_GLFUNC(GetPathLengthNV)(
      get_raw_name(path), start_segment, num_segments);
    OGLPLUS_VERIFY(GetPathLengthNV, gl_object(path), debug);
    return {result};
}
//------------------------------------------------------------------------------
inline outcome<boolean>
path_nv_ops::point_along_path(path_nv_name path,
  GLsizei start_seg,
  GLsizei num_segs,
  GLfloat distance,
  GLfloat& ref_x,
  GLfloat& ref_y,
  GLfloat& ref_tg_x,
  GLfloat& ref_tg_y) noexcept {
    boolean result = OGLPLUS_GLFUNC(PointAlongPathNV)(get_raw_name(path),
      start_seg,
      num_segs,
      distance,
      &ref_x,
      &ref_y,
      &ref_tg_x,
      &ref_tg_y);
    OGLPLUS_VERIFY(PointAlongPathNV, gl_object(path), debug);
    return {result};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::stencil_fill_path(
  path_nv_name path, path_fill_mode_nv mode, GLuint mask) noexcept {
    OGLPLUS_GLFUNC(StencilFillPathNV)(get_raw_name(path), GLenum(mode), mask);
    OGLPLUS_VERIFY(
      StencilFillPathNV, gl_enum_value(mode).gl_object(path), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::cover_fill_path(
  path_nv_name path, path_fill_cover_mode_nv mode) noexcept {
    OGLPLUS_GLFUNC(CoverFillPathNV)(get_raw_name(path), GLenum(mode));
    OGLPLUS_VERIFY(CoverFillPathNV, gl_enum_value(mode).gl_object(path), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::stencil_stroke_path(
  path_nv_name path, GLint reference, GLuint mask) noexcept {
    OGLPLUS_GLFUNC(StencilStrokePathNV)(get_raw_name(path), reference, mask);
    OGLPLUS_VERIFY(StencilStrokePathNV, gl_object(path), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::cover_stroke_path(
  path_nv_name path, path_stroke_cover_mode_nv mode) noexcept {
    OGLPLUS_GLFUNC(CoverStrokePathNV)(get_raw_name(path), GLenum(mode));
    OGLPLUS_VERIFY(
      CoverStrokePathNV, gl_enum_value(mode).gl_object(path), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_parameter_i(
  path_nv_name path, oglplus::path_parameter_nv param, GLint value) noexcept {
    OGLPLUS_GLFUNC(PathParameteriNV)(get_raw_name(path), GLenum(param), value);
    OGLPLUS_VERIFY(
      PathParameteriNV, gl_enum_value(param).gl_object(path), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_parameter_f(
  path_nv_name path, oglplus::path_parameter_nv param, GLfloat value) noexcept {
    OGLPLUS_GLFUNC(PathParameterfNV)(get_raw_name(path), GLenum(param), value);
    OGLPLUS_VERIFY(
      PathParameterfNV, gl_enum_value(param).gl_object(path), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::get_path_parameter_iv(path_nv_name path,
  oglplus::path_parameter_nv param,
  span<GLint> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetPathParameterivNV)
    (get_raw_name(path), GLenum(param), values.data());
    OGLPLUS_VERIFY(
      GetPathParameterivNV, gl_enum_value(param).gl_object(path), always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::get_path_parameter_fv(path_nv_name path,
  oglplus::path_parameter_nv param,
  span<GLfloat> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetPathParameterfvNV)
    (get_raw_name(path), GLenum(param), values.data());
    OGLPLUS_VERIFY(
      GetPathParameterfvNV, gl_enum_value(param).gl_object(path), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename R, typename T>
inline outcome<R>
path_nv_ops::return_path_parameter_i(
  path_nv_name path, path_parameter_nv parameter) noexcept {
    GLint result = 0;
    return get_path_parameter_iv(path, parameter, {&result, 1}), R(T(result));
}
//------------------------------------------------------------------------------
template <typename R>
inline outcome<R>
path_nv_ops::return_path_parameter_f(
  path_nv_name path, path_parameter_nv parameter) noexcept {
    GLfloat result = 0;
    return get_path_parameter_fv(path, parameter, {&result, 1}), R(result);
}
//------------------------------------------------------------------------------
inline outcome<GLfloat>
path_nv_ops::get_path_computed_length(path_nv_name path) noexcept {
    return return_path_parameter_f<GLfloat>(
      path, path_parameter_nv(GL_PATH_COMPUTED_LENGTH_NV));
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_stroke_width(path_nv_name path, GLfloat value) noexcept {
    return path_parameter_f(
      path, path_parameter_nv(GL_PATH_STROKE_WIDTH_NV), value);
}
//------------------------------------------------------------------------------
inline outcome<GLfloat>
path_nv_ops::get_path_stroke_width(path_nv_name path) noexcept {
    return return_path_parameter_f<GLfloat>(
      path, path_parameter_nv(GL_PATH_STROKE_WIDTH_NV));
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_miter_limit(path_nv_name path, GLfloat value) noexcept {
    return path_parameter_f(
      path, path_parameter_nv(GL_PATH_MITER_LIMIT_NV), value);
}
//------------------------------------------------------------------------------
inline outcome<GLfloat>
path_nv_ops::get_path_miter_limit(path_nv_name path) noexcept {
    return return_path_parameter_f<GLfloat>(
      path, path_parameter_nv(GL_PATH_MITER_LIMIT_NV));
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_join_style(
  path_nv_name path, path_join_style_nv value) noexcept {
    return path_parameter_i(
      path, path_parameter_nv(GL_PATH_JOIN_STYLE_NV), GLint(GLenum(value)));
}
//------------------------------------------------------------------------------
inline outcome<path_join_style_nv>
path_nv_ops::get_path_join_style(path_nv_name path) noexcept {
    return return_path_parameter_i<path_join_style_nv, GLenum>(
      path, path_parameter_nv(GL_PATH_JOIN_STYLE_NV));
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_initial_dash_cap(
  path_nv_name path, path_cap_style_nv value) noexcept {
    return path_parameter_i(path,
      path_parameter_nv(GL_PATH_INITIAL_DASH_CAP_NV),
      GLint(GLenum(value)));
}
//------------------------------------------------------------------------------
inline outcome<path_cap_style_nv>
path_nv_ops::get_path_initial_dash_cap(path_nv_name path) noexcept {
    return return_path_parameter_i<path_cap_style_nv, GLenum>(
      path, path_parameter_nv(GL_PATH_INITIAL_DASH_CAP_NV));
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_terminal_dash_cap(
  path_nv_name path, path_cap_style_nv value) noexcept {
    return path_parameter_i(path,
      path_parameter_nv(GL_PATH_TERMINAL_DASH_CAP_NV),
      GLint(GLenum(value)));
}
//------------------------------------------------------------------------------
inline outcome<path_cap_style_nv>
path_nv_ops::get_path_terminal_dash_cap(path_nv_name path) noexcept {
    return return_path_parameter_i<path_cap_style_nv, GLenum>(
      path, path_parameter_nv(GL_PATH_TERMINAL_DASH_CAP_NV));
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_dash_offset(path_nv_name path, GLfloat value) noexcept {
    return path_parameter_f(
      path, path_parameter_nv(GL_PATH_DASH_OFFSET_NV), value);
}
//------------------------------------------------------------------------------
inline outcome<GLfloat>
path_nv_ops::get_path_dash_offset(path_nv_name path) noexcept {
    return return_path_parameter_f<GLfloat>(
      path, path_parameter_nv(GL_PATH_DASH_OFFSET_NV));
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_dash_offset_reset(
  path_nv_name path, path_dash_offset_reset_nv value) noexcept {
    return path_parameter_i(path,
      path_parameter_nv(GL_PATH_DASH_OFFSET_RESET_NV),
      GLint(GLenum(value)));
}
//------------------------------------------------------------------------------
inline outcome<path_dash_offset_reset_nv>
path_nv_ops::get_path_dash_offset_reset(path_nv_name path) noexcept {
    return return_path_parameter_i<path_dash_offset_reset_nv, GLenum>(
      path, path_parameter_nv(GL_PATH_DASH_OFFSET_RESET_NV));
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::path_dash_array(
  path_nv_name path, span<const GLfloat> dashes) noexcept {
    assert(dashes.size() > 0);
    OGLPLUS_GLFUNC(PathDashArrayNV)
    (get_raw_name(path), GLsizei(dashes.size()), dashes.data());
    OGLPLUS_VERIFY(PathDashArrayNV, gl_object(path), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::copy_path(path_nv_name dst_path, path_nv_name src_path) noexcept {
    OGLPLUS_GLFUNC(CopyPathNV)(get_raw_name(dst_path), get_raw_name(src_path));
    OGLPLUS_VERIFY(CopyPathNV, gl_subject(src_path).gl_object(dst_path), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::interpolate_path(path_nv_name dst_path,
  path_nv_name path_a,
  path_nv_name path_b,
  GLfloat weight) noexcept {
    OGLPLUS_GLFUNC(InterpolatePathsNV)
    (get_raw_name(dst_path),
      get_raw_name(path_a),
      get_raw_name(path_b),
      weight);
    OGLPLUS_VERIFY(InterpolatePathNV, gl_object(dst_path), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
path_nv_ops::transform_path(path_nv_name dst_path,
  path_nv_name src_path,
  path_transform_type_nv transform_type,
  span<const GLfloat> transform_values) noexcept {
    // TODO: check if we have enough values
    OGLPLUS_GLFUNC(TransformPathNV)
    (get_raw_name(dst_path),
      get_raw_name(src_path),
      GLenum(transform_type),
      transform_values.data());
    OGLPLUS_VERIFY(TransformPathNV,
      gl_enum_value(transform_type).gl_subject(src_path).gl_object(dst_path),
      debug);
    return {};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline deferred_error_handler
obj_gen_del_ops<tag::path_nv>::_gen(span<GLuint> names) noexcept {
    GLuint base = OGLPLUS_GLFUNC(GenPathsNV)(GLsizei(names.size()));
    for(span_size_t i = 0; i < names.size(); ++i) {
	names[i] = base + GLuint(i);
    }
    OGLPLUS_VERIFY_SIMPLE(GenPathsNV, debug);
    return {};
}
//------------------------------------------------------------------------------
inline deferred_error_handler
obj_gen_del_ops<tag::path_nv>::_gen(
  object_name_base_and_count_view<GLuint> names) noexcept {
    names.base(OGLPLUS_GLFUNC(GenPathsNV)(GLsizei(names.size())));
    OGLPLUS_VERIFY_SIMPLE(GenPathsNV, debug);
    return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline deferred_error_handler
obj_gen_del_ops<tag::path_nv>::_delete(span<GLuint> names) noexcept {
    if(names.begin() != names.end()) {
	OGLPLUS_GLFUNC(DeletePathsNV)(*names.begin(), GLsizei(names.size()));
	OGLPLUS_VERIFY_SIMPLE(DeletePathsNV, debug);
    }
    return {};
}
//------------------------------------------------------------------------------
inline deferred_error_handler
obj_gen_del_ops<tag::path_nv>::_delete(
  object_name_base_and_count_view<GLuint> names) noexcept {
    if(names.size() > 0) {
	OGLPLUS_GLFUNC(DeletePathsNV)(names.base(), GLsizei(names.size()));
	OGLPLUS_VERIFY_SIMPLE(DeletePathsNV, debug);
    }
    return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline outcome<boolean>
obj_gen_del_ops<tag::path_nv>::_is_a(GLuint name) noexcept {
    GLboolean res = OGLPLUS_GLFUNC(IsPathNV)(name);
    OGLPLUS_VERIFY_SIMPLE(IsPathNV, debug);
    return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
