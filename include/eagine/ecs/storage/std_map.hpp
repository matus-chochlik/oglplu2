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
#include <cassert>
#include <map>
#include <set>

namespace eagine {
namespace ecs {

template <typename Entity, typename Component>
class std_map_cmp_storage;

template <typename Entity, typename Component>
class std_map_cmp_storage_iterator
  : public component_storage_iterator_intf<Entity> {
private:
    typedef typename std::map<Entity, Component> _map_t;
    typedef typename _map_t::iterator _iter_t;
    _map_t* _map;
    _iter_t _i;

    friend class std_map_cmp_storage<Entity, Component>;

public:
    std_map_cmp_storage_iterator(_map_t& m) noexcept
      : _map(&m)
      , _i(m.begin()) {
        assert(_map);
    }

    void reset() override {
        assert(_map);
        _i = _map->begin();
    }

    bool done() override {
        assert(_map);
        return _i == _map->end();
    }

    void next() override {
        assert(!done());
        ++_i;
    }

    bool find(Entity e) override {
        if(done())
            return false;
        if(e == _i->first)
            return true;
        if(e < _i->first)
            return false;

        while(++_i != _map->end()) {
            if(_i->first == e)
                return true;
        }
        return false;
    }

    Entity current() override {
        return _i->first;
    }
};

template <typename Entity, typename Component>
class std_map_cmp_storage : public component_storage<Entity, Component> {
private:
    std::map<Entity, Component> _components;
    std::set<Entity> _hidden;

    typedef std_map_cmp_storage_iterator<Entity, Component> _map_iter_t;

    _map_iter_t& _iter_cast(component_storage_iterator<Entity>& i) noexcept {
        assert(dynamic_cast<_map_iter_t*>(i.ptr()) != nullptr);
        return *static_cast<_map_iter_t*>(i.ptr());
    }

    Entity _iter_entity(component_storage_iterator<Entity>& i) noexcept {
        return _iter_cast(i)._i->first;
    }

    typename std::map<Entity, Component>::iterator
    _remove(typename std::map<Entity, Component>::iterator p) {
        assert(p != _components.end());
        _hidden.erase(p->first);
        return _components.erase(p);
    }

public:
    typedef entity_param_t<Entity> entity_param;
    typedef component_storage_iterator<Entity> iterator_t;

    storage_caps capabilities() override {
        return storage_caps{storage_cap_bit::hide | storage_cap_bit::remove |
                            storage_cap_bit::store | storage_cap_bit::modify};
    }

    iterator_t new_iterator() override {
        return iterator_t(new _map_iter_t(_components));
    }

    void delete_iterator(iterator_t&& i) override {
        delete i.release();
    }

    bool has(entity_param e) override {
        return _components.find(e) != _components.end();
    }

    bool is_hidden(entity_param e) override {
        return _hidden.find(e) != _hidden.end();
    }

    bool is_hidden(iterator_t& i) override {
        assert(!i.done());
        return is_hidden(_iter_entity(i));
    }

    bool hide(entity_param e) override {
        if(has(e)) {
            _hidden.insert(e);
            return true;
        }
        return false;
    }

    void hide(iterator_t& i) override {
        assert(!i.done());
        _hidden.insert(_iter_entity(i));
    }

    bool show(entity_param e) override {
        return _hidden.erase(e) > 0;
    }

    bool show(iterator_t& i) override {
        return _hidden.erase(_iter_entity(i)) > 0;
    }

    bool copy(entity_param ef, entity_param et) override {
        if(is_hidden(ef))
            return false;
        auto pf = _components.find(ef);
        if(pf == _components.end())
            return false;
        return store(et, Component(pf->second));
    }

    bool swap(entity_param ea, entity_param eb) override {
        auto pa = _components.find(ea);
        auto pb = _components.find(eb);
        bool ha = is_hidden(ea);
        bool hb = is_hidden(eb);

        if(pa != _components.end() && pb != _components.end()) {
            using std::swap;
            swap(pa->second, pb->second);
            if(ha && !hb)
                show(ea);
            if(hb && !ha)
                show(eb);
        } else if(pa != _components.end()) {
            store(eb, std::move(pa->second));
            remove(ea);
            if(ha)
                hide(eb);
        } else if(pb != _components.end()) {
            store(ea, std::move(pb->second));
            remove(eb);
            if(hb)
                hide(ea);
        }
        return true;
    }

    bool remove(entity_param e) override {
        _hidden.erase(e);
        return _components.erase(e) > 0;
    }

    void remove(iterator_t& i) override {
        assert(!i.done());
        _hidden.erase(_iter_entity(i));
        _iter_cast(i)._i = _components.erase(_iter_cast(i)._i);
    }

    bool store(entity_param e, Component&& c) override {
        _hidden.erase(e);
        _components.emplace(e, std::move(c));
        return true;
    }

    bool store(iterator_t& i, entity_param e, Component&& c) override {
        _hidden.erase(e);
        auto& p = _iter_cast(i)._i;
        p = _components.emplace_hint(p, e, std::move(c));
        return true;
    }

