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

namespace eagine::sslp {
//------------------------------------------------------------------------------
class ssl_no_result_info {
public:
    constexpr auto error_code(anything) noexcept -> auto& {
        return *this;
    }

    constexpr auto message() const noexcept -> string_view {
        return {"OpenSSL function not available"};
    }

    constexpr auto set_unknown_error() noexcept -> auto& {
        return *this;
    }
};
//------------------------------------------------------------------------------
class ssl_result_info {
public:
    explicit constexpr operator bool() const noexcept {
        return _error_code == 0;
    }

    constexpr auto operator!() const noexcept {
        return _error_code != 0;
    }

    constexpr auto error_code(unsigned long ec) noexcept -> auto& {
        _error_code = ec;
        return *this;
    }

    constexpr auto set_unknown_error() noexcept -> auto& {
        if(!_error_code) {
            _error_code = ~0UL;
        }
        return *this;
    }

    auto message() const noexcept -> string_view {
        // TODO: get error string from OpenSSL
        return {"unknown ssl error"};
    }

private:
    unsigned long _error_code{0UL};
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
template <typename Result, api_result_validity Validity>
inline auto
collapse_bool(api_result<Result, ssl_result_info, Validity>&& r) noexcept {
    return r.collapsed(
      [](int value) { return value == 1; },
      [](auto& info) { info.set_unknown_error(); });
}
//------------------------------------------------------------------------------
} // namespace eagine::sslp

#endif // EAGINE_SSL_API_RESULT_HPP
