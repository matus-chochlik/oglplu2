/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_MATRIX_SCALE_HPP
#define EAGINE_MATH_MATRIX_SCALE_HPP

#include "matrix_ctr.hpp"

namespace eagine::math {

// scale
template <typename X>
class scale;

// is_matrix_constructor<scale>
template <typename T, int N, bool RM, bool V>
struct is_matrix_constructor<scale<matrix<T, N, N, RM, V>>> : std::true_type {};

/// @brief Implements constructor of scale transformation matrix.
/// @ingroup math
/// @see matrix_scale
///
/// @note Do not use directly, use matrix_scale
template <typename T, bool RM, bool V>
class scale<matrix<T, 4, 4, RM, V>> {
public:
    constexpr scale(vect::data_t<T, 3, V> v) noexcept
      : _v(v) {}

    /// @brief Initializes the matrix constructor.
    /// @param vx is the x-axis scale factor.
    /// @param vy is the y-axis scale factor.
    /// @param vz is the z-axis scale factor.
    constexpr scale(T vx, T vy, T vz) noexcept
      : _v{vx, vy, vz} {}

    /// @brief Returns the constructed matrix.
    constexpr auto operator()() const noexcept {
        return matrix<T, 4, 4, RM, V>{
          {{_v[0], T(0), T(0), T(0)},
           {T(0), _v[1], T(0), T(0)},
           {T(0), T(0), _v[2], T(0)},
           {T(0), T(0), T(0), T(1)}}};
    }

    friend constexpr auto
    reorder_mat_ctr(const scale<matrix<T, 4, 4, RM, V>>& c) noexcept
      -> scale<matrix<T, 4, 4, !RM, V>> {
        return {c._v};
    }

private:
    vect::data_t<T, 3, V> _v;
};

// multiply
template <typename T, int N, bool RM1, bool RM2, bool V>
static constexpr auto multiply(
  const scale<matrix<T, N, N, RM1, V>>& a,
  const scale<matrix<T, N, N, RM2, V>>& b) noexcept
  -> scale<matrix<T, N, N, RM1, V>> {
    return {a._v * b._v};
}

// uniform_scale
template <typename X>
class uniform_scale;

// is_matrix_constructor<uniform_scale>
template <typename T, int N, bool RM, bool V>
struct is_matrix_constructor<uniform_scale<matrix<T, N, N, RM, V>>>
  : std::true_type {};

/// @brief Implements constructor of uniform scale transformation matrix.
/// @ingroup math
/// @see matrix_uniform_scale
///
/// @note Do not use directly, use matrix_uniform_scale
template <typename T, bool RM, bool V>
class uniform_scale<matrix<T, 4, 4, RM, V>> {
public:
    /// @brief Initializes the matrix constructor.
    /// @param v is the scale factor.
    constexpr uniform_scale(T v) noexcept
      : _v(v) {}

    /// @brief Returns the constructed matrix.
    constexpr auto operator()() const noexcept {
        return matrix<T, 4, 4, RM, V>{
          {{_v, T(0), T(0), T(0)},
           {T(0), _v, T(0), T(0)},
           {T(0), T(0), _v, T(0)},
           {T(0), T(0), T(0), T(1)}}};
    }

    friend constexpr auto
    reorder_mat_ctr(const uniform_scale<matrix<T, 4, 4, RM, V>>& c) noexcept
      -> uniform_scale<matrix<T, 4, 4, !RM, V>> {
        return {c._v};
    }

private:
    T _v;
};

// multiply
template <typename T, int N, bool RM1, bool RM2, bool V>
static constexpr auto multiply(
  const uniform_scale<matrix<T, N, N, RM1, V>>& a,
  const uniform_scale<matrix<T, N, N, RM2, V>>& b) noexcept
  -> uniform_scale<matrix<T, N, N, RM1, V>> {
    return {a._v * b._v};
}

/// @brief Alias for constructor of scale transformation matrix.
/// @ingroup math
/// @see matrix_translation
/// @see matrix_rotation_x
/// @see matrix_rotation_y
/// @see matrix_rotation_z
/// @see matrix_uniform_scale
template <typename T, bool V>
using matrix_scale =
  convertible_matrix_constructor<scale<matrix<T, 4, 4, true, V>>>;

/// @brief Alias for constructor of uniform scale transformation matrix.
/// @ingroup math
/// @see matrix_translation
/// @see matrix_rotation_x
/// @see matrix_rotation_y
/// @see matrix_rotation_z
/// @see matrix_reflection_x
/// @see matrix_reflection_y
/// @see matrix_reflection_z
/// @see matrix_scale
template <typename T, bool V>
using matrix_uniform_scale =
  convertible_matrix_constructor<uniform_scale<matrix<T, 4, 4, true, V>>>;

} // namespace eagine::math

#endif // EAGINE_MATH_MATRIX_SCALE_HPP