    void for_single(
      callable_ref<void(entity_param, manipulator<const Component>&)> func,
      entity_param e) override {
        auto p = _components.find(e);
        if(p != _components.end()) {
            if(!is_hidden(e)) {
                concrete_manipulator<const Component> m(
                  p->second, true /*can_remove*/
                );
                func(p->first, m);
                if(m.remove_requested()) {
                    _remove(p);
                }
            }
        }
    }

    void for_single(
      callable_ref<void(entity_param, manipulator<const Component>&)> func,
      iterator_t& i) override {
        assert(!i.done());
        auto& p = _iter_cast(i)._i;
        assert(p != _components.end());
        if(!is_hidden(p->first)) {
            concrete_manipulator<const Component> m(
              p->second, true /*can_remove*/
            );
            func(p->first, m);
            if(m.remove_requested()) {
                p = _remove(p);
            }
        }
    }

    void for_single(
      callable_ref<void(entity_param, manipulator<Component>&)> func,
      entity_param e) override {
        auto p = _components.find(e);
        if(p != _components.end()) {
            if(!is_hidden(e)) {
                // TODO: modify notification
                concrete_manipulator<Component> m(
                  p->second, true /*can_remove*/
                );
                func(p->first, m);
                if(m.remove_requested()) {
                    _remove(p);
                }
            }
        }
    }

    void for_single(
      callable_ref<void(entity_param, manipulator<Component>&)> func,
      iterator_t& i) override {
        assert(!i.done());
        auto& p = _iter_cast(i)._i;
        assert(p != _components.end());
        if(!is_hidden(p->first)) {
            // TODO: modify notification
            concrete_manipulator<Component> m(
              p->second, true /*can_remove*/
            );
            func(p->first, m);
            if(m.remove_requested()) {
                p = _remove(p);
            }
        }
    }

    void
    for_each(callable_ref<void(entity_param, manipulator<const Component>&)>
               func) override {
        concrete_manipulator<const Component> m(true /*can_remove*/);
        auto p = _components.begin();
        while(p != _components.end()) {
            if(!is_hidden(p->first)) {
                m.reset(p->second);
                func(p->first, m);
                if(m.remove_requested()) {
                    p = _remove(p);
                } else
                    ++p;
            } else
                ++p;
        }
    }

    void for_each(
      callable_ref<void(entity_param, manipulator<Component>&)> func) override {
        concrete_manipulator<Component> m(true /*can_remove*/);
        auto p = _components.begin();
        while(p != _components.end()) {
            if(!is_hidden(p->first)) {
                // TODO: modify notification
                m.reset(p->second);
                func(p->first, m);
                if(m.remove_requested()) {
                    p = _remove(p);
                } else
                    ++p;
            } else
                ++p;
        }
    }
};

template <typename Entity, typename Relation>
class std_map_rel_storage;

template <typename Entity, typename Relation>
class std_map_rel_storage_iterator
  : public relation_storage_iterator_intf<Entity> {
private:
    typedef std::pair<Entity, Entity> _pair_t;
    typedef typename std::map<_pair_t, Relation> _map_t;
    typedef typename _map_t::iterator _iter_t;
    _map_t* _map;
    _iter_t _i;

    friend class std_map_rel_storage<Entity, Relation>;

public:
    std_map_rel_storage_iterator(_map_t& m) noexcept
      : _map(&m)
      , _i(m.begin()) {
        assert(_map);
    }

    void reset() override {
        assert(_map);
        _i = _map->begin();
    }

    bool done() override {
        assert(_map);
        return _i == _map->end();
    }

    void next() override {
        assert(!done());
        ++_i;
    }

    Entity subject() override {
        return _i->first.first;
    }

    Entity object() override {
        return _i->first.second;
    }
};

template <typename Entity, typename Relation>
class std_map_rel_storage : public relation_storage<Entity, Relation> {
private:
    typedef std::pair<Entity, Entity> _pair_t;
    std::map<_pair_t, Relation> _relations;

    typedef std_map_rel_storage_iterator<Entity, Relation> _map_iter_t;

    _map_iter_t& _iter_cast(relation_storage_iterator<Entity>& i) noexcept {
        assert(dynamic_cast<_map_iter_t*>(i.ptr()) != nullptr);
        return *static_cast<_map_iter_t*>(i.ptr());
    }

    typename std::map<_pair_t, Relation>::iterator
    _remove(typename std::map<_pair_t, Relation>::iterator p) {
        assert(p != _relations.end());
        return _relations.erase(p);
    }

public:
    typedef entity_param_t<Entity> entity_param;
    typedef relation_storage_iterator<Entity> iterator_t;

    storage_caps capabilities() override {
        return storage_caps{storage_cap_bit::remove | storage_cap_bit::store |
                            storage_cap_bit::modify};
    }

    iterator_t new_iterator() override {
        return iterator_t(new _map_iter_t(_relations));
    }

    void delete_iterator(iterator_t&& i) override {
        delete i.release();
    }

    bool has(entity_param s, entity_param o) override {
        return _relations.find(_pair_t(s, o)) != _relations.end();
    }

