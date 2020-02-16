/**
 *  @example standalone/009_glfw3_glew_cube.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
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

    GLdouble h = 0.5 * 1.618;
    GLdouble w = h * asp;

    gl.matrix_mode(GL.projection);
    gl.load_identity();
    gl.frustum(-w, +w, -h, +h, 1, 3);
    gl.translate_f(0, 0, -2);
}

static void run_loop(GLFWwindow* window, int width, int height) {
    using namespace oglplus;

    shader vs(GL.vertex_shader);

    vs.source(
      glsl_literal("#version 120\n"

                   "attribute vec3 Position;\n"
                   "attribute vec3 Normal;\n"
                   "attribute vec2 Coord;\n"

                   "varying vec3 vertPosition;\n"
                   "varying vec3 vertNormal;\n"
                   "varying vec2 vertCoord;\n"

                   "void main()\n"
                   "{\n"
                   "	gl_Position = ftransform();\n"
                   "	vertPosition = Position;\n"
                   "	vertNormal = Normal;\n"
                   "	vertCoord = Coord;\n"
                   "}\n"));
    vs.compile();

    shader fs(GL.fragment_shader);

    fs.source(glsl_literal(
      "#version 120\n"

      "varying vec3 vertPosition;\n"
      "varying vec3 vertNormal;\n"
      "varying vec2 vertCoord;\n"

      "void main()\n"
      "{\n"
      "	vec2 vc = abs(vertCoord);\n"
      "	float c1 = max(max(vc.x, vc.y)-0.9875, 0.0)*100;\n"
      "	float c2 = 1.0-0.45*dot(vc, vc);\n"
      "	vec3 lc = vec3(0);\n"
      "	vec3 fc1 = normalize(abs(vec3(1, 1, 1) - vertPosition));\n"
      "	vec3 fc2 = normalize(abs(vec3(1, 1, 1) - vertNormal));\n"
      "	vec3 fc = mix(fc1, fc2, 0.5);\n"
      "	gl_FragColor = vec4(mix(fc, lc, c1)*c2, 1.0);\n"
      "}\n"));
    fs.compile();

    program prog;

    prog.attach(vs);
    prog.attach(fs);
    prog.link();

    gl.use_program(prog);

    vertex_array vao;

    gl.bind(vao);

    // positions
    const GLfloat v[8][3] = {{-0.5f, -0.5f, -0.5f},
                             {+0.5f, -0.5f, -0.5f},
                             {-0.5f, +0.5f, -0.5f},
                             {+0.5f, +0.5f, -0.5f},
                             {-0.5f, -0.5f, +0.5f},
                             {+0.5f, -0.5f, +0.5f},
                             {-0.5f, +0.5f, +0.5f},
                             {+0.5f, +0.5f, +0.5f}};

    const GLint f[6][2][3] = {{{0, 4, 2}, {2, 4, 6}},
                              {{5, 1, 7}, {7, 1, 3}},
                              {{0, 1, 4}, {4, 1, 5}},
                              {{6, 7, 2}, {2, 7, 3}},
                              {{1, 0, 3}, {3, 0, 2}},
                              {{4, 5, 6}, {6, 5, 7}}};

    const GLuint vertex_count = 6 * 2 * 3;
    GLfloat cube_vertices[vertex_count * 3];

    for(GLuint fi = 0; fi != 6; ++fi) {
        for(GLuint ti = 0; ti != 2; ++ti) {
            for(GLuint vi = 0; vi != 3; ++vi) {
                for(GLuint ci = 0; ci != 3; ++ci) {
                    cube_vertices[fi * 2 * 3 * 3 + ti * 3 * 3 + vi * 3 + ci] =
                      v[f[fi][ti][vi]][ci];
                }
            }
        }
    }

    buffer pos;
    gl.bind(GL.array_buffer, pos);
    gl.buffer_data(GL.array_buffer, cube_vertices, GL.static_draw);

    gl.vertex_array_attrib_pointer(
      vertex_attrib_location(0), 3, GL.float_, false, 0, nullptr);
    gl.enable_vertex_array_attrib(vertex_attrib_location(0));

    vertex_attrib_location va_p;
    gl.query_location(va_p, prog, "Position");
    gl.vertex_array_attrib_pointer(va_p, 3, GL.float_, false, 0, nullptr);
    gl.enable_vertex_array_attrib(va_p);

    // normals
    const GLfloat n[6][3] = {{-1.0f, 0.0f, 0.0f},
                             {1.0f, 0.0f, 0.0f},
                             {0.0f, -1.0f, 0.0f},
                             {0.0f, 1.0f, 0.0f},
                             {0.0f, 0.0f, -1.0f},
                             {0.0f, 0.0f, 1.0f}};
    GLfloat cube_normals[vertex_count * 3];
    for(GLuint fi = 0; fi != 6; ++fi) {
        for(GLuint vi = 0; vi != 6; ++vi) {
            for(GLuint ci = 0; ci != 3; ++ci) {
                cube_normals[(fi * 6 + vi) * 3 + ci] = n[fi][ci];
            }
        }
    }

    buffer nml;
    gl.bind(GL.array_buffer, nml);
    gl.buffer_data(GL.array_buffer, cube_normals, GL.static_draw);

    vertex_attrib_location va_n;
    gl.query_location(va_n, prog, "Normal");
    gl.vertex_array_attrib_pointer(va_n, 3, GL.float_, false, 0, nullptr);
    gl.enable_vertex_array_attrib(va_n);

    // face-coords
    const GLfloat c[6][2] = {{-1.0f, -1.0f},
                             {+1.0f, -1.0f},
                             {-1.0f, +1.0f},
                             {-1.0f, +1.0f},
                             {+1.0f, -1.0f},
                             {+1.0f, +1.0f}};

    GLfloat cube_coords[vertex_count * 2];

    for(GLuint fi = 0; fi != 6; ++fi) {
        for(GLuint vi = 0; vi != 6; ++vi) {
            for(GLuint ci = 0; ci != 2; ++ci) {
                cube_coords[(fi * 6 + vi) * 2 + ci] = c[vi][ci];
            }
        }
    }

    buffer crd;
    gl.bind(GL.array_buffer, crd);
    gl.buffer_data(GL.array_buffer, cube_coords, GL.static_draw);

    vertex_attrib_location va_c;
    gl.query_location(va_c, prog, "Coord");
    gl.vertex_array_attrib_pointer(va_c, 2, GL.float_, false, 0, nullptr);
    gl.enable_vertex_array_attrib(va_c);

    gl.clear_color(0.3f, 0.3f, 0.3f, 0.0f);
    gl.clear_depth(1.0f);

    gl.enable(GL.depth_test);

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

        gl.clear(GL.color_buffer_bit | GL.depth_buffer_bit);

        gl.matrix_mode(GL.modelview);
        gl.load_identity();
        gl.rotate_f(degrees_(0.1f * (deg += 1)), 1, 0, 0);
        gl.rotate_f(degrees_(0.1f * (deg += 2)), 0, 1, 0);
        gl.rotate_f(degrees_(0.1f * (deg += 3)), 0, 0, 1);

        gl.draw_arrays(GL.triangles, 0, 6 * 2 * 3);

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
        glfwWindowHint(GLFW_DEPTH_BITS, 24);
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

int main() {
    try {
        init_and_run();
        return 0;
    } catch(oglplus::error& gle) {
        oglplus::format_error(
          gle,
          "OpenGL error\n"
          "in GL function: %(gl_function_name)\n"
          "with object: %(gl_object)\n"
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
