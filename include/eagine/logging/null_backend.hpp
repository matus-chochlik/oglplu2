/**
 *  @file eagine/logging/null_backend.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_LOGGING_NULL_BACKEND_HPP
#define EAGINE_LOGGING_NULL_BACKEND_HPP

#include "backend.hpp"

namespace eagine {
//------------------------------------------------------------------------------
struct null_log_backend : logger_backend {

    auto entry_backend(identifier, log_event_severity) noexcept
      -> logger_backend* final {
        return nullptr;
    }

    auto allocator() noexcept -> memory::shared_byte_allocator final {
        return {};
    }

    auto type_id() noexcept -> identifier final {
        return EAGINE_ID(Null);
    }

    void enter_scope(identifier) noexcept final {}

    void leave_scope(identifier) noexcept final {}

    auto begin_message(
      identifier,
      logger_instance_id,
      log_event_severity,
      string_view) noexcept -> bool final {
        return false;
    }

    void add_nothing(identifier, identifier) noexcept final {}

    void add_identifier(identifier, identifier, identifier) noexcept final {}

    void add_message_id(identifier, identifier, message_id) noexcept final {}

    void add_bool(identifier, identifier, bool) noexcept final {}

    void add_integer(identifier, identifier, std::intmax_t) noexcept final {}

    void add_unsigned(identifier, identifier, std::uintmax_t) noexcept final {}

    void add_float(identifier, identifier, float) noexcept final {}

    void add_float(identifier, identifier, float, float, float) noexcept final {
    }

    void add_duration(
      identifier,
      identifier,
      std::chrono::duration<float>) noexcept final {}

    void add_string(identifier, identifier, string_view) noexcept final {}

    void add_blob(identifier, identifier, memory::const_block) noexcept final {}

    void finish_message() noexcept final {}

    void finish_log() noexcept final {}

    void log_chart_sample(
      identifier,
      logger_instance_id,
      identifier,
      float) noexcept final {}
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_NULL_BACKEND_HPP
