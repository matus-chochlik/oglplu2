/**
 *  @file eagine/outcome.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_OUTCOME_1509260923_HPP
#define EAGINE_OUTCOME_1509260923_HPP

#include "deferred_handler.hpp"
#include <cassert>

namespace eagine {

template <typename T>
class basic_outcome_storage;

template <typename T>
class basic_outcome_storage
{
private:
	T _val;
public:
	basic_outcome_storage(void) = default;

	constexpr
	basic_outcome_storage(T val)
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
class basic_outcome_storage<T&>
{
private:
	T* _ref;
public:
	constexpr
	basic_outcome_storage(void)
	noexcept
	 : _ref(nullptr)
	{ }

	basic_outcome_storage(T& ref)
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

template <typename T, typename ErrorData>
class basic_outcome;

template <typename ErrorData>
class basic_outcome<void, ErrorData>
{
protected:
	deferred_handler<ErrorData> _handler;
public:
	basic_outcome(void) = default;

	constexpr
	basic_outcome(deferred_handler<ErrorData>&& handler)
	noexcept
	 : _handler(std::move(handler))
	{ }

	ErrorData& handler_data(void)
	noexcept
	{
		return _handler.data();
	}

	const ErrorData& handler_data(void) const
	noexcept
	{
		return _handler.data();
	}

	basic_outcome& ignore_error(void)
	noexcept
	{
		_handler.cancel();
		return *this;
	}

	template <typename Handler>
	auto handle_error(Handler new_handler)
	{
		_handler.cancel();
		return new_handler(_handler.data());
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

template <typename T, typename ErrorData>
class basic_outcome
 : public basic_outcome<void, ErrorData>
{
private:
	basic_outcome_storage<T> _value;
public:
	constexpr
	basic_outcome(deferred_handler<ErrorData>&& handler)
	noexcept
	 : basic_outcome<void, ErrorData>(std::move(handler))
	{ }

	basic_outcome(T value)
	noexcept
	 : _value(value)
	{ }

	T get(void)
	{
		this->_handler.trigger();
		return _value.get();
	}

	operator T (void)
	{
		return get();
	}
};

} // namespace eagine

#endif // include guard
