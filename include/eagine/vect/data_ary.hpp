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

#include "../type_traits.hpp"
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
		typename P,
		typename = std::enable_if_t<
			(N == 1) && (std::is_convertible<P, T>::value)
		>
	>
	constexpr
	_ary_data(P&& p)
	 : _v{T(std::forward<P>(p))}
	{ }

	template <
		typename P1,
		typename P2,
		typename ... Pn,
		typename = std::enable_if_t<(sizeof...(Pn)+2) == N>
	>
	constexpr
	_ary_data(P1&& p1, P2&& p2, Pn&& ... pn)
	 : _v{
		T(std::forward<P1>(p1)),
		T(std::forward<P2>(p2)),
		T(std::forward<Pn>(pn))...
	}
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

