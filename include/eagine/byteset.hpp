/**
 *  @file eagine/byteset.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BYTESET_1509260923_HPP
#define EAGINE_BYTESET_1509260923_HPP

#include "memory_block.hpp"
#include "std/type_traits.hpp"
#include "std/utility.hpp"
#include "types.hpp"
#include <climits>

namespace eagine {

template <std::size_t N>
class byteset {
public:
    static_assert(N > 0, "byteset size must be greater than zero");
    using size_type = span_size_t;
    using value_type = unsigned char;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;

    using iterator = value_type*;
    using const_iterator = const value_type*;

    constexpr byteset() = default;

    template <
      typename... B,
      typename = std::enable_if_t<
        (sizeof...(B) == N) && (sizeof...(B) != 0) &&
        std::
          conjunction_v<std::true_type, std::is_convertible<B, value_type>...>>>
    explicit constexpr inline byteset(B... b) noexcept
      : _bytes{value_type(b)...} {
    }

    pointer data() noexcept {
        return _bytes;
    }

    constexpr const_pointer data() const noexcept {
        return _bytes;
    }

    constexpr size_type size() const noexcept {
        return N;
    }

    const_memory_block block() const noexcept {
        return {data(), size()};
    }

    constexpr reference operator[](size_type i) noexcept {
        return _bytes[i];
    }

    constexpr const_reference operator[](size_type i) const noexcept {
        return _bytes[i];
    }

    constexpr reference front() noexcept {
        return _bytes[0];
    }

    constexpr const_reference front() const noexcept {
        return _bytes[0];
    }

    constexpr reference back() noexcept {
        return _bytes[N - 1];
    }

    constexpr const_reference back() const noexcept {
        return _bytes[N - 1];
    }

    iterator begin() noexcept {
        return _bytes + 0;
    }

    iterator end() noexcept {
        return _bytes + N;
    }

    constexpr const_iterator begin() const noexcept {
        return _bytes + 0;
    }

    constexpr const_iterator end() const noexcept {
        return _bytes + N;
    }

    friend constexpr inline int
    compare(const byteset& a, const byteset& b) noexcept {
        return _do_cmp(a, b, std::make_index_sequence<N>{});
    }

    friend constexpr inline bool
    operator==(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) == 0;
    }

    friend constexpr inline bool
    operator!=(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) != 0;
    }

    friend constexpr inline bool
    operator<(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) < 0;
    }

    friend constexpr inline bool
    operator<=(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) <= 0;
    }

    friend constexpr inline bool
    operator>(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) > 0;
    }

    friend constexpr inline bool
    operator>=(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) >= 0;
    }

    template <
      typename UInt,
      typename =
        std::enable_if_t<(sizeof(UInt) >= N) && std::is_integral_v<UInt>>>
    constexpr inline UInt as(UInt i = 0) const noexcept {
        return _push_back_to(i, 0);
    }

private:
    value_type _bytes[N];

    template <typename UInt>
    constexpr inline UInt _push_back_to(UInt state, std::size_t i) const
      noexcept {
        return (i < N) ? _push_back_to((state << CHAR_BIT) | _bytes[i], i + 1)
                       : state;
    }

    static constexpr inline int _cmp_byte(value_type a, value_type b) noexcept {
        return (a == b) ? 0 : (a < b) ? -1 : 1;
    }

    static constexpr inline int
    _do_cmp(const byteset&, const byteset&, std::index_sequence<>) noexcept {
        return 0;
    }

    template <std::size_t I, std::size_t... In>
    static constexpr inline int
    _do_cmp(const byteset& a, const byteset& b, std::index_sequence<I, In...>) {
        return (a._bytes[I] == b._bytes[I])
                 ? _do_cmp(a, b, std::index_sequence<In...>{})
                 : _cmp_byte(a._bytes[I], b._bytes[I]);
    }
};

} // namespace eagine

#endif // include guard
