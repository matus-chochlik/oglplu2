/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALUT_API_RESULT_HPP
#define OALPLUS_ALUT_API_RESULT_HPP

#include "config.hpp"
#include <eagine/anything.hpp>
#include <eagine/c_api_wrap.hpp>
#include <eagine/string_span.hpp>

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Class storing information about call result for unavailable ALUT functions.
/// @ingroup gl_api_wrap
/// @see gl_no_result
/// @see gl_result_info
class alut_no_result_info {
public:
    constexpr auto error_code(anything) noexcept -> auto& {
        return *this;
    }

    /// @brief Returns a message associated with the result.
    constexpr auto message() const noexcept -> string_view {
        return {"ALUT function not available"};
    }

private:
};
//------------------------------------------------------------------------------
/// @brief Class storing information about an ALUT function call result.
/// @ingroup gl_api_wrap
/// @see gl_result
/// @see gl_no_result_info
class alut_result_info {
public:
    using enum_type = alut_types::enum_type;

    /// @brief Indicates if the call finished without error.
    explicit constexpr operator bool() const noexcept {
        return alut_types::error_code_no_error(_error_code);
    }

    constexpr auto error_code(enum_type ec) noexcept -> auto& {
        _error_code = ec;
        return *this;
    }

    constexpr auto error_code() const noexcept -> enum_type {
        return _error_code;
    }

    /// @brief Returns a message associated with the result.
    auto message() const noexcept -> string_view {
#ifdef ALUT_ERROR_INVALID_ENUM
        if(_error_code == ALUT_ERROR_INVALID_ENUM) {
            return {"invalid enumeration parameter value"};
        }
#endif
#ifdef ALUT_ERROR_INVALID_VALUE
        if(_error_code == ALUT_ERROR_INVALID_VALUE) {
            return {"invalid parameter value"};
        }
#endif
#ifdef ALUT_ERROR_INVALID_OPERATION
        if(_error_code == ALUT_ERROR_INVALID_OPERATION) {
            return {"invalid operation"};
        }
#endif
#ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
        if(_error_code == ALUT_ERROR_NO_CURRENT_CONTEXT) {
            return {"no current context"};
        }
#endif
#ifdef ALUT_ERROR_AL_ERROR_ON_ENTRY
        if(_error_code == ALUT_ERROR_AL_ERROR_ON_ENTRY) {
            return {"AL error on entry to function"};
        }
#endif
#ifdef ALUT_ERROR_ALC_ERROR_ON_ENTRY
        if(_error_code == ALUT_ERROR_ALC_ERROR_ON_ENTRY) {
            return {"ALC error on entry to function"};
        }
#endif
#ifdef ALUT_ERROR_OPEN_DEVICE
        if(_error_code == ALUT_ERROR_OPEN_DEVICE) {
            return {"failed to open device"};
        }
#endif
#ifdef ALUT_ERROR_CLOSE_DEVICE
        if(_error_code == ALUT_ERROR_CLOSE_DEVICE) {
            return {"failed to close device"};
        }
#endif
#ifdef ALUT_ERROR_CREATE_CONTEXT
        if(_error_code == ALUT_ERROR_CREATE_CONTEXT) {
            return {"failed to create context"};
        }
#endif
#ifdef ALUT_ERROR_DESTROY_CONTEXT
        if(_error_code == ALUT_ERROR_DESTROY_CONTEXT) {
            return {"failed to destroy context"};
        }
#endif
#ifdef ALUT_ERROR_GEN_BUFFERS
        if(_error_code == ALUT_ERROR_GEN_BUFFERS) {
            return {"failed to generate audio buffers"};
        }
#endif
#ifdef ALUT_ERROR_BUFFER_DATA
        if(_error_code == ALUT_ERROR_BUFFER_DATA) {
            return {"failed to store data in buffer"};
        }
#endif
#ifdef ALUT_ERROR_IO_ERROR
        if(_error_code == ALUT_ERROR_IO_ERROR) {
            return {"input/output error"};
        }
#endif
#ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
        if(_error_code == ALUT_ERROR_UNSUPPORTED_FILE_TYPE) {
            return {"unsupported file type"};
        }
#endif
#ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
        if(_error_code == ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE) {
            return {"unsupported file sub-type"};
        }
#endif
#ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
        if(_error_code == ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA) {
            return {"corrupt or truncated data"};
        }
#endif
#ifdef ALUT_ERROR_NO_ERROR
        if(_error_code == ALUT_ERROR_NO_ERROR) {
            return {"no error"};
        }
#endif
#ifdef ALUT_ERROR_OUT_OF_MEMORY
        if(_error_code == ALUT_ERROR_OUT_OF_MEMORY) {
            return {"out of memory"};
        }
#endif
        return {"unknown error"};
    }

private:
    enum_type _error_code{
#ifdef ALUT_ERROR_NO_ERROR
      ALUT_ERROR_NO_ERROR
#endif
    };
};
//------------------------------------------------------------------------------
/// @brief Alias for always-invalid result of a missing ALUT API function call.
/// @ingroup al_api_wrap
/// @see al_result
/// @see al_opt_result
template <typename Result>
using alut_no_result = api_no_result<Result, alut_no_result_info>;
//------------------------------------------------------------------------------
/// @brief Class wrapping the result of a ALUT API function call.
/// @ingroup al_api_wrap
/// @see al_no_result
/// @see al_opt_result
template <typename Result>
using alut_result = api_result<Result, alut_result_info>;
//------------------------------------------------------------------------------
/// @brief Class wrapping the result of a ALUT API function call.
/// @ingroup al_api_wrap
/// @see al_no_result
/// @see al_opt_result
template <typename Result>
using alut_opt_result = api_opt_result<Result, alut_result_info>;
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALUT_API_RESULT_HPP
