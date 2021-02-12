/// @example oglplus/001_glfw3_glew_info.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <GL/glew.h>

#include <eagine/scope_exit.hpp>
#include <oglplus/gl_api.hpp>

#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>

static void run() {
    using namespace eagine;
    using namespace eagine::oglp;

    gl_api gl;

    if(ok info{gl.get_string(gl.vendor)}) {
        std::cout << "Vendor: " << extract(info) << std::endl;
    }

    if(ok info{gl.get_string(gl.renderer)}) {
        std::cout << "Renderer: " << extract(info) << std::endl;
    }

    if(ok info{gl.get_string(gl.version)}) {
        std::cout << "Version: " << extract(info) << std::endl;
    }

    if(ok info{gl.get_integer(gl.major_version)}) {
        std::cout << "Major version: " << extract(info) << std::endl;
    }

    if(ok info{gl.get_integer(gl.minor_version)}) {
        std::cout << "Minor version: " << extract(info) << std::endl;
    }

    if(ok info{gl.get_string(gl.shading_language_version)}) {
        std::cout << "GLSL Version: " << extract(info) << std::endl;
    }

    std::cout << "Extensions:" << std::endl;

    if(ok extensions{gl.get_extensions()}) {
        for(auto name : extensions) {
            std::cout << "  " << name << std::endl;
        }
    } else {
        std::cerr << "failed to get GL extension list: "
                  << (!extensions).message() << std::endl;
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
                run();
            }
        }
    }
}

auto main() -> int {
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
