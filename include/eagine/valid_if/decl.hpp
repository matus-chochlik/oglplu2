/**
 *  @file eagine/valid_if/decl.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_DECL_1509260923_HPP
#define EAGINE_VALID_IF_DECL_1509260923_HPP

#include "base.hpp"
#include "../assert.hpp"

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

	struct do_log
	{
		inline
		do_log(const valid_flag_policy&)
		noexcept
		{ }

		template <typename Log, typename T>
		void operator ()(Log& log, const T&) const
		{
			log << "Getting the value of an empty optional";
		}
	};

	struct abort
	{
		[[noreturn]]
		void operator ()(void) const
		noexcept
		{
			EAGINE_ABORT("Getting the value of an empty optional");
		}
	};
};

template <
	typename T,
	typename Policy,
	typename Abort = typename Policy::abort,
	typename DoLog = typename Policy::do_log
>
class valid_if
 : public basic_valid_if<T, Policy, Abort, DoLog>
{
private:
	typedef basic_valid_if<T, Policy, Abort, DoLog> _base_t;

	_base_t& _base(void)
	noexcept
	{
		return *this;
	}
public:
	using _base_t::_base_t;
	using _base_t::is_valid;
	using _base_t::value;
	using _base_t::value_or;

	valid_if& operator = (const T& v)
	{
		_base() = v;
		return *this;
	}

	valid_if& operator = (T&& v)
	{
		_base() = std::move(v);
		return *this;
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
		return {func(value())};
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

template <typename T>
using optionally_valid = valid_if<T, valid_flag_policy>;

} // namespace eagine

#endif // include guard
