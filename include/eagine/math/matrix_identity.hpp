/**
 *  @file eagine/math/matrix_identity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_IDENTITY_HPP
#define EAGINE_MATH_MATRIX_IDENTITY_HPP

#include "matrix_ctr.hpp"

namespace eagine::math {

// identity
template <typename X>
struct identity;

// is_matrix_constructor<identity>
template <typename T, int R, int C, bool RM, bool V>
struct is_matrix_constructor<identity<matrix<T, R, C, RM, V>>>
  : std::true_type {};

// identity Matrix
template <typename T, int R, int C, bool RM, bool V>
struct identity<matrix<T, R, C, RM, V>> {
    template <int... U>
    using _useq = std::integer_sequence<int, U...>;

    template <int N>
    using _make_useq = std::make_integer_sequence<int, N>;

    template <int... I>
    static constexpr inline auto _identity(_useq<I...>) noexcept
      -> matrix<T, R, C, RM, V> {
        return {{vect::axis < T, RM ? C : R, I, V > ::apply(1)...}};
    }

    constexpr inline auto operator()() const noexcept
      -> matrix<T, R, C, RM, V> {
        using _riS = _make_useq<RM ? R : C>;
        return _identity(_riS());
    }
};

// multiply
template <typename T, int C, int R, bool RM1, bool RM2, bool V>
static constexpr inline auto multiply(
  const identity<matrix<T, C, R, RM1, V>>&,
  const identity<matrix<T, C, R, RM2, V>>&) noexcept
  -> identity<matrix<T, C, R, RM1, V>> {
    return {};
}

// multiply
template <
  typename MC,
  typename T,
  int C,
  int R,
  bool RM,
  bool V,
  typename = std::enable_if_t<
    is_matrix_constructor_v<MC> &&
    are_multiplicable<constructed_matrix_t<MC>, matrix<T, C, R, RM, V>>::value>>
static constexpr inline auto
multiply(const MC& mc, const identity<matrix<T, C, R, RM, V>>&) noexcept -> MC {
    return mc;
}

template <
  typename T,
  int C,
  int R,
  bool RM,
  bool V,
  typename MC,
  typename = std::enable_if_t<
    is_matrix_constructor_v<MC> &&
    are_multiplicable<matrix<T, C, R, RM, V>, constructed_matrix_t<MC>>::value>>
static constexpr inline auto
multiply(const identity<matrix<T, C, R, RM, V>>&, const MC& mc) noexcept -> MC {
    return mc;
}

// reorder_mat_ctr(identity)
template <typename T, int R, int C, bool RM, bool V>
static constexpr inline auto
reorder_mat_ctr(const identity<matrix<T, R, C, RM, V>>&) noexcept
  -> identity<matrix<T, R, C, !RM, V>> {
    return {};
}

} // namespace eagine::math

#endif // EAGINE_MATH_MATRIX_IDENTITY_HPP
