/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GL_API_RESULT_HPP
#define OGLPLUS_GL_API_RESULT_HPP

#include "config.hpp"
#include <eagine/anything.hpp>
#include <eagine/c_api_wrap.hpp>
#include <eagine/string_span.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
/// @brief Class storing information about call result for unavailable GL functions.
/// @ingroup gl_api_wrap
/// @see gl_no_result
/// @see gl_result_info
class gl_no_result_info {
public:
    constexpr auto error_code(anything) noexcept -> auto& {
        return *this;
    }

    /// @brief Returns a message associated with the result.
    constexpr auto message() const noexcept -> string_view {
        return {"GL function not available"};
    }

private:
};
//------------------------------------------------------------------------------
/// @brief Class storing information about a GL function call result.
/// @ingroup gl_api_wrap
/// @see gl_result
/// @see gl_no_result_info
class gl_result_info {
public:
    /// @brief Indicates if the call finished without error.
    explicit constexpr operator bool() const noexcept {
        return gl_types::error_code_no_error(_error_code);
    }

    constexpr auto error_code(gl_types::enum_type ec) noexcept -> auto& {
        _error_code = ec;
        return *this;
    }

    /// @brief Returns a message associated with the result.
    auto message() const noexcept -> string_view {
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
/// @brief Alias for always-invalid result of a missing GL API function call.
/// @ingroup gl_api_wrap
/// @see gl_result
/// @see gl_opt_result
template <typename Result>
using gl_no_result = api_no_result<Result, gl_no_result_info>;
//------------------------------------------------------------------------------
/// @brief Class wrapping the result of a GL API function call.
/// @ingroup gl_api_wrap
/// @see gl_no_result
/// @see gl_opt_result
template <typename Result>
using gl_result = api_result<Result, gl_result_info>;
//------------------------------------------------------------------------------
/// @brief Alias for conditionally-valid result of a GL API function call.
/// @ingroup gl_api_wrap
/// @see gl_result
/// @see gl_opt_result
template <typename Result>
using gl_opt_result = api_opt_result<Result, gl_result_info>;
//------------------------------------------------------------------------------
/// @brief Alias for a result that may come from mutiple difference GL API functions.
/// @ingroup gl_api_wrap
/// @see gl_result
/// @see gl_no_result
/// @see gl_opt_result
template <typename Result>
using gl_combined_result = api_combined_result<Result, gl_result_info>;
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_RESULT_HPP
