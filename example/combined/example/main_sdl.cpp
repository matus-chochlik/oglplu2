/**
 *  file. oglplus/example/main_sdl.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "main.hpp"
#include <eagine/maybe_unused.hpp>
#include <oglplus/config/basic.hpp>
#if OGLPLUS_SDL_FOUND
#include "state.hpp"
#include "wrapper.hpp"
#include <oglplus/gl.hpp>

#include <eagine/program_args.hpp>
#include <eagine/scope_exit.hpp>

#include <SDL/SDL.h>

#include <iostream>
#include <stdexcept>
#endif // OGLPLUS_SDL_FOUND

namespace eagine {
namespace oglp {

class example_main_sdl : public example_main_intf {
public:
    bool is_implemented() final {
        return (OGLPLUS_SDL_FOUND != 0);
    }

    string_view implementation_name() final {
        return {"SDL"};
    }

    int run(
      example_args& args, example_params& params, example_state& state) final {
#if OGLPLUS_SDL_FOUND
        auto errstr = [&args]() -> std::ostream& {
            return std::cerr << args.command() << ": ";
        };

        if(SDL_Init(SDL_INIT_VIDEO) != 0) {
            errstr() << "SDL initialization error: " << SDL_GetError()
                     << std::endl;
            return 2;
        }

        auto ensure_sdl_cleanup = finally(SDL_Quit);

        if(!SDL_SetVideoMode(
             state.width(),
             state.height(),
             32,
             // NOLINTNEXTLINE(hicpp-signed-bitwise)
             SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) {
            errstr() << SDL_GetError() << std::endl;
            return 2;
        }
        SDL_WM_SetCaption("OGLplus example (SDL)", nullptr);

        api_initializer gl_api_init;

        std::srand(params.rand_seed());

        state.set_depth(16);

        example_wrapper example(args, params, state);

        if(!example.is_ready()) {
            return 2;
        }
        example_loop(state, example);

        return 0;
#else
        EAGINE_MAYBE_UNUSED(args);
        EAGINE_MAYBE_UNUSED(params);
        EAGINE_MAYBE_UNUSED(state);
        return 1;
#endif
    }

private:
#if OGLPLUS_SDL_FOUND
    void example_loop(example_state& state, example_wrapper& example) {
        int w = state.width();
        int h = state.height();
        int x, y, z = 0;

        example.set_size(w, h);

        SDL_Event event;
        while(true) {
            while(SDL_PollEvent(&event)) {
                switch(event.type) {
                    case SDL_QUIT: {
                        return;
                    }
                    case SDL_KEYUP: {
                        if(event.key.keysym.sym == SDLK_ESCAPE) {
                            return;
                        }
                        break;
                    }
                    case SDL_MOUSEMOTION: {
                        x = event.motion.x;
                        y = event.motion.y;
                        example.set_mouse_pos(x, h - y);
                        break;
                    }
                    case SDL_MOUSEBUTTONUP:
                    case SDL_MOUSEBUTTONDOWN: {
                        bool pressed = event.type == SDL_MOUSEBUTTONDOWN;
                        auto button = event.button.button;

                        if(button == SDL_BUTTON_LEFT) {
                            example.set_mouse_btn(1, pressed);
                        } else if(button == SDL_BUTTON_WHEELUP) {
                            example.set_mouse_wheel(++z);
                        } else if(button == SDL_BUTTON_WHEELDOWN) {
                            example.set_mouse_wheel(--z);
                        }
                        break;
                    }
                    case SDL_VIDEORESIZE: {
                        w = event.resize.w;
                        h = event.resize.h;
                        example.set_size(w, h);
                        break;
                    }
                    default:;
                }
            }

            example.update();

            example.render();
            SDL_GL_SwapBuffers();

            if(!example.next_frame()) {
                break;
            }
        }
    }
#endif
};

std::unique_ptr<example_main_intf> make_example_main_sdl() {
    return {std::make_unique<example_main_sdl>()};
}

} // namespace oglp
} // namespace eagine
