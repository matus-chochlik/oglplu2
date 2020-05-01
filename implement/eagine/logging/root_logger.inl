/**
 *  @file eagine/logging/root_logger.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/logging/asio_backend.hpp>
#include <eagine/logging/null_backend.hpp>
#include <eagine/logging/ostream_backend.hpp>
#include <cerrno>
#include <iostream>

namespace eagine {
//------------------------------------------------------------------------------
static constexpr inline log_event_severity default_log_severity() noexcept {
    return static_cast<log_event_severity>(
      static_cast<std::underlying_type_t<log_event_severity>>(
        log_event_severity::EAGINE_MIN_LOG_SEVERITY) +
      1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::unique_ptr<logger_backend> root_logger_choose_backend(
  const program_args& args,
  const root_logger_options& opts,
  log_event_severity min_severity) {
    std::unique_ptr<logger_backend> result{};

    for(auto& arg : args) {
        if(arg.is_tag("--use-null-log")) {
            return std::make_unique<null_log_backend>();
        } else if(arg.is_tag("--use-cerr-log")) {
            return std::make_unique<ostream_log_backend<>>(
              std::cerr, min_severity);
        } else if(arg.is_tag("--use-cout-log")) {
            return std::make_unique<ostream_log_backend<>>(
              std::cout, min_severity);
#if EAGINE_HAS_ASIO_LOG_BACKEND
        } else if(arg.is_tag("--use-asio-log")) {
            return std::make_unique<asio_ostream_log_backend<>>(min_severity);
#endif
        }
    }

    if(opts.default_no_log) {
        return std::make_unique<null_log_backend>();
    }

#if EAGINE_DEBUG
#if EAGINE_HAS_ASIO_LOG_BACKEND
    try {
        return std::make_unique<asio_ostream_log_backend<>>(min_severity);
    } catch(std::system_error& err) {
        if(err.code().value() != ENOENT) {
            throw;
        }
    }
#endif
#endif

    return std::make_unique<ostream_log_backend<>>(std::clog, min_severity);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::unique_ptr<logger_backend> root_logger::_init_backend(
  const program_args& args, const root_logger_options& opts) {
    auto min_severity{default_log_severity()};

    for(auto arg = args.first(); arg; arg = arg.next()) {
        if(arg.is_tag("--min-log-severity")) {
            if(arg.next().parse(min_severity, std::cerr)) {
                arg = arg.next();
            }
        }
    }

    auto backend = root_logger_choose_backend(args, opts, min_severity);

    return backend;
}
//------------------------------------------------------------------------------
} // namespace eagine
