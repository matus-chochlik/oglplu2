/// @file
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
/// @brief Helper class detecting if type T has x.size() member function.
/// @ingroup type_utils
template <typename T>
struct has_span_size_member
  : public decltype(
      _has_span_size_member_base::_detect(static_cast<T*>(nullptr))) {};
//------------------------------------------------------------------------------
/// @brief Trait indicating if type T has x.size() member function.
/// @ingroup type_utils
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
/// @brief Helper class detecting if type T has x.data() member function.
/// @ingroup type_utils
template <typename T>
struct has_span_data_member
  : public decltype(
      _has_span_data_member_base::_detect(static_cast<T*>(nullptr))) {};
//------------------------------------------------------------------------------
/// @brief Trait indicating if type T has x.size() member function.
/// @ingroup type_utils
template <typename T>
constexpr bool has_span_data_member_v = has_span_data_member<T>::value;
//------------------------------------------------------------------------------
// basic_span
//------------------------------------------------------------------------------
/// @brief Non-owning view of a contiguous range of memory with ValueType elements.
/// @ingroup type_utils
/// @tparam ValueType the type of elements assumed in the covered memory range.
/// @tparam Pointer the pointer type used to point to the start of the span.
/// @tparam SizeType the integer type used to count the elements in the span.
///
/// This template is similar to std::span but allows to specify other pointer
/// types besides ValueType*, for example basic_offset_ptr, etc. and to specify
/// the size type.
template <
  typename ValueType,
  typename Pointer = ValueType*,
  typename SizeType = span_size_t>
class basic_span {
public:
    /// @brief The element value type.
    using value_type = ValueType;

    /// @brief The element count type.
    using size_type = SizeType;

    /// @brief The memory address type.
    using address_type = basic_address<std::is_const_v<ValueType>>;

    /// @brief The pointer type.
    using pointer = Pointer;

    /// @brief The iterator type.
    using iterator = Pointer;

    /// @brief The const iterator type.
    using const_iterator = Pointer;

    /// @brief The reverse iterator type
    using reverse_iterator = std::reverse_iterator<iterator>;

    /// @brief Construction from pointer and length.
    constexpr basic_span(pointer addr, size_type len) noexcept
      : _addr{addr}
      , _size{len} {}

    /// @brief Construction from memory address and length.
    constexpr basic_span(address_type addr, size_type len) noexcept
      : _addr{static_cast<Pointer>(addr)}
      , _size{len} {}

    /// @brief Construction from a pair of pointers.
    constexpr basic_span(pointer b, pointer e) noexcept
      : _addr{b}
      , _size{b <= e ? e - b : 0} {}

    /// @brief Construction from a pair of memory addresses.
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

    /// @brief Default constructor. Constructs an empty span.
    /// @post is_empty()
    /// @post size() == 0
    constexpr basic_span() noexcept = default;

    /// @brief Copy constructor.
    constexpr basic_span(const basic_span&) noexcept = default;

    /// @brief Move constructor.
    constexpr basic_span(basic_span&&) noexcept = default;

    /// @brief Copy assignment operator.
    auto operator=(const basic_span&) noexcept -> basic_span& = default;

    /// @brief Move assignment operator.
    auto operator=(basic_span&&) noexcept -> basic_span& = default;
    ~basic_span() noexcept = default;

    /// @brief Converting copy constructor from span of compatible elements.
    template <
      typename T,
      typename P,
      typename S,
      typename = enable_if_convertible<T, P, S>,
      typename = enable_if_different<T, P, S>>
    constexpr basic_span(basic_span<T, P, S> that) noexcept
      : _addr{static_cast<Pointer>(that.data())}
      , _size{limit_cast<SizeType>(that.size())} {}

    /// @brief Converting copy assignment from span of compatible elements.
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

    /// @brief Resets this span.
    /// @post is_empty()
    auto reset() noexcept -> auto& {
        return *this = {};
    }

