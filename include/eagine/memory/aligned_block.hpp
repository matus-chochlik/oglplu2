/**
 *  @file eagine/memory/aligned_block.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_ALIGNED_BLOCK_HPP
#define EAGINE_MEMORY_ALIGNED_BLOCK_HPP

#include "block.hpp"
#include <type_traits>

namespace eagine::memory {
//------------------------------------------------------------------------------

template <std::size_t Size>
struct aligned_block {
    std::aligned_storage_t<Size> _storage{};

public:
    block get() noexcept {
        return as_bytes(cover_one(_storage));
    }

    operator block() noexcept {
        return get();
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_ALIGNED_BLOCK_HPP
