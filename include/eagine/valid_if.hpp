/**
 *  @file eagine/valid_if.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_1509260923_HPP
#define EAGINE_VALID_IF_1509260923_HPP

#include <utility>

namespace eagine {

template <typename T, typename Policy>
class valid_if
{
private:
	T _value;
	Policy _is_valid;

protected:
	valid_if(void) = default;

	valid_if(T val)
	noexcept
	 : _value(val)
	{ }

	explicit
	valid_if(Policy policy)
	noexcept
	 : _value()
	 , _is_valid(policy)
	{ }

public:
	valid_if(T val, Policy policy)
	noexcept
	 : _value(val)
	 , _is_valid(policy)
	{ }

	bool is_valid(void) const
	noexcept
	{
		return _is_valid(_value);
	}

	operator bool (void) const
	noexcept
	{
		return is_valid();
	}

	bool operator ! (void) const
	noexcept
	{
		return !is_valid();
	}

	const T& value(void) const
	noexcept
	{
		assert(is_valid());
		return _value;
	}

	const T& value_or(const T& fallback) const
	noexcept
	{
		return is_valid()?value():fallback;
	}

	const T& operator * (void) const
	noexcept
	{
		return value();
	}

	const T* operator -> (void) const
	noexcept
	{
		return &value();
	}
};

template <typename T, T Sentinel>
struct valid_if_greater_than_policy
{
	bool operator ()(T value) const
	noexcept
	{
		return value != Sentinel;
	}
};

template <typename T, T Cmp>
struct valid_if_greater_than
 : valid_if<T, valid_if_greater_than_policy<T, Cmp>>
{
	valid_if_greater_than(T val)
	noexcept
	 : valid_if<T, valid_if_greater_than_policy<T, Cmp>>(val)
	{ }
};

template <typename T, T Sentinel>
struct valid_if_not_policy
{
	bool operator ()(T value) const
	noexcept
	{
		return value != Sentinel;
	}
};

template <typename T, T Sentinel>
struct valid_if_not
 : valid_if<T, valid_if_not_policy<T, Sentinel>>
{
	valid_if_not(T val)
	noexcept
	 : valid_if<T, valid_if_not_policy<T, Sentinel>>(val)
	{ }
};

} // namespace eagine

#endif // include guard
