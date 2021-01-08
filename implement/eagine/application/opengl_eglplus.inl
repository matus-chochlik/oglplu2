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
#include <eagine/valid_if/decl.hpp>
#include <oglplus/config/basic.hpp>

#include <eglplus/egl.hpp>
#include <eglplus/egl_api.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// surface
//------------------------------------------------------------------------------
class eglplus_opengl_surface
  : public main_ctx_object
  , public video_provider {
public:
    eglplus_opengl_surface(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(EGLPbuffer), parent} {}

    auto initialize(
      execution_context&,
      eglp::egl_api& egl,
      string_view name,
      const launch_options&,
      const video_options&) -> bool;

    void cleanup(eglp::egl_api& egl);

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
    optionally_valid<eglp::egl_types::display_type> _display{};
    int _width{1};
    int _height{1};
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::initialize(
  execution_context& exec_ctx,
  eglp::egl_api& egl,
  string_view name,
  const launch_options&,
  const video_options&) -> bool {

    if(ok display{egl.get_display()}) {
        if(ok initialized{egl.initialize(display)}) {
            _display = {display, true};
            EAGINE_MAYBE_UNUSED(name);
            // TODO
            // return true;
        } else {
            exec_ctx.log_error("failed to initialize EGL display")
              .arg(EAGINE_ID(message), (!display).message());
        }
    } else {
        exec_ctx.log_error("failed to get EGL display")
          .arg(EAGINE_ID(message), (!display).message());
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_surface::cleanup(eglp::egl_api& egl) {
    if(_display) {
        egl.terminate(extract(_display));
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::video_kind() const noexcept -> video_context_kind {
    return video_context_kind::opengl;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::instance_name() const noexcept -> string_view {
    return _instance_name;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::is_offscreen() noexcept -> tribool {
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::has_framebuffer() noexcept -> tribool {
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_surface::surface_size() noexcept -> std::tuple<int, int> {
    return {_width, _height};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_surface::video_begin(execution_context&) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_surface::video_end(execution_context&) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_surface::video_commit(execution_context&) {}
//------------------------------------------------------------------------------
// provider
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
    eglp::egl_api _egl;

    std::map<
      std::string,
      std::shared_ptr<eglplus_opengl_surface>,
      basic_str_view_less<std::string, string_view>>
      _surfaces;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::is_implemented() const noexcept -> bool {
    return _egl.get_display && _egl.initialize && _egl.terminate &&
           _egl.get_configs && _egl.choose_config && _egl.get_config_attrib &&
           _egl.query_string && _egl.swap_buffers;
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
    return !_surfaces.empty();
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
    if(_egl.get_display) {
        auto& options = exec_ctx.options();
        for(auto& [name, video_opts] : options.video_requirements()) {
            const bool should_create_surface =
              video_opts.has_provider(implementation_name()) &&
              (video_opts.video_kind() == video_context_kind::opengl);

            if(should_create_surface) {
                if(auto surface{
                     std::make_shared<eglplus_opengl_surface>(*this)}) {
                    if(extract(surface).initialize(
                         exec_ctx, _egl, name, options, video_opts)) {
                        _surfaces[name] = std::move(surface);
                    } else {
                        extract(surface).cleanup(_egl);
                    }
                }
            }
        }
        return true;
    }
    exec_ctx.log_error("EGL is context is not supported");
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_provider::update(execution_context&) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void eglplus_opengl_provider::cleanup(execution_context&) {
    for(auto& entry : _surfaces) {
        entry.second->cleanup(_egl);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::input() -> std::shared_ptr<input_provider> {
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto eglplus_opengl_provider::video(string_view name)
  -> std::shared_ptr<video_provider> {
    auto pos = _surfaces.find(name);
    if(pos != _surfaces.end()) {
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
