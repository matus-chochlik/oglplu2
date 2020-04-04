/**
 *  @file oglplus/shapes/drawing.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/null_ptr.hpp>
#include <oglplus/utils/gl_func.hpp>

namespace eagine {
namespace oglp {
namespace shapes {
//------------------------------------------------------------------------------
template <typename A>
primitive_type draw_operation::_translate(
  const basic_gl_api<A>& api, eagine::shapes::primitive_type mode) noexcept {
    const basic_gl_constants<A>& GL = api;
    switch(mode) {
        case eagine::shapes::primitive_type::points:
            return GL.points;
        case eagine::shapes::primitive_type::lines:
            return GL.lines;
        case eagine::shapes::primitive_type::quads:
            return GL.lines_adjacency;
        case eagine::shapes::primitive_type::tetrahedrons:
            return GL.lines_adjacency;
        case eagine::shapes::primitive_type::line_strip:
            return GL.line_strip;
        case eagine::shapes::primitive_type::line_loop:
            return GL.line_loop;
        case eagine::shapes::primitive_type::triangles:
            return GL.triangles;
        case eagine::shapes::primitive_type::triangle_strip:
            return GL.triangle_strip;
        case eagine::shapes::primitive_type::triangle_fan:
            return GL.triangle_fan;
        case eagine::shapes::primitive_type::patches:
            return GL.patches;
    }
    return GL.none;
}
//------------------------------------------------------------------------------
template <typename A>
data_type draw_operation::_translate(
  const basic_gl_api<A>& api, eagine::shapes::attrib_data_type type) noexcept {
    const basic_gl_constants<A>& GL = api;
    switch(type) {
        case eagine::shapes::attrib_data_type::float_:
            return GL.float_;
    }
    return GL.none;
}
//------------------------------------------------------------------------------
template <typename A>
data_type draw_operation::_translate(
  const basic_gl_api<A>& api, eagine::shapes::index_data_type type) noexcept {
    const basic_gl_constants<A>& GL = api;
    switch(type) {
        case eagine::shapes::index_data_type::unsigned_8:
            return GL.unsigned_byte_;
        case eagine::shapes::index_data_type::unsigned_16:
            return GL.unsigned_short_;
        case eagine::shapes::index_data_type::unsigned_32:
            return GL.unsigned_int_;
        case eagine::shapes::index_data_type::none:
            break;
    }
    return GL.none;
}
//------------------------------------------------------------------------------
span_size_t draw_operation::_byte_mult(
  eagine::shapes::index_data_type type) noexcept {
    switch(type) {
        case eagine::shapes::index_data_type::unsigned_8:
            return span_size(sizeof(gl_types::ubyte_type));
        case eagine::shapes::index_data_type::unsigned_16:
            return span_size(sizeof(gl_types::ushort_type));
        case eagine::shapes::index_data_type::unsigned_32:
            return span_size(sizeof(gl_types::uint_type));
        case eagine::shapes::index_data_type::none:
            break;
    }
    return 1;
}
//------------------------------------------------------------------------------
template <typename A>
draw_operation::draw_operation(
  const basic_gl_api<A>& api,
  const eagine::shapes::draw_operation& draw_op) noexcept
  : _mode(_translate(api, draw_op.mode))
  , _idx_type(_translate(api, draw_op.idx_type))
  , _first(GLint(draw_op.first * _byte_mult(draw_op.idx_type)))
  , _count(GLsizei(draw_op.count))
  , _phase(GLuint(draw_op.phase))
  , _primitive_restart_index(draw_op.primitive_restart_index)
  , _patch_vertices(draw_op.patch_vertices)
  , _primitive_restart(draw_op.primitive_restart)
  , _cw_face_winding(draw_op.cw_face_winding) {
}
//------------------------------------------------------------------------------
gl_types::const_void_ptr_type draw_operation::_idx_ptr() const noexcept {
    return eagine::memory::typed_nullptr<const gl_types::ubyte_type> + _first;
}
//------------------------------------------------------------------------------
template <typename A>
void draw_operation::draw(const basic_gl_api<A>& api) const noexcept {
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

    if(is_indexed(api)) {
        gl.draw_elements(_mode, _count, _idx_type, _idx_ptr());
    } else {
        gl.draw_arrays(_mode, _first, _count);
    }
}
//------------------------------------------------------------------------------
/*
outcome<void> draw_using_instructions(span<const draw_operation> ops) noexcept {
    for(const draw_operation& op : ops) {
        if(auto res = failure(op.draw())) {
            return std::move(res);
        }
    }
    return {};
}
*/
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace oglp
} // namespace eagine
//------------------------------------------------------------------------------
