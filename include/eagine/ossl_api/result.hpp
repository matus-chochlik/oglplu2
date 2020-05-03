/**
 *  @file eagine/ossl_api/result.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OSSL_API_RESULT_HPP
#define EAGINE_OSSL_API_RESULT_HPP

#include "config.hpp"
#include <eagine/anything.hpp>
#include <eagine/c_api_wrap.hpp>
#include <eagine/string_span.hpp>

namespace eagine {
namespace osslp {
//------------------------------------------------------------------------------
class ossl_no_result_info {
public:
    constexpr ossl_no_result_info& error_code(anything) noexcept {
        return *this;
    }

    constexpr string_view message() const noexcept {
        return {"OpenSSL function not available"};
    }

private:
};
//------------------------------------------------------------------------------
class ossl_result_info {
public:
    explicit constexpr operator bool() const noexcept {
        return _error_code == 1;
    }

    constexpr bool operator!() const noexcept {
        return _error_code != 1;
    }

    constexpr ossl_result_info& error_code(int ec) noexcept {
        _error_code = ec;
        return *this;
    }

    string_view message() const noexcept {
        return {"unknown error"};
    }

private:
    int _error_code{0};
};
//------------------------------------------------------------------------------
template <typename Result>
using ossl_no_result = api_no_result<Result, ossl_no_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using ossl_result = api_result<Result, ossl_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using ossl_opt_result = api_opt_result<Result, ossl_result_info>;
//------------------------------------------------------------------------------
} // namespace osslp
} // namespace eagine

#endif // EAGINE_OSSL_API_RESULT_HPP

