/**
 *  @file oglplus/gl_api/config.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_CONFIG_HPP
#define OGLPLUS_GL_API_CONFIG_HPP

#include "../config/basic.hpp"
#include <eagine/maybe_unused.hpp>

#ifndef OGLPLUS_HAS_GL
#if defined(GL_NO_ERROR)
#define OGLPLUS_HAS_GL 1
#else
#define OGLPLUS_HAS_GL 0
#endif
#endif // OGLPLUS_HAS_GL

#if !OGLPLUS_HAS_GL
#include <eagine/nothing.hpp>
#include <cstdint>
#endif

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
struct gl_types {
#if OGLPLUS_HAS_GL
    static constexpr bool has_api = true;
#if defined(__GLEW_H__)
    static constexpr bool has_static_api = false;
#else
    static constexpr bool has_static_api = true;
#endif
    using void_ptr_type = GLvoid*;
    using const_void_ptr_type = const GLvoid*;
    using char_type = GLchar;
    using bool_type = GLboolean;
    using enum_type = GLenum;
    using bitfield_type = GLbitfield;
    using byte_type = GLbyte;
    using ubyte_type = GLubyte;
    using short_type = GLshort;
    using ushort_type = GLushort;
    using int_type = GLint;
    using uint_type = GLuint;
    using int64_type = GLint64;
    using uint64_type = GLuint64;
    using fixed_type = GLfixed;
    using float_type = GLfloat;
    using double_type = GLdouble;
    using sizei_type = GLsizei;
    using sizeiptr_type = GLsizeiptr;
    using intptr_type = GLintptr;
    using sync_type = GLsync;
#else
    static constexpr bool has_api = false;
    static constexpr bool has_static_api = true;
    using void_ptr_type = void*;
    using const_void_ptr_type = const void*;
    using char_type = char;
    using bool_type = bool;
    using enum_type = unsigned;
    using bitfield_type = unsigned;
    using byte_type = std::int8_t;
    using ubyte_type = std::uint8_t;
    using short_type = std::int16_t;
    using ushort_type = std::uint16_t;
    using int_type = int;
    using uint_type = unsigned;
    using int64_type = std::int64_t;
    using uint64_type = std::uint64_t;
    using fixed_type = std::int32_t;
    using float_type = float;
    using double_type = double;
    using sizei_type = std::ptrdiff_t;
    using sizeiptr_type = std::intptr_t;
    using intptr_type = std::intptr_t;
    using sync_type = nothing_t;
#endif

    static constexpr bool bool_true(bool_type b) noexcept {
#if OGLPLUS_HAS_GL
        return b == GL_TRUE;
#else
        return b;
#endif
    }

    static constexpr bool error_code_no_error(enum_type ec) noexcept {
#if OGLPLUS_HAS_GL
        return ec == GL_NO_ERROR;
#else
        EAGINE_MAYBE_UNUSED(ec);
        return false;
#endif
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_CONFIG_HPP

