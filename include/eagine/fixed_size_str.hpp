/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_FIXED_SIZE_STR_HPP
#define EAGINE_FIXED_SIZE_STR_HPP

#include "assert.hpp"
#include "int_constant.hpp"
#include "string_span.hpp"
#include "types.hpp"
#include <cstring>

namespace eagine {

/// @brief String with maximum fixed-size internal storage.
/// @ingroup string_utils
template <span_size_t N>
class fixed_size_string {
public:
    /// @brief Default construction.
    /// @post empty
    fixed_size_string() noexcept {
        std::memset(_str, '\0', N);
    }

    /// @brief Construction from a pack of characters.
    template <typename... C, typename = std::enable_if_t<sizeof...(C) == N>>
    constexpr fixed_size_string(C... c) noexcept
      : _str{c...} {}

    /// @brief Construction from a C-string literal.
    fixed_size_string(const char (&s)[N]) noexcept {
        std::strncpy(_str, s, N);
        EAGINE_ASSERT(_str[N - 1] == '\0');
    }

    template <
      span_size_t N1,
      span_size_t N2,
      typename = std::enable_if_t<N1 + N2 == N + 1>>
    fixed_size_string(
      const fixed_size_string<N1>& s1,
      const fixed_size_string<N2>& s2) noexcept {
        std::strncpy(_str, s1._str, N1);
        std::strncpy(_str + N1 - 1, s2._str, N2);
    }

    /// @brief Alias for length type.
    using size_type = span_size_t;

    /// @brief Alias for iterator type.
    using iterator = char*;

    /// @brief Alias for const iterator type.
    using const_iterator = const char*;

    /// @brief Indicates if the string is empty.
    auto empty() const noexcept {
        return _str[0] == '\0';
    }

    /// @brief Returns the size of the string.
    auto size() const noexcept -> span_size_t {
        return N - 1;
    }

    /// @brief Returns pointer to the internally-stored character data.
    auto data() const noexcept {
        return static_cast<const char*>(_str);
    }

    /// @brief Returns pointer to the internally-stored character data.
    ///
    /// This function ensures that the internal storage is zero terminated.
    auto c_str() const noexcept {
        EAGINE_ASSERT(_str[N - 1] == '\0');
        return data();
    }

    /// @brief Returns iterator to the start of the string.
    auto begin() noexcept -> iterator {
        return _str;
    }

    /// @brief Returns const iterator to the start of the string.
    auto begin() const noexcept -> const_iterator {
        return _str;
    }

    /// @brief Returns iterator past the end of the string.
    auto end() noexcept -> iterator {
        return _str + N - 1;
    }

    /// @brief Returns const iterator past the end of the string.
    auto end() const noexcept -> const_iterator {
        return _str + N - 1;
    }

    /// @brief Returns a view over the internal character data storage.
    auto view() const noexcept -> string_view {
        return {_str, N - 1};
    }

    /// @brief Returns a view over the internal character data storage.
    /// @see view
    operator string_view() const noexcept {
        return view();
    }

private:
    static_assert(N > 0, "Zero-length fixed size strings are not supported");

    char _str[N] = {};

    template <span_size_t>
    friend class fixed_size_string;
};

/// @brief Creates a fixed_size_string from a C-string literal.
/// @ingroup string_utils
template <span_size_t N>
static inline auto make_fixed_size_string(const char (&str)[N]) noexcept {
    return fixed_size_string<N>(str);
}

/// @brief Concatenation operator for fixed_size_string.
/// @ingroup string_utils
template <span_size_t N1, span_size_t N2>
static inline auto operator+(
  const fixed_size_string<N1>& s1,
  const fixed_size_string<N2>& s2) noexcept {
    return fixed_size_string<N1 + N2 - 1>(s1, s2);
}

/// @brief Converts a single-digit decimal number into fixed_size_string.
/// @ingroup string_utils
template <int I>
static inline auto to_fixed_size_string(
  int_constant<I>,
  std::enable_if_t<(I >= 0) && (I < 10)>* = nullptr) noexcept {
    return fixed_size_string<2>(char('0' + I), '\0');
}

/// @brief Converts a multi-digit decimal number into fixed_size_string.
/// @ingroup string_utils
template <int I>
static inline auto to_fixed_size_string(
  int_constant<I>,
  std::enable_if_t<(I > 9)>* = nullptr) noexcept {
    return to_fixed_size_string(int_constant<I / 10>()) +
           fixed_size_string<2>(char('0' + I % 10), '\0');
}

/// @brief Converts a negative decimal number into fixed_size_string.
/// @ingroup string_utils
template <int I>
static inline auto to_fixed_size_string(
  int_constant<I>,
  std::enable_if_t<(I < 0)>* = nullptr) noexcept {
    return fixed_size_string<2>("-") + to_fixed_size_string(int_constant<-I>());
}

} // namespace eagine

#endif // EAGINE_FIXED_SIZE_STR_HPP
