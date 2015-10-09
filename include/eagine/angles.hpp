/**
 *  @file eagine/angles.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ANGLES_1509260923_HPP
#define EAGINE_ANGLES_1509260923_HPP

#include <type_traits>

namespace eagine {

template <typename T>
struct degrees_t
{
	static_assert(std::is_arithmetic<T>::value, "");

	T _v;

	explicit constexpr inline
	degrees_t(T v)
	noexcept
	 : _v(v)
	{ }

	template <
		typename U,
		typename = typename std::is_convertible<U, T>::type
	>
	constexpr inline
	degrees_t(degrees_t<U> d)
	noexcept
	 : _v(T(d._v))
	{ }

	explicit constexpr inline
	operator T (void) const
	noexcept
	{
		return _v;
	}
};

template <typename T>
static inline
degrees_t<T>
degrees(T value)
noexcept
{
	return degrees_t<T>{value};
}

} // namespace eagine

#endif // include guard
