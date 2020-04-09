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

namespace eagine {
//------------------------------------------------------------------------------
class root_logger : public logger {
    static std::unique_ptr<logger_backend> _init_backend(const program_args&);

public:
    root_logger(identifier logger_id, const program_args& args)
      : logger{logger_id, _init_backend(args)} {
    }

    root_logger(const program_args& args)
      : root_logger(EAGINE_ID(RootLogger), args) {
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/logging/root_logger.inl>
#endif

#endif // EAGINE_LOGGING_ROOT_LOGGER_HPP