    /// @brief Resets this span with a new pointer and length.
    auto reset(pointer addr, size_type length) noexcept -> auto& {
        return *this = basic_span(addr, length);
    }

    /// @brief Resets this span with a new memory address and length.
    auto reset(address_type addr, size_type length) noexcept -> auto& {
        return *this = basic_span(addr, length);
    }

    /// @brief Resets this span with a pair or pointers.
    auto reset(pointer b, pointer e) noexcept -> auto& {
        return *this = basic_span(b, e);
    }

    /// @brief Indicates that the span is not empty.
    /// @see is_empty
    /// @see size
    explicit constexpr operator bool() const noexcept {
        return size() != 0;
    }

    /// @brief Indicates that the span is empty.
    /// @see size
    constexpr auto is_empty() const noexcept -> bool {
        return size() == 0;
    }

    /// @brief Indicates that the span is empty.
    /// @see is_empty
    /// @see size
    constexpr auto empty() const noexcept -> bool {
        return size() == 0;
    }

    /// @brief Indicates that the span is terminated with value T(0) if applicable.
    constexpr auto is_zero_terminated() const noexcept -> bool {
        return size() < 0;
    }

    /// @brief Returns the number of elements in the span.
    /// @see is_empty
    constexpr auto size() const noexcept -> size_type {
        return EAGINE_LIKELY(_size >= 0) ? _size : -_size;
    }

    /// @brief Returns a pointer to the start of the span.
    /// @see begin
    /// @see end
    /// @see size
    constexpr auto data() const noexcept -> pointer {
        return _addr;
    }

    /// @brief Returns an interator to the start of the span.
    constexpr auto begin() const noexcept -> iterator {
        return _addr;
    }

    /// @brief Returns a iterator past the end of the span.
    constexpr auto end() const noexcept -> iterator {
        return begin() + size();
    }

    /// @brief Returns a reverse interator to the end of the span.
    constexpr auto rbegin() const noexcept {
        return reverse_iterator{end()};
    }

    /// @brief Returns a reverse interator past the begin of the span.
    constexpr auto rend() const noexcept {
        return reverse_iterator{begin()};
    }

    /// @brief Returns the memory address of the start of the span.
    constexpr auto addr() const noexcept -> address_type {
        return as_address(begin());
    }

    /// @brief Returns the memory address of the start of the span.
    constexpr auto begin_addr() const noexcept -> address_type {
        return as_address(begin());
    }

    /// @brief Returns the memory address past the end of the span.
    constexpr auto end_addr() const noexcept -> address_type {
        return as_address(end());
    }

    /// @brief Checks if the start of the span is aligned as the alignment of X.
    template <typename X>
    auto is_aligned_as() const noexcept -> bool {
        return addr().template is_aligned_as<X>();
    }

    /// @brief Indicates if this span encloses the specified address.
    /// @see contains
    auto encloses(const_address a) const noexcept -> bool {
        return (addr() <= a) && (a <= end_addr());
    }

    /// @brief Indicates if this span encloses another span.
    /// @see encloses
    /// @see overlaps
    template <typename Ts, typename Ps, typename Ss>
    auto contains(basic_span<Ts, Ps, Ss> that) const noexcept -> bool {
        return (addr() <= that.addr()) && (that.end_addr() <= end_addr());
    }

    /// @brief Indicates if this span overlaps with another span.
    /// @see encloses
    /// @see contains
    template <typename Ts, typename Ps, typename Ss>
    auto overlaps(const basic_span<Ts, Ps, Ss>& that) const noexcept -> bool {
        return encloses(that.addr()) || encloses(that.end_addr()) ||
               that.encloses(addr()) || that.encloses(end_addr());
    }

    /// @brief Returns a const reference to value at the specified index.
    /// @pre index < size()
    constexpr auto ref(size_type index) const noexcept
      -> std::add_const_t<value_type>& {
        return EAGINE_CONSTEXPR_ASSERT(index < size(), _addr[index]);
    }

