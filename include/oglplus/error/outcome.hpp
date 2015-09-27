/**
 *  @file oglplus/error/outcome.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_ERROR_OUTCOME_1509260923_HPP
#define OGLPLUS_ERROR_OUTCOME_1509260923_HPP

#include "../utils/deferred_handler.hpp"
#include "info.hpp"
#include <cassert>

namespace oglplus {

template <typename T>
class outcome_storage;

template <typename T>
class outcome_storage
{
private:
	T _val;
public:
	outcome_storage(void) = default;

	constexpr
	outcome_storage(T val)
	noexcept
	 : _val(val)
	{ }

	constexpr
	T get(void) const
	noexcept
	{
		return _val;
	}
};

template <typename T>
class outcome_storage<T&>
{
private:
	T* _ref;
public:
	constexpr
	outcome_storage(void)
	noexcept
	 : _ref(nullptr)
	{ }

	outcome_storage(T& ref)
	noexcept
	 : _ref(&ref)
	{ }

	T& get(void) const
	noexcept
	{
		assert(_ref != nullptr);
		return *_ref;
	}
};

template <typename T>
class outcome
{
private:
	deferred_handler<error_info> _handler;
	outcome_storage<T> _value;
public:
	outcome(deferred_handler<error_info>&& handler)
	noexcept
	 : _handler(std::move(handler))
	{ }

	outcome(T value)
	noexcept
	 : _value(value)
	{ }

	T get(void)
	{
		_handler.trigger();
		return _value.get();
	}

	operator T (void)
	{
		return get();
	}

	outcome& ignore_error(void)
	noexcept
	{
		_handler.cancel();
		return *this;
	}

	bool done(void) const
	noexcept
	{
		return !_handler;
	}

	bool done_without_error(void)
	noexcept
	{
		return !_handler.cancel();
	}
};

} // namespace oglplus

#endif // include guard
