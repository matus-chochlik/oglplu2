/// @file eagine/memory/span.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_SPAN_HPP
#define EAGINE_MEMORY_SPAN_HPP

#include "../assert.hpp"
#include "../compare.hpp"
#include "../extract.hpp"
#include "../int_constant.hpp"
#include "../type_identity.hpp"
#include "../types.hpp"
#include "address.hpp"
#include <cstring>
#include <initializer_list>
#include <iterator>
#include <type_traits>

namespace eagine {
namespace memory {
//------------------------------------------------------------------------------
// rebind_pointer
//------------------------------------------------------------------------------
template <typename Ptr, typename U>
struct rebind_pointer;
//------------------------------------------------------------------------------
template <typename Ptr, typename U>
using rebind_pointer_t = typename rebind_pointer<Ptr, U>::type;
//------------------------------------------------------------------------------
template <typename T, typename U>
struct rebind_pointer<T*, U> : type_identity<U*> {};
//------------------------------------------------------------------------------
// has_span_size_member
//------------------------------------------------------------------------------
struct _has_span_size_member_base {
    template <typename X, typename S = decltype(std::declval<X>().size())>

    static auto _detect(X*) -> bool_constant<std::is_integral_v<S>>;
    static auto _detect(...) -> std::false_type;
};
//------------------------------------------------------------------------------
template <typename T>
struct has_span_size_member
  : public decltype(
      _has_span_size_member_base::_detect(static_cast<T*>(nullptr))) {};
//------------------------------------------------------------------------------
template <typename T>
constexpr bool has_span_size_member_v = has_span_size_member<T>::value;
//------------------------------------------------------------------------------
// has_span_data_member
//------------------------------------------------------------------------------
struct _has_span_data_member_base {
    template <
      typename X,
      typename P = decltype(std::declval<X>().data()),
      typename PT = typename std::pointer_traits<P>::element_type>

    static auto _detect(X*) -> std::true_type;
    static auto _detect(...) -> std::false_type;
};
//------------------------------------------------------------------------------
template <typename T>
struct has_span_data_member
  : public decltype(
      _has_span_data_member_base::_detect(static_cast<T*>(nullptr))) {};
//------------------------------------------------------------------------------
template <typename T>
constexpr bool has_span_data_member_v = has_span_data_member<T>::value;
//------------------------------------------------------------------------------
// basic_span
//------------------------------------------------------------------------------
template <
  typename ValueType,
  typename Pointer = ValueType*,
  typename SizeType = span_size_t>
class basic_span {
public:
    using value_type = ValueType;
    using size_type = SizeType;
    using address_type = basic_address<std::is_const_v<ValueType>>;
    using pointer = Pointer;
    using iterator = Pointer;
    using const_iterator = Pointer;
    using reverse_iterator = std::reverse_iterator<iterator>;

    constexpr basic_span(pointer addr, size_type len) noexcept
      : _addr{addr}
      , _size{len} {}

    constexpr basic_span(address_type addr, size_type len) noexcept
      : _addr{static_cast<Pointer>(addr)}
      , _size{len} {}

    constexpr basic_span(pointer b, pointer e) noexcept
      : _addr{b}
      , _size{b <= e ? e - b : 0} {}

    constexpr basic_span(address_type ba, address_type be) noexcept
      : _addr{static_cast<Pointer>(ba)}
      , _size{limit_cast<size_type>(
          ba <= be ? (be - ba) / sizeof(value_type) : 0)} {}

    template <typename T, typename P, typename S>
    using enable_if_convertible = std::enable_if_t<
      std::is_convertible_v<T, ValueType> &&
      std::is_convertible_v<P, Pointer> && std::is_convertible_v<S, SizeType>>;

    template <typename T, typename P, typename S>
    using enable_if_different = std::enable_if_t<
      !std::is_same_v<T, ValueType> || !std::is_same_v<P, Pointer> ||
      !std::is_same_v<S, SizeType>>;

    constexpr basic_span() noexcept = default;
    constexpr basic_span(const basic_span&) noexcept = default;
    constexpr basic_span(basic_span&&) noexcept = default;
    auto operator=(const basic_span&) noexcept -> basic_span& = default;
    auto operator=(basic_span&&) noexcept -> basic_span& = default;
    ~basic_span() noexcept = default;

    template <
      typename T,
      typename P,
      typename S,
      typename = enable_if_convertible<T, P, S>,
      typename = enable_if_different<T, P, S>>
    constexpr basic_span(basic_span<T, P, S> that) noexcept
      : _addr{static_cast<Pointer>(that.data())}
      , _size{limit_cast<SizeType>(that.size())} {}

    template <
      typename T,
      typename P,
      typename S,
      typename = enable_if_convertible<T, P, S>,
      typename = enable_if_different<T, P, S>>
    auto operator=(basic_span<T, P, S> that) noexcept -> auto& {
        _addr = static_cast<Pointer>(that.data());
        _size = limit_cast<SizeType>(that.size());
        return *this;
    }

