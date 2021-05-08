/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/logging/type/exception.hpp>
#include <eagine/main_ctx.hpp>
#include <eagine/main_ctx_storage.hpp>

namespace eagine {
//------------------------------------------------------------------------------
// main
//------------------------------------------------------------------------------
extern auto main(main_ctx& ctx) -> int;
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_impl(int argc, const char** argv, const main_ctx_options& options)
  -> int {
    main_ctx_storage storage{argc, argv, options};
    main_ctx ctx{storage};
    try {
        return eagine::main(ctx);
    } catch(const std::system_error& sys_err) {
        ctx.log()
          .error("unhandled system error: ${error}")
          .arg(EAGINE_ID(error), sys_err);
    } catch(const std::exception& err) {
        ctx.log()
          .error("unhandled generic error: ${error}")
          .arg(EAGINE_ID(error), err);
    }
    return 1;
}
//------------------------------------------------------------------------------
} // namespace eagine
