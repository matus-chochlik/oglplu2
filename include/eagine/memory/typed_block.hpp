/**
 *  @file eagine/memory/typed_block.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_TYPED_BLOCK_1510290655_HPP
#define EAGINE_MEMORY_TYPED_BLOCK_1510290655_HPP

#include "block.hpp"
#include "../span.hpp"

namespace eagine {
namespace memory {

template <typename T>
static inline
span<T> as_span_of(const basic_block<std::is_const<T>::value>& blk)
{
	assert(blk.is_aligned_to(alignof(T)));
	return {
		static_cast<T*>(blk.addr()),
		span_size_type(blk.size()/sizeof(T))
	};
}

} // namespace memory
} // namespace eagine

#endif // include guard
