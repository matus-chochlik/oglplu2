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

template <std::size_t I>
typename std::tuple_element<I, alut_api>::type& get(alut_api& x) noexcept {
    return x;
}

template <std::size_t I>
const typename std::tuple_element<I, alut_api>::type& get(
  const alut_api& x) noexcept {
    return x;
}
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {

template <>
struct tuple_size<eagine::oalp::alut_api>
  : public std::integral_constant<std::size_t, 2> {};

template <>
struct tuple_element<0, eagine::oalp::alut_api> {
    using type = eagine::oalp::basic_alut_api<eagine::oalp::alut_api_traits>;
};

template <>
struct tuple_element<1, eagine::oalp::alut_api> {
    using type =
      eagine::oalp::basic_alut_constants<eagine::oalp::alut_api_traits>;
};

} // namespace std

#endif // OALPLUS_ALUT_API_HPP

