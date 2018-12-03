/**
 *  @example standalone/001_glfw3_glew_info.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <GL/glew.h>

#include <oglplus/constant_defs.hpp>
#include <oglplus/constants.hpp>
#include <oglplus/enum/value_names.hpp>
#include <oglplus/enum/value_range.hpp>
#include <oglplus/operations.hpp>

#include <eagine/scope_exit.hpp>

#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>

static void run() {
    using namespace oglplus;

    operations gl;

    for(auto str_query : enum_value_range<string_query>()) {
        std::cout << enum_value_name(str_query) << ": " << std::endl;
        //<< gl.get_string(str_query) << std::endl;
    }

    std::cout << "EXTENSIONS:" << std::endl;

    GLuint index = 0;
    while(true) {
        if(auto result = success(gl.get_extension_name(index++))) {
            std::cout << '\t' << result.value() << std::endl;
        } else {
            result.ignore_error();
            break;
        }
    }
}

static void init_and_run() {
    if(!glfwInit()) {
        throw std::runtime_error("GLFW initialization error");
    } else {
        auto ensure_glfw_cleanup = eagine::finally(glfwTerminate);

        glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);

        int width = 800, height = 600;

        GLFWwindow* window =
          glfwCreateWindow(width, height, "OGLplus example", NULL, NULL);

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
                run();
            }
        }
    }
}

int main() {
    try {
        init_and_run();
        return 0;
    } catch(std::runtime_error& sre) {
        std::cerr << "Runtime error: " << sre.what() << std::endl;
    } catch(std::exception& se) {
        std::cerr << "Unknown error: " << se.what() << std::endl;
    }
    return 1;
}
