/**
 *  file. oglplus/example/main_glx.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "main.hpp"
#include <eagine/maybe_unused.hpp>
#include <oglplus/config/basic.hpp>
#if OGLPLUS_GLX_FOUND
// clang-format off
#include <oglplus/gl.hpp>
#include "state.hpp"
#include "wrapper.hpp"

#include <eagine/interop/glx/context.hpp>
#include <eagine/interop/glx/fb_configs.hpp>
#include <eagine/interop/glx/pixmap.hpp>
#include <eagine/interop/glx/version.hpp>
#include <eagine/interop/x11/color_map.hpp>
#include <eagine/interop/x11/display.hpp>
#include <eagine/interop/x11/visual_info.hpp>
#include <eagine/interop/x11/window.hpp>

#include <eagine/program_args.hpp>
#include <eagine/scope_exit.hpp>

#include <iostream>
#include <stdexcept>
// clang-format on
#endif // OGLPLUS_GLX_FOUND

namespace eagine {
//------------------------------------------------------------------------------
using namespace oglp;
class example_main_glx : public example_main_intf {
public:
    auto is_implemented() -> bool final {
        return (OGLPLUS_GLX_FOUND != 0);
    }

    auto implementation_name() -> string_view final {
        return {"GLX"};
    }

    auto run(example_run_context& erc) -> int final {
#if OGLPLUS_GLX_FOUND
        x11::Display display;

        glx::version(display).assert_at_least(1, 3);

        static int visual_attribs[] = {
          GLX_X_RENDERABLE,
          True,
          GLX_DRAWABLE_TYPE,
          GLX_WINDOW_BIT,
          GLX_RENDER_TYPE,
          GLX_RGBA_BIT,
          GLX_X_VISUAL_TYPE,
          GLX_TRUE_COLOR,
          GLX_RED_SIZE,
          erc.params.color_bits(),
          GLX_GREEN_SIZE,
          erc.params.color_bits(),
          GLX_BLUE_SIZE,
          erc.params.color_bits(),
          GLX_ALPHA_SIZE,
          erc.params.alpha_bits(),
          GLX_DEPTH_SIZE,
          erc.params.depth_bits(),
          GLX_STENCIL_SIZE,
          erc.params.stencil_bits(),
          GLX_DOUBLEBUFFER,
          True,
          GLX_SAMPLE_BUFFERS,
          erc.params.samples() ? 1 : 0,
          GLX_SAMPLES,
          erc.params.samples() / 0,
          None};
        glx::FBConfig fbc =
          // NOLINTNEXTLINE(hicpp-no-array-decay)
          glx::FBConfigs(display, visual_attribs).FindBest(display);

        x11::VisualInfo vi(display, fbc);

        x11::Window win(
          display,
          vi,
          x11::Colormap(display, vi),
          "OGLplus example (glX)",
          erc.params.window_x_pos(),
          erc.params.window_y_pos(),
          unsigned(erc.state.width()),
          unsigned(erc.state.height()));

        win.SelectInput(
          // NOLINTNEXTLINE(hicpp-signed-bitwise)
          StructureNotifyMask | PointerMotionMask | ButtonMotionMask |
          // NOLINTNEXTLINE(hicpp-signed-bitwise)
          ButtonPressMask | ButtonReleaseMask | KeyPressMask);

        glx::Context ctx(display, fbc, 3, 3);

        ctx.MakeCurrent(win);

        oglp::api_initializer gl_api_init;

        erc.state.set_depth(16);

        example_wrapper example(erc);
        example.context().log().info("using GLX context");

        if(!example.is_ready()) {
            return 2;
        }
        _example_loop(display, win, ctx, erc, example);
        example.destroy();
        return 0;
#else
        EAGINE_MAYBE_UNUSED(erc);
        return 1;
#endif
    }

private:
#if OGLPLUS_GLX_FOUND
    void _example_loop(
      const x11::Display& display,
      const x11::Window& win,
      const glx::Context& ctx,
      example_run_context& erc,
      example_wrapper& example) {
        auto& state = erc.state;

        XEvent event;

        int w = state.width();
        int h = state.height();
        int x, y, z = 0;

        while(true) {
            while(display.NextEvent(event)) {
                switch(event.type) {
                    case ClientMessage:
                    case DestroyNotify: {
                        return;
                    }

                    case ConfigureNotify: {
                        example.set_size(w, h);
                        break;
                    }

                    case MotionNotify: {
                        x = event.xmotion.x;
                        y = event.xmotion.y;
                        example.set_mouse_pos(x, h - y);
                        break;
                    }

                    case ButtonPress:
                    case ButtonRelease: {
                        bool pressed = event.xbutton.type == ButtonPress;
                        if(event.xbutton.button == 1) {
                            example.set_mouse_btn(1, pressed);
                        } else if(event.xbutton.button == 4) {
                            example.set_mouse_wheel(++z);
                        } else if(event.xbutton.button == 5) {
                            example.set_mouse_wheel(--z);
                        }
                        break;
                    }

                    case KeyPress: {
                        if(::XLookupKeysym(&event.xkey, 0) == XK_Escape) {
                            return;
                        }
                        break;
                    }
                    default:;
                }
            }

            example.update();
            example.render();
            ctx.SwapBuffers(win);

            if(!example.next_frame()) {
                break;
            }
        }
    }
#endif
};
//------------------------------------------------------------------------------
auto make_example_main_glx() -> std::unique_ptr<example_main_intf> {
    return {std::make_unique<example_main_glx>()};
}
//------------------------------------------------------------------------------
} // namespace eagine
