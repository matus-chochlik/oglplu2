/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_SSL_API_FWD_HPP
#define EAGINE_SSL_API_FWD_HPP

namespace eagine::sslp {
//------------------------------------------------------------------------------
class ssl_api_traits;

template <typename ApiTraits>
class basic_ssl_api;

using ssl_api = basic_ssl_api<ssl_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::sslp

#endif // EAGINE_SSL_API_FWD_HPP
