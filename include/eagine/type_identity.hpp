/**
 *  @file eagine/type_identity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TYPE_IDENTITY_HPP
#define EAGINE_TYPE_IDENTITY_HPP

#include <type_traits>

namespace eagine {

template <typename T>
struct type_identity {
    using type = T;

    template <
      typename X,
      typename = std::enable_if_t<std::is_same_v<T, X> && !std::is_array_v<X>>>
    constexpr inline auto operator()(X v) const -> X {
        return v;
    }
};

template <typename T, typename F>
struct get_type {
    template <typename X>
    static auto _get(X*) -> typename X::type;

    template <typename X>
    static auto _get(...) -> F;

    using type = decltype(_get<T>(static_cast<T*>(nullptr)));
};

template <typename T, typename F = void>
using type_t = typename get_type<T, F>::type;

template <typename T>
static constexpr inline auto make_identity(const T&) noexcept
  -> type_identity<T> {
    return {};
}

} // namespace eagine

#endif // EAGINE_TYPE_IDENTITY_HPP
