/**
 *  @file eagine/memory/shared_alloc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_SHARED_ALLOC_HPP
#define EAGINE_MEMORY_SHARED_ALLOC_HPP

#include "../nothing.hpp"
#include "byte_alloc.hpp"
#include <new>
#include <type_traits>
#include <typeinfo>
#include <utility>

namespace eagine {
namespace memory {

// shared_byte_allocator
template <typename Base>
class basic_shared_byte_alloc : public Base {
private:
    byte_allocator* _pballoc = nullptr;

    template <typename X>
    static byte_allocator* _get_new(
      X&& that,
      std::enable_if_t<std::is_convertible_v<X*, byte_allocator*>>* =
        nullptr) noexcept {
        try {
            return that.accomodate_self();
        } catch(std::bad_alloc&) {
        }
        return nullptr;
    }

    void _cleanup() noexcept {
        if(_pballoc) {
            if(_pballoc->release()) {
                _pballoc->eject_self();
            }
        }
    }

    byte_allocator* _release() noexcept {
        byte_allocator* result = _pballoc;
        _pballoc = nullptr;
        return result;
    }

    byte_allocator* _copy() const noexcept {
        return _pballoc ? _pballoc->duplicate() : nullptr;
    }

    explicit basic_shared_byte_alloc(byte_allocator* pballoc) noexcept
      : _pballoc(pballoc) {
    }

public:
    using value_type = byte;
    using size_type = span_size_t;

    basic_shared_byte_alloc() noexcept
      : basic_shared_byte_alloc(nullptr) {
    }

    basic_shared_byte_alloc(const basic_shared_byte_alloc& that) noexcept
      : basic_shared_byte_alloc(that._copy()) {
    }

    basic_shared_byte_alloc(basic_shared_byte_alloc&& tmp) noexcept
      : basic_shared_byte_alloc(tmp._release()) {
    }

    template <
      typename X,
      typename = std::enable_if_t<std::is_convertible_v<X*, byte_allocator*>>>
    basic_shared_byte_alloc(X&& x) noexcept
      : basic_shared_byte_alloc(_get_new(std::forward<X>(x))) {
    }

    basic_shared_byte_alloc& operator=(
      const basic_shared_byte_alloc& that) noexcept {
        _cleanup();
        _pballoc = that._copy();
        return *this;
    }

    basic_shared_byte_alloc& operator=(
      basic_shared_byte_alloc&& that) noexcept {
        _cleanup();
        _pballoc = that._release();
        return *this;
    }

    ~basic_shared_byte_alloc() noexcept {
        _cleanup();
    }

    explicit operator bool() const noexcept {
        return _pballoc != nullptr;
    }

    bool operator!() const noexcept {
        return _pballoc == nullptr;
    }

    size_type max_size(size_type a) const noexcept {
        return _pballoc ? _pballoc->max_size(a) : 0;
    }

    tribool has_allocated(const owned_block& b, size_type a) noexcept {
        return _pballoc ? _pballoc->has_allocated(b, a)
                        : bool(b) ? tribool{false} : tribool{indeterminate};
    }

    owned_block allocate(size_type n, size_type a) noexcept {
        return _pballoc ? _pballoc->allocate(n, a) : owned_block{};
    }

    void deallocate(owned_block&& b, size_type a) noexcept {
        if(_pballoc) {
            _pballoc->deallocate(std::move(b), a);
        }
        assert(b.empty());
    }

    bool can_reallocate(
      const owned_block& b, size_type n, size_type a) noexcept {
        return _pballoc ? _pballoc->can_reallocate(b, n, a) : (n == b.size());
    }

    owned_block reallocate(owned_block&& b, size_type n, size_type a) noexcept {
        if(_pballoc) {
            return _pballoc->reallocate(std::move(b), n, a);
        }
        assert(n == b.size());
        return std::move(b);
    }

    void do_reallocate(owned_block& b, size_type n, size_type a) noexcept {
        if(_pballoc) {
            return _pballoc->do_reallocate(b, n, a);
        }
        assert(n == b.size());
    }

    friend bool operator==(
      const basic_shared_byte_alloc& a,
      const basic_shared_byte_alloc& b) noexcept {
        if((a._pballoc == nullptr) && (b._pballoc == nullptr)) {
            return true;
        } else if(a._pballoc) {
            return a._pballoc->equal(b._pballoc);
        }
        return false;
    }

    friend bool operator!=(
      const basic_shared_byte_alloc& a,
      const basic_shared_byte_alloc& b) noexcept {
        return !(a == b);
    }

    template <typename ByteAlloc>
    ByteAlloc& as() {

        auto* pa = dynamic_cast<ByteAlloc*>(_pballoc);
        if(pa == nullptr) {
            throw std::bad_cast();
        }
        return *pa;
    }
};

using shared_byte_allocator = basic_shared_byte_alloc<nothing_t>;

} // namespace memory
} // namespace eagine

#endif // EAGINE_MEMORY_SHARED_ALLOC_HPP