    auto reset() noexcept -> auto& {
        return *this = basic_span();
    }

    auto reset(pointer addr, size_type length) noexcept -> auto& {
        return *this = basic_span(addr, length);
    }

    auto reset(address_type addr, size_type length) noexcept -> auto& {
        return *this = basic_span(addr, length);
    }

    auto reset(pointer b, pointer e) noexcept -> auto& {
        return *this = basic_span(b, e);
    }

    explicit constexpr operator bool() const noexcept {
        return size() != 0;
    }

    constexpr auto is_empty() const noexcept -> bool {
        return size() == 0;
    }

    constexpr auto empty() const noexcept -> bool {
        return size() == 0;
    }

    constexpr auto is_zero_terminated() const noexcept -> bool {
        return size() < 0;
    }

    constexpr auto size() const noexcept -> size_type {
        return EAGINE_LIKELY(_size >= 0) ? _size : -_size;
    }

    constexpr auto data() const noexcept -> pointer {
        return _addr;
    }

    constexpr auto begin() const noexcept -> iterator {
        return _addr;
    }

    constexpr auto end() const noexcept -> iterator {
        return begin() + size();
    }

    constexpr auto rbegin() const noexcept {
        return reverse_iterator{end()};
    }

    constexpr auto rend() const noexcept {
        return reverse_iterator{begin()};
    }

    constexpr auto addr() const noexcept -> address_type {
        return as_address(begin());
    }

    constexpr auto begin_addr() const noexcept -> address_type {
        return as_address(begin());
    }

    constexpr auto end_addr() const noexcept -> address_type {
        return as_address(end());
    }

    template <typename X>
    auto is_aligned_as() const noexcept -> bool {
        return addr().template is_aligned_as<X>();
    }

    auto encloses(const_address a) const noexcept -> bool {
        return (addr() <= a) && (a <= end_addr());
    }

    template <typename Ts, typename Ps, typename Ss>
    auto contains(basic_span<Ts, Ps, Ss> that) const noexcept -> bool {
        return (addr() <= that.addr()) && (that.end_addr() <= end_addr());
    }

    template <typename Ts, typename Ps, typename Ss>
    auto overlaps(const basic_span<Ts, Ps, Ss>& that) const noexcept -> bool {
        return encloses(that.addr()) || encloses(that.end_addr()) ||
               that.encloses(addr()) || that.encloses(end_addr());
    }

    auto ref(size_type index) noexcept -> value_type& {
        return EAGINE_CONSTEXPR_ASSERT(index < size(), _addr[index]);
    }

    auto front() const noexcept -> const value_type& {
        return EAGINE_CONSTEXPR_ASSERT(0 < size(), _addr[0]);
    }

    auto front() noexcept -> value_type& {
        return EAGINE_CONSTEXPR_ASSERT(0 < size(), _addr[0]);
    }

    auto back() const noexcept -> const value_type& {
        return EAGINE_CONSTEXPR_ASSERT(0 < size(), _addr[size() - 1]);
    }

    auto back() noexcept -> value_type& {
        return EAGINE_CONSTEXPR_ASSERT(0 < size(), _addr[size() - 1]);
    }

    constexpr auto ref(size_type index) const noexcept
      -> std::add_const_t<value_type>& {
        return EAGINE_CONSTEXPR_ASSERT(index < size(), _addr[index]);
    }

    template <typename Int>
    auto element(Int index) noexcept
      -> std::enable_if_t<std::is_integral_v<Int>, value_type&> {
        return ref(span_size(index));
    }

    template <typename Int>
    constexpr auto element(Int index) const noexcept
      -> std::enable_if_t<std::is_integral_v<Int>, std::add_const_t<value_type>&> {
        return ref(span_size(index));
    }

    template <typename Int>
    auto operator[](Int index) noexcept
      -> std::enable_if_t<std::is_integral_v<Int>, value_type&> {
        return element(index);
    }

