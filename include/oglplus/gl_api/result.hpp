/**
 *  @file oglplus/gl_api/result.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_RESULT_HPP
#define OGLPLUS_GL_API_RESULT_HPP

#include "config.hpp"
#include <eagine/anything.hpp>
#include <eagine/c_api_wrap.hpp>
#include <eagine/string_span.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
class gl_no_result_info {
public:
    constexpr gl_no_result_info& error_code(anything) noexcept {
        return *this;
    }

    constexpr string_view message() const noexcept {
        return {"EGL function not available"};
    }

private:
};
//------------------------------------------------------------------------------
class gl_result_info {
public:
    explicit constexpr operator bool() const noexcept {
        return gl_types::error_code_no_error(_error_code);
    }

    constexpr bool operator!() const noexcept {
        return !gl_types::error_code_no_error(_error_code);
    }

    constexpr gl_result_info& error_code(gl_types::enum_type ec) noexcept {
        _error_code = ec;
        return *this;
    }

    string_view message() const noexcept {
#ifdef GL_INVALID_ENUM
        if(_error_code == GL_INVALID_ENUM) {
            return {"invalid enum value"};
        }
#endif
#ifdef GL_INVALID_VALUE
        if(_error_code == GL_INVALID_VALUE) {
            return {"invalid value"};
        }
#endif
#ifdef GL_INVALID_OPERATION
        if(_error_code == GL_INVALID_OPERATION) {
            return {"invalid operation"};
        }
#endif
#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
        if(_error_code == GL_INVALID_FRAMEBUFFER_OPERATION) {
            return {"invalid framebuffer operation"};
        }
#endif
#ifdef GL_NO_ERROR
        if(_error_code == GL_NO_ERROR) {
            return {"no error"};
        }
#endif
#ifdef GL_STACK_OVERFLOW
        if(_error_code == GL_STACK_OVERFLOW) {
            return {"stack overflow"};
        }
#endif
#ifdef GL_STACK_UNDERFLOW
        if(_error_code == GL_STACK_UNDERFLOW) {
            return {"stack underflow"};
        }
#endif
#ifdef GL_TABLE_TOO_LARGE
        if(_error_code == GL_TABLE_TOO_LARGE) {
            return {"table too large"};
        }
#endif
#ifdef GL_CONTEXT_LOST
        if(_error_code == GL_CONTEXT_LOST) {
            return {"rendering context lost"};
        }
#endif
#ifdef GL_OUT_OF_MEMORY
        if(_error_code == GL_OUT_OF_MEMORY) {
            return {"out of memory"};
        }
#endif
        return {"unknown error"};
    }

private:
    gl_types::enum_type _error_code{
#ifdef GL_NO_ERROR
      GL_NO_ERROR
#endif
    };
};
//------------------------------------------------------------------------------
template <typename Result>
using gl_no_result = api_no_result<Result, gl_no_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using gl_result = api_result<Result, gl_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using gl_opt_result = api_opt_result<Result, gl_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using gl_combined_result = api_combined_result<Result, gl_result_info>;
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_RESULT_HPP

