/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_MATRIX_REFLECTION_HPP
#define EAGINE_MATH_MATRIX_REFLECTION_HPP

#include "matrix_ctr.hpp"
#include <cmath>

namespace eagine::math {

// reflection_I
template <typename X, int I>
class reflection_I;

// is_matrix_constructor<reflection_I>
template <typename T, int N, bool RM, bool V, int I>
struct is_matrix_constructor<reflection_I<matrix<T, N, N, RM, V>, I>>
  : std::true_type {};

/// @brief Implements constructor of reflection transformation matrix.
/// @ingroup math
/// @tparam I index of the reflection axis (0 = x, 1 = y, 2 = z).
/// @see matrix_reflection_x
/// @see matrix_reflection_y
/// @see matrix_reflection_z
///
/// @note Do not use directly, use matrix_reflection_{x,y,z}
template <typename T, bool RM, bool V, int I>
class reflection_I<matrix<T, 4, 4, RM, V>, I> {
public:
    /// @brief Initializes the matrix constructor.
    /// @param r says whether to actually reflect along the I axis.
    constexpr reflection_I(bool r = true) noexcept
      : _v(r ? T(-1) : T(1)) {}

    constexpr auto v(int i) const noexcept -> T {
        return (I == i) ? _v : T(1);
    }

    /// @brief Returns the constructed matrix.
    constexpr auto operator()() const noexcept {
        return matrix<T, 4, 4, RM, V>{
          {{v(0), T(0), T(0), T(0)},
           {T(0), v(1), T(0), T(0)},
           {T(0), T(0), v(2), T(0)},
           {T(0), T(0), T(0), T(1)}}};
    }

private:
    T _v;
};

// multiply
template <typename T, int N, bool RM1, bool RM2, bool V, int I>
static constexpr auto multiply(
  const reflection_I<matrix<T, N, N, RM1, V>, I>& a,
  const reflection_I<matrix<T, N, N, RM2, V>, I>& b) noexcept
  -> reflection_I<matrix<T, N, N, RM1, V>, I> {
    return {(a._v < b._v) || (a._v > b._v)};
}

// reorder_mat_ctr(reflection_I)
template <typename T, int N, bool RM, bool V, int I>
static constexpr auto
reorder_mat_ctr(const reflection_I<matrix<T, N, N, RM, V>, I>& c) noexcept
  -> reflection_I<matrix<T, N, N, !RM, V>, I> {
    return {c._v < T(0)};
}

/// @brief Alias for implementation of constructor of reflection along x-axis matrix.
/// @ingroup math
template <typename M>
using reflection_x = reflection_I<M, 0>;

/// @brief Alias for implementation of constructor of reflection along y-axis matrix.
/// @ingroup math
template <typename M>
using reflection_y = reflection_I<M, 1>;

/// @brief Alias for implementation of constructor of reflection along z-axis matrix.
/// @ingroup math
template <typename M>
using reflection_z = reflection_I<M, 2>;

/// @brief Alias for constructor of reflection along x-axis transformation matrix.
/// @ingroup math
/// @see matrix_translation
/// @see matrix_rotation_x
/// @see matrix_rotation_y
/// @see matrix_rotation_z
/// @see matrix_reflection_y
/// @see matrix_reflection_z
/// @see matrix_scale
/// @see matrix_uniform_scale
template <typename T, bool V>
using matrix_reflection_x =
  convertible_matrix_constructor<reflection_x<matrix<T, 4, 4, true, V>>>;

/// @brief Alias for constructor of reflection along y-axis transformation matrix.
/// @ingroup math
/// @see matrix_translation
/// @see matrix_rotation_x
/// @see matrix_rotation_y
/// @see matrix_rotation_z
/// @see matrix_reflection_x
/// @see matrix_reflection_z
/// @see matrix_scale
/// @see matrix_uniform_scale
template <typename T, bool V>
using matrix_reflection_y =
  convertible_matrix_constructor<reflection_y<matrix<T, 4, 4, true, V>>>;

/// @brief Alias for constructor of reflection along z-axis transformation matrix.
/// @ingroup math
/// @see matrix_translation
/// @see matrix_rotation_x
/// @see matrix_rotation_y
/// @see matrix_rotation_z
/// @see matrix_reflection_x
/// @see matrix_reflection_y
/// @see matrix_scale
/// @see matrix_uniform_scale
template <typename T, bool V>
using matrix_reflection_z =
  convertible_matrix_constructor<reflection_z<matrix<T, 4, 4, true, V>>>;

} // namespace eagine::math

#endif // EAGINE_MATH_MATRIX_REFLECTION_HPP
