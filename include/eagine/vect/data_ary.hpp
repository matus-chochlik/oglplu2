/**
 *  @file eagine/vect/data_ary.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VECT_DATA_ARY_1509260923_HPP
#define EAGINE_VECT_DATA_ARY_1509260923_HPP

#include "config.hpp"
#include "fwd.hpp"
#include <utility>
#include <cstdint>

namespace eagine {
namespace vect {

template <typename T, unsigned N>
struct _ary_data
{
	T _v[N];

	typedef _ary_data type;

	_ary_data(void) = default;
	_ary_data(const _ary_data& that) = default;
	_ary_data& operator = (const _ary_data& that) = default;

	template <
		typename ... P,
		typename = typename std::enable_if<
			(N > 1) && (sizeof...(P) == N)
		>::type
	>
	constexpr
	_ary_data(P&& ... p)
	 : _v{T(std::forward<P>(p))...}
	{ }

	template <
		typename P,
		typename = typename std::enable_if<
			(N == 1) && (std::is_convertible<P, T>::value)
		>::type
	>
	constexpr
	_ary_data(P&& p)
	 : _v{T(std::forward<P>(p))}
	{ }

	constexpr inline
	T operator [] (unsigned i) const
	noexcept
	{
		return _v[i];
	}

	inline
	T& operator [] (unsigned i)
	noexcept
	{
		return _v[i];
	}

	friend constexpr inline
	_ary_data operator + (_ary_data a)
	noexcept
	{
		return a;
	}

	friend
	_ary_data operator - (_ary_data a)
	noexcept
	{
		for(unsigned i=0; i<N; ++i)
		{
			a._v[i] = -a._v[i];
		}
		return a;
	}

	friend
	_ary_data operator + (const _ary_data& a, const _ary_data& b)
	noexcept
	{
		_ary_data c;
		for(unsigned i=0; i<N; ++i)
		{
			c._v[i] = a._v[i] + b._v[i];
		}
		return c;
	}

	friend
	_ary_data operator - (const _ary_data& a, const _ary_data& b)
	noexcept
	{
		_ary_data c;
		for(unsigned i=0; i<N; ++i)
		{
			c._v[i] = a._v[i] - b._v[i];
		}
		return c;
	}

	friend
	_ary_data operator * (const _ary_data& a, const _ary_data& b)
	noexcept
	{
		_ary_data c;
		for(unsigned i=0; i<N; ++i)
		{
			c._v[i] = a._v[i] * b._v[i];
		}
		return c;
	}

	friend
	_ary_data operator / (const _ary_data& a, const _ary_data& b)
	noexcept
	{
		_ary_data c;
		for(unsigned i=0; i<N; ++i)
		{
			c._v[i] = a._v[i] / b._v[i];
		}
		return c;
	}
};

template <typename T, unsigned N>
struct _ary_cref
{
	typedef const _ary_data<T, N>& type;
};

template <typename T>
struct _ary_data<T, 0u>
{
	typedef _ary_data type;

	T operator [] (unsigned i) const;
};

} // namespace vect
} // namespace eagine

#endif //include guard

