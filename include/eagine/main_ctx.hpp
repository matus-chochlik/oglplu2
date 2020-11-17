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
#include "tribool.hpp"

namespace eagine {

struct main_ctx_options {
    std::string app_name{};
    identifier app_id{"RootLogger"};
    root_logger_options logger_opts{};
};

class master_ctx;
class data_compressor;
class application_config;

class main_ctx {
private:
    program_args& _args;
    logger& _log;
    application_config& _app_config;
    system_info& _sys_info;
    memory::buffer& _scratch_space;
    data_compressor& _compressor;
    string_view _exe_path;
    string_view _app_name;

    static auto _single_ptr() noexcept -> main_ctx*&;

public:
    main_ctx(master_ctx&) noexcept;
    main_ctx(main_ctx&&) = delete;
    main_ctx(const main_ctx&) = delete;
    auto operator=(main_ctx&&) = delete;
    auto operator=(const main_ctx&) = delete;
    ~main_ctx() noexcept;

    static inline auto get() noexcept -> main_ctx& {
        EAGINE_ASSERT(_single_ptr());
        return *_single_ptr();
    }

    auto version() noexcept -> optionally_valid<std::tuple<int, int, int, int>>;

    auto version_at_least(int major, int minor, int patch = 0, int commit = 0)
      -> tribool {
        if(const auto opt_ver{version()}) {
            return extract(opt_ver) >=
                   std::make_tuple(major, minor, patch, commit);
        }
        return indeterminate;
    }

    auto args() noexcept -> auto& {
        return _args;
    }

    auto log() noexcept -> auto& {
        return _log;
    }

    auto config() noexcept -> auto& {
        return _app_config;
    }

    auto system() noexcept -> auto& {
        return _sys_info;
    }

    auto scratch_space() noexcept -> auto& {
        return _scratch_space;
    }

    auto compressor() noexcept -> auto& {
        return _compressor;
    }

    auto exe_path() const noexcept -> string_view {
        return _exe_path;
    }

    auto app_name() const noexcept -> string_view {
        return _app_name;
    }
};

auto main_impl(int, const char**, const main_ctx_options&) -> int;

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/main_ctx.inl>
#endif

#endif // EAGINE_MAIN_CTX_HPP
