/// @file
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
/// @brief Tag type denoting EGL device object.
/// @ingroup egl_api_wrap
/// @see device_handle
using device_tag = EAGINE_MSG_TYPE(egl, Device);

/// @brief Tag type denoting EGL display object.
/// @ingroup egl_api_wrap
/// @see display_handle
using display_tag = EAGINE_MSG_TYPE(egl, Display);

/// @brief Tag type denoting EGL surface object.
/// @ingroup egl_api_wrap
/// @see surface_handle
using surface_tag = EAGINE_MSG_TYPE(egl, Surface);

/// @brief Tag type denoting EGL context object.
/// @ingroup egl_api_wrap
/// @see context_handle
using context_tag = EAGINE_MSG_TYPE(egl, Context);

/// @brief Tag type denoting EGL stream object.
/// @ingroup egl_api_wrap
/// @see stream_handle
using stream_tag = EAGINE_MSG_TYPE(egl, Stream);

/// @brief Tag type denoting EGL image object.
/// @ingroup egl_api_wrap
/// @see image_handle
using image_tag = EAGINE_MSG_TYPE(egl, Image);

/// @brief Tag type denoting EGL output layer.
/// @ingroup egl_api_wrap
/// @see output_layer_handle
using output_layer_tag = EAGINE_MSG_TYPE(egl, OutLayer);

/// @brief Tag type denoting EGL output port.
/// @ingroup egl_api_wrap
/// @see output_port_handle
using output_port_tag = EAGINE_MSG_TYPE(egl, OutPort);

/// @brief Tag type denoting EGL sync object.
/// @ingroup egl_api_wrap
/// @see sync_handle
using sync_tag = EAGINE_MSG_TYPE(egl, Sync);
//------------------------------------------------------------------------------
/// @brief Alias for EGL device handle wrapper.
/// @ingroup egl_api_wrap
using device_handle = basic_handle<
  device_tag,
  egl_types::device_type,
  egl_types::device_type(nullptr)>;
//------------------------------------------------------------------------------
#if defined(EGL_NO_DISPLAY)
using display_handle =
  basic_handle<display_tag, egl_types::display_type, EGL_NO_DISPLAY>;
#else
/// @brief Alias for EGL display  handle wrapper.
/// @ingroup egl_api_wrap
using display_handle = basic_handle<display_tag, nothing_t>;
#endif
//------------------------------------------------------------------------------
#if defined(EGL_NO_SURFACE)
using surface_handle =
  basic_handle<surface_tag, egl_types::surface_type, EGL_NO_SURFACE>;
#else
/// @brief Alias for EGL surface handle wrapper.
/// @ingroup egl_api_wrap
using surface_handle = basic_handle<surface_tag, nothing_t>;
#endif
//------------------------------------------------------------------------------
#if defined(EGL_NO_CONTEXT)
using context_handle =
  basic_handle<context_tag, egl_types::context_type, EGL_NO_CONTEXT>;
#else
/// @brief Alias for EGL context handle wrapper.
/// @ingroup egl_api_wrap
using context_handle = basic_handle<context_tag, nothing_t>;
#endif
//------------------------------------------------------------------------------
/// @brief Alias for EGL stream handle wrapper.
/// @ingroup egl_api_wrap
using stream_handle = basic_handle<
  stream_tag,
  egl_types::stream_type,
  egl_types::stream_type(nullptr)>;
//------------------------------------------------------------------------------
#if defined(EGL_NO_IMAGE)
using image_handle =
  basic_handle<image_tag, egl_types::image_type, EGL_NO_IMAGE>;
#else
/// @brief Alias for EGL image handle wrapper.
/// @ingroup egl_api_wrap
using image_handle = basic_handle<image_tag, nothing_t>;
#endif
//------------------------------------------------------------------------------
/// @brief Alias for EGL output layer handle wrapper.
/// @ingroup egl_api_wrap
using output_layer_handle = basic_handle<
  stream_tag,
  egl_types::output_layer_type,
  egl_types::output_layer_type(nullptr)>;
//------------------------------------------------------------------------------
/// @brief Alias for EGL output port handle wrapper.
/// @ingroup egl_api_wrap
using output_port_handle = basic_handle<
  stream_tag,
  egl_types::output_port_type,
  egl_types::output_port_type(nullptr)>;
//------------------------------------------------------------------------------
#if defined(EGL_NO_SYNC)
using sync_handle = basic_handle<sync_tag, egl_types::sync_type, EGL_NO_SYNC>;
#else
/// @brief Alias for EGL sync object handle wrapper.
/// @ingroup egl_api_wrap
using sync_handle = basic_handle<sync_tag, nothing_t>;
#endif
//------------------------------------------------------------------------------
} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_OBJECTS_HPP
