/// @example oglplus/003_glfw3_glew_path_nv.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <GL/glew.h>

#include <oglplus/constant_defs.hpp>
#include <oglplus/constants.hpp>
#include <oglplus/error/format.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/math/vector.hpp>
#include <oglplus/operations.hpp>

#include <eagine/scope_exit.hpp>

#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>

static oglplus::constants GL;
static oglplus::operations gl;

static void handle_resize(int width, int height) {
    gl.viewport(0, 0, width, height);
    GLdouble asp = GLdouble(width) / height;

    GLdouble h = 2;
    GLdouble w = h * asp;

    gl.matrix_mode(GL.projection);
    gl.load_identity();
    gl.ortho(-w, +w, -h, +h, 0, 1);
}

static void run_loop(GLFWwindow* window, int width, int height) {
    using namespace oglplus;

    path_nv path;

    path.commands(path_nv_spec<GLfloat>(6, 10)
                    .move_to(0.00F, 0.85F)
                    .line_to(0.65F, -0.80F)
                    .line_to(-0.85F, 0.30F)
                    .line_to(0.85F, 0.30F)
                    .line_to(-0.65F, -0.80F)
                    .close());

    path.stroke_width(0.01F);
    path.join_style(GL.round_nv);
    path.dashes(0.05F, 0.02F);

    gl.clear_color(vec4(0.6F, 0.7F, 0.6F, 0.0F));
    gl.clear_stencil(0);
    gl.stencil_mask(~0u);
    gl.stencil_func(GL.notequal, 0, 0x1F);
    gl.stencil_op(GL.keep, GL.keep, GL.zero);

    gl.enable(GL.stencil_test);

    handle_resize(width, height);

    int deg = 0;

    while(true) {
        glfwPollEvents();

        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, 1);
            break;
        }

        if(glfwWindowShouldClose(window)) {
            break;
        }

        int new_width, new_height;
        glfwGetWindowSize(window, &new_width, &new_height);

        if((width != new_width) || (height != new_height)) {
            width = new_width;
            height = new_height;

            handle_resize(width, height);
        }

        gl.clear(GL.color_buffer_bit | GL.stencil_buffer_bit);

        gl.matrix_mode(GL.modelview);
        gl.load_identity();
        gl.rotate_f(degrees_(deg++), 0, 0, 1);

        gl.color_f(0.2F, 0.2F, 1.0F);

        path.stencil_fill(GL.count_up_nv, 0x1F);
        path.cover_fill(GL.bounding_box_nv);

        gl.color_f(0.1F, 0.1F, 0.1F);

        path.stencil_stroke(1, ~0u);
        path.cover_stroke(GL.convex_hull_nv);

        glfwSwapBuffers(window);
    }
}

static void init_and_run() {
    if(!glfwInit()) {
        throw std::runtime_error("GLFW initialization error");
    } else {
        auto ensure_glfw_cleanup = eagine::finally(glfwTerminate);

        glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 0);
        glfwWindowHint(GLFW_DEPTH_BITS, 0);
        glfwWindowHint(GLFW_STENCIL_BITS, 8);

        glfwWindowHint(GLFW_SAMPLES, GLFW_DONT_CARE);

        int width = 800, height = 600;

        GLFWwindow* window =
          glfwCreateWindow(width, height, "OGLplus example", nullptr, nullptr);

        if(!window) {
            throw std::runtime_error("Error creating GLFW window");
        } else {
            glfwMakeContextCurrent(window);
            glewExperimental = GL_TRUE;
            GLenum init_result = glewInit();
            glGetError();
            if(init_result != GLEW_OK) {
                throw std::runtime_error("OpenGL/GLEW initialization error.");
            } else {
                run_loop(window, width, height);
            }
        }
    }
}

auto main() -> int {
    try {
        init_and_run();
        return 0;
    } catch(oglplus::error& gle) {
        oglplus::format_error(
          gle,
          "OpenGL error\n"
          "in GL function: %(gl_function_name)\n"
          "with enum parameter: %(gl_enum_value)\n"
          "from source file: %(source_file)\n"
          "%(message)",
          std::cerr)
          << std::endl;
    } catch(std::runtime_error& sre) {
        std::cerr << "Runtime error: " << sre.what() << std::endl;
    } catch(std::exception& se) {
        std::cerr << "Unknown error: " << se.what() << std::endl;
    }
    return 1;
}
