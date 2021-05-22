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
#include "message_bus.hpp"
#include "process.hpp"
#include "program_args.hpp"
#include "system_info.hpp"
#include "user_info.hpp"
#include "watchdog.hpp"

namespace eagine {
//------------------------------------------------------------------------------
class main_ctx_storage : public main_ctx_getters {
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
      , _msg_bus{*this}
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

    auto preinitialize() noexcept -> main_ctx_storage& final {
        _sys_info.preinitialize();
        return *this;
    }

    auto instance_id() const noexcept -> process_instance_id_t final {
        return _instance_id;
    }

    auto args() const noexcept -> const program_args& final {
        return _args;
    }

    auto log() noexcept -> logger& final {
        return _log_root;
    }

    auto watchdog() noexcept -> process_watchdog& final {
        return _watchdog;
    }

    auto config() noexcept -> application_config& final {
        return _app_config;
    }

    auto compiler() const noexcept -> const compiler_info& final {
        return _cmplr_info;
    }

    auto build() const noexcept -> const build_info& final {
        return _bld_info;
    }

    auto system() noexcept -> system_info& final {
        return _sys_info;
    }

    auto user() noexcept -> user_info& final {
        return _usr_info;
    }

    auto bus() noexcept -> message_bus& final {
        return _msg_bus;
    }

    auto compressor() noexcept -> data_compressor& final {
        return _compressor;
    }

    auto scratch_space() noexcept -> memory::buffer& final {
        return _scratch_space;
    }

    auto exe_path() const noexcept -> string_view final {
        return {_exe_path};
    }

    auto app_name() const noexcept -> string_view final {
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
    message_bus _msg_bus;
    memory::buffer _scratch_space{};
    data_compressor _compressor{};
    std::string _exe_path{};
    std::string _app_name{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif
