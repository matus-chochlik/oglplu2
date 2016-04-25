/**
 *  @file eagine/memory/copy.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_COPY_1510290655_HPP
#define EAGINE_MEMORY_COPY_1510290655_HPP

#include "block.hpp"
#include <cstring>
#include <cassert>

namespace eagine {
namespace memory {

static inline
block copy(const_block source, block dest)
{
	assert(dest.size() >= source.size());
	std::memcpy(dest.data(), source.data(), source.size());
	return block(dest.data(), source.size());
}

} // namespace memory
} // namespace eagine

#endif // include guard
