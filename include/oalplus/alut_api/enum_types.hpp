/**
 *  @file oalplus/alut_api/enum_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_ENUM_TYPES_HPP
#define OALPLUS_ALUT_API_ENUM_TYPES_HPP

#include "config.hpp"
#include "enum_class.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct alut_error_code
  : alut_enum_class<
      alut_error_code,
      alut_types::enum_type,
      EAGINE_ID_V(ErrorCode)> {
    using enum_class::enum_class;
};

struct waveform_function
  : alut_enum_class<
      waveform_function,
      alut_types::enum_type,
      EAGINE_ID_V(WvefrmFunc)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALUT_API_ENUM_TYPES_HPP

