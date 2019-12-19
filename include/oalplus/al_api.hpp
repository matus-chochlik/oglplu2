/**
 *  @file oalplus/al_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_HPP
#define OALPLUS_AL_API_HPP

#include "al_api/api.hpp"
#include "al_api/api_traits.hpp"
#include "al_api/constants.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
class al_api
  : protected al_api_traits
  , public basic_al_api<al_api_traits>
  , public basic_al_constants<al_api_traits> {
public:
    al_api(al_api_traits traits)
      : al_api_traits{std::move(traits)}
      , basic_al_api<al_api_traits>{*static_cast<al_api_traits*>(this)}
      , basic_al_constants<al_api_traits>{
          *static_cast<al_api_traits*>(this),
          *static_cast<basic_al_api<al_api_traits>*>(this)} {
    }

    al_api()
      : al_api{al_api_traits{}} {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_HPP

