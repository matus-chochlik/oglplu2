/**
 *  @file eagine/application/opengl_glfw3.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine::application {

#include <eagine/application/context.hpp>
#include <eagine/maybe_unused.hpp>
#include <oglplus/config/basic.hpp>

#if OGLPLUS_GLFW3_FOUND

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#endif
#include <GLFW/glfw3.h>
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // OGLPLUS_GLFW3_FOUND
//------------------------------------------------------------------------------
#if OGLPLUS_GLFW3_FOUND
class glfw3_opengl_window
  : public main_ctx_object
  , public video_provider
  , public input_provider {
public:
    glfw3_opengl_window(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(GLFW3Wndow), parent} {}

    auto initialize(
      string_view name,
      const launch_options&,
      const video_options&,
      span<GLFWmonitor* const>) -> bool;
    void update(execution_context& exec_ctx);
    void cleanup();

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
    GLFWwindow* _window{nullptr};
    double _mouse_x{0};
    double _mouse_y{0};
    int _window_width{1};
    int _window_height{1};
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_window::initialize(
  string_view name,
  const launch_options& options,
  const video_options& video_opts,
  span<GLFWmonitor* const> monitors) -> bool {
    _instance_name = name;

    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
    glfwWindowHint(GLFW_RED_BITS, video_opts.color_bits());
    glfwWindowHint(GLFW_BLUE_BITS, video_opts.color_bits());
    glfwWindowHint(GLFW_GREEN_BITS, video_opts.color_bits());
    glfwWindowHint(GLFW_ALPHA_BITS, video_opts.alpha_bits());
    glfwWindowHint(GLFW_DEPTH_BITS, video_opts.depth_bits());
    glfwWindowHint(GLFW_STENCIL_BITS, video_opts.stencil_bits());

    glfwWindowHint(GLFW_SAMPLES, video_opts.samples() / GLFW_DONT_CARE);

    GLFWmonitor* window_monitor = nullptr;
    int fallback_width = 1280, fallback_height = 800;
    if(video_opts.fullscreen()) {
        window_monitor = glfwGetPrimaryMonitor();
        if(auto opt_mon_name{video_opts.monitor_name()}) {
            for(auto monitor : monitors) {
                string_view mon_name(glfwGetMonitorName(monitor));
                if(are_equal(extract(opt_mon_name), mon_name)) {
                    window_monitor = monitor;
                }
            }
        }
    }
    if(auto mode{glfwGetVideoMode(
         window_monitor ? window_monitor : glfwGetPrimaryMonitor())}) {
        fallback_width = extract(mode).width;
        fallback_height = extract(mode).height;
    }

    if(video_opts.offscreen()) {
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    }

    _window = glfwCreateWindow(
      video_opts.surface_width() / fallback_width,
      video_opts.surface_height() / fallback_height,
      c_str(options.application_title()),
      window_monitor,
      nullptr);

    if(_window) {
        glfwSetWindowTitle(_window, c_str(options.application_title()));
        return true;
    } else {
        log_error("Failed to create GLFW window").arg(EAGINE_ID(name), name);
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_window::video_kind() const noexcept -> video_context_kind {
    return video_context_kind::opengl;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_window::instance_name() const noexcept -> string_view {
    return _instance_name;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_window::is_offscreen() noexcept -> tribool {
    if(_window) {
        return glfwGetWindowAttrib(_window, GLFW_VISIBLE) == 0;
    }
    return indeterminate;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_window::has_framebuffer() noexcept -> tribool {
    if(_window) {
        return glfwGetWindowAttrib(_window, GLFW_VISIBLE) != 0;
    }
    return indeterminate;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_window::surface_size() noexcept -> std::tuple<int, int> {
    return {_window_width, _window_height};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_window::video_begin(execution_context&) {

    EAGINE_ASSERT(_window);
    glfwMakeContextCurrent(_window);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_window::video_end(execution_context&) {
    glfwMakeContextCurrent(nullptr);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_window::video_commit(execution_context&) {
    EAGINE_ASSERT(_window);
    glfwSwapBuffers(_window);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_window::update(execution_context& exec_ctx) {

    if(glfwWindowShouldClose(_window)) {
        exec_ctx.stop_running();
    } else {
        glfwGetWindowSize(_window, &_window_width, &_window_height);

        glfwGetCursorPos(_window, &_mouse_x, &_mouse_y);
        exec_ctx.pointer_position(float(_mouse_x), float(_mouse_y), 0);
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_window::cleanup() {
    if(_window) {
        glfwDestroyWindow(_window);
    }
}
#endif // OGLPLUS_GLFW3_FOUND
//------------------------------------------------------------------------------
class glfw3_opengl_provider
  : public main_ctx_object
  , public hmi_provider {
public:
    glfw3_opengl_provider(main_ctx_parent parent)
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
#if OGLPLUS_GLFW3_FOUND
    std::map<
      std::string,
      std::shared_ptr<glfw3_opengl_window>,
      basic_str_view_less<std::string, string_view>>
      _windows;
#endif
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::is_implemented() const noexcept -> bool {
    return OGLPLUS_GLFW3_FOUND != 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::implementation_name() const noexcept
  -> string_view {
    return {"GLFW3"};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::is_initialized() -> bool {
#if OGLPLUS_GLFW3_FOUND
    return !_windows.empty();
#endif
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::should_initialize(execution_context& exec_ctx)
  -> bool {
    EAGINE_MAYBE_UNUSED(exec_ctx);
#if OGLPLUS_GLFW3_FOUND
    for(auto& [name, video_opts] : exec_ctx.options().video_requirements()) {
        EAGINE_MAYBE_UNUSED(name);
        if(video_opts.has_provider(implementation_name())) {
            return true;
        }
    }
#endif
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::initialize(execution_context& exec_ctx) -> bool {
    EAGINE_MAYBE_UNUSED(exec_ctx);
#if OGLPLUS_GLFW3_FOUND
    if(glfwInit()) {
        auto monitors = []() {
            int monitor_count = 0;
            auto* monitor_list = glfwGetMonitors(&monitor_count);
            return memory::view(monitor_list, monitor_count);
        }();

        log_info("GLFW monitors").arg_func([monitors](logger_backend& backend) {
            for(auto monitor : monitors) {
                backend.add_string(
                  EAGINE_ID(monitors),
                  EAGINE_ID(string),
                  string_view(glfwGetMonitorName(monitor)));
            }
        });

        auto& options = exec_ctx.options();
        for(auto& [name, video_opts] : options.video_requirements()) {
            const bool should_create_window =
              video_opts.has_provider(implementation_name()) &&
              (video_opts.video_kind() == video_context_kind::opengl);

            if(should_create_window) {
                if(auto new_win{std::make_shared<glfw3_opengl_window>(*this)}) {
                    if(extract(new_win).initialize(
                         name, options, video_opts, monitors)) {
                        _windows[name] = std::move(new_win);
                    }
                }
            }
        }
        return true;
    } else {
        exec_ctx.log_error("GLFW initialization error");
    }
#endif // OGLPLUS_GLFW3_FOUND
    exec_ctx.log_error("GLFW is context is not supported");
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_provider::update(execution_context& exec_ctx) {
    EAGINE_MAYBE_UNUSED(exec_ctx);
#if OGLPLUS_GLFW3_FOUND
    glfwPollEvents();
    for(auto& win : _windows) {
        win.second->update(exec_ctx);
    }
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_provider::cleanup(execution_context&) {
#if OGLPLUS_GLFW3_FOUND
    for(auto& win : _windows) {
        win.second->cleanup();
    }
    glfwTerminate();
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::input() -> std::shared_ptr<input_provider> {
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::video(string_view name)
  -> std::shared_ptr<video_provider> {
    EAGINE_MAYBE_UNUSED(name);
#if OGLPLUS_GLFW3_FOUND
    auto pos = _windows.find(name);
    if(pos != _windows.end()) {
        return {pos->second};
    }
#endif // OGLPLUS_GLFW3_FOUND
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::audio(string_view)
  -> std::shared_ptr<audio_provider> {
    return {};
}
//------------------------------------------------------------------------------
auto make_glfw3_opengl_provider(main_ctx_parent parent)
  -> std::shared_ptr<hmi_provider> {
    return {std::make_shared<glfw3_opengl_provider>(parent)};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
