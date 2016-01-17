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
#include "../all_are_same.hpp"

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
		typename = std::enable_if_t<
			(sizeof...(P) == N) &&
			all_are_convertible_to<T, P...>::value
		>
	>
	constexpr inline
	tvec(P&& ... p)
	noexcept
	 : _base(_base::make(std::forward<P>(p)...))
	{ }

	template <
		typename P,
		unsigned M,
		bool W,
		typename = std::enable_if_t<
			!std::is_same<P, T>::value ||
			!(M == N)
		>
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
		typename = std::enable_if_t<
			(sizeof...(R) > 1) &&
			(M+sizeof...(R) == N) &&
			all_are_convertible_to<T, R...>::value
		>
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
 : identity<std::remove_cv_t<T[N]>>
{ };

template <typename T, unsigned N, bool V>
struct compound_view_maker<math::tvec<T, N, V>>
{
	inline
	auto operator()(const math::vector<T, N, V>& v) const
	noexcept
	{
		return vect::view<T, N, V>::apply(v._v);
	}
};

} // namespace eagine

#endif //include guard

