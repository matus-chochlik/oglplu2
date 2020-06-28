/**
 *  @file oalplus/al_api/config.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
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

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct al_types {
    using void_ptr_type = void*;
    using const_void_ptr_type = const void*;
#if OALPLUS_HAS_AL
    static constexpr bool has_api = true;
    using enum_type = ALenum;
    using char_type = ALchar;
    using bool_type = ALboolean;
    using byte_type = ALbyte;
    using ubyte_type = ALubyte;
    using short_type = ALshort;
    using ushort_type = ALushort;
    using int_type = ALint;
    using uint_type = ALuint;
    using name_type = ALuint;
    using size_type = ALsizei;
    using float_type = ALfloat;
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

    static constexpr bool bool_true(bool_type b) noexcept {
#if OALPLUS_HAS_AL
        return b == AL_TRUE;
#else
        return b;
#endif
    }

    static constexpr bool error_code_no_error(enum_type ec) noexcept {
#if OALPLUS_HAS_AL
        return ec == AL_NO_ERROR;
#else
        EAGINE_MAYBE_UNUSED(ec);
        return false;
#endif
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_CONFIG_HPP

