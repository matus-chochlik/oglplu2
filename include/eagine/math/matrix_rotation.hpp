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
EAGINE_DIAG_PUSH()
EAGINE_DIAG_OFF(double-promotion)
#endif

namespace eagine::math {

// rotation_I
template <typename X, int I>
class rotation_I;

// is_matrix_constructor<rotation_I>
template <typename T, int N, bool RM, bool V, int I>
struct is_matrix_constructor<rotation_I<matrix<T, N, N, RM, V>, I>>
  : std::true_type {};

/// @brief Implements constructor of rotation transformation matrix.
/// @ingroup math
/// @tparam I index of the rotation axis (0 = x, 1 = y, 2 = z).
/// @see matrix_rotation_x
/// @see matrix_rotation_y
/// @see matrix_rotation_z
///
/// @note Do not use directly, use matrix_rotation_{x,y,z}
template <typename T, bool RM, bool V, int I>
class rotation_I<matrix<T, 4, 4, RM, V>, I> {
public:
    /// @brief Initializes the matrix constructor.
    /// @param v is the angle of rotation.
    constexpr rotation_I(radians_t<T> v) noexcept
      : _v(v) {}

    /// @brief Returns the constructed matrix.
    constexpr auto operator()() const {
        using _axis = int_constant<I>;
        return _make(cos(_v), sin(_v) * (RM ? 1 : -1), _axis());
    }

    friend constexpr auto
    reorder_mat_ctr(const rotation_I<matrix<T, 4, 4, RM, V>, I>& c) noexcept
      -> rotation_I<matrix<T, 4, 4, !RM, V>, I> {
        return {c._v};
    }

private:
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

    radians_t<T> _v;
};

// multiply
template <typename T, int N, bool RM1, bool RM2, bool V, int I>
static constexpr auto multiply(
  const rotation_I<matrix<T, N, N, RM1, V>, I>& a,
  const rotation_I<matrix<T, N, N, RM2, V>, I>& b) noexcept
  -> rotation_I<matrix<T, N, N, RM1, V>, I> {
    return {radians_t<T>{T(a._v) + T(b._v)}};
}

/// @brief Alias for implementation of constructor of rotation along x-axis matrix.
/// @ingroup math
template <typename M>
using rotation_x = rotation_I<M, 0>;

/// @brief Alias for implementation of constructor of rotation along y-axis matrix.
/// @ingroup math
template <typename M>
using rotation_y = rotation_I<M, 1>;

/// @brief Alias for implementation of constructor of rotation along z-axis matrix.
/// @ingroup math
template <typename M>
using rotation_z = rotation_I<M, 2>;

/// @brief Alias for constructor of rotation along x-axis transformation matrix.
/// @ingroup math
/// @see matrix_translation
/// @see matrix_rotation_y
/// @see matrix_rotation_z
/// @see matrix_scale
/// @see matrix_uniform_scale
template <typename T, bool V>
using matrix_rotation_x =
  convertible_matrix_constructor<rotation_x<matrix<T, 4, 4, true, V>>>;

/// @brief Alias for constructor of rotation along y-axis transformation matrix.
/// @ingroup math
/// @see matrix_translation
/// @see matrix_rotation_x
/// @see matrix_rotation_z
/// @see matrix_reflection_x
/// @see matrix_reflection_y
/// @see matrix_reflection_z
/// @see matrix_scale
/// @see matrix_uniform_scale
template <typename T, bool V>
using matrix_rotation_y =
  convertible_matrix_constructor<rotation_y<matrix<T, 4, 4, true, V>>>;

/// @brief Alias for constructor of rotation along z-axis transformation matrix.
/// @ingroup math
/// @see matrix_translation
/// @see matrix_rotation_x
/// @see matrix_rotation_y
/// @see matrix_reflection_x
/// @see matrix_reflection_y
/// @see matrix_reflection_z
/// @see matrix_scale
/// @see matrix_uniform_scale
template <typename T, bool V>
using matrix_rotation_z =
  convertible_matrix_constructor<rotation_z<matrix<T, 4, 4, true, V>>>;

} // namespace eagine::math

#ifdef __clang__
EAGINE_DIAG_POP()
#endif

#endif // EAGINE_MATH_MATRIX_ROTATION_HPP
