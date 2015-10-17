/**
 *  @file eagine/math/vector.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_VECTOR_1509260923_HPP
#define EAGINE_MATH_VECTOR_1509260923_HPP

#include "scalar.hpp"
#include "../vect/axis.hpp"
#include "../vect/cast.hpp"
#include "../vect/from.hpp"
#include "../vect/view.hpp"
#include "../vec_mat_traits.hpp"
#include <utility>
#include <cassert>

namespace eagine {
namespace math {

template <typename T, unsigned N, bool V>
struct vector
{
	typedef vector type;

	typedef T value_type;

	typedef vect::has_vect_data_t<T, N, V> is_vectorized;

	typedef vect::data_t<T, N, V> data_type;

	data_type _v;

	static inline
	vector zero(void)
	noexcept
	{
		return vector{vect::fill<T,N,V>::apply(T(0))};
	}

	static inline
	vector fill(T v)
	noexcept
	{
		return vector{vect::fill<T,N,V>::apply(v)};
	}

	template <unsigned I>
	static inline
	vector axis(void)
	noexcept
	{
		return vector{vect::axis<T,N,I,V>::apply(T(1))};
	}

	template <unsigned I>
	static inline
	vector axis(T v)
	noexcept
	{
		return vector{vect::axis<T,N,I,V>::apply(v)};
	}

	static inline
	vector axis(unsigned i, T v)
	noexcept
	{
		assert(i < N);
		vector r = zero();
		r._v[i] = v;
		return r;
	}

	template <
		typename P,
		typename = typename std::enable_if<
			(N == 1) && (std::is_convertible<P, T>::value)
		>::type
	>
	static constexpr inline
	vector make(P&& p)
	noexcept
	{
		return vector{{T(std::forward<P>(p))}};
	}

	template <
		typename ... P,
		typename = typename std::enable_if<
			(N > 1) && (sizeof...(P) == N)
		>::type
	>
	static constexpr inline
	vector make(P&& ... p)
	noexcept
	{
		return vector{{T(std::forward<P>(p))...}};
	}

	template <
		typename P,
		unsigned M,
		bool W,
		typename = typename std::enable_if<
			(!std::is_same<T, P>::value || (N != M) || (V != W))
		>::type
	>
	static constexpr inline
	vector from(const vector<P, M, W>& v, T d = T(0))
	noexcept
	{
		return vector{vect::cast<P, M, W, T, N, V>::apply(v._v, d)};
	}

	template <typename P, unsigned M, bool W>
	static constexpr inline
	vector from(const vector<P, M, W>& v, const vector<T, N-M, W>& u)
	noexcept
	{
		return vector{vect::cast<P, M, W, T, N, V>::apply(v._v, u._v)};
	}

	static inline
	vector from(const T* dt, std::size_t sz)
	noexcept
	{
		return vector{vect::from_array<T,N,V>::apply(dt, sz)};
	}

	static inline
	vector from(const T* dt, std::size_t sz, T fv)
	noexcept
	{
		return vector{vect::from_saafv<T,N,V>::apply(dt, sz, fv)};
	}

	static constexpr inline
	unsigned dimension(void)
	noexcept
	{
		return N;
	}

	constexpr inline
	T operator [] (unsigned pos) const
	noexcept
	{
		return _v[pos];
	}

	template <unsigned M = N>
	constexpr inline
	typename std::enable_if<(M > 0), T>::type x(void) const
	noexcept
	{
		static_assert(M == N, "");
		return _v[0];
	}

	template <unsigned M = N>
	constexpr inline
	typename std::enable_if<(M > 1), T>::type y(void) const
	noexcept
	{
		static_assert(M == N, "");
		return _v[1];
	}

	template <unsigned M = N>
	constexpr inline
	typename std::enable_if<(M > 2), T>::type z(void) const
	noexcept
	{
		static_assert(M == N, "");
		return _v[2];
	}

	template <unsigned M = N>
	constexpr inline
	typename std::enable_if<(M > 3), T>::type w(void) const
	noexcept
	{
		static_assert(M == N, "");
		return _v[3];
	}
};

} // namespace math

template <typename T, unsigned N, bool V>
struct is_known_vector_type<math::vector<T, N, V>>
 : std::is_scalar<T>
{ };

template <typename T, unsigned N, bool V>
struct canonical_compound_type<math::vector<T, N, V>>
 : identity<typename std::remove_cv<T[N]>::type>
{ };

template <typename T, unsigned N, bool V>
static inline
auto element_view(const math::vector<T, N, V>& v)
noexcept
{
	return eagine::vect::view<T, N, V>::apply(v._v);
}


} // namespace eagine

#endif //include guard

