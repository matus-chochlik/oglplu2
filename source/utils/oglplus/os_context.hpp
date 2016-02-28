/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef UTILS_OGLPLUS_OS_CONTEXT_1107121519_HPP
#define UTILS_OGLPLUS_OS_CONTEXT_1107121519_HPP

#include <oglplus/config/site.hpp>

#if OGLPLUS_GLX_FOUND
#include "os_context_glx.hpp"
#elif OGLPLUS_GLFW3_FOUND
#include "os_context_glfw3.hpp"
#elif OGLPLUS_GLFW_FOUND
#include "os_context_glfw.hpp"
#elif OGLPLUS_GLUT_FOUND
# if defined(__APPLE__) && __APPLE__
# include <GLUT/glut.h>
# else
# include <GL/glut.h>
# endif
#elif OGLPLUS_SDL_FOUND
#include <SDL/SDL.h>
#endif

namespace oglplus {

#if OGLPLUS_GLX_FOUND
typedef offscreen_context_glx offscreen_context;
#elif OGLPLUS_GLFW3_FOUND
typedef offscreen_context_glfw3 offscreen_context;
#elif OGLPLUS_GLFW_FOUND
typedef offscreen_context_glfw offscreen_context;
#elif OGLPLUS_GLUT_FOUND
#elif OGLPLUS_SDL_FOUND
#endif

} // namespace oglplus

#endif
