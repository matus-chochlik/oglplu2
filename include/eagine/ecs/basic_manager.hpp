/**
 *  @file eagine/ecs/basic_manager.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_BASIC_MANAGER_HPP
#define EAGINE_ECS_BASIC_MANAGER_HPP

#include "../mp_list.hpp"
#include "../type_name.hpp"
#include "cmp_storage.hpp"
#include "component.hpp"
#include "entity_traits.hpp"
#include <memory>
#include <type_traits>

namespace eagine::ecs {
//------------------------------------------------------------------------------
template <typename Entity>
class basic_manager;
//------------------------------------------------------------------------------
template <typename Entity, typename PL>
class component_relation;

template <typename Entity, typename... PL>
class component_relation<Entity, mp_list<PL...>> {
private:
    basic_manager<Entity>& _m;

    template <typename F, typename... C, typename... X>
    static inline auto _apply(
      basic_manager<Entity>& m,
      const F& func,
      mp_list<mp_list<C...>>,
      X&&... x) {
        callable_ref<void(entity_param_t<Entity>, manipulator<C> & ...)> w(
          [&func, &x...](entity_param_t<Entity> e, manipulator<C>&... c) {
              func(std::forward<X>(x)..., e, c...);
          });
        m.for_each(w);
    }

    template <
      typename F,
      typename... C,
      typename L,
      typename... Ls,
      typename... X>
    static inline auto _apply(
      basic_manager<Entity>& m,
      const F& func,
      mp_list<mp_list<C...>, L, Ls...>,
      X&&... x) {
        callable_ref<void(entity_param_t<Entity>, manipulator<C> & ...)> w(
          [&m, &func, &x...](entity_param_t<Entity> e, manipulator<C>&... c) {
              _apply(
                m, func, mp_list<L, Ls...>(), std::forward<X>(x)..., e, c...);
          });
        m.for_each(w);
    }

public:
    component_relation(basic_manager<Entity>& m)
      : _m(m) {
    }

    template <typename... C>
    component_relation<Entity, mp_list<PL..., mp_list<C...>>> cross() {
        return {_m};
    }

    template <typename Func>
    void for_each(const Func& func) {
        _apply(_m, func, mp_list<PL...>());
    }
};
//------------------------------------------------------------------------------
template <typename Entity>
class basic_manager {
public:
    using entity_param = entity_param_t<Entity>;

private:
    using _base_cmp_storage_t = base_component_storage<Entity>;
    using _base_cmp_storage_ptr_t = std::unique_ptr<_base_cmp_storage_t>;

    component_uid_map<_base_cmp_storage_ptr_t> _cmp_storages{};

    component_uid_map<_base_cmp_storage_ptr_t>& _get_storages(
      std::false_type) noexcept {
        return _cmp_storages;
    }

    const component_uid_map<_base_cmp_storage_ptr_t>& _get_storages(
      std::false_type) const noexcept {
        return _cmp_storages;
    }

    using _base_rel_storage_t = base_relation_storage<Entity>;
    using _base_rel_storage_ptr_t = std::unique_ptr<_base_rel_storage_t>;

    component_uid_map<_base_rel_storage_ptr_t> _rel_storages{};

    component_uid_map<_base_rel_storage_ptr_t>& _get_storages(
      std::true_type) noexcept {
        return _rel_storages;
    }

    const component_uid_map<_base_rel_storage_ptr_t>& _get_storages(
      std::true_type) const noexcept {
        return _rel_storages;
    }

    template <bool IsR>
    component_uid_map<std::unique_ptr<base_storage<Entity, IsR>>>&
    _get_storages() noexcept {
        return _get_storages(std::integral_constant<bool, IsR>());
    }

    template <bool IsR>
    const component_uid_map<std::unique_ptr<base_storage<Entity, IsR>>>&
    _get_storages() const noexcept {
        return _get_storages(std::integral_constant<bool, IsR>());
    }

    template <typename C>
    using _bare_t = std::remove_const_t<std::remove_reference_t<C>>;

    static constexpr inline unsigned _count_true() {
        return 0;
    }

    template <typename T, typename... P>
    static constexpr unsigned _count_true(T v, P... p) {
        return (bool(v) ? 1 : 0) + _count_true(p...);
    }

    template <typename C>
    static inline std::string (*_cmp_name_getter())() {
        return &type_name<C>;
    }

    template <typename Data, bool IsR>
    storage<Entity, Data, IsR>& _find_storage();

    template <typename C>
    component_storage<Entity, C>& _find_cmp_storage() {
        return _find_storage<C, false>();
    }

    template <typename R>
    relation_storage<Entity, R>& _find_rel_storage() {
        return _find_storage<R, true>();
    }

    template <bool IsR>
    void _do_reg_stg_type(
      std::unique_ptr<base_storage<Entity, IsR>>&&,
      component_uid_t,
      std::string (*)());

    template <bool IsR>
    void _do_unr_stg_type(component_uid_t, std::string (*)());

    template <bool IsR>
    bool _does_know_stg_type(component_uid_t) const;

    template <bool IsR, typename Result, typename Func>
    Result _apply_on_base_stg(
      Result, const Func&, component_uid_t, std::string (*)()) const;

    template <typename D, bool IsR, typename Result, typename Func>
    Result _apply_on_stg(Result, const Func&) const;

    template <bool IsR>
    storage_caps _get_stg_type_caps(component_uid_t, std::string (*)()) const;

    bool _does_have_c(entity_param, component_uid_t, std::string (*)());

    bool _does_have_r(
      entity_param, entity_param, component_uid_t, std::string (*)());

    bool _is_hidn(entity_param, component_uid_t, std::string (*)());

    bool _do_show(entity_param, component_uid_t, std::string (*)());

    bool _do_hide(entity_param, component_uid_t, std::string (*)());

    template <typename Component>
    bool _do_add_c(entity_param, Component&& component);

    template <typename Relation>
    bool _do_add_r(entity_param, entity_param, Relation&& relation);

    bool _do_add_r(
      entity_param, entity_param, component_uid_t, std::string (*)());

    bool _do_cpy(
      entity_param f, entity_param t, component_uid_t, std::string (*)());

    bool _do_swp(
      entity_param f, entity_param t, component_uid_t, std::string (*)());

    bool _do_rem_c(entity_param, component_uid_t, std::string (*)());

    bool _do_rem_r(
      entity_param, entity_param, component_uid_t, std::string (*)());

    template <typename C, typename Func>
    bool _call_for_single_c(entity_param, const Func&);

    template <typename C, typename Func>
    void _call_for_each_c(const Func&);

    template <typename R, typename Func>
    void _call_for_each_r(const Func&);

    template <typename... C, typename Func>
    void _call_for_each_c_m_p(const Func&);

    template <typename... C, typename Func>
    void _call_for_each_c_m_r(const Func&);

    template <typename T, typename C>
    T _do_get_c(T C::*, entity_param, T);

public:
    basic_manager() = default;

    template <typename Component>
    void register_component_type(
      std::unique_ptr<component_storage<Entity, Component>>&& storage) {
        _do_reg_stg_type<false>(
          _base_cmp_storage_ptr_t(std::move(storage)),
          Component::uid(),
          _cmp_name_getter<Component>());
    }

    template <typename Relation>
    void register_relation_type(
      std::unique_ptr<relation_storage<Entity, Relation>>&& storage) {
        _do_reg_stg_type<true>(
          _base_rel_storage_ptr_t(std::move(storage)),
          Relation::uid(),
          _cmp_name_getter<Relation>());
    }

    template <
      template <class, class>
      class Storage,
      typename Component,
      typename... P>
    void register_component_storage(P&&... p) {
        register_component_type<Component>(
          std::make_unique<Storage<Entity, Component>>(std::forward<P>(p)...));
    }

    template <
      template <class, class>
      class Storage,
      typename Relation,
      typename... P>
    void register_relation_storage(P&&... p) {
        register_relation_type<Relation>(
          std::make_unique<Storage<Entity, Relation>>(std::forward<P>(p)...));
    }

    template <typename Component>
    void unregister_component_type() {
        _do_unr_stg_type<false>(
          Component::uid(), _cmp_name_getter<Component>());
    }

    template <typename Relation>
    void unregister_relation_type() {
        _do_unr_stg_type<true>(Relation::uid(), _cmp_name_getter<Relation>());
    }

    template <typename Component>
    bool knows_component_type() const {
        return _does_know_stg_type<false>(Component::uid());
    }

    template <typename Relation>
    bool knows_relation_type() const {
        return _does_know_stg_type<true>(Relation::uid());
    }

    template <typename Component>
    storage_caps component_storage_caps() const {
        return _get_stg_type_caps<false>(
          Component::uid(), _cmp_name_getter<Component>());
    }

    template <typename Relation>
    storage_caps relation_storage_caps() const {
        return _get_stg_type_caps<true>(
          Relation::uid(), _cmp_name_getter<Relation>());
    }

    template <typename Component>
    bool component_storage_can(storage_cap_bit cap) const {
        return _get_stg_type_caps<false>(
                 Component::uid(), _cmp_name_getter<Component>())
          .has(cap);
    }

    template <typename Relation>
    bool relation_storage_can(storage_cap_bit cap) const {
        return _get_stg_type_caps<true>(
                 Relation::uid(), _cmp_name_getter<Relation>())
          .has(cap);
    }

    void forget(entity_param ent);

    template <typename Component>
    bool has(entity_param ent) {
        return _does_have_c(
          ent, Component::uid(), _cmp_name_getter<Component>());
    }

    template <typename Relation>
    bool has(entity_param subject, entity_param object) {
        return _does_have_r(
          subject, object, Relation::uid(), _cmp_name_getter<Relation>());
    }

    template <typename... Components>
    bool has_all(entity_param ent) {
        return _count_true(_does_have_c(
                 ent, Components::uid(), _cmp_name_getter<Components>())...) ==
               (sizeof...(Components));
    }

    template <typename Component>
    bool hidden(entity_param ent) {
        return _is_hidn(ent, Component::uid(), _cmp_name_getter<Component>());
    }

    template <typename... Components>
    bool all_hidden(entity_param ent) {
        return _count_true(_is_hidn(
                 ent, Components::uid(), _cmp_name_getter<Components>())...) ==
               (sizeof...(Components));
    }

    template <typename... Components>
    basic_manager& show(entity_param ent) {
        (..., _do_show(ent, Components::uid(), _cmp_name_getter<Components>()));
        return *this;
    }

    template <typename... Components>
    basic_manager& hide(entity_param ent) {
        (..., _do_hide(ent, Components::uid(), _cmp_name_getter<Components>()));
        return *this;
    }

    template <typename... Components>
    basic_manager& add(entity_param ent, Components&&... components) {
        (..., _do_add_c(ent, std::move(components)));
        return *this;
    }

    template <typename Relation>
    basic_manager& add_relation(
      entity_param subject, entity_param object, Relation&& rel) {
        _do_add_r(subject, object, std::forward<Relation>(rel));
        return *this;
    }

    template <typename Relation>
    basic_manager& add_relation(entity_param subject, entity_param object) {
        _do_add_r(
          subject, object, Relation::uid(), _cmp_name_getter<Relation>());
        return *this;
    }

    template <typename... Components>
    basic_manager& copy(entity_param from, entity_param to) {
        (...,
         _do_cpy(from, to, Components::uid(), _cmp_name_getter<Components>()));
        return *this;
    }

    template <typename... Components>
    basic_manager& swap(entity_param e1, entity_param e2) {
        (...,
         _do_swp(e1, e2, Components::uid(), _cmp_name_getter<Components>()));
        return *this;
    }

    template <typename... Components>
    basic_manager& remove(entity_param ent) {
        (...,
         _do_rem_c(ent, Components::uid(), _cmp_name_getter<Components>()));
        return *this;
    }

    template <typename Relation>
    basic_manager& remove_relation(entity_param subject, entity_param object) {
        _do_rem_r(
          subject, object, Relation::uid(), _cmp_name_getter<Relation>());
        return *this;
    }

    template <typename T, typename Component>
    T get(T Component::*mvp, entity_param ent, T res = T()) {
        return _do_get_c(mvp, ent, res);
    }

    template <typename Component>
    basic_manager& for_single(
      const callable_ref<void(entity_param, manipulator<const Component>&)>&
        func,
      entity_param ent) {
        _call_for_single_c<Component>(func, ent);
        return *this;
    }

    template <typename Component>
    basic_manager& for_single(
      const callable_ref<void(entity_param, manipulator<Component>&)>& func,
      entity_param ent) {
        _call_for_single_c<Component>(func, ent);
        return *this;
    }

    template <typename Component>
    basic_manager& for_each(
      const callable_ref<void(entity_param, manipulator<const Component>&)>&
        func) {
        _call_for_each_c<Component>(func);
        return *this;
    }

    template <typename Component>
    basic_manager& for_each(
      const callable_ref<void(entity_param, manipulator<Component>&)>& func) {
        _call_for_each_c<Component>(func);
        return *this;
    }

    template <typename Relation>
    basic_manager& for_each(
      const callable_ref<void(entity_param, entity_param)>& func) {
        _call_for_each_r<Relation>(func);
        return *this;
    }

    template <typename Relation>
    basic_manager& for_each(
      const callable_ref<
        void(entity_param, entity_param, manipulator<const Relation>&)>& func) {
        _call_for_each_r<Relation>(func);
        return *this;
    }

    template <typename Relation>
    basic_manager& for_each(
      const callable_ref<
        void(entity_param, entity_param, manipulator<Relation>&)>& func) {
        _call_for_each_r<Relation>(func);
        return *this;
    }

    template <typename... Components>
    basic_manager& for_each_opt(
      const callable_ref<void(entity_param, manipulator<Components>&...)>&
        func) {
        _call_for_each_c_m_p<Components...>(func);
        return *this;
    }

    template <typename... Components, typename Func>
    basic_manager& for_each_with_opt(const Func& func) {
        callable_ref<void(entity_param, manipulator<Components> & ...)> wrap(
          func);
        return for_each_opt<Components...>(wrap);
    }

    template <typename... Components>
    std::enable_if_t<(sizeof...(Components) > 1), basic_manager&> for_each(
      const callable_ref<void(entity_param, manipulator<Components>&...)>&
        func) {
        _call_for_each_c_m_r<Components...>(func);
        return *this;
    }

    template <typename... Components, typename Func>
    basic_manager& for_each_with(const Func& func) {
        callable_ref<void(entity_param, manipulator<Components> & ...)> wrap(
          func);
        return for_each<Components...>(wrap);
    }

    template <typename... Components>
    component_relation<Entity, mp_list<mp_list<Components...>>> select() {
        return {*this};
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::ecs

#include <eagine/ecs/basic_manager.inl>

#endif // EAGINE_ECS_BASIC_MANAGER_HPP
