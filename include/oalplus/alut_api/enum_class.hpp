/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALUT_API_ENUM_CLASS_HPP
#define OALPLUS_ALUT_API_ENUM_CLASS_HPP

#include "config.hpp"
#include <eagine/enum_bitfield.hpp>
#include <eagine/enum_class.hpp>
#include <eagine/identifier.hpp>

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Typed wrapper class for ALUT enum constants/values.
/// @ingroup al_api_wrap
/// @see al_enum_class
/// @see alc_enum_class
///
/// This wrapper uses the specified Id to group various ALUT constants logically
/// belonging together and prevents accidental mismatches and use of ALUT
/// constants from unrelated groups.
template <typename Self, identifier_t Id>
using alut_enum_class =
  enum_class<Self, alut_types::enum_type, EAGINE_ID_V(ALUT), Id>;

/// @brief Type erasure alias for ALUT enum classes.
/// @ingroup al_api_wrap
using alut_any_enum_class = any_enum_class<EAGINE_ID_V(ALUT)>;

/// @brief Type erasure alias for ALUT enum values.
/// @ingroup al_api_wrap
using alut_any_enum_value = any_enum_value<EAGINE_ID_V(ALUT)>;

static constexpr auto
same_enum_class(alut_any_enum_class a, alut_any_enum_class b) noexcept -> bool {
    return ::eagine::same_enum_class(a, b);
}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALUT_API_ENUM_CLASS_HPP
