/**
 *  @file eagine/deferred_handler.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_DEFERRED_HANDLER_1509260923_HPP
#define EAGINE_DEFERRED_HANDLER_1509260923_HPP

#include <utility>
#include <cassert>

namespace eagine {

template <typename Data>
struct default_deferred_handler_policy
{
	void (*_handler)(Data&);

	void (*_release_handler(void) noexcept)(Data&)
	{
		void (*handler)(Data&) = _handler;
		_handler = nullptr;
		return handler;
	}

	constexpr inline
	default_deferred_handler_policy(void)
	noexcept
	 : _handler(nullptr)
	{ }

	constexpr inline
	default_deferred_handler_policy(void(*handler)(Data&))
	noexcept
	 : _handler(handler)
	{ }

	default_deferred_handler_policy(
		const default_deferred_handler_policy&
	) = delete;
	default_deferred_handler_policy& operator = (
		const default_deferred_handler_policy&
	) = delete;

	default_deferred_handler_policy(
		default_deferred_handler_policy&& temp
	) noexcept
	 : _handler(temp._release_handler())
	{ }

	default_deferred_handler_policy& operator = (
		default_deferred_handler_policy&& temp
	) noexcept
	{
		this->_handler = temp._release_handler();
		return *this;
	}

	inline
	bool is_valid(const Data&) const
	noexcept
	{
		return _handler != nullptr;
	}

	inline
	void invoke(Data& data) const
	{
		assert(_handler != nullptr);
		_handler(data);
	}

	inline
	void cancel(Data&)
	noexcept
	{
		_handler = nullptr;
	}
};

template <typename Data, typename HandlerPolicy>
class cancelled_handler
{
private:
	Data _data;
	bool _error;
public:
	constexpr inline
	cancelled_handler(void)
	noexcept
	 : _data()
	 , _error(true)
	{ }

	cancelled_handler(cancelled_handler&&) = default;
	cancelled_handler& operator = (cancelled_handler&&) = default;

	constexpr inline
	cancelled_handler(Data&& data, bool had_error)
	noexcept
	 : _data(std::move(data))
	 , _error(had_error)
	{ }

	constexpr inline
	cancelled_handler(const Data& data, bool had_error)
	noexcept
	 : _data(data)
	 , _error(had_error)
	{ }

	explicit
	operator bool (void) const
	noexcept
	{
		return _error;
	}

	bool operator ! (void) const
	noexcept
	{
		return !_error;
	}

	bool cancel(void)
	noexcept
	{
		return _error;
	}

	Data& data(void)
	noexcept
	{
		return _data;
	}

	const Data& data(void) const
	noexcept
	{
		return _data;
	}
};

template <
	typename Data,
	typename HandlerPolicy = default_deferred_handler_policy<Data>
>
class deferred_handler
{
private:
	HandlerPolicy _handler;
	Data _data;
public:
	constexpr inline
	deferred_handler(void)
	noexcept
	 : _handler()
	 , _data()
	{ }

	constexpr inline
	deferred_handler(Data&& data)
	noexcept
	 : _handler()
	 , _data(std::move(data))
	{ }

	constexpr inline
	deferred_handler(const Data& data)
	noexcept
	 : _handler()
	 , _data(data)
	{ }

	constexpr inline
	deferred_handler(HandlerPolicy handler, Data&& data)
	noexcept
	 : _handler(std::move(handler))
	 , _data(std::move(data))
	{ }

	constexpr inline
	deferred_handler(HandlerPolicy handler, const Data& data)
	noexcept
	 : _handler(std::move(handler))
	 , _data(data)
	{ }

	deferred_handler(const deferred_handler&) = delete;
	deferred_handler& operator = (const deferred_handler&) = delete;

	deferred_handler(deferred_handler&& temp)
	noexcept
	 : _handler(std::move(temp._handler))
	 , _data(std::move(temp._data))
	{
		temp._handler.cancel(temp._data);
	}

	deferred_handler& operator = (deferred_handler&& temp)
	noexcept
	{
		this->_handler = std::move(temp._handler);
		this->_data = std::move(temp._data);
		temp._handler.cancel(temp._data);
		return *this;
	}

	~deferred_handler(void)
	noexcept(false)
	{
		if(_handler.is_valid(_data))
		{
			_handler.invoke(_data);
		}
	}

	explicit
	operator bool (void) const
	noexcept
	{
		return _handler.is_valid(_data);
	}

	bool operator ! (void) const
	noexcept
	{
		return !_handler.is_valid(_data);
	}

	bool cancel(void)
	noexcept
	{
		if(_handler.is_valid(_data))
		{
			_handler.cancel(_data);
			return true;
		}
		return false;
	}

	void trigger(void)
	{
		if(_handler.is_valid(_data))
		{
			HandlerPolicy handler = std::move(_handler);
			try { handler.invoke(_data); }
			catch(...)
			{
				handler.cancel(_data);
				throw;
			}
			handler.cancel(_data);
		}
	}

	Data& data(void)
	noexcept
	{
		return _data;
	}

	const Data& data(void) const
	noexcept
	{
		return _data;
	}
};

template <typename Data>
static inline constexpr
deferred_handler<Data> make_deferred_handler(
	void (*handler)(Data&),
	Data data
) noexcept
{
	return {handler, std::move(data)};
}

} // namespace eagine

#endif // include guard
