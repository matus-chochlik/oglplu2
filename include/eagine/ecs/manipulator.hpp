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

#include "../type_traits.hpp"
#include <cassert>
#include <utility>

namespace eagine {
namespace ecs {

template <typename Component, bool Const>
class basic_manipulator;

template <typename Component>
class basic_manipulator<Component, false>
{
private:
	Component* _ptr;
protected:
	void _reset_cmp(Component& cmp)
	noexcept
	{
		_ptr = &cmp;
	}
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
protected:
	void _reset_cmp(const Component& cmp)
	noexcept
	{
		_ptr = &cmp;
	}
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
class manipulator
 : public get_manipulator<
	std::remove_const_t<Component>,
	std::is_const<Component>::value
>::type
{
private:
	using _base = typename get_manipulator<
		std::remove_const_t<Component>,
		std::is_const<Component>::value
	>::type;

	typedef std::remove_const_t<Component> _nonconstC;
	std::remove_const_t<Component> * _add_place;
protected:
	const bool _can_rem;
	bool _removed;
	bool _added;
public:
	manipulator(bool can_rem)
	 : _base()
	 , _add_place(nullptr)
	 , _can_rem(can_rem)
	 , _removed(false)
	 , _added(false)
	{ }

	manipulator(Component& cmp, bool can_rem)
	 : _base(cmp)
	 , _add_place(nullptr)
	 , _can_rem(can_rem)
	 , _removed(false)
	 , _added(false)
	{ }

	manipulator(Component& cmp, _nonconstC& add, bool can_rem)
	 : _base(cmp)
	 , _add_place(&add)
	 , _can_rem(can_rem)
	 , _removed(false)
	 , _added(false)
	{ }

	manipulator(std::nullptr_t, _nonconstC& add, bool can_rem)
	 : _base()
	 , _add_place(&add)
	 , _can_rem(can_rem)
	 , _removed(false)
	 , _added(false)
	{ }

	bool can_add(void) const
	noexcept
	{
		return _add_place != nullptr;
	}

	void add(std::remove_const_t<Component>&& cmp)
	{
		assert(can_add());
		assert(_add_place);
		*_add_place = std::move(cmp);
		this->_reset_cmp(*_add_place);
		_added = true;
	}

	bool can_remove(void) const
	noexcept
	{
		return _can_rem && this->is_valid();
	}

	void remove(void)
	{
		_removed = true;
	}
};

template <typename Component>
class concrete_manipulator
 : public manipulator<Component>
{
public:
	using manipulator<Component>::manipulator;

	void reset(Component& cmp)
	noexcept
	{
		this->_reset_cmp(cmp);
		this->_added = false;
		this->_removed = false;
	}

	bool add_requested(void) const
	noexcept
	{
		return this->_added;
	}

	bool remove_requested(void) const
	noexcept
	{
		return this->_removed;
	}
};

} // namespace ecs
} // namespace eagine

#endif //include guard

