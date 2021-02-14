/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_ADDRESS_HPP
#define EAGINE_MEMORY_ADDRESS_HPP

#include "../assert.hpp"
#include "../types.hpp"
#include "align.hpp"
#include <cstddef>
#include <type_traits>

namespace eagine::memory {
//------------------------------------------------------------------------------
template <bool IsConst>
class basic_address {
public:
    using pointer = std::conditional_t<IsConst, const void*, void*>;

    using byte_pointer = std::conditional_t<IsConst, const byte*, byte*>;

private:
    pointer _addr{nullptr};

public:
    ~basic_address() noexcept = default;
    constexpr basic_address() noexcept = default;
    constexpr basic_address(basic_address&&) noexcept = default;
    constexpr auto operator=(basic_address&&) noexcept
      -> basic_address& = default;

    constexpr explicit basic_address(std::nullptr_t) noexcept {}

    constexpr explicit basic_address(std::intptr_t addr) noexcept
      : _addr(reinterpret_cast<pointer>(addr)) {}

    constexpr explicit basic_address(pointer addr) noexcept
      : _addr(addr) {}

    template <
      typename Int,
      typename = std::enable_if_t<
        std::is_integral_v<Int> && std::is_convertible_v<Int, std::ptrdiff_t>>>
    constexpr basic_address(basic_address that, Int offs) noexcept
      : _addr(that.ptr() + offs) {}

    constexpr basic_address(const basic_address&) noexcept = default;
    constexpr auto operator=(const basic_address&) noexcept
      -> basic_address& = default;

    template <bool IsConst2, typename = std::enable_if_t<IsConst && !IsConst2>>
    constexpr basic_address(basic_address<IsConst2> a) noexcept
      : _addr(pointer(a)) {}

    constexpr auto is_null() const noexcept {
        return _addr == nullptr;
    }

    constexpr explicit operator bool() const noexcept {
        return !is_null();
    }

    constexpr auto ptr() const noexcept {
        return static_cast<byte_pointer>(_addr);
    }

    constexpr auto get() const noexcept {
        return _addr;
    }

    constexpr explicit operator pointer() const noexcept {
        return _addr;
    }

    template <
      typename T,
      typename =
        std::enable_if_t<!std::is_void_v<T> && (std::is_const_v<T> || !IsConst)>>
    constexpr explicit operator T*() const noexcept {
        return EAGINE_CONSTEXPR_ASSERT(
          is_aligned_as<T>(), static_cast<T*>(_addr));
    }

    constexpr auto value() const noexcept {
        return reinterpret_cast<std::intptr_t>(_addr);
    }

    constexpr auto misalignment(span_size_t alignment) const noexcept {
        return memory::misalignment(value(), alignment);
    }

    constexpr auto is_aligned_to(span_size_t alignment) const noexcept {
        return memory::is_aligned_to(value(), alignment);
    }

    template <typename T>
    constexpr auto is_aligned_as(type_identity<T> tid = {}) const noexcept {
        return memory::is_aligned_as<T>(value(), tid);
    }

    constexpr friend inline auto
    operator==(basic_address a, basic_address b) noexcept {
        return a.ptr() == b.ptr();
    }

    constexpr friend inline auto
    operator!=(basic_address a, basic_address b) noexcept {
        return a.ptr() != b.ptr();
    }

    constexpr friend inline auto
    operator<(basic_address a, basic_address b) noexcept {
        return a.ptr() < b.ptr();
    }

    constexpr friend inline auto
    operator<=(basic_address a, basic_address b) noexcept {
        return a.ptr() <= b.ptr();
    }

    constexpr friend inline auto
    operator>(basic_address a, basic_address b) noexcept {
        return a.ptr() > b.ptr();
    }

    constexpr friend inline auto
    operator>=(basic_address a, basic_address b) noexcept {
        return a.ptr() >= b.ptr();
    }

    constexpr friend inline auto
    operator-(basic_address a, basic_address b) noexcept -> std::ptrdiff_t {
        return a.ptr() - b.ptr();
    }