    template <typename Int>
    constexpr auto operator[](Int index) const noexcept
      -> std::enable_if_t<std::is_integral_v<Int>, std::add_const_t<value_type>&> {
        return element(index);
    }

private:
    pointer _addr{nullptr};
    // if _size is negative it indicates that the span is terminated
    // by a zero value. if such case the span length is calculated by
    // getting the absolute value of _size.
    size_type _size{0};
};
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
static constexpr auto absolute(basic_span<T, P, S> spn) noexcept
  -> basic_span<T, T*, S> {
    return {spn};
}
//------------------------------------------------------------------------------
template <typename T, typename S = span_size_t>
using span = basic_span<T, T*, S>;
//------------------------------------------------------------------------------
template <typename T>
using span_if_mutable = std::enable_if_t<!std::is_const_v<T>, span<T>>;
//------------------------------------------------------------------------------
template <typename T>
using const_span = span<std::add_const_t<T>>;
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto view_one(const T& value) noexcept -> const_span<T> {
    return {std::addressof(value), span_size(1)};
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto cover_one(T& value) noexcept -> span_if_mutable<T> {
    return {std::addressof(value), span_size(1)};
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto view_one(const T* pointer) noexcept -> const_span<T> {
    return {pointer, span_size(1)};
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto cover_one(T* pointer) noexcept -> span_if_mutable<T> {
    return {pointer, span_size(1)};
}
//------------------------------------------------------------------------------
template <typename T, typename S>
static constexpr auto view(T* addr, S size) noexcept -> const_span<T> {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
template <typename T, typename S>
static constexpr auto cover(T* addr, S size) noexcept -> span_if_mutable<T> {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
template <typename T, typename S>
static constexpr auto view(const_address addr, S size) noexcept
  -> const_span<T> {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
template <typename T, typename S>
static constexpr auto cover(address addr, S size) noexcept
  -> span_if_mutable<T> {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
static constexpr auto view(const T (&array)[N]) noexcept -> const_span<T> {
    return view(static_cast<const T*>(array), N);
}
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
static constexpr auto cover(T (&array)[N]) noexcept -> span_if_mutable<T> {
    return cover(static_cast<T*>(array), N);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto view(std::initializer_list<T> il) noexcept
  -> const_span<T> {
    return view(il.begin(), il.size());
}
//------------------------------------------------------------------------------
template <
  typename C,
  typename =
    std::enable_if_t<has_span_data_member_v<C> && has_span_size_member_v<C>>>
static constexpr auto view(const C& container) noexcept {
    return view(container.data(), container.size());
}
//------------------------------------------------------------------------------
template <
  typename C,
  typename =
    std::enable_if_t<has_span_data_member_v<C> && has_span_size_member_v<C>>>
static constexpr auto cover(C& container) noexcept {
    return cover(container.data(), container.size());
}
//------------------------------------------------------------------------------
// accomodate
//------------------------------------------------------------------------------
static constexpr auto can_accomodate_between(
  const_address bgn,
  const_address end,
  span_size_t size) noexcept -> bool {
    return (end - bgn) >= size;
}
//------------------------------------------------------------------------------
template <typename T, typename B, typename P, typename S>
static constexpr auto can_accomodate(
  basic_span<B, P, S> blk,
  span_size_t count,
  type_identity<T> tid = {}) noexcept {
    return can_accomodate_between(
      align_up(blk.begin_addr(), span_align_of(tid), span_align_of(tid)),
      align_down(blk.end_addr(), span_align_of(tid), span_align_of(tid)),
      count * span_size_of(tid));
}
//------------------------------------------------------------------------------
template <typename T, typename B, typename P, typename S>
static constexpr auto
can_accomodate(basic_span<B, P, S> blk, type_identity<T> tid = {}) noexcept {
    return can_accomodate(blk, 1, tid);
}
//------------------------------------------------------------------------------
template <typename T, typename B, typename P, typename S>
static constexpr auto
accomodate(basic_span<B, P, S> blk, type_identity<T> tid = {}) noexcept
  -> basic_span<std::add_const_t<T>, rebind_pointer_t<P, T>, S> {
    return {
      align_up_to(blk.begin_addr(), tid), align_down_to(blk.end_addr(), tid)};
}
//------------------------------------------------------------------------------
// extract
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
static constexpr auto extract(basic_span<T, P, S> spn) noexcept -> T& {
    return EAGINE_CONSTEXPR_ASSERT(spn.size() >= 1, spn.front());
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
static constexpr auto extract_or(basic_span<T, P, S> spn, T& fallback) noexcept
  -> T& {
    return (spn.size() >= 1) ? spn.front() : fallback;
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S, typename F>
static constexpr auto extract_or(basic_span<T, P, S> spn, F&& fallback)
  -> std::enable_if_t<std::is_convertible_v<F, T>, T> {
    return (spn.size() >= 1) ? spn.front() : T{std::forward<F>(fallback)};
}
//------------------------------------------------------------------------------
} // namespace memory
//------------------------------------------------------------------------------
template <
  typename Tl,
  typename Tr,
  typename Pl,
  typename Pr,
  typename Sl,
  typename Sr>
struct equal_cmp<memory::basic_span<Tl, Pl, Sl>, memory::basic_span<Tr, Pr, Sr>> {

    static auto check(
      memory::basic_span<Tl, Pl, Sl> l,
      memory::basic_span<Tr, Pr, Sr> r) noexcept -> bool {
        if(are_equal(l.size(), r.size())) {
            if constexpr(
              std::is_same_v<std::remove_const_t<Tl>, std::remove_const_t<Tr>> &&
              std::is_integral_v<std::remove_const_t<Tl>>) {
                return 0 ==
                       std::memcmp(
                         l.data(), r.data(), sizeof(Tl) * std_size(l.size()));
            } else {
                const auto n = span_size(l.size());
                for(span_size_t i = 0; i < n; ++i) {
                    if(!are_equal(l[i], r[i])) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MEMORY_SPAN_HPP
