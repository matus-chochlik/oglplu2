/**
 *  @file oglplus/oper/drawing.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <algorithm>
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_1)
inline outcome<void>
drawing_state::primitive_restart_index(GLuint index) noexcept {
    OGLPLUS_GLFUNC(PrimitiveRestartIndex)(index);
    OGLPLUS_VERIFY(PrimitiveRestartIndex, gl_index(index), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
inline outcome<void>
drawing_state::patch_parameter_i(
  oglplus::patch_parameter param, GLint value) noexcept {
    OGLPLUS_GLFUNC(PatchParameteri)(GLenum(param), value);
    OGLPLUS_VERIFY(PatchParameteri, gl_enum_value(param), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_state::patch_parameter(
  oglplus::patch_parameter param, span<const GLfloat> values) noexcept {
    OGLPLUS_GLFUNC(PatchParameterfv)(GLenum(param), values.data());
    OGLPLUS_VERIFY(PatchParameterfv, gl_enum_value(param), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_arrays(
  primitive_type mode, GLint first, GLsizei count) noexcept {
    OGLPLUS_GLFUNC(DrawArrays)(GLenum(mode), first, count);
    OGLPLUS_VERIFY(DrawArrays, gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0)
inline outcome<void>
drawing_ops::multi_draw_arrays(primitive_type mode,
  span<const GLint> first,
  span<const GLsizei> count) noexcept {
    OGLPLUS_GLFUNC(MultiDrawArrays)
    (GLenum(mode),
      first.data(),
      count.data(),
      GLsizei(std::min(first.size(), count.size())));
    OGLPLUS_VERIFY(MultiDrawArrays, gl_enum_value(mode), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_1)
inline outcome<void>
drawing_ops::draw_arrays_instanced(
  primitive_type mode, GLint first, GLsizei count, GLsizei primcount) noexcept {
    OGLPLUS_GLFUNC(DrawArraysInstanced)(GLenum(mode), first, count, primcount);
    OGLPLUS_VERIFY(DrawArraysInstanced, gl_enum_value(mode), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_2)
inline outcome<void>
drawing_ops::draw_arrays_instanced_base_instance(primitive_type mode,
  GLint first,
  GLsizei count,
  GLsizei primcount,
  GLuint baseinstance) noexcept {
    OGLPLUS_GLFUNC(DrawArraysInstancedBaseInstance)
    (GLenum(mode), first, count, primcount, baseinstance);
    OGLPLUS_VERIFY(DrawArraysInstancedBaseInstance, gl_enum_value(mode), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
inline outcome<void>
drawing_ops::draw_arrays_indirect(
  primitive_type mode, const GLvoid* indirect) noexcept {
    OGLPLUS_GLFUNC(DrawArraysIndirect)(GLenum(mode), indirect);
    OGLPLUS_VERIFY(DrawArraysIndirect, gl_enum_value(mode), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_elements(primitive_type mode,
  GLsizei count,
  index_type type,
  const GLvoid* indices) noexcept {
    OGLPLUS_GLFUNC(DrawElements)(GLenum(mode), count, GLenum(type), indices);
    OGLPLUS_VERIFY(DrawElements, gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_elements(
  primitive_type mode, GLsizei count, index_type type) noexcept {
    return draw_elements(mode, count, type, nullptr);
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0)
inline outcome<void>
drawing_ops::multi_draw_elements(primitive_type mode,
  span<const GLsizei> count,
  index_type type,
  span<const GLvoid*> indices) noexcept {
    OGLPLUS_GLFUNC(MultiDrawElements)
    (GLenum(mode),
      count.data(),
      GLenum(type),
      indices.data(),
      GLsizei(std::min(count.size(), indices.size())));
    OGLPLUS_VERIFY(MultiDrawElements, gl_enum_value(mode), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_range_elements(primitive_type mode,
  GLuint start,
  GLuint end,
  GLsizei count,
  index_type type,
  const GLvoid* indices) noexcept {
    OGLPLUS_GLFUNC(DrawRangeElements)
    (GLenum(mode), start, end, count, GLenum(type), indices);
    OGLPLUS_VERIFY(DrawRangeElements, gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_range_elements(primitive_type mode,
  GLuint start,
  GLuint end,
  GLsizei count,
  index_type type) noexcept {
    return draw_range_elements(mode, start, end, count, type, nullptr);
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_1)
inline outcome<void>
drawing_ops::draw_elements_instanced(primitive_type mode,
  GLsizei count,
  index_type type,
  const GLvoid* indices,
  GLsizei primcount) noexcept {
    OGLPLUS_GLFUNC(DrawElementsInstanced)
    (GLenum(mode), count, GLenum(type), indices, primcount);
    OGLPLUS_VERIFY(DrawElementsInstanced, gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_elements_instanced(primitive_type mode,
  GLsizei count,
  index_type type,
  GLsizei primcount) noexcept {
    return draw_elements_instanced(mode, count, type, nullptr, primcount);
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_2)
inline outcome<void>
drawing_ops::draw_elements_base_vertex(primitive_type mode,
  GLsizei count,
  index_type type,
  const GLvoid* indices,
  GLint basevertex) noexcept {
    OGLPLUS_GLFUNC(DrawElementsBaseVertex)
    (GLenum(mode), count, GLenum(type), indices, basevertex);
    OGLPLUS_VERIFY(DrawElementsBaseVertex, gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_elements_base_vertex(primitive_type mode,
  GLsizei count,
  index_type type,
  GLint basevertex) noexcept {
    return draw_elements_base_vertex(mode, count, type, nullptr, basevertex);
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::multi_draw_elements_base_vertex(primitive_type mode,
  span<const GLsizei> count,
  index_type type,
  span<const GLvoid*> indices,
  span<const GLint> basevertex) noexcept {
    OGLPLUS_GLFUNC(MultiDrawElementsBaseVertex)
    (GLenum(mode),
      count.data(),
      GLenum(type),
      indices.data(),
      GLsizei(
	std::min(std::min(count.size(), indices.size()), basevertex.size())),
      basevertex.data());
    OGLPLUS_VERIFY(MultiDrawElementsBaseVertex, gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_range_elements_base_vertex(primitive_type mode,
  GLuint start,
  GLuint end,
  GLsizei count,
  index_type type,
  const GLvoid* indices,
  GLint basevertex) noexcept {
    OGLPLUS_GLFUNC(DrawRangeElementsBaseVertex)
    (GLenum(mode), start, end, count, GLenum(type), indices, basevertex);
    OGLPLUS_VERIFY(DrawRangeElementsBaseVertex, gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_range_elements_base_vertex(primitive_type mode,
  GLuint start,
  GLuint end,
  GLsizei count,
  index_type type,
  GLint basevertex) noexcept {
    return draw_range_elements_base_vertex(
      mode, start, end, count, type, nullptr, basevertex);
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_elements_instanced_base_vertex(primitive_type mode,
  GLsizei count,
  index_type type,
  const GLvoid* indices,
  GLsizei primcount,
  GLint basevertex) noexcept {
    OGLPLUS_GLFUNC(DrawElementsInstancedBaseVertex)
    (GLenum(mode), count, GLenum(type), indices, primcount, basevertex);
    OGLPLUS_VERIFY(DrawElementsInstancedBaseVertex, gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_elements_instanced_base_vertex(primitive_type mode,
  GLsizei count,
  index_type type,
  GLsizei primcount,
  GLint basevertex) noexcept {
    return draw_elements_instanced_base_vertex(
      mode, count, type, nullptr, primcount, basevertex);
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_2)
inline outcome<void>
drawing_ops::draw_elements_instanced_base_instance(primitive_type mode,
  GLsizei count,
  index_type type,
  const GLvoid* indices,
  GLsizei primcount,
  GLuint baseinstance) noexcept {
    OGLPLUS_GLFUNC(DrawElementsInstancedBaseInstance)
    (GLenum(mode), count, GLenum(type), indices, primcount, baseinstance);
    OGLPLUS_VERIFY(
      DrawElementsInstancedBaseInstance, gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_elements_instanced_base_instance(primitive_type mode,
  GLsizei count,
  index_type type,
  GLsizei primcount,
  GLuint baseinstance) noexcept {
    return draw_elements_instanced_base_instance(
      mode, count, type, nullptr, primcount, baseinstance);
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_elements_instanced_base_vertex_base_instance(
  primitive_type mode,
  GLsizei count,
  index_type type,
  const GLvoid* indices,
  GLsizei primcount,
  GLint basevertex,
  GLuint baseinstance) noexcept {
    OGLPLUS_GLFUNC(DrawElementsInstancedBaseVertexBaseInstance)
    (GLenum(mode),
      count,
      GLenum(type),
      indices,
      primcount,
      basevertex,
      baseinstance);
    OGLPLUS_VERIFY(
      DrawElementsInstancedBaseVertexBaseInstance, gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_elements_instanced_base_vertex_base_instance(
  primitive_type mode,
  GLsizei count,
  index_type type,
  GLsizei primcount,
  GLint basevertex,
  GLuint baseinstance) noexcept {
    return draw_elements_instanced_base_vertex_base_instance(
      mode, count, type, nullptr, primcount, basevertex, baseinstance);
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
inline outcome<void>
drawing_ops::draw_elements_indirect(
  primitive_type mode, index_type type, const GLvoid* indirect) noexcept {
    OGLPLUS_GLFUNC(DrawElementsIndirect)(GLenum(mode), GLenum(type), indirect);
    OGLPLUS_VERIFY(DrawElementsIndirect, gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_transform_feedback(
  primitive_type mode, transform_feedback_name xfb) noexcept {
    OGLPLUS_GLFUNC(DrawTransformFeedback)(GLenum(mode), get_raw_name(xfb));
    OGLPLUS_VERIFY(
      DrawTransformFeedback, gl_object(xfb).gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_transform_feedback_stream(
  primitive_type mode, transform_feedback_name xfb, GLuint stream) noexcept {
    OGLPLUS_GLFUNC(DrawTransformFeedbackStream)
    (GLenum(mode), get_raw_name(xfb), stream);
    OGLPLUS_VERIFY(DrawTransformFeedbackStream,
      gl_object(xfb).gl_index(stream).gl_enum_value(mode),
      debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_2)
inline outcome<void>
drawing_ops::draw_transform_feedback_instanced(primitive_type mode,
  transform_feedback_name xfb,
  GLsizei primcount) noexcept {
    OGLPLUS_GLFUNC(DrawTransformFeedbackInstanced)
    (GLenum(mode), get_raw_name(xfb), primcount);
    OGLPLUS_VERIFY(
      DrawTransformFeedback, gl_object(xfb).gl_enum_value(mode), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
drawing_ops::draw_transform_feedback_stream_instanced(primitive_type mode,
  transform_feedback_name xfb,
  GLuint stream,
  GLsizei primcount) noexcept {
    OGLPLUS_GLFUNC(DrawTransformFeedbackStreamInstanced)
    (GLenum(mode), get_raw_name(xfb), stream, primcount);
    OGLPLUS_VERIFY(DrawTransformFeedbackStreamInstanced,
      gl_object(xfb).gl_index(stream).gl_enum_value(mode),
      debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
