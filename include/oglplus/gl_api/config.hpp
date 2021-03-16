/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
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

namespace eagine::oglp {
//------------------------------------------------------------------------------
/// @brief Collection of aliases for GL types.
/// @ingroup gl_api_wrap
struct gl_types {
#if OGLPLUS_HAS_GL
    static constexpr bool has_api = true;
#if defined(__GLEW_H__)
    static constexpr bool has_static_api = false;
#else
    static constexpr bool has_static_api = true;
#endif
    /// @brief Untyped pointer type.
    using void_ptr_type = GLvoid*;

    /// @brief Untyped const pointer type.
    using const_void_ptr_type = const GLvoid*;

    /// @brief String character type.
    using char_type = GLchar;

    /// @brief Boolean type.
    using bool_type = GLboolean;

    /// @brief Enumeration type.
    using enum_type = GLenum;

    /// @brief Bit-field type.
    using bitfield_type = GLbitfield;

    /// @brief Byte type.
    using byte_type = GLbyte;

    /// @brief Unsigned-byte type.
    using ubyte_type = GLubyte;

    /// @brief Signed short integer type.
    using short_type = GLshort;

    /// @brief Unsigned short integer type.
    using ushort_type = GLushort;

    /// @brief Signed integer type.
    using int_type = GLint;

    /// @brief Unsigned integer type.
    using uint_type = GLuint;

    /// @brief Signed 64-bit integer type.
    using int64_type = GLint64;

    /// @brief Unsigned 64-bit integer type.
    using uint64_type = GLuint64;

    /// @brief Floating-point type.
    using float_type = GLfloat;

    /// @brief Double-precision floating-point type.
    using double_type = GLdouble;

    /// @brief Signed integer size type.
    using sizei_type = GLsizei;

    /// @brief Signed integer size type.
    using sizeiptr_type = GLsizeiptr;

    /// @brief Signed integer size type.
    using intptr_type = GLintptr;

    /// @brief Sync handle type.
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
    using float_type = float;
    using double_type = double;
    using sizei_type = std::ptrdiff_t;
    using sizeiptr_type = std::intptr_t;
    using intptr_type = std::intptr_t;
    using sync_type = nothing_t;
#endif

    /// @brief Object handle type.
    using name_type = uint_type;

    /// @brief Converts bool_type value to native bool,
    static constexpr auto bool_true(bool_type b) noexcept -> bool {
#if OGLPLUS_HAS_GL
        return b == GL_TRUE;
#else
        return b;
#endif
    }

    /// @brief Tests if the specified error code represents no-error value.
    static constexpr auto error_code_no_error(enum_type ec) noexcept -> bool {
#if OGLPLUS_HAS_GL
        return ec == GL_NO_ERROR;
#else
        EAGINE_MAYBE_UNUSED(ec);
        return false;
#endif
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_CONFIG_HPP
