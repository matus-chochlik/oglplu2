/**
 *  @file eagine/memory/offset_ptr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_OFFSET_PTR_HPP
#define EAGINE_MEMORY_OFFSET_PTR_HPP

#include "../assert.hpp"
#include "../extract.hpp"
#include "../identity.hpp"
#include "address.hpp"

namespace eagine::memory {
//------------------------------------------------------------------------------
// basic_offset_ptr
//------------------------------------------------------------------------------
template <typename Pointee, typename OffsetType>
class basic_offset_ptr {
public:
    using address = basic_address<std::is_const_v<Pointee>>;
    using const_address = basic_address<true>;
    using offset_type = OffsetType;
    using pointer = Pointee*;
    using const_pointer = std::add_const_t<Pointee>*;
    using reference = Pointee&;
    using const_reference = std::add_const_t<Pointee>&;

private:
    static_assert(std::is_signed_v<offset_type>);

    offset_type _offs = {0};
    using _rawptr = typename address::pointer;

    template <typename P, typename O>
    static auto _that_addr(const basic_offset_ptr<P, O>& that) {
        return address(_rawptr(&that));
    }

    auto _this_addr() const noexcept {
        return _that_addr(*this);
    }

    auto _get_offs(address addr) noexcept -> offset_type {
        return addr ? addr - _this_addr() : 0;
    }

    auto _get_offs(Pointee* ptr) noexcept {
        return _get_offs(address(ptr));
    }

    template <typename P, typename O>
    auto _get_offs(const basic_offset_ptr<P, O>& that) noexcept -> offset_type {
        return that.is_null() ? offset_type(0)
                              : limit_cast<offset_type>(that.offset()) +
                                  _get_offs(_that_addr(that));
    }

public:
    constexpr basic_offset_ptr() noexcept = default;
    ~basic_offset_ptr() noexcept = default;

    explicit constexpr basic_offset_ptr(offset_type offs) noexcept
      : _offs{offs} {}

    explicit constexpr basic_offset_ptr(address addr) noexcept
      : _offs{_get_offs(addr)} {}

    basic_offset_ptr(Pointee* ptr) noexcept
      : _offs{_get_offs(ptr)} {}

    basic_offset_ptr(const basic_offset_ptr& that) noexcept
      : _offs{_get_offs(that)} {}

    basic_offset_ptr(basic_offset_ptr&& that) noexcept
      : _offs{_get_offs(that)} {}

    template <typename P, typename O>
    using enable_if_convertible = std::enable_if<
      std::is_convertible_v<O, OffsetType> &&
      std::is_convertible_v<P*, Pointee*>>;

    template <typename P, typename O>
    using enable_if_different = std::enable_if<
      !std::is_same_v<O, OffsetType> && !std::is_same_v<P, Pointee>>;

    template <
      typename P,
      typename O,
      typename = enable_if_convertible<P, O>,
      typename = enable_if_different<P, O>>
    basic_offset_ptr(const basic_offset_ptr<P, O>& that) noexcept
      : _offs{_get_offs(that)} {}

    // NOLINTNEXTLINE(bugprone-unhandled-self-assignment,cert-oop54-cpp)
    auto operator=(const basic_offset_ptr& that) noexcept -> basic_offset_ptr& {
        if(this != std::addressof(that)) {
            _offs = _get_offs(that);
        }
        return *this;
    }

    auto operator=(basic_offset_ptr&& that) noexcept -> basic_offset_ptr& {
        _offs = _get_offs(that);
        return *this;
    }

    auto reset(Pointee* ptr) noexcept -> auto& {
        return *this = basic_offset_ptr(ptr);
    }

    auto reset(address adr) noexcept -> auto& {
        return *this = basic_offset_ptr(adr);
    }

    constexpr auto is_null() const noexcept -> bool {
        return _offs == offset_type(0);
    }

    explicit constexpr operator bool() const noexcept {
        return !is_null();
    }

    constexpr auto offset() const noexcept -> offset_type {
        return _offs;
    }

    auto addr() noexcept -> address {
        return is_null() ? address() : address(_this_addr(), _offs);
    }

    constexpr auto addr() const noexcept -> const_address {
        return is_null() ? address() : address(_this_addr(), _offs);
    }

    auto data() noexcept -> pointer {
        return static_cast<pointer>(addr());
    }

    constexpr auto data() const noexcept -> const_pointer {
        return static_cast<const_pointer>(addr());
    }

    auto get() noexcept -> pointer {
        return data();
    }

    constexpr auto get() const noexcept -> const_pointer {
        return data();
    }

    operator pointer() noexcept {
        return get();
    }

    constexpr operator const_pointer() const noexcept {
        return get();
    }

    auto operator*() noexcept -> reference {
        EAGINE_ASSERT(!is_null());
        return *get();
    }

    constexpr auto operator*() const noexcept -> const_reference {
        EAGINE_ASSERT(!is_null());
        return *get();
    }

    auto operator->() noexcept -> pointer {
        EAGINE_ASSERT(!is_null());
        return get();
    }

    constexpr auto operator->() const noexcept -> const_pointer {
        EAGINE_ASSERT(!is_null());
        return get();
    }

    auto operator++() noexcept -> auto& {
        return *this = basic_offset_ptr(get() + 1);
    }

    auto operator--() noexcept -> auto& {
        return *this = basic_offset_ptr(get() - 1);
    }

    auto operator[](offset_type index) noexcept -> reference {
        EAGINE_ASSERT(!is_null());
        return get()[index];
    }

    constexpr auto operator[](offset_type index) const noexcept
      -> const_reference {
        EAGINE_ASSERT(!is_null());
        return get()[index];
    }
};
//------------------------------------------------------------------------------
// extract
//------------------------------------------------------------------------------
template <typename P, typename O>
static constexpr inline auto extract(basic_offset_ptr<P, O> ptr) noexcept
  -> P& {
    return EAGINE_CONSTEXPR_ASSERT(!ptr.is_null(), ptr.get());
}
//------------------------------------------------------------------------------
template <typename P, typename O>
static constexpr inline auto
extract_or(basic_offset_ptr<P, O> ptr, P& fallback) noexcept -> P& {
    return ptr.is_null() ? fallback : ptr.get();
}
//------------------------------------------------------------------------------
template <typename P, typename O, typename F>
static constexpr inline auto extract_or(basic_offset_ptr<P, O> ptr, P& fallback)
  -> std::enable_if_t<std::is_convertible_v<F, P>, P> {
    return ptr.is_null() ? P{std::forward<F>(fallback)} : ptr.get();
}
//------------------------------------------------------------------------------
// rebind_pointer
//------------------------------------------------------------------------------
template <typename Ptr, typename U>
struct rebind_pointer;
//------------------------------------------------------------------------------
template <typename T, typename O, typename U>
struct rebind_pointer<basic_offset_ptr<T, O>, U>
  : identity<basic_offset_ptr<U, O>> {};
//------------------------------------------------------------------------------
template <typename P, typename O>
static constexpr inline auto as_address(basic_offset_ptr<P, O> op) noexcept
  -> basic_address<std::is_const_v<P>> {
    return op.addr();
}
//------------------------------------------------------------------------------
template <typename Pointee>
using offset_ptr = basic_offset_ptr<Pointee, std::ptrdiff_t>;
//------------------------------------------------------------------------------
template <typename Pointee>
using short_offset_ptr = basic_offset_ptr<Pointee, short>;
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_OFFSET_PTR_HPP
