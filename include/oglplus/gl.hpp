/**
 *  @file oglplus/gl.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_1509260923_HPP
#define OGLPLUS_GL_1509260923_HPP

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif

#include <oglplus/config/basic.hpp>

#ifndef OGLPLUS_USE_GLCOREARB_H
#define OGLPLUS_USE_GLCOREARB_H 1
#endif

#ifndef OGLPLUS_USE_GL3_H
#define OGLPLUS_USE_GL3_H 0
#endif

#ifndef OGLPLUS_USE_GLEW
#define OGLPLUS_USE_GLEW 0
#endif

#ifndef OGLPLUS_USE_GL3W
#define OGLPLUS_USE_GL3W 0
#endif

#ifndef OGLPLUS_NO_GL

namespace oglplus {

struct api_initializer
{
	api_initializer(const api_initializer&) = delete;

	api_initializer(int /*gl_ver_major*/ = 3, int /*gl_ver_minor*/ = 3);
	~api_initializer(void);
};

} // namespace oglplus

# if OGLPLUS_USE_GLCOREARB_H
#  define GLCOREARB_PROTOTYPES
#  define GL_GLEXT_PROTOTYPES
#  include <GL/glcorearb.h>
#  include <GL/glext.h>

# elif OGLPLUS_USE_GL3_H
#  define GL3_PROTOTYPES
#  ifdef __APPLE__
#   include <OpenGL/gl3.h>
#  else
#   include <GL3/gl3.h>
#  endif
#  define __gl_h_
#  define __gl_h__
#  define __glext_h_
#  define __glext_h__

# elif OGLPLUS_USE_GLEW
#  include <GL/glew.h>

# elif OGLPLUS_USE_GL3W
#  define GL3_PROTOTYPES
#  include <GL/gl3w.h>

# else
#  error "Some library including OpenGL symbols is required!"
# endif // OGLPLUS_USE_*

#endif // OGLPLUS_NO_GL

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/gl.inl>
#endif

#endif // include guard
