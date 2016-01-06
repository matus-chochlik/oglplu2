/**
 *  @file eagine/math/matrix_reflection.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_REFLECTION_1509260923_HPP
#define EAGINE_MATH_MATRIX_REFLECTION_1509260923_HPP

#include "matrix_ctr.hpp"
#include <cmath>

namespace eagine {
namespace math {

// reflection_I
template <typename X, unsigned I>
struct reflection_I;

// is_matrix_constructor<reflection_I>
template <typename T, unsigned N, bool RM, bool V, unsigned I>
struct is_matrix_constructor<reflection_I<matrix<T,N,N,RM,V>, I>>
 : std::true_type
{ };

// scale matrix 4x4 row-major
template <typename T, bool RM, bool V, unsigned I>
struct reflection_I<matrix<T,4,4,RM,V>, I>
{
	T _v;

	constexpr
	reflection_I(bool r = true)
	noexcept
	 : _v(r?T(-1):T(1))
	{ }

	constexpr inline
	T v(unsigned i) const
	noexcept
	{
		return (I == i)?_v:T(1);
	}

	constexpr inline
	matrix<T,4,4,RM,V> operator()(void) const
	noexcept
	{
		return matrix<T,4,4,RM,V>{{
			{v(0),T(0),T(0),T(0)},
			{T(0),v(1),T(0),T(0)},
			{T(0),T(0),v(2),T(0)},
			{T(0),T(0),T(0),T(1)}
		}};
	}
};

// multiply
template <typename T, unsigned N, bool RM1, bool RM2, bool V, unsigned I>
static constexpr inline
reflection_I<matrix<T,N,N,RM1,V>, I>
multiply(
	const reflection_I<matrix<T,N,N,RM1,V>, I>& a,
	const reflection_I<matrix<T,N,N,RM2,V>, I>& b
) noexcept
{
	return {(a._v < b._v) || (a._v > b._v)};
}

// reorder_mat_ctr(reflection_I)
template <typename T, unsigned N, bool RM, bool V, unsigned I>
static constexpr inline
reflection_I<matrix<T,N,N,!RM,V>, I>
reorder_mat_ctr(const reflection_I<matrix<T,N,N,RM,V>, I>& c)
noexcept
{
	return {c._v<T(0)};
}

// reflection x
template <typename M>
using reflection_x = reflection_I<M, 0>;

// reflection y
template <typename M>
using reflection_y = reflection_I<M, 1>;

// reflection z
template <typename M>
using reflection_z = reflection_I<M, 2>;

// matrix_*
template <typename T, bool V>
using matrix_reflection_x =
	convertible_matrix_constructor<reflection_x<matrix<T,4,4,true,V>>>;

template <typename T, bool V>
using matrix_reflection_y =
	convertible_matrix_constructor<reflection_y<matrix<T,4,4,true,V>>>;

template <typename T, bool V>
using matrix_reflection_z =
	convertible_matrix_constructor<reflection_z<matrix<T,4,4,true,V>>>;

} // namespace math
} // namespace eagine

#endif //include guard

