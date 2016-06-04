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
#include <cassert>

namespace eagine {
namespace ecs {

template <typename Entity>
struct storage_iterator_intf
{
	virtual
	~storage_iterator_intf(void) = default;

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
class storage_iterator
{
private:
	storage_iterator_intf<Entity>* _i;
public:
	storage_iterator(storage_iterator_intf<Entity>* i)
	noexcept
	 : _i(i)
	{
		assert(_i);
	}

	storage_iterator(const storage_iterator&) = delete;

	storage_iterator(storage_iterator&& tmp)
	noexcept
	 : _i(tmp._i)
	{
		tmp._i = nullptr;
	}

	~storage_iterator(void)
	noexcept
	{
		assert(_i == nullptr);
	}

	storage_iterator_intf<Entity>* release(void)
	{
		storage_iterator_intf<Entity>* p = _i;
		_i = nullptr;
		return p;
	}

	storage_iterator_intf<Entity>* ptr(void)
	noexcept
	{
		assert(_i);
		return _i;
	}

	storage_iterator_intf<Entity>& get(void)
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
struct base_storage
{
	typedef entity_param_t<Entity> entity_param;
	typedef storage_iterator<Entity> iterator_t;

	virtual
	~base_storage(void) = default;

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
 : base_storage<Entity>
{
	typedef entity_param_t<Entity> entity_param;
	typedef storage_iterator<Entity> iterator_t;

	virtual
	bool store(entity_param, Component&&) = 0;

	virtual
	bool apply_to(
		callable_ref<bool(entity_param, const Component&)>,
		entity_param
	) = 0;

	virtual
	bool apply_to(
		callable_ref<bool(entity_param, const Component&)>,
		iterator_t&
	) = 0;

	virtual
	bool apply_to(
		callable_ref<bool(entity_param, Component&)>,
		entity_param
	) = 0;

	virtual
	bool apply_to(
		callable_ref<bool(entity_param, Component&)>,
		iterator_t&
	) = 0;

	virtual
	void for_each(callable_ref<bool(entity_param, const Component&)>) = 0;

	virtual
	void for_each(callable_ref<bool(entity_param, Component&)>) = 0;
};

} // namespace ecs
} // namespace eagine

#endif //include guard

