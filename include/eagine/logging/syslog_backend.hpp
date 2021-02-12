/// @file eagine/logging/syslog_backend.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_LOGGING_SYSLOG_BACKEND_HPP
#define EAGINE_LOGGING_SYSLOG_BACKEND_HPP

#include "../config/platform.hpp"
#include "../flat_map.hpp"
#include "../memory/default_alloc.hpp"
#include "../memory/span_algo.hpp"
#include "backend.hpp"
#include <mutex>

#if EAGINE_POSIX
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>
#endif

namespace eagine {
//------------------------------------------------------------------------------
template <typename Lockable = std::mutex>
class syslog_log_backend : public logger_backend {
public:
    syslog_log_backend(log_event_severity min_severity)
      : _min_severity{min_severity} {
#if EAGINE_POSIX
        ::openlog(
          "OGLplus",
          LOG_CONS | LOG_NDELAY | LOG_PID, // NOLINT(hicpp-signed-bitwise)
          LOG_LOCAL0);                     // NOLINT(hicpp-signed-bitwise)
#endif
    }

    auto entry_backend(identifier, log_event_severity severity) noexcept
      -> logger_backend* final {
        if(severity >= _min_severity) {
            return this;
        }
        return nullptr;
    }

    auto allocator() noexcept -> memory::shared_byte_allocator final {
        return memory::default_byte_allocator();
    }

    auto type_id() noexcept -> identifier final {
        return EAGINE_ID(Syslog);
    }

    void enter_scope(identifier) noexcept final {}

    void leave_scope(identifier) noexcept final {}

    void set_description(
      identifier src,
      logger_instance_id inst,
      string_view name,
      string_view desc) noexcept final {
        EAGINE_MAYBE_UNUSED(src);
#if EAGINE_POSIX
        const auto idn{src.name()};
        ::syslog( // NOLINT(hicpp-vararg)
          _translate(log_event_severity::info),
          sizeof(logger_instance_id) > 4 ? "%16lx|%10.*s|name=%s, desc=%s"
                                         : "%8lx|%10.*s|name=%s, desc=%s",
          static_cast<unsigned long>(inst),
          int(idn.size()),
          idn.data(),
          c_str(name).c_str(),
          c_str(desc).c_str());
#endif
    }

    auto begin_message(
      identifier src,
      logger_instance_id inst,
      log_event_severity,
      string_view format) noexcept -> bool final {

        auto& msg = _new_message();
        msg.source = src;
        msg.instance = inst;
        msg.format.assign(
          sizeof(logger_instance_id) > 4 ? "%16lx|%10.*s|" : "%8lx|%10.*s|");
        _translate(format, msg);
        return true;
    }

    void do_add_arg(identifier arg, string_view value) noexcept {
        auto& msg = _get_message();
        const auto aidv = arg.value();
        bool found = false;
        for(auto [idx, idv] : msg.arg_idx) {
            if(idv == aidv) {
                found = true;
                break;
            }
        }
        if(found) {
            msg.arg_map[aidv].assign(value);
        } else {
            msg.format.append(", ");
            msg.format.append(arg.name().view());
            msg.format.append("=");
            msg.format.append(value);
        }
    }

    void add_nothing(identifier, identifier) noexcept final {}

    void add_identifier(identifier arg, identifier, identifier value) noexcept
      final {
        do_add_arg(arg, value.name().view());
    }

    void add_message_id(identifier arg, identifier, message_id value) noexcept
      final {
        std::string temp;
        temp.reserve(21);
        temp.append(value.class_().name().view());
        temp.append(".");
        temp.append(value.method().name().view());
        do_add_arg(arg, temp);
    }

    void add_bool(identifier arg, identifier, bool value) noexcept final {
        do_add_arg(arg, value ? string_view{"True"} : string_view{"False"});
    }

    void add_integer(identifier arg, identifier, std::intmax_t value) noexcept
      final {
        using std::to_string;
        do_add_arg(arg, to_string(value));
    }

    void add_unsigned(identifier arg, identifier, std::uintmax_t value) noexcept
      final {
        using std::to_string;
        do_add_arg(arg, to_string(value));
    }

