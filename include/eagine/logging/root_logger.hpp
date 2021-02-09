/**
 *  @file eagine/logging/root_logger.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_LOGGING_ROOT_LOGGER_HPP
#define EAGINE_LOGGING_ROOT_LOGGER_HPP

#include "../program_args.hpp"
#include "logger.hpp"
#include "root_logger_opts.hpp"

namespace eagine {
//------------------------------------------------------------------------------
class root_logger : public logger {

    static auto _init_backend(const program_args&, const root_logger_options&)
      -> std::unique_ptr<logger_backend>;

    auto _log_git_info() -> void;
    auto _log_compiler_info() -> void;
    auto _log_args(const program_args&) -> void;

public:
    root_logger(
      identifier logger_id,
      const program_args& args,
      const root_logger_options& opts)
      : logger{logger_id, {_init_backend(args, opts)}} {
        _log_args(args);
        _log_git_info();
        _log_compiler_info();
    }

    root_logger(const program_args& args, const root_logger_options& opts)
      : root_logger(EAGINE_ID(RootLogger), args, opts) {}

    root_logger(const program_args& args)
      : root_logger(EAGINE_ID(RootLogger), args, root_logger_options{}) {}
};
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/logging/root_logger.inl>
#endif

#endif // EAGINE_LOGGING_ROOT_LOGGER_HPP
