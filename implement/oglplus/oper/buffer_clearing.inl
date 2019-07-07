/**
 *  @file oglplus/oper/buffer_clearing.inl
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
inline outcome<void> buffer_clearing_state::clear_color(
  GLfloat r, GLfloat g, GLfloat b, GLfloat a) noexcept {
    OGLPLUS_GLFUNC(ClearColor)(r, g, b, a);
    OGLPLUS_VERIFY_SIMPLE(ClearColor, always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> buffer_clearing_state::clear_depth(GLfloat d) noexcept {
    OGLPLUS_GLFUNC(ClearDepthf)(d);
    OGLPLUS_VERIFY_SIMPLE(ClearDepthf, always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void> buffer_clearing_state::clear_stencil(GLint s) noexcept {
    OGLPLUS_GLFUNC(ClearStencil)(s);
    OGLPLUS_VERIFY_SIMPLE(ClearStencil, always);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<rgba_value>
buffer_clearing_state::get_color_clear_value() noexcept {
    rgba_value result;
    OGLPLUS_GLFUNC(GetFloatv)
    (GL_COLOR_CLEAR_VALUE, static_cast<GLfloat*>(result._v));
    OGLPLUS_VERIFY_SIMPLE(GetFloatv, debug);
    return {result};
}
//------------------------------------------------------------------------------
inline outcome<GLfloat>
buffer_clearing_state::get_depth_clear_value() noexcept {
    auto result = GLfloat(0);
    OGLPLUS_GLFUNC(GetFloatv)(GL_DEPTH_CLEAR_VALUE, &result);
    OGLPLUS_VERIFY_SIMPLE(GetFloatv, debug);
    return {result};
}
//------------------------------------------------------------------------------
inline outcome<GLint>
buffer_clearing_state::get_stencil_clear_value() noexcept {
    auto result = GLint(0);
    OGLPLUS_GLFUNC(GetIntegerv)(GL_STENCIL_CLEAR_VALUE, &result);
    OGLPLUS_VERIFY_SIMPLE(GetIntegerv, debug);
    return {result};
}
//------------------------------------------------------------------------------
inline outcome<void> buffer_clearing_ops::clear(
  enum_bitfield<buffer_select_bits> bits) noexcept {
    OGLPLUS_GLFUNC(Clear)(GLbitfield(bits));
    OGLPLUS_VERIFY_SIMPLE(Clear, debug);
    return {};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
