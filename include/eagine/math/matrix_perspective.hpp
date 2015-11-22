/**
 *  @file eagine/math/matrix_perspective.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_PERSPECTIVE_1509260923_HPP
#define EAGINE_MATH_MATRIX_PERSPECTIVE_1509260923_HPP

#include "matrix_ctr.hpp"

namespace eagine {
namespace math {

// perspective
template <typename X>
struct perspective;

// is_matrix_constructor<perspective>
template <typename T, unsigned N, bool RM, bool V>
struct is_matrix_constructor<perspective<matrix<T,N,N,RM,V>>>
 : std::true_type
{ };

// perspective matrix 4x4
template <typename T, bool RM, bool V>
struct perspective<matrix<T,4,4,RM,V>>
{
	typedef vect::data_t<T, 6, V> _dT;
	_dT _v;

	constexpr
	perspective(const _dT& v)
	noexcept
	 : _v(v)
	{ }

	constexpr
	perspective(
		T x_left,
		T x_right,
		T y_bottom,
		T y_top,
		T z_near,
		T z_far
	) noexcept
	 : _v{x_left, x_right, y_bottom, y_top, z_near, z_far}
	{ }

	constexpr inline
	T _x_left(void) const
	noexcept
	{ return _v[0]; }

	constexpr inline
	T _x_right(void) const
	noexcept
	{ return _v[1]; }

	constexpr inline
	T _y_bottom(void) const
	noexcept
	{ return _v[2]; }

	constexpr inline
	T _y_top(void) const
	noexcept
	{ return _v[3]; }

	constexpr inline
	T _z_near(void) const
	noexcept
	{ return _v[4]; }

	constexpr inline
	T _z_far(void) const
	noexcept
	{ return _v[5]; }

	static inline
	perspective x(
		radians_t<T> xfov,
		T aspect,
		T z_near,
		T z_far
	) noexcept
	{
		assert(aspect > T(0));
		assert(T(xfov) > T(0));

		T x_right = z_near * tan(xfov * T(0.5));
		T x_left = -x_right;

		T y_bottom = x_left / aspect;
		T y_top = x_right / aspect;

		return perspective(
			x_left,
			x_right,
			y_bottom,
			y_top,
			z_near,
			z_far
		);
	}

	static inline
	perspective y(
		radians_t<T> yfov,
		T aspect,
		T z_near,
		T z_far
	) noexcept
	{
		assert(aspect > T(0));
		assert(T(yfov) > T(0));

		T y_top = z_near * tan(yfov * T(0.5));
		T y_bottom = -y_top;

		T x_left = y_bottom * aspect;
		T x_right = y_top * aspect;

		return perspective(
			x_left,
			x_right,
			y_bottom,
			y_top,
			z_near,
			z_far
		);
	}

	constexpr inline
	T _m00(void) const
	noexcept
	{
		return (T(2) * _z_near()) / (_x_right() - _x_left());
	}

	constexpr inline
	T _m11(void) const
	noexcept
	{
		return (T(2) * _z_near()) / (_y_top() - _y_bottom());
	}

	constexpr inline
	T _m22(void) const
	noexcept
	{
		return -(_z_far() + _z_near()) / (_z_far() - _z_near());
	}

	constexpr inline
	T _m20(void) const
	noexcept
	{
		return (_x_right() + _x_left()) / (_x_right() - _x_left());
	}

	constexpr inline
	T _m21(void) const
	noexcept
	{
		return (_y_top() + _y_bottom()) / (_y_top() - _y_bottom());
	}

	constexpr inline
	T _m23(void) const
	noexcept
	{
		return -T(1);
	}

	constexpr inline
	T _m32(void) const
	noexcept
	{
		return -(T(2) * _z_far() * _z_near()) / (_z_far() - _z_near());
	}

	constexpr inline
	matrix<T,4,4, true,V> _make(std::true_type) const
	noexcept
	{
		return matrix<T,4,4, true,V>{{
			{_m00(),   T(0), _m20(),   T(0)},
			{  T(0), _m11(), _m21(),   T(0)},
			{  T(0),   T(0), _m22(), _m32()},
			{  T(0),   T(0), _m23(),   T(0)}
		}};
	}

	constexpr inline
	matrix<T,4,4,false,V> _make(std::false_type) const
	noexcept
	{
		return matrix<T,4,4,false,V>{{
			{_m00(),   T(0),   T(0),   T(0)},
			{  T(0), _m11(),   T(0),   T(0)},
			{_m20(), _m21(), _m22(), _m23()},
			{  T(0),   T(0), _m32(),   T(0)}
		}};
	}

	constexpr inline
	matrix<T,4,4,RM,V> operator()(void) const
	noexcept
	{
		return _make(std::integral_constant<bool, RM>());
	}

};

// reorder_mat_ctr(perspective)
template <typename T, unsigned N, bool RM, bool V>
static constexpr inline
perspective<matrix<T,N,N,!RM,V>>
reorder_mat_ctr(const perspective<matrix<T,N,N,RM,V>>& c)
noexcept
{
	return {c._v};
}

// matrix_*
template <typename T, bool V>
using matrix_perspective =
	convertible_matrix_constructor<perspective<matrix<T,4,4,true,V>>>;

} // namespace math
} // namespace eagine

#endif //include guard

