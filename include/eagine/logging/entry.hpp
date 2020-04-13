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
static inline auto adapt_log_entry_arg(
  identifier name, std::shared_ptr<logger_backend> value) {
    return [name, value{std::move(value)}](logger_backend& backend) {
        if(value) {
            backend.add_identifier(
              name, EAGINE_ID(LogBkEndId), value->type_id());
        } else {
            backend.add_nothing(name, EAGINE_ID(LogBkEndId));
        }
    };
}
//------------------------------------------------------------------------------
template <typename T, typename = std::enable_if_t<has_enumerator_mapping_v<T>>>
static constexpr inline auto adapt_log_entry_arg(identifier name, T value) {
    return [=](logger_backend& backend) {
        backend.add_string(name, enumerator_name(value));
    };
}
//------------------------------------------------------------------------------
template <typename T>
struct does_have_log_entry_adapter {
private:
    template <
      typename X,
      typename = decltype(
        adapt_log_entry_arg(std::declval<identifier>(), std::declval<X>()))>
    static std::true_type _test(X*);

    static std::false_type _test(...);

public:
    // NOLINTNEXTLINE(hicpp-vararg)
    using type = decltype(_test(static_cast<T*>(nullptr)));
};

template <typename T>
using has_log_entry_adapter_t = typename does_have_log_entry_adapter<T>::type;

template <typename T>
constexpr const bool has_log_entry_adapter_v =
  has_log_entry_adapter_t<T>::value;
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

    log_entry& arg(identifier name, identifier tag, identifier value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_identifier(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, identifier value) noexcept {
        return arg(name, EAGINE_ID(id), value);
    }

    log_entry& arg(identifier name, identifier tag, int value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_integer(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, int value) noexcept {
        return arg(name, EAGINE_ID(int), value);
    }

    log_entry& arg(identifier name, identifier tag, unsigned value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_unsigned(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, unsigned value) noexcept {
        return arg(name, EAGINE_ID(uint), value);
    }

    log_entry& arg(identifier name, identifier tag, float value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_float(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, float value) noexcept {
        return arg(name, EAGINE_ID(real), value);
    }

    log_entry& arg(
      identifier name, identifier tag, string_view value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_string(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, string_view value) noexcept {
        return arg(name, EAGINE_ID(str), value);
    }

    log_entry& arg(
      identifier name, identifier tag, memory::const_block value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_blob(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, memory::const_block value) noexcept {
        return arg(name, EAGINE_ID(blk), value);
    }

    template <typename T>
    std::enable_if_t<has_log_entry_adapter_v<std::decay_t<T>>, log_entry&> arg(
      identifier name, T&& value) noexcept {
        if(_backend) {
            _args.add(adapt_log_entry_arg(name, std::forward<T>(value)));
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
