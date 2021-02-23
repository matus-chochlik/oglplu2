/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_SHARED_ALLOC_HPP
#define EAGINE_MEMORY_SHARED_ALLOC_HPP

#include "../assert.hpp"
#include "../nothing.hpp"
#include "byte_alloc.hpp"
#include <new>
#include <type_traits>
#include <typeinfo>
#include <utility>

namespace eagine::memory {

// shared_byte_allocator
template <typename Base>
class basic_shared_byte_alloc : public Base {
public:
    using value_type = byte;
    using size_type = span_size_t;

    template <typename X>
    static constexpr const bool is_compatible_v =
      std::is_convertible_v<std::decay_t<X>*, byte_allocator*>;

    template <typename X, typename T = void>
    using enable_if_compatible_t = std::enable_if_t<is_compatible_v<X>, T>;

    basic_shared_byte_alloc() noexcept
      : basic_shared_byte_alloc(nullptr) {}

    basic_shared_byte_alloc(const basic_shared_byte_alloc& that) noexcept
      : basic_shared_byte_alloc(that._copy()) {}

    basic_shared_byte_alloc(basic_shared_byte_alloc&& tmp) noexcept
      : basic_shared_byte_alloc(tmp._release()) {}

    template <typename X, typename = enable_if_compatible_t<X>>
    basic_shared_byte_alloc(X&& x) noexcept
      : basic_shared_byte_alloc(_get_new(std::forward<X>(x))) {}

    auto operator=(basic_shared_byte_alloc&& that) noexcept -> auto& {
        if(this != std::addressof(that)) {
            _cleanup();
            _pballoc = that._release();
        }
        return *this;
    }

    // NOLINTNEXTLINE(bugprone-unhandled-self-assignment,cert-oop54-cpp)
    auto operator=(const basic_shared_byte_alloc& that) noexcept -> auto& {
        if(this != std::addressof(that)) {
            _cleanup();
            _pballoc = that._copy();
        }
        return *this;
    }

    ~basic_shared_byte_alloc() noexcept {
        _cleanup();
    }

    explicit operator bool() const noexcept {
        return _pballoc != nullptr;
    }

    auto max_size(size_type a) const noexcept -> size_type {
        return _pballoc ? _pballoc->max_size(a) : 0;
    }

    auto has_allocated(const owned_block& b, size_type a) noexcept -> tribool {
        return _pballoc ? _pballoc->has_allocated(b, a)
                        : bool(b) ? tribool{false} : tribool{indeterminate};
    }

    auto allocate(size_type n, size_type a) noexcept -> owned_block {
        return _pballoc ? _pballoc->allocate(n, a) : owned_block{};
    }

    void deallocate(owned_block&& b, size_type a) noexcept {
        if(_pballoc) {
            _pballoc->deallocate(std::move(b), a);
        }
    }

    auto can_reallocate(const owned_block& b, size_type n, size_type a) noexcept
      -> bool {
        return _pballoc ? _pballoc->can_reallocate(b, n, a) : (n == b.size());
    }

    auto reallocate(owned_block&& b, size_type n, size_type a) noexcept
      -> owned_block {
        if(_pballoc) {
            return _pballoc->reallocate(std::move(b), n, a);
        }
        EAGINE_ASSERT(n == b.size());
        return std::move(b);
    }

    void do_reallocate(owned_block& b, size_type n, size_type a) noexcept {
        if(_pballoc) {
            return _pballoc->do_reallocate(b, n, a);
        }
        EAGINE_ASSERT(n == b.size());
    }

    friend auto operator==(
      const basic_shared_byte_alloc& a,
      const basic_shared_byte_alloc& b) noexcept {
        if((a._pballoc == nullptr) && (b._pballoc == nullptr)) {
            return true;
        } else if(a._pballoc) {
            return a._pballoc->equal(b._pballoc);
        }
        return false;
    }

    friend auto operator!=(
      const basic_shared_byte_alloc& a,
      const basic_shared_byte_alloc& b) noexcept {
        return !(a == b);
    }

    template <typename ByteAlloc>
    auto as() -> ByteAlloc& {
        auto* pa = dynamic_cast<ByteAlloc*>(_pballoc);
        if(pa == nullptr) {
            throw std::bad_cast();
        }
        return *pa;
    }

private:
    byte_allocator* _pballoc{nullptr};

    template <typename X>
    static auto _get_new(X&& that) noexcept
      -> enable_if_compatible_t<X, byte_allocator*> {
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

    auto _release() noexcept -> byte_allocator* {
        byte_allocator* result = _pballoc;
        _pballoc = nullptr;
        return result;
    }

    auto _copy() const noexcept -> byte_allocator* {
        return _pballoc ? _pballoc->duplicate() : nullptr;
    }

    explicit basic_shared_byte_alloc(byte_allocator* pballoc) noexcept
      : _pballoc{pballoc} {}
};

using shared_byte_allocator = basic_shared_byte_alloc<nothing_t>;

} // namespace eagine::memory

#endif // EAGINE_MEMORY_SHARED_ALLOC_HPP
