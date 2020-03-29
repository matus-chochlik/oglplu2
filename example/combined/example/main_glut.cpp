/**
 *  file. oglplus/example/main_glut.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "main.hpp"
#include <oglplus/config/basic.hpp>
#if OGLPLUS_GLUT_FOUND
#include "state.hpp"
#include "wrapper.hpp"
#include <oglplus/gl.hpp>

#include <eagine/assert.hpp>
#include <eagine/program_args.hpp>
#include <eagine/scope_exit.hpp>

#if OGLPLUS_FREEGLUT_FOUND
#include <GL/freeglut.h>
#elif defined(__APPLE__) && __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cassert>
#include <iostream>
#endif // OGLPLUS_GLUT_FOUND

#if defined(__APPLE__) && __APPLE__ && defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace eagine {
//------------------------------------------------------------------------------
#if OGLPLUS_GLUT_FOUND

class single_glut_context {
private:
    static single_glut_context*& instance_ptr() {
        static single_glut_context* pinst = nullptr;
        return pinst;
    }

    static single_glut_context& instance() {
        EAGINE_ASSERT(instance_ptr());
        return *instance_ptr();
    }

    example_wrapper example;
    int _height;
    int _wheel;

public:
    single_glut_context(
      example_args& args, example_params& params, example_state& state)
      : example(args, params, state)
      , _height(state.height())
      , _wheel(0) {
        EAGINE_ASSERT(!instance_ptr());
        instance_ptr() = this;
        if(example.is_ready()) {

            glutDisplayFunc(&display_func);
            glutIdleFunc(&display_func);
            glutReshapeFunc(&reshape_func);

            glutMotionFunc(&motion_func);
            glutPassiveMotionFunc(&motion_func);

            glutMouseFunc(&mouse_func);
            glutKeyboardFunc(&keyboard_func);

#ifdef FREEGLUT
            glutSetOption(
              GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
            glutCloseFunc(&close_func);
#endif
        }
    }

    bool is_ready() const {
        return example.is_ready();
    }

    single_glut_context(single_glut_context&&) = delete;
    single_glut_context(const single_glut_context&) = delete;
    single_glut_context& operator=(single_glut_context&&) = delete;
    single_glut_context& operator=(const single_glut_context&) = delete;

    ~single_glut_context() noexcept {
        EAGINE_ASSERT(instance_ptr());
        instance_ptr() = nullptr;
    }

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

#ifdef FREEGLUT
    void quit() {
        glutLeaveMainLoop();
    }
#else
    [[noreturn]] void quit() {
        exit(0);
    }
#endif

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

private:
    void close() {
        example.destroy();
    }

    static void close_func() {
        instance().close();
    }

    void display() {
        example.update();

        example.render();
        glutSwapBuffers();

        if(!example.next_frame()) {
            quit();
        }
    }

    static void display_func() {
        instance().display();
    }

    void reshape(int width, int height) {
        _height = height;
        example.set_size(width, height);
    }

    static void reshape_func(int width, int height) {
        instance().reshape(width, height);
    }

    void motion(int x, int y) {
        example.set_mouse_pos(x, _height - y);
    }

    static void motion_func(int x, int y) {
        instance().motion(x, y);
    }

    void mouse_press(int button, int state, int x, int y) {
        example.set_mouse_pos(x, _height - y);
        if(button == GLUT_LEFT_BUTTON) {
            example.set_mouse_btn(1, state == GLUT_DOWN);
        } else if(button == 3) {
            if(state == GLUT_DOWN) {
                example.set_mouse_wheel(++_wheel);
            }
        } else if(button == 4) {
            if(state == GLUT_DOWN) {
                example.set_mouse_wheel(--_wheel);
            }
        }
    }

    static void mouse_func(int button, int state, int x, int y) {
        instance().mouse_press(button, state, x, y);
    }

    void key_press(unsigned char k) {
        if(k == 0x1B) {
            quit();
        }
        // TODO
    }

    static void keyboard_func(unsigned char k, int, int) {
        instance().key_press(k);
    }
};

#endif // OGLPLUS_GLUT_FOUND
//------------------------------------------------------------------------------
class example_main_glut : public example_main_intf {
public:
    bool is_implemented() final {
        return (OGLPLUS_GLUT_FOUND != 0);
    }

    string_view implementation_name() final {
#if OGLPLUS_FREEGLUT_FOUND
        return {"FREEGLUT"};
#else
        return {"GLUT"};
#endif
    }

    int run(
      example_args& args, example_params& params, example_state& state) final {
#if OGLPLUS_GLX_FOUND

        int argc = args.argc();
        char** argv = const_cast<char**>(args.argv());

        glutInit(&argc, argv);
        glutInitDisplayMode(
#if defined(__APPLE__) && __APPLE__
          GLUT_3_2_CORE_PROFILE |
#endif
          // NOLINTNEXTLINE(hicpp-signed-bitwise)
          GLUT_DOUBLE | GLUT_RGBA | (params.depth_buffer() ? GLUT_DEPTH : 0) |
          (params.stencil_buffer() ? GLUT_STENCIL : 0));
#ifdef FREEGLUT
        glutInitContextVersion(
          OGLPLUS_GL_VERSION_MAJOR, OGLPLUS_GL_VERSION_MINOR);
#endif
        glutInitWindowSize(state.width(), state.height());
        glutInitWindowPosition(params.window_x_pos(), params.window_y_pos());
#ifdef FREEGLUT
        glutCreateWindow("OGLplus example (FREEGLUT)");
#else
        glutCreateWindow("OGLplus example (GLUT)");
#endif

        oglp::api_initializer gl_api_init;

        state.set_depth(16);

        single_glut_context ctx(args, params, state);
        if(!ctx.is_ready()) {
            return 2;
        }
        glutMainLoop();

        return 0;
#else
        return 1;
#endif
    }
};
//------------------------------------------------------------------------------
std::unique_ptr<example_main_intf> make_example_main_glut() {
    return {std::make_unique<example_main_glut>()};
}
//------------------------------------------------------------------------------
} // namespace eagine

#if defined(__APPLE__) && __APPLE__ && defined(__clang__)
#pragma clang diagnostic pop
#endif
