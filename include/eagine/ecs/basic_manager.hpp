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

    template <typename F, typename... C, typename L, typename... Ls, typename... X>
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
      : _m(m) {}

    template <typename... C>
    auto cross() -> component_relation<Entity, mp_list<PL..., mp_list<C...>>> {
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

    auto _get_storages(std::false_type) noexcept -> auto& {
        return _cmp_storages;
    }

    auto _get_storages(std::false_type) const noexcept -> auto& {
        return _cmp_storages;
    }

    using _base_rel_storage_t = base_relation_storage<Entity>;
    using _base_rel_storage_ptr_t = std::unique_ptr<_base_rel_storage_t>;

    component_uid_map<_base_rel_storage_ptr_t> _rel_storages{};

    auto _get_storages(std::true_type) noexcept -> auto& {
        return _rel_storages;
    }

    auto _get_storages(std::true_type) const noexcept -> auto& {
        return _rel_storages;
    }

    template <bool IsR>
    auto _get_storages() noexcept -> auto& {
        return _get_storages(std::integral_constant<bool, IsR>());
    }

    template <bool IsR>
    auto _get_storages() const noexcept -> auto& {
        return _get_storages(std::integral_constant<bool, IsR>());
    }

    template <typename C>
    using _bare_t = std::remove_const_t<std::remove_reference_t<C>>;

    static constexpr inline auto _count_true() -> unsigned {
        return 0U;
    }

    template <typename T, typename... P>
    static constexpr auto _count_true(T v, P... p) -> unsigned {
        return (bool(v) ? 1U : 0U) + _count_true(p...);
    }

    template <typename C>
    static auto _cmp_name_getter() -> std::string (*)() {
        return &type_name<C>;
    }

    template <typename Data, bool IsR>
    auto _find_storage() -> storage<Entity, Data, IsR>&;

    template <typename C>
    auto _find_cmp_storage() -> auto& {
        return _find_storage<C, false>();
    }

    template <typename R>
    auto _find_rel_storage() -> auto& {
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
    auto _does_know_stg_type(component_uid_t) const -> bool;

    template <bool IsR, typename Result, typename Func>
    auto
    _apply_on_base_stg(Result, const Func&, component_uid_t, std::string (*)())
      const -> Result;

    template <typename D, bool IsR, typename Result, typename Func>
    auto _apply_on_stg(Result, const Func&) const -> Result;

    template <bool IsR>
    auto _get_stg_type_caps(component_uid_t, std::string (*)()) const
      -> storage_caps;

    auto _does_have_c(entity_param, component_uid_t, std::string (*)()) -> bool;

    auto _does_have_r(
      entity_param,
      entity_param,
      component_uid_t,
      std::string (*)()) -> bool;

    auto _is_hidn(entity_param, component_uid_t, std::string (*)()) -> bool;

    auto _do_show(entity_param, component_uid_t, std::string (*)()) -> bool;

    auto _do_hide(entity_param, component_uid_t, std::string (*)()) -> bool;

    template <typename Component>
    auto _do_add_c(entity_param, Component&& component) -> bool;

    template <typename Relation>
    auto _do_add_r(entity_param, entity_param, Relation&& relation) -> bool;

    auto
      _do_add_r(entity_param, entity_param, component_uid_t, std::string (*)())
        -> bool;

    auto
    _do_cpy(entity_param f, entity_param t, component_uid_t, std::string (*)())
      -> bool;

    auto
    _do_swp(entity_param f, entity_param t, component_uid_t, std::string (*)())
      -> bool;

    auto _do_rem_c(entity_param, component_uid_t, std::string (*)()) -> bool;

    auto
      _do_rem_r(entity_param, entity_param, component_uid_t, std::string (*)())
        -> bool;

    template <typename C, typename Func>
    auto _call_for_single_c(entity_param, const Func&) -> bool;

    template <typename C, typename Func>
    void _call_for_each_c(const Func&);

    template <typename R, typename Func>
    void _call_for_each_r(const Func&);

    template <typename... C, typename Func>
    void _call_for_each_c_m_p(const Func&);

    template <typename... C, typename Func>
    void _call_for_each_c_m_r(const Func&);

    template <typename T, typename C>
    auto _do_get_c(T C::*, entity_param, T) -> T;

public:
    basic_manager() = default;

    template <typename Component>
    auto register_component_type(
      std::unique_ptr<component_storage<Entity, Component>>&& storage)
      -> auto& {
        _do_reg_stg_type<false>(
          _base_cmp_storage_ptr_t(std::move(storage)),
          Component::uid(),
          _cmp_name_getter<Component>());
        return *this;
    }

    template <typename Relation>
    auto register_relation_type(
      std::unique_ptr<relation_storage<Entity, Relation>>&& storage) -> auto& {
        _do_reg_stg_type<true>(
          _base_rel_storage_ptr_t(std::move(storage)),
          Relation::uid(),
          _cmp_name_getter<Relation>());
        return *this;
    }

    template <
      template <class, class>
      class Storage,
      typename Component,
      typename... P>
    auto register_component_storage(P&&... p) -> auto& {
        register_component_type<Component>(
          std::make_unique<Storage<Entity, Component>>(std::forward<P>(p)...));
        return *this;
    }

    template <
      template <class, class>
      class Storage,
      typename Relation,
      typename... P>
    auto register_relation_storage(P&&... p) -> auto& {
        register_relation_type<Relation>(
          std::make_unique<Storage<Entity, Relation>>(std::forward<P>(p)...));
        return *this;
    }

    template <typename Component>
    auto unregister_component_type() -> auto& {
        _do_unr_stg_type<false>(
          Component::uid(), _cmp_name_getter<Component>());
        return *this;
    }

    template <typename Relation>
    auto unregister_relation_type() -> auto& {
        _do_unr_stg_type<true>(Relation::uid(), _cmp_name_getter<Relation>());
        return *this;
    }

    template <typename Component>
    auto knows_component_type() const -> bool {
        return _does_know_stg_type<false>(Component::uid());
    }

    template <typename Relation>
    auto knows_relation_type() const -> bool {
        return _does_know_stg_type<true>(Relation::uid());
    }

    template <typename Component>
    auto component_storage_caps() const -> storage_caps {
        return _get_stg_type_caps<false>(
          Component::uid(), _cmp_name_getter<Component>());
    }

    template <typename Relation>
    auto relation_storage_caps() const -> storage_caps {
        return _get_stg_type_caps<true>(
          Relation::uid(), _cmp_name_getter<Relation>());
    }

    template <typename Component>
    auto component_storage_can(storage_cap_bit cap) const -> bool {
        return _get_stg_type_caps<false>(
                 Component::uid(), _cmp_name_getter<Component>())
          .has(cap);
    }

    template <typename Relation>
    auto relation_storage_can(storage_cap_bit cap) const -> bool {
        return _get_stg_type_caps<true>(
                 Relation::uid(), _cmp_name_getter<Relation>())
          .has(cap);
    }

    void forget(entity_param ent);

    template <typename Component>
    auto has(entity_param ent) -> bool {
        return _does_have_c(
          ent, Component::uid(), _cmp_name_getter<Component>());
    }

    template <typename Relation>
    auto has(entity_param subject, entity_param object) -> bool {
        return _does_have_r(
          subject, object, Relation::uid(), _cmp_name_getter<Relation>());
    }

    template <typename... Components>
    auto has_all(entity_param ent) -> bool {
        return _count_true(_does_have_c(
                 ent, Components::uid(), _cmp_name_getter<Components>())...) ==
               (sizeof...(Components));
    }

    template <typename Relation>
    auto is(entity_param object, entity_param subject) -> bool {
        return _does_have_r(
          subject, object, Relation::uid(), _cmp_name_getter<Relation>());
    }

    template <typename Component>
    auto hidden(entity_param ent) -> bool {
        return _is_hidn(ent, Component::uid(), _cmp_name_getter<Component>());
    }

    template <typename... Components>
    auto all_hidden(entity_param ent) -> bool {
        return _count_true(_is_hidn(
                 ent, Components::uid(), _cmp_name_getter<Components>())...) ==
               (sizeof...(Components));
    }

    template <typename... Components>
    auto show(entity_param ent) -> auto& {
        (..., _do_show(ent, Components::uid(), _cmp_name_getter<Components>()));
        return *this;
    }

    template <typename... Components>
    auto hide(entity_param ent) -> auto& {
        (..., _do_hide(ent, Components::uid(), _cmp_name_getter<Components>()));
        return *this;
    }

    template <typename... Components>
    auto add(entity_param ent, Components&&... components) -> auto& {
        (..., _do_add_c(ent, std::move(components)));
        return *this;
    }

    template <typename Relation>
    auto add_relation(entity_param subject, entity_param object, Relation&& rel)
      -> auto& {
        _do_add_r(subject, object, std::forward<Relation>(rel));
        return *this;
    }

    template <typename Relation>
    auto add_relation(entity_param subject, entity_param object) -> auto& {
        _do_add_r(
          subject, object, Relation::uid(), _cmp_name_getter<Relation>());
        return *this;
    }

    template <typename... Components>
    auto copy(entity_param from, entity_param to) -> auto& {
        (...,
         _do_cpy(from, to, Components::uid(), _cmp_name_getter<Components>()));
        return *this;
    }

    template <typename... Components>
    auto swap(entity_param e1, entity_param e2) -> auto& {
        (...,
         _do_swp(e1, e2, Components::uid(), _cmp_name_getter<Components>()));
        return *this;
    }

    template <typename... Components>
    auto remove(entity_param ent) -> auto& {
        (...,
         _do_rem_c(ent, Components::uid(), _cmp_name_getter<Components>()));
        return *this;
    }

    template <typename Relation>
    auto remove_relation(entity_param subject, entity_param object) -> auto& {
        _do_rem_r(
          subject, object, Relation::uid(), _cmp_name_getter<Relation>());
        return *this;
    }

    template <typename T, typename Component>
    auto get(T Component::*mvp, entity_param ent, T res = T()) -> T {
        return _do_get_c(mvp, ent, res);
    }

    template <typename Component>
    auto for_single(
      const callable_ref<void(entity_param, manipulator<const Component>&)>&
        func,
      entity_param ent) -> auto& {
        _call_for_single_c<Component>(func, ent);
        return *this;
    }

    template <typename Component>
    auto for_single(
      const callable_ref<void(entity_param, manipulator<Component>&)>& func,
      entity_param ent) -> auto& {
        _call_for_single_c<Component>(func, ent);
        return *this;
    }

    template <typename Component>
    auto for_each(
      const callable_ref<void(entity_param, manipulator<const Component>&)>&
        func) -> auto& {
        _call_for_each_c<Component>(func);
        return *this;
    }

    template <typename Component>
    auto for_each(
      const callable_ref<void(entity_param, manipulator<Component>&)>& func)
      -> auto& {
        _call_for_each_c<Component>(func);
        return *this;
    }

    template <typename Relation>
    auto for_each(const callable_ref<void(entity_param, entity_param)>& func)
      -> auto& {
        _call_for_each_r<Relation>(func);
        return *this;
    }

    template <typename Relation>
    auto for_each(
      const callable_ref<
        void(entity_param, entity_param, manipulator<const Relation>&)>& func)
      -> auto& {
        _call_for_each_r<Relation>(func);
        return *this;
    }

    template <typename Relation>
    auto
    for_each(const callable_ref<
             void(entity_param, entity_param, manipulator<Relation>&)>& func)
      -> auto& {
        _call_for_each_r<Relation>(func);
        return *this;
    }

    template <typename... Components>
    auto for_each_opt(
      const callable_ref<void(entity_param, manipulator<Components>&...)>& func)
      -> auto& {
        _call_for_each_c_m_p<Components...>(func);
        return *this;
    }

    template <typename... Components, typename Func>
    auto for_each_with_opt(const Func& func) -> auto& {
        callable_ref<void(entity_param, manipulator<Components> & ...)> wrap(
          func);
        return for_each_opt<Components...>(wrap);
    }

    template <typename... Components>
    auto for_each(
      const callable_ref<void(entity_param, manipulator<Components>&...)>& func)
      -> std::enable_if_t<(sizeof...(Components) > 1), basic_manager&> {
        _call_for_each_c_m_r<Components...>(func);
        return *this;
    }

    template <typename... Components, typename Func>
    auto for_each_with(const Func& func) -> auto& {
        callable_ref<void(entity_param, manipulator<Components> & ...)> wrap(
          func);
        return for_each<Components...>(wrap);
    }

    template <typename... Components>
    auto select()
      -> component_relation<Entity, mp_list<mp_list<Components...>>> {
        return {*this};
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::ecs

#include <eagine/ecs/basic_manager.inl>

#endif // EAGINE_ECS_BASIC_MANAGER_HPP
