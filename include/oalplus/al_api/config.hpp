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

#ifndef OALPLUS_HAS_AL
#if defined(AL_NO_ERROR)
#define OALPLUS_HAS_AL 1
#else
#define OALPLUS_HAS_AL 0
#endif
#endif // OALPLUS_HAS_AL

#if !OALPLUS_HAS_AL
#include <eagine/nothing.hpp>
#include <cstdint>
#endif

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct al_types {
#if OALPLUS_HAS_AL
    static constexpr bool has_api = true;
    using enum_type = ALenum;
    using char_type = ALchar;
    using bool_type = ALboolean;
    using int_type = ALint;
    using uint_type = ALuint;
    using name_type = ALuint;
    using size_type = ALsizei;
    using float_type = ALfloat;
    using double_type = ALdouble;
    using void_ptr_type = void*;
    using const_void_ptr_type = const void*;
#else
    static constexpr bool has_api = false;
    using enum_type = int;
    using char_type = char;
    using bool_type = bool;
    using int_type = int;
    using uint_type = unsigned;
    using name_type = unsigned;
    using size_type = std::intptr_t;
    using float_type = float;
    using double_type = double;
    using void_ptr_type = void*;
    using const_void_ptr_type = const void*;
#endif
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_CONFIG_HPP

