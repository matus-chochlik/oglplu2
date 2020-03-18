/**
 *  @file oglplus/gl_def.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_DEF_HPP
#define OGLPLUS_GL_DEF_HPP

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif

#include <oglplus/config/basic.hpp>
//------------------------------------------------------------------------------
#if defined(__gl_glcorearb_h_)
#define OGLPLUS_GLCOREARB_DETECTED 1
#else
#define OGLPLUS_GLCOREARB_DETECTED 0
#endif
//------------------------------------------------------------------------------
#if defined(__glew_h__) || defined(__GLEW_H__)
#define OGLPLUS_GLEW_DETECTED 1
#else
#define OGLPLUS_GLEW_DETECTED 0
#endif
//------------------------------------------------------------------------------
#if OGLPLUS_GLCOREARB_DETECTED || OGLPLUS_GLEW_DETECTED
#undef OGLPLUS_USE_GLCOREARB_H
#undef OGLPLUS_USE_GLEW
#endif
//------------------------------------------------------------------------------
#ifndef OGLPLUS_USE_GLCOREARB_H
#if OGLPLUS_GLEW_DETECTED
#define OGLPLUS_USE_GLCOREARB_H 0
#else
#define OGLPLUS_USE_GLCOREARB_H 1
#endif
#endif
//------------------------------------------------------------------------------
#ifndef OGLPLUS_USE_GL3_GL3_H
#define OGLPLUS_USE_GL3_GL3_H 0
#endif
//------------------------------------------------------------------------------
#ifndef OGLPLUS_USE_GLES3_GL32_H
#define OGLPLUS_USE_GLES3_GL32_H 0
#endif
//------------------------------------------------------------------------------
#ifndef OGLPLUS_USE_GLES3_GL31_H
#define OGLPLUS_USE_GLES3_GL31_H 0
#endif
//------------------------------------------------------------------------------
#ifndef OGLPLUS_USE_GLES3_GL3_H
#define OGLPLUS_USE_GLES3_GL3_H 0
#endif
//------------------------------------------------------------------------------
#ifndef OGLPLUS_USE_GLEW
#if OGLPLUS_GLCOREARB_DETECTED
#define OGLPLUS_USE_GLEW 0
#else
#define OGLPLUS_USE_GLEW 1
#endif
#endif
//------------------------------------------------------------------------------
#ifndef OGLPLUS_USE_GL3W
#define OGLPLUS_USE_GL3W 0
#endif
//------------------------------------------------------------------------------
#ifndef OGLPLUS_NO_GL
//------------------------------------------------------------------------------
namespace eagine {
namespace oglp {

struct api_initializer {
    ~api_initializer() noexcept = default;
    api_initializer(const api_initializer&) = delete;
    api_initializer(api_initializer&&) = delete;
    api_initializer& operator=(const api_initializer&) = delete;
    api_initializer& operator=(api_initializer&&) = delete;

    explicit api_initializer(
      int /*gl_ver_major*/ = 3, int /*gl_ver_minor*/ = 3);
};

} // namespace oglp
} // namespace eagine
//------------------------------------------------------------------------------
#if OGLPLUS_USE_GLCOREARB_H
#define GLCOREARB_PROTOTYPES
#define GL_GLEXT_PROTOTYPES
#include <GL/glcorearb.h>
#include <GL/glext.h>
//------------------------------------------------------------------------------
#elif OGLPLUS_USE_GL3_GL3_H
#define GL3_PROTOTYPES
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL3/gl3.h>
#endif
#define __gl_h_
#define __gl_h__
#define __glext_h_
#define __glext_h__
//------------------------------------------------------------------------------
#elif OGLPLUS_USE_GLES3_GL32_H
#define GL3_PROTOTYPES
#include <GLES3/gl32.h>
//------------------------------------------------------------------------------
#elif OGLPLUS_USE_GLES3_GL31_H
#define GL3_PROTOTYPES
#include <GLES3/gl31.h>
//------------------------------------------------------------------------------
#elif OGLPLUS_USE_GLES3_GL3_H
#define GL3_PROTOTYPES
#include <GLES3/gl3.h>
//------------------------------------------------------------------------------
#elif OGLPLUS_USE_GLEW
#include <GL/glew.h>
//------------------------------------------------------------------------------
#elif OGLPLUS_USE_GL3W
#define GL3_PROTOTYPES
#include <GL/gl3w.h>
//------------------------------------------------------------------------------
#else
#error "Some library including OpenGL symbols is required!"
#endif // OGLPLUS_USE_*
//------------------------------------------------------------------------------
#endif // OGLPLUS_NO_GL
//------------------------------------------------------------------------------
#ifdef __clang__
#pragma clang diagnostic pop
#endif
//------------------------------------------------------------------------------
#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/gl_def.inl>
#endif
//------------------------------------------------------------------------------
#endif // OGLPLUS_GL_DEF_HPP
