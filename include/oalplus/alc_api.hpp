/**
 *  @file oalplus/alc_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_HPP
#define OALPLUS_ALC_API_HPP

#include "alc_api/api.hpp"
#include "alc_api/api_traits.hpp"
#include "alc_api/constants.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct alc_api
  : basic_alc_api<alc_api_traits>
  , basic_alc_constants<alc_api_traits> {
    alc_api(alc_api_traits& traits)
      : basic_alc_api<alc_api_traits>(traits)
      , basic_alc_constants<alc_api_traits>(traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_HPP

