/**
 *  @file eagine/logging/logger.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_LOGGING_LOGGER_HPP
#define EAGINE_LOGGING_LOGGER_HPP

#include "config.hpp"
#include "entry.hpp"

namespace eagine {
//------------------------------------------------------------------------------
class logger {
public:
    template <log_event_severity severity>
    using entry = std::
      conditional_t<is_log_level_enabled_v<severity>, log_entry, no_log_entry>;

    auto log(
      identifier source,
      log_event_severity severity,
      std::true_type,
      string_view format) noexcept -> log_entry {
        return {
          source,
          reinterpret_cast<logger_instance_id>(this),
          severity,
          format,
          _entry_backend(source, severity)};
    }

    constexpr auto
    log(identifier, log_event_severity, std::false_type, string_view) noexcept
      -> no_log_entry {
        return {};
    }

    template <log_event_severity severity>
    constexpr auto log(
      identifier source,
      log_event_severity_constant<severity>,
      string_view format) noexcept -> entry<severity> {
        return log(
          source, severity, is_log_level_enabled_t<severity>{}, format);
    }

    template <log_event_severity severity>
    auto log(
      log_event_severity_constant<severity> level,
      string_view format) noexcept -> entry<severity> {
        return log(_logger_id, level, format);
    }

    auto log(
      identifier source,
      log_event_severity severity,
      string_view format) noexcept -> log_entry {
        return {
          source,
          reinterpret_cast<logger_instance_id>(this),
          severity,
          format,
          _entry_backend(source, severity)};
    }

    auto log(log_event_severity severity, string_view format) noexcept {
        return log(_logger_id, severity, format);
    }

    auto fatal(string_view format) noexcept {
        return log(
          log_event_severity_constant<log_event_severity::fatal>{}, format);
    }

    auto error(string_view format) noexcept {
        return log(
          log_event_severity_constant<log_event_severity::error>{}, format);
    }

    auto warning(string_view format) noexcept {
        return log(
          log_event_severity_constant<log_event_severity::warning>{}, format);
    }

    auto info(string_view format) noexcept {
        return log(
          log_event_severity_constant<log_event_severity::info>{}, format);
    }

    auto stat(string_view format) noexcept {
        return log(
          log_event_severity_constant<log_event_severity::stat>{}, format);
    }

    auto debug(string_view format) noexcept {
        return log(
          log_event_severity_constant<log_event_severity::debug>{}, format);
    }

    auto trace(string_view format) noexcept {
        return log(
          log_event_severity_constant<log_event_severity::trace>{}, format);
    }

    auto backtrace(string_view format) noexcept {
        return log(
          log_event_severity_constant<log_event_severity::backtrace>{}, format);
    }

    auto lifetime(string_view format) noexcept {
        // TODO: switch depending on Debug/Release ?
        return info(format);
    }

    auto log_stream(identifier source, log_event_severity severity) noexcept
      -> stream_log_entry {
        return {
          source,
          reinterpret_cast<logger_instance_id>(this),
          severity,
          _entry_backend(source, severity)};
    }

    auto log_stream(log_event_severity severity) noexcept {
        return log_stream(_logger_id, severity);
    }

    auto error_stream() noexcept {
        return log_stream(log_event_severity::error);
    }

    logger() noexcept = default;

    logger(identifier logger_id, logger& parent) noexcept
      : _logger_id{logger_id}
      , _backend{parent._backend} {
        lifetime("created as a child of ${parent}")
          .arg(EAGINE_ID(parent), EAGINE_ID(LogId), parent._logger_id)
          .arg(EAGINE_ID(self), EAGINE_ID(LogId), _logger_id);
    }

    logger(logger&& temp) noexcept
      : _logger_id{temp._logger_id}
      , _backend{std::move(temp._backend)} {
        lifetime("being moved");
    }

    logger(const logger& that) noexcept
      : _logger_id{that._logger_id}
      , _backend{that._backend} {
        lifetime("being copied");
    }

    auto operator=(logger&&) = delete;
    auto operator=(const logger&) = delete;

    ~logger() noexcept {
        lifetime("being destroyed");
    }

protected:
    logger(
      identifier logger_id,
      std::shared_ptr<logger_backend> backend) noexcept
      : _logger_id{logger_id}
      , _backend{std::move(backend)} {
        lifetime("${self} created with ${backend} backend")
          .arg(EAGINE_ID(backend), _backend)
          .arg(EAGINE_ID(self), EAGINE_ID(LogId), _logger_id);
    }

private:
    identifier _logger_id{EAGINE_ID(Logger)};
    std::shared_ptr<logger_backend> _backend{};

    inline auto
    _entry_backend(identifier source, log_event_severity severity) noexcept
      -> logger_backend* {
        if(is_log_level_enabled(severity)) {
            if(_backend) {
                return _backend->entry_backend(source, severity);
            }
        }
        return nullptr;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_LOGGER_HPP
