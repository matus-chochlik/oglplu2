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
class logger_shared_backend_getter {
    using This = logger_shared_backend_getter;

public:
    logger_shared_backend_getter() noexcept = default;
    logger_shared_backend_getter(This&&) noexcept = default;
    logger_shared_backend_getter(const This&) noexcept = default;
    auto operator=(This&&) = delete;
    auto operator=(const This&) = delete;

    ~logger_shared_backend_getter() noexcept = default;

    logger_shared_backend_getter(
      std::shared_ptr<logger_backend> backend) noexcept
      : _backend{std::move(backend)} {}

    auto operator()() noexcept -> logger_backend* {
        return _backend.get();
    }

private:
    std::shared_ptr<logger_backend> _backend{};
};
//------------------------------------------------------------------------------
template <typename BackendGetter>
class basic_logger : protected BackendGetter {
public:
    template <log_event_severity severity>
    using entry = std::
      conditional_t<is_log_level_enabled_v<severity>, log_entry, no_log_entry>;

protected:
    basic_logger() noexcept = default;

    basic_logger(BackendGetter get_backend) noexcept(
      std::is_nothrow_move_constructible_v<BackendGetter>)
      : BackendGetter(std::move(get_backend)) {}

    auto make_log_entry(
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

    constexpr auto make_log_entry(
      identifier,
      log_event_severity,
      std::false_type,
      string_view) noexcept -> no_log_entry {
        return {};
    }

    template <log_event_severity severity>
    constexpr auto make_log_entry(
      identifier source,
      log_event_severity_constant<severity>,
      string_view format) noexcept -> entry<severity> {
        return make_log_entry(
          source, severity, is_log_level_enabled_t<severity>{}, format);
    }

    auto make_log_entry(
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

    auto log_fatal(identifier source, string_view format) noexcept {
        return make_log_entry(
          source,
          log_event_severity_constant<log_event_severity::fatal>{},
          format);
    }

    auto log_error(identifier source, string_view format) noexcept {
        return make_log_entry(
          source,
          log_event_severity_constant<log_event_severity::error>{},
          format);
    }

    auto log_warning(identifier source, string_view format) noexcept {
        return make_log_entry(
          source,
          log_event_severity_constant<log_event_severity::warning>{},
          format);
    }

    auto log_info(identifier source, string_view format) noexcept {
        return make_log_entry(
          source,
          log_event_severity_constant<log_event_severity::info>{},
          format);
    }

    auto log_stat(identifier source, string_view format) noexcept {
        return make_log_entry(
          source,
          log_event_severity_constant<log_event_severity::stat>{},
          format);
    }

    auto log_debug(identifier source, string_view format) noexcept {
        return make_log_entry(
          source,
          log_event_severity_constant<log_event_severity::debug>{},
          format);
    }

    auto log_trace(identifier source, string_view format) noexcept {
        return make_log_entry(
          source,
          log_event_severity_constant<log_event_severity::trace>{},
          format);
    }

    auto log_backtrace(identifier source, string_view format) noexcept {
        return make_log_entry(
          source,
          log_event_severity_constant<log_event_severity::backtrace>{},
          format);
    }

    auto log_lifetime(identifier source, string_view format) noexcept {
        // TODO: switch depending on Debug/Release ?
        return log_info(source, format);
    }

    auto make_log_stream(identifier source, log_event_severity severity) noexcept
      -> stream_log_entry {
        return {
          source,
          reinterpret_cast<logger_instance_id>(this),
          severity,
          _entry_backend(source, severity)};
    }

    auto _get_backend() noexcept {
        return _backend_getter()();
    }

    auto _entry_backend(identifier source, log_event_severity severity) noexcept
      -> logger_backend* {
        if(is_log_level_enabled(severity)) {
            if(auto backend{_get_backend()}) {
                return backend->entry_backend(source, severity);
            }
        }
        return nullptr;
    }

private:
    auto _backend_getter() noexcept -> BackendGetter& {
        return *this;
    }
};
//------------------------------------------------------------------------------
template <typename BackendGetter>
class named_logging_object : public basic_logger<BackendGetter> {
    using base = basic_logger<BackendGetter>;

public:
    template <log_event_severity severity>
    using entry = std::
      conditional_t<is_log_level_enabled_v<severity>, log_entry, no_log_entry>;

    named_logging_object(
      identifier logger_id,
      const std::shared_ptr<logger_backend>& backend) noexcept
      : base(backend)
      , _logger_id{logger_id} {
        this
          ->log_lifetime(_logger_id, "${self} created with ${backend} backend")
          .arg(EAGINE_ID(backend), this->_get_backend())
          .arg(EAGINE_ID(self), EAGINE_ID(LogId), _logger_id);
    }

    named_logging_object() noexcept = default;

    named_logging_object(
      identifier logger_id,
      named_logging_object& parent) noexcept
      : base(static_cast<const base&>(parent))
      , _logger_id{logger_id} {
        this->log_lifetime(_logger_id, "created as a child of ${parent}")
          .arg(EAGINE_ID(parent), EAGINE_ID(LogId), parent._logger_id);
    }

    named_logging_object(named_logging_object&& temp) noexcept
      : base(static_cast<base&&>(temp))
      , _logger_id{temp._logger_id} {
        this->log_lifetime(_logger_id, "being moved");
    }

    named_logging_object(const named_logging_object& that) noexcept
      : base(static_cast<const base&>(that))
      , _logger_id{that._logger_id} {
        this->log_lifetime(_logger_id, "being copied");
    }

    auto operator=(named_logging_object&&) noexcept
      -> named_logging_object& = default;
    auto operator=(const named_logging_object&)
      -> named_logging_object& = default;

    ~named_logging_object() noexcept {
        this->log_lifetime(_logger_id, "being destroyed");
    }

    auto log_fatal(string_view format) noexcept {
        return base::log_fatal(_logger_id, format);
    }

    auto log_error(string_view format) noexcept {
        return base::log_error(_logger_id, format);
    }

    auto log_warning(string_view format) noexcept {
        return base::log_warning(_logger_id, format);
    }

    auto log_info(string_view format) noexcept {
        return base::log_info(_logger_id, format);
    }

    auto log_stat(string_view format) noexcept {
        return base::log_stat(_logger_id, format);
    }

    auto log_debug(string_view format) noexcept {
        return base::log_debug(_logger_id, format);
    }

    auto log_trace(string_view format) noexcept {
        return base::log_trace(_logger_id, format);
    }

    auto log_backtrace(string_view format) noexcept {
        return base::log_backtrace(_logger_id, format);
    }

protected:
    template <log_event_severity severity>
    auto make_log_entry(
      log_event_severity_constant<severity> level,
      string_view format) noexcept -> entry<severity> {
        return base::make_log_entry(_logger_id, level, format);
    }

    auto make_log_entry(log_event_severity severity, string_view format) noexcept
      -> log_entry {
        return base::make_log_entry(_logger_id, severity, format);
    }

    auto make_log_stream(log_event_severity severity) noexcept {
        return base::make_log_stream(_logger_id, severity);
    }

private:
    identifier _logger_id{EAGINE_ID(Logger)};
};
//------------------------------------------------------------------------------
class logger : public named_logging_object<logger_shared_backend_getter> {
    using base = named_logging_object<logger_shared_backend_getter>;

public:
    template <log_event_severity severity>
    auto log(
      log_event_severity_constant<severity> level,
      string_view format) noexcept -> entry<severity> {
        return make_log_entry(level, format);
    }

    auto log(log_event_severity severity, string_view format) noexcept {
        return make_log_entry(severity, format);
    }

    auto error_stream() noexcept {
        return make_log_stream(log_event_severity::error);
    }

    auto fatal(string_view format) noexcept {
        return log_fatal(format);
    }

    auto error(string_view format) noexcept {
        return log_error(format);
    }

    auto warning(string_view format) noexcept {
        return log_warning(format);
    }

    auto info(string_view format) noexcept {
        return log_info(format);
    }

    auto stat(string_view format) noexcept {
        return log_stat(format);
    }

    auto debug(string_view format) noexcept {
        return log_debug(format);
    }

    auto trace(string_view format) noexcept {
        return log_trace(format);
    }

    auto backtrace(string_view format) noexcept {
        return log_backtrace(format);
    }

    using base::base;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_LOGGER_HPP
