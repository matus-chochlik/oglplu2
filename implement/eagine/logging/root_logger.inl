/**
 *  @file eagine/logging/root_logger.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/logging/null_backend.hpp>
#include <eagine/logging/ostream_backend.hpp>
#include <iostream>

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::unique_ptr<logger_backend> root_logger_choose_backend(
  const program_args& args, log_event_severity min_severity) {
    std::unique_ptr<logger_backend> result{};

    for(auto& arg : args) {
        if(arg.is_tag("--use-null-log")) {
            result = std::make_unique<null_log_backend>();
        } else if(arg.is_tag("--use-cerr-log")) {
            result =
              std::make_unique<ostream_log_backend<>>(std::cerr, min_severity);
        } else if(arg.is_tag("--use-cout-log")) {
            result =
              std::make_unique<ostream_log_backend<>>(std::cout, min_severity);
        }
    }

    if(!result) {
        result =
          std::make_unique<ostream_log_backend<>>(std::clog, min_severity);
    }

    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::unique_ptr<logger_backend> root_logger::_init_backend(
  const program_args& args) {
    auto min_severity{log_event_severity::info};

    for(auto arg = args.first(); arg; arg = arg.next()) {
        if(arg.is_tag("--min-log-severity")) {
            if(arg.next().parse(min_severity, std::cerr)) {
                arg = arg.next();
            }
        }
    }

    auto backend = root_logger_choose_backend(args, min_severity);

    return backend;
}
//------------------------------------------------------------------------------
} // namespace eagine
