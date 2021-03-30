/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_BYTESET_HPP
#define EAGINE_BYTESET_HPP

#include "memory/block.hpp"
#include "types.hpp"
#include <climits>
#include <type_traits>
#include <utility>

namespace eagine {

/// @brief Class storing a sequence of bytes converting them to and from unsigned integer.
/// @ingroup type_utils
/// @tparam N the size - number of elements - in the byte sequence.
/// @see biteset
template <std::size_t N>
class byteset {
public:
    static_assert(N > 0, "byteset size must be greater than zero");

    /// @brief Alias for size type.
    using size_type = span_size_t;

    /// @brief Alias for element value type.
    using value_type = byte;

    /// @brief Alias for element reference type.
    using reference = value_type&;

    /// @brief Alias for const reference type.
    using const_reference = const value_type&;

    /// @brief Alias for pointer to element type.
    using pointer = value_type*;

    /// @brief Alias for pointer to const element type.
    using const_pointer = const value_type*;

    /// @brief Alias for iterator type.
    using iterator = value_type*;

    /// @brief Alias for const iterator type.
    using const_iterator = const value_type*;

    /// @brief Default constructor.
    constexpr byteset() noexcept = default;

    /// @brief Construction from a pack of integer values.
    template <
      typename... B,
      typename = std::enable_if_t<
        (sizeof...(B) == N) && (sizeof...(B) != 0) &&
        std::conjunction_v<std::true_type, std::is_convertible<B, value_type>...>>>
    explicit constexpr byteset(B... b) noexcept
      : _bytes{value_type{b}...} {}

    template <
      std::size_t... I,
      typename UInt,
      typename =
        std::enable_if_t<(sizeof(UInt) >= N) && std::is_integral_v<UInt>>>
    constexpr byteset(std::index_sequence<I...>, UInt init) noexcept
      : _bytes{value_type((init >> (8 * (N - I - 1))) & 0xFFU)...} {}

    /// @brief Construiction from unsigned integer that is then split into bytes.
    template <
      typename UInt,
      typename = std::enable_if_t<
        (sizeof(UInt) >= N) && std::is_integral_v<UInt> &&
        std::is_unsigned_v<UInt>>>
    explicit constexpr byteset(UInt init) noexcept
      : byteset(std::make_index_sequence<N>(), init) {}

    /// @brief Returns a pointer to the byte sequence start.
    /// @see size
    auto data() noexcept -> pointer {
        return _bytes;
    }

    /// @brief Returns a const pointer to the byte sequence start.
    /// @see size
    constexpr auto data() const noexcept -> const_pointer {
        return _bytes;
    }

    /// @brief Returns the count of bytes in the stored sequence.
    constexpr auto size() const noexcept -> size_type {
        return N;
    }

    /// @brief Creates a const view over the stored sequence of bytes.
    constexpr auto block() const noexcept -> memory::const_block {
        return {data(), size()};
    }

    /// @brief Subscript operator.
    constexpr auto operator[](size_type i) noexcept -> reference {
        return _bytes[i];
    }

    /// @brief Subscript operator.
    constexpr auto operator[](size_type i) const noexcept -> const_reference {
        return _bytes[i];
    }

    /// @brief Returns the first byte in the sequence.
    /// @see back
    constexpr auto front() noexcept -> reference {
        return _bytes[0];
    }

    /// @brief Returns the first byte in the sequence.
    /// @see back
    constexpr auto front() const noexcept -> const_reference {
        return _bytes[0];
    }

    /// @brief Returns the last byte in the sequence.
    /// @see front
    constexpr auto back() noexcept -> reference {
        return _bytes[N - 1];
    }

    /// @brief Returns the last byte in the sequence.
    /// @see front
    constexpr auto back() const noexcept -> const_reference {
        return _bytes[N - 1];
    }

    /// @brief Returns an iterator to the start of the byte sequence.
    auto begin() noexcept -> iterator {
        return _bytes + 0;
    }

    /// @brief Returns an iterator past the end of the byte sequence.
    auto end() noexcept -> iterator {
        return _bytes + N;
    }

    /// @brief Returns a const iterator to the start of the byte sequence.
    constexpr auto begin() const noexcept -> const_iterator {
        return _bytes + 0;
    }

    /// @brief Returns a const iterator past the end of the byte sequence.
    constexpr auto end() const noexcept -> const_iterator {
        return _bytes + N;
    }

    friend constexpr auto compare(const byteset& a, const byteset& b) noexcept {
        return _do_cmp(a, b, std::make_index_sequence<N>{});
    }

    /// @brief Equality comparison.
    friend constexpr auto
    operator==(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) == 0;
    }

    /// @brief Non-equality comparison.
    friend constexpr auto
    operator!=(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) != 0;
    }

    /// @brief Less-than comparison.
    friend constexpr auto
    operator<(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) < 0;
    }

    /// @brief Less-equal comparison.
    friend constexpr auto
    operator<=(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) <= 0;
    }

    /// @brief Greater-than comparison.
    friend constexpr auto
    operator>(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) > 0;
    }

    /// @brief Greater-equal comparison.
    friend constexpr auto
    operator>=(const byteset& a, const byteset& b) noexcept {
        return compare(a, b) >= 0;
    }

    /// @brief Converts the byte sequence into an unsigned integer value.
    template <
      typename UInt,
      typename =
        std::enable_if_t<(sizeof(UInt) >= N) && std::is_integral_v<UInt>>>
    constexpr auto as(UInt i = 0) const noexcept {
        return _push_back_to(i, 0);
    }

private:
    value_type _bytes[N]{};

    template <typename UInt>
    constexpr auto _push_back_to(UInt state, std::size_t i) const noexcept
      -> UInt {
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        return (i < N) ? _push_back_to((state << CHAR_BIT) | _bytes[i], i + 1)
                       : state;
    }

    static constexpr auto _cmp_byte(value_type a, value_type b) noexcept
      -> int {
        return (a == b) ? 0 : (a < b) ? -1 : 1;
    }

    static constexpr auto
    _do_cmp(const byteset&, const byteset&, std::index_sequence<>) noexcept
      -> int {
        return 0;
    }

    template <std::size_t I, std::size_t... In>
    static constexpr auto _do_cmp(
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
