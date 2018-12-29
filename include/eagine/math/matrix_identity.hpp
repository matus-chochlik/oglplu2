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

namespace eagine {
namespace math {

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
    static constexpr inline matrix<T, R, C, RM, V> _identity(
      _useq<I...>) noexcept {
        return {{vect::axis < T, RM ? C : R, I, V > ::apply(1)...}};
    }

    constexpr inline matrix<T, R, C, RM, V> operator()() const noexcept {
        using _riS = _make_useq<RM ? R : C>;
        return _identity(_riS());
    }
};

// multiply
template <typename T, int C, int R, bool RM1, bool RM2, bool V>
static constexpr inline identity<matrix<T, C, R, RM1, V>> multiply(
  const identity<matrix<T, C, R, RM1, V>>&,
  const identity<matrix<T, C, R, RM2, V>>&) noexcept {
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
static constexpr inline MC multiply(
  const MC& mc, const identity<matrix<T, C, R, RM, V>>&) noexcept {
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
static constexpr inline MC multiply(
  const identity<matrix<T, C, R, RM, V>>&, const MC& mc) noexcept {
    return mc;
}

// reorder_mat_ctr(identity)
template <typename T, int R, int C, bool RM, bool V>
static constexpr inline identity<matrix<T, R, C, !RM, V>> reorder_mat_ctr(
  const identity<matrix<T, R, C, RM, V>>&) noexcept {
    return {};
}

} // namespace math
} // namespace eagine

#endif // EAGINE_MATH_MATRIX_IDENTITY_HPP
