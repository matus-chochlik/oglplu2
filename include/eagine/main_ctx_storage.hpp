/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MAIN_CTX_STORAGE_HPP
#define EAGINE_MAIN_CTX_STORAGE_HPP

#include "application_config.hpp"
#include "build_info.hpp"
#include "compiler_info.hpp"
#include "compression.hpp"
#include "logging/root_logger.hpp"
#include "process.hpp"
#include "program_args.hpp"
#include "system_info.hpp"
#include "user_info.hpp"
#include "watchdog.hpp"

namespace eagine {
//------------------------------------------------------------------------------
class main_ctx_storage {
public:
    main_ctx_storage(
      int argc,
      const char** argv,
      const main_ctx_options& options) noexcept
      : _args{argc, argv}
      , _log_root{options.app_id, _args, options.logger_opts}
      , _bld_info{build_info::query()}
      , _watchdog{*this}
      , _app_config{*this}
      , _sys_info{*this}
      , _usr_info{*this}
      , _app_name{options.app_name} {
        auto fs_path = std::filesystem::path(to_string(_args.command()));
        if(_app_name.empty()) {
            _app_name = fs_path.stem().string();
        }
        _exe_path = fs_path.lexically_normal().string();

        _log_root.info("application ${appName} starting")
          .arg(EAGINE_ID(appName), _app_name)
          .arg(EAGINE_ID(exePath), _exe_path);
    }

    auto instance_id() const noexcept {
        return _instance_id;
    }

    auto args() noexcept -> auto& {
        return _args;
    }

    auto log() noexcept -> auto& {
        return _log_root;
    }

    auto watchdog() noexcept -> auto& {
        return _watchdog;
    }

    auto config() noexcept -> auto& {
        return _app_config;
    }

    auto compiler() noexcept -> auto& {
        return _cmplr_info;
    }

    auto build() noexcept -> auto& {
        return _bld_info;
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
        return {_exe_path};
    }

    auto app_name() const noexcept -> string_view {
        return {_app_name};
    }

private:
    const process_instance_id_t _instance_id{make_process_instance_id()};
    program_args _args;
    root_logger _log_root;
    compiler_info _cmplr_info;
    build_info _bld_info;
    process_watchdog _watchdog;
    application_config _app_config;
    system_info _sys_info;
    user_info _usr_info;
    memory::buffer _scratch_space{};
    data_compressor _compressor{};
    std::string _exe_path{};
    std::string _app_name{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif
