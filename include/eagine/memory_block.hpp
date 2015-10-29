/**
 *  @file eagine/memory_block.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_BLOCK_1509260923_HPP
#define EAGINE_MEMORY_BLOCK_1509260923_HPP

#include "memory/block.hpp"

namespace eagine {

template <bool is_const>
using basic_memory_block = memory::basic_block<is_const>;

typedef memory::block memory_block;;
typedef memory::const_block const_memory_block;

typedef memory::owned_block owned_memory_block;

} // namespace eagine

#endif // include guard
