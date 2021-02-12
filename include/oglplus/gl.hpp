/// @file oglplus/gl.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GL_HPP
#define OGLPLUS_GL_HPP

#include <oglplus/gl_def.hpp>
#if __has_include(<oglplus/config/fix_gl_version.hpp>)
#include <oglplus/config/fix_gl_version.hpp>
#endif
#if __has_include(<oglplus/config/fix_gl_extension.hpp>)
#include <oglplus/config/fix_gl_extension.hpp>
#endif

#ifndef GL_SHADER
#define GL_SHADER 0x82E1
#endif

#ifndef GL_PROGRAM
#define GL_PROGRAM 0x82E2
#endif

#ifndef GL_PROGRAM_PIPELINE
#define GL_PROGRAM_PIPELINE 0x82E4
#endif

#ifndef APIENTRY
#define APIENTRY
#endif

#endif
