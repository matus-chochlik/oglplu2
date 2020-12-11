/**
 *  @file eagine/application/context.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/application/opengl_glfw3.hpp>
#include <eagine/application/state.hpp>
#include <eagine/branch_predict.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
auto make_all_hmi_contexts() -> std::array<std::shared_ptr<hmi_context>, 1> {
    return {{make_glfw3_context()}};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto execution_context::prepare(std::unique_ptr<launchpad> pad)
  -> execution_context& {
    if(pad) {
        if(pad->setup(main_context(), _options)) {

            for(auto& hmi_ctx : make_all_hmi_contexts()) {
                if(hmi_ctx->is_implemented()) {
                    log_debug("using ${name} HMI context")
                      .arg(EAGINE_ID(name), hmi_ctx->implementation_name());
                    _hmi_contexts.emplace_back(std::move(hmi_ctx));
                } else {
                    log_debug("${name} HMI context is not implemented")
                      .arg(EAGINE_ID(name), hmi_ctx->implementation_name());
                }
            }

            if(_hmi_contexts.empty()) {
                log_error("there are no available HMI contexts");
                _exec_result = 4;
            } else if(!(_app = pad->launch(*this, _options))) {
                log_error("failed to launch application");
                _exec_result = 3;
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
auto execution_context::is_running() noexcept -> bool {
    if(EAGINE_LIKELY(_app)) {
        return !_app->is_done();
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void execution_context::stop_running() noexcept {
    EAGINE_ASSERT(_app);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void execution_context::update() noexcept {
    EAGINE_ASSERT(_app);
    _app->update(*this);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void execution_context::surface_size(int width, int height) {
    EAGINE_MAYBE_UNUSED(width);
    EAGINE_MAYBE_UNUSED(height);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void execution_context::pointer_position(float x, float y, int index) {
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    EAGINE_MAYBE_UNUSED(index);
}
//------------------------------------------------------------------------------
} // namespace eagine::application
