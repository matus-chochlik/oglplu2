/**
 *  @file eagine/valid_if/base.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_BASE_1509260923_HPP
#define EAGINE_VALID_IF_BASE_1509260923_HPP

#include "../type_traits.hpp"
#include <utility>
#include <cassert>

namespace eagine {

template <
	typename T,
	typename Policy,
	typename Abort,
	typename DoLog,
	typename ... P
>
class basic_valid_if
{
private:
	T _value;
	Policy _policy;
	Abort _do_abort;
	DoLog _do_log;

protected:
	explicit
	basic_valid_if(Policy policy)
	noexcept
	 : _value()
	 , _policy(policy)
	 , _do_log(_policy)
	{ }
public:
	basic_valid_if(void)
	noexcept
	 : _value()
	 , _policy()
	 , _do_log(_policy)
	{ }

	basic_valid_if(basic_valid_if&&) = default;
	basic_valid_if(const basic_valid_if&) = default;

	basic_valid_if& operator = (basic_valid_if&&) = default;
	basic_valid_if& operator = (const basic_valid_if&) = default;

	~basic_valid_if(void) = default;

	constexpr inline
	basic_valid_if(T val)
	noexcept
	 : _value(val)
	 , _policy()
	 , _do_log(_policy)
	{ }

	constexpr
	basic_valid_if(T val, Policy policy)
	noexcept
	 : _value(val)
	 , _policy(policy)
	 , _do_log(_policy)
	{ }

	basic_valid_if& operator = (const T& v)
	{
		_value = v;
		return *this;
	}

	basic_valid_if& operator = (T&& v)
	{
		_value = std::move(v);
		return *this;
	}

	friend
	bool operator == (const basic_valid_if& a, const basic_valid_if& b)
	noexcept
	{
		return (a._value == b._value) && a.is_valid() && b.is_valid();
	}

	bool is_valid(const T& val, P ... p) const
	noexcept
	{
		return _policy(val, p...);
	}

	bool is_valid(P ... p) const
	noexcept
	{
		return is_valid(_value, p...);
	}

	template <typename Log>
	void log_invalid(Log& log, const T& v, P ... p) const
	{
		assert(!is_valid(v));
		_do_log(log, v, p...);
	}

	template <typename Log>
	void log_invalid(Log& log, P ... p) const
	{
		log_invalid(log, _value, p...);
	}

	template <typename Func>
	basic_valid_if& call_if_invalid(Func func, P ... p)
	{
		if(!is_valid(p...)) func(_do_log, _value, p...);
		return *this;
	}

	void abort_if_invalid(P ... p) const
	noexcept
	{
		if(!is_valid(p...)) _do_abort();
	}

	T& value(P ... p)
	noexcept
	{
		abort_if_invalid(p...);
		return _value;
	}

	const T& value(P ... p) const
	noexcept
	{
		abort_if_invalid(p...);
		return _value;
	}

	T& value_or(T& fallback, P ... p)
	noexcept
	{
		return is_valid(p...)?value(p...):fallback;
	}

	const T& value_or(const T& fallback, P ... p) const
	noexcept
	{
		return is_valid(p...)?value(p...):fallback;
	}

	template <typename Func>
	std::enable_if_t<std::is_same<std::result_of_t<Func(T)>, void>::value>
	then(const Func& func, P ... p) const
	{
		if(is_valid(p...))
		{
			func(value(p...));
		}
	}
};

} // namespace eagine

#endif // include guard
