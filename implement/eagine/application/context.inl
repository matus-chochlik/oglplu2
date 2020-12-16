/**
 *  @file eagine/application/context.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
//
#include <oglplus/gl_api.hpp>
//
#include <eagine/application/input.hpp>
#include <eagine/application/opengl_glfw3.hpp>
#include <eagine/application/state.hpp>
#include <eagine/branch_predict.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// video_context
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto video_context::init_gl_api() noexcept -> bool {
    try {
        _gl_api = std::make_shared<oglp::gl_api>();
    } catch(...) {
    }
    return bool(_gl_api);
}
//------------------------------------------------------------------------------
// providers
//------------------------------------------------------------------------------
inline auto make_all_hmi_providers(main_ctx_parent parent)
  -> std::array<std::shared_ptr<hmi_provider>, 1> {
    return {{make_glfw3_opengl_provider(parent)}};
}
//------------------------------------------------------------------------------
// execution_context
//------------------------------------------------------------------------------
inline auto execution_context::_setup_providers() -> bool {
    auto try_init = [&](auto provider) -> bool {
        if(provider->is_initialized()) {
            return true;
        }
        if(provider->should_initialize(*this)) {
            if(provider->initialize(*this)) {
                return true;
            }
            log_error("failed to initialize HMI provider ${name}")
              .arg(EAGINE_ID(name), provider->implementation_name());
        } else {
            log_debug("skipping initialization of HMI provider ${name}")
              .arg(EAGINE_ID(name), provider->implementation_name());
        }
        return false;
    };

    for(auto& provider : _hmi_providers) {
        if(try_init(provider)) {
            _video_contexts.emplace_back(std::make_unique<video_context>(
              *this, extract(provider).video()));
        } else {
            return false;
        }
    }

    for(auto& provider : _hmi_providers) {
        if(try_init(provider)) {
            _audio_contexts.emplace_back(std::make_unique<audio_context>(
              *this, extract(provider).audio()));
        } else {
            return false;
        }
    }

    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto execution_context::state() const noexcept -> const context_state_view& {
    EAGINE_ASSERT(_state);
    return *_state;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto execution_context::prepare(std::unique_ptr<launchpad> pad)
  -> execution_context& {
    if(pad) {
        if(pad->setup(main_context(), _options)) {

            for(auto& provider : make_all_hmi_providers(*this)) {
                if(provider->is_implemented()) {
                    log_debug("using ${name} HMI provider")
                      .arg(EAGINE_ID(name), provider->implementation_name());
                    _hmi_providers.emplace_back(std::move(provider));
                } else {
                    log_debug("${name} HMI provider is not implemented")
                      .arg(EAGINE_ID(name), provider->implementation_name());
                }
            }

            if(_hmi_providers.empty()) {
                log_error("there are no available HMI providers");
                _exec_result = 5;
            } else {
                if(_setup_providers()) {
                    _state = std::make_shared<context_state>(*this);
                    EAGINE_ASSERT(_state);
                    if(!(_app = pad->launch(*this, _options))) {
                        log_error("failed to launch application");
                        _exec_result = 3;
                    }
                } else {
                    log_error("failed to setup providers");
                    _exec_result = 4;
                }
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
    if(EAGINE_LIKELY(_keep_running)) {
        if(EAGINE_LIKELY(_app)) {
            return !_app->is_done();
        }
    }
    return false;
}
//------------------------------------------------------------------------------
void execution_context::stop_running() noexcept {
    _keep_running = false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void execution_context::cleanup() noexcept {
    if(_app) {
        _app->cleanup();
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void execution_context::update() noexcept {
    for(auto& provider : _hmi_providers) {
        EAGINE_ASSERT(provider);
        provider->update(*this);
    }
    EAGINE_ASSERT(_state);
    _state->advance_frame().advance_time();
    EAGINE_ASSERT(_app);
    _app->update();
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
