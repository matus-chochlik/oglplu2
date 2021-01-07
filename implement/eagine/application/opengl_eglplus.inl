/**
 *  @file eagine/application/opengl_eglplus.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/application/context.hpp>
#include <eagine/maybe_unused.hpp>
#include <oglplus/config/basic.hpp>

#include <eglplus/egl.hpp>
#include <eglplus/egl_api.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
class eglplus_opengl_pbuffer
  : public main_ctx_object
  , public video_provider {
public:
    eglplus_opengl_pbuffer(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(EGLPbuffer), parent} {}

    auto video_kind() const noexcept -> video_context_kind final;
    auto instance_name() const noexcept -> string_view final;

    auto is_offscreen() noexcept -> tribool final;
    auto has_framebuffer() noexcept -> tribool final;
    auto surface_size() noexcept -> std::tuple<int, int> final;

    void video_begin(execution_context&) final;
    void video_end(execution_context&) final;
    void video_commit(execution_context&) final;

private:
    string_view _instance_name;
    int _width{1};
    int _height{1};
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_pbuffer::video_kind() const noexcept -> video_context_kind {
    return video_context_kind::opengl;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_pbuffer::instance_name() const noexcept -> string_view {
    return _instance_name;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_pbuffer::is_offscreen() noexcept -> tribool {
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_pbuffer::has_framebuffer() noexcept -> tribool {
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_pbuffer::surface_size() noexcept -> std::tuple<int, int> {
    return {_width, _height};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_pbuffer::video_begin(execution_context&) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_pbuffer::video_end(execution_context&) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_pbuffer::video_commit(execution_context&) {}
//------------------------------------------------------------------------------
class eglplus_opengl_provider
  : public main_ctx_object
  , public hmi_provider {
public:
    eglplus_opengl_provider(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(GLFW3Prvdr), parent} {}

    auto is_implemented() const noexcept -> bool final;
    auto implementation_name() const noexcept -> string_view final;

    auto is_initialized() -> bool final;
    auto should_initialize(execution_context&) -> bool final;
    auto initialize(execution_context&) -> bool final;
    void update(execution_context&) final;
    void cleanup(execution_context&) final;

    auto input() -> std::shared_ptr<input_provider> final;
    auto video(string_view) -> std::shared_ptr<video_provider> final;
    auto audio(string_view) -> std::shared_ptr<audio_provider> final;

private:
    std::map<
      std::string,
      std::shared_ptr<eglplus_opengl_pbuffer>,
      basic_str_view_less<std::string, string_view>>
      _pbuffers;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::is_implemented() const noexcept -> bool {
    // TODO
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::implementation_name() const noexcept
  -> string_view {
    return {"eglplus"};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::is_initialized() -> bool {
    return !_pbuffers.empty();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::should_initialize(execution_context& exec_ctx)
  -> bool {
    for(auto& [name, video_opts] : exec_ctx.options().video_requirements()) {
        EAGINE_MAYBE_UNUSED(name);
        if(video_opts.has_provider(implementation_name())) {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::initialize(execution_context& exec_ctx) -> bool {
    EAGINE_MAYBE_UNUSED(exec_ctx);
    exec_ctx.log_error("eglplus is context is not supported");
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_provider::update(execution_context&) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_provider::cleanup(execution_context&) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::input() -> std::shared_ptr<input_provider> {
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::video(string_view name)
  -> std::shared_ptr<video_provider> {
    auto pos = _pbuffers.find(name);
    if(pos != _pbuffers.end()) {
        return {pos->second};
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::audio(string_view)
  -> std::shared_ptr<audio_provider> {
    return {};
}
//------------------------------------------------------------------------------
auto make_eglplus_opengl_provider(main_ctx_parent parent)
  -> std::shared_ptr<hmi_provider> {
    return {std::make_shared<eglplus_opengl_provider>(parent)};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
