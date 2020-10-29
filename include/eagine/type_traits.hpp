/**
 *  @file eagine/type_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TYPE_TRAITS_HPP
#define EAGINE_TYPE_TRAITS_HPP

#include <type_traits>

namespace eagine {

template <typename X, typename Match>
using disable_if_same_t = std::enable_if_t<
  !std::is_same_v<std::remove_cv_t<std::remove_reference_t<X>>, Match>>;

template <typename Sig>
struct is_noexcept_function;

template <typename Sig>
using is_noexcept_function_t = typename is_noexcept_function<Sig>::type;

template <typename Sig>
constexpr bool is_noexcept_function_v = is_noexcept_function<Sig>::value;

template <typename RV, typename... P>
struct is_noexcept_function<RV(P...)> : std::false_type {};

template <typename RV, typename... P>
struct is_noexcept_function<RV(P...) noexcept> : std::true_type {};

} // namespace eagine

#endif // EAGINE_TYPE_TRAITS_HPP
