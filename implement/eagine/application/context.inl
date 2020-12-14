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
inline auto make_all_hmi_providers()
  -> std::array<std::shared_ptr<hmi_provider>, 1> {
    return {{make_glfw3_opengl_provider()}};
}
//------------------------------------------------------------------------------
// execution_context
//------------------------------------------------------------------------------
inline auto execution_context::_setup_providers() -> bool {
    auto try_init = [&](auto provider) -> bool {
        if(provider->is_initialized()) {
            return true;
        }
        if(provider->initialize(*this)) {
            return true;
        }
        log_error("failed to initialize HMI provider ${name}")
          .arg(EAGINE_ID(name), provider->implementation_name());
        return false;
    };

    if(auto video_kind{_options.required_video_kind()}) {
        for(auto& provider : _hmi_providers) {
            if(auto video_ctx{provider->video()}) {
                if(extract(video_ctx).video_kind() == extract(video_kind)) {
                    if(try_init(provider)) {
                        _video_contexts.emplace_back(
                          std::make_unique<video_context>(
                            *this, std::move(video_ctx)));
                    } else {
                        return false;
                    }
                }
            }
        }
    }

    if(auto audio_kind{_options.required_audio_kind()}) {
        for(auto& provider : _hmi_providers) {
            if(auto audio_ctx{provider->audio()}) {
                if(extract(audio_ctx).audio_kind() == extract(audio_kind)) {
                    if(try_init(provider)) {
                        _audio_contexts.emplace_back(
                          std::make_unique<audio_context>(
                            *this, std::move(audio_ctx)));
                    } else {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto execution_context::prepare(std::unique_ptr<launchpad> pad)
  -> execution_context& {
    if(pad) {
        if(pad->setup(main_context(), _options)) {

            for(auto& provider : make_all_hmi_providers()) {
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
    EAGINE_ASSERT(_app);
    _app->cleanup();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void execution_context::update() noexcept {
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
