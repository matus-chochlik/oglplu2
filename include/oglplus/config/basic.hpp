/**
 *  @file oglplus/config/basic.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CONFIG_BASIC_HPP
#define OGLPLUS_CONFIG_BASIC_HPP

#if __has_include(<oglplus/config/site.hpp>)
#include <oglplus/config/site.hpp>
#endif

#ifndef OGLPLUS_GLX_FOUND
#define OGLPLUS_GLX_FOUND 0
#endif

#ifndef OGLPLUS_GLFW3_FOUND
#define OGLPLUS_GLFW3_FOUND 0
#endif

#ifndef OGLPLUS_GLFW_FOUND
#define OGLPLUS_GLFW_FOUND 0
#endif

#ifndef OGLPLUS_GLUT_FOUND
#define OGLPLUS_GLUT_FOUND 0
#endif

#ifndef OGLPLUS_FREEGLUT_FOUND
#define OGLPLUS_FREEGLUT_FOUND 0
#endif

#ifndef OGLPLUS_SDL_FOUND
#define OGLPLUS_SDL_FOUND 0
#endif

#ifndef OGLPLUS_LOW_PROFILE
#define OGLPLUS_LOW_PROFILE 0
#endif

#ifndef OGLPLUS_NO_LIMIT_CHECKS
#define OGLPLUS_NO_LIMIT_CHECKS OGLPLUS_LOW_PROFILE
#endif

#ifndef OGLPLUS_LINK_LIBRARY
#define OGLPLUS_LINK_LIBRARY 0
#endif

#if OGLPLUS_LINK_LIBRARY
#define OGLPLUS_LIB_FUNC
#else
#define OGLPLUS_LIB_FUNC inline
#endif

#endif // OGLPLUS_CONFIG_BASIC_HPP
