/**
 *  @file eagine/memory/span.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_SPAN_HPP
#define EAGINE_MEMORY_SPAN_HPP

#include "../assert.hpp"
#include "../compare.hpp"
#include "../extract.hpp"
#include "../identity.hpp"
#include "../int_constant.hpp"
#include "../std/type_traits.hpp"
#include "../types.hpp"
#include "address.hpp"
#include <initializer_list>
#include <iterator>

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
struct rebind_pointer<T*, U> : identity<U*> {};
//------------------------------------------------------------------------------
// has_span_size_member
//------------------------------------------------------------------------------
struct _has_span_size_member_base {
    template <typename X, typename S = decltype(std::declval<X>().size())>
    static bool_constant<std::is_integral_v<S>> _detect(X*);

    static std::false_type _detect(...);
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
    static std::true_type _detect(X*);

    static std::false_type _detect(...);
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
    using reverse_iterator = std::reverse_iterator<iterator>;

    constexpr basic_span(pointer addr, size_type len) noexcept
      : _addr{addr}
      , _size{len} {
    }

    constexpr basic_span(address_type addr, size_type len) noexcept
      : _addr{static_cast<Pointer>(addr)}
      , _size{len} {
    }

    constexpr basic_span(pointer b, pointer e) noexcept
      : _addr{b}
      , _size{b <= e ? e - b : 0} {
    }

    constexpr basic_span(address_type ba, address_type be) noexcept
      : _addr{static_cast<Pointer>(ba)}
      , _size{limit_cast<size_type>(
          ba <= be ? (be - ba) / sizeof(value_type) : 0)} {
    }

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
    basic_span& operator=(const basic_span&) noexcept = default;
    basic_span& operator=(basic_span&&) noexcept = default;

    template <
      typename T,
      typename P,
      typename S,
      typename = enable_if_convertible<T, P, S>,
      typename = enable_if_different<T, P, S>>
    constexpr basic_span(basic_span<T, P, S> that) noexcept
      : _addr{static_cast<Pointer>(that.data())}
      , _size{limit_cast<SizeType>(that.size())} {
    }

    template <
      typename T,
      typename P,
      typename S,
      typename = enable_if_convertible<T, P, S>,
      typename = enable_if_different<T, P, S>>
    basic_span& operator=(basic_span<T, P, S> that) noexcept {
        _addr = static_cast<Pointer>(that.data());
        _size = limit_cast<SizeType>(that.size());
        return *this;
    }

    basic_span& reset() noexcept {
        return *this = basic_span();
    }

    basic_span& reset(pointer addr, size_type length) noexcept {
        return *this = basic_span(addr, length);
    }

    basic_span& reset(address_type addr, size_type length) noexcept {
        return *this = basic_span(addr, length);
    }

    basic_span& reset(pointer b, pointer e) noexcept {
        return *this = basic_span(b, e);
    }

    explicit constexpr inline operator bool() const noexcept {
        return _size != 0;
    }

    constexpr inline bool operator!() const noexcept {
        return _size == 0;
    }

    constexpr inline bool empty() const noexcept {
        return _size == 0;
    }

    constexpr inline size_type size() const noexcept {
        return _size;
    }

    constexpr inline pointer data() const noexcept {
        return _addr;
    }

    constexpr inline iterator begin() const noexcept {
        return _addr;
    }

    constexpr inline iterator end() const noexcept {
        return begin() + size();
    }

    constexpr inline auto rbegin() const noexcept {
        return reverse_iterator{_addr + _size - 1};
    }

    constexpr inline auto rend() const noexcept {
        return reverse_iterator{_addr - 1};
    }

    constexpr inline address_type addr() const noexcept {
        return as_address(begin());
    }

    constexpr inline address_type begin_addr() const noexcept {
        return as_address(begin());
    }

    constexpr inline address_type end_addr() const noexcept {
        return as_address(end());
    }

    template <typename X>
    bool is_aligned_as() const noexcept {
        return addr().template is_aligned_as<X>();
    }

    bool encloses(const_address a) const noexcept {
        return (addr() <= a) && (a <= end_addr());
    }

    template <typename Ts, typename Ps, typename Ss>
    bool contains(basic_span<Ts, Ps, Ss> that) const noexcept {
        return (addr() <= that.addr()) && (that.end_addr() <= end_addr());
    }

    template <typename Ts, typename Ps, typename Ss>
    bool overlaps(const basic_span<Ts, Ps, Ss>& that) const noexcept {
        return encloses(that.addr()) || encloses(that.end_addr()) ||
               that.encloses(addr()) || that.encloses(end_addr());
    }

    inline value_type& ref(size_type index) noexcept {
        return EAGINE_CONSTEXPR_ASSERT(index < size(), _addr[index]);
    }

    constexpr inline std::add_const_t<value_type>& ref(size_type index) const
      noexcept {
        return EAGINE_CONSTEXPR_ASSERT(index < size(), _addr[index]);
    }

    template <typename Int>
    inline std::enable_if_t<std::is_integral_v<Int>, value_type&> element(
      Int index) noexcept {
        return ref(span_size(index));
    }

    template <typename Int>
    constexpr inline std::
      enable_if_t<std::is_integral_v<Int>, std::add_const_t<value_type>&>
      element(Int index) const noexcept {
        return ref(span_size(index));
    }

    template <typename Int>
    inline std::enable_if_t<std::is_integral_v<Int>, value_type&> operator[](
      Int index) noexcept {
        return element(index);
    }

    template <typename Int>
    constexpr inline std::
      enable_if_t<std::is_integral_v<Int>, std::add_const_t<value_type>&>
      operator[](Int index) const noexcept {
        return element(index);
    }

private:
    pointer _addr = nullptr;
    size_type _size = 0;
};
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
static constexpr inline basic_span<T, T*, S> absolute(
  basic_span<T, P, S> spn) noexcept {
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
static constexpr inline const_span<T> viewOne(const T& value) noexcept {
    return {std::addressof(value), span_size(1)};
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline span_if_mutable<T> coverOne(T& value) noexcept {
    return {std::addressof(value), span_size(1)};
}
//------------------------------------------------------------------------------
template <typename T, typename S>
static constexpr inline const_span<T> view(T* addr, S size) noexcept {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
template <typename T, typename S>
static constexpr inline span_if_mutable<T> cover(T* addr, S size) noexcept {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
template <typename T, typename S>
static constexpr inline const_span<T> view(
  const_address addr, S size) noexcept {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
template <typename T, typename S>
static constexpr inline span_if_mutable<T> cover(
  address addr, S size) noexcept {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
static constexpr inline const_span<T> view(const T (&array)[N]) noexcept {
    return view(static_cast<const T*>(array), N);
}
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
static constexpr inline span_if_mutable<T> cover(T (&array)[N]) noexcept {
    return cover(static_cast<T*>(array), N);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline const_span<T> view(
  std::initializer_list<T> il) noexcept {
    return view(il.begin(), il.size());
}
//------------------------------------------------------------------------------
template <
  typename C,
  typename =
    std::enable_if_t<has_span_data_member_v<C> && has_span_size_member_v<C>>>
static constexpr inline auto view(C& container) noexcept {
    return view(container.data(), container.size());
}
//------------------------------------------------------------------------------
template <
  typename C,
  typename =
    std::enable_if_t<has_span_data_member_v<C> && has_span_size_member_v<C>>>
static constexpr inline auto cover(C& container) noexcept {
    return cover(container.data(), container.size());
}
//------------------------------------------------------------------------------
// accomodate
//------------------------------------------------------------------------------
template <typename T, typename B, typename P, typename S>
static constexpr inline bool can_accomodate(
  basic_span<B, P, S> blk, identity<T> tid = {}) noexcept {
    return (align_down_to(blk.end_addr(), tid) -
            align_up_to(blk.begin_addr(), tid)) >= span_size_of(tid);
}
//------------------------------------------------------------------------------
template <typename T, typename B, typename P, typename S>
static constexpr inline basic_span<std::add_const_t<T>, rebind_pointer_t<P, T>, S>
accomodate(basic_span<B, P, S> blk, identity<T> tid = {}) noexcept {
    return {
      align_up_to(blk.begin_addr(), tid), align_down_to(blk.end_addr(), tid)};
}
//------------------------------------------------------------------------------
// extract
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
static constexpr inline extracted<T> extract(basic_span<T, P, S> spn) noexcept {
    return {spn ? spn.data() : nullptr};
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
struct equal_cmp<
  memory::basic_span<Tl, Pl, Sl>,
  memory::basic_span<Tr, Pr, Sr>> {
    static inline bool check(
      memory::basic_span<Tl, Pl, Sl> l,
      memory::basic_span<Tr, Pr, Sr> r) noexcept {
        if(are_equal(l.size(), r.size())) {
            const auto n = span_size(l.size());
            for(span_size_t i = 0; i < n; ++i) {
                if(!are_equal(l[i], r[i])) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MEMORY_SPAN_HPP
