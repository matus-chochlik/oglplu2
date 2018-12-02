/**
 *  @file eagine/memory/address.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_ADDRESS_1510290655_HPP
#define EAGINE_MEMORY_ADDRESS_1510290655_HPP

#include "../std/type_traits.hpp"
#include "../types.hpp"
#include "align.hpp"
#include <cassert>
#include <cstddef>

namespace eagine {
namespace memory {

template <bool IsConst>
class basic_address {
public:
    typedef std::conditional_t<IsConst, const void*, void*> pointer;

    typedef std::conditional_t<IsConst, const byte*, byte*> byte_pointer;

private:
    pointer _addr;

public:
    constexpr basic_address() noexcept
      : _addr(nullptr) {
    }

    explicit constexpr basic_address(std::nullptr_t) noexcept
      : _addr(nullptr) {
    }

    explicit constexpr basic_address(std::intptr_t addr) noexcept
      : _addr(reinterpret_cast<pointer>(addr)) {
    }

    explicit constexpr basic_address(pointer addr) noexcept
      : _addr(addr) {
    }

    template <
      typename Int,
      typename = std::enable_if_t<
        std::is_integral_v<Int> && std::is_convertible_v<Int, std::ptrdiff_t>>>
    basic_address(basic_address that, Int offs) noexcept
      : _addr(that.ptr() + offs) {
    }

    basic_address(const basic_address&) = default;
    basic_address& operator=(const basic_address&) = default;

    template <bool IsConst2, typename = std::enable_if_t<IsConst && !IsConst2>>
    basic_address(basic_address<IsConst2> a) noexcept
      : _addr(pointer(a)) {
    }

    bool is_null() const noexcept {
        return _addr == nullptr;
    }

    explicit operator bool() const noexcept {
        return !is_null();
    }

    bool operator!() const noexcept {
        return is_null();
    }

    byte_pointer ptr() const noexcept {
        return static_cast<byte_pointer>(_addr);
    }

    pointer get() const noexcept {
        return _addr;
    }

    explicit operator pointer() const noexcept {
        return _addr;
    }

    template <
      typename T,
      typename = std::enable_if_t<
        !std::is_void<T>::value && (std::is_const<T>::value || !IsConst)>>
    explicit operator T*() const noexcept {
        assert(is_aligned_as<T>());
        return static_cast<T*>(_addr);
    }

    std::intptr_t value() const noexcept {
        return reinterpret_cast<std::intptr_t>(_addr);
    }

    span_size_t misalignment(span_size_t alignment) const noexcept {
        return memory::misalignment(value(), alignment);
    }

    bool is_aligned_to(span_size_t alignment) const noexcept {
        return memory::is_aligned_to(value(), alignment);
    }

    template <typename T>
    bool is_aligned_as() const noexcept {
        return memory::is_aligned_as<T>(value());
    }

    friend inline bool operator==(basic_address a, basic_address b) noexcept {
        return a.ptr() == b.ptr();
    }

    friend inline bool operator!=(basic_address a, basic_address b) noexcept {
        return a.ptr() != b.ptr();
    }

    friend inline bool operator<(basic_address a, basic_address b) noexcept {
        return a.ptr() < b.ptr();
    }

    friend inline bool operator<=(basic_address a, basic_address b) noexcept {
        return a.ptr() <= b.ptr();
    }

    friend inline bool operator>(basic_address a, basic_address b) noexcept {
        return a.ptr() > b.ptr();
    }

    friend inline bool operator>=(basic_address a, basic_address b) noexcept {
        return a.ptr() >= b.ptr();
    }

    friend inline std::ptrdiff_t
    operator-(basic_address a, basic_address b) noexcept {
        return a.ptr() - b.ptr();
    }

    friend inline basic_address
    operator+(basic_address a, std::ptrdiff_t o) noexcept {
        return {a, o};
    }

    friend inline basic_address
    operator-(basic_address a, std::ptrdiff_t o) noexcept {
        return {a, -o};
    }
};

typedef basic_address<true> const_address;
typedef basic_address<false> address;

template <typename T>
static inline basic_address<std::is_const<T>::value>
as_address(T* addr) noexcept {
    return basic_address<std::is_const<T>::value>(addr);
}

static inline span_size_t
misalignment(const_address addr, span_size_t alignment) noexcept {
    return addr.misalignment(alignment);
}

static inline span_size_t
misalignment(const void* ptr, span_size_t alignment) noexcept {
    return misalignment(as_address(ptr), alignment);
}

static inline bool
is_aligned_to(const_address addr, span_size_t alignment) noexcept {
    return addr.is_aligned_to(alignment);
}

static inline bool
is_aligned_to(const void* ptr, span_size_t alignment) noexcept {
    return is_aligned_to(as_address(ptr), alignment);
}

template <typename T>
static inline bool is_aligned_as(const_address addr) noexcept {
    return addr.template is_aligned_as<T>();
}

template <bool IsConst>
static inline basic_address<IsConst> align_up(
  basic_address<IsConst> addr, span_size_t align, span_size_t max) noexcept {
    auto ma = misalignment(addr, align);
    ma = (ma ? align - ma : 0);

    assert(span_size(ma) <= max);
    return {addr, ma};
}

template <bool IsConst>
static inline basic_address<IsConst> align_down(
  basic_address<IsConst> addr, span_size_t align, span_size_t max) noexcept {
    auto ma = misalignment(addr, align);

    assert(span_size(ma) <= max);
    return {addr, -ma};
}

template <bool IsConst>
static inline basic_address<IsConst>
align_down(basic_address<IsConst> addr, span_size_t align) noexcept {
    return align_down(addr, align, addr.value());
}

static inline const byte* align_down(const byte* ptr, span_size_t align) {
    return align_down(const_address(ptr), align).ptr();
}

template <typename T>
static inline T* align_up_to(
  basic_address<std::is_const<T>::value> addr,
  span_size_t align = span_align_of<T>(),
  span_size_t max = span_size_of<T>()) noexcept {
    if(align < span_align_of<T>()) {
        align = span_align_of<T>();
    }

    return static_cast<T*>(align_up(addr, align, max));
}

template <typename T>
static inline T* align_down_to(
  basic_address<std::is_const<T>::value> addr,
  span_size_t align = span_align_of<T>(),
  span_size_t max = span_size_of<T>()) noexcept {
    if(align < span_align_of<T>()) {
        align = span_align_of<T>();
    }

    return static_cast<T*>(align_down(addr, align, max));
}

} // namespace memory
} // namespace eagine

#endif // include guard
