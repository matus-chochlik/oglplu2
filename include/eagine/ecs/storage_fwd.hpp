/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_ECS_STORAGE_FWD_HPP
#define EAGINE_ECS_STORAGE_FWD_HPP

namespace eagine::ecs {

template <typename Entity, bool IsRelation>
struct storage_iterator_intf;

template <typename Entity>
using component_storage_iterator_intf = storage_iterator_intf<Entity, false>;

template <typename Entity>
using relation_storage_iterator_intf = storage_iterator_intf<Entity, true>;

template <typename Entity, bool IsRelation>
class storage_iterator;

template <typename Entity>
using component_storage_iterator = storage_iterator<Entity, false>;

template <typename Entity>
using relation_storage_iterator = storage_iterator<Entity, true>;

template <typename Entity, bool IsRelation>
struct base_storage;

template <typename Entity>
using base_component_storage = base_storage<Entity, false>;

template <typename Entity>
using base_relation_storage = base_storage<Entity, true>;

template <typename Entity, typename Data, bool IsRelation>
struct storage;

template <typename Entity, typename Data>
using component_storage = storage<Entity, Data, false>;

template <typename Entity, typename Data>
using relation_storage = storage<Entity, Data, true>;

} // namespace eagine::ecs

#endif // EAGINE_ECS_STORAGE_FWD_HPP
