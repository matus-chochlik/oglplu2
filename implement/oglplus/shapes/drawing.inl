/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/memory/null_ptr.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
template <typename A>
inline auto
translate(const basic_gl_api<A>& api, shapes::primitive_type mode) noexcept
  -> primitive_type {
    auto& GL = api.constants();

    switch(mode) {
        case shapes::primitive_type::points:
            return GL.points;
        case shapes::primitive_type::lines:
            return GL.lines;
        case shapes::primitive_type::quads:
            return GL.lines_adjacency;
        case shapes::primitive_type::tetrahedrons:
            return GL.lines_adjacency;
        case shapes::primitive_type::line_strip:
            return GL.line_strip;
        case shapes::primitive_type::line_loop:
            return GL.line_loop;
        case shapes::primitive_type::triangles:
            return GL.triangles;
        case shapes::primitive_type::triangle_strip:
            return GL.triangle_strip;
        case shapes::primitive_type::triangle_fan:
            return GL.triangle_fan;
        case shapes::primitive_type::triangles_adjacency:
            return GL.triangles_adjacency;
        case shapes::primitive_type::patches:
            return GL.patches;
    }
    return GL.points;
}
//------------------------------------------------------------------------------
template <typename A>
inline auto
translate(const basic_gl_api<A>& api, shapes::attrib_data_type type) noexcept
  -> data_type {
    auto& GL = api.constants();

    switch(type) {
        case shapes::attrib_data_type::ubyte:
            return GL.unsigned_byte_;
        case shapes::attrib_data_type::int_16:
            return GL.short_;
        case shapes::attrib_data_type::int_32:
            return GL.int_;
        case shapes::attrib_data_type::uint_16:
            return GL.unsigned_short_;
        case shapes::attrib_data_type::uint_32:
            return GL.unsigned_int_;
        case shapes::attrib_data_type::float_:
            return GL.float_;
        case shapes::attrib_data_type::none:
            break;
    }
    return GL.float_;
}
//------------------------------------------------------------------------------
template <typename A>
inline auto
translate(const basic_gl_api<A>& api, shapes::index_data_type type) noexcept
  -> index_data_type {
    auto& GL = api.constants();

    switch(type) {
        case shapes::index_data_type::unsigned_8:
            return GL.unsigned_byte_;
        case shapes::index_data_type::unsigned_16:
            return GL.unsigned_short_;
        case shapes::index_data_type::unsigned_32:
            return GL.unsigned_int_;
        case shapes::index_data_type::none:
            break;
    }
    return GL.none;
}
//------------------------------------------------------------------------------
inline auto type_size(shapes::attrib_data_type type) noexcept -> span_size_t {
    switch(type) {
        case shapes::attrib_data_type::ubyte:
            return span_size(sizeof(gl_types::ubyte_type));
        case shapes::attrib_data_type::int_16:
            return span_size(sizeof(gl_types::short_type));
        case shapes::attrib_data_type::int_32:
            return span_size(sizeof(gl_types::int_type));
        case shapes::attrib_data_type::uint_16:
            return span_size(sizeof(gl_types::ushort_type));
        case shapes::attrib_data_type::uint_32:
            return span_size(sizeof(gl_types::uint_type));
        case shapes::attrib_data_type::float_:
            return span_size(sizeof(gl_types::float_type));
        case shapes::attrib_data_type::none:
            break;
    }
    return 1;
}
//------------------------------------------------------------------------------
inline auto type_size(shapes::index_data_type type) noexcept -> span_size_t {
    switch(type) {
        case shapes::index_data_type::unsigned_8:
            return span_size(sizeof(gl_types::ubyte_type));
        case shapes::index_data_type::unsigned_16:
            return span_size(sizeof(gl_types::ushort_type));
        case shapes::index_data_type::unsigned_32:
            return span_size(sizeof(gl_types::uint_type));
        case shapes::index_data_type::none:
            break;
    }
    return 1;
}
//------------------------------------------------------------------------------
template <typename A>
inline shape_draw_operation::shape_draw_operation(
  const basic_gl_api<A>& api,
  const shapes::draw_operation& draw_op) noexcept
  : _mode(translate(api, draw_op.mode))
  , _idx_type(translate(api, draw_op.idx_type))
  , _first(gl_types::int_type(draw_op.first * type_size(draw_op.idx_type)))
  , _count(gl_types::sizei_type(draw_op.count))
  , _phase(gl_types::uint_type(draw_op.phase))
  , _primitive_restart_index(draw_op.primitive_restart_index)
  , _patch_vertices(draw_op.patch_vertices)
  , _primitive_restart(draw_op.primitive_restart)
  , _cw_face_winding(draw_op.cw_face_winding) {}
