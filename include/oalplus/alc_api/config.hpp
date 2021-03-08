/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALC_API_CONFIG_HPP
#define OALPLUS_ALC_API_CONFIG_HPP

#include "../config/basic.hpp"
#include <eagine/maybe_unused.hpp>

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

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Collection of aliases for ALC types.
/// @ingroup al_api_wrap
struct alc_types {
    /// @brief Untyped pointer type.
    using void_ptr_type = void*;
#if OALPLUS_HAS_ALC
    static constexpr bool has_api = true;

    /// @brief Device handle type.
    using device_type = ALCdevice;

    /// @brief Audio context type.
    using context_type = ALCcontext;

    /// @brief Enumeration type.
    using enum_type = ALCenum;

    /// @brief String character type.
    using char_type = ALCchar;

    /// @brief Boolean type.
    using bool_type = ALCboolean;

    /// @brief Integer type.
    using int_type = ALCint;

    /// @brief Unsigned integer type.
    using uint_type = ALCuint;

    /// @brief Integer type used to store sizes and counts.
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

    static constexpr auto bool_true(bool_type b) noexcept -> bool {
#if OALPLUS_HAS_ALC
        return b == ALC_TRUE;
#else
        return b;
#endif
    }

    static constexpr auto error_code_no_error(enum_type ec) noexcept -> bool {
#if OALPLUS_HAS_ALC
        return ec == ALC_NO_ERROR;
#else
        EAGINE_MAYBE_UNUSED(ec);
        return false;
#endif
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALC_API_CONFIG_HPP
