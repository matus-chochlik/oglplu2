/**
 *  @file eagine/ecs/component.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_COMPONENT_HPP
#define EAGINE_ECS_COMPONENT_HPP

#include "../config/basic.hpp"
#include "../flat_map.hpp"
#include "../identifier_t.hpp"
#include "../optional_ref.hpp"
#include <type_traits>

namespace eagine::ecs {

// component unique identifier
using component_uid_t = identifier_t;

// entity_data
template <typename Derived, bool IsRelation>
struct entity_data {
    static constexpr inline bool component_uid() noexcept {
        return Derived::uid();
    }

    static constexpr inline bool is_relation() noexcept {
        return IsRelation;
    }
};

// component - base class
template <typename Derived>
using component = entity_data<Derived, false>;

// relation - base class
template <typename Derived>
using relation = entity_data<Derived, true>;

// component_uid_map
template <typename T>
class component_uid_map {
private:
    flat_map<component_uid_t, T> _storage{};

public:
    optional_reference_wrapper<T> find(component_uid_t cid) noexcept {
        const auto pos{_storage.find(cid)};
        if(pos != _storage.end()) {
            return {pos->second};
        }
        return {nothing};
    }

    optional_reference_wrapper<const T> find(
      component_uid_t cid) const noexcept {
        const auto pos{_storage.find(cid)};
        if(pos != _storage.end()) {
            return {pos->second};
        }
        return {nothing};
    }

    template <typename... Args>
    bool emplace(component_uid_t cid, Args&&... args) {
        return _storage.emplace(cid, std::forward<Args>(args)...).second;
    }

    auto erase(component_uid_t cid) {
        return _storage.erase(cid);
    }

    T& operator[](component_uid_t cid) {
        return _storage[cid];
    }
};

} // namespace eagine::ecs

#endif // EAGINE_ECS_COMPONENT_HPP
