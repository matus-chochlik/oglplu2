/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALC_API_ENUM_TYPES_HPP
#define OALPLUS_ALC_API_ENUM_TYPES_HPP

#include "enum_class.hpp"

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Typed enumeration for ALC error code constants.
/// @ingroup al_api_wrap
/// @see al_error_code
/// @see alut_error_code
struct alc_error_code : alc_enum_class<alc_error_code, EAGINE_ID_V(ErrorCode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ALC context attribute constants.
/// @ingroup al_api_wrap
struct context_attribute
  : alc_enum_class<context_attribute, EAGINE_ID_V(CntxtAttr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ALC string query constants.
/// @ingroup al_api_wrap
struct alc_string_query
  : alc_enum_class<alc_string_query, EAGINE_ID_V(StrQuery)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ALC integer query constants.
/// @ingroup al_api_wrap
struct alc_integer_query
  : alc_enum_class<alc_integer_query, EAGINE_ID_V(IntQuery)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALC_API_ENUM_TYPES_HPP
