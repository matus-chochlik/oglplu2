/**
 *  @file eagine/memory/c_realloc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_C_REALLOC_HPP
#define EAGINE_MEMORY_C_REALLOC_HPP

#include "byte_alloc.hpp"
#include <cassert>
#include <limits>

namespace eagine::memory {

// c_byte_reallocator
template <typename Policy = default_byte_allocator_policy>
class c_byte_reallocator
  : public byte_allocator_impl<Policy, c_byte_reallocator> {
public:
    using size_type = span_size_t;

    auto equal(byte_allocator* a) const noexcept -> bool override {
        return dynamic_cast<c_byte_reallocator*>(a) != nullptr;
    }

    auto max_size(size_type) noexcept -> size_type override {
        return std::numeric_limits<size_type>::max();
    }

    auto has_allocated(const owned_block&, size_type) noexcept
      -> tribool override {
        return indeterminate;
    }

    auto allocate(size_type n, size_type a) noexcept -> owned_block override;

    void deallocate(owned_block&& b, size_type) noexcept override;

    auto can_reallocate(const owned_block&, size_type, size_type) noexcept
      -> bool override {
        return true;
    }

    auto reallocate(owned_block&& b, size_type n, size_type a) noexcept
      -> owned_block override;
};

} // namespace eagine::memory

#include <eagine/memory/c_realloc.inl>

#endif // EAGINE_MEMORY_C_REALLOC_HPP
