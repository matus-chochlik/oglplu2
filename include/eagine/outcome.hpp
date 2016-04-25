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
#include "selector.hpp"
#include <utility>
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
	 : _val(std::move(val))
	{ }

	constexpr
	const T& get(void) const
	noexcept
	{
		return _val;
	}

	T& ref(void)
	noexcept
	{
		return _val;
	}

	template <typename Func>
	void apply(Func func)
	noexcept
	{
		try { func(_val); }
		catch(...) { }
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

	template <typename Func>
	void apply(Func func)
	noexcept
	{
		try { func(get()); }
		catch(...) { }
	}
};

template <
	typename T,
	typename ErrorData,
	typename HandlerPolicy = default_deferred_handler_policy<ErrorData>,
	template <class, class> class Handler = deferred_handler
>
class basic_outcome;

template <typename ErrorData, typename HandlerPolicy>
class basic_outcome<void, ErrorData, HandlerPolicy, cancelled_handler>
{
protected:
	cancelled_handler<ErrorData, HandlerPolicy> _handler;
public:
	basic_outcome(void) = default;
	basic_outcome(basic_outcome&&) = default;

	constexpr
	basic_outcome(cancelled_handler<ErrorData, HandlerPolicy>&& handler)
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

	bool failed(void) const
	noexcept
	{
		return bool(_handler);
	}

	bool succeeded(void) const
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

template <typename T, typename ErrorData, typename HandlerPolicy>
class basic_outcome<T, ErrorData, HandlerPolicy, cancelled_handler>
 : public basic_outcome<void, ErrorData, HandlerPolicy, cancelled_handler>
{
private:
	typedef basic_outcome<
		void,
		ErrorData,
		HandlerPolicy,
		cancelled_handler
	> _base;
	basic_outcome_storage<T> _value;
public:
	basic_outcome(basic_outcome&&) = default;

	basic_outcome(
		cancelled_handler<ErrorData, HandlerPolicy>&& handler,
		basic_outcome_storage<T>&& val_stor
	) noexcept
	 : _base(std::move(handler))
	 , _value(std::move(val_stor))
	{ }

	T value(void)
	{
		assert(this->succeeded());
		return _value.get();
	}

	T value_or(const T& fallback)
	{
		return this->succeeded()?_value.get():fallback;
	}

	T&& rvalue(void)
	{
		assert(this->succeeded());
		return std::move(_value.ref());
	}

	operator T&& (void)
	{
		return rvalue();
	}

	template <typename Func>
	void then(Func func)
	noexcept
	{
		if(this->succeeded())
		{
			_value.apply(func);
		}
	}
};

template <typename ErrorData, typename HandlerPolicy>
class basic_outcome<void, ErrorData, HandlerPolicy, deferred_handler>
{
protected:
	deferred_handler<ErrorData, HandlerPolicy> _handler;
public:
	basic_outcome(void) = default;
	basic_outcome(basic_outcome&&) = default;

	constexpr
	basic_outcome(deferred_handler<ErrorData, HandlerPolicy>&& handler)
	noexcept
	 : _handler(std::move(handler))
	{ }

	deferred_handler<ErrorData, HandlerPolicy>
	release_handler(void)
	noexcept
	{
		return std::move(_handler);
	}

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

	basic_outcome<void, ErrorData, HandlerPolicy, cancelled_handler>
	ignore_error(void)
	noexcept
	{
		return cancelled_handler<ErrorData, HandlerPolicy>(
			std::move(_handler.data()),
			_handler.cancel()
		);
	}

	template <typename HandlerFunc>
	auto handle_error(HandlerFunc handler_func)
	{
		_handler.cancel();
		return handler_func(_handler.data());
	}

	bool failed(void) const
	noexcept
	{
		return bool(_handler);
	}

