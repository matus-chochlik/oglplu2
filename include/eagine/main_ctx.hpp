/**
 *  @file eagine/main_ctx.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MAIN_CTX_HPP
#define EAGINE_MAIN_CTX_HPP

#include "logging/root_logger.hpp"
#include "program_args.hpp"

namespace eagine {

class main_ctx {
private:
    program_args _args;
    root_logger _log_root;

public:
    main_ctx(int argc, const char** argv) noexcept
      : _args{argc, argv}
      , _log_root{_args} {
    }

    auto& args() noexcept {
        return _args;
    }

    logger& log() noexcept {
        return _log_root;
    }
};

} // namespace eagine

#endif // EAGINE_MAIN_CTX_HPP
