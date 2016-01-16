/**
 *  @file oglplus/utils/gl_func.hpp
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


#ifndef OGLPLUS_GL_DSA_FUNC_NAME
# ifdef GL_VERSION_4_5
#  define OGLPLUS_GL_DSA_FUNC_NAME(FUNC) #FUNC
# elif defined(GL_EXT_direct_state_access)
#  define OGLPLUS_GL_DSA_FUNC_NAME(FUNC) #FUNC "EXT"
# endif
#endif


#if defined(__GLEW_H__)
#define OGLPLUS_DYN_LOADED_GL_FUNCTIONS 1
#else
#define OGLPLUS_DYN_LOADED_GL_FUNCTIONS 0
#endif

#endif // include guard
