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

template <std::size_t I>
typename std::tuple_element<I, alc_api>::type& get(alc_api& x) noexcept {
    return x;
}

template <std::size_t I>
const typename std::tuple_element<I, alc_api>::type& get(
  const alc_api& x) noexcept {
    return x;
}
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {

template <>
struct tuple_size<eagine::oalp::alc_api>
  : public std::integral_constant<std::size_t, 2> {};

template <>
struct tuple_element<0, eagine::oalp::alc_api> {
    using type = eagine::oalp::basic_alc_api<eagine::oalp::alc_api_traits>;
};

template <>
struct tuple_element<1, eagine::oalp::alc_api> {
    using type =
      eagine::oalp::basic_alc_constants<eagine::oalp::alc_api_traits>;
};

} // namespace std

#endif // OALPLUS_ALC_API_HPP

