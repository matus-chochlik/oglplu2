/**
 *  @file eagine/scope_exit.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SCOPE_EXIT_1509260923_HPP
#define EAGINE_SCOPE_EXIT_1509260923_HPP

#include "callable_ref.hpp"
#include "nothing.hpp"
#include <type_traits>
#include <exception>

namespace eagine {

template <typename OnException = nothing_t>
class on_scope_exit
{
public:
	typedef callable_ref<void(void)> action_type;
private:
	action_type _action;

	void _invoke(std::true_type) const
	{
		if(_action)
		{
			if(std::uncaught_exception())
			{
				try { _action(); }
				catch(...){ }
			}
		}
	}

	void _invoke(std::false_type) const
	{
		if(_action)
		{
			if(!std::uncaught_exception())
			{
				_action();
			}
		}
	}

	void _invoke(nothing_t) const
	{
		if(_action)
		{
			_action();
		}
	}
public:
	on_scope_exit(action_type action)
	noexcept
	 : _action(action)
	{ }

	template <typename Func>
	on_scope_exit(Func& action)
	noexcept
	 : _action(action_type(action))
	{ }

	on_scope_exit(const on_scope_exit&) = delete;

	~on_scope_exit(void)
	noexcept(false)
	{
		_invoke(OnException());
	}

	action_type release(void)
	{
		return std::move(_action);
	}

	void cancel(void)
	{
		_action = action_type();
	}
};

} // namespace eagine

#endif // include guard
