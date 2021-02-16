/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_ECS_ENTITY_TRAITS_HPP
#define EAGINE_ECS_ENTITY_TRAITS_HPP

namespace eagine::ecs {

template <typename Entity>
struct entity_traits {
    using parameter_type = Entity;

    static auto minimum() noexcept -> Entity {
        return Entity();
    }
};

template <typename Entity>
using entity_param_t = typename entity_traits<Entity>::parameter_type;

} // namespace eagine::ecs

#endif // EAGINE_ECS_ENTITY_TRAITS_HPP
