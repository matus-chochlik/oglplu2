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

#include "../config/basic.hpp"
#include "../int_constant.hpp"
#include "severity.hpp"

namespace eagine {
//------------------------------------------------------------------------------
#ifndef EAGINE_MIN_LOG_SEVERITY
#if EAGINE_LOW_PROFILE
#define EAGINE_MIN_LOG_SEVERITY warning
#else
#if EAGINE_DEBUG
#define EAGINE_MIN_LOG_SEVERITY trace
#else
#define EAGINE_MIN_LOG_SEVERITY stat
#endif
#endif
#endif
//------------------------------------------------------------------------------
template <log_event_severity severity>
using log_event_severity_constant =
  std::integral_constant<log_event_severity, severity>;
//------------------------------------------------------------------------------
using min_log_severity_t =
  log_event_severity_constant<log_event_severity::EAGINE_MIN_LOG_SEVERITY>;
//------------------------------------------------------------------------------
template <log_event_severity severity>
using is_log_level_enabled_t =
  bool_constant<(severity >= min_log_severity_t::value)>;

template <log_event_severity severity>
static constexpr const bool is_log_level_enabled_v =
  is_log_level_enabled_t<severity>::value;
//------------------------------------------------------------------------------
static constexpr auto is_log_level_enabled(log_event_severity severity) noexcept
  -> bool {
    return (severity >= min_log_severity_t::value);
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_CONFIG_HPP
