/**
 *  @example eagine/ecs/elements/init.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_EXAMPLE_ECS_INIT_HPP // NOLINT(llvm-header-guard)
#define EAGINE_EXAMPLE_ECS_INIT_HPP

#include "entity.hpp"
#include <eagine/ecs/basic_manager.hpp>
#include <eagine/ecs/entity/string.hpp>
#include <eagine/value_tree/wrappers.hpp>

namespace eagine {
//------------------------------------------------------------------------------
void initialize(
  ecs::basic_manager<element_symbol>& elements,
  const valtree::compound& source);
//------------------------------------------------------------------------------
} // namespace eagine

#endif
