/**
 *  @file eagine/ecs/cmp_storage.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_CMP_STORAGE_1509260923_HPP
#define EAGINE_ECS_CMP_STORAGE_1509260923_HPP

#include "entity_traits.hpp"
#include "storage_caps.hpp"
#include "manipulator.hpp"
#include "../callable_ref.hpp"
#include <cassert>

namespace eagine {
namespace ecs {

template <typename Entity>
struct component_storage_iterator_intf
{
	virtual
	~component_storage_iterator_intf(void) = default;

	virtual
	void reset(void) = 0;

	virtual
	bool done(void) = 0;

	virtual
	void next(void) = 0;

	virtual
	bool find(Entity) = 0;

	virtual
	Entity current(void) = 0;
};

template <typename Entity>
class component_storage_iterator
{
private:
	component_storage_iterator_intf<Entity>* _i;
public:
	component_storage_iterator(component_storage_iterator_intf<Entity>* i)
	noexcept
	 : _i(i)
	{
		assert(_i);
	}

	component_storage_iterator(const component_storage_iterator&) = delete;

	component_storage_iterator(component_storage_iterator&& tmp)
	noexcept
	 : _i(tmp._i)
	{
		tmp._i = nullptr;
	}

	~component_storage_iterator(void)
	noexcept
	{
		assert(_i == nullptr);
	}

	component_storage_iterator_intf<Entity>* release(void)
	{
		component_storage_iterator_intf<Entity>* p = _i;
		_i = nullptr;
		return p;
	}

	component_storage_iterator_intf<Entity>* ptr(void)
	noexcept
	{
		assert(_i);
		return _i;
	}

	component_storage_iterator_intf<Entity>& get(void)
	noexcept
	{
		assert(_i);
		return *_i;
	}

	void reset(void)
	{
		get().reset();
	}

	bool done(void)
	{
		return get().done();
	}

	void next(void)
	{
		get().next();
	}

	bool find(Entity e)
	{
		return get().find(e);
	}

	Entity current(void)
	{
		return get().current();
	}
};

template <typename Entity>
struct base_component_storage
{
	typedef entity_param_t<Entity> entity_param;
	typedef component_storage_iterator<Entity> iterator_t;

	virtual
	~base_component_storage(void) = default;

	virtual
	storage_caps capabilities(void) = 0;

	virtual
	iterator_t new_iterator(void) = 0;

	virtual
	void delete_iterator(iterator_t&&) = 0;

	virtual
	bool has(entity_param) = 0;

	virtual
	bool is_hidden(entity_param) = 0;

	virtual
	bool is_hidden(iterator_t&) = 0;

	virtual
	bool hide(entity_param) = 0;

	virtual
	void hide(iterator_t&) = 0;

	virtual
	bool show(entity_param) = 0;

	virtual
	bool show(iterator_t&) = 0;

	virtual
	bool copy(entity_param from, entity_param to) = 0;

	virtual
	bool swap(entity_param a, entity_param b) = 0;

	virtual
	bool remove(entity_param) = 0;
};

template <typename Entity, typename Component>
struct component_storage
 : base_component_storage<Entity>
{
	typedef entity_param_t<Entity> entity_param;
	typedef component_storage_iterator<Entity> iterator_t;

	virtual
	bool store(entity_param, Component&&) = 0;

	virtual
	void for_single(
		callable_ref<void(entity_param, manipulator<const Component>&)>,
		entity_param
	) = 0;

	virtual
	void for_single(
		callable_ref<void(entity_param, manipulator<const Component>&)>,
		iterator_t&
	) = 0;

	virtual
	void for_single(
		callable_ref<void(entity_param, manipulator<Component>&)>,
		entity_param
	) = 0;

	virtual
	void for_single(
		callable_ref<void(entity_param, manipulator<Component>&)>,
		iterator_t&
	) = 0;

	virtual
	void for_each(
		callable_ref<void(entity_param, manipulator<const Component>&)>
	) = 0;

	virtual
	void for_each(
		callable_ref<void(entity_param, manipulator<Component>&)>
	) = 0;
};

} // namespace ecs
} // namespace eagine

#endif //include guard

