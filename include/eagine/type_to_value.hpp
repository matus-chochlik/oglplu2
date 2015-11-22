/**
 *  @file eagine/type_to_value.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TYPE_TO_VALUE_1509260923_HPP
#define EAGINE_TYPE_TO_VALUE_1509260923_HPP

#include "instead_of.hpp"
#include "identity.hpp"
#include "type_traits.hpp"
#include "iterator.hpp"
#include "types.hpp"
#include <utility>
#include <cassert>

namespace eagine {

template <typename Value>
struct type_to_value_unit_base
{
	Value _value;

	type_to_value_unit_base(void) = default;

	template <typename T>
	type_to_value_unit_base(T&& value)
	 : _value(std::forward<T>(value))
	{ }

	operator Value& (void)
	noexcept
	{
		return _value;
	}

	operator const Value& (void) const
	noexcept
	{
		return _value;
	}
};

template <typename Value, typename Key>
struct type_to_value_unit
 : type_to_value_unit_base<Value>
{
	type_to_value_unit(void) = default;

	template <typename T>
	type_to_value_unit(T&& value)
	 : type_to_value_unit_base<Value>(std::forward<T>(value))
	{ }
};

template <typename Value, typename ... Keys>
struct type_to_value
 : type_to_value_unit<Value, Keys>...
{
	typedef Value value_type;
	typedef std::ptrdiff_t size_type;

	type_to_value(void) = default;

	type_to_value(instead_of_t<Keys, Value> ... values)
	 : type_to_value_unit<Value, Keys>(values)...
	{ }

	template <
		typename Transform,
		typename = std::enable_if_t<
			!std::is_same<Value, Transform>::value
		>
	>
	type_to_value(const Transform& transform)
	 : type_to_value_unit<Value, Keys>(transform(identity<Keys>()))...
	{ }

	static constexpr inline
	size_type size(void)
	noexcept
	{
		return sizeof ... (Keys);
	}

	type_to_value_unit_base<Value>*
	units(void)
	noexcept
	{
		static_assert(
			sizeof(type_to_value) ==
			sizeof(type_to_value_unit_base<Value>)*
			sizeof ... (Keys),
			"Unable to reinterpret this as array of units"
		);
		typedef type_to_value_unit_base<Value> ub_t;
		return reinterpret_cast<ub_t*>(this);
	}

	const type_to_value_unit_base<Value>*
	units(void) const
	noexcept
	{
		static_assert(
			sizeof(type_to_value) ==
			sizeof(type_to_value_unit_base<Value>)*
			sizeof ... (Keys),
			"Unable to reinterpret this as array of units"
		);
		typedef type_to_value_unit_base<Value> ub_t;
		return reinterpret_cast<const ub_t*>(this);
	}

	type_to_value_unit_base<Value>&
	unit(size_type pos)
	noexcept
	{
		assert(pos < size());
		return units()[pos];
	}

	const type_to_value_unit_base<Value>&
	unit(size_type pos) const
	noexcept
	{
		assert(pos < size());
		return units()[pos];
	}

	template <typename Key>
	type_to_value_unit<Value, Key>& unit(void)
	noexcept
	{
		return *this;
	}

	template <typename Key>
	const type_to_value_unit<Value, Key>& unit(void) const
	noexcept
	{
		return *this;
	}

	template <typename Key>
	Value& ref(void)
	noexcept
	{
		return unit<Key>();
	}

	template <typename Key>
	const Value& ref(void) const
	noexcept
	{
		return unit<Key>();
	}

	Value& ref(size_type pos)
	noexcept
	{
		return unit(pos);
	}

	const Value& ref(size_type pos) const
	noexcept
	{
		return unit(pos);
	}

	Value& operator [] (size_type pos)
	noexcept
	{
		return ref(pos);
	}

	const Value& operator [] (size_type pos) const
	noexcept
	{
		return ref(pos);
	}

	typedef noexcept_casting_iterator<
		type_to_value_unit_base<Value>*,
		Value, Value&
	> iterator;

	iterator begin(void)
	noexcept
	{
		return iterator(units());
	}

	iterator end(void)
	noexcept
	{
		return iterator(units()+size());
	}

	friend
	bool operator == (const type_to_value& a, const type_to_value& b)
	noexcept
	{
		for(size_type i=0; i<size(); ++i)
		{
			if(a[i] != b[i])
			{
				return false;
			}
		}
		return true;
	}

	friend
	bool operator != (const type_to_value& a, const type_to_value& b)
	noexcept
	{
		return !(a == b);
	}
};

} // namespace eagine

#endif //include guard