    /// @brief Returns a reference to value at the specified index.
    /// @pre index < size()
    auto ref(size_type index) noexcept -> value_type& {
        return EAGINE_CONSTEXPR_ASSERT(index < size(), _addr[index]);
    }

    /// @brief Returns a const reference to value at the front of the span.
    /// @see back
    /// @pre !is_empty()
    auto front() const noexcept -> const value_type& {
        return EAGINE_CONSTEXPR_ASSERT(0 < size(), _addr[0]);
    }

    /// @brief Returns a reference to value at the front of the span.
    /// @see back
    /// @pre !is_empty()
    auto front() noexcept -> value_type& {
        return EAGINE_CONSTEXPR_ASSERT(0 < size(), _addr[0]);
    }

    /// @brief Returns a const reference to value at the back of the span.
    /// @see front
    /// @pre !is_empty()
    auto back() const noexcept -> const value_type& {
        return EAGINE_CONSTEXPR_ASSERT(0 < size(), _addr[size() - 1]);
    }

    /// @brief Returns a const reference to value at the back of the span.
    /// @see front
    /// @pre !is_empty()
    auto back() noexcept -> value_type& {
        return EAGINE_CONSTEXPR_ASSERT(0 < size(), _addr[size() - 1]);
    }

    /// @brief Returns a const reference to value at the specified index.
    /// @pre 0 <= index < size()
    template <typename Int>
    constexpr auto element(Int index) const noexcept
      -> std::enable_if_t<std::is_integral_v<Int>, std::add_const_t<value_type>&> {
        return ref(span_size(index));
    }

    /// @brief Returns a reference to value at the specified index.
    /// @pre 0 <= index < size()
    template <typename Int>
    auto element(Int index) noexcept
      -> std::enable_if_t<std::is_integral_v<Int>, value_type&> {
        return ref(span_size(index));
    }

    /// @brief Array subscript operator.
    /// @see element
    template <typename Int>
    auto operator[](Int index) noexcept
      -> std::enable_if_t<std::is_integral_v<Int>, value_type&> {
        return element(index);
    }

