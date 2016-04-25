/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef UTILS_OGLPLUS_OS_CONTEXT_1107121519_HPP
#define UTILS_OGLPLUS_OS_CONTEXT_1107121519_HPP

#include <oglplus/config/site.hpp>

#if OGLPLUS_USE_GLX
#include "os_context_glx.hpp"
#elif OGLPLUS_USE_GLFW3
#include "os_context_glfw3.hpp"
#elif OGLPLUS_USE_GLFW
#include "os_context_glfw.hpp"
#elif OGLPLUS_USE_SDL
#include "os_context_sdl.hpp"
#elif OGLPLUS_USE_GLUT
#include "os_context_glut.hpp"
#endif

namespace oglplus {

#if OGLPLUS_USE_GLX
typedef offscreen_context_glx offscreen_context;
# define OGLPLUS_HAS_OS_CONTEXT 1
#elif OGLPLUS_USE_GLFW3
typedef offscreen_context_glfw3 offscreen_context;
# define OGLPLUS_HAS_OS_CONTEXT 1
#elif OGLPLUS_USE_GLFW
typedef offscreen_context_glfw offscreen_context;
# define OGLPLUS_HAS_OS_CONTEXT 1
#elif OGLPLUS_USE_SDL
typedef offscreen_context_sdl offscreen_context;
#elif OGLPLUS_USE_GLUT
# define OGLPLUS_HAS_OS_CONTEXT 1
typedef offscreen_context_glut offscreen_context;
#else
# define OGLPLUS_HAS_OS_CONTEXT 0
#endif

} // namespace oglplus

#endif
