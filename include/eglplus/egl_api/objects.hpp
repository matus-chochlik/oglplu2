/// @file eglplus/egl_api/objects.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EGLPLUS_EGL_API_OBJECTS_HPP
#define EGLPLUS_EGL_API_OBJECTS_HPP

#include "config.hpp"
#include <eagine/handle.hpp>
#include <eagine/message_id.hpp>

namespace eagine::eglp {
//------------------------------------------------------------------------------
using device_tag = EAGINE_MSG_TYPE(egl, Device);
using display_tag = EAGINE_MSG_TYPE(egl, Display);
using surface_tag = EAGINE_MSG_TYPE(egl, Surface);
using context_tag = EAGINE_MSG_TYPE(egl, Context);
using stream_tag = EAGINE_MSG_TYPE(egl, Stream);
using image_tag = EAGINE_MSG_TYPE(egl, Image);
using output_layer_tag = EAGINE_MSG_TYPE(egl, OutLayer);
using output_port_tag = EAGINE_MSG_TYPE(egl, OutPort);
using sync_tag = EAGINE_MSG_TYPE(egl, Sync);
//------------------------------------------------------------------------------
using device_handle = basic_handle<
  device_tag,
  egl_types::device_type,
  egl_types::device_type(nullptr)>;
//------------------------------------------------------------------------------
#if defined(EGL_NO_DISPLAY)
using display_handle =
  basic_handle<display_tag, egl_types::display_type, EGL_NO_DISPLAY>;
#else
using display_handle = basic_handle<display_tag, nothing_t>;
#endif
//------------------------------------------------------------------------------
#if defined(EGL_NO_SURFACE)
using surface_handle =
  basic_handle<surface_tag, egl_types::surface_type, EGL_NO_SURFACE>;
#else
using surface_handle = basic_handle<surface_tag, nothing_t>;
#endif
//------------------------------------------------------------------------------
#if defined(EGL_NO_CONTEXT)
using context_handle =
  basic_handle<context_tag, egl_types::context_type, EGL_NO_CONTEXT>;
#else
using context_handle = basic_handle<context_tag, nothing_t>;
#endif
//------------------------------------------------------------------------------
using stream_handle = basic_handle<
  stream_tag,
  egl_types::stream_type,
  egl_types::stream_type(nullptr)>;
//------------------------------------------------------------------------------
#if defined(EGL_NO_IMAGE)
using image_handle =
  basic_handle<image_tag, egl_types::image_type, EGL_NO_IMAGE>;
#else
using image_handle = basic_handle<image_tag, nothing_t>;
#endif
//------------------------------------------------------------------------------
using output_layer_handle = basic_handle<
  stream_tag,
  egl_types::output_layer_type,
  egl_types::output_layer_type(nullptr)>;
//------------------------------------------------------------------------------
using output_port_handle = basic_handle<
  stream_tag,
  egl_types::output_port_type,
  egl_types::output_port_type(nullptr)>;
//------------------------------------------------------------------------------
#if defined(EGL_NO_SYNC)
using sync_handle = basic_handle<sync_tag, egl_types::sync_type, EGL_NO_SYNC>;
#else
using sync_handle = basic_handle<sync_tag, nothing_t>;
#endif
//------------------------------------------------------------------------------
} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_OBJECTS_HPP
