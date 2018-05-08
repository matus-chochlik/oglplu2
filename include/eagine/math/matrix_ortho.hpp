/**
 *  @file eagine/math/matrix_ortho.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_ORTHO_1509260923_HPP
#define EAGINE_MATH_MATRIX_ORTHO_1509260923_HPP

#include "matrix_ctr.hpp"

namespace eagine {
namespace math {

// ortho
template <typename X>
struct ortho;

// is_matrix_constructor<ortho>
template <typename T, int N, bool RM, bool V>
struct is_matrix_constructor<ortho<matrix<T, N, N, RM, V>>> : std::true_type {};

// ortho matrix 4x4
template <typename T, bool RM, bool V>
struct ortho<matrix<T, 4, 4, RM, V>> {
    typedef vect::data_t<T, 6, V> _dT;
    _dT _v;

    constexpr ortho(const _dT& v) noexcept
      : _v(v) {
    }

    constexpr ortho(
      T x_left, T x_right, T y_bottom, T y_top, T z_near, T z_far) noexcept
      : _v{x_left, x_right, y_bottom, y_top, z_near, z_far} {
    }

    constexpr inline T _x_left(void) const {
	return _v[0];
    }
    constexpr inline T _x_right(void) const {
	return _v[1];
    }
    constexpr inline T _y_bottom(void) const {
	return _v[2];
    }
    constexpr inline T _y_top(void) const {
	return _v[3];
    }
    constexpr inline T _z_near(void) const {
	return _v[4];
    }
    constexpr inline T _z_far(void) const {
	return _v[5];
    }

    constexpr inline T _m00(void) const noexcept {
	return T(2) / (_x_right() - _x_left());
    }

    constexpr inline T _m11(void) const noexcept {
	return T(2) / (_y_top() - _y_bottom());
    }

    constexpr inline T _m22(void) const noexcept {
	return -T(2) / (_z_far() - _z_near());
    }

    constexpr inline T _m30(void) const noexcept {
	return -(_x_right() + _x_left()) / (_x_right() - _x_left());
    }

    constexpr inline T _m31(void) const noexcept {
	return -(_y_top() + _y_bottom()) / (_y_top() - _y_bottom());
    }

    constexpr inline T _m32(void) const noexcept {
	return -(_z_far() + _z_near()) / (_z_far() - _z_near());
    }

    constexpr inline matrix<T, 4, 4, true, V> _make(std::true_type) const
      noexcept {
	return matrix<T, 4, 4, true, V>{{{_m00(), T(0), T(0), _m30()},
	  {T(0), _m11(), T(0), _m31()},
	  {T(0), T(0), _m22(), _m32()},
	  {T(0), T(0), T(0), T(1)}}};
    }

    constexpr inline matrix<T, 4, 4, false, V> _make(std::false_type) const
      noexcept {
	return matrix<T, 4, 4, false, V>{{{_m00(), T(0), T(0), T(0)},
	  {T(0), _m11(), T(0), T(0)},
	  {T(0), T(0), _m22(), T(0)},
	  {_m30(), _m31(), _m32(), T(1)}}};
    }

    constexpr inline matrix<T, 4, 4, RM, V> operator()(void) const noexcept {
	return _make(bool_constant<RM>());
    }
};

// reorder_mat_ctr(ortho)
template <typename T, int N, bool RM, bool V>
static constexpr inline ortho<matrix<T, N, N, !RM, V>>
reorder_mat_ctr(const ortho<matrix<T, N, N, RM, V>>& c) noexcept {
    return {c._v};
}

// matrix_*
template <typename T, bool V>
using matrix_ortho =
  convertible_matrix_constructor<ortho<matrix<T, 4, 4, true, V>>>;

} // namespace math
} // namespace eagine

#endif // include guard
