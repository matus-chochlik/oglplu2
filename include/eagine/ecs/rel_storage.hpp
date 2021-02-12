/// @file eagine/ecs/rel_storage.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
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
    storage_iterator_intf() noexcept = default;
    storage_iterator_intf(storage_iterator_intf&&) noexcept = default;
    storage_iterator_intf(const storage_iterator_intf&) = delete;
    auto operator=(storage_iterator_intf&&) = delete;
    auto operator=(const storage_iterator_intf&) = delete;

    virtual ~storage_iterator_intf() noexcept = default;

    virtual auto reset() -> void = 0;

    virtual auto done() -> bool = 0;

    virtual void next() = 0;

    virtual auto subject() -> Entity = 0;

    virtual auto object() -> Entity = 0;
};

template <typename Entity>
class storage_iterator<Entity, true> {
private:
    storage_iterator_intf<Entity, true>* _i{nullptr};

public:
    storage_iterator(storage_iterator_intf<Entity, true>* i) noexcept
      : _i(i) {
        EAGINE_ASSERT(_i);
    }

    storage_iterator(storage_iterator&& tmp) noexcept
      : _i{std::exchange(tmp._i, nullptr)} {}
    storage_iterator(const storage_iterator&) = delete;

    auto operator=(storage_iterator&&) = delete;
    auto operator=(const storage_iterator&) = delete;

    ~storage_iterator() noexcept {
        EAGINE_ASSERT(_i == nullptr);
    }

    auto release() -> storage_iterator_intf<Entity, true>* {
        return std::exchange(_i, nullptr);
    }

    auto ptr() noexcept -> storage_iterator_intf<Entity, true>* {
        EAGINE_ASSERT(_i);
        return _i;
    }

    auto get() noexcept -> storage_iterator_intf<Entity, true>& {
        EAGINE_ASSERT(_i);
        return *_i;
    }

    void reset() {
        get().reset();
    }

    auto done() -> bool {
        return get().done();
    }

    void next() {
        get().next();
    }

    auto subject() -> Entity {
        return get().subject();
    }

    auto object() -> Entity {
        return get().object();
    }
};

template <typename Entity>
struct base_storage<Entity, true> {
    using entity_param = entity_param_t<Entity>;
    using iterator_t = storage_iterator<Entity, true>;

    base_storage() noexcept = default;
    base_storage(base_storage&&) noexcept = default;
    base_storage(const base_storage&) = delete;
    auto operator=(base_storage&&) = delete;
    auto operator=(const base_storage&) = delete;

    virtual ~base_storage() noexcept = default;

    virtual auto capabilities() -> storage_caps = 0;

    virtual auto new_iterator() -> iterator_t = 0;

    virtual void delete_iterator(iterator_t&&) = 0;

    virtual auto has(entity_param subject, entity_param object) -> bool = 0;

    virtual auto store(entity_param subject, entity_param object) -> bool = 0;

    virtual auto remove(entity_param subject, entity_param object) -> bool = 0;

    virtual void remove(iterator_t&) = 0;

    virtual void for_each(
      callable_ref<void(entity_param, entity_param)>,
      entity_param subject) = 0;

    virtual void for_each(callable_ref<void(entity_param, entity_param)>) = 0;
};

template <typename Entity, typename Relation>
struct storage<Entity, Relation, true> : base_storage<Entity, true> {
    using entity_param = entity_param_t<Entity>;
    using iterator_t = storage_iterator<Entity, true>;

    using base_storage<Entity, true>::store;

    virtual auto store(entity_param subject, entity_param object, Relation &&)
      -> bool = 0;

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
      callable_ref<void(entity_param, entity_param, manipulator<Relation>&)>) = 0;
};

} // namespace eagine::ecs

#endif // EAGINE_ECS_REL_STORAGE_HPP
