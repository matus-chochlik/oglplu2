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
    logger_backend* entry_backend(
      identifier, log_event_severity) noexcept final {
        return nullptr;
    }

    identifier type_id() noexcept final {
        return EAGINE_ID(Null);
    }

    void enter_scope(identifier) noexcept final {
    }

    void leave_scope(identifier) noexcept final {
    }

    bool begin_message(
      identifier, log_event_severity, string_view) noexcept final {
        return false;
    }

    void add_nothing(identifier, identifier) noexcept final {
    }

    void add_identifier(identifier, identifier, identifier) noexcept final {
    }

    void add_bool(identifier, identifier, bool) noexcept final {
    }

    void add_integer(identifier, identifier, std::intmax_t) noexcept final {
    }

    void add_unsigned(identifier, identifier, std::uintmax_t) noexcept final {
    }

    void add_float(identifier, identifier, float) noexcept final {
    }

    void add_duration(
      identifier, identifier, std::chrono::duration<float>) noexcept final {
    }

    void add_string(identifier, identifier, string_view) noexcept final {
    }

    void add_blob(identifier, identifier, memory::const_block) noexcept final {
    }

    void finish_message() noexcept final {
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_NULL_BACKEND_HPP
