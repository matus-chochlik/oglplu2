/**
 *  @file eagine/ecs/storage/std_map.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_STORAGE_STD_MAP_1509260923_HPP
#define EAGINE_ECS_STORAGE_STD_MAP_1509260923_HPP

#include "../storage.hpp"
#include <set>
#include <map>
#include <cassert>

namespace eagine {
namespace ecs {

template <typename Entity, typename Component>
class std_map_storage;

template <typename Entity, typename Component>
class std_map_storage_iterator
 : public storage_iterator_intf<Entity>
{
private:
	typedef typename std::map<Entity, Component> _map_t;
	typedef typename _map_t::iterator _iter_t;
	_map_t* _map;
	_iter_t _i;

	friend class std_map_storage<Entity, Component>;
public:
	std_map_storage_iterator(_map_t& m)
	noexcept
	 : _map(&m)
	 , _i(m.begin())
	{
		assert(_map);
	}

	void reset(void)
	override
	{
		assert(_map);
		_i = _map->begin();
	}

	bool done(void)
	override
	{
		assert(_map);
		return _i == _map->end();
	}

	void next(void)
	override
	{
		assert(!done());
		++_i;
	}

	bool find(Entity e)
	override
	{
		if(done()) return false;
		if(e == _i->first) return true;
		if(e <  _i->first) return false;

		while(++_i != _map->end())
		{
			if(_i->first == e) return true;
		}
		return false;
	}

	Entity current(void)
	override
	{
		return _i->first;
	}
};

template <typename Entity, typename Component>
class std_map_storage
 : public component_storage<Entity, Component>
{
private:
	std::pair<Entity, Component> _p_t;
	std::map<Entity, Component> _components;
	std::set<Entity> _hidden;

	typedef std_map_storage_iterator<Entity, Component> _map_iter_t;
	_map_iter_t& _iter_cast(storage_iterator<Entity>& i)
	{
		assert(dynamic_cast<_map_iter_t*>(i.ptr()) != nullptr);
		return *static_cast<_map_iter_t*>(i.ptr());
	}
public:
	typedef entity_param_t<Entity> entity_param;
	typedef storage_iterator<Entity> iterator_t;

	storage_caps capabilities(void)
	override
	{
		return storage_caps{
			storage_cap_bit::hide|
			storage_cap_bit::erase|
			storage_cap_bit::store|
			storage_cap_bit::modify
		};
	}

	iterator_t new_iterator(void)
	override
	{
		return iterator_t(new _map_iter_t(_components));
	}

	void delete_iterator(iterator_t&& i)
	override
	{
		delete i.release();
	}

	bool has(entity_param e)
	override
	{
		return _components.find(e) != _components.end();
	}

	bool is_hidden(entity_param e)
	override
	{
		return _hidden.find(e) != _hidden.end();
	}

	bool is_hidden(iterator_t& i)
	override
	{
		return is_hidden(_iter_cast(i)._i->first);
	}

	bool hide(entity_param e)
	override
	{
		if(has(e))
		{
			_hidden.insert(e);
			return true;
		}
		return false;
	}

	bool show(entity_param e)
	override
	{
		return _hidden.erase(e) > 0;
	}

	bool erase(entity_param e)
	override
	{
		_hidden.erase(e);
		return _components.erase(e) > 0;
	}

	bool store(entity_param e, Component&& c)
	override
	{
		_components.emplace(e, std::move(c));
		return true;
	}

	bool read_with(
		entity_param e,
		callable_ref<bool(entity_param, const Component&)> f
	) override
	{
		auto p = _components.find(e);
		if(p != _components.end())
		{
			if(!is_hidden(e))
			{
				return f(p->first, p->second);
			}
		}
		return false;
	}

	bool read_with(
		iterator_t& i,
		callable_ref<bool(entity_param, const Component&)> f
	) override
	{
		assert(!i.done());
		auto p = _iter_cast(i)._i;
		assert(p != _components.end());
		if(!is_hidden(p->first))
		{
			return f(p->first, p->second);
		}
		return false;
	}

	bool modify_with(
		entity_param e,
		callable_ref<bool(entity_param, Component&)> f
	) override
	{
		auto p = _components.find(e);
		if(p != _components.end())
		{
			if(!is_hidden(e))
			{
				return f(p->first, p->second);
			}
		}
		return false;
	}

	void read_each_with(callable_ref<bool(entity_param,const Component&)> f)
	override
	{
		for(auto& p : _components)
		{
			if(!is_hidden(p.first))
			{
				f(p.first, p.second);
			}
		}
	}

	void modify_each_with(callable_ref<bool(entity_param, Component&)>f)
	override
	{
		for(auto& p : _components)
		{
			if(!is_hidden(p.first))
			{
				f(p.first, p.second);
			}
		}
	}
};

} // namespace ecs
} // namespace eagine

#endif //include guard

