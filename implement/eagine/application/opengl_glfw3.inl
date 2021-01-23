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
    auto surface_aspect() noexcept -> float final;

    void video_begin(execution_context&) final;
    void video_end(execution_context&) final;
    void video_commit(execution_context&) final;

    void input_enumerate(
      callable_ref<
        void(identifier, identifier, input_value_kinds, input_value_types)>)
      final;

    void input_connect(input_router&) final;
    void input_disconnect() final;

private:
    string_view _instance_name;
    GLFWwindow* _window{nullptr};
    input_router* _input_router{nullptr};
    input_variable<double> _mouse_x_pix{0};
    input_variable<double> _mouse_y_pix{0};
    input_variable<double> _mouse_x_ndc{0};
    input_variable<double> _mouse_y_ndc{0};
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
    glfwWindowHint(GLFW_RED_BITS, video_opts.color_bits() / GLFW_DONT_CARE);
    glfwWindowHint(GLFW_BLUE_BITS, video_opts.color_bits() / GLFW_DONT_CARE);
    glfwWindowHint(GLFW_GREEN_BITS, video_opts.color_bits() / GLFW_DONT_CARE);
    glfwWindowHint(GLFW_ALPHA_BITS, video_opts.alpha_bits() / GLFW_DONT_CARE);
    glfwWindowHint(GLFW_DEPTH_BITS, video_opts.depth_bits() / GLFW_DONT_CARE);
    glfwWindowHint(
      GLFW_STENCIL_BITS, video_opts.stencil_bits() / GLFW_DONT_CARE);

    glfwWindowHint(GLFW_SAMPLES, video_opts.samples() / GLFW_DONT_CARE);

    GLFWmonitor* window_monitor = nullptr;
    int fallback_width = 1280, fallback_height = 800;
    if(video_opts.fullscreen()) {
        window_monitor = glfwGetPrimaryMonitor();
        if(auto opt_mon_name{video_opts.display_name()}) {
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
        glfwGetWindowSize(_window, &_window_width, &_window_height);
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
auto glfw3_opengl_window::surface_aspect() noexcept -> float {
    return float(_window_width) / float(_window_height);
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
void glfw3_opengl_window::input_enumerate(
  callable_ref<void(identifier, identifier, input_value_kinds, input_value_types)>
    callback) {
    // Mouse inputs
    callback(
      EAGINE_ID(Cursor),
      EAGINE_ID(MotionX),
      input_value_kind::absolute_free | input_value_kind::absolute_norm,
      input_value_type::double_type);
    callback(
      EAGINE_ID(Cursor),
      EAGINE_ID(MotionY),
      input_value_kind::absolute_free | input_value_kind::absolute_norm,
      input_value_type::double_type);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_window::input_connect(input_router& router) {
    EAGINE_MAYBE_UNUSED(router);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_window::input_disconnect() {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_window::update(execution_context& exec_ctx) {

    if(glfwWindowShouldClose(_window)) {
        exec_ctx.stop_running();
    } else {
        glfwGetWindowSize(_window, &_window_width, &_window_height);

        if(_input_router) {
            double mouse_x_pix{0}, mouse_y_pix{0};
            glfwGetCursorPos(_window, &mouse_x_pix, &mouse_y_pix);
            if(_mouse_x_pix.assign(mouse_x_pix)) {
                extract(_input_router)
                  .trigger(
                    {EAGINE_ID(Cursor),
                     EAGINE_ID(MotionX),
                     input_value_kind::absolute_free},
                    _mouse_x_pix);
                if(_mouse_x_ndc.assign((mouse_x_pix / _window_width) - 0.5)) {
                    extract(_input_router)
                      .trigger(
                        {EAGINE_ID(Cursor),
                         EAGINE_ID(MotionX),
                         input_value_kind::absolute_norm},
                        _mouse_x_ndc);
                }
            }
            if(_mouse_y_pix.assign(mouse_y_pix)) {
                extract(_input_router)
                  .trigger(
                    {EAGINE_ID(Cursor),
                     EAGINE_ID(MotionY),
                     input_value_kind::absolute_free},
                    _mouse_y_pix);
                if(_mouse_y_ndc.assign((mouse_y_pix / _window_height) - 0.5)) {
                    extract(_input_router)
                      .trigger(
                        {EAGINE_ID(Cursor),
                         EAGINE_ID(MotionY),
                         input_value_kind::absolute_norm},
                        _mouse_y_ndc);
                }
            }
        }
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

    void input_enumerate(
      callable_ref<void(std::shared_ptr<input_provider>)>) final;
    void video_enumerate(
      callable_ref<void(std::shared_ptr<video_provider>)>) final;
    void audio_enumerate(
      callable_ref<void(std::shared_ptr<audio_provider>)>) final;

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
    return {"glfw3"};
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
                    } else {
                        extract(new_win).cleanup();
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
    for(auto& entry : _windows) {
        entry.second->update(exec_ctx);
    }
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_provider::cleanup(execution_context&) {
#if OGLPLUS_GLFW3_FOUND
    for(auto& entry : _windows) {
        entry.second->cleanup();
    }
    glfwTerminate();
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_provider::input_enumerate(
  callable_ref<void(std::shared_ptr<input_provider>)> handler) {
    EAGINE_MAYBE_UNUSED(handler);
#if OGLPLUS_GLFW3_FOUND
    for(auto& p : _windows) {
        handler(p.second);
    }
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_provider::video_enumerate(
  callable_ref<void(std::shared_ptr<video_provider>)> handler) {
    EAGINE_MAYBE_UNUSED(handler);
#if OGLPLUS_GLFW3_FOUND
    for(auto& p : _windows) {
        handler(p.second);
    }
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_provider::audio_enumerate(
  callable_ref<void(std::shared_ptr<audio_provider>)>) {}
//------------------------------------------------------------------------------
auto make_glfw3_opengl_provider(main_ctx_parent parent)
  -> std::shared_ptr<hmi_provider> {
    return {std::make_shared<glfw3_opengl_provider>(parent)};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
