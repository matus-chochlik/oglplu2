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

namespace eagine {
namespace ecs {

template <typename Entity, typename Component>
class std_map_storage
 : public component_storage<Entity, Component>
{
private:
	std::pair<Entity, Component> _p_t;
	std::map<Entity, Component> _components;
	std::set<Entity> _hidden;
public:
	typedef entity_param_t<Entity> entity_param;

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
};

} // namespace ecs
} // namespace eagine

#endif //include guard

