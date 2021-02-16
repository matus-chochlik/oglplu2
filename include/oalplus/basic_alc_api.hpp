/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_BASIC_ALC_API_HPP
#define OALPLUS_BASIC_ALC_API_HPP

#include "alc_api/api.hpp"
#include "alc_api/api_traits.hpp"
#include "alc_api/constants.hpp"

namespace eagine::oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_alc_api
  : protected ApiTraits
  , public basic_alc_operations<ApiTraits>
  , public basic_alc_constants<ApiTraits> {
public:
    basic_alc_api(ApiTraits traits)
      : ApiTraits{std::move(traits)}
      , basic_alc_operations<ApiTraits>{*static_cast<ApiTraits*>(this)}
      , basic_alc_constants<ApiTraits>{
          *static_cast<ApiTraits*>(this),
          *static_cast<basic_alc_operations<ApiTraits>*>(this)} {}

    basic_alc_api()
      : basic_alc_api{ApiTraits{}} {}
};

template <std::size_t I, typename ApiTraits>
auto get(basic_alc_api<ApiTraits>& x) noexcept ->
  typename std::tuple_element<I, basic_alc_api<ApiTraits>>::type& {
    return x;
}

template <std::size_t I, typename ApiTraits>
auto get(const basic_alc_api<ApiTraits>& x) noexcept -> const
  typename std::tuple_element<I, basic_alc_api<ApiTraits>>::type& {
    return x;
}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {

template <typename ApiTraits>
struct tuple_size<eagine::oalp::basic_alc_api<ApiTraits>>
  : public std::integral_constant<std::size_t, 2> {};

template <typename ApiTraits>
struct tuple_element<0, eagine::oalp::basic_alc_api<ApiTraits>> {
    using type = eagine::oalp::basic_alc_operations<ApiTraits>;
};

template <typename ApiTraits>
struct tuple_element<1, eagine::oalp::basic_alc_api<ApiTraits>> {
    using type = eagine::oalp::basic_alc_constants<ApiTraits>;
};

} // namespace std

#endif // OALPLUS_BASIC_ALC_API_HPP
