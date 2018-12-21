/**
 *  @file eglplus/egl.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_HPP
#define EGLPLUS_EGL_HPP

#if defined(EAGINE_YCM)
#if __has_include(<EGL/egl.h>)
#include <EGL/egl.h>
#endif
#else // EAGINE_YCM
#include <EGL/egl.h>
#endif // EAGINE_YCM
// TODO

#endif // EGLPLUS_EGL_HPP
