/**
 *  @file oalplus/egl_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_EGL_API_HPP
#define OALPLUS_EGL_API_HPP

#include "egl_api/api.hpp"
#include "egl_api/api_traits.hpp"
#include "egl_api/constants.hpp"

namespace eagine {
namespace eglp {
//------------------------------------------------------------------------------
class egl_api
  : protected egl_api_traits
  , public basic_egl_api<egl_api_traits>
  , public basic_egl_constants<egl_api_traits> {
public:
    egl_api(egl_api_traits traits)
      : egl_api_traits{std::move(traits)}
      , basic_egl_api<egl_api_traits>{*static_cast<egl_api_traits*>(this)}
      , basic_egl_constants<egl_api_traits>{
          *static_cast<egl_api_traits*>(this),
          *static_cast<basic_egl_api<egl_api_traits>*>(this)} {
    }

    egl_api()
      : egl_api{egl_api_traits{}} {
    }
};
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // OALPLUS_EGL_API_HPP

