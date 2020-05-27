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

#include "../bitfield.hpp"
#include "../branch_predict.hpp"
#include "../memory/object_storage.hpp"
#include "../message_id.hpp"
#include "../valid_if/decl.hpp"
#include "backend.hpp"
#include <sstream>

namespace eagine {
//------------------------------------------------------------------------------
static inline auto adapt_log_entry_arg(
  identifier name, const std::shared_ptr<logger_backend>& value) {
    return [name, &value](logger_backend& backend) {
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
        backend.add_string(name, EAGINE_ID(enum), enumerator_name(value));
    };
}
//------------------------------------------------------------------------------
template <typename T, typename = std::enable_if_t<has_enumerator_mapping_v<T>>>
static constexpr inline auto adapt_log_entry_arg(
  identifier name, bitfield<T> bf) {
    return [=](logger_backend& backend) {
        auto func = [&backend, name, bf](const auto& info) {
            if(bf.has(static_cast<T>(info.value))) {
                backend.add_string(name, EAGINE_ID(bitfield), info.name);
            }
        };
        for_each_enumerator(func, identity<T>{});
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
template <typename T>
struct does_have_log_entry_function;

template <typename T>
using has_log_entry_function_t = typename does_have_log_entry_function<T>::type;

template <typename T>
constexpr const bool has_log_entry_function_v =
  has_log_entry_function_t<T>::value;
//------------------------------------------------------------------------------
class logger;

class log_entry {
    static memory::shared_byte_allocator _be_alloc(
      logger_backend* backend) noexcept {
        if(backend) {
            return backend->allocator();
        }
        return {};
    }

public:
    log_entry(log_entry&& temp) noexcept
      : _backend{temp._backend}
      , _format{temp._format}
      , _args{_be_alloc(_backend)}
      , _severity{temp._severity} {
        temp._backend = nullptr;
    }
    log_entry(const log_entry&) = delete;
    log_entry& operator=(log_entry&&) = delete;
    log_entry& operator=(const log_entry&) = delete;

    ~log_entry() noexcept {
        if(_backend) {
            if(EAGINE_LIKELY(_backend->begin_message(
                 _source_id, _instance_id, _severity, _format))) {
                _args(*_backend);
                _backend->finish_message();
                _backend = nullptr;
            }
        }
    }

    log_entry& set_format(string_view format) noexcept {
        _format = format;
        return *this;
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

    log_entry& arg(
      identifier name, identifier tag, const message_id_tuple& value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_message_id(
                  name, tag, value.class_(), value.method());
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, message_id_tuple value) noexcept {
        return arg(name, EAGINE_ID(MessageId), value);
    }

    template <identifier_t ClassId, identifier_t MethodId>
    log_entry& arg(
      identifier name, identifier tag, message_id<ClassId, MethodId>) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_message_id(
                  name, tag, identifier(ClassId), identifier(MethodId));
            });
        }
        return *this;
    }

    template <identifier_t ClassId, identifier_t MethodId>
    log_entry& arg(
      identifier name, message_id<ClassId, MethodId> value) noexcept {
        return arg(name, EAGINE_ID(MessageId), value);
    }

