/**
 *  file. oglplus/example/main_glx.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include "wrapper.hpp"
#include "state.hpp"

#include <oglplus/glx/context.hpp>
#include <oglplus/glx/fb_configs.hpp>
#include <oglplus/glx/version.hpp>
#include <oglplus/glx/pixmap.hpp>
#include <oglplus/x11/window.hpp>
#include <oglplus/x11/color_map.hpp>
#include <oglplus/x11/visual_info.hpp>
#include <oglplus/x11/display.hpp>

#include <eagine/scope_exit.hpp>
#include <eagine/program_args.hpp>


#include <iostream>
#include <stdexcept>

void example_loop(
	const oglplus::x11::Display& display,
	const oglplus::x11::Window& win,
	const oglplus::glx::Context& ctx,
	oglplus::example_state& state,
	oglplus::example_wrapper& example
)
{
	XEvent event;

	int w = state.width();
	int h = state.height();
	int x, y, z = 0;

	while(true)
	{
		while(display.NextEvent(event))
		switch(event.type)
		{
			case ClientMessage:
			case DestroyNotify:
			{
				return;
			}

			case ConfigureNotify:
			{
				w = event.xconfigure.width;
				h = event.xconfigure.height;
				example.set_size(w, h);
				break;
			}

			case MotionNotify:
			{
				x = event.xmotion.x;
				y = event.xmotion.y;
				example.set_mouse_pos(x, h-y);
				break;
			}

			case ButtonPress:
			case ButtonRelease:
			{
				bool pressed = event.xbutton.type==ButtonPress;
				if(event.xbutton.button == 1)
				{
					example.set_mouse_btn(1, pressed);
				}
				else if(event.xbutton.button == 4)
				{
					example.set_mouse_wheel(++z);
				}
				else if(event.xbutton.button == 5)
				{
					example.set_mouse_wheel(--z);
				}
				break;
			}
					
			case KeyPress:
			{
				if(::XLookupKeysym(&event.xkey, 0) == XK_Escape)
				{
					return;
				}
				break;
			}
			default:;
		}

		example.update();
		example.render();
		ctx.SwapBuffers(win);

		if(!example.next_frame())
		{
			break;
		}
	}
}

int example_main(
	const eagine::program_args& /*args*/,
	oglplus::example_params& params,
	oglplus::example_state& state
)
{
	using namespace oglplus;

	x11::Display display;

	glx::Version version(display);
	version.AssertAtLeast(1, 3);

	static int visual_attribs[] =
	{
		GLX_X_RENDERABLE    , True,
		GLX_DRAWABLE_TYPE   , GLX_WINDOW_BIT,
		GLX_RENDER_TYPE     , GLX_RGBA_BIT,
		GLX_X_VISUAL_TYPE   , GLX_TRUE_COLOR,
		GLX_RED_SIZE        , params.color_bits(),
		GLX_GREEN_SIZE      , params.color_bits(),
		GLX_BLUE_SIZE       , params.color_bits(),
		GLX_ALPHA_SIZE      , params.alpha_bits(),
		GLX_DEPTH_SIZE      , params.depth_bits(),
		GLX_STENCIL_SIZE    , params.stencil_bits(),
		GLX_DOUBLEBUFFER    , True,
		GLX_SAMPLE_BUFFERS  , params.samples()?1:0,
		GLX_SAMPLES         , params.samples()/0,
		None
	};
	glx::FBConfig fbc = glx::FBConfigs(
		display,
		visual_attribs
	).FindBest(display);

	x11::VisualInfo vi(display, fbc);

	x11::Window win(
		display,
		vi,
		x11::Colormap(display, vi),
		"OGLplus example",
		params.window_x_pos(),
		params.window_y_pos(),
		unsigned(state.width()),
		unsigned(state.height())
	);

	win.SelectInput(
		StructureNotifyMask|
		PointerMotionMask|
		ButtonMotionMask|
		ButtonPressMask|
		ButtonReleaseMask|
		KeyPressMask
	);

	glx::Context ctx(display, fbc, 3, 3);

	ctx.MakeCurrent(win);

	oglplus::api_initializer gl_api_init;

	std::srand(params.rand_seed());
	state.set_depth(16);

	oglplus::example_wrapper example(params, state);

	example_loop(display, win, ctx, state, example);

	return 0;
}

