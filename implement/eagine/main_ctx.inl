/**
 *  @file eagine/main_ctx.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/compression.hpp>
#include <eagine/logging/exception.hpp>
#include <eagine/logging/root_logger.hpp>
#include <eagine/memory/buffer.hpp>

namespace eagine {
//------------------------------------------------------------------------------
class master_ctx {
private:
    program_args _args;
    root_logger _log_root;
    system_info _sys_info{};
    memory::buffer _scratch_space{};
    data_compressor _compressor{};
    std::string _exe_path{};

public:
    master_ctx(
      int argc, const char** argv, const main_ctx_options& options) noexcept
      : _args{argc, argv}
      , _log_root{options.logger_id, _args, options.logger_opts} {
        // TODO: realpath
        _exe_path = to_string(_args.command());
    }

    auto& args() noexcept {
        return _args;
    }

    logger& log() noexcept {
        return _log_root;
    }

    system_info& system() noexcept {
        return _sys_info;
    }

    memory::buffer& scratch_space() noexcept {
        return _scratch_space;
    }

    data_compressor& compressor() noexcept {
        return _compressor;
    }

    string_view exe_path() const noexcept {
        return {_exe_path};
    }
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx*& main_ctx::_single_ptr() noexcept {
    static main_ctx* the_ptr{nullptr};
    return the_ptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx::main_ctx(master_ctx& master) noexcept
  : _args{master.args()}
  , _log{master.log()}
  , _sys_info{master.system()}
  , _scratch_space{master.scratch_space()}
  , _compressor{master.compressor()}
  , _exe_path{master.exe_path()} {
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
extern int main(main_ctx& ctx);
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
int main_impl(int argc, const char** argv, const main_ctx_options& options) {
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
