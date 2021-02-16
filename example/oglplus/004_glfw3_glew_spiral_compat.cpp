/// @example oglplus/004_glfw3_glew_spiral_compat.cpp
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
#include <oglplus/operations.hpp>

#include <eagine/scope_exit.hpp>

#include <GLFW/glfw3.h>

#include <cmath>
#include <iostream>
#include <stdexcept>

static oglplus::constants GL;
static oglplus::operations gl;

static void handle_resize(int width, int height) {
    gl.viewport(0, 0, width, height);
    GLdouble asp = GLdouble(width) / height;

    GLdouble h = 1.618;
    GLdouble w = h * asp;

    gl.matrix_mode(GL.projection);
    gl.load_identity();
    gl.ortho(-w, +w, -h, +h, 0, 1);
}

static void run_loop(GLFWwindow* window, int width, int height) {
    using namespace oglplus;

    shader vs(GL.vertex_shader);

    gl.shader_source(
      vs,
      glsl_literal("#version 120\n"

                   "attribute vec2 Coord;\n"
                   "attribute vec3 Color1;\n"
                   "attribute vec3 Color2;\n"
                   "varying vec2 vertCoord;\n"
                   "varying vec3 vertColor1;\n"
                   "varying vec3 vertColor2;\n"

                   "void main()\n"
                   "{\n"
                   "	gl_Position = ftransform();\n"
                   "	vertCoord = Coord;\n"
                   "	vertColor1 = Color1;\n"
                   "	vertColor2 = Color2;\n"
                   "}\n"));
    gl.compile_shader(vs);

    shader fs(GL.fragment_shader);

    gl.shader_source(
      fs,
      glsl_literal("#version 120\n"

                   "varying vec2 vertCoord;\n"
                   "varying vec3 vertColor1;\n"
                   "varying vec3 vertColor2;\n"

                   "float spiral(vec2 c)\n"
                   "{\n"
                   "	return max(sign(mod(8*(sqrt(c.x)+c.y), 2)-1),0);\n"
                   "}\n"

                   "void main()\n"
                   "{\n"
                   "	gl_FragColor = vec4(mix(\n"
                   "		vertColor1,\n"
                   "		vertColor2,\n"
                   "		spiral(vertCoord)\n"
                   "	), 1);\n"
                   "}\n"));
    gl.compile_shader(fs);

    program prog;

    gl.attach_shader(prog, vs);
    gl.attach_shader(prog, fs);
    gl.link_program(prog);
    gl.use_program(prog);

    vertex_attrib<GLfloat[2]> coord(prog, "Coord");
    vertex_attrib<GLfloat> color1(prog, "Color1");
    vertex_attrib<GLfloat> color2(prog, "Color2");

    gl.clear_color(0.7F, 0.7F, 0.6F, 0.0F);

    handle_resize(width, height);

    int deg = 0;

    const auto twopi = std::atan(1) * 8;
    const int nseg = 72;
    const auto sstep = float(twopi / nseg);
    const auto spart = float(1.0F / nseg);
    const float z = 0, o = 1;
    float a;

    while(true) {
        using std::cos;
        using std::sin;

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

        gl.clear(GL.color_buffer_bit);

        gl.matrix_mode(GL.modelview);
        gl.load_identity();
        gl.rotate_f(degrees_(deg += 2), 0, 0, 1);

        gl.begin(GL.triangle_strip);
        for(int s = 0; s < nseg; ++s) {
            a = (s + 0) * spart;

            gl.vertex_attrib(coord, view({z, a}), false);
            gl.vertex_attrib(color1, 0.2F, 0.1F, 0.1F, false);
            gl.vertex_attrib(color2, 0.3F, 0.1F, 0.2F, false);
            gl.vertex_f(0, 0);

            gl.vertex_attrib(coord, view({o, a}), false);
            gl.vertex_attrib(color1, 0.0F, 0.0F, 0.0F, false);
            gl.vertex_attrib(color2, 0.9F, 0.3F, 0.4F, false);
            gl.vertex_f(cos((s + 0) * sstep), sin((s + 0) * sstep));

            a = (s + 1) * spart;

            gl.vertex_attrib(coord, view({z, a}), false);
            gl.vertex_attrib(color1, 0.2F, 0.1F, 0.1F, false);
            gl.vertex_attrib(color2, 0.3F, 0.1F, 0.2F, false);
            gl.vertex_f(0, 0);

            gl.vertex_attrib(coord, view({o, a}), false);
            gl.vertex_attrib(color1, 0.0F, 0.0F, 0.0F, false);
            gl.vertex_attrib(color2, 0.9F, 0.3F, 0.4F, false);
            gl.vertex_f(cos((s + 1) * sstep), sin((s + 1) * sstep));
        }
        gl.end();

        gl.vertex_attrib(color1, 0.2F, 0.1F, 0.1F, true);

        const GLfloat c2[3] = {0.3F, 0.1F, 0.2F};
        gl.vertex_attrib(color2, c2, true);

        gl.begin(GL.line_loop);
        for(int s = 0; s < nseg; ++s) {
            gl.vertex_attrib(coord, view({o, s * spart}), false);
            gl.vertex_f(cos(s * sstep), sin(s * sstep));
        }
        gl.end();

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
        glfwWindowHint(GLFW_STENCIL_BITS, 0);

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
