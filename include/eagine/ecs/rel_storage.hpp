/**
 *  @file eagine/ecs/rel_storage.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_REL_STORAGE_HPP
#define EAGINE_ECS_REL_STORAGE_HPP

#include "../assert.hpp"
#include "../callable_ref.hpp"
#include "entity_traits.hpp"
#include "manipulator.hpp"
#include "storage_caps.hpp"
#include "storage_fwd.hpp"

namespace eagine::ecs {

template <typename Entity>
struct storage_iterator_intf<Entity, true> {
    virtual ~storage_iterator_intf() = default;

    virtual void reset() = 0;

    virtual bool done() = 0;

    virtual void next() = 0;

    virtual Entity subject() = 0;

    virtual Entity object() = 0;
};

template <typename Entity>
class storage_iterator<Entity, true> {
private:
    storage_iterator_intf<Entity, true>* _i;

public:
    storage_iterator(storage_iterator_intf<Entity, true>* i) noexcept
      : _i(i) {
        EAGINE_ASSERT(_i);
    }

    storage_iterator(const storage_iterator&) = delete;

    storage_iterator(storage_iterator&& tmp) noexcept
      : _i(tmp._i) {
        tmp._i = nullptr;
    }

    ~storage_iterator() noexcept {
        EAGINE_ASSERT(_i == nullptr);
    }

    storage_iterator_intf<Entity, true>* release() {
        storage_iterator_intf<Entity, true>* p = _i;
        _i = nullptr;
        return p;
    }

    storage_iterator_intf<Entity, true>* ptr() noexcept {
        EAGINE_ASSERT(_i);
        return _i;
    }

    storage_iterator_intf<Entity, true>& get() noexcept {
        EAGINE_ASSERT(_i);
        return *_i;
    }

    void reset() {
        get().reset();
    }

    bool done() {
        return get().done();
    }

    void next() {
        get().next();
    }

    Entity subject() {
        return get().subject();
    }

    Entity object() {
        return get().object();
    }
};

template <typename Entity>
struct base_storage<Entity, true> {
    using entity_param = entity_param_t<Entity>;
    using iterator_t = storage_iterator<Entity, true>;

    virtual ~base_storage() = default;

    virtual storage_caps capabilities() = 0;

    virtual iterator_t new_iterator() = 0;

    virtual void delete_iterator(iterator_t&&) = 0;

    virtual bool has(entity_param subject, entity_param object) = 0;

    virtual bool store(entity_param subject, entity_param object) = 0;

    virtual bool remove(entity_param subject, entity_param object) = 0;

    virtual void remove(iterator_t&) = 0;

    virtual void for_each(
      callable_ref<void(entity_param, entity_param)>, entity_param subject) = 0;

    virtual void for_each(callable_ref<void(entity_param, entity_param)>) = 0;
};

template <typename Entity, typename Relation>
struct storage<Entity, Relation, true> : base_storage<Entity, true> {
    using entity_param = entity_param_t<Entity>;
    using iterator_t = storage_iterator<Entity, true>;

    using base_storage<Entity, true>::store;

    virtual bool store(
      entity_param subject, entity_param object, Relation&&) = 0;

    virtual void for_single(
      callable_ref<
        void(entity_param, entity_param, manipulator<const Relation>&)>,
      entity_param subject,
      entity_param object) = 0;

    virtual void for_single(
      callable_ref<
        void(entity_param, entity_param, manipulator<const Relation>&)>,
      iterator_t&) = 0;

    virtual void for_single(
      callable_ref<void(entity_param, entity_param, manipulator<Relation>&)>,
      entity_param subject,
      entity_param object) = 0;

    virtual void for_single(
      callable_ref<void(entity_param, entity_param, manipulator<Relation>&)>,
      iterator_t&) = 0;

    using base_storage<Entity, true>::for_each;

    virtual void for_each(
      callable_ref<
        void(entity_param, entity_param, manipulator<const Relation>&)>,
      entity_param subject) = 0;

    virtual void for_each(
      callable_ref<void(entity_param, entity_param, manipulator<Relation>&)>,
      entity_param subject) = 0;

    virtual void for_each(
      callable_ref<
        void(entity_param, entity_param, manipulator<const Relation>&)>) = 0;

    virtual void for_each(
      callable_ref<
        void(entity_param, entity_param, manipulator<Relation>&)>) = 0;
};

} // namespace eagine::ecs

#endif // EAGINE_ECS_REL_STORAGE_HPP
