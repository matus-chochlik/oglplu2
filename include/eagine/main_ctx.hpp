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

#include "logging/logger.hpp"
#include "logging/root_logger_opts.hpp"
#include "program_args.hpp"

namespace eagine {

struct main_ctx_options {
    identifier logger_id{"RootLogger"};
    root_logger_options logger_opts{};
};

class master_ctx;

class main_ctx {
private:
    program_args& _args;
    logger& _log;
    string_view _exe_path;

public:
    main_ctx(master_ctx&) noexcept;

    auto& args() noexcept {
        return _args;
    }

    logger& log() noexcept {
        return _log;
    }

    string_view exe_path() const noexcept {
        return _exe_path;
    }
};

int main_impl(int, const char**, const main_ctx_options&);

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/main_ctx.inl>
#endif

#endif // EAGINE_MAIN_CTX_HPP
