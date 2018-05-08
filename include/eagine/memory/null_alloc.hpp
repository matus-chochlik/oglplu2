/**
 *  @file eagine/memory/null_alloc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_NULL_ALLOC_1509260923_HPP
#define EAGINE_MEMORY_NULL_ALLOC_1509260923_HPP

#include "byte_alloc.hpp"
#include <cassert>

namespace eagine {
namespace memory {

template <typename Policy = default_byte_allocator_policy>
class null_byte_allocator
  : public byte_allocator_impl<Policy, null_byte_allocator> {
public:
    typedef span_size_t size_type;

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
	assert(b.empty());
    }
};

} // namespace memory
} // namespace eagine

#endif // include guard
