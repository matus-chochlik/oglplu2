/**
 *  @file eagine/application/context.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/branch_predict.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto execution_context::prepare(std::unique_ptr<launchpad> pad)
  -> execution_context& {
    if(pad) {
        if(pad->setup(main_context(), _options)) {
            if(!(_app = pad->launch(main_context(), _options))) {
                log_error("failed to launch application");
            }
        } else {
            log_error("failed to setup application launchpad");
            _exec_result = 2;
        }
    } else {
        log_error("received invalid application launchpad");
        _exec_result = 1;
    }
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto execution_context::keep_running() noexcept -> bool {
    if(EAGINE_LIKELY(_app)) {
        return !_app->is_done();
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto execution_context::update() noexcept -> bool {
    return true;
}
//------------------------------------------------------------------------------
} // namespace eagine::application