    constexpr friend inline auto
    operator+(basic_address a, std::ptrdiff_t o) noexcept -> basic_address {
        return {a, o};
    }

    constexpr friend inline auto
    operator-(basic_address a, std::ptrdiff_t o) noexcept -> basic_address {
        return {a, -o};
    }
};
//------------------------------------------------------------------------------
using const_address = basic_address<true>;
using address = basic_address<false>;
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto as_address(T* addr) noexcept {
    return basic_address<std::is_const_v<T>>(addr);
}
//------------------------------------------------------------------------------
static constexpr auto
misalignment(const_address addr, span_size_t alignment) noexcept {
    return addr.misalignment(alignment);
}
//------------------------------------------------------------------------------
static constexpr auto
misalignment(const void* ptr, span_size_t alignment) noexcept {
    return misalignment(as_address(ptr), alignment);
}
//------------------------------------------------------------------------------
static constexpr auto
is_aligned_to(const_address addr, span_size_t alignment) noexcept {
    return addr.is_aligned_to(alignment);
}
//------------------------------------------------------------------------------
static constexpr auto
is_aligned_to(const void* ptr, span_size_t alignment) noexcept {
    return is_aligned_to(as_address(ptr), alignment);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto
is_aligned_as(const_address addr, type_identity<T> tid = {}) noexcept {
    return addr.is_aligned_as(tid);
}
//------------------------------------------------------------------------------
static constexpr auto
align_up_offs(span_size_t align, span_size_t misalign) noexcept {
    return (misalign ? align - misalign : 0);
}
//------------------------------------------------------------------------------
template <bool IsConst>
static constexpr auto align_up_by(
  basic_address<IsConst> addr,
  span_size_t offs,
  span_size_t max) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(
      (offs <= max), basic_address<IsConst>(addr, offs));
}
//------------------------------------------------------------------------------
template <bool IsConst>
static constexpr auto align_up(
  basic_address<IsConst> addr,
  span_size_t align,
  span_size_t max) noexcept -> basic_address<IsConst> {
    return align_up_by(
      addr, align_up_offs(align, misalignment(addr, align)), max);
}
//------------------------------------------------------------------------------
static constexpr auto
align_down_offs(span_size_t, span_size_t misalign) noexcept {
    return misalign;
}
//------------------------------------------------------------------------------
template <bool IsConst>
static constexpr auto align_down_by(
  basic_address<IsConst> addr,
  span_size_t offs,
  span_size_t max) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(
      (offs <= max), basic_address<IsConst>(addr, -offs));
}
//------------------------------------------------------------------------------
template <bool IsConst>
static constexpr auto align_down(
  basic_address<IsConst> addr,
  span_size_t align,
  span_size_t max) noexcept -> basic_address<IsConst> {

    return align_down_by(
      addr, align_down_offs(align, misalignment(addr, align)), max);
}
//------------------------------------------------------------------------------
template <bool IsConst>
static constexpr auto
align_down(basic_address<IsConst> addr, span_size_t align) noexcept {
    return align_down(addr, align, addr.value());
}
//------------------------------------------------------------------------------
static inline auto align_down(const byte* ptr, span_size_t align)
  -> const byte* {
    return align_down(const_address(ptr), align).ptr();
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto align_up_to(
  basic_address<std::is_const_v<T>> addr,
  type_identity<T> = {},
  span_size_t align = span_align_of<T>(),
  span_size_t max = span_size_of<T>()) noexcept {

    if(align < span_align_of<T>()) {
        align = span_align_of<T>();
    }

    return static_cast<T*>(align_up(addr, align, max));
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto align_down_to(
  basic_address<std::is_const_v<T>> addr,
  type_identity<T> = {},
  span_size_t align = span_align_of<T>(),
  span_size_t max = span_size_of<T>()) noexcept {
    if(align < span_align_of<T>()) {
        align = span_align_of<T>();
    }

    return static_cast<T*>(align_down(addr, align, max));
}
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_ADDRESS_HPP
