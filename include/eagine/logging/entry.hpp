/**
 *  @file eagine/logging/entry.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_LOGGING_ENTRY_HPP
#define EAGINE_LOGGING_ENTRY_HPP

#include "../branch_predict.hpp"
#include "../memory/default_alloc.hpp"
#include "../memory/object_storage.hpp"
#include "backend.hpp"

namespace eagine {
//------------------------------------------------------------------------------
class logger;

class log_entry {
public:
    log_entry(log_entry&& temp) noexcept
      : _backend{temp._backend}
      , _format{temp._format}
      , _args{memory::c_byte_reallocator<>()}
      , _severity{temp._severity} {
        temp._backend = nullptr;
    }
    log_entry(const log_entry&) = delete;
    log_entry& operator=(log_entry&&) = delete;
    log_entry& operator=(const log_entry&) = delete;

    ~log_entry() noexcept {
        if(_backend) {
            if(EAGINE_LIKELY(
                 _backend->begin_message(_source_id, _severity, _format))) {
                _args(*_backend);
                _backend->finish_message();
            }
        }
    }

    log_entry& arg(identifier name, identifier value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_identifier(name, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, string_view value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_string(name, value);
            });
        }
        return *this;
    }

private:
    friend class logger;

    log_entry(
      identifier source_id,
      log_event_severity severity,
      string_view format,
      logger_backend* backend) noexcept
      : _source_id{source_id}
      , _backend{backend}
      , _format{format}
      , _args{memory::default_byte_allocator()} // TODO: arena alloc
      , _severity{severity} {
    }

    identifier _source_id{};
    logger_backend* _backend{nullptr};
    const string_view _format{};
    memory::callable_storage<void(logger_backend&)> _args;
    const log_event_severity _severity{log_event_severity::info};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_ENTRY_HPP
