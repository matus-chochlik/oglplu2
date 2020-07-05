/**
 *  @file eagine/memory/null_alloc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_NULL_ALLOC_HPP
#define EAGINE_MEMORY_NULL_ALLOC_HPP

#include "../assert.hpp"
#include "byte_alloc.hpp"

namespace eagine::memory {

template <typename Policy = default_byte_allocator_policy>
class null_byte_allocator
  : public byte_allocator_impl<Policy, null_byte_allocator> {
public:
    using size_type = span_size_t;

    bool equal(byte_allocator* a) const noexcept override {
        return dynamic_cast<null_byte_allocator*>(a) != nullptr;
    }

    size_type max_size(size_type) noexcept override {
        return 0;
    }

    tribool has_allocated(const owned_block&, size_type) noexcept override {
        return indeterminate;
    }

    owned_block allocate(size_type, size_type) noexcept override {
        return {};
    }

    void deallocate(owned_block&& b, size_type) noexcept override {
        EAGINE_ASSERT(b.empty());
    }
};

} // namespace eagine::memory

#endif // EAGINE_MEMORY_NULL_ALLOC_HPP
