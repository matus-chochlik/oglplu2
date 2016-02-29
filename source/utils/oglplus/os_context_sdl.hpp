/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef UTILS_OGLPLUS_OS_CONTEXT_SDL_1107121519_HPP
#define UTILS_OGLPLUS_OS_CONTEXT_SDL_1107121519_HPP

#include <SDL/SDL.h>
#include <stdexcept>
#include "os_context_common.hpp"

namespace oglplus {

class offscreen_context_sdl
{
public:
	offscreen_context_sdl(const offscreen_context_params& p)
	{
		if(SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			throw
			std::runtime_error("Failed to initialize SDL.");
		}

		if(!SDL_SetVideoMode(
			p.width, p.height, 32,
			SDL_HWSURFACE |
			SDL_GL_DOUBLEBUFFER |
			SDL_OPENGL
		))
		{
			SDL_Quit();
			throw
			std::runtime_error("Failed to set SDL video mode.");
		}
		SDL_WM_SetCaption(p.title, nullptr);
	}

	~offscreen_context_sdl(void)
	noexcept
	{
		try { SDL_Quit(); }
		catch(...) { }
	}
};

} // namespace oglplus

#endif