    log_entry& arg(
      identifier name, identifier tag, std::int64_t value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_integer(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, std::int64_t value) noexcept {
        return arg(name, EAGINE_ID(int64), value);
    }

    log_entry& arg(
      identifier name, identifier tag, std::int32_t value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_integer(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, std::int32_t value) noexcept {
        return arg(name, EAGINE_ID(int32), value);
    }

    log_entry& arg(
      identifier name, identifier tag, std::int16_t value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_integer(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, std::int16_t value) noexcept {
        return arg(name, EAGINE_ID(int16), value);
    }

    log_entry& arg(
      identifier name, identifier tag, std::uint64_t value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_unsigned(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, std::uint64_t value) noexcept {
        return arg(name, EAGINE_ID(uint64), value);
    }

    log_entry& arg(
      identifier name, identifier tag, std::uint32_t value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_unsigned(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, std::uint32_t value) noexcept {
        return arg(name, EAGINE_ID(uint32), value);
    }

    log_entry& arg(
      identifier name, identifier tag, std::uint16_t value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_unsigned(name, tag, value);
            });
        }
        return *this;
    }

    log_entry& arg(identifier name, std::uint16_t value) noexcept {
        return arg(name, EAGINE_ID(uint16), value);
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
      identifier name,
      identifier tag,
      float min,
      float value,
      float max) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_float(name, tag, min, value, max);
            });
        }
        return *this;
    }

    log_entry& arg(
      identifier name, float min, float value, float max) noexcept {
        return arg(name, EAGINE_ID(real), min, value, max);
    }

    template <typename R, typename P>
    log_entry& arg(
      identifier name,
      identifier tag,
      std::chrono::duration<R, P> value) noexcept {
        if(_backend) {
            _args.add([=](logger_backend& backend) {
                backend.add_duration(
                  name,
                  tag,
                  std::chrono::duration_cast<std::chrono::duration<float>>(
                    value));
            });
        }
        return *this;
    }

    template <typename R, typename P>
    log_entry& arg(
      identifier name, std::chrono::duration<R, P> value) noexcept {
        return arg(name, EAGINE_ID(duration), value);
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

    template <typename Func>
    log_entry& arg_func(Func function) {
        if(_backend) {
            _args.add(std::move(function));
        }
        return *this;
    }

    template <typename T>
    std::enable_if_t<has_log_entry_adapter_v<std::decay_t<T>>, log_entry&> arg(
      identifier name, T&& value) noexcept {
        if(_backend) {
            _args.add(adapt_log_entry_arg(name, std::forward<T>(value)));
        }
        return *this;
    }

    template <typename T, typename P, typename F>
    std::enable_if_t<
      has_log_entry_function_v<std::decay_t<T>> &&
        has_log_entry_function_v<std::decay_t<F>>,
      log_entry&>
    arg(
      identifier name,
      identifier tag,
      valid_if_or_fallback<T, P, F>&& opt) noexcept {
        if(opt.is_valid()) {
            return arg(name, tag, std::move(opt.value()));
        }
        return arg(name, std::move(opt.fallback()));
    }

    template <typename T, typename P, typename F>
    std::enable_if_t<
      has_log_entry_function_v<std::decay_t<T>> &&
        has_log_entry_function_v<std::decay_t<F>>,
      log_entry&>
    arg(identifier name, identifier tag, valid_if<T, P> opt, F fbck) noexcept {
        return arg(name, tag, either_or(std::move(opt), std::move(fbck)));
    }

private:
    friend class logger;

    log_entry(
      identifier source_id,
      logger_instance_id instance_id,
      log_event_severity severity,
      string_view format,
      logger_backend* backend) noexcept
      : _source_id{source_id}
      , _instance_id{instance_id}
      , _backend{backend}
      , _format{format}
      , _args{_be_alloc(_backend)}
      , _severity{severity} {
    }

    identifier _source_id{};
    logger_instance_id _instance_id{};
    logger_backend* _backend{nullptr};
    string_view _format{};
    memory::callable_storage<void(logger_backend&)> _args;
    const log_event_severity _severity{log_event_severity::info};
};
//------------------------------------------------------------------------------
struct no_log_entry {
    template <typename T>
    constexpr inline no_log_entry& arg(identifier, T&&) noexcept {
        return *this;
    }
    template <typename T>
    constexpr inline no_log_entry& arg(identifier, identifier, T&&) noexcept {
        return *this;
    }

    template <typename T, typename P, typename F>
    constexpr inline no_log_entry& arg(
      identifier, identifier, valid_if<T, P>, const F&) noexcept {
        return *this;
    }

    template <typename Func>
    constexpr inline no_log_entry& arg_func(const Func&) {
        return *this;
    }
};
//------------------------------------------------------------------------------
template <typename T>
struct does_have_log_entry_function {
private:
    template <
      typename X,
      typename = decltype(std::declval<log_entry>().arg(
        std::declval<identifier>(),
        std::declval<identifier>(),
        std::declval<X>()))>
    static std::true_type _test(X*);

    static std::false_type _test(...);

public:
    // NOLINTNEXTLINE(hicpp-vararg)
    using type = decltype(_test(static_cast<T*>(nullptr)));
};
//------------------------------------------------------------------------------
class stream_log_entry {
public:
    operator std::ostream&() noexcept {
        return _out;
    }

    stream_log_entry(stream_log_entry&&) = default;
    stream_log_entry(const stream_log_entry&) = delete;
    stream_log_entry& operator=(stream_log_entry&&) = delete;
    stream_log_entry& operator=(const stream_log_entry&) = delete;

    ~stream_log_entry() noexcept {
        try {
            auto fmt_str(_out.str());
            if(!fmt_str.empty()) {
                if(_backend) {
                    if(EAGINE_LIKELY(_backend->begin_message(
                         _source_id, _instance_id, _severity, fmt_str))) {
                        _backend->finish_message();
                        _backend = nullptr;
                    }
                }
            }
        } catch(...) {
        }
    }

private:
    friend class logger;

    stream_log_entry(
      identifier source_id,
      logger_instance_id instance_id,
      log_event_severity severity,
      logger_backend* backend) noexcept
      : _source_id{source_id}
      , _instance_id{instance_id}
      , _backend{backend}
      , _severity{severity} {
    }

    std::stringstream _out{};
    identifier _source_id{};
    logger_instance_id _instance_id{};
    logger_backend* _backend{nullptr};
    const log_event_severity _severity{log_event_severity::info};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_ENTRY_HPP
