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

#include "../base64dump.hpp"
#include "../memory/aligned_block.hpp"
#include "../memory/stack_alloc.hpp"
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
    log_event_severity _min_severity;
    const std::chrono::steady_clock::time_point _start;
    memory::aligned_block<3840> _alloc_block{};

protected:
    virtual void flush() noexcept {
    }

public:
    ostream_log_backend(
      std::ostream& out, log_event_severity min_severity) noexcept
      : _out{out}
      , _min_severity{min_severity}
      , _start{std::chrono::steady_clock::now()} {
        try {
            std::unique_lock lock{_lockable};
            _out << "<?xml version='1.0' encoding='UTF-8'?>\n";
            _out << "<log start='" << _start.time_since_epoch().count()
                 << "'>\n";
        } catch(...) {
        }
    }

    ostream_log_backend(ostream_log_backend&&) = delete;
    ostream_log_backend(const ostream_log_backend&) = delete;
    ostream_log_backend& operator=(ostream_log_backend&&) = delete;
    ostream_log_backend& operator=(const ostream_log_backend&) = delete;

    memory::shared_byte_allocator allocator() noexcept final {
        return {memory::stack_byte_allocator_only<>{_alloc_block}};
    }

    identifier type_id() noexcept final {
        return EAGINE_ID(OutStream);
    }

    logger_backend* entry_backend(
      identifier, log_event_severity severity) noexcept final {
        if(severity >= _min_severity) {
            return this;
        }
        return nullptr;
    }

    void enter_scope(identifier scope) noexcept final {
        try {
            _lockable.lock();
            _out << "<s name='" << scope.name() << "'>\n";
        } catch(...) {
        }
    }

    void leave_scope(identifier) noexcept final {
        try {
            _lockable.lock();
            _out << "</s>\n";
        } catch(...) {
        }
    }

    bool begin_message(
      identifier source,
      logger_instance_id instance,
      log_event_severity severity,
      string_view format) noexcept final {
        try {
            _lockable.lock();
            const auto now = std::chrono::steady_clock::now();
            _out << "<m";
            _out << " lvl='" << enumerator_name(severity) << "'";
            _out << " src='" << source.name() << "'";
            _out << " iid='" << instance << "'";
            _out << " ts='" << (now - _start).count() << "'";
            _out << ">";
            _out << "<f>" << format << "</f>";
        } catch(...) {
        }
        return true;
    }

    void add_nothing(identifier arg, identifier tag) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "' t='" << tag.name() << "'/>";
        } catch(...) {
        }
    }

    void add_identifier(
      identifier arg, identifier tag, identifier value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "' t='" << tag.name() << "'>"
                 << value.name() << "</a>";
        } catch(...) {
        }
    }

    void add_message_id(
      identifier arg,
      identifier tag,
      identifier clss,
      identifier method) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "' t='" << tag.name() << "'>"
                 << clss.name() << "." << method.name() << "</a>";
        } catch(...) {
        }
    }

    void add_bool(identifier arg, identifier tag, bool value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "' t='" << tag.name() << "'>"
                 << (value ? "true" : "false") << "</a>";
        } catch(...) {
        }
    }

    void add_integer(
      identifier arg, identifier tag, std::intmax_t value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "' t='" << tag.name() << "'>"
                 << value << "</a>";
        } catch(...) {
        }
    }

    void add_unsigned(
      identifier arg, identifier tag, std::uintmax_t value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "' t='" << tag.name() << "'>"
                 << value << "</a>";
        } catch(...) {
        }
    }

    void add_float(identifier arg, identifier tag, float value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "' t='" << tag.name() << "'>"
                 << value << "</a>";
        } catch(...) {
        }
    }

    void add_duration(
      identifier arg,
      identifier tag,
      std::chrono::duration<float> value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "' t='" << tag.name()
                 << "' u='s'>" << value.count() << "</a>";
        } catch(...) {
        }
    }

    void add_blob(
      identifier arg,
      identifier tag,
      memory::const_block value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "' t='" << tag.name()
                 << "' blob='true'>" << base64dump(value) << "</a>";
        } catch(...) {
        }
    }

    void add_string(
      identifier arg, identifier tag, string_view value) noexcept final {
        try {
            _out << "<a n='" << arg.name() << "' t='" << tag.name() << "'>"
                 << value << "</a>";
        } catch(...) {
        }
    }

    void finish_message() noexcept final {
        try {
            _out << "</m>\n";
            flush();
            _lockable.unlock();
        } catch(...) {
        }
    }

    void finish_log() noexcept final {
        try {
            std::unique_lock lock{_lockable};
            _out << "</log>\n" << std::flush;
            flush();
        } catch(...) {
        }
    }

    ~ostream_log_backend() noexcept override {
        finish_log();
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_OSTREAM_BACKEND_HPP
