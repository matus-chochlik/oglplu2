/**
 *  @file eagine/memory/stack_alloc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_STACK_ALLOC_HPP
#define EAGINE_MEMORY_STACK_ALLOC_HPP

#include "byte_alloc.hpp"
#include <cassert>
#include <type_traits>

namespace eagine {
namespace memory {

// base_stack_allocator
// non-rebindable non-copyable stack allocator
// use with care!
template <typename T>
class base_stack_allocator : public block_owner {
private:
    T* _btm;
    T* _top;
    T* _pos;
    T* _min;
    span_size_t _dif{0};

    const_block _store() const noexcept;

    const_block _allocated() const noexcept;

    const_block _available() const noexcept;

public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = span_size_t;
    using difference_type = std::ptrdiff_t;

    base_stack_allocator(const base_stack_allocator&) = delete;

    base_stack_allocator(base_stack_allocator&& tmp) noexcept;

    base_stack_allocator() noexcept;

    base_stack_allocator(const block& blk, span_size_t align) noexcept;

    base_stack_allocator(const block& blk) noexcept;

    ~base_stack_allocator() noexcept;

    size_type max_size() const noexcept {
        return _available().size();
    }

    size_type allocated_size() const noexcept {
        return _allocated().size();
    }

    tribool has_allocated(const owned_block& b) const noexcept;

    owned_block allocate(size_type n) noexcept;

    owned_block truncate(owned_block&& b, size_type nn) noexcept;

    void deallocate(owned_block&& b) noexcept;

    friend bool operator==(
      const base_stack_allocator& a, const base_stack_allocator& b) noexcept {
        if((a._btm == b._btm) && (a._top == b._top)) {
            assert(a._pos == b._pos);
            assert(a._min == b._min);
            assert(a._dif == b._dif);

            return true;
        }
        return false;
    }
};

// stack_byte_allocator_only
template <typename Policy = default_byte_allocator_policy>
class stack_byte_allocator_only
  : public byte_allocator_impl<Policy, stack_byte_allocator_only> {
private:
    base_stack_allocator<byte> _alloc;

public:
    using value_type = byte;
    using size_type = span_size_t;

    stack_byte_allocator_only(stack_byte_allocator_only&&) = default;
    stack_byte_allocator_only(const block& blk)
      : _alloc(blk) {
    }

    bool equal(byte_allocator* a) const noexcept override;

    size_type max_size(size_type) noexcept override {
        return _alloc.max_size();
    }

    tribool has_allocated(const owned_block& b, span_size_t) noexcept override {
        return _alloc.has_allocated(b);
    }

    owned_block allocate(size_type n, size_type a) noexcept override;

    void deallocate(owned_block&& b, size_type) noexcept override;
};

// stack_byte_allocator
template <typename Policy = default_byte_allocator_policy>
class stack_byte_allocator
  : public byte_allocator_impl<Policy, stack_byte_allocator> {
private:
    base_stack_allocator<byte> _alloc;

public:
    using value_type = byte;
    using size_type = span_size_t;

    stack_byte_allocator(stack_byte_allocator&&) = default;
    stack_byte_allocator(const block& blk)
      : _alloc(blk) {
    }

    bool equal(byte_allocator* a) const noexcept override;

    size_type max_size(size_type a) noexcept override {
        return _alloc.max_size() > a ? _alloc.max_size() - a : 0;
    }

    tribool has_allocated(const owned_block& b, span_size_t) noexcept override {
        return _alloc.has_allocated(b);
    }

    owned_block allocate(size_type n, size_type a) noexcept override;

    void deallocate(owned_block&& b, size_type) noexcept override;
};

// stack_aligned_byte_allocator
template <typename Policy = default_byte_allocator_policy>
class stack_aligned_byte_allocator
  : public byte_allocator_impl<Policy, stack_aligned_byte_allocator> {
private:
    span_size_t _align;

    base_stack_allocator<byte> _alloc;
    using _this_class = stack_aligned_byte_allocator;

public:
    using value_type = byte;
    using size_type = span_size_t;

    stack_aligned_byte_allocator(stack_aligned_byte_allocator&&) = default;

    stack_aligned_byte_allocator(const block& blk, span_size_t align)
      : _align(align)
      , _alloc(blk, _align) {
    }

    bool equal(byte_allocator* a) const noexcept override;

    size_type max_size(size_type) noexcept override {
        return _alloc.max_size();
    }

    tribool has_allocated(const owned_block& b, span_size_t) noexcept override;

    owned_block allocate(size_type n, size_type a) noexcept override;

    void deallocate(owned_block&& b, size_type a) noexcept override;

    span_size_t _own_end_misalign(_this_class* p) const noexcept;

    byte_allocator* accomodate_self() noexcept;

    void eject_self() noexcept override;
};

} // namespace memory
} // namespace eagine

#include <eagine/memory/stack_alloc.inl>

#endif // EAGINE_MEMORY_STACK_ALLOC_HPP
