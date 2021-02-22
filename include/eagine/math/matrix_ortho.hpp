/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_MATRIX_ORTHO_HPP
#define EAGINE_MATH_MATRIX_ORTHO_HPP

#include "matrix_ctr.hpp"

namespace eagine::math {

// ortho
template <typename X>
class ortho;

// is_matrix_constructor<ortho>
template <typename T, int N, bool RM, bool V>
struct is_matrix_constructor<ortho<matrix<T, N, N, RM, V>>> : std::true_type {};

/// @brief Implements constructor of orthographic projection matrix.
/// @ingroup math
/// @see matrix_ortho
///
/// @note Do not use directly, use matrix_ortho.
template <typename T, bool RM, bool V>
class ortho<matrix<T, 4, 4, RM, V>> {
public:
    constexpr ortho(const vect::data_t<T, 6, V>& v) noexcept
      : _v(v) {}

    /// @brief Initializes the matrix constructor.
    constexpr ortho(
      T x_left,
      T x_right,
      T y_bottom,
      T y_top,
      T z_near,
      T z_far) noexcept
      : _v{x_left, x_right, y_bottom, y_top, z_near, z_far} {}

    /// @brief Returns the constructed matrix.
    constexpr auto operator()() const noexcept {
        return _make(bool_constant<RM>());
    }

private:
    constexpr auto _x_left() const {
        return _v[0];
    }
    constexpr auto _x_right() const {
        return _v[1];
    }
    constexpr auto _y_bottom() const {
        return _v[2];
    }
    constexpr auto _y_top() const {
        return _v[3];
    }
    constexpr auto _z_near() const {
        return _v[4];
    }
    constexpr auto _z_far() const {
        return _v[5];
    }

    constexpr auto _m00() const noexcept {
        return T(2) / (_x_right() - _x_left());
    }

    constexpr auto _m11() const noexcept {
        return T(2) / (_y_top() - _y_bottom());
    }

    constexpr auto _m22() const noexcept {
        return -T(2) / (_z_far() - _z_near());
    }

    constexpr auto _m30() const noexcept {
        return -(_x_right() + _x_left()) / (_x_right() - _x_left());
    }

    constexpr auto _m31() const noexcept {
        return -(_y_top() + _y_bottom()) / (_y_top() - _y_bottom());
    }

    constexpr auto _m32() const noexcept {
        return -(_z_far() + _z_near()) / (_z_far() - _z_near());
    }

    constexpr auto _make(std::true_type) const noexcept {
        return matrix<T, 4, 4, true, V>{
          {{_m00(), T(0), T(0), _m30()},
           {T(0), _m11(), T(0), _m31()},
           {T(0), T(0), _m22(), _m32()},
           {T(0), T(0), T(0), T(1)}}};
    }

    constexpr auto _make(std::false_type) const noexcept {
        return matrix<T, 4, 4, false, V>{
          {{_m00(), T(0), T(0), T(0)},
           {T(0), _m11(), T(0), T(0)},
           {T(0), T(0), _m22(), T(0)},
           {_m30(), _m31(), _m32(), T(1)}}};
    }

    using _dT = vect::data_t<T, 6, V>;
    _dT _v;
};

// reorder_mat_ctr(ortho)
template <typename T, int N, bool RM, bool V>
static constexpr auto
reorder_mat_ctr(const ortho<matrix<T, N, N, RM, V>>& c) noexcept
  -> ortho<matrix<T, N, N, !RM, V>> {
    return {c._v};
}

/// @brief Alias for constructor of orthographic projection matrix.
/// @ingroup math
template <typename T, bool V>
using matrix_ortho =
  convertible_matrix_constructor<ortho<matrix<T, 4, 4, true, V>>>;

} // namespace eagine::math

#endif // EAGINE_MATH_MATRIX_ORTHO_HPP
