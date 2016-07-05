/**
 *  @file eagine/ecs/component.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_COMPONENT_1509260923_HPP
#define EAGINE_ECS_COMPONENT_1509260923_HPP

#include "../config/basic.hpp"
#include "../type_traits.hpp"
#include <cstddef>
#include <vector>

namespace eagine {
namespace ecs {

// component unique identifier
typedef std::size_t component_uid_t;

// component_uid_getter
class component_uid_getter
{
private:
	static component_uid_t& _curr_uid(void);
public:
	static component_uid_t new_uid(void);
};

// component_uid
template <typename Derived>
struct component_uid
{
	static component_uid_t value(void)
	{
		static component_uid_t cid = component_uid_getter::new_uid();
		return cid;
	}

	component_uid_t operator()(void) const
	{
		return value();
	}
};

// component - base class
template <typename Derived>
struct component
{
	static component_uid<Derived> _uid;
};

template <typename Derived>
component_uid<Derived> component<Derived>::_uid = {};

// get_component_uid
template <typename X>
static inline
component_uid_t get_component_uid(void)
{
	typedef std::remove_const_t<std::remove_reference_t<X>> Component;
	return Component::_uid();
}

// component_uid_map
template <typename T>
class component_uid_map
{
private:
	std::vector<T> _storage;
public:
	component_uid_map(void) = default;

	typedef typename std::vector<T>::iterator iterator;
	typedef typename std::vector<T>::const_iterator const_iterator;
	typedef typename std::vector<T>::difference_type difference_type;

	const_iterator begin(void) const
	{
		return _storage.begin();
	}

	iterator begin(void)
	{
		return _storage.begin();
	}

	const_iterator end(void) const
	{
		return _storage.end();
	}

	iterator end(void)
	{
		return _storage.end();
	}

	const_iterator
	find(component_uid_t cid) const
	{
		if(cid < _storage.size())
		{
			return _storage.begin()+difference_type(cid);
		}
		else return _storage.end();
	}

	iterator
	find(component_uid_t cid)
	{
		if(cid < _storage.size())
		{
			return _storage.begin()+difference_type(cid);
		}
		else return _storage.end();
	}

	void erase(iterator pos)
	{
		*pos = T();
	}

	T& operator [] (component_uid_t cid)
	{
		if(cid >= _storage.size())
		{
			_storage.resize(cid+1);
		}
		return _storage[cid];
	}
};

} // namespace ecs
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/ecs/component.inl>
#endif

#endif //include guard

