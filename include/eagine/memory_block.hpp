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
#include "memory/typed_block.hpp"

namespace eagine {

template <bool IsConst>
using basic_memory_block = memory::basic_block<IsConst>;

typedef memory::block memory_block;;
typedef memory::const_block const_memory_block;

typedef memory::owned_block owned_memory_block;

template <typename T>
static inline
auto memory_block_of(T& x)
noexcept
{
	return memory::block_of(x);
}

using memory::as_span_of;

} // namespace eagine

#endif // include guard
