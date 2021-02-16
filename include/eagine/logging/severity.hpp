/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_LOGGING_SEVERITY_HPP
#define EAGINE_LOGGING_SEVERITY_HPP

#include "../reflect/enumerators.hpp"

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Log event severity enumeration.
/// @ingroup logging
enum class log_event_severity {
    /// @brief Backtracing log entries (the lowest severity).
    backtrace,
    /// @brief Trace log entries.
    trace,
    /// @brief Debug log entries.
    debug,
    /// @brief Statistic log entries.
    stat,
    /// @brief Informational log entries.
    info,
    /// @brief Warning log entries, indicating potential problems.
    warning,
    /// @brief Error log entries, indicating serious problems.
    error,
    /// @brief Fatal error log entries, indicating problem requiring termination.
    fatal
};

template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<log_event_severity>, Selector) noexcept {
    return enumerator_map_type<log_event_severity, 8>{
      {{"backtrace", log_event_severity::backtrace},
       {"trace", log_event_severity::trace},
       {"debug", log_event_severity::debug},
       {"stat", log_event_severity::stat},
       {"info", log_event_severity::info},
       {"warning", log_event_severity::warning},
       {"error", log_event_severity::error},
       {"fatal", log_event_severity::fatal}}};
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_SEVERITY_HPP
