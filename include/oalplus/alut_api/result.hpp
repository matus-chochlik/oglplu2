/**
 *  @file oalplus/alut_api/result.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_RESULT_HPP
#define OALPLUS_ALUT_API_RESULT_HPP

#include "config.hpp"
#include <eagine/anything.hpp>
#include <eagine/c_api_wrap.hpp>
#include <eagine/string_span.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
class alut_no_result_info {
public:
    constexpr alut_no_result_info& error_code(anything) noexcept {
        return *this;
    }

    constexpr string_view message() const noexcept {
        return {"ALUT function not available"};
    }

private:
};
//------------------------------------------------------------------------------
class alut_result_info {
public:
    using enum_type = alut_types::enum_type;

    explicit constexpr operator bool() const noexcept {
#ifdef ALUT_ERROR_NO_ERROR
        return _error_code == ALUT_ERROR_NO_ERROR;
#else
        return false;
#endif
    }

    constexpr bool operator!() const noexcept {
#ifdef ALUT_ERROR_NO_ERROR
        return _error_code != ALUT_ERROR_NO_ERROR;
#else
        return true;
#endif
    }

    constexpr alut_result_info& error_code(enum_type ec) noexcept {
        _error_code = ec;
        return *this;
    }

    constexpr enum_type error_code() const noexcept {
        return _error_code;
    }

    string_view message() const noexcept {
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
template <typename Result>
using alut_no_result = api_no_result<Result, alut_no_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using alut_result = api_result<Result, alut_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using alut_opt_result = api_opt_result<Result, alut_result_info>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALUT_API_RESULT_HPP

