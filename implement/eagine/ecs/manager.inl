/**
 *  @file eagine/ecs/manager.inl
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
template <typename Component>
component_storage<Entity, Component>&
manager<Entity>::
_find_storage(void)
{
	auto p_storage = _storages.find(get_component_uid<Component>());

	typedef component_storage<Entity, Component> cs_t;
	cs_t* ct_storage = nullptr;

	if(p_storage != _storages.end())
	{
		auto& b_storage = *p_storage;
		if(b_storage)
		{
			ct_storage = dynamic_cast<cs_t*>(b_storage.get());
			assert(ct_storage);
		}
	}
	if(!ct_storage)
	{
		std::string(*get_name)(void) = _cmp_name_getter<Component>();
		detail::mgr_handle_cmp_not_reg(get_name());
		EAGINE_ABORT("Logic error!");
	}
	return *ct_storage;
}
//------------------------------------------------------------------------------
template <typename Entity>
inline void
manager<Entity>::
_do_reg_cmp_type(
	std::unique_ptr<base_storage<Entity>>&& storage,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	assert(bool(storage));

	auto p_storage = _storages.find(cid);

	if(p_storage == _storages.end())
	{
		_storages[cid] = std::move(storage);
	}
	else
	{
		detail::mgr_handle_cmp_is_reg(get_name());
	}
}
//------------------------------------------------------------------------------
template <typename Entity>
inline void
manager<Entity>::
_do_unr_cmp_type(
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	auto p_storage = _storages.find(cid);

	if(p_storage != _storages.end())
	{
		_storages.erase(p_storage);
	}
	else
	{
		detail::mgr_handle_cmp_not_reg(get_name());
	}
}
//------------------------------------------------------------------------------
template <typename Entity>
inline bool
manager<Entity>::
_does_know_cmp_type(component_uid_t cid) const
{
	auto p_storage = _storages.find(cid);

	if(p_storage != _storages.end())
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
template <typename Result, typename Func>
inline Result
manager<Entity>::
_apply_on_base_stg(
	Result fallback,
	const Func& func,
	component_uid_t cid,
	std::string(*get_name)(void)
) const
{
	auto p_storage = _storages.find(cid);

	if(p_storage != _storages.end())
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
template <typename Component, typename Result, typename Func>
inline Result
manager<Entity>::
_apply_on_cmp_stg(Result fallback, const Func& func) const
{
	return _apply_on_base_stg(
		fallback,
		[&func](auto& b_storage) -> Result
		{
			typedef component_storage<Entity, Component> cs_t;

			cs_t* ct_storage = dynamic_cast<cs_t*>(b_storage.get());
			assert(ct_storage);

			return func(ct_storage);
		},
		get_component_uid<Component>(),
		_cmp_name_getter<Component>()
	);
}
//------------------------------------------------------------------------------
template <typename Entity>
inline storage_caps
manager<Entity>::
_get_cmp_type_caps(component_uid_t cid, std::string(*get_name)(void)) const
{
	return _apply_on_base_stg(
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
manager<Entity>::
_does_have(
	const Entity& ent,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg(
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
manager<Entity>::
_is_hidn(
	const Entity& ent,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg(
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
manager<Entity>::
_do_show(
	const Entity& ent,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg(
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
manager<Entity>::
_do_hide(
	const Entity& ent,
	component_uid_t cid,
	std::string(*get_name)(void)
)
{
	return _apply_on_base_stg(
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
manager<Entity>::
_do_add(const Entity& ent, Component&& component)
{
	return _apply_on_cmp_stg<Component>(
		false,
		[&ent, &component](auto& c_storage) -> bool
		{
			c_storage->store(ent, std::move(component));
			return true;
		}
	);
}
//------------------------------------------------------------------------------
} // namespace ecs
} // namespace eagine
