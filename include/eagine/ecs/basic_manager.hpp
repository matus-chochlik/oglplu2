/**
 *  @file eagine/ecs/basic_manager.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_MANAGER_1509260923_HPP
#define EAGINE_ECS_MANAGER_1509260923_HPP

#include "component.hpp"
#include "cmp_storage.hpp"
#include "cmp_storage.hpp"
#include "entity_traits.hpp"
#include "../type_traits.hpp"
#include "../type_name.hpp"
#include "../mp_list.hpp"
#include <memory>

namespace eagine {
namespace ecs {

template <typename Entity>
class basic_manager;

template <typename Entity, typename PL>
class component_relation;

template <typename Entity, typename ... PL>
class component_relation<Entity, mp_list<PL...>>
{
private:
	basic_manager<Entity>& _m;

	template <
		typename F,
		typename ... C,
		typename ... X
	> static inline
	auto _apply(
		basic_manager<Entity>& m,
		const F& func,
		mp_list<mp_list<C...>>,
		X&& ... x
	)
	{
		callable_ref<void(
			entity_param_t<Entity>,
			manipulator<C>&...
		)> w(
			[&func, &x...](
				entity_param_t<Entity> e,
				manipulator<C>&...c
			)
			{
				func(std::forward<X>(x)..., e, c...);
			}
		);
		m.for_each(w);
	}

	template <
		typename F,
		typename ... C,
		typename L,
		typename ... Ls,
		typename ... X
	> static inline
	auto _apply(
		basic_manager<Entity>& m,
		const F& func,
		mp_list<mp_list<C...>, L, Ls...>,
		X&& ... x
	)
	{
		callable_ref<void(
			entity_param_t<Entity>,
			manipulator<C>&...
		)> w(
			[&m,&func,&x...](
				entity_param_t<Entity> e,
				manipulator<C>&...c
			)
			{
				_apply(
					m, func,
					mp_list<L, Ls...>(),
					std::forward<X>(x)...,
					e, c...
				);
			}
		);
		m.for_each(w);
	}
public:
	component_relation(basic_manager<Entity>& m)
	 : _m(m)
	{ }

	template <typename ... C>
	component_relation<Entity, mp_list<PL..., mp_list<C...>>>
	cross(void)
	{
		return {_m};
	}

	template <typename Func>
	void for_each(const Func& func)
	{
		_apply(_m, func, mp_list<PL...>());
	}
};

template <typename Entity>
class basic_manager
{
public:
	typedef entity_param_t<Entity> entity_param;
private:
	typedef base_component_storage<Entity> _base_cmp_storage_t;
	typedef std::unique_ptr<_base_cmp_storage_t> _base_cmp_storage_ptr_t;

	component_uid_map<_base_cmp_storage_ptr_t> _cmp_storages;

	component_uid_map<_base_cmp_storage_ptr_t>&
	_get_storages(std::false_type)
	noexcept
	{
		return _cmp_storages;
	}

	typedef base_relation_storage<Entity> _base_rel_storage_t;
	typedef std::unique_ptr<_base_rel_storage_t> _base_rel_storage_ptr_t;

	component_uid_map<_base_rel_storage_ptr_t> _rel_storages;

	component_uid_map<_base_rel_storage_ptr_t>&
	_get_storages(std::true_type)
	noexcept
	{
		return _rel_storages;
	}

	template <bool IsR>
	component_uid_map<std::unique_ptr<base_component_storage<Entity>>>&
	_get_storages(void)
	noexcept
	{
		return _get_storages(std::integral_constant<bool, IsR>());
	}

	template <typename C>
	using _bare_t = std::remove_const_t<std::remove_reference_t<C>>;

	template <typename ... P>
	static inline void _eat(P ...) { }

	static constexpr inline
	unsigned _count_true(void)
	{
		return 0;
	}

	template <typename T, typename ... P>
	static constexpr unsigned
	_count_true(T v, P ... p)
	{
		return (bool(v)?1:0)+_count_true(p...);
	}

	template <typename C>
	static inline
	std::string (*_cmp_name_getter(void))(void)
	{
		return &type_name<C>;
	}

	template <typename Data, bool IsR>
	storage<Entity, Data, IsR>& _find_storage(void);

	template <typename C>
	component_storage<Entity, C>& _find_cmp_storage(void)
	{
		return _find_storage<C, false>();
	}

	template <typename R>
	relation_storage<Entity, R>& _find_rel_storage(void)
	{
		return _find_storage<R, true>();
	}

	void _do_reg_cmp_type(
		std::unique_ptr<base_component_storage<Entity>>&&,
		component_uid_t,
		std::string(*)(void)
	);

	void _do_unr_cmp_type(component_uid_t, std::string(*)(void));

	bool _does_know_cmp_type(component_uid_t) const;

	template <typename Result, typename Func>
	Result _apply_on_base_stg(
		Result,
		const Func&,
		component_uid_t,
		std::string(*)(void)
	) const;

	template <typename C, typename Result, typename Func>
	Result _apply_on_cmp_stg(Result, const Func&) const;

	storage_caps _get_cmp_type_caps(
		component_uid_t,
		std::string(*)(void)
	) const;

	bool _does_have(
		entity_param,
		component_uid_t,
		std::string(*)(void)
	);

	bool _is_hidn(
		entity_param,
		component_uid_t,
		std::string(*)(void)
	);

	bool _do_show(
		entity_param,
		component_uid_t,
		std::string(*)(void)
	);

	bool _do_hide(
		entity_param,
		component_uid_t,
		std::string(*)(void)
	);

	template <typename Component>
	bool _do_add(entity_param, Component&& component);

	bool _do_cpy(
		entity_param f,
		entity_param t,
		component_uid_t,
		std::string(*)(void)
	);

	bool _do_swp(
		entity_param f,
		entity_param t,
		component_uid_t,
		std::string(*)(void)
	);

	bool _do_rem(
		entity_param,
		component_uid_t,
		std::string(*)(void)
	);

	template <typename C, typename Func>
	bool _call_for_single_c(entity_param, const Func&);

	template <typename C, typename Func>
	void _call_for_each_c(const Func&);

	template <typename ... C, typename Func>
	void _call_for_each_c_m_p(const Func&);

	template <typename ... C, typename Func>
	void _call_for_each_c_m_r(const Func&);

	template <typename T, typename C>
	T _do_get_c(T C::*, entity_param, T);
public:
	basic_manager(void) = default;

	template <typename Component>
	void register_component_type(
		std::unique_ptr<component_storage<Entity, Component>>&& storage
	)
	{
		_do_reg_cmp_type(
			_base_cmp_storage_ptr_t(std::move(storage)),
			get_component_uid<Component>(),
			_cmp_name_getter<Component>()
		);
	}

	template <
		template <class, class> class Storage,
		typename Component,
		typename ... P
	>
	void register_component_storage(P&& ... p)
	{
		register_component_type<Component>(
			std::unique_ptr<Storage<Entity, Component>>(
				new Storage<Entity, Component>(
					std::forward<P>(p)...
				)
			)
		);
	}

	template <typename Component>
	void unregister_component_type(void)
	{
		_do_unr_cmp_type(
			get_component_uid<Component>(),
			_cmp_name_getter<Component>()
		);
	}

	template <typename Component>
	bool knows_component_type(void) const
	{
		return _does_know_cmp_type(get_component_uid<Component>());
	}

	template <typename Component>
	storage_caps component_storage_caps(void) const
	{
		return _get_cmp_type_caps(
			get_component_uid<Component>(),
			_cmp_name_getter<Component>()
		);
	}

	template <typename Component>
	bool component_storage_can(storage_cap_bit cap) const
	{
		return _get_cmp_type_caps(
			get_component_uid<Component>(),
			_cmp_name_getter<Component>()
		).has(cap);
	}

	void forget(entity_param ent);

	template <typename Component>
	bool has(entity_param ent)
	{
		return _does_have(
			ent,
			get_component_uid<Component>(),
			_cmp_name_getter<Component>()
		);
	}

	template <typename ... Components>
	bool has_all(entity_param ent)
	{
		return _count_true(
			_does_have(
				ent,
				get_component_uid<Components>(),
				_cmp_name_getter<Components>()
			)...
		) == (sizeof...(Components));
	}

	template <typename Component>
	bool hidden(entity_param ent)
	{
		return _is_hidn(
			ent,
			get_component_uid<Component>(),
			_cmp_name_getter<Component>()
		);
	}

	template <typename ... Components>
	bool all_hidden(entity_param ent)
	{
		return _count_true(
			_is_hidn(
				ent,
				get_component_uid<Components>(),
				_cmp_name_getter<Components>()
			)...
		) == (sizeof...(Components));
	}

	template <typename ... Components>
	basic_manager&
	show(entity_param ent)
	{
		_eat(_do_show(
			ent,
			get_component_uid<Components>(),
			_cmp_name_getter<Components>()
		)...);
		return *this;
	}

	template <typename ... Components>
	basic_manager&
	hide(entity_param ent)
	{
		_eat(_do_hide(
			ent,
			get_component_uid<Components>(),
			_cmp_name_getter<Components>()
		)...);
		return *this;
	}

	template <typename ... Components>
	basic_manager&
	add(entity_param ent, Components&& ... components)
	{
		_eat(_do_add(ent, std::move(components))...);
		return *this;
	}

	template <typename ... Components>
	basic_manager&
	copy(entity_param from, entity_param to)
	{
		_eat(_do_cpy(
			from,
			to,
			get_component_uid<Components>(),
			_cmp_name_getter<Components>()
		)...);
		return *this;
	}

	template <typename ... Components>
	basic_manager&
	swap(entity_param e1, entity_param e2)
	{
		_eat(_do_swp(
			e1,
			e2,
			get_component_uid<Components>(),
			_cmp_name_getter<Components>()
		)...);
		return *this;
	}

	template <typename ... Components>
	basic_manager&
	remove(entity_param ent)
	{
		_eat(_do_rem(
			ent,
			get_component_uid<Components>(),
			_cmp_name_getter<Components>()
		)...);
		return *this;
	}

	template <typename T, typename Component>
	T get(T Component::*mvp, entity_param ent, T res = T())
	{
		return _do_get_c(mvp, ent, res);
	}

	template <typename Component>
	basic_manager& for_single(
		const callable_ref<void(
			entity_param,
			manipulator<const Component>&
		)>& func,
		entity_param ent
	)
	{
		_call_for_single_c<Component>(func, ent);
		return *this;
	}

	template <typename Component>
	basic_manager& for_single(
		const callable_ref<void(
			entity_param,
			manipulator<Component>&
		)>& func,
		entity_param ent
	)
	{
		_call_for_single_c<Component>(func, ent);
		return *this;
	}

	template <typename Component>
	basic_manager&
	for_each(const callable_ref<void(
		entity_param,
		manipulator<const Component>&
	)>& func)
	{
		_call_for_each_c<Component>(func);
		return *this;
	}

	template <typename Component>
	basic_manager&
	for_each(const callable_ref<void(
		entity_param,
		manipulator<Component>&
	)>& func)
	{
		_call_for_each_c<Component>(func);
		return *this;
	}

	template <typename ... Components>
	basic_manager&
	for_each_opt(const callable_ref<void(
		entity_param,
		manipulator<Components>&...)
	>& func)
	{
		_call_for_each_c_m_p<Components...>(func);
		return *this;
	}

	template <typename ... Components, typename Func>
	basic_manager&
	for_each_with_opt(const Func& func)
	{
		callable_ref<void(
			entity_param,
			manipulator<Components>&...
		)> wrap(func);
		return for_each_opt<Components...>(wrap);
	}

	template <typename ... Components>
	std::enable_if_t<(sizeof ... (Components) > 1), basic_manager&>
	for_each(const callable_ref<void(
		entity_param,
		manipulator<Components>&...
	)>& func)
	{
		_call_for_each_c_m_r<Components...>(func);
		return *this;
	}

	template <typename ... Components, typename Func>
	basic_manager&
	for_each_with(const Func& func)
	{
		callable_ref<void(
			entity_param,
			manipulator<Components>&...
		)> wrap(func);
		return for_each<Components...>(wrap);
	}

	template <typename ... Components>
	component_relation<Entity, mp_list<mp_list<Components...>>>
	select(void)
	{
		return {*this};
	}

};

} // namespace ecs
} // namespace eagine

#include <eagine/ecs/basic_manager.inl>

#endif //include guard

