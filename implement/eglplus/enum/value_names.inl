//  File implement/eglplus/enum/value_names.inl
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/eglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//

#include <eagine/maybe_unused.hpp>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4065)
#endif //_MSC_VER

namespace eglplus {

EGLPLUS_LIB_FUNC
string_view get_enum_value_name( // NOLINT(hicpp-function-size)

  const any_enum_value& aev) noexcept {
#ifdef EGL_ALPHA_MASK_SIZE
    static const char* s_ALPHA_MASK_SIZE = "ALPHA_MASK_SIZE";
#endif
#ifdef EGL_ALPHA_SIZE
    static const char* s_ALPHA_SIZE = "ALPHA_SIZE";
#endif
#ifdef EGL_BACK_BUFFER
    static const char* s_BACK_BUFFER = "BACK_BUFFER";
#endif
#ifdef EGL_BAD_ACCESS
    static const char* s_BAD_ACCESS = "BAD_ACCESS";
#endif
#ifdef EGL_BAD_ALLOC
    static const char* s_BAD_ALLOC = "BAD_ALLOC";
#endif
#ifdef EGL_BAD_ATTRIBUTE
    static const char* s_BAD_ATTRIBUTE = "BAD_ATTRIBUTE";
#endif
#ifdef EGL_BAD_CONFIG
    static const char* s_BAD_CONFIG = "BAD_CONFIG";
#endif
#ifdef EGL_BAD_CONTEXT
    static const char* s_BAD_CONTEXT = "BAD_CONTEXT";
#endif
#ifdef EGL_BAD_CURRENT_SURFACE
    static const char* s_BAD_CURRENT_SURFACE = "BAD_CURRENT_SURFACE";
#endif
#ifdef EGL_BAD_DISPLAY
    static const char* s_BAD_DISPLAY = "BAD_DISPLAY";
#endif
#ifdef EGL_BAD_MATCH
    static const char* s_BAD_MATCH = "BAD_MATCH";
#endif
#ifdef EGL_BAD_NATIVE_PIXMAP
    static const char* s_BAD_NATIVE_PIXMAP = "BAD_NATIVE_PIXMAP";
#endif
#ifdef EGL_BAD_NATIVE_WINDOW
    static const char* s_BAD_NATIVE_WINDOW = "BAD_NATIVE_WINDOW";
#endif
#ifdef EGL_BAD_PARAMETER
    static const char* s_BAD_PARAMETER = "BAD_PARAMETER";
#endif
#ifdef EGL_BAD_SURFACE
    static const char* s_BAD_SURFACE = "BAD_SURFACE";
#endif
#ifdef EGL_BIND_TO_TEXTURE_RGB
    static const char* s_BIND_TO_TEXTURE_RGB = "BIND_TO_TEXTURE_RGB";
#endif
#ifdef EGL_BIND_TO_TEXTURE_RGBA
    static const char* s_BIND_TO_TEXTURE_RGBA = "BIND_TO_TEXTURE_RGBA";
#endif
#ifdef EGL_BLUE_SIZE
    static const char* s_BLUE_SIZE = "BLUE_SIZE";
#endif
#ifdef EGL_BUFFER_DESTROYED
    static const char* s_BUFFER_DESTROYED = "BUFFER_DESTROYED";
#endif
#ifdef EGL_BUFFER_PRESERVED
    static const char* s_BUFFER_PRESERVED = "BUFFER_PRESERVED";
#endif
#ifdef EGL_BUFFER_SIZE
    static const char* s_BUFFER_SIZE = "BUFFER_SIZE";
#endif
#ifdef EGL_CLIENT_APIS
    static const char* s_CLIENT_APIS = "CLIENT_APIS";
#endif
#ifdef EGL_COLOR_BUFFER_TYPE
    static const char* s_COLOR_BUFFER_TYPE = "COLOR_BUFFER_TYPE";
#endif
#ifdef EGL_CONFIG_CAVEAT
    static const char* s_CONFIG_CAVEAT = "CONFIG_CAVEAT";
#endif
#ifdef EGL_CONFIG_ID
    static const char* s_CONFIG_ID = "CONFIG_ID";
#endif
#ifdef EGL_CONFORMANT
    static const char* s_CONFORMANT = "CONFORMANT";
#endif
#ifdef EGL_CONTEXT_FLAGS
    static const char* s_CONTEXT_FLAGS = "CONTEXT_FLAGS";
#endif
#ifdef EGL_CONTEXT_LOST
    static const char* s_CONTEXT_LOST = "CONTEXT_LOST";
#endif
#ifdef EGL_CONTEXT_MAJOR_VERSION
    static const char* s_CONTEXT_MAJOR_VERSION = "CONTEXT_MAJOR_VERSION";
#endif
#ifdef EGL_CONTEXT_MINOR_VERSION
    static const char* s_CONTEXT_MINOR_VERSION = "CONTEXT_MINOR_VERSION";
#endif
#ifdef EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
    static const char* s_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT =
      "CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT";
#endif
#ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
    static const char* s_CONTEXT_OPENGL_CORE_PROFILE_BIT =
      "CONTEXT_OPENGL_CORE_PROFILE_BIT";
#endif
#ifdef EGL_CONTEXT_OPENGL_DEBUG_BIT
    static const char* s_CONTEXT_OPENGL_DEBUG_BIT = "CONTEXT_OPENGL_DEBUG_BIT";
#endif
#ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT
    static const char* s_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT =
      "CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT";
#endif
#ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
    static const char* s_CONTEXT_OPENGL_PROFILE_MASK =
      "CONTEXT_OPENGL_PROFILE_MASK";
#endif
#ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
    static const char* s_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY =
      "CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY";
#endif
#ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
    static const char* s_CONTEXT_OPENGL_ROBUST_ACCESS_BIT =
      "CONTEXT_OPENGL_ROBUST_ACCESS_BIT";
#endif
#ifdef EGL_DEPTH_SIZE
    static const char* s_DEPTH_SIZE = "DEPTH_SIZE";
#endif
#ifdef EGL_EXTENSIONS
    static const char* s_EXTENSIONS = "EXTENSIONS";
#endif
#ifdef EGL_GL_COLORSPACE
    static const char* s_GL_COLORSPACE = "GL_COLORSPACE";
#endif
#ifdef EGL_GL_COLORSPACE_LINEAR
    static const char* s_GL_COLORSPACE_LINEAR = "GL_COLORSPACE_LINEAR";
#endif
#ifdef EGL_GL_COLORSPACE_sRGB
    static const char* s_GL_COLORSPACE_sRGB = "GL_COLORSPACE_sRGB";
#endif
#ifdef EGL_GREEN_SIZE
    static const char* s_GREEN_SIZE = "GREEN_SIZE";
#endif
#ifdef EGL_HEIGHT
    static const char* s_HEIGHT = "HEIGHT";
#endif
#ifdef EGL_HORIZONTAL_RESOLUTION
    static const char* s_HORIZONTAL_RESOLUTION = "HORIZONTAL_RESOLUTION";
#endif
#ifdef EGL_LARGEST_PBUFFER
    static const char* s_LARGEST_PBUFFER = "LARGEST_PBUFFER";
#endif
#ifdef EGL_LEVEL
    static const char* s_LEVEL = "LEVEL";
#endif
#ifdef EGL_LOSE_CONTEXT_ON_RESET
    static const char* s_LOSE_CONTEXT_ON_RESET = "LOSE_CONTEXT_ON_RESET";
#endif
#ifdef EGL_LUMINANCE_BUFFER
    static const char* s_LUMINANCE_BUFFER = "LUMINANCE_BUFFER";
#endif
#ifdef EGL_LUMINANCE_SIZE
    static const char* s_LUMINANCE_SIZE = "LUMINANCE_SIZE";
#endif
#ifdef EGL_MAX_PBUFFER_HEIGHT
    static const char* s_MAX_PBUFFER_HEIGHT = "MAX_PBUFFER_HEIGHT";
#endif
#ifdef EGL_MAX_PBUFFER_PIXELS
    static const char* s_MAX_PBUFFER_PIXELS = "MAX_PBUFFER_PIXELS";
#endif
#ifdef EGL_MAX_PBUFFER_WIDTH
    static const char* s_MAX_PBUFFER_WIDTH = "MAX_PBUFFER_WIDTH";
#endif
#ifdef EGL_MAX_SWAP_INTERVAL
    static const char* s_MAX_SWAP_INTERVAL = "MAX_SWAP_INTERVAL";
#endif
#ifdef EGL_MIN_SWAP_INTERVAL
    static const char* s_MIN_SWAP_INTERVAL = "MIN_SWAP_INTERVAL";
#endif
#ifdef EGL_MIPMAP_LEVEL
    static const char* s_MIPMAP_LEVEL = "MIPMAP_LEVEL";
#endif
#ifdef EGL_MIPMAP_TEXTURE
    static const char* s_MIPMAP_TEXTURE = "MIPMAP_TEXTURE";
#endif
#ifdef EGL_MULTISAMPLE_RESOLVE
    static const char* s_MULTISAMPLE_RESOLVE = "MULTISAMPLE_RESOLVE";
#endif
#ifdef EGL_MULTISAMPLE_RESOLVE_BOX
    static const char* s_MULTISAMPLE_RESOLVE_BOX = "MULTISAMPLE_RESOLVE_BOX";
#endif
#ifdef EGL_MULTISAMPLE_RESOLVE_BOX_BIT
    static const char* s_MULTISAMPLE_RESOLVE_BOX_BIT =
      "MULTISAMPLE_RESOLVE_BOX_BIT";
#endif
#ifdef EGL_MULTISAMPLE_RESOLVE_DEFAULT
    static const char* s_MULTISAMPLE_RESOLVE_DEFAULT =
      "MULTISAMPLE_RESOLVE_DEFAULT";
#endif
#ifdef EGL_NATIVE_RENDERABLE
    static const char* s_NATIVE_RENDERABLE = "NATIVE_RENDERABLE";
#endif
#ifdef EGL_NATIVE_VISUAL_ID
    static const char* s_NATIVE_VISUAL_ID = "NATIVE_VISUAL_ID";
#endif
#ifdef EGL_NATIVE_VISUAL_TYPE
    static const char* s_NATIVE_VISUAL_TYPE = "NATIVE_VISUAL_TYPE";
#endif
#ifdef EGL_NONE
    static const char* s_NONE = "NONE";
#endif
#ifdef EGL_NON_CONFORMANT_CONFIG
    static const char* s_NON_CONFORMANT_CONFIG = "NON_CONFORMANT_CONFIG";
#endif
#ifdef EGL_NOT_INITIALIZED
    static const char* s_NOT_INITIALIZED = "NOT_INITIALIZED";
#endif
#ifdef EGL_NO_RESET_NOTIFICATION
    static const char* s_NO_RESET_NOTIFICATION = "NO_RESET_NOTIFICATION";
#endif
#ifdef EGL_NO_TEXTURE
    static const char* s_NO_TEXTURE = "NO_TEXTURE";
#endif
#ifdef EGL_OPENGL_API
    static const char* s_OPENGL_API = "OPENGL_API";
#endif
#ifdef EGL_OPENGL_BIT
    static const char* s_OPENGL_BIT = "OPENGL_BIT";
#endif
#ifdef EGL_OPENGL_ES2_BIT
    static const char* s_OPENGL_ES2_BIT = "OPENGL_ES2_BIT";
#endif
#ifdef EGL_OPENGL_ES3_BIT
    static const char* s_OPENGL_ES3_BIT = "OPENGL_ES3_BIT";
#endif
#ifdef EGL_OPENGL_ES_API
    static const char* s_OPENGL_ES_API = "OPENGL_ES_API";
#endif
#ifdef EGL_OPENGL_ES_BIT
    static const char* s_OPENGL_ES_BIT = "OPENGL_ES_BIT";
#endif
#ifdef EGL_OPENVG_API
    static const char* s_OPENVG_API = "OPENVG_API";
#endif
#ifdef EGL_OPENVG_BIT
    static const char* s_OPENVG_BIT = "OPENVG_BIT";
#endif
#ifdef EGL_PBUFFER_BIT
    static const char* s_PBUFFER_BIT = "PBUFFER_BIT";
#endif
#ifdef EGL_PIXEL_ASPECT_RATIO
    static const char* s_PIXEL_ASPECT_RATIO = "PIXEL_ASPECT_RATIO";
#endif
#ifdef EGL_PIXMAP_BIT
    static const char* s_PIXMAP_BIT = "PIXMAP_BIT";
#endif
#ifdef EGL_RED_SIZE
    static const char* s_RED_SIZE = "RED_SIZE";
#endif
#ifdef EGL_RENDERABLE_TYPE
    static const char* s_RENDERABLE_TYPE = "RENDERABLE_TYPE";
#endif
#ifdef EGL_RENDER_BUFFER
    static const char* s_RENDER_BUFFER = "RENDER_BUFFER";
#endif
#ifdef EGL_RGB_BUFFER
    static const char* s_RGB_BUFFER = "RGB_BUFFER";
#endif
#ifdef EGL_SAMPLES
    static const char* s_SAMPLES = "SAMPLES";
#endif
#ifdef EGL_SAMPLE_BUFFERS
    static const char* s_SAMPLE_BUFFERS = "SAMPLE_BUFFERS";
#endif
#ifdef EGL_SINGLE_BUFFER
    static const char* s_SINGLE_BUFFER = "SINGLE_BUFFER";
#endif
#ifdef EGL_SLOW_CONFIG
    static const char* s_SLOW_CONFIG = "SLOW_CONFIG";
#endif
#ifdef EGL_STENCIL_SIZE
    static const char* s_STENCIL_SIZE = "STENCIL_SIZE";
#endif
#ifdef EGL_SURFACE_TYPE
    static const char* s_SURFACE_TYPE = "SURFACE_TYPE";
#endif
#ifdef EGL_SWAP_BEHAVIOR
    static const char* s_SWAP_BEHAVIOR = "SWAP_BEHAVIOR";
#endif
#ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
    static const char* s_SWAP_BEHAVIOR_PRESERVED_BIT =
      "SWAP_BEHAVIOR_PRESERVED_BIT";
#endif
#ifdef EGL_TEXTURE_2D
    static const char* s_TEXTURE_2D = "TEXTURE_2D";
#endif
#ifdef EGL_TEXTURE_FORMAT
    static const char* s_TEXTURE_FORMAT = "TEXTURE_FORMAT";
#endif
#ifdef EGL_TEXTURE_RGB
    static const char* s_TEXTURE_RGB = "TEXTURE_RGB";
#endif
#ifdef EGL_TEXTURE_RGBA
    static const char* s_TEXTURE_RGBA = "TEXTURE_RGBA";
#endif
#ifdef EGL_TEXTURE_TARGET
    static const char* s_TEXTURE_TARGET = "TEXTURE_TARGET";
#endif
#ifdef EGL_TRANSPARENT_BLUE_VALUE
    static const char* s_TRANSPARENT_BLUE_VALUE = "TRANSPARENT_BLUE_VALUE";
#endif
#ifdef EGL_TRANSPARENT_GREEN_VALUE
    static const char* s_TRANSPARENT_GREEN_VALUE = "TRANSPARENT_GREEN_VALUE";
#endif
#ifdef EGL_TRANSPARENT_RED_VALUE
    static const char* s_TRANSPARENT_RED_VALUE = "TRANSPARENT_RED_VALUE";
#endif
#ifdef EGL_TRANSPARENT_RGB
    static const char* s_TRANSPARENT_RGB = "TRANSPARENT_RGB";
#endif
#ifdef EGL_TRANSPARENT_TYPE
    static const char* s_TRANSPARENT_TYPE = "TRANSPARENT_TYPE";
#endif
#ifdef EGL_VENDOR
    static const char* s_VENDOR = "VENDOR";
#endif
#ifdef EGL_VERSION
    static const char* s_VERSION = "VERSION";
#endif
#ifdef EGL_VERTICAL_RESOLUTION
    static const char* s_VERTICAL_RESOLUTION = "VERTICAL_RESOLUTION";
#endif
#ifdef EGL_VG_ALPHA_FORMAT
    static const char* s_VG_ALPHA_FORMAT = "VG_ALPHA_FORMAT";
#endif
#ifdef EGL_VG_ALPHA_FORMAT_NONPRE
    static const char* s_VG_ALPHA_FORMAT_NONPRE = "VG_ALPHA_FORMAT_NONPRE";
#endif
#ifdef EGL_VG_ALPHA_FORMAT_PRE
    static const char* s_VG_ALPHA_FORMAT_PRE = "VG_ALPHA_FORMAT_PRE";
#endif
#ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
    static const char* s_VG_ALPHA_FORMAT_PRE_BIT = "VG_ALPHA_FORMAT_PRE_BIT";
#endif
#ifdef EGL_VG_COLORSPACE
    static const char* s_VG_COLORSPACE = "VG_COLORSPACE";
#endif
#ifdef EGL_VG_COLORSPACE_LINEAR
    static const char* s_VG_COLORSPACE_LINEAR = "VG_COLORSPACE_LINEAR";
#endif
#ifdef EGL_VG_COLORSPACE_LINEAR_BIT
    static const char* s_VG_COLORSPACE_LINEAR_BIT = "VG_COLORSPACE_LINEAR_BIT";
#endif
#ifdef EGL_VG_COLORSPACE_sRGB
    static const char* s_VG_COLORSPACE_sRGB = "VG_COLORSPACE_sRGB";
#endif
#ifdef EGL_WIDTH
    static const char* s_WIDTH = "WIDTH";
#endif
#ifdef EGL_WINDOW_BIT
    static const char* s_WINDOW_BIT = "WINDOW_BIT";
#endif

    switch(aev._type_id) {
        case 0: /* color_buffer_type */
            switch(EGLenum(aev._value)) {
#ifdef EGL_LUMINANCE_BUFFER
                case EGL_LUMINANCE_BUFFER:
                    return {s_LUMINANCE_BUFFER, 16};
#endif
#ifdef EGL_RGB_BUFFER
                case EGL_RGB_BUFFER:
                    return {s_RGB_BUFFER, 10};
#endif
                default:;
            }
            break;
        case 1: /* config_attrib */
            switch(EGLenum(aev._value)) {
#ifdef EGL_ALPHA_MASK_SIZE
                case EGL_ALPHA_MASK_SIZE:
                    return {s_ALPHA_MASK_SIZE, 15};
#endif
#ifdef EGL_ALPHA_SIZE
                case EGL_ALPHA_SIZE:
                    return {s_ALPHA_SIZE, 10};
#endif
#ifdef EGL_BIND_TO_TEXTURE_RGB
                case EGL_BIND_TO_TEXTURE_RGB:
                    return {s_BIND_TO_TEXTURE_RGB, 19};
#endif
#ifdef EGL_BIND_TO_TEXTURE_RGBA
                case EGL_BIND_TO_TEXTURE_RGBA:
                    return {s_BIND_TO_TEXTURE_RGBA, 20};
#endif
#ifdef EGL_BLUE_SIZE
                case EGL_BLUE_SIZE:
                    return {s_BLUE_SIZE, 9};
#endif
#ifdef EGL_BUFFER_SIZE
                case EGL_BUFFER_SIZE:
                    return {s_BUFFER_SIZE, 11};
#endif
#ifdef EGL_COLOR_BUFFER_TYPE
                case EGL_COLOR_BUFFER_TYPE:
                    return {s_COLOR_BUFFER_TYPE, 17};
#endif
#ifdef EGL_CONFIG_CAVEAT
                case EGL_CONFIG_CAVEAT:
                    return {s_CONFIG_CAVEAT, 13};
#endif
#ifdef EGL_CONFIG_ID
                case EGL_CONFIG_ID:
                    return {s_CONFIG_ID, 9};
#endif
#ifdef EGL_CONFORMANT
                case EGL_CONFORMANT:
                    return {s_CONFORMANT, 10};
#endif
#ifdef EGL_DEPTH_SIZE
                case EGL_DEPTH_SIZE:
                    return {s_DEPTH_SIZE, 10};
#endif
#ifdef EGL_GREEN_SIZE
                case EGL_GREEN_SIZE:
                    return {s_GREEN_SIZE, 10};
#endif
#ifdef EGL_LEVEL
                case EGL_LEVEL:
                    return {s_LEVEL, 5};
#endif
#ifdef EGL_LUMINANCE_SIZE
                case EGL_LUMINANCE_SIZE:
                    return {s_LUMINANCE_SIZE, 14};
#endif
#ifdef EGL_MAX_PBUFFER_HEIGHT
                case EGL_MAX_PBUFFER_HEIGHT:
                    return {s_MAX_PBUFFER_HEIGHT, 18};
#endif
#ifdef EGL_MAX_PBUFFER_PIXELS
                case EGL_MAX_PBUFFER_PIXELS:
                    return {s_MAX_PBUFFER_PIXELS, 18};
#endif
#ifdef EGL_MAX_PBUFFER_WIDTH
                case EGL_MAX_PBUFFER_WIDTH:
                    return {s_MAX_PBUFFER_WIDTH, 17};
#endif
#ifdef EGL_MAX_SWAP_INTERVAL
                case EGL_MAX_SWAP_INTERVAL:
                    return {s_MAX_SWAP_INTERVAL, 17};
#endif
#ifdef EGL_MIN_SWAP_INTERVAL
                case EGL_MIN_SWAP_INTERVAL:
                    return {s_MIN_SWAP_INTERVAL, 17};
#endif
#ifdef EGL_NATIVE_RENDERABLE
                case EGL_NATIVE_RENDERABLE:
                    return {s_NATIVE_RENDERABLE, 17};
#endif
#ifdef EGL_NATIVE_VISUAL_ID
                case EGL_NATIVE_VISUAL_ID:
                    return {s_NATIVE_VISUAL_ID, 16};
#endif
#ifdef EGL_NATIVE_VISUAL_TYPE
                case EGL_NATIVE_VISUAL_TYPE:
                    return {s_NATIVE_VISUAL_TYPE, 18};
#endif
#ifdef EGL_RED_SIZE
                case EGL_RED_SIZE:
                    return {s_RED_SIZE, 8};
#endif
#ifdef EGL_RENDERABLE_TYPE
                case EGL_RENDERABLE_TYPE:
                    return {s_RENDERABLE_TYPE, 15};
#endif
#ifdef EGL_SAMPLES
                case EGL_SAMPLES:
                    return {s_SAMPLES, 7};
#endif
#ifdef EGL_SAMPLE_BUFFERS
                case EGL_SAMPLE_BUFFERS:
                    return {s_SAMPLE_BUFFERS, 14};
#endif
#ifdef EGL_STENCIL_SIZE
                case EGL_STENCIL_SIZE:
                    return {s_STENCIL_SIZE, 12};
#endif
#ifdef EGL_SURFACE_TYPE
                case EGL_SURFACE_TYPE:
                    return {s_SURFACE_TYPE, 12};
#endif
#ifdef EGL_TRANSPARENT_BLUE_VALUE
                case EGL_TRANSPARENT_BLUE_VALUE:
                    return {s_TRANSPARENT_BLUE_VALUE, 22};
#endif
#ifdef EGL_TRANSPARENT_GREEN_VALUE
                case EGL_TRANSPARENT_GREEN_VALUE:
                    return {s_TRANSPARENT_GREEN_VALUE, 23};
#endif
#ifdef EGL_TRANSPARENT_RED_VALUE
                case EGL_TRANSPARENT_RED_VALUE:
                    return {s_TRANSPARENT_RED_VALUE, 21};
#endif
#ifdef EGL_TRANSPARENT_TYPE
                case EGL_TRANSPARENT_TYPE:
                    return {s_TRANSPARENT_TYPE, 16};
#endif
                default:;
            }
            break;
        case 2: /* config_caveat */
            switch(EGLenum(aev._value)) {
#ifdef EGL_NONE
                case EGL_NONE:
                    return {s_NONE, 4};
#endif
#ifdef EGL_NON_CONFORMANT_CONFIG
                case EGL_NON_CONFORMANT_CONFIG:
                    return {s_NON_CONFORMANT_CONFIG, 21};
#endif
#ifdef EGL_SLOW_CONFIG
                case EGL_SLOW_CONFIG:
                    return {s_SLOW_CONFIG, 11};
#endif
                default:;
            }
            break;
        case 3: /* context_attrib */
            switch(EGLenum(aev._value)) {
#ifdef EGL_CONTEXT_FLAGS
                case EGL_CONTEXT_FLAGS:
                    return {s_CONTEXT_FLAGS, 13};
#endif
#ifdef EGL_CONTEXT_MAJOR_VERSION
                case EGL_CONTEXT_MAJOR_VERSION:
                    return {s_CONTEXT_MAJOR_VERSION, 21};
#endif
#ifdef EGL_CONTEXT_MINOR_VERSION
                case EGL_CONTEXT_MINOR_VERSION:
                    return {s_CONTEXT_MINOR_VERSION, 21};
#endif
#ifdef EGL_CONTEXT_OPENGL_PROFILE_MASK
                case EGL_CONTEXT_OPENGL_PROFILE_MASK:
                    return {s_CONTEXT_OPENGL_PROFILE_MASK, 27};
#endif
#ifdef EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY
                case EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY:
                    return {s_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY, 42};
#endif
                default:;
            }
            break;
        case 4: /* context_flag */
            switch(EGLenum(aev._value)) {
#ifdef EGL_CONTEXT_OPENGL_DEBUG_BIT
                case EGL_CONTEXT_OPENGL_DEBUG_BIT:
                    return {s_CONTEXT_OPENGL_DEBUG_BIT, 24};
#endif
#ifdef EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT
                case EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT:
                    return {s_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT, 37};
#endif
#ifdef EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT
                case EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT:
                    return {s_CONTEXT_OPENGL_ROBUST_ACCESS_BIT, 32};
#endif
                default:;
            }
            break;
        case 5: /* error_code */
            switch(EGLenum(aev._value)) {
#ifdef EGL_BAD_ACCESS
                case EGL_BAD_ACCESS:
                    return {s_BAD_ACCESS, 10};
#endif
#ifdef EGL_BAD_ALLOC
                case EGL_BAD_ALLOC:
                    return {s_BAD_ALLOC, 9};
#endif
#ifdef EGL_BAD_ATTRIBUTE
                case EGL_BAD_ATTRIBUTE:
                    return {s_BAD_ATTRIBUTE, 13};
#endif
#ifdef EGL_BAD_CONFIG
                case EGL_BAD_CONFIG:
                    return {s_BAD_CONFIG, 10};
#endif
#ifdef EGL_BAD_CONTEXT
                case EGL_BAD_CONTEXT:
                    return {s_BAD_CONTEXT, 11};
#endif
#ifdef EGL_BAD_CURRENT_SURFACE
                case EGL_BAD_CURRENT_SURFACE:
                    return {s_BAD_CURRENT_SURFACE, 19};
#endif
#ifdef EGL_BAD_DISPLAY
                case EGL_BAD_DISPLAY:
                    return {s_BAD_DISPLAY, 11};
#endif
#ifdef EGL_BAD_MATCH
                case EGL_BAD_MATCH:
                    return {s_BAD_MATCH, 9};
#endif
#ifdef EGL_BAD_NATIVE_PIXMAP
                case EGL_BAD_NATIVE_PIXMAP:
                    return {s_BAD_NATIVE_PIXMAP, 17};
#endif
#ifdef EGL_BAD_NATIVE_WINDOW
                case EGL_BAD_NATIVE_WINDOW:
                    return {s_BAD_NATIVE_WINDOW, 17};
#endif
#ifdef EGL_BAD_PARAMETER
                case EGL_BAD_PARAMETER:
                    return {s_BAD_PARAMETER, 13};
#endif
#ifdef EGL_BAD_SURFACE
                case EGL_BAD_SURFACE:
                    return {s_BAD_SURFACE, 11};
#endif
#ifdef EGL_CONTEXT_LOST
                case EGL_CONTEXT_LOST:
                    return {s_CONTEXT_LOST, 12};
#endif
#ifdef EGL_NOT_INITIALIZED
                case EGL_NOT_INITIALIZED:
                    return {s_NOT_INITIALIZED, 15};
#endif
                default:;
            }
            break;
        case 6: /* gl_colorspace */
            switch(EGLenum(aev._value)) {
#ifdef EGL_GL_COLORSPACE_LINEAR
                case EGL_GL_COLORSPACE_LINEAR:
                    return {s_GL_COLORSPACE_LINEAR, 20};
#endif
#ifdef EGL_GL_COLORSPACE_sRGB
                case EGL_GL_COLORSPACE_sRGB:
                    return {s_GL_COLORSPACE_sRGB, 18};
#endif
                default:;
            }
            break;
        case 7: /* multisample_resolve */
            switch(EGLenum(aev._value)) {
#ifdef EGL_MULTISAMPLE_RESOLVE_BOX
                case EGL_MULTISAMPLE_RESOLVE_BOX:
                    return {s_MULTISAMPLE_RESOLVE_BOX, 23};
#endif
#ifdef EGL_MULTISAMPLE_RESOLVE_DEFAULT
                case EGL_MULTISAMPLE_RESOLVE_DEFAULT:
                    return {s_MULTISAMPLE_RESOLVE_DEFAULT, 27};
#endif
                default:;
            }
            break;
        case 8: /* opengl_profile_bit */
            switch(EGLenum(aev._value)) {
#ifdef EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT
                case EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT:
                    return {s_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT, 40};
#endif
#ifdef EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT
                case EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT:
                    return {s_CONTEXT_OPENGL_CORE_PROFILE_BIT, 31};
#endif
                default:;
            }
            break;
        case 9: /* opengl_rns */
            switch(EGLenum(aev._value)) {
#ifdef EGL_LOSE_CONTEXT_ON_RESET
                case EGL_LOSE_CONTEXT_ON_RESET:
                    return {s_LOSE_CONTEXT_ON_RESET, 21};
#endif
#ifdef EGL_NO_RESET_NOTIFICATION
                case EGL_NO_RESET_NOTIFICATION:
                    return {s_NO_RESET_NOTIFICATION, 21};
#endif
                default:;
            }
            break;
        case 10: /* render_buffer */
            switch(EGLenum(aev._value)) {
#ifdef EGL_BACK_BUFFER
                case EGL_BACK_BUFFER:
                    return {s_BACK_BUFFER, 11};
#endif
#ifdef EGL_SINGLE_BUFFER
                case EGL_SINGLE_BUFFER:
                    return {s_SINGLE_BUFFER, 13};
#endif
                default:;
            }
            break;
        case 11: /* renderable_type_bit */
            switch(EGLenum(aev._value)) {
#ifdef EGL_OPENGL_BIT
                case EGL_OPENGL_BIT:
                    return {s_OPENGL_BIT, 10};
#endif
#ifdef EGL_OPENGL_ES2_BIT
                case EGL_OPENGL_ES2_BIT:
                    return {s_OPENGL_ES2_BIT, 14};
#endif
#ifdef EGL_OPENGL_ES3_BIT
                case EGL_OPENGL_ES3_BIT:
                    return {s_OPENGL_ES3_BIT, 14};
#endif
#ifdef EGL_OPENGL_ES_BIT
                case EGL_OPENGL_ES_BIT:
                    return {s_OPENGL_ES_BIT, 13};
#endif
#ifdef EGL_OPENVG_BIT
                case EGL_OPENVG_BIT:
                    return {s_OPENVG_BIT, 10};
#endif
                default:;
            }
            break;
        case 12: /* rendering_api */
            switch(EGLenum(aev._value)) {
#ifdef EGL_NONE
                case EGL_NONE:
                    return {s_NONE, 4};
#endif
#ifdef EGL_OPENGL_API
                case EGL_OPENGL_API:
                    return {s_OPENGL_API, 10};
#endif
#ifdef EGL_OPENGL_ES_API
                case EGL_OPENGL_ES_API:
                    return {s_OPENGL_ES_API, 13};
#endif
#ifdef EGL_OPENVG_API
                case EGL_OPENVG_API:
                    return {s_OPENVG_API, 10};
#endif
                default:;
            }
            break;
        case 13: /* string_query */
            switch(EGLenum(aev._value)) {
#ifdef EGL_CLIENT_APIS
                case EGL_CLIENT_APIS:
                    return {s_CLIENT_APIS, 11};
#endif
#ifdef EGL_EXTENSIONS
                case EGL_EXTENSIONS:
                    return {s_EXTENSIONS, 10};
#endif
#ifdef EGL_VENDOR
                case EGL_VENDOR:
                    return {s_VENDOR, 6};
#endif
#ifdef EGL_VERSION
                case EGL_VERSION:
                    return {s_VERSION, 7};
#endif
                default:;
            }
            break;
        case 14: /* surface_attrib */
            switch(EGLenum(aev._value)) {
#ifdef EGL_CONFIG_ID
                case EGL_CONFIG_ID:
                    return {s_CONFIG_ID, 9};
#endif
#ifdef EGL_GL_COLORSPACE
                case EGL_GL_COLORSPACE:
                    return {s_GL_COLORSPACE, 13};
#endif
#ifdef EGL_HEIGHT
                case EGL_HEIGHT:
                    return {s_HEIGHT, 6};
#endif
#ifdef EGL_HORIZONTAL_RESOLUTION
                case EGL_HORIZONTAL_RESOLUTION:
                    return {s_HORIZONTAL_RESOLUTION, 21};
#endif
#ifdef EGL_LARGEST_PBUFFER
                case EGL_LARGEST_PBUFFER:
                    return {s_LARGEST_PBUFFER, 15};
#endif
#ifdef EGL_MIPMAP_LEVEL
                case EGL_MIPMAP_LEVEL:
                    return {s_MIPMAP_LEVEL, 12};
#endif
#ifdef EGL_MIPMAP_TEXTURE
                case EGL_MIPMAP_TEXTURE:
                    return {s_MIPMAP_TEXTURE, 14};
#endif
#ifdef EGL_MULTISAMPLE_RESOLVE
                case EGL_MULTISAMPLE_RESOLVE:
                    return {s_MULTISAMPLE_RESOLVE, 19};
#endif
#ifdef EGL_PIXEL_ASPECT_RATIO
                case EGL_PIXEL_ASPECT_RATIO:
                    return {s_PIXEL_ASPECT_RATIO, 18};
#endif
#ifdef EGL_RENDER_BUFFER
                case EGL_RENDER_BUFFER:
                    return {s_RENDER_BUFFER, 13};
#endif
#ifdef EGL_SWAP_BEHAVIOR
                case EGL_SWAP_BEHAVIOR:
                    return {s_SWAP_BEHAVIOR, 13};
#endif
#ifdef EGL_TEXTURE_FORMAT
                case EGL_TEXTURE_FORMAT:
                    return {s_TEXTURE_FORMAT, 14};
#endif
#ifdef EGL_TEXTURE_TARGET
                case EGL_TEXTURE_TARGET:
                    return {s_TEXTURE_TARGET, 14};
#endif
#ifdef EGL_VERTICAL_RESOLUTION
                case EGL_VERTICAL_RESOLUTION:
                    return {s_VERTICAL_RESOLUTION, 19};
#endif
#ifdef EGL_VG_ALPHA_FORMAT
                case EGL_VG_ALPHA_FORMAT:
                    return {s_VG_ALPHA_FORMAT, 15};
#endif
#ifdef EGL_VG_COLORSPACE
                case EGL_VG_COLORSPACE:
                    return {s_VG_COLORSPACE, 13};
#endif
#ifdef EGL_WIDTH
                case EGL_WIDTH:
                    return {s_WIDTH, 5};
#endif
                default:;
            }
            break;
        case 15: /* surface_type_bit */
            switch(EGLenum(aev._value)) {
#ifdef EGL_MULTISAMPLE_RESOLVE_BOX_BIT
                case EGL_MULTISAMPLE_RESOLVE_BOX_BIT:
                    return {s_MULTISAMPLE_RESOLVE_BOX_BIT, 27};
#endif
#ifdef EGL_PBUFFER_BIT
                case EGL_PBUFFER_BIT:
                    return {s_PBUFFER_BIT, 11};
#endif
#ifdef EGL_PIXMAP_BIT
                case EGL_PIXMAP_BIT:
                    return {s_PIXMAP_BIT, 10};
#endif
#ifdef EGL_SWAP_BEHAVIOR_PRESERVED_BIT
                case EGL_SWAP_BEHAVIOR_PRESERVED_BIT:
                    return {s_SWAP_BEHAVIOR_PRESERVED_BIT, 27};
#endif
#ifdef EGL_VG_ALPHA_FORMAT_PRE_BIT
                case EGL_VG_ALPHA_FORMAT_PRE_BIT:
                    return {s_VG_ALPHA_FORMAT_PRE_BIT, 23};
#endif
#ifdef EGL_VG_COLORSPACE_LINEAR_BIT
                case EGL_VG_COLORSPACE_LINEAR_BIT:
                    return {s_VG_COLORSPACE_LINEAR_BIT, 24};
#endif
#ifdef EGL_WINDOW_BIT
                case EGL_WINDOW_BIT:
                    return {s_WINDOW_BIT, 10};
#endif
                default:;
            }
            break;
        case 16: /* swap_behavior */
            switch(EGLenum(aev._value)) {
#ifdef EGL_BUFFER_DESTROYED
                case EGL_BUFFER_DESTROYED:
                    return {s_BUFFER_DESTROYED, 16};
#endif
#ifdef EGL_BUFFER_PRESERVED
                case EGL_BUFFER_PRESERVED:
                    return {s_BUFFER_PRESERVED, 16};
#endif
                default:;
            }
            break;
        case 17: /* texture_format */
            switch(EGLenum(aev._value)) {
#ifdef EGL_NO_TEXTURE
                case EGL_NO_TEXTURE:
                    return {s_NO_TEXTURE, 10};
#endif
#ifdef EGL_TEXTURE_RGB
                case EGL_TEXTURE_RGB:
                    return {s_TEXTURE_RGB, 11};
#endif
#ifdef EGL_TEXTURE_RGBA
                case EGL_TEXTURE_RGBA:
                    return {s_TEXTURE_RGBA, 12};
#endif
                default:;
            }
            break;
        case 18: /* texture_target */
            switch(EGLenum(aev._value)) {
#ifdef EGL_NO_TEXTURE
                case EGL_NO_TEXTURE:
                    return {s_NO_TEXTURE, 10};
#endif
#ifdef EGL_TEXTURE_2D
                case EGL_TEXTURE_2D:
                    return {s_TEXTURE_2D, 10};
#endif
                default:;
            }
            break;
        case 19: /* transparent_type */
            switch(EGLenum(aev._value)) {
#ifdef EGL_NONE
                case EGL_NONE:
                    return {s_NONE, 4};
#endif
#ifdef EGL_TRANSPARENT_RGB
                case EGL_TRANSPARENT_RGB:
                    return {s_TRANSPARENT_RGB, 15};
#endif
                default:;
            }
            break;
        case 20: /* vg_alpha_format */
            switch(EGLenum(aev._value)) {
#ifdef EGL_VG_ALPHA_FORMAT_NONPRE
                case EGL_VG_ALPHA_FORMAT_NONPRE:
                    return {s_VG_ALPHA_FORMAT_NONPRE, 22};
#endif
#ifdef EGL_VG_ALPHA_FORMAT_PRE
                case EGL_VG_ALPHA_FORMAT_PRE:
                    return {s_VG_ALPHA_FORMAT_PRE, 19};
#endif
                default:;
            }
            break;
        case 21: /* vg_colorspace */
            switch(EGLenum(aev._value)) {
#ifdef EGL_VG_COLORSPACE_LINEAR
                case EGL_VG_COLORSPACE_LINEAR:
                    return {s_VG_COLORSPACE_LINEAR, 20};
#endif
#ifdef EGL_VG_COLORSPACE_sRGB
                case EGL_VG_COLORSPACE_sRGB:
                    return {s_VG_COLORSPACE_sRGB, 18};
#endif
                default:;
            }
            break;
        default:;
    }

    EAGINE_MAYBE_UNUSED(aev);
    return {};
}

} // namespace eglplus
#ifdef _MSC_VER
#pragma warning(pop)
#endif //_MSC_VER
