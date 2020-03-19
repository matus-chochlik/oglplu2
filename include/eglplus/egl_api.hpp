/**
 *  @file eglplus/egl_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_HPP
#define EGLPLUS_EGL_API_HPP

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

template <std::size_t I>
typename std::tuple_element<I, egl_api>::type& get(egl_api& x) noexcept {
    return x;
}

template <std::size_t I>
const typename std::tuple_element<I, egl_api>::type& get(
  const egl_api& x) noexcept {
    return x;
}
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {

template <>
struct tuple_size<eagine::eglp::egl_api>
  : public std::integral_constant<std::size_t, 2> {};

template <>
struct tuple_element<0, eagine::eglp::egl_api> {
    using type = eagine::eglp::basic_egl_api<eagine::eglp::egl_api_traits>;
};

template <>
struct tuple_element<1, eagine::eglp::egl_api> {
    using type =
      eagine::eglp::basic_egl_constants<eagine::eglp::egl_api_traits>;
};

} // namespace std

#endif // EGLPLUS_EGL_API_HPP

