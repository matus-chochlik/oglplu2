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
#include "memory/buffer_fwd.hpp"
#include "program_args.hpp"
#include "system_info.hpp"

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
    system_info& _sys_info;
    memory::buffer& _scratch_space;
    string_view _exe_path;

    static main_ctx*& _single_ptr() noexcept;

public:
    main_ctx(master_ctx&) noexcept;
    main_ctx(main_ctx&&) = delete;
    main_ctx(const main_ctx&) = delete;
    main_ctx& operator=(main_ctx&&) = delete;
    main_ctx& operator=(const main_ctx&) = delete;
    ~main_ctx() noexcept;

    static inline main_ctx& get() noexcept {
        EAGINE_ASSERT(_single_ptr());
        return *_single_ptr();
    }

    auto& args() noexcept {
        return _args;
    }

    logger& log() noexcept {
        return _log;
    }

    system_info& system() noexcept {
        return _sys_info;
    }

    memory::buffer& scratch_space() noexcept {
        return _scratch_space;
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
