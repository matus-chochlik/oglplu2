/**
 *  @file oalplus/al_api/result.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_RESULT_HPP
#define OALPLUS_AL_API_RESULT_HPP

#include <eagine/anything.hpp>
#include <eagine/c_api_wrap.hpp>
#include <eagine/string_span.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
class al_no_result_info {
public:
    constexpr al_no_result_info& error_code(anything) noexcept {
        return *this;
    }

    constexpr string_view message() const noexcept {
        return {"AL function not available"};
    }

private:
};
//------------------------------------------------------------------------------
class al_result_info {
public:
    using enum_type = ALCenum;

    explicit constexpr operator bool() const noexcept {
#ifdef AL_NO_ERROR
        return _error_code == AL_NO_ERROR;
#else
        return false;
#endif
    }

    constexpr bool operator!() const noexcept {
#ifdef AL_NO_ERROR
        return _error_code != AL_NO_ERROR;
#else
        return true;
#endif
    }

    constexpr al_result_info& error_code(enum_type ec) noexcept {
        _error_code = ec;
        return *this;
    }

    string_view message() const noexcept {
#ifdef AL_INVALID_NAME
        if(_error_code == AL_INVALID_NAME) {
            return {"invalid object name"};
        }
#endif
#ifdef AL_INVALID_ENUM
        if(_error_code == AL_INVALID_ENUM) {
            return {"invalid enumeration value"};
        }
#endif
#ifdef AL_INVALID_VALUE
        if(_error_code == AL_INVALID_VALUE) {
            return {"invalid parameter value"};
        }
#endif
#ifdef AL_INVALID_OPERATION
        if(_error_code == AL_INVALID_OPERATION) {
            return {"invalid operation"};
        }
#endif
#ifdef AL_NO_ERROR
        if(_error_code == AL_NO_ERROR) {
            return {"no error"};
        }
#endif
#ifdef AL_OUT_OF_MEMORY
        if(_error_code == AL_OUT_OF_MEMORY) {
            return {"out of memory"};
        }
#endif
        return {"unknown error"};
    }

private:
    enum_type _error_code{
#ifdef AL_NO_ERROR
      AL_NO_ERROR
#endif
    };
};
//------------------------------------------------------------------------------
template <typename Result>
using al_no_result = api_no_result<Result, al_no_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using al_result = api_result<Result, al_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using al_opt_result = api_opt_result<Result, al_result_info>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_RESULT_HPP

