/**
 *  @file eagine/logging/program_args.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_LOGGING_PROGRAM_ARGS_HPP
#define EAGINE_LOGGING_PROGRAM_ARGS_HPP

#include "../program_args.hpp"
#include "entry.hpp"

namespace eagine {
//------------------------------------------------------------------------------
static inline auto adapt_log_entry_arg(
  identifier name, const program_arg& value) {
    return [name, value](logger_backend& backend) {
        backend.add_string(name, EAGINE_ID(ProgramArg), string_view(value));
    };
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_PROGRAM_ARGS_HPP
