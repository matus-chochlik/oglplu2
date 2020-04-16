/**
 *  @file eagine/logging/config.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_LOGGING_CONFIG_HPP
#define EAGINE_LOGGING_CONFIG_HPP

#include "../int_constant.hpp"
#include "severity.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <log_event_severity severity>
using log_event_severity_constant =
  std::integral_constant<log_event_severity, severity>;
//------------------------------------------------------------------------------
// TODO switch with PP
using min_log_severity_t =
  log_event_severity_constant<log_event_severity::trace>;
//------------------------------------------------------------------------------
template <log_event_severity severity>
using is_log_level_enabled_t =
  bool_constant<(severity >= min_log_severity_t::value)>;

template <log_event_severity severity>
static constexpr const bool is_log_level_enabled_v =
  is_log_level_enabled_t<severity>::value;
//------------------------------------------------------------------------------
static constexpr inline bool is_log_level_enabled(
  log_event_severity severity) noexcept {
    return (severity >= min_log_severity_t::value);
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_CONFIG_HPP
