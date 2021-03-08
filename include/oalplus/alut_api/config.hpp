/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALUT_API_CONFIG_HPP
#define OALPLUS_ALUT_API_CONFIG_HPP

#include "../al_api/config.hpp"
#include "../config/basic.hpp"
#include <eagine/maybe_unused.hpp>

#ifndef OALPLUS_HAS_ALUT
#if defined(ALUT_ERROR_NO_ERROR)
#define OALPLUS_HAS_ALUT 1
#else
#define OALPLUS_HAS_ALUT 0
#endif
#endif // OALPLUS_HAS_ALUT

#if !OALPLUS_HAS_ALUT
#include <cstdint>
#endif

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Collection of aliases for ALUT types.
/// @ingroup al_api_wrap
struct alut_types {

    /// @brief Boolean type.
    using bool_type = al_types::bool_type;

    /// @brief String character type.
    using char_type = al_types::char_type;

    /// @brief Enum type.
    using enum_type = al_types::enum_type;

    /// @brief Integer type.
    using int_type = al_types::int_type;

    /// @brief Unsigned integer type.
    using uint_type = al_types::uint_type;

    /// @brief AL object handle type.
    using name_type = al_types::name_type;

    /// @brief Integer type used to store sizes and counts.
    using size_type = al_types::size_type;

    /// @brief Floating-point type.
    using float_type = al_types::float_type;

    /// @brief Untyped pointer type.
    using void_ptr_type = al_types::void_ptr_type;

    /// @brief Untyped const pointer type.
    using const_void_ptr_type = al_types::const_void_ptr_type;
#if OALPLUS_HAS_ALUT
    static constexpr bool has_api = true;
#else
    static constexpr bool has_api = false;
#endif

    static constexpr auto bool_true(bool_type b) noexcept -> bool {
#if OALPLUS_HAS_ALUT
        return b == AL_TRUE;
#else
        return b;
#endif
    }

    static constexpr auto error_code_no_error(enum_type ec) noexcept -> bool {
#if OALPLUS_HAS_ALUT
        return ec == ALUT_ERROR_NO_ERROR;
#else
        EAGINE_MAYBE_UNUSED(ec);
        return false;
#endif
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALUT_API_CONFIG_HPP
