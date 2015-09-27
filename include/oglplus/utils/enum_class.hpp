/**
 *  @file oglplus/utils/enums.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_ENUMS_1509260923_HPP
#define OGLPLUS_UTILS_ENUMS_1509260923_HPP

#include "mp_list.hpp"

namespace oglplus {

template <typename T, T Value, typename ClassList>
struct enum_value;

template <typename T, T Value, typename ... Classes>
struct enum_value<T, Value, mp_list<Classes...>>
{ };

template <typename Self, typename T>
struct enum_class
{
	T _value;

	enum_class(void) = default;

	template <
		T Value,
		typename Classes,
		typename = typename std::enable_if<mp_contains<Classes,Self>::value>::type
	>
	constexpr inline
	enum_class(enum_value<T, Value, Classes>)
	noexcept
	 : _value(Value)
	{ }

	explicit constexpr inline
	enum_class(T value)
	noexcept
	 : _value(value)
	{ }

	explicit constexpr inline
	operator T (void) const
	noexcept
	{
		return _value;
	}

	friend inline
	bool operator == (enum_class a, enum_class b)
	noexcept
	{
		return a._value == b._value;
	}

	friend inline
	bool operator != (enum_class a, enum_class b)
	noexcept
	{
		return a._value != b._value;
	}
};

} // namespace oglplus

#endif // include guard
