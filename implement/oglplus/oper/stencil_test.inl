/**
 *  @file oglplus/oper/stencil_test.inl
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
inline outcome<void>
stencil_test_state::stencil_func(
  compare_function func, GLint ref, GLuint mask) noexcept {
    OGLPLUS_GLFUNC(StencilFunc)(GLenum(func), ref, mask);
    OGLPLUS_VERIFY(StencilFunc, gl_enum_value(func), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
stencil_test_state::stencil_func_separate(
  single_face face, compare_function func, GLint ref, GLuint mask) noexcept {
    OGLPLUS_GLFUNC(StencilFuncSeparate)(GLenum(face), GLenum(func), ref, mask);
    OGLPLUS_VERIFY(StencilFuncSeparate, gl_enum_value(func), debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
stencil_test_state::stencil_op(
  stencil_operation sfail,
  stencil_operation dfail,
  stencil_operation dpass) noexcept {
    OGLPLUS_GLFUNC(StencilOp)(GLenum(sfail), GLenum(dfail), GLenum(dpass));
    OGLPLUS_VERIFY_SIMPLE(StencilOp, debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<void>
stencil_test_state::stencil_op_separate(
  single_face face,
  stencil_operation sfail,
  stencil_operation dfail,
  stencil_operation dpass) noexcept {
    OGLPLUS_GLFUNC(StencilOpSeparate)
    (GLenum(face), GLenum(sfail), GLenum(dfail), GLenum(dpass));
    OGLPLUS_VERIFY_SIMPLE(StencilOpSeparate, debug);
    return {};
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
