/**
 *  @file eagine/ecs/cmp_storage.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_CMP_STORAGE_HPP
#define EAGINE_ECS_CMP_STORAGE_HPP

#include "../assert.hpp"
#include "../callable_ref.hpp"
#include "entity_traits.hpp"
#include "manipulator.hpp"
#include "storage_caps.hpp"
#include "storage_fwd.hpp"
#include <cassert>

namespace eagine::ecs {
//------------------------------------------------------------------------------
template <typename Entity>
struct storage_iterator_intf<Entity, false> {

    storage_iterator_intf() noexcept = default;
    storage_iterator_intf(storage_iterator_intf&&) noexcept = default;
    storage_iterator_intf(const storage_iterator_intf&) = delete;
    storage_iterator_intf& operator=(storage_iterator_intf&&) = delete;
    storage_iterator_intf& operator=(const storage_iterator_intf&) = delete;
    virtual ~storage_iterator_intf() = default;

    virtual void reset() = 0;

    virtual bool done() = 0;

    virtual void next() = 0;

    virtual bool find(Entity) = 0;

    virtual Entity current() = 0;
};
//------------------------------------------------------------------------------
template <typename Entity>
class storage_iterator<Entity, false> {
private:
    storage_iterator_intf<Entity, false>* _i{nullptr};

public:
    storage_iterator(storage_iterator_intf<Entity, false>* i) noexcept
      : _i(i) {
        EAGINE_ASSERT(_i);
    }

    storage_iterator(storage_iterator&& tmp) noexcept
      : _i(tmp._i) {
        tmp._i = nullptr;
    }

    storage_iterator(const storage_iterator&) = delete;
    storage_iterator& operator=(storage_iterator&&) = delete;
    storage_iterator& operator=(const storage_iterator&) = delete;

    ~storage_iterator() noexcept {
        EAGINE_ASSERT(_i == nullptr);
    }

    storage_iterator_intf<Entity, false>* release() {
        storage_iterator_intf<Entity, false>* p = _i;
        _i = nullptr;
        return p;
    }

    storage_iterator_intf<Entity, false>* ptr() noexcept {
        EAGINE_ASSERT(_i);
        return _i;
    }

    storage_iterator_intf<Entity, false>& get() noexcept {
        EAGINE_ASSERT(_i);
        return *_i;
    }

    void reset() {
        get().reset();
    }

    bool done() {
        return get().done();
    }

    auto& next() {
        get().next();
        return *this;
    }

    bool find(Entity e) {
        return get().find(e);
    }

    Entity current() {
        return get().current();
    }
};
//------------------------------------------------------------------------------
template <typename Entity>
struct base_storage<Entity, false> {
    using entity_param = entity_param_t<Entity>;
    using iterator_t = storage_iterator<Entity, false>;

    base_storage() noexcept = default;
    base_storage(base_storage&&) noexcept = default;
    base_storage(const base_storage&) = delete;
    base_storage& operator=(base_storage&&) = delete;
    base_storage& operator=(const base_storage&) = delete;
    virtual ~base_storage() = default;

    virtual storage_caps capabilities() = 0;

    virtual iterator_t new_iterator() = 0;

    virtual void delete_iterator(iterator_t&&) = 0;

    virtual bool has(entity_param) = 0;

    virtual bool is_hidden(entity_param) = 0;

    virtual bool is_hidden(iterator_t&) = 0;

    virtual bool hide(entity_param) = 0;

    virtual void hide(iterator_t&) = 0;

    virtual bool show(entity_param) = 0;

    virtual bool show(iterator_t&) = 0;

    virtual bool copy(entity_param from, entity_param to) = 0;

    virtual bool swap(entity_param a, entity_param b) = 0;

    virtual bool remove(entity_param) = 0;

    virtual void remove(iterator_t&) = 0;
};
//------------------------------------------------------------------------------
template <typename Entity, typename Component>
struct storage<Entity, Component, false> : base_storage<Entity, false> {
    using entity_param = entity_param_t<Entity>;
    using iterator_t = storage_iterator<Entity, false>;

    virtual bool store(entity_param, Component&&) = 0;

    virtual bool store(iterator_t&, entity_param, Component&&) = 0;

    virtual void for_single(
      callable_ref<void(entity_param, manipulator<const Component>&)>,
      entity_param) = 0;

    virtual void for_single(
      callable_ref<void(entity_param, manipulator<const Component>&)>,
      iterator_t&) = 0;

    virtual void for_single(
      callable_ref<void(entity_param, manipulator<Component>&)>,
      entity_param) = 0;

    virtual void for_single(
      callable_ref<void(entity_param, manipulator<Component>&)>,
      iterator_t&) = 0;

    virtual void for_each(
      callable_ref<void(entity_param, manipulator<const Component>&)>) = 0;

    virtual void for_each(
      callable_ref<void(entity_param, manipulator<Component>&)>) = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine::ecs

#endif // EAGINE_ECS_CMP_STORAGE_HPP