    void add_float(identifier arg, identifier, float value) noexcept final {
        using std::to_string;
        do_add_arg(arg, to_string(value));
    }

    void
    add_float(identifier arg, identifier, float, float value, float) noexcept
      final {
        using std::to_string;
        do_add_arg(arg, to_string(value));
    }

    void add_duration(
      identifier arg,
      identifier,
      std::chrono::duration<float> value) noexcept final {
        using std::to_string;
        std::string temp(to_string(value.count()));
        temp.append("[s]");
        do_add_arg(arg, temp);
    }

    void
    add_string(identifier arg, identifier, string_view value) noexcept final {
        using std::to_string;
        do_add_arg(arg, value);
    }

    void add_blob(identifier, identifier, memory::const_block) noexcept final {}

    void finish_message() noexcept final {
        _do_log(_get_message());
        _del_message();
    }

    void finish_log() noexcept final {
#if EAGINE_POSIX
        ::closelog();
#endif
    }

    void log_chart_sample(
      identifier,
      logger_instance_id,
      identifier,
      float) noexcept final {}

private:
    Lockable _lockable{};
    log_event_severity _min_severity;

    struct _message_state {
        identifier source;
        logger_instance_id instance{0};
        std::string format;
        flat_map<std::size_t, identifier_t> arg_idx;
        flat_map<identifier_t, std::string> arg_map;
        std::size_t arg_count{0};
    };

    _message_state _the_message{};

    auto _new_message() noexcept -> auto& {
        _lockable.lock();
        _the_message.arg_count = 0;
        for(auto& [idx, idv] : _the_message.arg_idx) {
            EAGINE_MAYBE_UNUSED(idx);
            idv = 0;
        }
        return _the_message;
    }

    auto _get_message() noexcept -> auto& {
        return _the_message;
    }

    void _del_message() noexcept {
        _lockable.unlock();
    }

    static constexpr auto _translate(log_event_severity severity) noexcept
      -> int {
#if EAGINE_POSIX
        switch(severity) {
            case log_event_severity::fatal:
                return LOG_CRIT;
            case log_event_severity::error:
                return LOG_ERR;
            case log_event_severity::warning:
                return LOG_WARNING;
            case log_event_severity::info:
            case log_event_severity::stat:
                return LOG_INFO;
            case log_event_severity::debug:
                return LOG_DEBUG;
            case log_event_severity::trace:
                return LOG_NOTICE;
            case log_event_severity::backtrace:
                break;
        }
#endif
        EAGINE_MAYBE_UNUSED(severity);
        return 0;
    }

    static void _translate(string_view format, _message_state& msg) {
        while(auto pos{find_position(format, string_view{"${"})}) {
            const string_view prev{head(format, extract(pos))};
            msg.format.append(prev);
            format = skip(format, extract(pos) + 2);
            if(auto end{find_position(format, string_view{"}"})}) {
                msg.arg_idx[msg.arg_count++] =
                  identifier(head(format, extract(end))).value();
                msg.format.append("%s");
                format = skip(format, extract(end) + 1);
            }
        }
        msg.format.append(format);
    }

    template <std::size_t... I>
    void _do_log_I(_message_state& msg, std::index_sequence<I...>) {
        const auto source_name = msg.source.name();
        ::syslog( // NOLINT(hicpp-vararg)
          _translate(log_event_severity::info),
          msg.format.c_str(),
          static_cast<unsigned long>(msg.instance),
          int(source_name.size()),
          source_name.data(),
          msg.arg_map[msg.arg_idx[I]].c_str()...);
    }

    template <std::size_t N>
    auto _do_log_N(_message_state& msg) -> bool {
        if constexpr(N > 0) {
            if(_do_log_N<N - 1>(msg)) {
                return true;
            }
        }
        if(msg.arg_count == N) {
            _do_log_I(msg, std::make_index_sequence<N>());
            return true;
        }
        return false;
    }

    void _do_log(_message_state& msg) {
        _do_log_N<12>(msg);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_SYSLOG_BACKEND_HPP
