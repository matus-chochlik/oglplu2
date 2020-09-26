/**
 *  @file eagine/byteset.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BYTESET_HPP
#define EAGINE_BYTESET_HPP

#include "memory/block.hpp"
#include "types.hpp"
#include <climits>
#include <type_traits>
#include <utility>

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
        std::conjunction_v<std::true_type, std::is_convertible<B, value_type>...>>>
    explicit constexpr inline byteset(B... b) noexcept
      : _bytes{value_type{b}...} {}

    template <
      std::size_t... I,
      typename UInt,
      typename =
        std::enable_if_t<(sizeof(UInt) >= N) && std::is_integral_v<UInt>>>
    constexpr inline byteset(std::index_sequence<I...>, UInt init) noexcept
      : _bytes{value_type((init >> (8 * (N - I - 1))) & 0xFFU)...} {}

    template <
      typename UInt,
      typename =
        std::enable_if_t<(sizeof(UInt) >= N) && std::is_integral_v<UInt>>>
    explicit constexpr inline byteset(UInt init) noexcept
      : byteset(std::make_index_sequence<N>(), init) {}

    auto data() noexcept -> pointer {
        return _bytes;
    }

    constexpr auto data() const noexcept -> const_pointer {
        return _bytes;
    }

    constexpr auto size() const noexcept -> size_type {
        return N;
    }

    constexpr auto block() const noexcept -> memory::const_block {
        return {data(), size()};
    }

    constexpr auto operator[](size_type i) noexcept -> reference {
        return _bytes[i];
    }

    constexpr auto operator[](size_type i) const noexcept -> const_reference {
        return _bytes[i];
    }

    constexpr auto front() noexcept -> reference {
        return _bytes[0];
    }

    constexpr auto front() const noexcept -> const_reference {
        return _bytes[0];
    }

    constexpr auto back() noexcept -> reference {
        return _bytes[N - 1];
    }

    constexpr auto back() const noexcept -> const_reference {
        return _bytes[N - 1];
    }

    auto begin() noexcept -> iterator {
        return _bytes + 0;
    }

    auto end() noexcept -> iterator {
        return _bytes + N;
    }

    constexpr auto begin() const noexcept -> const_iterator {
        return _bytes + 0;
    }

    constexpr auto end() const noexcept -> const_iterator {
        return _bytes + N;
    }

    friend constexpr inline auto
    compare(const byteset& a, const byteset& b) noexcept {
        return _do_cmp(a, b, std::make_index_sequence<N>{});
    }

    friend constexpr inline auto
    operator==(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) == 0;
    }

    friend constexpr inline auto
    operator!=(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) != 0;
    }

    friend constexpr inline auto
    operator<(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) < 0;
    }

    friend constexpr inline auto
    operator<=(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) <= 0;
    }

    friend constexpr inline auto
    operator>(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) > 0;
    }

    friend constexpr inline auto
    operator>=(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) >= 0;
    }

    template <
      typename UInt,
      typename =
        std::enable_if_t<(sizeof(UInt) >= N) && std::is_integral_v<UInt>>>
    constexpr inline auto as(UInt i = 0) const noexcept {
        return _push_back_to(i, 0);
    }

private:
    value_type _bytes[N]{};

    template <typename UInt>
    constexpr inline auto
    _push_back_to(UInt state, std::size_t i) const noexcept -> UInt {
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        return (i < N) ? _push_back_to((state << CHAR_BIT) | _bytes[i], i + 1)
                       : state;
    }

    static constexpr inline auto _cmp_byte(value_type a, value_type b) noexcept
      -> int {
        return (a == b) ? 0 : (a < b) ? -1 : 1;
    }

    static constexpr inline auto
    _do_cmp(const byteset&, const byteset&, std::index_sequence<>) noexcept
      -> int {
        return 0;
    }

    template <std::size_t I, std::size_t... In>
    static constexpr inline auto _do_cmp(
      const byteset& a,
      const byteset& b,
      std::index_sequence<I, In...>) noexcept -> int {
        return (a._bytes[I] == b._bytes[I])
                 ? _do_cmp(a, b, std::index_sequence<In...>{})
                 : _cmp_byte(a._bytes[I], b._bytes[I]);
    }
};

} // namespace eagine

#endif // EAGINE_BYTESET_HPP
