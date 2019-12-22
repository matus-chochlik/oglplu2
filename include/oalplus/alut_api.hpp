/**
 *  @file oalplus/alut_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_HPP
#define OALPLUS_ALUT_API_HPP

#include "alut_api/api.hpp"
#include "alut_api/api_traits.hpp"
#include "alut_api/constants.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
class alut_api
  : protected alut_api_traits
  , public basic_alut_api<alut_api_traits>
  , public basic_alut_constants<alut_api_traits> {
public:
    alut_api(alut_api_traits traits)
      : alut_api_traits{std::move(traits)}
      , basic_alut_api<alut_api_traits>{*static_cast<alut_api_traits*>(this)}
      , basic_alut_constants<alut_api_traits>{
          *static_cast<alut_api_traits*>(this),
          *static_cast<basic_alut_api<alut_api_traits>*>(this)} {
    }

    alut_api()
      : alut_api{alut_api_traits{}} {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALUT_API_HPP

