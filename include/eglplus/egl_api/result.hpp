/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EGLPLUS_EGL_API_RESULT_HPP
#define EGLPLUS_EGL_API_RESULT_HPP

#include "config.hpp"
#include <eagine/anything.hpp>
#include <eagine/c_api_wrap.hpp>
#include <eagine/string_span.hpp>

namespace eagine::eglp {
//------------------------------------------------------------------------------
/// @brief Class storing information about call result for unavailable EGL functions.
/// @ingroup egl_api_wrap
/// @see egl_no_result
/// @see egl_result_info
class egl_no_result_info {
public:
    constexpr auto error_code(anything) noexcept -> auto& {
        return *this;
    }

    /// @brief Returns a message associated with the result.
    constexpr auto message() const noexcept -> string_view {
        return {"EGL function not available"};
    }

private:
};
//------------------------------------------------------------------------------
/// @brief Class storing information about an EGL function call result.
/// @ingroup egl_api_wrap
/// @see egl_result
/// @see egl_no_result_info
class egl_result_info {
public:
    /// @brief Indicates if the call finished without error.
    explicit constexpr operator bool() const noexcept {
        return egl_types::error_code_no_error(_error_code);
    }

    constexpr auto error_code(egl_types::int_type ec) noexcept -> auto& {
        _error_code = ec;
        return *this;
    }

    /// @brief Returns a message associated with the result.
    auto message() const noexcept -> string_view {
#ifdef EGL_BAD_SURFACE
        if(_error_code == EGL_BAD_SURFACE) {
            return {"bad surface"};
        }
#endif
#ifdef EGL_BAD_CURRENT_SURFACE
        if(_error_code == EGL_BAD_CURRENT_SURFACE) {
            return {"bad current surface"};
        }
#endif
#ifdef EGL_BAD_DISPLAY
        if(_error_code == EGL_BAD_DISPLAY) {
            return {"bad display"};
        }
#endif
#ifdef EGL_CONTEXT_LOST
        if(_error_code == EGL_CONTEXT_LOST) {
            return {"EGL context lost"};
        }
#endif
#ifdef EGL_BAD_PARAMETER
        if(_error_code == EGL_BAD_PARAMETER) {
            return {"invalid parameter"};
        }
#endif
#ifdef EGL_BAD_ATTRIBUTE
        if(_error_code == EGL_BAD_ATTRIBUTE) {
            return {"unrecognized attribute or attribute value"};
        }
#endif
#ifdef EGL_BAD_CONFIG
        if(_error_code == EGL_BAD_CONFIG) {
            return {"invalid configuration"};
        }
#endif
#ifdef EGL_BAD_CONTEXT
        if(_error_code == EGL_BAD_CONTEXT) {
            return {"invalid context"};
        }
#endif
#ifdef EGL_BAD_NATIVE_PIXMAP
        if(_error_code == EGL_BAD_NATIVE_PIXMAP) {
            return {"bad native pixmap"};
        }
#endif
#ifdef EGL_BAD_NATIVE_WINDOW
        if(_error_code == EGL_BAD_NATIVE_WINDOW) {
            return {"bad native window"};
        }
#endif
#ifdef EGL_BAD_MATCH
        if(_error_code == EGL_BAD_MATCH) {
            return {"inconsistent attributes"};
        }
#endif
#ifdef EGL_BAD_ACCESS
        if(_error_code == EGL_BAD_ACCESS) {
            return {"cannot access requested resource"};
        }
#endif
#ifdef EGL_NOT_INITIALIZED
        if(_error_code == EGL_NOT_INITIALIZED) {
            return {"EGL not initialized"};
        }
#endif
#ifdef EGL_BAD_STREAM_KHR
        if(_error_code == EGL_BAD_STREAM_KHR) {
            return {"bad EGL stream"};
        }
#endif
#ifdef EGL_BAD_OUTPUT_LAYER_EXT
        if(_error_code == EGL_BAD_OUTPUT_LAYER_EXT) {
            return {"bad EGL output layer"};
        }
#endif
#ifdef EGL_BAD_OUTPUT_PORT_EXT
        if(_error_code == EGL_BAD_OUTPUT_PORT_EXT) {
            return {"bad EGL output port"};
        }
#endif
#ifdef EGL_BAD_STATE_KHR
        if(_error_code == EGL_BAD_STATE_KHR) {
            return {"bad EGL state"};
        }
#endif
#ifdef EGL_SUCCESS
        if(_error_code == EGL_SUCCESS) {
            return {"no error"};
        }
#endif
#ifdef EGL_BAD_ALLOC
        if(_error_code == EGL_BAD_ALLOC) {
            return {"out of memory"};
        }
#endif
        return {"unknown error"};
    }

private:
    egl_types::int_type _error_code{
#ifdef EGL_SUCCESS
      EGL_SUCCESS
#endif
    };
};
//------------------------------------------------------------------------------
/// @brief Alias for always-invalid result of a missing EGL API function call.
/// @ingroup egl_api_wrap
/// @see egl_result
/// @see egl_opt_result
template <typename Result>
using egl_no_result = api_no_result<Result, egl_no_result_info>;
//------------------------------------------------------------------------------
/// @brief Class wrapping the result of a EGL API function call.
/// @ingroup egl_api_wrap
/// @see egl_no_result
/// @see egl_opt_result
template <typename Result>
using egl_result = api_result<Result, egl_result_info>;
//------------------------------------------------------------------------------
/// @brief Alias for conditionally-valid result of a EGL API function call.
/// @ingroup gl_api_wrap
/// @see egl_result
/// @see egl_no_result
template <typename Result>
using egl_opt_result = api_opt_result<Result, egl_result_info>;
//------------------------------------------------------------------------------
} // namespace eagine::eglp

#endif // EGLPLUS_EGL_API_RESULT_HPP