    /// @brief Array subscript operator.
    /// @see element
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
/// @brief Converts argument to span using a native pointer type.
/// @ingroup memory
/// @see relative
template <typename T, typename P, typename S>
static constexpr auto absolute(basic_span<T, P, S> spn) noexcept
  -> basic_span<T, T*, S> {
    return {spn};
}
//------------------------------------------------------------------------------
/// @brief Default alias for basic memory spans with native pointer type.
/// @ingroup memory
template <typename T, typename S = span_size_t>
using span = basic_span<T, T*, S>;
//------------------------------------------------------------------------------
/// @brief Alias for span<T> if T is mutable type. Ill defined otherwise.
/// @ingroup memory
template <typename T>
using span_if_mutable = std::enable_if_t<!std::is_const_v<T>, span<T>>;
//------------------------------------------------------------------------------
/// @brief Alias for spans with const element type.
/// @ingroup memory
template <typename T>
using const_span = span<std::add_const_t<T>>;
//------------------------------------------------------------------------------
/// @brief Creates a single-const-element view over the specified value.
/// @ingroup memory
template <typename T>
static constexpr auto view_one(const T& value) noexcept -> const_span<T> {
    return {std::addressof(value), span_size(1)};
}
//------------------------------------------------------------------------------
/// @brief Creates a single-element mutable span over the specified value.
/// @ingroup memory
template <typename T>
static constexpr auto cover_one(T& value) noexcept -> span_if_mutable<T> {
    return {std::addressof(value), span_size(1)};
}
//------------------------------------------------------------------------------
/// @brief Creates a single-const-element view from the specified pointer.
/// @ingroup memory
template <typename T>
static constexpr auto view_one(const T* pointer) noexcept -> const_span<T> {
    return {pointer, span_size(1)};
}
//------------------------------------------------------------------------------
/// @brief Creates a single-element mutable span from the specified pointer.
/// @ingroup memory
template <typename T>
static constexpr auto cover_one(T* pointer) noexcept -> span_if_mutable<T> {
    return {pointer, span_size(1)};
}
//------------------------------------------------------------------------------
/// @brief Creates a view starting at the specified pointer and specified length.
/// @ingroup memory
template <typename T, typename S>
static constexpr auto view(T* addr, S size) noexcept -> const_span<T> {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
/// @brief Creates a span starting at the specified pointer and specified length.
/// @ingroup memory
template <typename T, typename S>
static constexpr auto cover(T* addr, S size) noexcept -> span_if_mutable<T> {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
/// @brief Creates a view starting at the specified address and specified length.
/// @ingroup memory
template <typename T, typename S>
static constexpr auto view(const_address addr, S size) noexcept
  -> const_span<T> {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
/// @brief Creates a span starting at the specified address and specified length.
/// @ingroup memory
template <typename T, typename S>
static constexpr auto cover(address addr, S size) noexcept
  -> span_if_mutable<T> {
    return {addr, span_size(size)};
}
//------------------------------------------------------------------------------
/// @brief Creates a const view over the specified fixed-size array.
/// @ingroup memory
template <typename T, std::size_t N>
static constexpr auto view(const T (&array)[N]) noexcept -> const_span<T> {
    return view(static_cast<const T*>(array), N);
}
//------------------------------------------------------------------------------
/// @brief Creates a mutable span covering the specified fixed-size array.
/// @ingroup memory
template <typename T, std::size_t N>
static constexpr auto cover(T (&array)[N]) noexcept -> span_if_mutable<T> {
    return cover(static_cast<T*>(array), N);
}
//------------------------------------------------------------------------------
/// @brief Creates a const view over the specified initializer list.
/// @ingroup memory
template <typename T>
static constexpr auto view(std::initializer_list<T> il) noexcept
  -> const_span<T> {
    return view(il.begin(), il.size());
}
//------------------------------------------------------------------------------
/// @brief Creates a const view over a compatible contiguous container.
/// @ingroup memory
template <
  typename C,
  typename =
    std::enable_if_t<has_span_data_member_v<C> && has_span_size_member_v<C>>>
static constexpr auto view(const C& container) noexcept {
    return view(container.data(), container.size());
}
//------------------------------------------------------------------------------
/// @brief Creates a mutable span covering a compatible contiguous container.
/// @ingroup memory
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
/// @brief Indicates if the specified memory block can accomodate count elements of T.
/// @ingroup type_utils
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
/// @brief Indicates if the specified memory block can accomodate one element of T.
/// @ingroup type_utils
template <typename T, typename B, typename P, typename S>
static constexpr auto
can_accomodate(basic_span<B, P, S> blk, type_identity<T> tid = {}) noexcept {
    return can_accomodate(blk, 1, tid);
}
//------------------------------------------------------------------------------
/// @brief Returns a span, rebinding the element type (typically from basic_block).
/// @ingroup memory
/// @see as_bytes
/// @see as_chars
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
/// @brief Overload of extract for spans. Returns the first element,
/// @pre spn.size() >= 1
/// @ingroup memory
template <typename T, typename P, typename S>
static constexpr auto extract(basic_span<T, P, S> spn) noexcept -> T& {
    return EAGINE_CONSTEXPR_ASSERT(spn.size() >= 1, spn.front());
}
//------------------------------------------------------------------------------
/// @brief Overload of extract_or for spans. Returns the first element,
/// @ingroup memory
template <typename T, typename P, typename S>
static constexpr auto extract_or(basic_span<T, P, S> spn, T& fallback) noexcept
  -> T& {
    return (spn.size() >= 1) ? spn.front() : fallback;
}
//------------------------------------------------------------------------------
/// @brief Overload of extract_or for spans. Returns the first element,
/// @ingroup memory
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
