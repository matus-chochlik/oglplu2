/**
 *  @file eagine/math/scalar.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_SCALAR_HPP
#define EAGINE_MATH_SCALAR_HPP

#include "../identity.hpp"
#include "../vect/data.hpp"
#include "../vect/fill.hpp"
#include "fwd.hpp"
#include <type_traits>

namespace eagine::math {
//------------------------------------------------------------------------------
template <typename T, int N, bool V>
struct scalar {
    using type = scalar;

    using value_type = T;

    using is_vectorized = vect::has_vect_data_t<T, N, V>;

    using data_type =
      std::conditional_t<is_vectorized::value, vect::data_t<T, N, V>, T>;

    data_type _v;

    using _cpT = const scalar&;

    static constexpr inline scalar _from(data_type v) noexcept {
        return scalar{v};
    }

    static constexpr inline scalar _make(T v, std::true_type) noexcept {
        return scalar{vect::fill<T, N, V>::apply(v)};
    }

    static constexpr inline scalar _make(T v, std::false_type) noexcept {
        return scalar{v};
    }

    static constexpr inline scalar make(T v) noexcept {
        return _make(v, is_vectorized());
    }

    constexpr inline T _get(std::true_type) const noexcept {
        return _v[0];
    }

    constexpr inline T _get(std::false_type) const noexcept {
        return _v;
    }

    constexpr inline operator T() const noexcept {
        return _get(is_vectorized());
    }

    inline scalar& operator=(T v) noexcept {
        return *this = make(v);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::math

#endif // EAGINE_MATH_SCALAR_HPP
