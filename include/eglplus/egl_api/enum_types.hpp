/**
 *  @file eglplus/egl_api/enum_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_ENUM_TYPES_HPP
#define EGLPLUS_EGL_API_ENUM_TYPES_HPP

#include "enum_class.hpp"

namespace eagine::eglp {
//------------------------------------------------------------------------------
struct error_code : egl_enum_class<error_code, EAGINE_ID_V(ErrorCode)> {
    using enum_class::enum_class;
};

struct platform : egl_enum_class<platform, EAGINE_ID_V(Platform)> {
    using enum_class::enum_class;
};

struct platform_attribute
  : egl_enum_class<platform_attribute, EAGINE_ID_V(PltfrmAttr)> {
    using enum_class::enum_class;
};

struct string_query : egl_enum_class<string_query, EAGINE_ID_V(StrQuery)> {
    using enum_class::enum_class;
};

struct device_string_query
  : egl_enum_class<device_string_query, EAGINE_ID_V(DevStrQury)> {
    using enum_class::enum_class;
};

struct config_attribute
  : egl_enum_class<config_attribute, EAGINE_ID_V(ConfAttrib)> {
    using enum_class::enum_class;
};

struct config_caveat : egl_enum_class<config_caveat, EAGINE_ID_V(ConfCaveat)> {
    using enum_class::enum_class;
};

struct surface_attribute
  : egl_enum_class<surface_attribute, EAGINE_ID_V(SurfAttrib)> {
    using enum_class::enum_class;
};

struct surface_type_bit
  : egl_enum_class<surface_type_bit, EAGINE_ID_V(SurfTypBit)> {
    using enum_class::enum_class;
};

struct renderable_type_bit
  : egl_enum_class<renderable_type_bit, EAGINE_ID_V(RndrTypBit)> {
    using enum_class::enum_class;
};

struct client_api : egl_enum_class<client_api, EAGINE_ID_V(ClientApi)> {
    using enum_class::enum_class;
};

struct client_api_bit
  : egl_enum_class<client_api_bit, EAGINE_ID_V(ClntApiBit)> {
    using enum_class::enum_class;
};

struct context_attribute
  : egl_enum_class<context_attribute, EAGINE_ID_V(CtxtAttrib)> {
    using enum_class::enum_class;
};

struct context_opengl_profile_bit
  : egl_enum_class<context_opengl_profile_bit, EAGINE_ID_V(OGLPrflBit)> {
    using enum_class::enum_class;
};

struct stream_attribute
  : egl_enum_class<stream_attribute, EAGINE_ID_V(StreamAttr)> {
    using enum_class::enum_class;
};

struct sync_type : egl_enum_class<sync_type, EAGINE_ID_V(SyncType)> {
    using enum_class::enum_class;
};

struct sync_attribute
  : egl_enum_class<sync_attribute, EAGINE_ID_V(SyncAttrib)> {
    using enum_class::enum_class;
};

struct color_buffer_type
  : egl_enum_class<color_buffer_type, EAGINE_ID_V(ClrBufType)> {
    using enum_class::enum_class;
};

struct read_draw : egl_enum_class<read_draw, EAGINE_ID_V(ReadDraw)> {
    using enum_class::enum_class;
};

struct texture_format : egl_enum_class<texture_format, EAGINE_ID_V(TexFormat)> {
    using enum_class::enum_class;
};

struct texture_target : egl_enum_class<texture_target, EAGINE_ID_V(TexTarget)> {
    using enum_class::enum_class;
};

struct gl_colorspace : egl_enum_class<gl_colorspace, EAGINE_ID_V(GLClrspace)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_ENUM_TYPES_HPP
