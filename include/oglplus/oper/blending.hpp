/**
 *  @file oglplus/oper/blending.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_BLENDING_HPP
#define OGLPLUS_OPER_BLENDING_HPP

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"

namespace oglplus {
namespace oper {

struct blending_state {
    static outcome<void> blend_equation(
      oglplus::blend_equation equation) noexcept;

#if defined(GL_VERSION_4_0)
    static outcome<void> blend_equation(
      GLuint buf, oglplus::blend_equation equation) noexcept;
#endif

    static outcome<void> blend_equation_separate(
      oglplus::blend_equation modeRGB,
      oglplus::blend_equation modeAlpha) noexcept;

#if defined(GL_VERSION_4_0)
    static outcome<void> blend_equation_separate(
      GLuint buf,
      oglplus::blend_equation modeRGB,
      oglplus::blend_equation modeAlpha) noexcept;
#endif

    static outcome<void> blend_func(
      blend_function sfactor, blend_function dfactor) noexcept;

    static outcome<void> blend_func_separate(
      blend_function srcRGB,
      blend_function dstRGB,
      blend_function srcAlpha,
      blend_function dstAlpha) noexcept;

#if defined(GL_VERSION_4_0)
    static outcome<void> blend_func(
      GLuint buf, blend_function sfactor, blend_function dfactor) noexcept;

    static outcome<void> blend_func_separate(
      GLuint buf,
      blend_function srcRGB,
      blend_function dstRGB,
      blend_function srcAlpha,
      blend_function dstAlpha) noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/blending.inl>

#endif // OGLPLUS_OPER_BLENDING_HPP
