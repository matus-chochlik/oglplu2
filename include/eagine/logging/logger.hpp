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

    logger(identifier logger_id, logger& parent) noexcept
      : _logger_id{logger_id}
      , _backend{parent._backend} {
    }

protected:
    logger(
      identifier logger_id, std::shared_ptr<logger_backend> backend) noexcept
      : _logger_id{logger_id}
      , _backend{std::move(backend)} {
    }

private:
    identifier _logger_id{};
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
