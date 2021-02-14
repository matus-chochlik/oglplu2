/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_STD_ALLOC_HPP
#define EAGINE_MEMORY_STD_ALLOC_HPP

#include "../assert.hpp"
#include "default_alloc.hpp"
#include "shared_alloc.hpp"
#include <memory>

namespace eagine::memory {

// std_allocator
template <typename T>
class std_allocator : public block_owner {
private:
    shared_byte_allocator _sba;

public:
    auto _get_sba() const -> auto& {
        return _sba;
    }

    using value_type = T;
    using size_type = span_size_t;

    using propagate_on_container_move_assignment = std::true_type;
    using propagate_on_container_copy_assignment = std::true_type;
    using propagate_on_container_swap = std::true_type;
    using is_always_equal = std::false_type;

    template <typename U>
    struct rebind {
        using other = std_allocator<U>;
    };

    template <typename U>
    std_allocator(const std_allocator<U>& that)
      : _sba(that._get_sba()) {}

    std_allocator(shared_byte_allocator sba) noexcept
      : _sba(std::move(sba)) {}

    std_allocator() noexcept
      : _sba(default_byte_allocator()) {}

    template <typename ByteAlloc>
    auto as() -> ByteAlloc& {
        return _sba.as<ByteAlloc>();
    }

    auto address(T& r) noexcept -> T* {
        return std::allocator<T>().address(r);
    }

    auto address(const T& r) noexcept -> const T* {
        return std::allocator<T>().address(r);
    }

    auto max_size() const noexcept -> size_type {
        return _sba.max_size(alignof(T));
    }

    auto allocate(size_type n, const void* = nullptr) -> T* {
        owned_block b = _sba.allocate(span_size_of<T>(n), span_align_of<T>());

        if(!b) {
            throw std::bad_alloc();
        }

        EAGINE_ASSERT(is_aligned_to(b.addr(), span_align_of<T>()));
        EAGINE_ASSERT(b.size() >= span_size_of<T>(n));

        T* p = static_cast<T*>(b.addr());

        release_block(std::move(b));

        return p;
    }

    void deallocate(T* p, size_type n) {
        if(p && n) {
            _sba.deallocate(
              acquire_block(as_bytes(cover(p, n))), span_align_of<T>());
        }
    }

    friend auto
    operator==(const std_allocator& a, const std_allocator& b) noexcept {
        return (a._sba == b._sba);
    }

    friend auto
    operator!=(const std_allocator& a, const std_allocator& b) noexcept {
        return (a._sba != b._sba);
    }

    template <class U, class... A>
    static inline void construct(U* p, A&&... a) {
        ::new(static_cast<void*>(p)) U(std::forward<A>(a)...);
    }

    template <typename U>
    static inline void destroy(U* p) noexcept(noexcept(p->~U())) {
        return p->~U();
    }
};

} // namespace eagine::memory

#endif // EAGINE_MEMORY_STD_ALLOC_HPP
