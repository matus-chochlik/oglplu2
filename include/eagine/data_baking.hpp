/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_DATA_BAKING_HPP
#define EAGINE_DATA_BAKING_HPP

#include "memory/alloc_arena.hpp"
#include "memory/stack_alloc.hpp"

namespace eagine {
//------------------------------------------------------------------------------
using data_bake_arena_base = memory::basic_allocation_arena<
  memory::stack_byte_allocator_only<memory::byte_alloc_managed_policy>>;
//------------------------------------------------------------------------------
class data_bake_arena : public data_bake_arena_base {
public:
    explicit data_bake_arena(memory::block blk)
      : data_bake_arena_base(blk) {}

    auto baked_data() const noexcept -> memory::const_block {
        return this->allocator().allocated();
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_DATA_BAKING_HPP
