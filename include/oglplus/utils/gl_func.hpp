/**
 *  @file oglplus/utils/glfunc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_GLFUNC_1509260942_HPP
#define OGLPLUS_UTILS_GLFUNC_1509260942_HPP

#ifndef OGLPLUS_GLFUNC
#define OGLPLUS_GLFUNC(FUNCNAME) ::gl##FUNCNAME
#endif
#ifndef OGLPLUS_GLXFUNC
#define OGLPLUS_GLXFUNC(FUNCNAME) ::glX##FUNCNAME
#endif
#ifndef OGLPLUS_WGLFUNC
#define OGLPLUS_WGLFUNC(FUNCNAME) ::wgl##FUNCNAME
#endif

#if defined(__GLEW_H__)
#define OGLPLUS_DYN_LOADED_GL_FUNCTIONS 1
#else
#define OGLPLUS_DYN_LOADED_GL_FUNCTIONS 0
#endif

#endif // include guard
