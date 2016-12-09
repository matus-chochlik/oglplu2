/**
 *  @file eagine/vect/from.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_FROM_1509260923_HPP
#define EAGINE_VECT_FROM_1509260923_HPP

#include "data.hpp"
#include <cassert>

namespace eagine {
namespace vect {

template <typename T, unsigned N, bool V>
struct from_array
{
	static
	data_t<T, N, V>
	apply(const T* d, span_size_t n)
	noexcept
	{
		assert(N <= unsigned(n));
		data_t<T, N, V> r;
		for(unsigned i=0; i<N; ++i)
		{
			r[i] = d[i];
		}
		return r;
	}
};

#if EAGINE_VECT_OPTS

template <typename T, bool V>
struct from_array<T, 0, V>
{
	static constexpr
	data_t<T, 0, V>
	apply(const T*, unsigned)
	noexcept
	{
		return {};
	}
};

template <typename T, bool V>
struct from_array<T, 1, V>
{
	static
	data_t<T, 1, V>
	apply(const T* d, span_size_t n)
	noexcept
	{
		assert(1 <= n);
		return data_t<T, 1, V>
			{d[0]};
	}
};

template <typename T, bool V>
struct from_array<T, 2, V>
{
	static
	data_t<T, 2, V>
	apply(const T* d, span_size_t n)
	noexcept
	{
		assert(2 <= n);
		return data_t<T, 2, V>
			{d[0], d[1]};
	}
};

template <typename T, bool V>
struct from_array<T, 3, V>
{
	static
	data_t<T, 3, V>
	apply(const T* d, span_size_t n)
	noexcept
	{
		assert(3 <= n);
		return data_t<T, 3, V>
			{d[0], d[1], d[2]};
	}
};

template <typename T, bool V>
struct from_array<T, 4, V>
{
	static
	data_t<T, 4, V>
	apply(const T* d, span_size_t n)
	noexcept
	{
		assert(4 <= n);
		return data_t<T, 4, V>
			{d[0], d[1], d[2], d[3]};
	}
};

template <typename T, bool V>
struct from_array<T, 8, V>
{
	static
	data_t<T, 8, V>
	apply(const T* d, span_size_t n)
	noexcept
	{
		assert(8 <= n);
		return data_t<T, 8, V>
			{d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]};
	}
};

#endif

// from shorter array and fallback value
template <typename T, unsigned N, bool V>
struct from_saafv
{
	static
	data_t<T, N, V>
	apply(const T* d, span_size_t n, T v)
	noexcept
	{
		data_t<T, N, V> r = {};
		for(unsigned i=0; i<N && i<unsigned(n); ++i)
		{
			r[i] = d[i];
		}
		for(unsigned i=unsigned(n); i<N; ++i)
		{
			r[i] = v;
		}
		return r;
	}
};

} // namespace vect
} // namespace eagine

#endif //include guard

