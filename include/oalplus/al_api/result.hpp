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

#include <eagine/eat_anything.hpp>
#include <eagine/string_span.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename Result>
class al_no_result : public api_no_result_value<Result> {
public:
    constexpr al_no_result&& error_code(eat_anything) && noexcept {
        return std::move(*this);
    }

    constexpr string_view message() const noexcept {
        return {"function not available"};
    }
};
//------------------------------------------------------------------------------
template <typename Result>
class al_result : public api_result_value<Result> {
    using base = api_result_value<Result>;

public:
    using enum_type = ALenum;
    using base::base;

    explicit constexpr operator bool() const noexcept {
        return _error_code == AL_NO_ERROR;
    }

    constexpr bool operator!() const noexcept {
        return _error_code != AL_NO_ERROR;
    }

    constexpr al_result&& error_code(enum_type ec) && noexcept {
        _error_code = ec;
        return std::move(*this);
    }

    constexpr enum_type error_code() const noexcept {
        return _error_code;
    }

    string_view message() const noexcept {
        if(_error_code == AL_INVALID_ENUM) {
            return {"invalid enumeration parameter value"};
        }
        if(_error_code == AL_INVALID_NAME) {
            return {"invalid object name"};
        }
        if(_error_code == AL_INVALID_ENUM) {
            return {"invalid enumeration value"};
        }
        if(_error_code == AL_INVALID_VALUE) {
            return {"invalid parameter value"};
        }
        if(_error_code == AL_INVALID_OPERATION) {
            return {"invalid operation"};
        }
        if(_error_code == AL_NO_ERROR) {
            return {"no error"};
        }
        if(_error_code == AL_OUT_OF_MEMORY) {
            return {"out of memory"};
        }
        return {"unknown error"};
    }

private:
    enum_type _error_code{AL_NO_ERROR};
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_RESULT_HPP

