/**
 *  @file eagine/main_ctx.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/application_config.hpp>
#include <eagine/compression.hpp>
#include <eagine/logging/root_logger.hpp>
#include <eagine/logging/type/exception.hpp>
#include <eagine/memory/buffer.hpp>
#include <eagine/process.hpp>
#include <eagine/watchdog.hpp>
#include <filesystem>

namespace eagine {
//------------------------------------------------------------------------------
class master_ctx {
private:
    const process_instance_id_t _instance_id{make_process_instance_id()};
    program_args _args;
    root_logger _log_root;
    build_info _bld_info;
    process_watchdog _watchdog;
    application_config _app_config;
    system_info _sys_info;
    user_info _usr_info;
    memory::buffer _scratch_space{};
    data_compressor _compressor{};
    std::string _exe_path{};
    std::string _app_name{};

public:
    master_ctx(
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
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_ctx::_single_ptr() noexcept -> main_ctx*& {
    static main_ctx* the_ptr{nullptr};
    return the_ptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx::main_ctx(master_ctx& master) noexcept
  : _instance_id{master.instance_id()}
  , _args{master.args()}
  , _log{master.log()}
  , _watchdog{master.watchdog()}
  , _app_config{master.config()}
  , _bld_info{master.build()}
  , _sys_info{master.system()}
  , _usr_info{master.user()}
  , _scratch_space{master.scratch_space()}
  , _compressor{master.compressor()}
  , _exe_path{master.exe_path()}
  , _app_name{master.app_name()} {
    EAGINE_ASSERT(!_single_ptr());
    _single_ptr() = this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx::~main_ctx() noexcept {
    EAGINE_ASSERT(_single_ptr());
    _single_ptr() = nullptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_ctx::preinitialize() noexcept -> main_ctx& {
    _sys_info.preinitialize();
    return *this;
}
//------------------------------------------------------------------------------
// main_ctx_object-related
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx_log_backend_getter::main_ctx_log_backend_getter(master_ctx& c) noexcept
  : _backend{c.log().backend()} {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx_log_backend_getter::main_ctx_log_backend_getter() noexcept
  : _backend{main_ctx::get().log().backend()} {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_ctx_object::main_context() const noexcept -> main_ctx& {
    return main_ctx::get();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_ctx_object::process_instance_id() const noexcept
  -> process_instance_id_t {
    return main_context().instance_id();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_ctx_object::app_config() const noexcept -> application_config& {
    return main_context().config();
}
//------------------------------------------------------------------------------
// main
//------------------------------------------------------------------------------
extern auto main(main_ctx& ctx) -> int;
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_impl(int argc, const char** argv, const main_ctx_options& options)
  -> int {
    master_ctx master{argc, argv, options};
    main_ctx ctx{master};
    try {
        return eagine::main(ctx);
    } catch(std::system_error& sys_err) {
        ctx.log()
          .error("unhandled system error: ${error}")
          .arg(EAGINE_ID(error), sys_err);
    } catch(std::exception& err) {
        ctx.log()
          .error("unhandled generic error: ${error}")
          .arg(EAGINE_ID(error), err);
    }
    return 1;
}
//------------------------------------------------------------------------------
} // namespace eagine
