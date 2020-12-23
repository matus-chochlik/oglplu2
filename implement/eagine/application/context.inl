/**
 *  @file eagine/application/context.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oalplus/al.hpp>
//
#include <oglplus/gl_api.hpp>
#include <oalplus/al_api.hpp>
//
#include <eagine/application/input.hpp>
#include <eagine/application/opengl_glfw3.hpp>
#include <eagine/application/state.hpp>
#include <eagine/branch_predict.hpp>
#include <eagine/memory/buffer.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// video_context
//------------------------------------------------------------------------------
class video_context_state {
    static auto _get_options(
      const execution_context& ctx,
      string_view instance_name) noexcept -> const video_options& {
        auto& opts = ctx.options();
        auto pos = opts.video_requirements().find(instance_name);
        EAGINE_ASSERT(pos != opts.video_requirements().end());
        return pos->second;
    }

public:
    video_context_state(
      const execution_context& ctx,
      string_view instance_name) noexcept
      : _options{_get_options(ctx, instance_name)} {}

    auto init_framebuffer(execution_context&, oglp::gl_api&) noexcept -> bool {
        if(_options.needs_offscreen_framebuffer()) {
            // TODO: check options and make RBOs and FBO
        }
        return true;
    }

    void commit(oglp::gl_api&) noexcept {
        if(_options.framedump_color()) {
        }
    }

    void cleanup(oglp::gl_api& api) noexcept {
        if(_offscreen_fbo) {
            api.delete_framebuffers(std::move(_offscreen_fbo));
        }
        if(_stencil_rbo) {
            api.delete_renderbuffers(std::move(_stencil_rbo));
        }
        if(_depth_rbo) {
            api.delete_renderbuffers(std::move(_depth_rbo));
        }
        if(_color_rbo) {
            api.delete_renderbuffers(std::move(_color_rbo));
        }
    }

private:
    const video_options& _options;
    oglp::owned_renderbuffer_name _color_rbo;
    oglp::owned_renderbuffer_name _depth_rbo;
    oglp::owned_renderbuffer_name _stencil_rbo;
    oglp::owned_framebuffer_name _offscreen_fbo;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto video_context::init_gl_api() noexcept -> bool {
    try {
        EAGINE_ASSERT(_provider);
        _gl_api = std::make_shared<oglp::gl_api>();
        _state = std::make_shared<video_context_state>(
          _parent, extract(_provider).instance_name());

        if(!extract(_provider).has_framebuffer()) {
            if(!extract(_state).init_framebuffer(_parent, extract(_gl_api))) {
                _parent.log_error("failed to create offscreen framebuffer");
                return false;
            }
        }
    } catch(...) {
        return false;
    }
    return bool(_gl_api);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void video_context::begin() {
    EAGINE_ASSERT(_provider);
    _provider->video_begin(_parent);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void video_context::end() {
    EAGINE_ASSERT(_provider);
    _provider->video_end(_parent);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void video_context::commit() {
    EAGINE_ASSERT(_provider);
    if(EAGINE_LIKELY(_gl_api)) {
        EAGINE_ASSERT(_state);
        _state->commit(extract(_gl_api));
    }
    _provider->video_commit(_parent);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void video_context::cleanup() noexcept {
    try {
        if(_state) {
            EAGINE_ASSERT(_gl_api);
            extract(_state).cleanup(extract(_gl_api));
            _state.reset();
        }
    } catch(...) {
    }
}
//------------------------------------------------------------------------------
// audio_context
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto audio_context::init_al_api() noexcept -> bool {
    try {
        _al_api = std::make_shared<oalp::al_api>();
    } catch(...) {
    }
    return bool(_al_api);
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

    for(auto& video_opts : _options._video_opts) {
        // TODO: proper provider selection
        if(video_opts.second._provider_name.empty()) {
            video_opts.second._provider_name = "GLFW3";
        }
    }

    for(auto& provider : _hmi_providers) {
        if(try_init(provider)) {
            if(auto video{extract(provider).video()}) {
                _video_contexts.emplace_back(
                  std::make_unique<video_context>(*this, std::move(video)));
                continue;
            }
        }
        return false;
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
    for(auto& video : _video_contexts) {
        EAGINE_ASSERT(video);
        video->cleanup();
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
