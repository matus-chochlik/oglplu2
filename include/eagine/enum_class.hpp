/**
 *  @file eagine/enum_class.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ENUM_CLASS_1509260923_HPP
#define EAGINE_ENUM_CLASS_1509260923_HPP

#include "mp_list.hpp"
#include "type_traits.hpp"
#include <cassert>

namespace eagine {

template <typename T, T Value, typename ClassList>
struct enum_value;

template <typename T, T Value, typename ... Classes>
struct enum_value<T, Value, mp_list<Classes...>>
{
	typedef enum_value type;

	explicit constexpr inline
	operator T (void) const
	noexcept
	{
		return Value;
	}
};

template <unsigned LibId>
struct any_enum_value;

template <typename Self, typename T, unsigned LibId, unsigned Id>
struct enum_class
{
	typedef enum_class type;

	typedef T value_type;

	static constexpr const unsigned lib_id = LibId;
	static constexpr const unsigned id = Id;

	value_type _value;

	enum_class(void) = default;

	template <
		T Value,
		typename Classes,
		typename = typename std::enable_if<
			mp_contains<Classes,Self>::value
		>::type
	>
	constexpr inline
	enum_class(enum_value<T, Value, Classes>)
	noexcept
	 : _value(Value)
	{ }

	constexpr
	enum_class(const any_enum_value<LibId>& aev)
	noexcept
	 : _value(static_cast<T>(aev._value))
	{
		assert(aev._type_id == Id);
	}

	explicit constexpr inline
	enum_class(value_type value)
	noexcept
	 : _value(value)
	{ }

	explicit constexpr inline
	operator value_type (void) const
	noexcept
	{
		return _value;
	}

	friend constexpr inline
	bool operator == (enum_class a, enum_class b)
	noexcept
	{
		return a._value == b._value;
	}

	friend constexpr inline
	bool operator != (enum_class a, enum_class b)
	noexcept
	{
		return a._value != b._value;
	}
};

template <typename T>
struct is_enum_class
 : std::false_type
{ };

template <typename Self, typename T, unsigned LibId, unsigned Id>
struct is_enum_class<enum_class<Self, T, LibId, Id>>
 : std::true_type
{ };

template <unsigned LibId>
struct any_enum_class
{
	unsigned _type_id;

	constexpr inline
	any_enum_class(void)
	noexcept
	 : _type_id(~unsigned(0))
	{ }

	template <typename Self, typename T, unsigned Id>
	constexpr inline
	any_enum_class(const enum_class<Self, T, LibId, Id>&)
	noexcept
	 : _type_id(Id)
	{ }

	constexpr inline
	any_enum_class(const any_enum_value<LibId>& aev)
	noexcept
	 : _type_id(aev._type_id)
	{ }

	explicit constexpr inline
	operator bool (void) const
	noexcept
	{
		return _type_id != ~unsigned(0);
	}

	constexpr inline
	bool operator ! (void) const
	noexcept
	{
		return _type_id == ~unsigned(0);
	}

	friend
	bool operator == (const any_enum_class& a, const any_enum_class& b)
	noexcept
	{
		return a._type_id == b._type_id;
	}

	friend
	bool operator != (const any_enum_class& a, const any_enum_class& b)
	noexcept
	{
		return a._type_id != b._type_id;
	}
};

template <unsigned LibId>
struct any_enum_value
{
	long _value;
	unsigned _type_id;

	constexpr inline
	any_enum_value(void)
	noexcept
	 : _value(0)
	 , _type_id(~unsigned(0))
	{ }

	template <typename Self, typename T, unsigned Id>
	constexpr inline
	any_enum_value(enum_class<Self, T, LibId, Id> v)
	noexcept
	 : _value(long(v._value))
	 , _type_id(Id)
	{ }

	explicit constexpr inline
	operator bool (void) const
	noexcept
	{
		return _type_id != ~unsigned(0);
	}

	constexpr inline
	bool operator ! (void) const
	noexcept
	{
		return _type_id == ~unsigned(0);
	}

	friend
	bool operator == (const any_enum_value& a, const any_enum_value& b)
	noexcept
	{
		return (a._value == b._value) && (a._type_id == b._type_id);
	}

	friend
	bool operator != (const any_enum_value& a, const any_enum_value& b)
	noexcept
	{
		return (a._value != b._value) || (a._type_id != b._type_id);
	}
};

template <unsigned LibId>
static constexpr inline
bool same_enum_class(any_enum_class<LibId> a, any_enum_class<LibId> b)
noexcept
{
	return a._type_id == b._type_id;
}

} // namespace eagine

#endif // include guard
