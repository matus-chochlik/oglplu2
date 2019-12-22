/**
 *  @file oalplus/alc_api/config.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_CONFIG_HPP
#define OALPLUS_ALC_API_CONFIG_HPP

#include "../config/basic.hpp"

#ifndef OALPLUS_HAS_ALC
#if defined(ALC_NO_ERROR)
#define OALPLUS_HAS_ALC 1
#else
#define OALPLUS_HAS_ALC 0
#endif
#endif // OALPLUS_HAS_ALC

#if !OALPLUS_HAS_ALC
#include <eagine/nothing.hpp>
#include <cstdint>
#endif

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct alc_types {
    using void_ptr_type = void*;
#if OALPLUS_HAS_ALC
    static constexpr bool has_api = true;
    using device_type = ALCdevice;
    using context_type = ALCcontext;
    using enum_type = ALCenum;
    using char_type = ALCchar;
    using bool_type = ALCboolean;
    using int_type = ALCint;
    using uint_type = ALCuint;
    using size_type = ALCsizei;
#else
    static constexpr bool has_api = false;
    using device_type = nothing_t;
    using context_type = nothing_t;
    using enum_type = int;
    using char_type = char;
    using bool_type = bool;
    using int_type = int;
    using uint_type = unsigned;
    using size_type = std::intptr_t;
#endif
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_CONFIG_HPP

