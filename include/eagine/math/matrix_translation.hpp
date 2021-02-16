/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_MATRIX_TRANSLATION_HPP
#define EAGINE_MATH_MATRIX_TRANSLATION_HPP

#include "matrix_ctr.hpp"

namespace eagine::math {

// translation
template <typename X>
struct translation;

// is_matrix_constructor<translation>
template <typename T, int N, bool RM, bool V>
struct is_matrix_constructor<translation<matrix<T, N, N, RM, V>>>
  : std::true_type {};

// translation matrix 4x4 row-major
template <typename T, bool RM, bool V>
struct translation<matrix<T, 4, 4, RM, V>> {
    vect::data_t<T, 3, V> _v;

    constexpr translation(vect::data_t<T, 3, V> v) noexcept
      : _v(v) {}

    constexpr translation(T vx, T vy, T vz) noexcept
      : _v{vx, vy, vz} {}

    constexpr auto _make(std::true_type) const noexcept {
        return matrix<T, 4, 4, true, V>{
          {{T(1), T(0), T(0), _v[0]},
           {T(0), T(1), T(0), _v[1]},
           {T(0), T(0), T(1), _v[2]},
           {T(0), T(0), T(0), T(1)}}};
    }

    constexpr auto _make(std::false_type) const noexcept {
        return matrix<T, 4, 4, false, V>{
          {{T(1), T(0), T(0), T(0)},
           {T(0), T(1), T(0), T(0)},
           {T(0), T(0), T(1), T(0)},
           {_v[0], _v[1], _v[2], T(1)}}};
    }

    constexpr auto operator()() const noexcept {
        return _make(bool_constant<RM>());
    }
};

// multiply
template <typename T, int N, bool RM1, bool RM2, bool V>
static constexpr auto multiply(
  const translation<matrix<T, N, N, RM1, V>>& a,
  const translation<matrix<T, N, N, RM2, V>>& b) noexcept
  -> translation<matrix<T, N, N, RM1, V>> {
    return {a._v + b._v};
}

// reorder_mat_ctr(translation)
template <typename T, int N, bool RM, bool V>
static constexpr auto
reorder_mat_ctr(const translation<matrix<T, N, N, RM, V>>& c) noexcept
  -> translation<matrix<T, N, N, !RM, V>> {
    return {c._v};
}

// matrix_*
template <typename T, bool V>
using matrix_translation =
  convertible_matrix_constructor<translation<matrix<T, 4, 4, true, V>>>;

} // namespace eagine::math

#endif // EAGINE_MATH_MATRIX_TRANSLATION_HPP
