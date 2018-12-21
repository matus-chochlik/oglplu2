/**
 *  @file eagine/memory/byte_alloc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_BYTE_ALLOC_HPP
#define EAGINE_MEMORY_BYTE_ALLOC_HPP

#include "../tribool.hpp"
#include "../types.hpp"
#include "block.hpp"
#include <cstdint>

namespace eagine {
namespace memory {

// byte_allocator
struct byte_allocator : block_owner {
    using value_type = byte;
    using size_type = span_size_t;

    byte_allocator() = default;
    byte_allocator(const byte_allocator&) = default;
    byte_allocator& operator=(const byte_allocator&) = default;

    virtual ~byte_allocator() noexcept = default;

    virtual byte_allocator* duplicate() noexcept = 0;

    virtual bool release() noexcept = 0;

    virtual bool equal(byte_allocator* a) const noexcept = 0;

    virtual size_type max_size(size_type a) noexcept = 0;

    virtual tribool has_allocated(
      const owned_block& b, size_type a = 0) noexcept = 0;

    virtual owned_block allocate(size_type n, size_type a) noexcept = 0;

    virtual void deallocate(owned_block&& b, size_type a = 0) noexcept = 0;

    virtual bool can_reallocate(
      const owned_block& b, size_type n, size_type a) noexcept = 0;

    virtual owned_block reallocate(
      owned_block&& b, size_type n, size_type a) noexcept = 0;

    void do_reallocate(owned_block& b, size_type n, size_type a) noexcept {
        if(b.size() != n) {
            if(can_reallocate(b, n, a)) {
                b = reallocate(std::move(b), n, a);
            } else {
                deallocate(std::move(b), a);
                b = allocate(n, a);
            }
        }
    }

    virtual void eject_self() noexcept = 0;
};

// byte_alloc_managed_policy
struct byte_alloc_managed_policy {
    inline byte_allocator* duplicate(byte_allocator* that) noexcept {
        return that;
    }

    inline bool release(byte_allocator*) noexcept {
        return false;
    }
};

// byte_alloc_ref_count_policy
class byte_alloc_ref_count_policy {
private:
    span_size_t _ref_count{1};

public:
    byte_alloc_ref_count_policy(const byte_alloc_ref_count_policy&) = delete;

    byte_alloc_ref_count_policy& operator=(const byte_alloc_ref_count_policy&) =
      delete;

    byte_alloc_ref_count_policy& operator=(byte_alloc_ref_count_policy&& tmp) =
      delete;

    byte_alloc_ref_count_policy() noexcept {
    }

    byte_alloc_ref_count_policy(byte_alloc_ref_count_policy&& tmp) noexcept
      : _ref_count(tmp._ref_count) {
        tmp._ref_count = 0;
    }

    ~byte_alloc_ref_count_policy() noexcept {
        assert(_ref_count == 0);
    }

    byte_allocator* duplicate(byte_allocator* that) noexcept {
        ++_ref_count;
        return that;
    }

    bool release(byte_allocator*) noexcept {
        return (--_ref_count == 0);
    }
};

// default_byte_allocator_policy
using default_byte_allocator_policy = byte_alloc_ref_count_policy;

// byte_allocator_impl
template <
  typename Policy,
  template <class...>
  class DerivedTpl,
  typename... Args>
class byte_allocator_impl : public byte_allocator {
private:
    Policy _policy;

    using Derived = DerivedTpl<Args..., Policy>;

    Derived& derived() {
        return *static_cast<Derived*>(this);
    }

public:
    using size_type = span_size_t;

    byte_allocator_impl() = default;
    byte_allocator_impl(byte_allocator_impl&&) = default;
    byte_allocator_impl(const byte_allocator_impl&) = delete;

    byte_allocator_impl& operator=(byte_allocator_impl&&) = default;
    byte_allocator_impl& operator=(const byte_allocator_impl&) = delete;

    byte_allocator* duplicate() noexcept override {
        return _policy.duplicate(this);
    }

    bool release() noexcept override {
        return _policy.release(this);
    }

    bool can_reallocate(
      const owned_block&, size_type, size_type) noexcept override {
        return false;
    }

    owned_block reallocate(
      owned_block&& b, size_type, size_type) noexcept override {
        return std::move(b);
    }

    template <typename Final>
    static Final* accomodate_derived(Final& that) noexcept {
        owned_block ob =
          that.allocate(span_size_of<Final>(), span_align_of<Final>());
        auto* const result = new(ob.begin()) Final(std::move(that));
        release_block(std::move(ob));
        return result;
    }

    template <typename Final>
    static void eject_derived(Final& that) noexcept {
        Final tmp = std::move(that);
        tmp.deallocate(
          acquire_block(as_bytes(coverOne(that))), span_align_of<Final>());
    }

    Derived* accomodate_self() noexcept {
        return accomodate_derived(derived());
    }

    void eject_self() noexcept override {
        eject_derived(derived());
    }
};

} // namespace memory
} // namespace eagine

#endif // EAGINE_MEMORY_BYTE_ALLOC_HPP
