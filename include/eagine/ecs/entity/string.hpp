/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_ECS_ENTITY_STRING_HPP
#define EAGINE_ECS_ENTITY_STRING_HPP

#include "../entity_traits.hpp"
#include <string>

namespace eagine::ecs {

template <>
struct entity_traits<std::string> {
    using parameter_type = const std::string&;

    static inline auto minimum() noexcept -> std::string {
        return {};
    }
};

} // namespace eagine::ecs

#endif // EAGINE_ECS_ENTITY_STRING_HPP