	bool succeeded(void) const
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

template <typename T, typename ErrorData, typename HandlerPolicy>
class basic_outcome<T, ErrorData, HandlerPolicy, deferred_handler>
 : public basic_outcome<void, ErrorData, HandlerPolicy, deferred_handler>
{
private:
	typedef basic_outcome<
		void,
		ErrorData,
		HandlerPolicy,
		deferred_handler
	> _base;
	basic_outcome_storage<T> _value;
public:
	basic_outcome(basic_outcome&&) = default;

	constexpr
	basic_outcome(deferred_handler<ErrorData, HandlerPolicy>&& handler)
	noexcept
	 : _base(std::move(handler))
	{ }

	basic_outcome(T value)
	noexcept
	 : _value(value)
	{ }

	basic_outcome(
		deferred_handler<ErrorData, HandlerPolicy>&& handler,
		T&& val
	) noexcept
	 : _base(std::move(handler))
	 , _value(std::move(val))
	{ }

	basic_outcome(
		basic_outcome<void, ErrorData, HandlerPolicy>&& that,
		T&& val, selector<0>
	) noexcept
	 : _base(std::move(that))
	 , _value(std::move(val))
	{ }

	basic_outcome(
		basic_outcome<void, ErrorData, HandlerPolicy>&& that,
		const T& val
	) noexcept
	 : _base(std::move(that))
	 , _value(val)
	{ }

	basic_outcome<T, ErrorData, HandlerPolicy, cancelled_handler>
	ignore_error(void)
	noexcept
	{
		return {
			cancelled_handler<ErrorData, HandlerPolicy>(
				std::move(this->_handler.data()),
				this->_handler.cancel()
			), std::move(_value)
		};
	}

	T value(void)
	{
		this->_handler.trigger();
		return _value.get();
	}

	T&& rvalue(void)
	{
		this->_handler.trigger();
		return std::move(_value.ref());
	}

	operator T&& (void)
	{
		return rvalue();
	}

	template <typename Func>
	void then(Func func)
	noexcept
	{
		if(this->succeeded())
		{
			_value.apply(func);
		}
	}
};

template <typename T, typename U, typename ErrorData, typename HandlerPolicy>
static inline
basic_outcome<T, ErrorData, HandlerPolicy>
outcome_cast(basic_outcome<U, ErrorData, HandlerPolicy>&& that)
noexcept
{
	if(that.failed())
	{
		return {that.release_handler()};
	}
	return {T(that.value())};
}

template <typename T, typename U, typename ErrorData, typename HandlerPolicy>
static inline
basic_outcome<T, ErrorData, HandlerPolicy>
outcome_conversion(
	basic_outcome<U, ErrorData, HandlerPolicy>&& that,
	T (*convert)(U)
) noexcept
{
	if(that.failed())
	{
		return {that.release_handler()};
	}
	return {convert(that.value())};
}

template <typename T, typename ErrorData, typename HandlerPolicy>
static inline
basic_outcome<T, ErrorData, HandlerPolicy>
operator , (basic_outcome<void, ErrorData, HandlerPolicy>&& bo, T value)
noexcept
{
	return {std::move(bo), std::move(value), selector<0>()};
}

template <typename T, typename ErrorData, typename HandlerPolicy, typename Func>
static inline
basic_outcome<T, ErrorData, HandlerPolicy>&&
operator | (basic_outcome<T, ErrorData, HandlerPolicy>&& bo, Func func)
noexcept
{
	bo.then(func);
	return std::move(bo);
}

template <typename T, typename ErrorData, typename HandlerPolicy>
class basic_positive_outcome
 : public basic_outcome<T, ErrorData, HandlerPolicy>
{
public:
	basic_positive_outcome(basic_outcome<T, ErrorData, HandlerPolicy>&& o)
	noexcept
	 : basic_outcome<T, ErrorData, HandlerPolicy>(std::move(o))
	{ }

	explicit
	operator bool (void) const
	noexcept
	{
		return this->succeeded();
	}

	bool operator ! (void) const
	noexcept
	{
		return this->failed();
	}
};

template <typename T, typename ErrorData, typename HandlerPolicy>
static inline
basic_positive_outcome<T, ErrorData, HandlerPolicy>
success(basic_outcome<T, ErrorData, HandlerPolicy>&& o)
noexcept
{
	return std::move(o);
}

template <typename T, typename ErrorData, typename HandlerPolicy>
class basic_negative_outcome
 : public basic_outcome<T, ErrorData, HandlerPolicy>
{
public:
	basic_negative_outcome(basic_outcome<T, ErrorData, HandlerPolicy>&& o)
	noexcept
	 : basic_outcome<T, ErrorData, HandlerPolicy>(std::move(o))
	{ }

	explicit
	operator bool (void) const
	noexcept
	{
		return this->failed();
	}

	bool operator ! (void) const
	noexcept
	{
		return this->succeeded();
	}
};

template <typename T, typename ErrorData, typename HandlerPolicy>
static inline
basic_negative_outcome<T, ErrorData, HandlerPolicy>
failure(basic_outcome<T, ErrorData, HandlerPolicy>&& o)
noexcept
{
	return std::move(o);
}

} // namespace eagine

#endif // include guard
