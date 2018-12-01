/**
 *  @file oglplus/oper/blending.inl
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
inline outcome<void>
blending_state::blend_equation(oglplus::blend_equation equation) noexcept {
    OGLPLUS_GLFUNC(BlendEquation)(GLenum(equation));
    OGLPLUS_VERIFY(BlendEquation, gl_enum_value(equation), debug);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
inline outcome<void>
blending_state::blend_equation(
  GLuint buf, oglplus::blend_equation equation) noexcept {
    OGLPLUS_GLFUNC(BlendEquationi)(buf, GLenum(equation));
    OGLPLUS_VERIFY(BlendEquation, gl_enum_value(equation).gl_index(buf), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
blending_state::blend_equation_separate(
  oglplus::blend_equation modeRGB, oglplus::blend_equation modeAlpha) noexcept {
    OGLPLUS_GLFUNC(BlendEquationSeparate)(GLenum(modeRGB), GLenum(modeAlpha));
    OGLPLUS_VERIFY(BlendEquationSeparate, gl_enum_value(modeRGB), debug);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
inline outcome<void>
blending_state::blend_equation_separate(
  GLuint buf,
  oglplus::blend_equation modeRGB,
  oglplus::blend_equation modeAlpha) noexcept {
    OGLPLUS_GLFUNC(BlendEquationSeparatei)
    (buf, GLenum(modeRGB), GLenum(modeAlpha));
    OGLPLUS_VERIFY(BlendEquation, gl_enum_value(modeRGB).gl_index(buf), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
blending_state::blend_func(
  blend_function sfactor, blend_function dfactor) noexcept {
    OGLPLUS_GLFUNC(BlendFunc)(GLenum(sfactor), GLenum(dfactor));
    OGLPLUS_VERIFY(BlendFunc, gl_enum_value(sfactor), debug);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
inline outcome<void>
blending_state::blend_func(
  GLuint buf, blend_function sfactor, blend_function dfactor) noexcept {
    OGLPLUS_GLFUNC(BlendFunci)(buf, GLenum(sfactor), GLenum(dfactor));
    OGLPLUS_VERIFY(BlendFunci, gl_enum_value(sfactor).gl_index(buf), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
inline outcome<void>
blending_state::blend_func_separate(
  blend_function srcRGB,
  blend_function dstRGB,
  blend_function srcAlpha,
  blend_function dstAlpha) noexcept {
    OGLPLUS_GLFUNC(BlendFuncSeparate)
    (GLenum(srcRGB), GLenum(dstRGB), GLenum(srcAlpha), GLenum(dstAlpha));
    OGLPLUS_VERIFY(BlendFuncSeparate, gl_enum_value(srcRGB), debug);
    return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
inline outcome<void>
blending_state::blend_func_separate(
  GLuint buf,
  blend_function srcRGB,
  blend_function dstRGB,
  blend_function srcAlpha,
  blend_function dstAlpha) noexcept {
    OGLPLUS_GLFUNC(BlendFuncSeparatei)
    (buf, GLenum(srcRGB), GLenum(dstRGB), GLenum(srcAlpha), GLenum(dstAlpha));
    OGLPLUS_VERIFY(
      BlendFuncSeparatei, gl_enum_value(srcRGB).gl_index(buf), debug);
    return {};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
