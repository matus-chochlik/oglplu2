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
class glfw3_opengl_context : public opengl_context {
public:
    auto is_implemented() const noexcept -> bool final;
    auto implementation_name() const noexcept -> string_view final;

    auto initialize(execution_context&) -> bool final;
    void cleanup(execution_context&) final;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_context::is_implemented() const noexcept -> bool {
    return OGLPLUS_GLFW3_FOUND != 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_context::implementation_name() const noexcept -> string_view {
    return {"GLFW3"};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_context::initialize(execution_context& exec_ctx) -> bool {
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

        auto window = glfwCreateWindow(
          options.surface_width(),
          options.surface_height(),
          c_str(options.application_title()),
          nullptr,
          nullptr);

        if(!window) {
            glfwMakeContextCurrent(window);
            glfwSetWindowTitle(window, c_str(options.application_title()));

            // TODO
            // glfwSetWindowPos(
            // window, options.window_x_pos(), options.window_y_pos());
            // glfwSetScrollCallback(window, example_scroll_callback);

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
void glfw3_opengl_context::cleanup(execution_context&) {
#if OGLPLUS_GLFW3_FOUND
    glfwTerminate();
#endif // OGLPLUS_GLFW3_FOUND
}
//------------------------------------------------------------------------------
auto make_glfw3_context() -> std::unique_ptr<opengl_context> {
    return {std::make_unique<glfw3_opengl_context>()};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
