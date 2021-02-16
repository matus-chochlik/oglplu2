/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_MATRIX_ROTATION_HPP
#define EAGINE_MATH_MATRIX_ROTATION_HPP

#include "../quantities.hpp"
#include "matrix_ctr.hpp"
#include <cmath>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine::math {

// rotation_I
template <typename X, int I>
struct rotation_I;

// is_matrix_constructor<rotation_I>
template <typename T, int N, bool RM, bool V, int I>
struct is_matrix_constructor<rotation_I<matrix<T, N, N, RM, V>, I>>
  : std::true_type {};

// scale matrix 4x4 row-major
template <typename T, bool RM, bool V, int I>
struct rotation_I<matrix<T, 4, 4, RM, V>, I> {
    radians_t<T> _v;

    constexpr rotation_I(radians_t<T> v) noexcept
      : _v(v) {}

    using _x = int_constant<0>;
    using _y = int_constant<1>;
    using _z = int_constant<2>;

    static constexpr auto _make(T cx, T sx, _x) noexcept {
        return matrix<T, 4, 4, RM, V>{
          {{T(1), T(0), T(0), T(0)},
           {T(0), cx, -sx, T(0)},
           {T(0), sx, cx, T(0)},
           {T(0), T(0), T(0), T(1)}}};
    }

    static constexpr auto _make(T cx, T sx, _y) noexcept {
        return matrix<T, 4, 4, RM, V>{
          {{cx, T(0), sx, T(0)},
           {T(0), T(1), T(0), T(0)},
           {-sx, T(0), cx, T(0)},
           {T(0), T(0), T(0), T(1)}}};
    }

    static constexpr auto _make(T cx, T sx, _z) noexcept {
        return matrix<T, 4, 4, RM, V>{
          {{cx, -sx, T(0), T(0)},
           {sx, cx, T(0), T(0)},
           {T(0), T(0), T(1), T(0)},
           {T(0), T(0), T(0), T(1)}}};
    }

    constexpr auto operator()() const {
        using _axis = int_constant<I>;
        return _make(cos(_v), sin(_v) * (RM ? 1 : -1), _axis());
    }
};

// multiply
template <typename T, int N, bool RM1, bool RM2, bool V, int I>
static constexpr auto multiply(
  const rotation_I<matrix<T, N, N, RM1, V>, I>& a,
  const rotation_I<matrix<T, N, N, RM2, V>, I>& b) noexcept
  -> rotation_I<matrix<T, N, N, RM1, V>, I> {
    return {radians_t<T>{T(a._v) + T(b._v)}};
}

// reorder_mat_ctr(rotation_I)
template <typename T, int N, bool RM, bool V, int I>
static constexpr auto
reorder_mat_ctr(const rotation_I<matrix<T, N, N, RM, V>, I>& c) noexcept
  -> rotation_I<matrix<T, N, N, !RM, V>, I> {
    return {c._v};
}

// rotation x
template <typename M>
using rotation_x = rotation_I<M, 0>;

// pitch
template <typename M>
using pitch = rotation_x<M>;

// rotation y
template <typename M>
using rotation_y = rotation_I<M, 1>;

// yaw
template <typename M>
using yaw = rotation_y<M>;

// rotation z
template <typename M>
using rotation_z = rotation_I<M, 2>;

// roll
template <typename M>
using roll = rotation_z<M>;

// matrix_*
template <typename T, bool V>
using matrix_rotation_x =
  convertible_matrix_constructor<rotation_x<matrix<T, 4, 4, true, V>>>;

template <typename T, bool V>
using matrix_rotation_y =
  convertible_matrix_constructor<rotation_y<matrix<T, 4, 4, true, V>>>;

template <typename T, bool V>
using matrix_rotation_z =
  convertible_matrix_constructor<rotation_z<matrix<T, 4, 4, true, V>>>;

} // namespace eagine::math

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // EAGINE_MATH_MATRIX_ROTATION_HPP
