/**
 *  @file eagine/ecs/storage.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_STORAGE_1509260923_HPP
#define EAGINE_ECS_STORAGE_1509260923_HPP

#include "entity_traits.hpp"
#include "storage_caps.hpp"
#include "../callable_ref.hpp"

namespace eagine {
namespace ecs {

template <typename Entity>
struct base_storage
{
	typedef entity_param_t<Entity> entity_param;

	virtual
	~base_storage(void) = default;

	virtual
	storage_caps capabilities(void) = 0;

	virtual
	bool has(entity_param) = 0;

	virtual
	bool is_hidden(entity_param) = 0;

	virtual
	bool hide(entity_param) = 0;

	virtual
	bool show(entity_param) = 0;

	virtual
	bool erase(entity_param) = 0;
};

template <typename Entity, typename Component>
struct component_storage
 : base_storage<Entity>
{
	typedef entity_param_t<Entity> entity_param;

	virtual
	bool store(entity_param, Component&&) = 0;

	virtual
	bool read_with(
		entity_param,
		callable_ref<bool(entity_param, const Component&)>
	) = 0;

	virtual
	bool modify_with(
		entity_param,
		callable_ref<bool(entity_param, Component&)>
	) = 0;
};

} // namespace ecs
} // namespace eagine

#endif //include guard

