/**
 *  @file oalplus/egl_api/result.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_EGL_API_RESULT_HPP
#define OALPLUS_EGL_API_RESULT_HPP

#include "config.hpp"
#include <eagine/anything.hpp>
#include <eagine/c_api_wrap.hpp>
#include <eagine/string_span.hpp>

namespace eagine {
namespace eglp {
//------------------------------------------------------------------------------
class egl_no_result_info {
public:
    constexpr egl_no_result_info& error_code(anything) noexcept {
        return *this;
    }

    constexpr string_view message() const noexcept {
        return {"EGL function not available"};
    }

private:
};
//------------------------------------------------------------------------------
class egl_result_info {
public:
    explicit constexpr operator bool() const noexcept {
#ifdef EGL_SUCCESS
        return _error_code == EGL_SUCCESS;
#else
        return false;
#endif
    }

    constexpr bool operator!() const noexcept {
#ifdef EGL_SUCCESS
        return _error_code != EGL_SUCCESS;
#else
        return true;
#endif
    }

    constexpr egl_result_info& error_code(egl_types::int_type ec) noexcept {
        _error_code = ec;
        return *this;
    }

    string_view message() const noexcept {
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
template <typename Result>
using egl_no_result = api_no_result<Result, egl_no_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using egl_result = api_result<Result, egl_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using egl_opt_result = api_opt_result<Result, egl_result_info>;
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // OALPLUS_EGL_API_RESULT_HPP

