/**
 *  @file oglplus/oper/debugging.inl
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
#if defined(GL_VERSION_4_3)
inline outcome<void>
debugging::push_debug_group(
  debug_output_source source, GLuint id, cstring_span message) noexcept {
    OGLPLUS_GLFUNC(PushDebugGroup)
    (GLenum(source), id, GLsizei(message.size()), message.data());
    OGLPLUS_VERIFY(PushDebugGroup, gl_enum_value(source), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
debugging::pop_debug_group() noexcept {
    OGLPLUS_GLFUNC(PopDebugGroup)();
    OGLPLUS_VERIFY_SIMPLE(PopDebugGroup, debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
debugging::debug_message_control(
  debug_output_source source,
  debug_output_type type,
  debug_output_severity severity,
  span<const GLuint> ids,
  boolean enabled) noexcept {
    OGLPLUS_GLFUNC(DebugMessageControl)
    (GLenum(source),
     GLenum(type),
     GLenum(severity),
     GLsizei(ids.size()),
     ids.data(),
     GLboolean(enabled));
    OGLPLUS_VERIFY(DebugMessageControl, gl_enum_value(source), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
debugging::debug_message_insert(
  debug_output_source source,
  debug_output_type type,
  GLuint id,
  debug_output_severity severity,
  cstring_span message) noexcept {
    OGLPLUS_GLFUNC(DebugMessageInsert)
    (GLenum(source),
     GLenum(type),
     id,
     GLenum(severity),
     GLsizei(message.size()),
     message.data());
    OGLPLUS_VERIFY(DebugMessageInsert, gl_enum_value(source), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
debugging::debug_message_callback(
  GLDEBUGPROC callback, void* user_param) noexcept {
    OGLPLUS_GLFUNC(DebugMessageCallback)(callback, user_param);
    OGLPLUS_VERIFY_SIMPLE(DebugMessageCallback, debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
debugging::get_debug_message_log(
  GLuint count,
  span<debug_output_source> sources,
  span<debug_output_type> types,
  span<GLuint> ids,
  span<debug_output_severity> severities,
  span<GLsizei> lengths,
  span<GLchar> message_log) noexcept {
    assert(span_size_t(count) <= sources.size());
    assert(span_size_t(count) <= types.size());
    assert(span_size_t(count) <= ids.size());
    assert(span_size_t(count) <= severities.size());
    assert(span_size_t(count) <= lengths.size());

    std::vector<GLenum> dst_sources(count);
    std::vector<GLenum> dst_types(count);
    std::vector<GLenum> dst_severities(count);

    OGLPLUS_GLFUNC(GetDebugMessageLog)
    (count,
     GLsizei(message_log.size()),
     dst_sources.data(),
     dst_types.data(),
     ids.data(),
     dst_severities.data(),
     lengths.data(),
     message_log.data());
    OGLPLUS_VERIFY_SIMPLE(GetDebugMessageLog, debug);

    for(std::size_t i = 0; i < std::size_t(count); ++i) {
        sources[i] = debug_output_source(dst_sources[i]);
        types[i] = debug_output_type(dst_types[i]);
        severities[i] = debug_output_severity(dst_severities[i]);
    }
    return {};
}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
