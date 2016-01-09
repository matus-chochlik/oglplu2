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

	constexpr inline
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
	constexpr
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

	explicit
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

	const T& operator / (const T& fallback) const
	noexcept
	{
		return value_or(fallback);
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

// greater-than
template <typename T, T Sentinel>
struct valid_if_gt_policy
{
	bool operator ()(T value) const
	noexcept
	{
		return value > Sentinel;
	}
};

template <typename T, T Cmp>
struct valid_if_greater_than
 : valid_if<T, valid_if_gt_policy<T, Cmp>>
{
	constexpr
	valid_if_greater_than(T val)
	noexcept
	 : valid_if<T, valid_if_gt_policy<T, Cmp>>(val)
	{ }
};

// not-equal
template <typename T, T Sentinel>
struct valid_if_ne_policy
{
	bool operator ()(T value) const
	noexcept
	{
		return value != Sentinel;
	}
};

template <typename T, T Sentinel>
struct valid_if_not
 : valid_if<T, valid_if_ne_policy<T, Sentinel>>
{
	constexpr
	valid_if_not(T val)
	noexcept
	 : valid_if<T, valid_if_ne_policy<T, Sentinel>>(val)
	{ }
};

// not-zero
template <typename T>
struct valid_if_nz_policy
{
	bool operator ()(T value) const
	noexcept
	{
		return (value > 0 || value < 0);
	}
};

template <typename T>
struct valid_if_not_zero
 : valid_if<T, valid_if_nz_policy<T>>
{
	constexpr
	valid_if_not_zero(T val)
	noexcept
	 : valid_if<T, valid_if_nz_policy<T>>(val)
	{ }
};

template <typename T>
using nonzero_t = valid_if_not_zero<T>;

template <typename T>
static inline
nonzero_t<T> nonzero(T v)
noexcept
{
	return {v};
}

} // namespace eagine

#endif // include guard
