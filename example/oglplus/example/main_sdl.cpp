/**
 *  file. oglplus/example/main_sdl.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include "wrapper.hpp"
#include "state.hpp"

#include <eagine/scope_exit.hpp>
#include <eagine/program_args.hpp>

#include <SDL/SDL.h>

#include <iostream>
#include <stdexcept>

void example_loop(
	oglplus::example_state& state,
	oglplus::example_wrapper& example
)
{
	int w = state.width();
	int h = state.height();
	int x, y, z = 0;

	SDL_Event event;
	while(true)
	{
		while(SDL_PollEvent(&event))
		switch(event.type)
		{
			case SDL_QUIT:
			{
				return;
			}
			case SDL_KEYUP:
			{
				if(event.key.keysym.sym == SDLK_ESCAPE)
				{
					return;
				}
				break;
			}
			case SDL_MOUSEMOTION:
			{
				x = event.motion.x;
				y = event.motion.y;
				example.set_mouse_pos(x, h-y);
				break;
			}
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEBUTTONDOWN:
			{
				bool pressed = event.type==SDL_MOUSEBUTTONDOWN;
				auto button = event.button.button;

				if(button == SDL_BUTTON_LEFT)
				{
					example.set_mouse_btn(1, pressed);
				}
				else if(button == SDL_BUTTON_WHEELUP)
				{
					example.set_mouse_wheel(++z);
				}
				else if(button == SDL_BUTTON_WHEELDOWN)
				{
					example.set_mouse_wheel(--z);
				}
				break;
			}
			case SDL_VIDEORESIZE:
			{
				w = event.resize.w;
				h = event.resize.h;
				example.set_size(w, h);
				break;
			}
			default:;
		}

		example.update();

		example.render();
		SDL_GL_SwapBuffers();

		if(!example.next_frame())
		{
			break;
		}
	}
}

int example_main(
	const eagine::program_args& args,
	oglplus::example_params& params,
	oglplus::example_state& state
)
{
	auto errstr = [&args](void) -> std::ostream&
	{
		return std::cerr
			<< args.command()
			<< ": ";
	};

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		errstr()
			<< "SDL initialization error: "
			<< SDL_GetError()
			<< std::endl;
		return 2;
	}

	auto ensure_sdl_cleanup = eagine::finally(SDL_Quit);

	if(!SDL_SetVideoMode(
		state.width(), state.height(),
		32,
		SDL_HWSURFACE |
		SDL_GL_DOUBLEBUFFER |
		SDL_OPENGL
	))
	{
		errstr()
			<< SDL_GetError()
			<< std::endl;
		return 2;
	}
	SDL_WM_SetCaption("OGLplus example", nullptr);


	oglplus::api_initializer gl_api_init;

	std::srand(params.rand_seed());

	state.set_depth(16);

	oglplus::example_wrapper example(params, state);

	example_loop(state, example);

	return 0;
}

