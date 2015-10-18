/**
 *  @file eagine/math/matrix_ctr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_CTR_1509260923_HPP
#define EAGINE_MATH_MATRIX_CTR_1509260923_HPP

#include "matrix.hpp"
#include "../nothing.hpp"

namespace eagine {
namespace math {

template <
	template <class> class MC,
	typename T, unsigned C, unsigned R, bool RM, bool V
>
struct constructed_matrix<MC<matrix<T,C,R,RM,V>>>
 : std::conditional<
	is_matrix_constructor<MC<matrix<T,C,R,RM,V>>>::value,
	matrix<T,C,R,RM,V>,
	nothing_t
>::type
{ };

template <
	template <class, unsigned> class MC,
	typename T, unsigned C, unsigned R, bool RM, bool V,
	unsigned I
>
struct constructed_matrix<MC<matrix<T,C,R,RM,V>, I>>
 : std::conditional<
	is_matrix_constructor<MC<matrix<T,C,R,RM,V>, I>>::value,
	matrix<T,C,R,RM,V>,
	nothing_t
>::type
{ };

// construct_matrix (noop)
template <bool RM, typename MC>
static constexpr inline
typename std::enable_if<
	is_matrix_constructor<MC>::value &&
	is_row_major<constructed_matrix_t<MC>>::value == RM,
	constructed_matrix_t<MC>
>::type construct_matrix(const MC& c)
noexcept
{
	return c();
}

// construct_matrix (reorder)
template <bool RM, typename MC>
static constexpr inline
typename std::enable_if<
	is_matrix_constructor<MC>::value &&
	is_row_major<constructed_matrix_t<MC>>::value != RM,
	reordered_matrix_t<constructed_matrix_t<MC>>
>::type construct_matrix(const MC& c)
noexcept
{
	return reorder_mat_ctr(c)();
}

template <
	typename MC1,
	typename MC2,
	typename = typename std::enable_if<
		is_matrix_constructor<MC1>::value &&
		is_matrix_constructor<MC2>::value &&
		are_multiplicable<
			constructed_matrix_t<MC1>,
			constructed_matrix_t<MC2>
		>::value
>::type
>
static inline
auto multiply(const MC1& mc1, const MC2& mc2)
noexcept
{
	return multiply(
		construct_matrix< true>(mc1),
		construct_matrix<false>(mc2)
	);
}

} // namespace math
} // namespace eagine

#endif //include guard

