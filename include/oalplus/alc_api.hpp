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
class alc_api
  : protected alc_api_traits
  , public basic_alc_api<alc_api_traits>
  , public basic_alc_constants<alc_api_traits> {
public:
    alc_api(alc_api_traits traits)
      : alc_api_traits{std::move(traits)}
      , basic_alc_api<alc_api_traits>{*static_cast<alc_api_traits*>(this)}
      , basic_alc_constants<alc_api_traits>{
          *static_cast<alc_api_traits*>(this),
          *static_cast<basic_alc_api<alc_api_traits>*>(this)} {
    }

    alc_api()
      : alc_api{alc_api_traits{}} {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_HPP

