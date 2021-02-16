/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_COPY_HPP
#define EAGINE_MEMORY_COPY_HPP

#include "../assert.hpp"
#include "block.hpp"
#include "buffer.hpp"
#include <cstring>

namespace eagine::memory {

static inline auto copy(const_block source, block dest) -> block {
    EAGINE_ASSERT(dest.size() >= source.size());
    std::memcpy(dest.data(), source.data(), std_size(source.size()));
    return block(dest.data(), source.size());
}

static inline auto copy_into(const_block source, buffer& dest) -> block {
    dest.resize(source.size());
    return copy(source, cover(dest));
}

} // namespace eagine::memory

#endif // EAGINE_MEMORY_COPY_HPP
