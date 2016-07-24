/**
 *  @file eagine/ecs/basic_manager.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/str_format.hpp>
#include <stdexcept>
#endif

namespace eagine {
namespace ecs {
//------------------------------------------------------------------------------
namespace detail {
#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
//------------------------------------------------------------------------------
[[noreturn]]
EAGINE_LIB_FUNC
void mgr_handle_cmp_is_reg(std::string&& c_name)
{
	throw std::runtime_error(
		format("Component type '${1}' is already registered")
		% std::move(c_name)
	);
}
//------------------------------------------------------------------------------
[[noreturn]]
EAGINE_LIB_FUNC
void mgr_handle_cmp_not_reg(std::string&& c_name)
{
	throw std::runtime_error(
		format("Component type '${1}' is not registered")
		% std::move(c_name)
	);
}
//------------------------------------------------------------------------------
#else
//------------------------------------------------------------------------------
[[noreturn]]
void mgr_handle_cmp_is_reg(std::string&&);
//------------------------------------------------------------------------------
[[noreturn]]
void mgr_handle_cmp_not_reg(std::string&&);
//------------------------------------------------------------------------------
#endif
} // namespace detail
//------------------------------------------------------------------------------
template <typename Entity>
template <typename Data, bool IsR>
storage<Entity, Data, IsR>&
basic_manager<Entity>::
_find_storage(void)
{
	auto pb_storage = _get_storages<IsR>().find(get_component_uid<Data>());

	typedef storage<Entity, Data, IsR> S;
	S* pd_storage = nullptr;

	if(pb_storage != _get_storages<IsR>().end())
	{
		auto& b_storage = *pb_storage;
		if(b_storage)
		{
			pd_storage = dynamic_cast<S*>(b_storage.get());
			assert(pd_storage);
		}
	}
	if(!pd_storage)
	{
		std::string(*get_name)(void) = _cmp_name_getter<Data>();
		detail::mgr_handle_cmp_not_reg(get_name());
		EAGINE_ABORT("Logic error!");
	}
	return *pd_storage;
}
//------------------------------------------------------------------------------
template <typename Entity>
template <bool IsRelation>
inline void
basic_manager<Entity>::
_do_reg_stg_type(
	std::unique_ptr<base_storage<Entity, IsRelation>>&& storage,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	assert(bool(storage));

	auto &storages = _get_storages<IsRelation>();
	auto p_storage = storages.find(cid);

	if(p_storage == storages.end())
	{
		storages[cid] = std::move(storage);
	}
	else
	{
		detail::mgr_handle_cmp_is_reg(get_name());
	}
}
//------------------------------------------------------------------------------
template <typename Entity>
template <bool IsRelation>
inline void
basic_manager<Entity>::
_do_unr_stg_type(
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	auto &storages = _get_storages<IsRelation>();
	auto p_storage = storages.find(cid);

	if(p_storage != storages.end())
	{
		storages.erase(p_storage);
	}
	else
	{
		detail::mgr_handle_cmp_not_reg(get_name());
	}
}
//------------------------------------------------------------------------------
template <typename Entity>
template <bool IsRelation>
inline bool
basic_manager<Entity>::
_does_know_stg_type(component_uid_t cid) const
{
	auto &storages = _get_storages<IsRelation>();
	auto p_storage = storages.find(cid);

	if(p_storage != storages.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}
//------------------------------------------------------------------------------
template <typename Entity>
template <bool IsRelation, typename Result, typename Func>
inline Result
basic_manager<Entity>::
_apply_on_base_stg(
	Result fallback,
	const Func& func,
	component_uid_t cid,
	std::string(*get_name)(void)
) const
{
	auto &storages = _get_storages<IsRelation>();
	auto p_storage = storages.find(cid);

	if(p_storage != storages.end())
	{
		auto& bs_storage = *p_storage;
		if(bs_storage)
		{
			return func(bs_storage);
		}
	}
	detail::mgr_handle_cmp_not_reg(get_name());
	return fallback;
}
//------------------------------------------------------------------------------
template <typename Entity>
template <typename Component, bool IsRelation, typename Result, typename Func>
inline Result
basic_manager<Entity>::
_apply_on_stg(Result fallback, const Func& func) const
{
	return _apply_on_base_stg<IsRelation>(
		fallback,
		[&func](auto& b_storage) -> Result
		{
			typedef storage<Entity, Component, IsRelation> S;

			S* ct_storage = dynamic_cast<S*>(b_storage.get());
			assert(ct_storage);

			return func(ct_storage);
		},
		get_component_uid<Component>(),
		_cmp_name_getter<Component>()
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
template <bool IsRelation>
inline storage_caps
basic_manager<Entity>::
_get_stg_type_caps(component_uid_t cid, std::string(*get_name)(void)) const
{
	return _apply_on_base_stg<IsRelation>(
		storage_caps(),
		[](auto& b_storage) -> storage_caps
		{
			return b_storage->capabilities();
		},
		cid, get_name
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
inline bool
basic_manager<Entity>::
_does_have_c(
	entity_param_t<Entity> ent,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg<false>(
		false,
		[&ent](auto& b_storage) -> bool
		{
			return b_storage->has(ent);
		},
		cid, get_name
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
inline bool
basic_manager<Entity>::
_does_have_r(
	entity_param_t<Entity> subject,
	entity_param_t<Entity> object,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg<true>(
		false,
		[&subject,&object](auto& b_storage) -> bool
		{
			return b_storage->has(subject, object);
		},
		cid, get_name
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
inline bool
basic_manager<Entity>::
_is_hidn(
	entity_param_t<Entity> ent,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg<false>(
		false,
		[&ent](auto& b_storage) -> bool
		{
			return b_storage->hidden(ent);
		},
		cid, get_name
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
inline bool
basic_manager<Entity>::
_do_show(
	entity_param_t<Entity> ent,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg<false>(
		false,
		[&ent](auto& b_storage) -> bool
		{
			return b_storage->show(ent);
		},
		cid, get_name
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
inline bool
basic_manager<Entity>::
_do_hide(
	entity_param_t<Entity> ent,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg<false>(
		false,
		[&ent](auto& b_storage) -> bool
		{
			return b_storage->hide(ent);
		},
		cid, get_name
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
template <typename Component>
inline bool
basic_manager<Entity>::
_do_add_c(entity_param_t<Entity> ent, Component&& component)
{
	return _apply_on_stg<Component, false>(
		false,
		[&ent, &component](auto& c_storage) -> bool
		{
			c_storage->store(ent, std::move(component));
			return true;
		}
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
template <typename Relation>
inline bool
basic_manager<Entity>::
_do_add_r(entity_param subj, entity_param obj, Relation&& relation)
{
	return _apply_on_stg<Relation, true>(
		false,
		[&subj, &obj, &relation](auto& c_storage) -> bool
		{
			c_storage->store(subj, obj, std::move(relation));
			return true;
		}
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
inline bool
basic_manager<Entity>::
_do_add_r(
	entity_param subject,
	entity_param object,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg<true>(
		false,
		[&subject, &object](auto& b_storage) -> bool
		{
			return b_storage->store(subject, object);
		},
		cid, get_name
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
inline bool
basic_manager<Entity>::
_do_cpy(
	entity_param_t<Entity> from,
	entity_param_t<Entity> to,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg<false>(
		false,
		[&from, &to](auto& b_storage) -> bool
		{
			return b_storage->copy(to, from);
		},
		cid, get_name
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
inline bool
basic_manager<Entity>::
_do_swp(
	entity_param_t<Entity> e1,
	entity_param_t<Entity> e2,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg<false>(
		false,
		[&e1, &e2](auto& b_storage) -> bool
		{
			b_storage->swap(e1, e2);
			return true;
		},
		cid, get_name
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
inline bool
basic_manager<Entity>::
_do_rem(
	entity_param_t<Entity> ent,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg<false>(
		false,
		[&ent](auto& b_storage) -> bool
		{
			return b_storage->remove(ent);
		},
		cid, get_name
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
template <typename T, typename C>
inline T
basic_manager<Entity>::
_do_get_c(T C::* mvp, entity_param_t<Entity> ent, T res)
{
	assert(mvp);

	typedef manipulator<const C> MC;

	auto getter = [mvp, &res](entity_param_t<Entity>, MC& cmp)
	{
		res = cmp.read().*mvp;
	};
	callable_ref<void(entity_param_t<Entity>, MC&)> func(getter);

	_call_for_single_c<C>(ent, func);
	return res;
}
//------------------------------------------------------------------------------
template <typename Entity>
template <typename Component, typename Func>
inline bool
basic_manager<Entity>::
_call_for_single_c(entity_param_t<Entity> ent, const Func& func)
{
	return _apply_on_stg<std::remove_const_t<Component>, false>(
		false,
		[&func, &ent](auto& c_storage) -> bool
		{
			c_storage->for_single(func, ent);
			return true;
		}
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
template <typename Component, typename Func>
inline void
basic_manager<Entity>::
_call_for_each_c(const Func& func)
{
	_apply_on_stg<std::remove_const_t<Component>, false>(
		false,
		[&func](auto& c_storage) -> bool
		{
			c_storage->for_each(func);
			return true;
		}
	);
}
//------------------------------------------------------------------------------
template <typename Entity, typename C>
class _manager_for_each_c_m_base
{
private:
	component_storage<Entity, std::remove_const_t<C>>& _storage;
protected:
	component_storage_iterator<Entity> _iter;
	Entity _curr;

	_manager_for_each_c_m_base(
		component_storage<Entity, std::remove_const_t<C>>& storage
	): _storage(storage)
	 , _iter(_storage.new_iterator())
	 , _curr(_iter.done()?Entity():_iter.current())
	{
		assert(
			std::is_const<C>::value ||
			_storage.capabilities().can_modify()
		);
	}

	~_manager_for_each_c_m_base(void)
	{
		_storage.delete_iterator(std::move(_iter));
	}

	bool _done(void)
	{
		return _iter.done();
	}

	entity_param_t<Entity> _current(void)
	{
		return _curr;
	}

	void _apply(const callable_ref<void(
		entity_param_t<Entity>,
		manipulator<C>&
	)>& func)
	{
		_storage.for_single(func, _iter);
	}
};
//------------------------------------------------------------------------------
template <typename Entity, typename C>
class _manager_for_each_c_m_p_base
 : public _manager_for_each_c_m_base<Entity, C>
{
protected:
	_manager_for_each_c_m_p_base(
		component_storage<Entity, std::remove_const_t<C>>& storage
	): _manager_for_each_c_m_base<Entity, C>(storage)
	{ }

	using _manager_for_each_c_m_base<Entity, C>::_iter;
	using _manager_for_each_c_m_base<Entity, C>::_curr;
	using _manager_for_each_c_m_base<Entity, C>::_done;
	using _manager_for_each_c_m_base<Entity, C>::_current;

	void _next_if(entity_param_t<Entity> m)
	{
		if(!_done())
		{
			if(_current() == m)
			{
				_iter.next();
				if(!_done())
				{
					_curr = _iter.current();
				}
			}
		}
	}
};
//------------------------------------------------------------------------------
template <typename Entity, typename LL, typename LR>
class _manager_for_each_c_m_p_unit;
//------------------------------------------------------------------------------
template <typename Entity, typename ... CL, typename C>
class _manager_for_each_c_m_p_unit<Entity, mp_list<CL...>, mp_list<C>>
 : public _manager_for_each_c_m_p_base<Entity, C>
{
private:
	callable_ref<void(
		entity_param_t<Entity>,
		manipulator<CL>&...,
		manipulator<C>&
	)> _func;
public:
	_manager_for_each_c_m_p_unit(
		const callable_ref<void(
			entity_param_t<Entity>,
			manipulator<CL>&...,
			manipulator<C>&
		)>& func,
		component_storage<Entity, std::remove_const_t<C>>& s
	): _manager_for_each_c_m_p_base<Entity, C>(s)
	 , _func(func)
	{ }

	bool done(void)
	{
		return this->_done();
	}

	void next_if_min(entity_param_t<Entity> m)
	{
		this->_next_if(m);
	}

	Entity min_entity(void)
	{
		return this->_current();
	}

	void apply(entity_param_t<Entity> m, manipulator<CL>&... clm)
	{
		if(this->_done() || (m < this->_current()))
		{
			manipulator<C> cman;
			_func(m, clm..., cman);
		}
		else
		{
			assert(m == this->_current());
			callable_ref<void(
				entity_param_t<Entity>,
				manipulator<C>&
			)> hlpr(
				[&clm...,this](
					entity_param_t<Entity> e,
					manipulator<C>& cm
				)
				{
					_func(e, clm..., cm);
				}
			);
			this->_apply(hlpr);
		}
	}
};
//------------------------------------------------------------------------------
template <typename Entity, typename ... CL, typename C, typename ... CR>
class _manager_for_each_c_m_p_unit<Entity, mp_list<CL...>, mp_list<C, CR...>>
 : public _manager_for_each_c_m_p_base<Entity, C>
{
private:
	_manager_for_each_c_m_p_unit<
		Entity,
		mp_list<CL..., C>,
		mp_list<CR...>
	> _rest;
public:
	_manager_for_each_c_m_p_unit(
		const callable_ref<void(
			entity_param_t<Entity>,
			manipulator<CL>&...,
			manipulator<C>&,
			manipulator<CR>&...)
		>& func,
		component_storage<Entity, std::remove_const_t<C>>& s,
		component_storage<Entity, std::remove_const_t<CR>>&... r
	): _manager_for_each_c_m_p_base<Entity, C>(s)
	 , _rest(func, r...)
	{ }

	bool done(void)
	{
		return this->_done() && _rest.done();
	}

	void next_if_min(entity_param_t<Entity> m)
	{
		_rest.next_if_min(m);
		this->_next_if(m);
	}

	Entity min_entity(void)
	{
		if(_rest.done())
		{
			assert(!this->_done());
			return this->_current();
		}

		Entity m = _rest.min_entity();
		if(this->_done())
		{
			return m;
		}
		Entity c = this->_current();
		return (m<c)?m:c;
	}

	void next(void)
	{
		next_if_min(min_entity());
	}

	void apply(
		entity_param_t<Entity> m,
		manipulator<CL>& ... clm
	)
	{
		if(this->_done() || (m < this->_current()))
		{
			manipulator<C> cman;
			_rest.apply(m, clm..., cman);
		}
		else
		{
			assert(m == this->_current());
			callable_ref<void(
				entity_param_t<Entity>,
				manipulator<C>&
			)> hlpr(
				[&clm...,this](
					entity_param_t<Entity> e,
					manipulator<C>& cm
				)
				{
					_rest.apply(e, clm..., cm);
				}
			);
			this->_apply(hlpr);
		}
	}

	void apply(void)
	{
		static_assert(sizeof...(CL) == 0, "");
		assert(!done());

		apply(min_entity());
	}
};
//------------------------------------------------------------------------------
template <typename Entity, typename ... C>
using _manager_for_each_c_m_p_helper =
	_manager_for_each_c_m_p_unit<Entity, mp_list<>, mp_list<C...>>;
//------------------------------------------------------------------------------
template <typename Entity>
template <typename ... Component, typename Func>
inline void
basic_manager<Entity>::
_call_for_each_c_m_p(const Func& func)
{
	_manager_for_each_c_m_p_helper<Entity, Component...> hlp(
		func,
		_find_cmp_storage<_bare_t<Component>>()...
	);
	while(!hlp.done())
	{
		hlp.apply();
		hlp.next();
	}
}
//------------------------------------------------------------------------------
template <typename Entity, typename C>
class _manager_for_each_c_m_r_base
 : public _manager_for_each_c_m_base<Entity, C>
{
protected:
	_manager_for_each_c_m_r_base(
		component_storage<Entity, std::remove_const_t<C>>& storage
	): _manager_for_each_c_m_base<Entity, C>(storage)
	{ }

	using _manager_for_each_c_m_base<Entity, C>::_iter;
	using _manager_for_each_c_m_base<Entity, C>::_curr;
	using _manager_for_each_c_m_base<Entity, C>::_done;
	using _manager_for_each_c_m_base<Entity, C>::_current;

	bool _next(void)
	{
		_iter.next();
		if(!_iter.done())
		{
			_curr = _iter.current();
			return true;
		}
		return false;
	}

	bool _find(entity_param_t<Entity> e)
	{
		if(_iter.find(e))
		{
			_curr = _iter.current();
			return true;
		}
		return false;
	}
};
//------------------------------------------------------------------------------
template <typename Entity, typename LL, typename LR>
class _manager_for_each_c_m_r_unit;
//------------------------------------------------------------------------------
template <typename Entity, typename ... CL, typename C>
class _manager_for_each_c_m_r_unit<Entity, mp_list<CL...>, mp_list<C>>
 : public _manager_for_each_c_m_r_base<Entity, C>
{
private:
	callable_ref<void(
		entity_param_t<Entity>,
		manipulator<CL>&...,
		manipulator<C>&
	)> _func;
public:
	_manager_for_each_c_m_r_unit(
		const callable_ref<void(
			entity_param_t<Entity>,
			manipulator<CL>&...,
			manipulator<C>&
		)>& func,
		component_storage<Entity, std::remove_const_t<C>>& s
	): _manager_for_each_c_m_r_base<Entity, C>(s)
	 , _func(func)
	{ }

	bool done(void)
	{
		return this->_done();
	}

	bool sync_to(entity_param_t<Entity> m)
	{
		return this->_find(m);
	}

	Entity max_entity(void)
	{
		return this->_current();
	}

	bool next(void)
	{
		return this->_next();
	}

	void apply(
		entity_param_t<Entity> m,
		manipulator<CL>&... clm
	)
	{
		assert(m == this->_current());
		callable_ref<void(
			entity_param_t<Entity>,
			manipulator<C>&
		)> hlpr(
			[&clm...,this](
				entity_param_t<Entity> e,
				manipulator<C>& cm
			)
			{
				_func(e, clm..., cm);
			}
		);
		this->_apply(hlpr);
	}
};
//------------------------------------------------------------------------------
template <typename Entity, typename ... CL, typename C, typename ... CR>
class _manager_for_each_c_m_r_unit<Entity, mp_list<CL...>, mp_list<C, CR...>>
 : public _manager_for_each_c_m_r_base<Entity, C>
{
private:
	_manager_for_each_c_m_r_unit<
		Entity,
		mp_list<CL..., C>,
		mp_list<CR...>
	> _rest;
public:
	_manager_for_each_c_m_r_unit(
		const callable_ref<void(
			entity_param_t<Entity>,
			manipulator<CL>&...,
			manipulator<C>&,
			manipulator<CR>&...
		)>& func,
		component_storage<Entity, std::remove_const_t<C>>& s,
		component_storage<Entity, std::remove_const_t<CR>>&... r
	): _manager_for_each_c_m_r_base<Entity, C>(s)
	 , _rest(func, r...)
	{ }

	bool done(void)
	{
		return this->_done() || _rest.done();
	}

	bool sync_to(entity_param_t<Entity> m)
	{
		return _rest.sync_to(m) && this->_find(m);
	}

	Entity max_entity(void)
	{
		Entity m = _rest.max_entity();
		Entity c = this->_current();
		return (m>c)?m:c;
	}

	bool sync(void)
	{
		static_assert(sizeof...(CL) == 0, "");
		return sync_to(max_entity());
	}

	bool next(void)
	{
		return _rest.next() && this->_next();
	}

	void apply(
		entity_param_t<Entity> m,
		manipulator<CL>&... clm
	)
	{
		assert(m == this->_current());
		callable_ref<void(
			entity_param_t<Entity>,
			manipulator<C>&
		)> hlpr(
			[&clm...,this](
				entity_param_t<Entity> e,
				manipulator<C>& cm
			)
			{
				_rest.apply(e, clm..., cm);
			}
		);
		this->_apply(hlpr);
	}

	void apply(void)
	{
		static_assert(sizeof...(CL) == 0, "");
		assert(!done());

		apply(max_entity());
	}
};
//------------------------------------------------------------------------------
template <typename Entity, typename ... C>
using _manager_for_each_c_m_r_helper =
	_manager_for_each_c_m_r_unit<Entity, mp_list<>, mp_list<C...>>;
//------------------------------------------------------------------------------
template <typename Entity>
template <typename ... Component, typename Func>
inline void
basic_manager<Entity>::
_call_for_each_c_m_r(const Func& func)
{
	_manager_for_each_c_m_r_helper<Entity, Component...> hlp(
		func,
		_find_cmp_storage<_bare_t<Component>>()...
	);
	if(hlp.sync())
	{
		while(!hlp.done())
		{
			hlp.apply();
			if(!hlp.next()) break;
			if(!hlp.sync()) break;
		}
	}
}
//------------------------------------------------------------------------------
template <typename Entity>
void
basic_manager<Entity>::
forget(entity_param_t<Entity> ent)
{
	for(auto& storage : _cmp_storages)
	{
		if(storage != nullptr)
		{
			if(storage->caps().can_remove())
			{
				storage->remove(ent);
			}
		}
	}
}
//------------------------------------------------------------------------------
} // namespace ecs
} // namespace eagine
