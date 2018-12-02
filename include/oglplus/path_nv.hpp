/**
 *  @file oglplus/path_nv.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PATH_NV_1509260923_HPP
#define OGLPLUS_PATH_NV_1509260923_HPP

#include "data_type.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "object/owner.hpp"
#include "path_nv_name.hpp"
#include "path_nv_spec.hpp"
#include "utils/boolean.hpp"
#include "utils/gl_func.hpp"

namespace oglplus {
namespace oper {

struct path_nv_ops {
    template <typename T>
    static outcome<void> path_commands(
      path_nv_name path,
      span<const GLubyte> commands,
      span<const T> coords) noexcept;

    template <typename T>
    static outcome<void>
    path_commands(path_nv_name path, const path_nv_spec<T>& spec) noexcept;

    template <typename T>
    static outcome<void> path_sub_commands(
      path_nv_name path,
      GLsizei command_start,
      GLsizei commands_to_delete,
      span<const GLubyte> commands,
      span<const T> coords) noexcept;

    template <typename T>
    static outcome<void> path_sub_commands(
      path_nv_name path,
      GLsizei command_start,
      GLsizei commands_to_delete,
      const path_nv_spec<T>& spec) noexcept;

    template <typename T>
    static outcome<void>
    path_coords(path_nv_name path, span<const T> coords) noexcept;

    static outcome<void> path_string(
      path_nv_name, path_format_nv format, span<const char> path_str) noexcept;

    static outcome<void>
    path_svg_string(path_nv_name, span<const char> path_str) noexcept;

    static outcome<void>
    path_ps_string(path_nv_name, span<const char> path_str) noexcept;

    static outcome<boolean> is_point_in_fill_path(
      path_nv_name, GLuint mask, GLfloat x, GLfloat y) noexcept;

    static outcome<boolean>
    is_point_in_stroke_path(path_nv_name, GLfloat x, GLfloat y) noexcept;

    static outcome<GLfloat>
    get_path_length(path_nv_name, GLsizei start_seg, GLsizei num_segs) noexcept;

    static outcome<boolean> point_along_path(
      path_nv_name,
      GLsizei start_seg,
      GLsizei num_segs,
      GLfloat distance,
      GLfloat& ref_x,
      GLfloat& ref_y,
      GLfloat& ref_tg_x,
      GLfloat& ref_tg_y) noexcept;

    static outcome<void> stencil_fill_path(
      path_nv_name, path_fill_mode_nv mode, GLuint mask) noexcept;

    static outcome<void>
    cover_fill_path(path_nv_name, path_fill_cover_mode_nv mode) noexcept;

    static outcome<void>
    stencil_stroke_path(path_nv_name, GLint reference, GLuint mask) noexcept;

    static outcome<void>
    cover_stroke_path(path_nv_name, path_stroke_cover_mode_nv mode) noexcept;

    static outcome<void> path_parameter_i(
      path_nv_name path,
      oglplus::path_parameter_nv param,
      GLint value) noexcept;

    static outcome<void> path_parameter_f(
      path_nv_name path,
      oglplus::path_parameter_nv param,
      GLfloat value) noexcept;

    static outcome<void> get_path_parameter_iv(
      path_nv_name path,
      oglplus::path_parameter_nv param,
      span<GLint> values) noexcept;

    static outcome<void> get_path_parameter_fv(
      path_nv_name path,
      oglplus::path_parameter_nv param,
      span<GLfloat> values) noexcept;

    template <typename R, typename T>
    static outcome<R>
    return_path_parameter_i(path_nv_name, path_parameter_nv param) noexcept;

    template <typename R>
    static outcome<R>
    return_path_parameter_f(path_nv_name, path_parameter_nv param) noexcept;

    static outcome<GLfloat> get_path_computed_length(path_nv_name) noexcept;

    static outcome<void>
    path_stroke_width(path_nv_name, GLfloat value) noexcept;

    static outcome<GLfloat> get_path_stroke_width(path_nv_name) noexcept;

    static outcome<void> path_miter_limit(path_nv_name, GLfloat value) noexcept;

    static outcome<GLfloat> get_path_miter_limit(path_nv_name) noexcept;

    static outcome<void>
    path_join_style(path_nv_name, path_join_style_nv value) noexcept;

    static outcome<path_join_style_nv>
      get_path_join_style(path_nv_name) noexcept;

    static outcome<void>
    path_initial_end_cap(path_nv_name, path_cap_style_nv value) noexcept;

    static outcome<path_cap_style_nv>
      get_path_initial_end_cap(path_nv_name) noexcept;

    static outcome<void>
    path_terminal_end_cap(path_nv_name, path_cap_style_nv value) noexcept;

    static outcome<path_cap_style_nv>
      get_path_terminal_end_cap(path_nv_name) noexcept;

    static outcome<void>
    path_initial_dash_cap(path_nv_name, path_cap_style_nv value) noexcept;

    static outcome<path_cap_style_nv>
      get_path_initial_dash_cap(path_nv_name) noexcept;

    static outcome<void>
    path_terminal_dash_cap(path_nv_name, path_cap_style_nv value) noexcept;

    static outcome<path_cap_style_nv>
      get_path_terminal_dash_cap(path_nv_name) noexcept;

    static outcome<void> path_dash_offset(path_nv_name, GLfloat value) noexcept;

    static outcome<GLfloat> get_path_dash_offset(path_nv_name) noexcept;

    static outcome<void> path_dash_offset_reset(
      path_nv_name, path_dash_offset_reset_nv value) noexcept;

    static outcome<path_dash_offset_reset_nv>
      get_path_dash_offset_reset(path_nv_name) noexcept;

    static outcome<void>
    path_dash_array(path_nv_name, span<const GLfloat> dashes) noexcept;

    static outcome<void>
    copy_path(path_nv_name dst_path, path_nv_name src_path) noexcept;

    static outcome<void> interpolate_path(
      path_nv_name dst_path,
      path_nv_name path_a,
      path_nv_name path_b,
      GLfloat weight) noexcept;

    static outcome<void> transform_path(
      path_nv_name dst_path,
      path_nv_name src_path,
      path_transform_type_nv transform_type,
      span<const GLfloat> transform_values) noexcept;
};

} // namespace oper

template <typename Derived, typename Base>
struct obj_member_ops<tag::path_nv, Derived, Base> : Base {
private:
    Derived& _self() noexcept {
        return *static_cast<Derived*>(this);
    }

    typedef oper::path_nv_ops _ops;

protected:
    using Base::Base;

public:
    template <typename T>
    outcome<Derived&>
    commands(span<const GLubyte> cmds, span<const T> crds) noexcept {
        return {_ops::path_commands(*this, cmds, crds), _self()};
    }

    template <typename T>
    outcome<Derived&> commands(const path_nv_spec<T>& spec) noexcept {
        return {_ops::path_commands(*this, spec), _self()};
    }

    template <typename T>
    outcome<Derived&> sub_commands(
      GLsizei cmd_start,
      GLsizei cmds_to_delete,
      span<const GLubyte> cmds,
      span<const T> crds) noexcept {
        return {
          _ops::path_sub_commands(*this, cmd_start, cmds_to_delete, cmds, crds),
          _self()};
    }

    template <typename T>
    outcome<Derived&> sub_commands(
      GLsizei cmd_start,
      GLsizei cmds_to_delete,
      const path_nv_spec<T>& spec) noexcept {
        return {_ops::path_sub_commands(*this, cmd_start, cmds_to_delete, spec),
                _self()};
    }

    template <typename T>
    outcome<Derived&> coords(span<const T> crds) noexcept {
        return {_ops::path_coords(*this, crds), _self()};
    }

    outcome<Derived&>
    string(path_format_nv format, span<const char> path_str) noexcept {
        return {_ops::path_string(*this, format, path_str), _self()};
    }

    outcome<Derived&> svg_string(span<const char> path_str) noexcept {
        return {_ops::path_svg_string(*this, path_str), _self()};
    }

    outcome<Derived&> ps_string(span<const char> path_str) noexcept {
        return {_ops::path_ps_string(*this, path_str), _self()};
    }

    outcome<boolean>
    is_point_in_fill(GLuint mask, GLfloat x, GLfloat y) noexcept {
        return _ops::is_point_in_fill_path(*this, mask, x, y);
    }

    outcome<boolean> is_point_in_stroke(GLfloat x, GLfloat y) noexcept {
        return _ops::is_point_in_stroke_path(*this, x, y);
    }

    outcome<GLfloat> get_length(GLsizei start_seg, GLsizei num_segs) noexcept {
        return _ops::get_path_length(*this, start_seg, num_segs);
    }

    outcome<boolean> point_along(
      GLsizei start_seg,
      GLsizei num_segs,
      GLfloat distance,
      GLfloat& ref_x,
      GLfloat& ref_y,
      GLfloat& ref_tg_x,
      GLfloat& ref_tg_y) noexcept {
        return _ops::point_along_path(
          *this,
          start_seg,
          num_segs,
          distance,
          ref_x,
          ref_y,
          ref_tg_x,
          ref_tg_y);
    }

    outcome<Derived&>
    stencil_fill(path_fill_mode_nv mode, GLuint mask) noexcept {
        return {_ops::stencil_fill_path(*this, mode, mask), _self()};
    }

    outcome<Derived&> cover_fill(path_fill_cover_mode_nv mode) noexcept {
        return {_ops::cover_fill_path(*this, mode), _self()};
    }

    outcome<Derived&> stencil_stroke(GLint ref, GLuint mask) noexcept {
        return {_ops::stencil_stroke_path(*this, ref, mask), _self()};
    }

    outcome<Derived&> cover_stroke(path_stroke_cover_mode_nv mode) noexcept {
        return {_ops::cover_stroke_path(*this, mode), _self()};
    }

    outcome<GLfloat> get_computed_length() const noexcept {
        return _ops::get_path_computed_length(*this);
    }

    outcome<Derived&> stroke_width(GLfloat value) noexcept {
        return {_ops::path_stroke_width(*this, value), _self()};
    }

    outcome<GLfloat> get_stroke_width() const noexcept {
        return _ops::get_path_stroke_width(*this);
    }

    outcome<Derived&> miter_limit(GLfloat value) noexcept {
        return {_ops::path_miter_limit(*this, value), _self()};
    }

    outcome<GLfloat> get_miter_limit() const noexcept {
        return _ops::get_path_miter_limit(*this);
    }

    outcome<Derived&> join_style(path_join_style_nv value) noexcept {
        return {_ops::path_join_style(*this, value), _self()};
    }

    outcome<path_join_style_nv> get_join_style() noexcept {
        return _ops::get_path_join_style(*this);
    }

    outcome<Derived&> initial_end_cap(path_cap_style_nv value) noexcept {
        return {_ops::path_initial_end_cap(*this, value), _self()};
    }

    outcome<path_cap_style_nv> get_initial_end_cap() noexcept {
        return _ops::get_path_initial_end_cap(*this);
    }

    outcome<Derived&> terminal_end_cap(path_cap_style_nv value) noexcept {
        return {_ops::path_terminal_end_cap(*this, value), _self()};
    }

    outcome<path_cap_style_nv> get_terminal_end_cap() noexcept {
        return _ops::get_path_terminal_end_cap(*this);
    }

    outcome<Derived&> initial_dash_cap(path_cap_style_nv value) noexcept {
        return {_ops::path_initial_dash_cap(*this, value), _self()};
    }

    outcome<path_cap_style_nv> get_initial_dash_cap() noexcept {
        return _ops::get_path_initial_dash_cap(*this);
    }

    outcome<Derived&> terminal_dash_cap(path_cap_style_nv value) noexcept {
        return {_ops::path_terminal_dash_cap(*this, value), _self()};
    }

    outcome<path_cap_style_nv> get_terminal_dash_cap() noexcept {
        return _ops::get_path_terminal_dash_cap(*this);
    }

    outcome<Derived&> dash_offset(GLfloat value) noexcept {
        return {_ops::path_dash_offset(*this, value), _self()};
    }

    outcome<GLfloat> get_dash_offset() const noexcept {
        return _ops::get_path_dash_offset(*this);
    }

    outcome<Derived&>
    dash_offset_reset(path_dash_offset_reset_nv value) noexcept {
        return {_ops::path_dash_offset_reset(*this, value), _self()};
    }

    outcome<path_dash_offset_reset_nv> get_dash_offset_reset() noexcept {
        return _ops::get_path_dash_offset_reset(*this);
    }

    outcome<Derived&> dash_array(span<const GLfloat> dshs) noexcept {
        return {_ops::path_dash_array(*this, dshs), _self()};
    }

    template <typename... T>
    outcome<Derived&> dashes(T... dshs) noexcept {
        const std::size_t N = sizeof...(T);
        const GLfloat da[N] = {GLfloat(dshs)...};
        return dash_array(da);
    }

    outcome<Derived&> copy_from(path_nv_name src_path) noexcept {
        return {_ops::copy_path(*this, src_path), _self()};
    }

    outcome<Derived&> interpolate_from(
      path_nv_name path_a, path_nv_name path_b, GLfloat weight) noexcept {
        return {_ops::interpolate_path(*this, path_a, path_b, weight), _self()};
    }

    outcome<Derived&> transform_from(
      path_nv_name src_path,
      path_transform_type_nv transform_type,
      span<const GLfloat> transform_values) noexcept {
        return {_ops::transform_path(
                  *this, src_path, transform_type, transform_values),
                _self()};
    }
};

template <>
struct obj_dsa_ops<tag::path_nv>
  : obj_member_ops<
      tag::path_nv,
      obj_dsa_ops<tag::path_nv>,
      obj_zero_dsa_ops<tag::path_nv>> {
    using obj_member_ops<
      tag::path_nv,
      obj_dsa_ops<tag::path_nv>,
      obj_zero_dsa_ops<tag::path_nv>>::obj_member_ops;
};

template <>
struct obj_gen_del_ops<tag::path_nv> {
    static deferred_error_handler _gen(span<GLuint> names) noexcept;

    static deferred_error_handler
    _gen(object_name_base_and_count_view<GLuint> names) noexcept;

    static deferred_error_handler _delete(span<GLuint> names) noexcept;

    static deferred_error_handler
    _delete(object_name_base_and_count_view<GLuint> names) noexcept;

    static outcome<boolean> _is_a(GLuint name) noexcept;
};

using path_nv = object_owner<tag::path_nv>;
template <std::size_t N>
using path_nv_array = object_array_owner<tag::path_nv, N>;
using path_nv_vector = object_vector_owner<tag::path_nv>;

static const object_zero_and_ops<tag::path_nv> no_path_nv = {};

} // namespace oglplus

#include <oglplus/path_nv.inl>

#endif // include guard
