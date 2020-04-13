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

#include "entry.hpp"

namespace eagine {
//------------------------------------------------------------------------------
class logger {
public:
    log_entry log(
      identifier source,
      log_event_severity severity,
      string_view format) noexcept {
        return {source, severity, format, _entry_backend(source, severity)};
    }

    log_entry log(log_event_severity severity, string_view format) noexcept {
        return log(_logger_id, severity, format);
    }

    inline auto fatal(string_view format) noexcept {
        return log(log_event_severity::fatal, format);
    }

    inline auto error(string_view format) noexcept {
        return log(log_event_severity::error, format);
    }

    inline auto warning(string_view format) noexcept {
        return log(log_event_severity::warning, format);
    }

    inline auto info(string_view format) noexcept {
        return log(log_event_severity::info, format);
    }

    inline auto debug(string_view format) noexcept {
        return log(log_event_severity::debug, format);
    }

    inline auto trace(string_view format) noexcept {
        return log(log_event_severity::trace, format);
    }

    inline auto backtrace(string_view format) noexcept {
        return log(log_event_severity::backtrace, format);
    }

    inline auto lifetime(string_view format) noexcept {
        // TODO: switch depending on Debug/Release ?
        return info(format);
    }

    logger() noexcept = default;

    logger(identifier logger_id, logger& parent) noexcept
      : _logger_id{logger_id}
      , _backend{parent._backend} {
        lifetime("${self} created as a child of ${parent}")
          .arg(EAGINE_ID(parent), EAGINE_ID(LogId), parent._logger_id)
          .arg(EAGINE_ID(self), EAGINE_ID(LogId), _logger_id);
    }

    logger(logger&& temp) noexcept
      : _logger_id{temp._logger_id}
      , _backend{std::move(temp._backend)} {
        lifetime("${self} being moved")
          .arg(EAGINE_ID(self), EAGINE_ID(LogId), _logger_id);
    }

    logger(const logger& that) noexcept
      : _logger_id{that._logger_id}
      , _backend{that._backend} {
        lifetime("${self} being copied")
          .arg(EAGINE_ID(self), EAGINE_ID(LogId), _logger_id);
    }

    logger& operator=(logger&&) = delete;
    logger& operator=(const logger&) = delete;

    ~logger() noexcept {
        lifetime("${self} being destroyed")
          .arg(EAGINE_ID(self), EAGINE_ID(LogId), _logger_id);
    }

protected:
    logger(
      identifier logger_id, std::shared_ptr<logger_backend> backend) noexcept
      : _logger_id{logger_id}
      , _backend{std::move(backend)} {
        lifetime("${self} created with ${backend} backend")
          .arg(EAGINE_ID(backend), _backend)
          .arg(EAGINE_ID(self), EAGINE_ID(LogId), _logger_id);
    }

private:
    identifier _logger_id{EAGINE_ID(Logger)};
    std::shared_ptr<logger_backend> _backend{};

    inline logger_backend* _entry_backend(
      identifier source, log_event_severity severity) noexcept {
        if(_backend) {
            return _backend->entry_backend(source, severity);
        }
        return nullptr;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_LOGGER_HPP
