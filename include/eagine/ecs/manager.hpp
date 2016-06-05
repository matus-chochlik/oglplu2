/**
 *  @file eagine/ecs/manager.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_MANAGER_1509260923_HPP
#define EAGINE_ECS_MANAGER_1509260923_HPP

#include "component.hpp"
#include "storage.hpp"
#include "entity_traits.hpp"
#include "../type_traits.hpp"
#include "../type_name.hpp"
#include <memory>

namespace eagine {
namespace ecs {

template <typename Entity>
class manager
{
public:
	typedef entity_param_t<Entity> entity_param;
private:
	typedef base_storage<Entity> _base_storage_t;
	typedef std::unique_ptr<_base_storage_t> _base_storage_ptr_t;

	component_uid_map<_base_storage_ptr_t> _storages;

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
	static std::string (*_cmp_name_getter(void))(void)
	{
		return &type_name<C>;
	}

	template <typename C>
	component_storage<Entity, C>& _find_storage(void);

	void _do_reg_cmp_type(
		std::unique_ptr<base_storage<Entity>>&&,
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
	bool _call_for_single(entity_param, const Func&);

	template <typename C, typename Func>
	void _call_for_each(const Func&);

	template <typename ... C, typename Func>
	void _call_for_each_m_p(const Func&);

	template <typename T, typename C>
	T _do_get(T C::*, entity_param, T);
public:

	manager(void) = default;

	template <typename Component>
	void register_component_type(
		std::unique_ptr<
			component_storage<Entity, Component>
		>&& storage
	)
	{
		_do_reg_cmp_type(
			_base_storage_ptr_t(std::move(storage)),
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

	template <typename ... C>
	bool has_all(entity_param ent)
	{
		return _count_true(
			_does_have(
				ent,
				get_component_uid<C>(),
				_cmp_name_getter<C>()
			)...
		) == (sizeof...(C));
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

	template <typename ... Component>
	manager& show(entity_param ent)
	{
		_eat(_do_show(
			ent,
			get_component_uid<Component>(),
			_cmp_name_getter<Component>()
		)...);
		return *this;
	}

	template <typename ... Component>
	manager& hide(entity_param ent)
	{
		_eat(_do_hide(
			ent,
			get_component_uid<Component>(),
			_cmp_name_getter<Component>()
		)...);
		return *this;
	}

	template <typename ... C>
	manager& add(entity_param ent, C&& ... components)
	{
		_eat(_do_add(ent, std::move(components))...);
		return *this;
	}

	template <typename ... C>
	manager& copy(entity_param from, entity_param to)
	{
		_eat(_do_cpy(
			from,
			to,
			get_component_uid<C>(),
			_cmp_name_getter<C>()
		)...);
		return *this;
	}

	template <typename ... C>
	manager& swap(entity_param e1, entity_param e2)
	{
		_eat(_do_swp(
			e1,
			e2,
			get_component_uid<C>(),
			_cmp_name_getter<C>()
		)...);
		return *this;
	}

	template <typename ... C>
	manager& remove(entity_param ent)
	{
		_eat(_do_rem(
			ent,
			get_component_uid<C>(),
			_cmp_name_getter<C>()
		)...);
		return *this;
	}

	template <typename T, typename C>
	T get(T C::*mvp, entity_param ent, T res = T())
	{
		return _do_get(mvp, ent, res);
	}

	template <typename C>
	manager& for_single(
		const callable_ref<bool(entity_param, const C&)>& func,
		entity_param ent
	)
	{
		_call_for_single<C>(func, ent);
		return *this;
	}

	template <typename C>
	manager& for_single(
		const callable_ref<bool(entity_param, C&)>& func,
		entity_param ent
	)
	{
		_call_for_single<C>(func, ent);
		return *this;
	}

	template <typename C>
	manager& for_each(
		const callable_ref<bool(entity_param, const C&)>& func
	)
	{
		_call_for_each<C>(func);
		return *this;
	}

	template <typename C>
	manager& for_each(
		const callable_ref<bool(entity_param, C&)>& func
	)
	{
		_call_for_each<C>(func);
		return *this;
	}

	template <typename ... C>
	manager& for_each(
		const callable_ref<void(entity_param, C*...)>& func
	)
	{
		_call_for_each_m_p<C...>(func);
		return *this;
	}

	template <typename ... C, typename Func>
	manager& for_each_ptr(const Func& func)
	{
		callable_ref<void(entity_param, C*...)> wrap(func);
		return for_each<C...>(wrap);
	}
};

} // namespace ecs
} // namespace eagine

#include <eagine/ecs/manager.inl>

#endif //include guard

