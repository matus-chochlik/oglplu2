/**
 *  @file eagine/ecs/component.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_COMPONENT_1509260923_HPP
#define EAGINE_ECS_COMPONENT_1509260923_HPP

#include <cstddef>
#include <vector>
#include "../config/basic.hpp"
#include "../std/type_traits.hpp"

namespace eagine {
namespace ecs {

// component unique identifier
typedef unsigned component_uid_t;

// component_uid_getter
template <bool IsRelation>
class component_uid_getter {
private:
    static component_uid_t& _curr_uid(void);

public:
    static inline component_uid_t new_uid(void) {
        return _curr_uid()++;
    }
};

// component_uid
template <typename Derived, bool IsRelation>
struct component_uid {
    static component_uid_t value(void) {
        static component_uid_t cid =
          component_uid_getter<IsRelation>::new_uid();
        return cid;
    }

    component_uid_t operator()(void) const {
        return value();
    }
};

// entity_data
template <typename Derived, bool IsRelation>
struct entity_data {
    static component_uid<Derived, IsRelation> _uid;
};

template <typename Derived, bool IsRelation>
component_uid<Derived, IsRelation> entity_data<Derived, IsRelation>::_uid = {};

// component - base class
template <typename Derived>
using component = entity_data<Derived, false>;

// relation - base class
template <typename Derived>
using relation = entity_data<Derived, true>;

// get_component_uid
template <typename X>
static inline component_uid_t
get_component_uid(void) {
    typedef std::remove_const_t<std::remove_reference_t<X>> Component;
    return Component::_uid();
}

// component_uid_map
template <typename T>
class component_uid_map {
private:
    std::vector<T> _storage;

public:
    component_uid_map(void) = default;

    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;
    typedef typename std::vector<T>::difference_type difference_type;

    const_iterator begin(void) const {
        return _storage.begin();
    }

    iterator begin(void) {
        return _storage.begin();
    }

    const_iterator end(void) const {
        return _storage.end();
    }

    iterator end(void) {
        return _storage.end();
    }

    const_iterator find(component_uid_t cid) const {
        if(cid < _storage.size()) {
            return _storage.begin() + difference_type(cid);
        } else
            return _storage.end();
    }

    iterator find(component_uid_t cid) {
        if(cid < _storage.size()) {
            return _storage.begin() + difference_type(cid);
        } else
            return _storage.end();
    }

    void erase(iterator pos) {
        *pos = T();
    }

    T& operator[](component_uid_t cid) {
        if(cid >= _storage.size()) {
            _storage.resize(cid + 1);
        }
        return _storage[cid];
    }
};

} // namespace ecs
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/ecs/component.inl>
#endif

#endif // include guard
