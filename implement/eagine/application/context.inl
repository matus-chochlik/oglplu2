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
inline auto execution_context::_setup_contexts() -> bool {
    auto try_init = [&](auto hmi_ctx) -> bool {
        if(hmi_ctx->is_initialized()) {
            return true;
        }
        if(hmi_ctx->initialize(*this)) {
            return true;
        }
        log_error("failed to initialize HMI context ${name}")
          .arg(EAGINE_ID(name), hmi_ctx->implementation_name());
        return false;
    };

    if(auto video_kind{_options.required_video_kind()}) {
        for(auto& hmi_ctx : _hmi_contexts) {
            if(auto video_ctx{hmi_ctx->video()}) {
                if(extract(video_ctx).video_kind() == extract(video_kind)) {
                    if(try_init(hmi_ctx)) {
                        _video_contexts.emplace_back(std::move(video_ctx));
                    } else {
                        return false;
                    }
                }
            }
        }
    }

    if(auto audio_kind{_options.required_audio_kind()}) {
        for(auto& hmi_ctx : _hmi_contexts) {
            if(auto audio_ctx{hmi_ctx->audio()}) {
                if(extract(audio_ctx).audio_kind() == extract(audio_kind)) {
                    if(try_init(hmi_ctx)) {
                        _audio_contexts.emplace_back(std::move(audio_ctx));
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
auto execution_context::_get_video(span_size_t index) noexcept
  -> video_context& {
    EAGINE_ASSERT(index < span_size(_video_contexts.size()));
    return *_video_contexts[std_size(index)];
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
                _exec_result = 5;
            } else {
                if(_setup_contexts()) {
                    if(!(_app = pad->launch(*this, _options))) {
                        log_error("failed to launch application");
                        _exec_result = 3;
                    }
                } else {
                    log_error("failed to setup contexts");
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
void execution_context::video_begin(span_size_t ctx_index) {
    _get_video(ctx_index).video_begin(*this);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void execution_context::video_end(span_size_t ctx_index) {
    _get_video(ctx_index).video_end(*this);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void execution_context::video_commit(span_size_t ctx_index) {
    _get_video(ctx_index).video_commit(*this);
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
