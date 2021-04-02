/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_LOGGING_PROXY_BACKEND_HPP
#define EAGINE_LOGGING_PROXY_BACKEND_HPP

#include "backend.hpp"
#include <functional>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
class proxy_log_backend : public logger_backend {
public:
    proxy_log_backend(log_event_severity min_severity) noexcept
      : _min_severity{min_severity} {}

    auto configure(application_config&) -> bool final;

    auto entry_backend(identifier source, log_event_severity severity) noexcept
      -> logger_backend* final;

    auto allocator() noexcept -> memory::shared_byte_allocator final;
    auto type_id() noexcept -> identifier final;

    void enter_scope(identifier source) noexcept final;
    void leave_scope(identifier source) noexcept final;

    void set_description(
      identifier source,
      logger_instance_id instance,
      string_view name,
      string_view desc) noexcept final;

    auto begin_message(
      identifier source,
      identifier tag,
      logger_instance_id instance,
      log_event_severity severity,
      string_view format) noexcept -> bool final;

    void add_nothing(identifier arg, identifier tag) noexcept final;

    void add_identifier(
      identifier arg,
      identifier tag,
      identifier value) noexcept final;

    void add_message_id(
      identifier arg,
      identifier tag,
      message_id value) noexcept final;

    void add_bool(identifier arg, identifier tag, bool value) noexcept final;

    void add_integer(
      identifier arg,
      identifier tag,
      std::intmax_t value) noexcept final;

    void add_unsigned(
      identifier arg,
      identifier tag,
      std::uintmax_t value) noexcept final;

    void add_float(identifier arg, identifier tag, float value) noexcept final;

    void add_float(
      identifier arg,
      identifier tag,
      float min,
      float value,
      float max) noexcept final;

    void add_duration(
      identifier arg,
      identifier tag,
      std::chrono::duration<float> value) noexcept final;

    void add_string(identifier arg, identifier tag, string_view value) noexcept
      final;

    void add_blob(
      identifier arg,
      identifier tag,
      memory::const_block value) noexcept final;

    void finish_message() noexcept final;

    void finish_log() noexcept final;

    void log_chart_sample(
      identifier source,
      logger_instance_id instance,
      identifier series,
      float value) noexcept final;

private:
    std::unique_ptr<logger_backend> _delegate;
    std::unique_ptr<std::vector<std::function<void()>>> _delayed{
      std::make_unique<std::vector<std::function<void()>>>()};
    log_event_severity _min_severity;
};
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/logging/proxy_backend.inl>
#endif

#endif // EAGINE_LOGGING_PROXY_BACKEND_HPP
