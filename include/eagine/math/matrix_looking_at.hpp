/**
 *  @file eagine/math/matrix_looking_at.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_LOOKING_AT_1509260923_HPP
#define EAGINE_MATH_MATRIX_LOOKING_AT_1509260923_HPP

#include "../quantities.hpp"
#include "matrix_ctr.hpp"

namespace eagine {
namespace math {

// looking_at_y_up
template <typename X>
struct looking_at_y_up;

// is_matrix_constructor<looking_at_y_up>
template <typename T, int N, bool RM, bool V>
struct is_matrix_constructor<looking_at_y_up<matrix<T, N, N, RM, V>>>
  : std::true_type {};

// looking_at_y_up matrix 4x4
template <typename T, bool RM, bool V>
struct looking_at_y_up<matrix<T, 4, 4, RM, V>> {
    typedef vector<T, 3, V> _dT;

    vector<T, 3, V> _e, _t;

    constexpr looking_at_y_up(
      const vector<T, 3, V>& eye, const vector<T, 3, V>& target) noexcept
      : _e(eye)
      , _t(target) {
    }

    static constexpr inline matrix<T, 4, 4, true, V> _make(
      const _dT& x, const _dT& y, const _dT& z, const _dT& t) noexcept {
	return matrix<T, 4, 4, true, V>{{{x[0], x[1], x[2], -dot(x, t)},
	  {y[0], y[1], y[2], -dot(y, t)},
	  {z[0], z[1], z[2], -dot(z, t)},
	  {T(0), T(0), T(0), T(1)}}};
    }

    static constexpr inline matrix<T, 4, 4, true, V> _make(
      const _dT& y, const _dT& z, const _dT& t) noexcept {
	return _make(cross(y, z), y, z, t);
    }

    static constexpr inline matrix<T, 4, 4, true, V> _make(
      const _dT& z, const _dT& t) noexcept {
	return _make(normalized(cross(z, t)), z, t);
    }

    static constexpr inline matrix<T, 4, 4, true, V> _make(
      const _dT& z) noexcept {
	return _make(z, _dT::make(z.z(), T(0), -z.x()));
    }

    constexpr inline matrix<T, 4, 4, true, V> _make(std::true_type) const
      noexcept {
	return _make(normalized(_e - _t));
    }

    constexpr inline matrix<T, 4, 4, false, V> _make(std::false_type) const
      noexcept {
	return reorder(_make(std::true_type()));
    }

    constexpr inline matrix<T, 4, 4, RM, V> operator()(void) const noexcept {
	return _make(bool_constant<RM>());
    }
};

// reorder_mat_ctr(looking_at_y_up)
template <typename T, int N, bool RM, bool V>
static constexpr inline looking_at_y_up<matrix<T, N, N, !RM, V>>
reorder_mat_ctr(const looking_at_y_up<matrix<T, N, N, RM, V>>& c) noexcept {
    return {c._e, c._t};
}

// matrix_*
template <typename T, bool V>
using matrix_looking_at_y_up =
  convertible_matrix_constructor<looking_at_y_up<matrix<T, 4, 4, true, V>>>;

} // namespace math
} // namespace eagine

#endif // include guard
