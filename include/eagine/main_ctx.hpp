/// @file eagine/main_ctx.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MAIN_CTX_HPP
#define EAGINE_MAIN_CTX_HPP

#include "build_info.hpp"
#include "identifier_t.hpp"
#include "logging/logger.hpp"
#include "logging/root_logger_opts.hpp"
#include "memory/buffer_fwd.hpp"
#include "program_args.hpp"
#include "system_info.hpp"
#include "user_info.hpp"

namespace eagine {

struct main_ctx_options {
    std::string app_name{};
    identifier app_id{"RootLogger"};
    root_logger_options logger_opts{};
};

class data_compressor;
class process_watchdog;

class main_ctx {
private:
    process_instance_id_t _instance_id;
    program_args& _args;
    logger& _log;
    process_watchdog& _watchdog;
    application_config& _app_config;
    build_info& _bld_info;
    system_info& _sys_info;
    user_info& _usr_info;
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

    auto instance_id() const noexcept -> process_instance_id_t {
        return _instance_id;
    }

    auto preinitialize() noexcept -> main_ctx&;

    auto build() const noexcept -> const auto& {
        return _bld_info;
    }

    auto args() noexcept -> auto& {
        return _args;
    }

    auto log() noexcept -> auto& {
        return _log;
    }

    auto watchdog() noexcept -> auto& {
        return _watchdog;
    }

    auto config() noexcept -> auto& {
        return _app_config;
    }

    auto system() noexcept -> auto& {
        return _sys_info;
    }

    auto user() noexcept -> auto& {
        return _usr_info;
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

#if !EAGINE_IMPLEMENTING_LIBRARY
extern auto main_impl(int, const char**, const main_ctx_options&) -> int;
#endif

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/main_ctx.inl>
#endif

#endif // EAGINE_MAIN_CTX_HPP
