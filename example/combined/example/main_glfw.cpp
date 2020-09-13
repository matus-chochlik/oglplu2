/**
 *  file. oglplus/example/main_glfw.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "main.hpp"
#include <eagine/main_ctx.hpp>
#include <eagine/maybe_unused.hpp>
#include <oglplus/config/basic.hpp>
#if OGLPLUS_GLFW_FOUND
#include "state.hpp"
#include "wrapper.hpp"
#include <oglplus/gl.hpp>

#include <eagine/program_args.hpp>
#include <eagine/scope_exit.hpp>

#include <GL/glfw.h>

#include <iostream>
#include <stdexcept>
#endif // OGLPLUS_GLFW_FOUND

namespace eagine {
//------------------------------------------------------------------------------
class example_main_glfw : public example_main_intf {
public:
    bool is_implemented() final {
        return (OGLPLUS_GLX_FOUND != 0);
    }

    string_view implementation_name() final {
        return {"GLFW"};
    }

    int run(example_run_context& erc) final {
#if OGLPLUS_GLFW_FOUND
        if(!glfwInit()) {
            erc.main.log().error("GLFW initialization error");
            return 2;
        } else {
            auto ensure_glfw_cleanup = finally(glfwTerminate);

            if(!glfwOpenWindow(
                 erc.state.width(),
                 erc.state.height(),
                 erc.params.color_bits(),
                 erc.params.color_bits(),
                 erc.params.color_bits(),
                 erc.params.alpha_bits(),
                 erc.params.depth_bits(),
                 erc.params.stencil_bits(),
                 GLFW_WINDOW)) {
                erc.main.log().error("Failed to create GLFW window");
                return 2;
            } else {
                glfwSetWindowTitle("OGLplus example (GLFW)");
                glfwSetWindowPos(
                  erc.params.window_x_pos(), erc.params.window_y_pos());

                oglp::api_initializer gl_api_init;

                erc.state.set_depth(16);
                example_wrapper example(erc);
                example.context().log().info("using GLFW context");

                if(!example.is_ready()) {
                    return 2;
                }
                _example_loop(erc, example);
                example.destroy();
            }
        }
        return 0;
#else
        EAGINE_MAYBE_UNUSED(erc);
        return 1;
#endif
    }

private:
#if OGLPLUS_GLFW_FOUND
    void _example_loop(example_run_context& erc, example_wrapper& example) {
        auto& state = erc.state;
        int w = state.width();
        int h = state.height();
        int x, y;

        while(true) {
            if(!glfwGetWindowParam(GLFW_OPENED)) {
                break;
            }

            if(glfwGetKey(GLFW_KEY_ESC)) {
                glfwCloseWindow();
                break;
            }

            glfwGetWindowSize(&w, &h);
            example.set_size(w, h);

            glfwGetMousePos(&x, &y);
            example.set_mouse_pos(x, h - y);

            example.set_mouse_btn(
              1, glfwGetMouseButton(GLFW_MOUSE_BUTTON_1) == GLFW_PRESS);

            example.set_mouse_wheel(glfwGetMouseWheel());

            example.update();

            example.render();
            glfwSwapBuffers();

            if(!example.next_frame()) {
                break;
            }
        }
    }
#endif
};
//------------------------------------------------------------------------------
std::unique_ptr<example_main_intf> make_example_main_glfw() {
    return {std::make_unique<example_main_glfw>()};
}
//------------------------------------------------------------------------------
} // namespace eagine
