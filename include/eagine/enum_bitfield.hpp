/**
 *  @file eagine/enum_bitfield.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ENUM_BITFIELD_1509260923_HPP
#define EAGINE_ENUM_BITFIELD_1509260923_HPP

#include "enum_class.hpp"

namespace eagine {

template <typename T, typename ClassList>
struct enum_bits;

template <typename T, typename ... Classes>
struct enum_bits<T, mp_list<Classes...>>
{
	T _bits;

	explicit constexpr inline
	enum_bits(T bits)
	noexcept
	 : _bits(bits)
	{ }
};

template <
	typename T,
	T V1,
	typename TL1,
	T V2,
	typename TL2,
	typename = std::enable_if_t<!mp_empty<mp_union_t<TL1,TL2>>::value>
>
static constexpr inline
enum_bits<T, mp_union_t<TL1, TL2>>
operator | (enum_value<T, V1, TL1>, enum_value<T, V2, TL2>)
noexcept
{
	return enum_bits<T, mp_union_t<TL1, TL2>>{V1|V2};
}

template <
	typename T,
	typename TL1,
	T V2,
	typename TL2,
	typename = std::enable_if_t<!mp_empty<mp_union_t<TL1,TL2>>::value>
>
static constexpr inline
enum_bits<T, mp_union_t<TL1, TL2>>
operator | (enum_bits<T, TL1> eb, enum_value<T, V2, TL2>)
noexcept
{
	return enum_bits<T, mp_union_t<TL1, TL2>>{eb._bits|V2};
}

template <typename EnumClass>
struct enum_bitfield
{
	typedef typename EnumClass::value_type value_type;

	value_type _value;

	constexpr inline
	enum_bitfield(void)
	noexcept
	 : _value(0)
	{ }

	explicit constexpr inline
	enum_bitfield(value_type value)
	noexcept
	 : _value(value)
	{ }

	constexpr inline
	enum_bitfield(EnumClass e)
	noexcept
	 : _value(e._value)
	{ }

	template <
		value_type Value,
		typename Classes,
		typename=std::enable_if_t<mp_contains<Classes,EnumClass>::value>
	>
	constexpr inline
	enum_bitfield(enum_value<value_type, Value, Classes>)
	noexcept
	 : _value(Value)
	{ }

	template <
		typename Classes,
		typename=std::enable_if_t<mp_contains<Classes,EnumClass>::value>
	>
	constexpr inline
	enum_bitfield(enum_bits<value_type, Classes> eb)
	noexcept
	 : _value(eb._bits)
	{ }

	explicit constexpr inline
	operator value_type(void) const
	noexcept
	{
		return _value;
	}

	template <value_type Value, typename Classes>
	constexpr inline
	bool has(enum_value<value_type, Value, Classes>) const
	noexcept
	{
		return (_value & Value) == Value;
	}

	friend constexpr inline
	bool operator == (enum_bitfield a, enum_bitfield b)
	noexcept
	{
		return a._value == b._value;
	}

	friend constexpr inline
	bool operator != (enum_bitfield a, enum_bitfield b)
	noexcept
	{
		return a._value != b._value;
	}

	friend constexpr inline
	enum_bitfield operator | (enum_bitfield a, enum_bitfield b)
	noexcept
	{
		return enum_bitfield{a._value|b._value};
	}

	friend constexpr inline
	enum_bitfield operator & (enum_bitfield a, enum_bitfield b)
	noexcept
	{
		return enum_bitfield{a._value&b._value};
	}
};

} // namespace eagine

#endif // include guard
