/**
 *  @file eagine/ossl_api_fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OSSL_API_FWD_HPP
#define EAGINE_OSSL_API_FWD_HPP

namespace eagine {
namespace osslp {
//------------------------------------------------------------------------------
class ossl_api_traits;

template <typename ApiTraits>
class basic_ossl_api;

using ossl_api = basic_ossl_api<ossl_api_traits>;
//------------------------------------------------------------------------------
} // namespace osslp
} // namespace eagine

#endif // EAGINE_OSSL_API_FWD_HPP

