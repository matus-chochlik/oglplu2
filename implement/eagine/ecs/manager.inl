/**
 *  @file eagine/ecs/manager.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>

namespace eagine {
namespace ecs {
//------------------------------------------------------------------------------
namespace detail {
#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
//------------------------------------------------------------------------------
[[noreturn]]
EAGINE_LIB_FUNC
void mgr_handle_cmp_is_reg(const std::string& /*c_name*/)
{
	throw std::runtime_error("Component type is already registered");
	/* TODO
	throw std::runtime_error((
		format(translate("Component type '{1}' is already registered"))
		% c_name.c_str()
	).str());
	*/
}
//------------------------------------------------------------------------------
[[noreturn]]
EAGINE_LIB_FUNC
void mgr_handle_cmp_not_reg(const std::string& /*c_name*/)
{
	throw std::runtime_error("Component type is not registered");
	/* TODO
	throw std::runtime_error((
		format(translate("Component type '{1}' is not registered"))
		% c_name.c_str()
	).str());
	*/
}
//------------------------------------------------------------------------------
#else
//------------------------------------------------------------------------------
[[noreturn]]
void mgr_handle_cmp_is_reg(const std::string&);
//------------------------------------------------------------------------------
[[noreturn]]
void mgr_handle_cmp_not_reg(const std::string&);
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
} // namespace ecs
} // namespace eagine
