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

namespace eagine {
namespace ecs {

#include <cassert>

template <typename Component>
class base_manipulator;

template <typename Component>
class base_manipulator
{
private:
	Component* _ptr;
public:
	base_manipulator(void)
	noexcept
	 : _ptr(nullptr)
	{ }

	base_manipulator(Component& cmp)
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
class base_manipulator<const Component>
{
private:
	const Component* _ptr;
public:
	base_manipulator(void)
	noexcept
	 : _ptr(nullptr)
	{ }

	base_manipulator(const Component& cmp)
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

template <typename Component>
class manipulator
 : public base_manipulator<Component>
{
public:
	using base_manipulator<Component>::base_manipulator;
};

} // namespace ecs
} // namespace eagine

#endif //include guard

