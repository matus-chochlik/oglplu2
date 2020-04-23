/**
 *  @file eagine/logging/backend.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_LOGGING_BACKEND_HPP
#define EAGINE_LOGGING_BACKEND_HPP

#include "../identifier.hpp"
#include "../memory/block.hpp"
#include "../memory/shared_alloc.hpp"
#include "../string_span.hpp"
#include "severity.hpp"
#include <chrono>
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
using logger_instance_id = std::uintptr_t;

struct logger_backend {

    logger_backend() noexcept = default;
    logger_backend(logger_backend&&) noexcept = default;
    logger_backend(const logger_backend&) noexcept = default;
    logger_backend& operator=(logger_backend&&) noexcept = default;
    logger_backend& operator=(const logger_backend&) noexcept = default;
    virtual ~logger_backend() noexcept = default;

    virtual memory::shared_byte_allocator allocator() noexcept = 0;

    virtual identifier type_id() noexcept = 0;

    virtual logger_backend* entry_backend(
      identifier source, log_event_severity severity) noexcept = 0;

    virtual void enter_scope(identifier scope) noexcept = 0;

    virtual void leave_scope(identifier scope) noexcept = 0;

    virtual bool begin_message(
      identifier source,
      logger_instance_id instance,
      log_event_severity severity,
      string_view format) noexcept = 0;

    virtual void add_nothing(identifier arg, identifier tag) noexcept = 0;

    virtual void add_identifier(
      identifier arg, identifier tag, identifier value) noexcept = 0;

    virtual void add_message_id(
      identifier arg,
      identifier tag,
      identifier clss,
      identifier method) noexcept = 0;

    virtual void add_bool(
      identifier arg, identifier tag, bool value) noexcept = 0;

    virtual void add_integer(
      identifier arg, identifier tag, std::intmax_t value) noexcept = 0;

    virtual void add_unsigned(
      identifier arg, identifier tag, std::uintmax_t value) noexcept = 0;

    virtual void add_float(
      identifier arg, identifier tag, float value) noexcept = 0;

    virtual void add_duration(
      identifier arg,
      identifier tag,
      std::chrono::duration<float> value) noexcept = 0;

    virtual void add_string(
      identifier arg, identifier tag, string_view value) noexcept = 0;

    virtual void add_blob(
      identifier arg, identifier tag, memory::const_block value) noexcept = 0;

    virtual void finish_message() noexcept = 0;

    virtual void finish_log() noexcept = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_BACKEND_HPP