//------------------------------------------------------------------------------
inline auto shape_draw_operation::_idx_ptr() const noexcept
  -> gl_types::const_void_ptr_type {
    return eagine::memory::typed_nullptr<const gl_types::ubyte_type> + _first;
}
//------------------------------------------------------------------------------
template <typename A>
inline void
shape_draw_operation::_prepare(const basic_gl_api<A>& api) const noexcept {
    auto& [gl, GL] = api;

    if(_cw_face_winding) {
        gl.front_face(GL.cw);
    } else {
        gl.front_face(GL.ccw);
    }

    if(GL.primitive_restart) {
        if(_primitive_restart) {
            gl.enable(GL.primitive_restart);
            gl.primitive_restart_index(_primitive_restart_index);
        } else {
            gl.disable(GL.primitive_restart);
        }
    }

    if(GL.patches) {
        if(_mode == GL.patches) {
            gl.patch_parameter_i(GL.patch_vertices, _patch_vertices);
        }
    }
}
//------------------------------------------------------------------------------
template <typename A>
inline void
shape_draw_operation::draw(const basic_gl_api<A>& api) const noexcept {
    _prepare(api);
    auto& [gl, GL] = api;

    if(is_indexed(api)) {
        gl.draw_elements(_mode, _count, _idx_type, _idx_ptr());
    } else {
        gl.draw_arrays(_mode, _first, _count);
    }
}
//------------------------------------------------------------------------------
template <typename A>
inline void shape_draw_operation::draw_instanced(
  const basic_gl_api<A>& api,
  gl_types::sizei_type inst_count) const noexcept {
    _prepare(api);
    auto& [gl, GL] = api;

    if(is_indexed(api)) {
        gl.draw_elements_instanced(
          _mode, _count, _idx_type, _idx_ptr(), inst_count);
    } else {
        gl.draw_arrays_instanced(_mode, _first, _count, inst_count);
    }
}
//------------------------------------------------------------------------------
template <typename A>
inline void draw_using_instructions(
  const basic_gl_api<A>& api,
  span<const shape_draw_operation> ops) noexcept {
    for(const auto& op : ops) {
        op.draw(api);
    }
}
//------------------------------------------------------------------------------
template <typename A>
inline void draw_instanced_using_instructions(
  const basic_gl_api<A>& api,
  span<const shape_draw_operation> ops,
  gl_types::sizei_type inst_count) noexcept {
    for(const auto& op : ops) {
        op.draw_instanced(api, inst_count);
    }
}
//------------------------------------------------------------------------------
template <typename A>
inline void draw_using_instructions(
  const basic_gl_api<A>& api,
  span<const shape_draw_operation> ops,
  const shape_draw_subset& subs) noexcept {
    for(span_size_t i = subs.first; i < subs.first + subs.count; ++i) {
        if(i < ops.size()) {
            ops[i].draw(api);
        }
    }
}
//------------------------------------------------------------------------------
template <typename A>
inline void draw_using_instructions(
  const basic_gl_api<A>& api,
  span<const shape_draw_operation> ops,
  const shape_draw_subset& subs,
  gl_types::sizei_type inst_count) noexcept {
    for(span_size_t i = subs.first; i < subs.first + subs.count; ++i) {
        if(i < ops.size()) {
            ops[i].draw_instanced(api, inst_count);
        }
    }
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp
//------------------------------------------------------------------------------
