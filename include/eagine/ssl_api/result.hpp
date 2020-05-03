/**
 *  @file eagine/ssl_api/result.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_SSL_API_RESULT_HPP
#define EAGINE_SSL_API_RESULT_HPP

#include "config.hpp"
#include <eagine/anything.hpp>
#include <eagine/c_api_wrap.hpp>
#include <eagine/string_span.hpp>

namespace eagine {
namespace sslp {
//------------------------------------------------------------------------------
class ssl_no_result_info {
public:
    constexpr ssl_no_result_info& error_code(anything) noexcept {
        return *this;
    }

    constexpr string_view message() const noexcept {
        return {"OpenSSL function not available"};
    }

private:
};
//------------------------------------------------------------------------------
class ssl_result_info {
public:
    explicit constexpr operator bool() const noexcept {
        return _error_code == 0;
    }

    constexpr bool operator!() const noexcept {
        return _error_code != 0;
    }

    constexpr ssl_result_info& error_code(unsigned long ec) noexcept {
        _error_code = ec;
        return *this;
    }

    string_view message() const noexcept {
        // TODO: get error string from OpenSSL
        return {"unknown error"};
    }

private:
    unsigned long _error_code{0};
};
//------------------------------------------------------------------------------
template <typename Result>
using ssl_no_result = api_no_result<Result, ssl_no_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using ssl_result = api_result<Result, ssl_result_info>;
//------------------------------------------------------------------------------
template <typename Result>
using ssl_opt_result = api_opt_result<Result, ssl_result_info>;
//------------------------------------------------------------------------------
} // namespace sslp
} // namespace eagine

#endif // EAGINE_SSL_API_RESULT_HPP

