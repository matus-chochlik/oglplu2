/**
 *  @file eagine/math/tvec.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_TVEC_1509260923_HPP
#define EAGINE_MATH_TVEC_1509260923_HPP

#include "vector.hpp"

namespace eagine {
namespace math {

// tvec
template <typename T, unsigned N, bool V>
struct tvec : vector<T, N, V>
{
	typedef vector<T, N, V> _base;

	constexpr inline
	tvec(void)
	noexcept
	 : _base(_base::zero())
	{ }

	constexpr inline
	tvec(T v)
	noexcept
	 : _base(_base::fill(v))
	{ }

	constexpr inline
	tvec(const _base& v)
	noexcept
	 : _base(v)
	{ }

	inline
	tvec(const T (&d)[N])
	noexcept
	 : _base(_base::from(d, N))
	{ }

	template <
		typename ... P,
		typename = typename std::enable_if<
			(1+sizeof...(P) == N)
		>::type
	>
	constexpr inline
	tvec(T v, P&& ... p)
	noexcept
	 : _base(_base::make(v, std::forward<P>(p)...))
	{ }

	template <
		typename P,
		unsigned M,
		bool W,
		typename = typename std::enable_if<
			!std::is_same<P, T>::value ||
			!(M == N)
		>::type
	>
	constexpr inline
	tvec(const vector<P, M, W>& v)
	noexcept
	 : _base(_base::from(v))
	{ }

	template <typename P, unsigned M, bool W>
	constexpr inline
	tvec(const vector<P, M, W>& v, T d)
	noexcept
	 : _base(_base::from(v, d))
	{ }

	template <
		typename P,
		unsigned M,
		bool W,
		typename ... R,
		typename = typename std::enable_if<
			(sizeof...(R) > 1) && (M+sizeof...(R) == N)
		>::type
	>
	constexpr inline
	tvec(const vector<P, M, W>& v, R&& ... r)
	noexcept
	 : _base(_base::from(
		v,
		vector<T, N-M, W>::make(std::forward<R>(r)...)
	))
	{ }

	template <typename P, unsigned M, bool W>
	constexpr inline
	tvec(const vector<P, M, W>& v, const vector<T, N-M, W>& w)
	noexcept
	 : _base(_base::from(v, w))
	{ }
};

} // namespace math

template <typename T, unsigned N, bool V>
struct is_known_vector_type<math::tvec<T, N, V>>
 : std::is_scalar<T>
{ };

template <typename T, unsigned N, bool V>
struct canonical_compound_type<math::tvec<T, N, V>>
 : identity<typename std::remove_cv<T[N]>::type>
{ };

} // namespace eagine

#endif //include guard

