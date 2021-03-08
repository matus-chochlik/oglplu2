/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALC_API_ENUM_CLASS_HPP
#define OALPLUS_ALC_API_ENUM_CLASS_HPP

#include "config.hpp"
#include <eagine/enum_bitfield.hpp>
#include <eagine/enum_class.hpp>
#include <eagine/identifier.hpp>

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Typed wrapper class for ALC enum constants/values.
/// @ingroup al_api_wrap
/// @see al_enum_class
/// @see alut_enum_class
///
/// This wrapper uses the specified Id to group various ALC constants logically
/// belonging together and prevents accidental mismatches and use of ALC constants
/// from unrelated groups. For example using a context attribute constant in place
/// of string query constants. Such mismatches result in compilation errors.
template <typename Self, identifier_t Id>
using alc_enum_class =
  enum_class<Self, alc_types::enum_type, EAGINE_ID_V(ALC), Id>;

/// @brief Type erasure alias for ALC enum classes.
/// @ingroup al_api_wrap
using alc_any_enum_class = any_enum_class<EAGINE_ID_V(ALC)>;

/// @brief Type erasure alias for ALC enum values.
/// @ingroup al_api_wrap
using alc_any_enum_value = any_enum_value<EAGINE_ID_V(ALC)>;

static constexpr auto
same_enum_class(alc_any_enum_class a, alc_any_enum_class b) noexcept -> bool {
    return ::eagine::same_enum_class(a, b);
}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALC_API_ENUM_CLASS_HPP
