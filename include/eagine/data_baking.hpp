/**
 *  @file eagine/data_baking.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_DATA_BAKING_1509260923_HPP
#define EAGINE_DATA_BAKING_1509260923_HPP

#include "memory/alloc_arena.hpp"
#include "memory/stack_alloc.hpp"

namespace eagine {

class data_bake_arena
  : public memory::basic_allocation_arena<
      memory::stack_byte_allocator_only<memory::byte_alloc_managed_policy>> {
public:
    explicit data_bake_arena(memory::block blk)
      : memory::basic_allocation_arena<
	  memory::stack_byte_allocator_only<memory::byte_alloc_managed_policy>>(
	  blk) {
    }
};

} // namespace eagine

#endif // include guard
