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

#include "type_traits.hpp"
#include <utility>
#include <cassert>

namespace eagine {

struct valid_flag_policy
{
	bool _is_valid;

	constexpr
	valid_flag_policy(void)
	noexcept
	 : _is_valid(false)
	{ }

	constexpr
	valid_flag_policy(bool is_valid)
	noexcept
	 : _is_valid(is_valid)
	{ }

	template <typename T>
	bool operator ()(const T&) const
	noexcept
	{
		return _is_valid;
	}
};

template <typename T, typename Policy>
class valid_if
{
private:
	T _value;
	Policy _policy;

protected:
	explicit
	valid_if(Policy policy)
	noexcept
	 : _value()
	 , _policy(policy)
	{ }

public:
	valid_if(void) = default;

	valid_if(valid_if&&) = default;
	valid_if(const valid_if&) = default;

	valid_if& operator = (valid_if&&) = default;
	valid_if& operator = (const valid_if&) = default;

	~valid_if(void) = default;

	constexpr inline
	valid_if(T val)
	noexcept
	 : _value(val)
	 , _policy()
	{ }

	constexpr
	valid_if(T val, Policy policy)
	noexcept
	 : _value(val)
	 , _policy(policy)
	{ }

	valid_if& operator = (const T& v)
	{
		_value = v;
		return *this;
	}

	valid_if& operator = (T&& v)
	{
		_value = std::move(v);
		return *this;
	}

	bool is_valid(const T& val) const
	noexcept
	{
		return _policy(val);
	}

	bool is_valid(void) const
	noexcept
	{
		return _policy(_value);
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

	T& value(void)
	noexcept
	{
		assert(is_valid());
		return _value;
	}

	const T& value(void) const
	noexcept
	{
		assert(is_valid());
		return _value;
	}

	T& value_or(T& fallback)
	noexcept
	{
		return is_valid()?value():fallback;
	}

	const T& value_or(const T& fallback) const
	noexcept
	{
		return is_valid()?value():fallback;
	}

	template <typename Func>
	std::enable_if_t<std::is_same<std::result_of_t<Func(T)>, void>::value>
	then(const Func& func) const
	{
		if(is_valid())
		{
			func(value());
		}
	}

	template <typename Func>
	std::enable_if_t<
		!std::is_same<std::result_of_t<Func(T)>, void>::value,
		valid_if<
			std::result_of_t<Func(T)>,
			valid_flag_policy
		>
	> then(const Func& func) const
	{
		if(is_valid())
		{
			return {func(value()), true};
		}
		return {};
	}

	template <typename Func>
	valid_if transformed(Func func) const
	{
		return {func(_value)};
	}

	template <typename Func>
	auto operator | (const Func& func) const
	{
		return then(func);
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

// always
struct always_valid_policy
{
	template <typename T>
	constexpr inline
	bool operator ()(T) const
	noexcept
	{
		return true;
	}
};

template <typename T, T Cmp>
using always_valid = valid_if<T, always_valid_policy>;

// greater-than
template <typename T, T Cmp>
struct valid_if_gt_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return value > Cmp;
	}
};

template <typename T, T Cmp>
using valid_if_greater_than = valid_if<T, valid_if_gt_policy<T, Cmp>>;

// positive
template <typename T>
struct valid_if_positive_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return value > T(0);
	}
};

template <typename T>
using valid_if_positive = valid_if<T, valid_if_positive_policy<T>>;

// not-equal
template <typename T, T Cmp>
struct valid_if_ne_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return value != Cmp;
	}
};

template <typename T, T Cmp>
using valid_if_not = valid_if<T, valid_if_ne_policy<T, Cmp>>;

// not-zero
template <typename T>
struct valid_if_nz_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (value > T(0)) || (value < T(0));
	}
};

template <typename T>
using valid_if_not_zero = valid_if<T, valid_if_nz_policy<T>>;

// nonzero
template <typename T>
using nonzero_t = valid_if_not_zero<T>;

template <typename T>
static inline
nonzero_t<T> nonzero(T v)
noexcept
{
	return {v};
}

// between [min, max]
template <typename T, T Min, T Max>
struct valid_if_btwn_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (Min <= value) && (value <= Max);
	}
};

template <typename T, T Min, T Max>
using valid_if_between = valid_if<T, valid_if_btwn_policy<T, Min, Max>>;

// in [0, 1]
template <typename T>
struct valid_if_ge0_le1_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (T(0) <= value) && (value <= T(1));
	}
};

template <typename T>
using valid_if_between_0_1 = valid_if<T, valid_if_ge0_le1_policy<T>>;

// in [0, 1)
template <typename T>
struct valid_if_ge0_lt1_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (T(0) <= value) && (value < T(1));
	}
};

template <typename T>
using valid_if_ge0_lt1 = valid_if<T, valid_if_ge0_lt1_policy<T>>;

// in (0, 1)
template <typename T>
struct valid_if_gt0_lt1_policy
{
	constexpr
	bool operator ()(T value) const
	noexcept
	{
		return (T(0) < value) && (value < T(1));
	}
};

template <typename T>
using valid_if_gt0_lt1 = valid_if<T, valid_if_gt0_lt1_policy<T>>;

// not empty
template <typename T>
struct valid_if_not_empty_policy
{
	constexpr
	bool operator ()(const T& range) const
	noexcept
	{
		return !range.empty();
	}
};

template <typename T>
using valid_if_not_empty = valid_if<T, valid_if_not_empty_policy<T>>;

// one of
template <typename T, T ... C>
struct valid_if_one_of_policy
{
	constexpr
	bool operator ()(const T& value) const
	noexcept
	{
		const T choices[] = {C...};
		for(const T& choice : choices)
		{
			if(value == choice)
			{
				return true;
			}
		}
		return false;
	}
};

template <typename T, T ... C>
using valid_if_one_of = valid_if<T, valid_if_one_of_policy<T, C...>>;

// in range
template <typename T, typename Range>
struct valid_if_in_range_policy
{
	Range _choices;

	valid_if_in_range_policy(const Range& choices)
	 : _choices(choices)
	{ }

	constexpr
	bool operator ()(const T& value) const
	noexcept
	{
		for(const T& choice : _choices)
		{
			if(value == choice)
			{
				return true;
			}
		}
		return false;
	}
};

template <typename T, typename Range>
using valid_if_in_range = valid_if<T, valid_if_in_range_policy<T, Range>>;

// in container

} // namespace eagine

#endif // include guard