    bool store(entity_param s, entity_param o) override {
        _relations.emplace(_pair_t(s, o), Relation());
        return true;
    }

    bool store(entity_param s, entity_param o, Relation&& r) override {
        _relations.emplace(_pair_t(s, o), std::move(r));
        return true;
    }

    bool remove(entity_param s, entity_param o) override {
        return _relations.erase(_pair_t(s, o)) > 0;
    }

    void remove(iterator_t& i) override {
        assert(!i.done());
        _iter_cast(i)._i = _relations.erase(_iter_cast(i)._i);
    }

    void for_single(
      callable_ref<
        void(entity_param, entity_param, manipulator<const Relation>&)> func,
      entity_param subject,
      entity_param object) override {
        auto po = _relations.find(_pair_t(subject, object));
        if(po != _relations.end()) {
            concrete_manipulator<const Relation> m(
              po->second, true /*can_erase*/
            );
            func(po->first.first, po->first.second, m);
            if(m.remove_requested()) {
                _remove(po);
            }
        }
    }

    void for_single(
      callable_ref<
        void(entity_param, entity_param, manipulator<const Relation>&)> func,
      iterator_t& i) override {
        assert(!i.done());
        auto& po = _iter_cast(i)._i;
        assert(po != _relations.end());

        concrete_manipulator<const Relation> m(
          po->second, true /*can_erase*/
        );
        func(po->first.first, po->first.second, m);
        if(m.remove_requested()) {
            po = _remove(po);
        }
    }

    void for_single(
      callable_ref<void(entity_param, entity_param, manipulator<Relation>&)>
        func,
      entity_param subject,
      entity_param object) override {
        auto po = _relations.find(_pair_t(subject, object));
        if(po != _relations.end()) {
            // TODO: modify notification
            concrete_manipulator<Relation> m(
              po->second, true /*can_erase*/
            );
            func(po->first.first, po->first.second, m);
            if(m.remove_requested()) {
                _remove(po);
            }
        }
    }

    void for_single(
      callable_ref<void(entity_param, entity_param, manipulator<Relation>&)>
        func,
      iterator_t& i) override {
        assert(!i.done());
        auto& po = _iter_cast(i)._i;
        assert(po != _relations.end());

        // TODO: modify notification
        concrete_manipulator<Relation> m(
          po->second, true /*can_erase*/
        );
        func(po->first.first, po->first.second, m);
        if(m.remove_requested()) {
            po = _remove(po);
        }
    }

    void for_each(
      callable_ref<void(entity_param, entity_param)> func,
      entity_param subject) override {
        entity_param object = entity_traits<Entity>::minimum();
        auto po = _relations.lower_bound(_pair_t(subject, object));
        while((po != _relations.end()) && (po->first.first == subject)) {
            func(subject, po->first.second);
            ++po;
        }
    }

    void
    for_each(callable_ref<void(entity_param, entity_param)> func) override {
        for(auto& p : _relations) {
            func(p.first.first, p.first.second);
        }
    }

    void for_each(
      callable_ref<
        void(entity_param, entity_param, manipulator<const Relation>&)> func,
      entity_param subject) override {
        concrete_manipulator<const Relation> m(true /*can_remove*/);
        entity_param object = entity_traits<Entity>::minimum();
        auto po = _relations.lower_bound(_pair_t(subject, object));
        while((po != _relations.end()) && (po->first.first == subject)) {
            m.reset(po->second);
            func(subject, po->first.second, m);
            if(m.remove_requested()) {
                po = _remove(po);
            } else
                ++po;
        }
    }

    void for_each(
      callable_ref<void(entity_param, entity_param, manipulator<Relation>&)>
        func,
      entity_param subject) override {
        concrete_manipulator<Relation> m(true /*can_remove*/);
        entity_param object = entity_traits<Entity>::minimum();
        auto po = _relations.lower_bound(_pair_t(subject, object));
        while((po != _relations.end()) && (po->first.first == subject)) {
            // TODO: modify notification
            m.reset(po->second);
            func(subject, po->first.second, m);
            if(m.remove_requested()) {
                po = _remove(po);
            } else
                ++po;
        }
    }

    void
    for_each(callable_ref<void(
               entity_param, entity_param, manipulator<const Relation>&)> func)
      override {
        concrete_manipulator<const Relation> m(true /*can_remove*/);
        auto po = _relations.begin();
        while(po != _relations.end()) {
            m.reset(po->second);
            func(po->first.first, po->first.second, m);
            if(m.remove_requested()) {
                po = _remove(po);
            } else
                ++po;
        }
    }

    void for_each(
      callable_ref<void(entity_param, entity_param, manipulator<Relation>&)>
        func) override {
        concrete_manipulator<Relation> m(true /*can_remove*/);
        auto po = _relations.begin();
        while(po != _relations.end()) {
            // TODO: modify notification
            m.reset(po->second);
            func(po->first.first, po->first.second, m);
            if(m.remove_requested()) {
                po = _remove(po);
            } else
                ++po;
        }
    }
};

} // namespace ecs
} // namespace eagine

#endif // include guard
