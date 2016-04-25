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

#include "../type_traits.hpp"
#include <cassert>
#include <cmath>

namespace eagine {
namespace math {

template <typename T>
static constexpr inline
T minimum(T a, T b)
noexcept
{
	return a < b ? a : b;
}

template <typename T, typename ... P>
static constexpr inline
T minimum(T a, T b, T c, P ... d)
noexcept
{
	return minimum(minimum(a, b), c, d...);
}

template <typename T>
static constexpr inline
T maximum(T a, T b)
noexcept
{
	return a > b ? a : b;
}

template <typename T, typename ... P>
static constexpr inline
T maximum(T a, T b, T c, P ... d)
noexcept
{
	return maximum(maximum(a, b), c, d...);
}

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
	return ((n >= 0) && (k >= 0) && (k <= n))?
		(factorial(n) / (factorial(k) * factorial(n-k))):0;
}

template <typename T, int N>
struct bezier_t
{
private:
	static constexpr
	T _coef(int m, int i, T t)
	noexcept
	{
		using std::pow;
		return T(binomial(m, i)*pow(t, i)*pow(1-t, m-i));
	}

	static constexpr
	T _calc(int, int, T)
	noexcept
	{
		return 0;
	}

	template <typename ... P>
	static constexpr
	T _calc(int m, int i, T t, T f, P ... r)
	noexcept
	{
		return f * _coef(m, i, t) + _calc(m, i+1, t, r...);
	}
public:
	template <
		typename ... P,
		typename = std::enable_if_t<sizeof ... (P) == N>
	>
	constexpr inline
	T operator () (T t, P ... p)
	noexcept
	{
		return _calc(N-1, 0, t, p ...);
	}
};

template <typename T, typename ... P>
static constexpr inline
T bezier(T t, P ... p)
noexcept
{
	return bezier_t<T, sizeof ... (P)>()(t, p...);
}

} // namespace math
} // namespace eagine

#endif //include guard

