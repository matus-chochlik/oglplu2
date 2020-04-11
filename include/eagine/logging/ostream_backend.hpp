/**
 *  @file eagine/logging/ostream_backend.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_LOGGING_OSTREAM_BACKEND_HPP
#define EAGINE_LOGGING_OSTREAM_BACKEND_HPP

#include "../hexdump.hpp"
#include "backend.hpp"
#include <mutex>
#include <ostream>

namespace eagine {
//------------------------------------------------------------------------------
template <typename Lockable = std::mutex>
class ostream_log_backend : public logger_backend {
private:
    Lockable _lockable{};
    std::ostream& _out;

public:
    ostream_log_backend(std::ostream& out) noexcept
      : _out{out} {
        try {
            std::unique_lock lock{_lockable};
            _out << "<?xml version='1.0' encoding='UTF-8'?>\n";
            _out << "<log>\n";
        } catch(...) {
        }
    }

    ostream_log_backend(ostream_log_backend&&) = delete;
    ostream_log_backend(const ostream_log_backend&) = delete;
    ostream_log_backend& operator=(ostream_log_backend&&) = delete;
    ostream_log_backend& operator=(const ostream_log_backend&) = delete;

    logger_backend* entry_backend(
      identifier, log_event_severity) noexcept final {
        return this;
    }

    bool begin_message(
      identifier source,
      log_event_severity severity,
      string_view format) noexcept final {
        try {
            _lockable.lock();
            _out << "<m";
            _out << " lvl='" << enumerator_name(severity) << "'";
            _out << " src='" << source.name() << "'";
            _out << ">";
            _out << "<f>" << format << "</f>";
        } catch(...) {
        }
        return true;
    }

    void add_identifier(identifier arg, identifier value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "'>" << value.name() << "</a>";
        } catch(...) {
        }
    }

    void add_integer(identifier arg, std::intmax_t value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "'>" << value << "</a>";
        } catch(...) {
        }
    }

    void add_unsigned(identifier arg, std::uintmax_t value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "'>" << value << "</a>";
        } catch(...) {
        }
    }

    void add_float(identifier arg, float value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "'>" << value << "</a>";
        } catch(...) {
        }
    }

    void add_duration(
      identifier arg, std::chrono::duration<float> value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "' u='s'>" << value.count()
                 << "</a>";
        } catch(...) {
        }
    }

    void add_blob(identifier arg, memory::const_block value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "'>" << hexdump(value) << "</a>";
        } catch(...) {
        }
    }

    void add_string(identifier arg, string_view value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "'>" << value << "</a>";
        } catch(...) {
        }
    }

    void finish_message() noexcept final {
        try {
            _out << "</m>\n";
            _lockable.unlock();
        } catch(...) {
        }
    }

    ~ostream_log_backend() noexcept final {
        try {
            std::unique_lock lock{_lockable};
            _out << "</log>\n" << std::flush;
        } catch(...) {
        }
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_OSTREAM_BACKEND_HPP
