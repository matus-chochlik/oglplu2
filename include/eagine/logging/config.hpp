/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

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
/// @brief Type alias for log event severity constants.
/// @ingroup logging
template <log_event_severity severity>
using log_event_severity_constant =
  std::integral_constant<log_event_severity, severity>;
//------------------------------------------------------------------------------
/// @brief The minimal log severity constant.
/// @ingroup logging
using min_log_severity_t =
  log_event_severity_constant<log_event_severity::EAGINE_MIN_LOG_SEVERITY>;
//------------------------------------------------------------------------------
/// @brief Compile-time trait indicating if the specified log severity is enabled.
/// @ingroup logging
/// @see is_log_level_enabled_v
/// @see min_log_severity_t
template <log_event_severity severity>
using is_log_level_enabled_t =
  bool_constant<(severity >= min_log_severity_t::value)>;

/// @brief Compile-time trait indicating if the specified log severity is enabled.
/// @ingroup logging
/// @see is_log_level_enabled_t
template <log_event_severity severity>
static constexpr const bool is_log_level_enabled_v =
  is_log_level_enabled_t<severity>::value;
//------------------------------------------------------------------------------
/// @brief Function indicating if the specified log severity is enabled.
/// @ingroup logging
/// @see is_log_level_enabled_v
static constexpr auto is_log_level_enabled(log_event_severity severity) noexcept
  -> bool {
    return (severity >= min_log_severity_t::value);
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_CONFIG_HPP
