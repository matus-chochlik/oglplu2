/**
 *  @file eagine/ecs/manipulator.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_MANIPULATOR_1509260923_HPP
#define EAGINE_ECS_MANIPULATOR_1509260923_HPP

#include <cassert>
#include "../type_traits.hpp"

namespace eagine {
namespace ecs {

template <typename Component, bool Const>
class basic_manipulator;

template <typename Component>
class basic_manipulator<Component, false>
{
private:
	Component* _ptr;
public:
	basic_manipulator(void)
	noexcept
	 : _ptr(nullptr)
	{ }

	basic_manipulator(Component& cmp)
	noexcept
	 : _ptr(&cmp)
	{ }

	bool is_valid(void) const
	noexcept
	{
		return _ptr != nullptr;
	}

	void reset(Component& cmp)
	noexcept
	{
		_ptr = &cmp;
	}

	const Component& read(void) const
	{
		assert(is_valid());
		return *_ptr;
	}

	Component& write(void)
	{
		assert(is_valid());
		return *_ptr;
	}
};

template <typename Component>
class basic_manipulator<Component, true>
{
private:
	const Component* _ptr;
public:
	basic_manipulator(void)
	noexcept
	 : _ptr(nullptr)
	{ }

	basic_manipulator(const Component& cmp)
	noexcept
	 : _ptr(&cmp)
	{ }

	bool is_valid(void) const
	noexcept
	{
		return _ptr != nullptr;
	}

	void reset(const Component& cmp)
	noexcept
	{
		_ptr = &cmp;
	}

	const Component& read(void) const
	{
		assert(_ptr != nullptr);
		return *_ptr;
	}
};

template <typename Component, bool Const>
struct get_manipulator
{
	typedef basic_manipulator<Component, Const> type;
};

template <typename Component>
struct manipulator : get_manipulator<
	std::remove_const_t<Component>,
	std::is_const<Component>::value
>::type
{
	using _base = typename get_manipulator<
		std::remove_const_t<Component>,
		std::is_const<Component>::value
	>::type;
	using _base::_base;
};

} // namespace ecs
} // namespace eagine

#endif //include guard

