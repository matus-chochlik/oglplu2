/**
 *  @file eagine/main_ctx.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/logging/exception.hpp>
#include <eagine/logging/root_logger.hpp>

namespace eagine {
//------------------------------------------------------------------------------
class master_ctx {
private:
    program_args _args;
    root_logger _log_root;

public:
    master_ctx(
      int argc, const char** argv, const main_ctx_options& options) noexcept
      : _args{argc, argv}
      , _log_root{options.logger_id, _args, options.logger_opts} {
    }

    auto& args() noexcept {
        return _args;
    }

    logger& log() noexcept {
        return _log_root;
    }
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx::main_ctx(master_ctx& master) noexcept
  : _args{master.args()}
  , _log{master.log()} {
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
