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

namespace oglplus {
namespace shapes {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
primitive_type draw_operation::_translate(
  eagine::shapes::primitive_type mode) noexcept {
    switch(mode) {
        case eagine::shapes::primitive_type::points:
            return primitive_type(GL_POINTS);
        case eagine::shapes::primitive_type::lines:
            return primitive_type(GL_LINES);
        case eagine::shapes::primitive_type::quads:
#if defined(GL_LINES_ADJACENCY)
            return primitive_type(GL_LINES_ADJACENCY);
#else
            break;
#endif
        case eagine::shapes::primitive_type::tetrahedrons:
#if defined(GL_LINES_ADJACENCY)
            return primitive_type(GL_LINES_ADJACENCY);
#else
            break;
#endif
        case eagine::shapes::primitive_type::line_strip:
            return primitive_type(GL_LINE_STRIP);
        case eagine::shapes::primitive_type::line_loop:
            return primitive_type(GL_LINE_LOOP);
        case eagine::shapes::primitive_type::triangles:
            return primitive_type(GL_TRIANGLES);
        case eagine::shapes::primitive_type::triangle_strip:
            return primitive_type(GL_TRIANGLE_STRIP);
        case eagine::shapes::primitive_type::triangle_fan:
            return primitive_type(GL_TRIANGLE_FAN);
        case eagine::shapes::primitive_type::patches:
#if defined(GL_PATCHES)
            return primitive_type(GL_PATCHES);
#else
            break;
#endif
    }
    return primitive_type(GL_NONE);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
data_type draw_operation::_translate(
  eagine::shapes::index_data_type type) noexcept {
    switch(type) {
        case eagine::shapes::index_data_type::unsigned_8:
            return data_type(GL_UNSIGNED_BYTE);
        case eagine::shapes::index_data_type::unsigned_16:
            return data_type(GL_UNSIGNED_SHORT);
        case eagine::shapes::index_data_type::unsigned_32:
            return data_type(GL_UNSIGNED_INT);
        case eagine::shapes::index_data_type::none:
            break;
    }
    return data_type(GL_NONE);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t draw_operation::_byte_mult(
  eagine::shapes::index_data_type type) noexcept {
    switch(type) {
        case eagine::shapes::index_data_type::unsigned_8:
            return span_size(sizeof(GLubyte));
        case eagine::shapes::index_data_type::unsigned_16:
            return span_size(sizeof(GLushort));
        case eagine::shapes::index_data_type::unsigned_32:
            return span_size(sizeof(GLuint));
        case eagine::shapes::index_data_type::none:
            break;
    }
    return 1;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
draw_operation::draw_operation(
  const eagine::shapes::draw_operation& draw_op) noexcept
  : _mode(_translate(draw_op.mode))
  , _idx_type(_translate(draw_op.idx_type))
  , _first(GLint(draw_op.first * _byte_mult(draw_op.idx_type)))
  , _count(GLsizei(draw_op.count))
  , _phase(GLuint(draw_op.phase))
  , _primitive_restart_index(draw_op.primitive_restart_index)
  , _patch_vertices(draw_op.patch_vertices)
  , _primitive_restart(draw_op.primitive_restart)
  , _cw_face_winding(draw_op.cw_face_winding) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool draw_operation::indexed() const noexcept {
    return GLenum(_idx_type) != GL_NONE;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
const void* draw_operation::_idx_ptr() const noexcept {
    return eagine::memory::typed_nullptr<const GLubyte> + _first;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
outcome<void> draw_operation::draw() const noexcept {
    OGLPLUS_GLFUNC(FrontFace)(_cw_face_winding ? GL_CW : GL_CCW);

#if defined(GL_PRIMITIVE_RESTART)
    if(_primitive_restart) {
        OGLPLUS_GLFUNC(Enable)(GL_PRIMITIVE_RESTART);
        OGLPLUS_GLFUNC(PrimitiveRestartIndex)(_primitive_restart_index);
    } else {
        OGLPLUS_GLFUNC(Disable)(GL_PRIMITIVE_RESTART);
    }
#endif
#if defined(GL_PATCHES)
    if(_mode == primitive_type(GL_PATCHES)) {
        OGLPLUS_GLFUNC(PatchParameteri)(GL_PATCH_VERTICES, _patch_vertices);
    }
#endif

    if(indexed()) {
        OGLPLUS_GLFUNC(DrawElements)
        (GLenum(_mode), GLsizei(_count), GLenum(_idx_type), _idx_ptr());
        OGLPLUS_VERIFY(DrawElements, gl_enum_value(_mode), debug);
    } else {
        OGLPLUS_GLFUNC(DrawArrays)
        (GLenum(_mode), GLint(_first), GLsizei(_count));
        OGLPLUS_VERIFY(DrawArrays, gl_enum_value(_mode), debug);
    }
    return {};
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
outcome<void> draw_using_instructions(span<const draw_operation> ops) noexcept {
    for(const draw_operation& op : ops) {
        if(auto res = failure(op.draw())) {
            return std::move(res);
        }
    }
    return {};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace oglplus
//------------------------------------------------------------------------------
