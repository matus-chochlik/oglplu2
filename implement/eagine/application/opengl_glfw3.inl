/**
 *  @file eagine/application/opengl_glfw3.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine::application {

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
class glfw3_opengl_provider
  : public std::enable_shared_from_this<glfw3_opengl_provider>
  , public hmi_provider
  , public video_provider
  , public input_provider {
public:
    auto is_implemented() const noexcept -> bool final;
    auto implementation_name() const noexcept -> string_view final;

    auto is_initialized() -> bool final;
    auto initialize(execution_context&) -> bool final;
    void update(execution_context&) final;
    void cleanup(execution_context&) final;

    auto video_kind() const noexcept -> video_context_kind final;

    void video_begin(execution_context&) final;
    void video_end(execution_context&) final;
    void video_commit(execution_context&) final;

    auto input() -> std::shared_ptr<input_provider> final;
    auto video() -> std::shared_ptr<video_provider> final;
    auto audio() -> std::shared_ptr<audio_provider> final;

private:
    GLFWwindow* _window{nullptr};
    double _mouse_x{0};
    double _mouse_y{0};
    int _window_width{1};
    int _window_height{1};
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
    return _window != nullptr;
#endif
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::initialize(execution_context& exec_ctx) -> bool {
#if OGLPLUS_GLFW3_FOUND
    if(glfwInit()) {
        auto& options = exec_ctx.options();

        glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
        glfwWindowHint(GLFW_RED_BITS, options.color_bits());
        glfwWindowHint(GLFW_BLUE_BITS, options.color_bits());
        glfwWindowHint(GLFW_GREEN_BITS, options.color_bits());
        glfwWindowHint(GLFW_ALPHA_BITS, options.alpha_bits());
        glfwWindowHint(GLFW_DEPTH_BITS, options.depth_bits());
        glfwWindowHint(GLFW_STENCIL_BITS, options.stencil_bits());

        glfwWindowHint(GLFW_SAMPLES, options.samples() / GLFW_DONT_CARE);

        _window = glfwCreateWindow(
          options.surface_width(),
          options.surface_height(),
          c_str(options.application_title()),
          nullptr,
          nullptr);

        if(_window) {
            glfwMakeContextCurrent(_window);
            glfwSetWindowTitle(_window, c_str(options.application_title()));

            // TODO
            // glfwSetWindowPos(
            // _window, options.window_x_pos(), options.window_y_pos());
            // glfwSetScrollCallback(_window, example_scroll_callback);
            //
            glfwGetWindowSize(_window, &_window_width, &_window_height);

            return true;
        } else {
            exec_ctx.log_error("Failed to create GLFW window");
        }
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
#if OGLPLUS_GLFW3_FOUND
    glfwPollEvents();

    if(glfwWindowShouldClose(_window)) {
        exec_ctx.stop_running();
    } else {
        glfwGetWindowSize(_window, &_window_width, &_window_height);
        exec_ctx.surface_size(_window_width, _window_height);

        glfwGetCursorPos(_window, &_mouse_x, &_mouse_y);
        exec_ctx.pointer_position(float(_mouse_x), float(_mouse_y), 0);
    }
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::video_kind() const noexcept -> video_context_kind {
    return video_context_kind::opengl;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_provider::video_begin(execution_context&) {
#if OGLPLUS_GLFW3_FOUND

    EAGINE_ASSERT(_window);
    glfwMakeContextCurrent(_window);
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_provider::video_end(execution_context&) {
#if OGLPLUS_GLFW3_FOUND

    glfwMakeContextCurrent(nullptr);
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_provider::video_commit(execution_context&) {
#if OGLPLUS_GLFW3_FOUND
    EAGINE_ASSERT(_window);
    glfwSwapBuffers(_window);
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_provider::cleanup(execution_context&) {
#if OGLPLUS_GLFW3_FOUND
    glfwTerminate();
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::input() -> std::shared_ptr<input_provider> {
    return {shared_from_this()};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::video() -> std::shared_ptr<video_provider> {
    return {shared_from_this()};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_provider::audio() -> std::shared_ptr<audio_provider> {
    return {};
}
//------------------------------------------------------------------------------
auto make_glfw3_opengl_provider() -> std::shared_ptr<hmi_provider> {
    return {std::make_shared<glfw3_opengl_provider>()};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
