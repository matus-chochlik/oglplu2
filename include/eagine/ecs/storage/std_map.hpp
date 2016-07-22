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

#include "../cmp_storage.hpp"
#include "../rel_storage.hpp"
#include <set>
#include <map>
#include <cassert>

namespace eagine {
namespace ecs {

template <typename Entity, typename Component>
class std_map_cmp_storage;

template <typename Entity, typename Component>
class std_map_cmp_storage_iterator
 : public component_storage_iterator_intf<Entity>
{
private:
	typedef typename std::map<Entity, Component> _map_t;
	typedef typename _map_t::iterator _iter_t;
	_map_t* _map;
	_iter_t _i;

	friend class std_map_cmp_storage<Entity, Component>;
public:
	std_map_cmp_storage_iterator(_map_t& m)
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
class std_map_cmp_storage
 : public component_storage<Entity, Component>
{
private:
	std::map<Entity, Component> _components;
	std::set<Entity> _hidden;

	typedef std_map_cmp_storage_iterator<Entity, Component> _map_iter_t;

	_map_iter_t& _iter_cast(component_storage_iterator<Entity>& i)
	noexcept
	{
		assert(dynamic_cast<_map_iter_t*>(i.ptr()) != nullptr);
		return *static_cast<_map_iter_t*>(i.ptr());
	}

	Entity _iter_entity(component_storage_iterator<Entity>& i)
	noexcept
	{
		return _iter_cast(i)._i->first;
	}
public:
	typedef entity_param_t<Entity> entity_param;
	typedef component_storage_iterator<Entity> iterator_t;

	storage_caps capabilities(void)
	override
	{
		return storage_caps{
			storage_cap_bit::hide|
			storage_cap_bit::remove|
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
		assert(!i.done());
		return is_hidden(_iter_entity(i));
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

	void hide(iterator_t& i)
	override
	{
		assert(!i.done());
		_hidden.insert(_iter_entity(i));
	}

	bool show(entity_param e)
	override
	{
		return _hidden.erase(e) > 0;
	}

	bool show(iterator_t& i)
	override
	{
		return _hidden.erase(_iter_entity(i)) > 0;
	}

	bool copy(entity_param ef, entity_param et)
	override
	{
		if(is_hidden(ef)) return false;
		auto pf = _components.find(ef);
		if(pf == _components.end()) return false;
		return store(et, Component(pf->second));
	}

	bool swap(entity_param ea, entity_param eb)
	override
	{
		auto pa = _components.find(ea);
		auto pb = _components.find(eb);
		bool ha = is_hidden(ea);
		bool hb = is_hidden(eb);

		if(pa != _components.end() && pb != _components.end())
		{
			using std::swap;
			swap(pa->second, pb->second);
			if(ha && !hb) show(ea);
			if(hb && !ha) show(eb);
		}
		else if(pa != _components.end())
		{
			store(eb, std::move(pa->second));
			remove(ea);
			if(ha) hide(eb);
		}
		else if(pb != _components.end())
		{
			store(ea, std::move(pb->second));
			remove(eb);
			if(hb) hide(ea);
		}
		return true;
	}

	bool remove(entity_param e)
	override
	{
		_hidden.erase(e);
		return _components.erase(e) > 0;
	}

	bool store(entity_param e, Component&& c)
	override
	{
		_hidden.erase(e);
		_components.emplace(e, std::move(c));
		return true;
	}

	void for_single(
		callable_ref<
			void(entity_param, manipulator<const Component>&)
		> func,
		entity_param e
	) override
	{
		auto p = _components.find(e);
		if(p != _components.end())
		{
			if(!is_hidden(e))
			{
				manipulator<const Component> m(p->second);
				func(p->first, m);
			}
		}
	}

	void for_single(
		callable_ref<
			void(entity_param, manipulator<const Component>&)
		> func,
		iterator_t& i
	) override
	{
		assert(!i.done());
		auto p = _iter_cast(i)._i;
		assert(p != _components.end());
		if(!is_hidden(p->first))
		{
			manipulator<const Component> m(p->second);
			func(p->first, m);
		}
	}

	void for_single(
		callable_ref<void(entity_param, manipulator<Component>&)> f,
		entity_param e
	) override
	{
		auto p = _components.find(e);
		if(p != _components.end())
		{
			if(!is_hidden(e))
			{
				// TODO: modify notification
				manipulator<Component> m(p->second);
				f(p->first, m);
			}
		}
	}

	void for_single(
		callable_ref<void(entity_param, manipulator<Component>&)> f,
		iterator_t& i
	) override
	{
		assert(!i.done());
		auto p = _iter_cast(i)._i;
		assert(p != _components.end());
		if(!is_hidden(p->first))
		{
			// TODO: modify notification
			manipulator<Component> m(p->second);
			f(p->first, m);
		}
	}

	void for_each(
		callable_ref<
			void(entity_param, manipulator<const Component>&)
		> func
	) override
	{
		manipulator<const Component> m;
		for(auto& p : _components)
		{
			if(!is_hidden(p.first))
			{
				m.reset(p.second);
				func(p.first, m);
			}
		}
	}

	void for_each(
		callable_ref<void(entity_param, manipulator<Component>&)> func
	) override
	{
		manipulator<Component> m;
		for(auto& p : _components)
		{
			if(!is_hidden(p.first))
			{
				// TODO: modify notification
				m.reset(p.second);
				func(p.first, m);
			}
		}
	}
};

template <typename Entity, typename Relation>
class std_map_rel_storage;

template <typename Entity, typename Relation>
class std_map_rel_storage_iterator
 : public relation_storage_iterator_intf<Entity>
{
private:
	typedef std::pair<Entity, Entity> _pair_t;
	typedef typename std::map<_pair_t, Relation> _map_t;
	typedef typename _map_t::iterator _iter_t;
	_map_t* _map;
	_iter_t _i;

	friend class std_map_rel_storage<Entity, Relation>;
public:
	std_map_rel_storage_iterator(_map_t& m)
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

	Entity parent(void)
	override
	{
		return _i->first.first;
	}

	Entity child(void)
	override
	{
		return _i->first.second;
	}
};

template <typename Entity, typename Relation>
class std_map_rel_storage
 : public relation_storage<Entity, Relation>
{
private:
	typedef std::pair<Entity, Entity> _pair_t;
	std::map<_pair_t, Relation> _relations;

	typedef std_map_rel_storage_iterator<_pair_t, Relation> _map_iter_t;

	_map_iter_t& _iter_cast(relation_storage_iterator<Entity>& i)
	noexcept
	{
		assert(dynamic_cast<_map_iter_t*>(i.ptr()) != nullptr);
		return *static_cast<_map_iter_t*>(i.ptr());
	}
public:
	typedef entity_param_t<Entity> entity_param;
	typedef component_storage_iterator<Entity> iterator_t;

	storage_caps capabilities(void)
	override
	{
		return storage_caps{
			storage_cap_bit::remove|
			storage_cap_bit::store|
			storage_cap_bit::modify
		};
	}

	iterator_t new_iterator(void)
	override
	{
		return iterator_t(new _map_iter_t(_relations));
	}

	void delete_iterator(iterator_t&& i)
	override
	{
		delete i.release();
	}

	bool has(entity_param p, entity_param c)
	override
	{
		return _relations.find(_pair_t(p, c)) != _relations.end();
	}

	bool store(entity_param p, entity_param c)
	override
	{
		_relations.emplace(_pair_t(p, c), Relation());
		return true;
	}

	bool store(entity_param p, entity_param c, Relation&& r)
	override
	{
		_relations.emplace(_pair_t(p, c), std::move(r));
		return true;
	}

	bool remove(entity_param p, entity_param c)
	override
	{
		return _relations.erase(_pair_t(p, c)) > 0;
	}

	void for_single(
		callable_ref<void(entity_param,entity_param, const Relation&)>,
		entity_param pa, entity_param ch
	) override
	{
		auto po = _relations.find(_pair_t(pa, ch));
		if(po != _relations.end())
		{
			manipulator<const Relation> m(po->second);
			func(po->first.first, po->first.second, m);
		}
	}

	void for_single(
		callable_ref<void(entity_param,entity_param, const Relation&)>,
		iterator_t& i
	) override
	{
		assert(!i.done());
		auto po = _iter_cast(i)._i;
		assert(po != _relations.end());

		manipulator<const Relation> m(po->second);
		f(po->first.first, po->first.second, m);
	}

	void for_single(
		callable_ref<void(entity_param,entity_param, Relation&)>,
		entity_param pa, entity_param ch
	) override
	{
		auto po = _relations.find(_pair_t(pa, ch));
		if(po != _relations.end())
		{
			// TODO: modify notification
			manipulator<Relation> m(po->second);
			func(po->first.first, po->first.second, m);
		}
	}

	void for_single(
		callable_ref<void(entity_param,entity_param, Relation&)>,
		iterator_t& i
	) override
	{
		assert(!i.done());
		auto po = _iter_cast(i)._i;
		assert(po != _relations.end());

		// TODO: modify notification
		manipulator<Relation> m(po->second);
		f(po->first.first, po->first.second, m);
	}

	void for_each(
		callable_ref<void(entity_param,entity_param, const Relation&)>
	) override
	{
		manipulator<const Relation> m;
		for(auto& p : _relations)
		{
			m.reset(p.second);
			func(p.first.first, p.first.second, m);
		}
	}

	void for_each(
		callable_ref<void(entity_param,entity_param, Relation&)>
	) override
	{
		manipulator<Relation> m;
		for(auto& p : _relations)
		{
			// TODO: modify notification
			m.reset(p.second);
			func(p.first.first, p.first.second, m);
		}
	}
};

} // namespace ecs
} // namespace eagine

#endif //include guard

