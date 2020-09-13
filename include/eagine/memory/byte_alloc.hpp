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

#include "../assert.hpp"
#include "../tribool.hpp"
#include "../types.hpp"
#include "block.hpp"
#include <cstdint>

namespace eagine::memory {

// byte_allocator
struct byte_allocator : block_owner {
    using value_type = byte;
    using size_type = span_size_t;

    byte_allocator() = default;
    byte_allocator(byte_allocator&&) noexcept = default;
    byte_allocator(const byte_allocator&) = default;
    auto operator=(byte_allocator&&) noexcept -> byte_allocator& = default;
    auto operator=(const byte_allocator&) -> byte_allocator& = default;

    virtual ~byte_allocator() noexcept = default;

    virtual auto duplicate() noexcept -> byte_allocator* = 0;

    virtual auto release() noexcept -> bool = 0;

    virtual auto equal(byte_allocator* a) const noexcept -> bool = 0;

    virtual auto max_size(size_type a) noexcept -> size_type = 0;

    virtual auto has_allocated(const owned_block& b, size_type a = 0) noexcept
      -> tribool = 0;

    virtual auto allocate(size_type n, size_type a) noexcept -> owned_block = 0;

    virtual void deallocate(owned_block&& b, size_type a = 0) noexcept = 0;

    virtual auto
    can_reallocate(const owned_block& b, size_type n, size_type a) noexcept
      -> bool = 0;

    virtual auto reallocate(owned_block&& b, size_type n, size_type a) noexcept
      -> owned_block = 0;

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
    inline auto duplicate(byte_allocator* that) noexcept -> byte_allocator* {
        return that;
    }

    inline auto release(byte_allocator*) noexcept -> bool {
        return false;
    }
};

// byte_alloc_ref_count_policy
class byte_alloc_ref_count_policy {
private:
    span_size_t _ref_count{1};

public:
    byte_alloc_ref_count_policy(const byte_alloc_ref_count_policy&) = delete;

    auto operator=(const byte_alloc_ref_count_policy&) = delete;
    auto operator=(byte_alloc_ref_count_policy&& tmp) = delete;

    byte_alloc_ref_count_policy() noexcept = default;

    byte_alloc_ref_count_policy(byte_alloc_ref_count_policy&& tmp) noexcept
      : _ref_count(tmp._ref_count) {
        tmp._ref_count = 0;
    }

    ~byte_alloc_ref_count_policy() noexcept {
        EAGINE_ASSERT(_ref_count == 0);
    }

    auto duplicate(byte_allocator* that) noexcept -> byte_allocator* {
        ++_ref_count;
        return that;
    }

    auto release(byte_allocator*) noexcept -> bool {
        return (--_ref_count == 0);
    }
};

// default_byte_allocator_policy
using default_byte_allocator_policy = byte_alloc_ref_count_policy;

// byte_allocator_impl
template <typename Policy, template <class...> class DerivedTpl, typename... Args>
class byte_allocator_impl : public byte_allocator {
private:
    Policy _policy;

    using Derived = DerivedTpl<Args..., Policy>;

    auto derived() -> Derived& {
        return *static_cast<Derived*>(this);
    }

public:
    using size_type = span_size_t;

    byte_allocator_impl() = default;
    byte_allocator_impl(byte_allocator_impl&&) noexcept(
      std::is_nothrow_move_constructible_v<Policy>) = default;
    byte_allocator_impl(const byte_allocator_impl&) = delete;

    auto operator=(byte_allocator_impl&&) noexcept(
      std::is_nothrow_move_assignable_v<Policy>)
      -> byte_allocator_impl& = default;
    auto operator=(const byte_allocator_impl&) = delete;

    ~byte_allocator_impl() noexcept override = default;

    auto duplicate() noexcept -> byte_allocator* override {
        return _policy.duplicate(this);
    }

    auto release() noexcept -> bool override {
        return _policy.release(this);
    }

    auto can_reallocate(const owned_block&, size_type, size_type) noexcept
      -> bool override {
        return false;
    }

    auto reallocate(owned_block&& b, size_type, size_type) noexcept
      -> owned_block override {
        return std::move(b);
    }

    template <typename Final>
    static auto accomodate_derived(Final& that) noexcept -> Final* {
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
          acquire_block(as_bytes(cover_one(that))), span_align_of<Final>());
    }

    auto accomodate_self() noexcept -> Derived* {
        return accomodate_derived(derived());
    }

    void eject_self() noexcept override {
        eject_derived(derived());
    }
};

} // namespace eagine::memory

#endif // EAGINE_MEMORY_BYTE_ALLOC_HPP
