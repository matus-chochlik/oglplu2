/**
 *  @file eagine/math/functions.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_FUNCTIONS_1509260923_HPP
#define EAGINE_MATH_FUNCTIONS_1509260923_HPP

#include <cassert>

namespace eagine {
namespace math {

static constexpr inline
int factorial(int n)
noexcept
{
	return n > 0? n * factorial(n-1) : 1;
}

static constexpr inline
int binomial(int n, int k)
noexcept
{
	return factorial(n) / (factorial(n-k) * factorial(k));
}


} // namespace math
} // namespace eagine

#endif //include guard

