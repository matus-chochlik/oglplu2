/**
 *  @file oalplus/alc_api/result.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_RESULT_HPP
#define OALPLUS_ALC_API_RESULT_HPP

#include <eagine/anything.hpp>
#include <eagine/c_api_wrap.hpp>
#include <eagine/string_span.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
class alc_no_result_info {
public:
    constexpr alc_no_result_info& error_code(anything) noexcept {
        return *this;
    }

    constexpr string_view message() const noexcept {
        return {"ALC function not available"};
    }

private:
};
//------------------------------------------------------------------------------
class alc_result_info {
public:
    using enum_type = ALCenum;

    explicit constexpr operator bool() const noexcept {
#ifdef ALC_NO_ERROR
        return _error_code == ALC_NO_ERROR;
#else
        return false;
#endif
    }

    constexpr bool operator!() const noexcept {
#ifdef ALC_NO_ERROR
        return _error_code != ALC_NO_ERROR;
#else
        return true;
#endif
    }

    constexpr alc_result_info& error_code(enum_type ec) noexcept {
        _error_code = ec;
        return *this;
    }

    constexpr enum_type error_code() const noexcept {
        return _error_code;
    }

    string_view message() const noexcept {
#ifdef ALC_INVALID_ENUM
        if(_error_code == ALC_INVALID_ENUM) {
            return {"invalid enumeration parameter value"};
        }
#endif
#ifdef ALC_INVALID_VALUE
        if(_error_code == ALC_INVALID_VALUE) {
            return {"invalid parameter value"};
        }
#endif
#ifdef ALC_INVALID_CONTEXT
        if(_error_code == ALC_INVALID_CONTEXT) {
            return {"invalid context"};
        }
#endif
#ifdef ALC_INVALID_DEVICE
        if(_error_code == ALC_INVALID_DEVICE) {
            return {"invalid device"};
        }
#endif
#ifdef ALC_NO_ERROR
        if(_error_code == ALC_NO_ERROR) {
            return {"no error"};
        }
#endif
#ifdef ALC_OUT_OF_MEMORY
        if(_error_code == ALC_OUT_OF_MEMORY) {
            return {"out of memory"};
        }
#endif
        return {"unknown error"};
    }

private:
    enum_type _error_code{
#ifdef ALC_NO_ERROR
      ALC_NO_ERROR
#endif
    };
};
//------------------------------------------------------------------------------
template <typename Result>
using alc_no_result = api_no_result<Result, alc_no_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using alc_result = api_result<Result, alc_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using alc_opt_result = api_opt_result<Result, alc_result_info>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_RESULT_HPP

