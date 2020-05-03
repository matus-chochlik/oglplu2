/**
 *  @file eagine/ossl_api/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OSSL_API_CONSTANTS_HPP
#define EAGINE_OSSL_API_CONSTANTS_HPP

#include "c_api.hpp"

namespace eagine {
namespace osslp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct basic_ossl_constants {
public:
    basic_ossl_constants(ApiTraits&, basic_ossl_c_api<ApiTraits>&) {
    }
};
//------------------------------------------------------------------------------
} // namespace osslp
} // namespace eagine

#endif // EAGINE_OSSL_API_CONSTANTS_HPP

