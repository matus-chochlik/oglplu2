/**
 *  @file eagine/ecs/entity_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_ENTITY_TRAITS_1509260923_HPP
#define EAGINE_ECS_ENTITY_TRAITS_1509260923_HPP

namespace eagine {
namespace ecs {

template <typename Entity>
struct entity_traits
{
	typedef Entity parameter_type;

	static inline Entity minimum(void)
	noexcept
	{
		return Entity();
	}
};

template <typename Entity>
using entity_param_t = typename entity_traits<Entity>::parameter_type;

} // namespace ecs
} // namespace eagine

#endif //include guard

