/**
 *  @file eagine/ssl_api/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_SSL_API_CONSTANTS_HPP
#define EAGINE_SSL_API_CONSTANTS_HPP

#include "c_api.hpp"

namespace eagine::sslp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct basic_ssl_constants {
public:
    basic_ssl_constants(ApiTraits&, basic_ssl_c_api<ApiTraits>&) {}
};
//------------------------------------------------------------------------------
} // namespace eagine::sslp

#endif // EAGINE_SSL_API_CONSTANTS_HPP
