/**
 *  @file eagine/identity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_IDENTITY_1509260923_HPP
#define EAGINE_IDENTITY_1509260923_HPP

#include <type_traits>

namespace eagine {

template <typename T>
struct identity {
    using type = T;

    template <
      typename X,
      typename = std::enable_if_t<std::is_same_v<T, X> && !std::is_array_v<X>>>
    constexpr inline X operator()(X v) const {
        return v;
    }
};

template <typename T>
static constexpr inline identity<T> make_identity(const T&) noexcept {
    return {};
}

} // namespace eagine

#endif // include guard
