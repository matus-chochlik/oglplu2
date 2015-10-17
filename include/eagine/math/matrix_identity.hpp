/**
 *  @file eagine/math/matrix_identity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_IDENTITY_1509260923_HPP
#define EAGINE_MATH_MATRIX_IDENTITY_1509260923_HPP

#include "matrix_ctr.hpp"

namespace eagine {
namespace math {

// identity
template <typename X>
struct identity;

// is_matrix_constructor<identity>
template <typename T, unsigned R, unsigned C, bool RM, bool V>
struct is_matrix_constructor<identity<matrix<T,R,C,RM,V>>>
 : std::true_type
{ };

// identity Matrix
template <typename T, unsigned R, unsigned C, bool RM, bool V>
struct identity<matrix<T,R,C,RM,V>>
{
	template <unsigned ... U>
	using _useq = integer_sequence<unsigned, U...>;

	template <unsigned N>
	using _make_useq = make_integer_sequence<unsigned, N>;

	template <unsigned ... I>
	static constexpr inline
	matrix<T,R,C,RM,V>
	_identity(_useq<I...>)
	noexcept
	{
		return {{vect::axis<T, RM?C:R, I, V>::apply(1)...}};
	}

	constexpr inline
	matrix<T,R,C,RM,V> operator()(void) const
	noexcept
	{
		typedef typename _make_useq<RM?R:C>::type _riS;
		return _identity(_riS());
	}
};

// multiply
template <
	typename MC,
	typename T, unsigned C, unsigned R, bool RM, bool V,
	typename = typename std::enable_if<
		is_matrix_constructor<MC>::value &&
		are_multiplicable<
			constructed_matrix_t<MC>,
			matrix<T,C,R,RM,V>
		>::value
	>::type
>
static constexpr inline
MC multiply(
	const MC& mc,
	const identity<matrix<T,C,R,RM,V>>&
) noexcept
{
	return mc;
}

template <
	typename T, unsigned C, unsigned R, bool RM, bool V,
	typename MC,
	typename = typename std::enable_if<
		is_matrix_constructor<MC>::value &&
		are_multiplicable<
			matrix<T,C,R,RM,V>,
			constructed_matrix_t<MC>
		>::value
	>::type
>
static constexpr inline
MC multiply(
	const identity<matrix<T,C,R,RM,V>>&,
	const MC& mc
) noexcept
{
	return mc;
}

// reorder_mat_ctr(identity)
template <typename T, unsigned R, unsigned C, bool RM, bool V>
static constexpr inline
identity<matrix<T,R,C,!RM,V>>
reorder_mat_ctr(const identity<matrix<T,R,C,RM,V>>&)
noexcept
{ return {}; }

} // namespace math
} // namespace eagine

#endif //include guard

