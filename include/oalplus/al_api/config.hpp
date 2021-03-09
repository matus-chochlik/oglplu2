/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_AL_API_CONFIG_HPP
#define OALPLUS_AL_API_CONFIG_HPP

#include "../config/basic.hpp"
#include <eagine/maybe_unused.hpp>

#ifndef OALPLUS_HAS_AL
#if defined(AL_NO_ERROR)
#define OALPLUS_HAS_AL 1
#else
#define OALPLUS_HAS_AL 0
#endif
#endif // OALPLUS_HAS_AL

#if !OALPLUS_HAS_AL
#include <cstdint>
#endif

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Collection of aliases for AL types.
/// @ingroup al_api_wrap
struct al_types {
    /// @brief Untyped pointer type.
    using void_ptr_type = void*;

    /// @brief Untyped const pointer type.
    using const_void_ptr_type = const void*;
#if OALPLUS_HAS_AL
    static constexpr bool has_api = true;

    /// @brief Enumeration type.
    using enum_type = ALenum;

    /// @brief String character type.
    using char_type = ALchar;

    /// @brief Boolean type.
    using bool_type = ALboolean;

    /// @brief Byte type.
    using byte_type = ALbyte;

    /// @brief Unsigned byte type.
    using ubyte_type = ALubyte;

    /// @brief Short integer type.
    using short_type = ALshort;

    /// @brief Unsigned short integer type.
    using ushort_type = ALushort;

    /// @brief Integer type.
    using int_type = ALint;

    /// @brief Signed integer type.
    using uint_type = ALuint;

    /// @brief AL object handle type.
    using name_type = ALuint;

    /// @brief Integer type used to store sizes and counts.
    using size_type = ALsizei;

    ///  @brief Floating-point type.
    using float_type = ALfloat;

    ///  @brief Double-precision floating-point type.
    using double_type = ALdouble;
#else
    static constexpr bool has_api = false;
    using enum_type = int;
    using char_type = char;
    using bool_type = bool;
    using byte_type = char;
    using ubyte_type = unsigned char;
    using short_type = short;
    using ushort_type = unsigned short;
    using int_type = int;
    using uint_type = unsigned;
    using name_type = unsigned;
    using size_type = std::intptr_t;
    using float_type = float;
    using double_type = double;
#endif

    static constexpr auto bool_true(bool_type b) noexcept -> bool {
#if OALPLUS_HAS_AL
        return b == AL_TRUE;
#else
        return b;
#endif
    }

    static constexpr auto error_code_no_error(enum_type ec) noexcept -> bool {
#if OALPLUS_HAS_AL
        return ec == AL_NO_ERROR;
#else
        EAGINE_MAYBE_UNUSED(ec);
        return false;
#endif
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_AL_API_CONFIG_HPP
