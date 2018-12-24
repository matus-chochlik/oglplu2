/**
 *  @file oglplus/oper/capabilities.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/oper/numeric_queries.hpp>
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline outcome<void> capability_state::enable(capability cap) noexcept {
    OGLPLUS_GLFUNC(Enable)(GLenum(cap));
    OGLPLUS_VERIFY(Enable, gl_enum_value(cap), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> capability_state::disable(capability cap) noexcept {
    OGLPLUS_GLFUNC(Disable)(GLenum(cap));
    OGLPLUS_VERIFY(Disable, gl_enum_value(cap), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<boolean> capability_state::is_enabled(capability cap) noexcept {
    GLboolean result = OGLPLUS_GLFUNC(IsEnabled)(GLenum(cap));
    OGLPLUS_VERIFY(IsEnabled, gl_enum_value(cap), always);
    return {boolean(result)};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0)
inline outcome<void>
capability_state::enable(capability cap, GLuint index) noexcept {
    OGLPLUS_GLFUNC(Enablei)(GLenum(cap), index);
    OGLPLUS_VERIFY(Enablei, gl_enum_value(cap).gl_index(index), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
capability_state::disable(capability cap, GLuint index) noexcept {
    OGLPLUS_GLFUNC(Disablei)(GLenum(cap), index);
    OGLPLUS_VERIFY(Disablei, gl_enum_value(cap).gl_index(index), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<boolean>
capability_state::is_enabled(capability cap, GLuint index) noexcept {
    GLboolean result = OGLPLUS_GLFUNC(IsEnabledi)(GLenum(cap), index);
    OGLPLUS_VERIFY(IsEnabledi, gl_enum_value(cap).gl_index(index), always);
    return {boolean(result)};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_CLIP_DISTANCE0)
inline outcome<void> capability_state::enable(clip_plane cap) noexcept {
    OGLPLUS_GLFUNC(Enable)(GLenum(cap));
    OGLPLUS_VERIFY(Enable, gl_enum_value(cap), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> capability_state::disable(clip_plane cap) noexcept {
    OGLPLUS_GLFUNC(Disable)(GLenum(cap));
    OGLPLUS_VERIFY(Disable, gl_enum_value(cap), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<boolean> capability_state::is_enabled(clip_plane cap) noexcept {
    GLboolean result = OGLPLUS_GLFUNC(IsEnabled)(GLenum(cap));
    OGLPLUS_VERIFY(IsEnabled, gl_enum_value(cap), always);
    return {boolean(result)};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_ARB_compatibility)
inline outcome<void>
capability_state::enable_client_state(client_capability cap) noexcept {
    OGLPLUS_GLFUNC(EnableClientState)(GLenum(cap));
    OGLPLUS_VERIFY(EnableClientState, gl_enum_value(cap), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
capability_state::disable_client_state(client_capability cap) noexcept {
    OGLPLUS_GLFUNC(DisableClientState)(GLenum(cap));
    OGLPLUS_VERIFY(DisableClientState, gl_enum_value(cap), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<boolean>
capability_state::is_enabled(client_capability cap) noexcept {
    GLboolean result = OGLPLUS_GLFUNC(IsEnabled)(GLenum(cap));
    OGLPLUS_VERIFY(IsEnabled, gl_enum_value(cap), always);
    return {boolean(result)};
}
//------------------------------------------------------------------------------
inline outcome<GLint> capability_state::get_red_bits() noexcept {
    return numeric_queries::get_integer(numeric_query(GL_RED_BITS));
}
//------------------------------------------------------------------------------
inline outcome<GLint> capability_state::get_green_bits() noexcept {
    return numeric_queries::get_integer(numeric_query(GL_GREEN_BITS));
}
//------------------------------------------------------------------------------
inline outcome<GLint> capability_state::get_blue_bits() noexcept {
    return numeric_queries::get_integer(numeric_query(GL_BLUE_BITS));
}
//------------------------------------------------------------------------------
inline outcome<GLint> capability_state::get_alpha_bits() noexcept {
    return numeric_queries::get_integer(numeric_query(GL_ALPHA_BITS));
}
//------------------------------------------------------------------------------
inline outcome<GLint> capability_state::get_depth_bits() noexcept {
    return numeric_queries::get_integer(numeric_query(GL_DEPTH_BITS));
}
//------------------------------------------------------------------------------
inline outcome<GLint> capability_state::get_stencil_bits() noexcept {
    return numeric_queries::get_integer(numeric_query(GL_STENCIL_BITS));
}
//------------------------------------------------------------------------------
inline outcome<boolean> capability_state::has_doublebuffer() noexcept {
    return numeric_queries::get_boolean(numeric_query(GL_DOUBLEBUFFER));
}
//------------------------------------------------------------------------------
inline outcome<boolean> capability_state::is_stereo() noexcept {
    return numeric_queries::get_boolean(numeric_query(GL_STEREO));
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5)
inline outcome<graphics_reset_status> get_graphics_reset_status() noexcept {
    GLenum result = OGLPLUS_GLFUNC(GetGraphicsResetStatus)();
    OGLPLUS_VERIFY_SIMPLE(GetGraphicsResetStatus, always);
    return {graphics_reset_status(result)};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
