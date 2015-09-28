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

namespace eagine {

template <typename Data>
class deferred_handler
{
private:
	void (*_handler)(Data&);
	Data _data;

	void (*_release_handler(void) noexcept)(Data&)
	{
		void (*handler)(Data&) = _handler;
		_handler = nullptr;
		return handler;
	}
public:
	constexpr
	deferred_handler(void)
	noexcept
	 : _handler(nullptr)
	{ }

	constexpr inline
	deferred_handler(void(*handler)(Data&), Data data)
	noexcept
	 : _handler(handler)
	 , _data(std::move(data))
	{ }

	deferred_handler(const deferred_handler&) = delete;
	deferred_handler& operator = (const deferred_handler&) = delete;

	deferred_handler(deferred_handler&& temp)
	noexcept
	 : _handler(temp._release_handler())
	 , _data(std::move(temp._data))
	{ }

	deferred_handler& operator = (deferred_handler&& temp)
	noexcept
	{
		this->_handler = temp._release_handler();
		this->_data = std::move(temp._data);
		return *this;
	}

	~deferred_handler(void)
	noexcept(false)
	{
		if(_handler != nullptr)
		{
			_handler(_data);
		}
	}

	explicit
	operator bool (void) const
	noexcept
	{
		return _handler != nullptr;
	}

	bool operator ! (void) const
	noexcept
	{
		return _handler == nullptr;
	}

	bool cancel(void)
	noexcept
	{
		if(_handler)
		{
			_handler = nullptr;
			return true;
		}
		return false;
	}

	void trigger(void)
	{
		if(_handler != nullptr)
		{
			auto handler = _handler;
			_handler = nullptr;
			handler(_data);
		}
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
