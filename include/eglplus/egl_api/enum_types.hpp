/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EGLPLUS_EGL_API_ENUM_TYPES_HPP
#define EGLPLUS_EGL_API_ENUM_TYPES_HPP

#include "enum_class.hpp"

namespace eagine::eglp {
//------------------------------------------------------------------------------
/// @brief Wrapper for true, false EGL enums.
/// @ingroup egl_api_wrap
struct true_false : egl_enum_class<true_false, EAGINE_ID_V(TrueFalse)> {
    using enum_class::enum_class;

    constexpr explicit operator bool() const noexcept {
#ifdef EGL_TRUE
        return this->_value == EGL_TRUE;
#else
        return false;
#endif
    }
};

/// @brief Typed enumeration for EGL error code constants.
/// @ingroup egl_api_wrap
struct error_code : egl_enum_class<error_code, EAGINE_ID_V(ErrorCode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL platform constants.
/// @ingroup egl_api_wrap
struct platform : egl_enum_class<platform, EAGINE_ID_V(Platform)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL platform attribute constants.
/// @ingroup egl_api_wrap
struct platform_attribute
  : egl_enum_class<platform_attribute, EAGINE_ID_V(PltfrmAttr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL string query constants.
/// @ingroup egl_api_wrap
struct string_query : egl_enum_class<string_query, EAGINE_ID_V(StrQuery)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL device string query constants.
/// @ingroup egl_api_wrap
struct device_string_query
  : egl_enum_class<device_string_query, EAGINE_ID_V(DevStrQury)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL config attribute constants.
/// @ingroup egl_api_wrap
struct config_attribute
  : egl_enum_class<config_attribute, EAGINE_ID_V(ConfAttrib)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL config caveat constants.
/// @ingroup egl_api_wrap
struct config_caveat : egl_enum_class<config_caveat, EAGINE_ID_V(ConfCaveat)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL surface attribute constants.
/// @ingroup egl_api_wrap
struct surface_attribute
  : egl_enum_class<surface_attribute, EAGINE_ID_V(SurfAttrib)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL surface type bit constants.
/// @ingroup egl_api_wrap
struct surface_type_bit
  : egl_enum_class<surface_type_bit, EAGINE_ID_V(SurfTypBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL renderable type bit constants.
/// @ingroup egl_api_wrap
struct renderable_type_bit
  : egl_enum_class<renderable_type_bit, EAGINE_ID_V(RndrTypBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL client API type constants.
/// @ingroup egl_api_wrap
struct client_api : egl_enum_class<client_api, EAGINE_ID_V(ClientApi)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL client API bit constants.
/// @ingroup egl_api_wrap
struct client_api_bit
  : egl_enum_class<client_api_bit, EAGINE_ID_V(ClntApiBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL context attribute constants.
/// @ingroup egl_api_wrap
struct context_attribute
  : egl_enum_class<context_attribute, EAGINE_ID_V(CtxtAttrib)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL OpenGL profile bit constants.
/// @ingroup egl_api_wrap
struct context_opengl_profile_bit
  : egl_enum_class<context_opengl_profile_bit, EAGINE_ID_V(OGLPrflBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL stream attribute constants.
/// @ingroup egl_api_wrap
struct stream_attribute
  : egl_enum_class<stream_attribute, EAGINE_ID_V(StreamAttr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL stream state constants.
/// @ingroup egl_api_wrap
struct stream_state
  : egl_enum_class<stream_attribute, EAGINE_ID_V(StreamStat)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL output layer attribute constants.
/// @ingroup egl_api_wrap
struct output_layer_attribute
  : egl_enum_class<output_layer_attribute, EAGINE_ID_V(OutLyrAttr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL output layer string query constants.
/// @ingroup egl_api_wrap
struct output_layer_string_query
  : egl_enum_class<output_layer_string_query, EAGINE_ID_V(OutLyrStrQ)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL output port attribute constants.
/// @ingroup egl_api_wrap
struct output_port_attribute
  : egl_enum_class<output_port_attribute, EAGINE_ID_V(OutPrtAttr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL output port string query constants.
/// @ingroup egl_api_wrap
struct output_port_string_query
  : egl_enum_class<output_port_string_query, EAGINE_ID_V(OutPrtStrQ)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL image attribute constants.
/// @ingroup egl_api_wrap
struct image_attribute
  : egl_enum_class<image_attribute, EAGINE_ID_V(ImageAttr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL image target constants.
/// @ingroup egl_api_wrap
struct image_target : egl_enum_class<image_target, EAGINE_ID_V(ImgeTarget)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL sync object type constants.
/// @ingroup egl_api_wrap
struct sync_type : egl_enum_class<sync_type, EAGINE_ID_V(SyncType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL sync object attribute constants.
/// @ingroup egl_api_wrap
struct sync_attribute
  : egl_enum_class<sync_attribute, EAGINE_ID_V(SyncAttrib)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL color buffer type constants.
/// @ingroup egl_api_wrap
struct color_buffer_type
  : egl_enum_class<color_buffer_type, EAGINE_ID_V(ClrBufType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL color component type constants.
/// @ingroup egl_api_wrap
struct color_component_type
  : egl_enum_class<color_component_type, EAGINE_ID_V(ClrCmpType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL read/draw specifier constants.
/// @ingroup egl_api_wrap
struct read_draw : egl_enum_class<read_draw, EAGINE_ID_V(ReadDraw)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL texture format constants.
/// @ingroup egl_api_wrap
struct texture_format : egl_enum_class<texture_format, EAGINE_ID_V(TexFormat)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL texture target constants.
/// @ingroup egl_api_wrap
struct texture_target : egl_enum_class<texture_target, EAGINE_ID_V(TexTarget)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for EGL OpenGL colorspace constants.
/// @ingroup egl_api_wrap
struct gl_colorspace : egl_enum_class<gl_colorspace, EAGINE_ID_V(GLClrspace)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_ENUM_TYPES_HPP
