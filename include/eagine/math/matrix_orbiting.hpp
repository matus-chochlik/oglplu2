/**
 *  @file eagine/math/matrix_orbiting.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_ORBITING_1509260923_HPP
#define EAGINE_MATH_MATRIX_ORBITING_1509260923_HPP

#include "matrix_ctr.hpp"
#include "../quantities.hpp"

namespace eagine {
namespace math {

// orbiting_y_up
template <typename X>
struct orbiting_y_up;

// is_matrix_constructor<orbiting_y_up>
template <typename T, int N, bool RM, bool V>
struct is_matrix_constructor<orbiting_y_up<matrix<T,N,N,RM,V>>>
 : std::true_type
{ };

// orbiting_y_up matrix 4x4
template <typename T, bool RM, bool V>
struct orbiting_y_up<matrix<T,4,4,RM,V>>
{
	vector<T,3,V> _t;
	vector<T,3,V> _x, _z, _y;
	T _r;

	constexpr
	orbiting_y_up(
		const vector<T,3,V>& t,
		const vector<T,3,V>& x,
		const vector<T,3,V>& y,
		const vector<T,3,V>& z,
		T r
	) noexcept
	 : _t(t)
	 , _x(x)
	 , _z(z)
	 , _y(y)
	 , _r(r)
	{ }

	constexpr orbiting_y_up(
		const vector<T, 3, V>& t,
		const T rs,
		const T sa,
		const T ca,
		const T se,
		const T ce
	) noexcept
	 : _t(t)
	 , _x{{-sa, T(0), -ca}}
	 , _z{{ce*ca, se, ce*-sa}}
	 , _y(cross(_z, _x))
	 , _r(rs)
	{ }

	constexpr orbiting_y_up(
		const vector<T, 3, V>& target,
		const T radius,
		radians_t<T> azimuth,
		radians_t<T> elevation
	)
	 : orbiting_y_up(
		target,
		radius,
		sin(azimuth),
		cos(azimuth),
		sin(elevation),
		cos(elevation)
	){ }

	constexpr inline
	matrix<T,4,4,true,V> _make(std::true_type) const
	noexcept
	{
		return matrix<T,4,4, true,V>{{
			{_x[0],_x[1],_x[2],-_r*dot(_x,_z) - dot(_x,_t)},
			{_y[0],_y[1],_y[2],-_r*dot(_y,_z) - dot(_y,_t)},
			{_z[0],_z[1],_z[2],-_r*dot(_z,_z) - dot(_z,_t)},
			{T(0), T(0), T(0), T(1)}
		}};
	}

	constexpr inline
	matrix<T,4,4,false,V> _make(std::false_type) const
	noexcept
	{
		return reorder(_make(std::true_type()));
	}

	constexpr inline
	matrix<T,4,4,RM,V> operator()(void) const
	noexcept
	{
		return _make(bool_constant<RM>());
	}
};

// reorder_mat_ctr(orbiting_y_up)
template <typename T, int N, bool RM, bool V>
static constexpr inline
orbiting_y_up<matrix<T,N,N,!RM,V>>
reorder_mat_ctr(const orbiting_y_up<matrix<T,N,N,RM,V>>& c)
noexcept
{
	return {c._t,c._x,c._y,c._z,c._r};
}

// matrix_*
template <typename T, bool V>
using matrix_orbiting_y_up =
	convertible_matrix_constructor<orbiting_y_up<matrix<T,4,4,true,V>>>;

} // namespace math
} // namespace eagine

#endif //include guard

