/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALUT_API_ENUM_TYPES_HPP
#define OALPLUS_ALUT_API_ENUM_TYPES_HPP

#include "enum_class.hpp"

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Typed enumeration for ALUT error code constants.
/// @ingroup al_api_wrap
/// @see al_error_code
/// @see alc_error_code
struct alut_error_code
  : alut_enum_class<alut_error_code, EAGINE_ID_V(ErrorCode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for ALUT waveform function constants.
/// @ingroup al_api_wrap
struct waveform_function
  : alut_enum_class<waveform_function, EAGINE_ID_V(WvefrmFunc)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALUT_API_ENUM_TYPES_HPP
