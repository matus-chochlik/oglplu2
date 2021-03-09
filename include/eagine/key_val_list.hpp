/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_KEY_VAL_LIST_HPP
#define EAGINE_KEY_VAL_LIST_HPP

#include "span.hpp"
#include <array>
#include <type_traits>
#include <utility>
#include <vector>

namespace eagine {

template <typename Traits, std::size_t N = 0>
class key_value_list;

/// @brief A single key/value pair for a key/value list.
/// @ingroup type_utils
/// @see key_value_list
template <typename Traits>
struct key_value_list_element {
    /// @brief Alias for the key type.
    using key_type = typename Traits::key_type;
    /// @brief Alias for the value type.
    using value_type = typename Traits::value_type;

    key_type _key;
    value_type _value;

    /// @brief Construction from the key and the value.
    constexpr key_value_list_element(key_type key, value_type value) noexcept
      : _key{key}
      , _value{value} {}
};

template <typename Traits, std::size_t N>
struct key_value_list_base;

template <typename Traits>
struct key_value_list_base<Traits, 0> {
    using value_type = typename Traits::value_type;

    key_value_list_base() = default;

    static auto data() noexcept -> const value_type* {
        static const value_type term = Traits::terminator();
        return &term;
    }
};

template <typename Traits>
struct key_value_list_base<Traits, 2> {
    std::array<typename Traits::value_type, 3> _elements;

    using key_type = typename Traits::key_type;
    using conv_type = typename Traits::conv_type;
    using value_type = typename Traits::value_type;

    constexpr key_value_list_base(key_type key, value_type value) noexcept
      : _elements{{value_type(conv_type(key)), value, Traits::terminator()}} {}

    constexpr key_value_list_base(
      const key_value_list_base<Traits, 0>&,
      key_type key,
      value_type value,
      std::index_sequence<>) noexcept
      : _elements{{value_type(conv_type(key)), value, Traits::terminator()}} {}

    auto data() const noexcept -> const value_type* {
        return _elements.data();
    }
};

template <typename Traits, std::size_t N>
struct key_value_list_base {
    std::array<typename Traits::value_type, N + 1> _elements;

    using key_type = typename Traits::key_type;
    using conv_type = typename Traits::conv_type;
    using value_type = typename Traits::value_type;

    template <
      std::size_t M,
      std::size_t... I,
      typename = std::enable_if_t<(M + 2 == N) && (sizeof...(I) == M)>>
    constexpr key_value_list_base(
      const key_value_list_base<Traits, M>& head,
      key_type key,
      value_type value,
      std::index_sequence<I...>) noexcept
      : _elements{
          {head._elements[I]...,
           value_type(conv_type(key)),
           value,
           Traits::terminator()}} {}

    auto data() const noexcept -> const value_type* {
        return _elements.data();
    }
};

/// @brief Template for classes wrapping static key/value typically attribute lists.
/// @ingroup type_utils
/// @tparam Traits policy class customizing the instantiation.
/// @tparam N the number of elements in the list (not including the terminating zero).
template <typename Traits, std::size_t N>
class key_value_list {
public:
    /// @brief Alias for the key type.
    using key_type = typename Traits::key_type;

    /// @brief Alias for the value type.
    using value_type = typename Traits::value_type;

    /// @brief Default constructor.
    key_value_list() = default;

    template <std::size_t M, typename = std::enable_if_t<M + 2 == N>>
    constexpr key_value_list(
      const key_value_list_base<Traits, M>& head,
      key_type key,
      value_type value) noexcept
      : _base(head, key, value, std::make_index_sequence<M>()) {}

    key_value_list(const key_value_list_element<Traits>& head) noexcept
      : _base(head._key, head._value) {}

    /// @brief Returns the size of the element array (including the terminating zero).
    /// @see data
    static constexpr auto size() noexcept -> span_size_t {
        return span_size(N + 1);
    }

    /// @brief Returns a pointer to the internal element array.
    /// @see size
    auto data() const noexcept -> const value_type* {
        return _base.data();
    }

    /// @brief Copies the internal element array into a vector.
    /// @see get
    auto copy() const noexcept -> std::vector<value_type> {
        return {data(), data() + size()};
    }

    /// @brief A const view of the internal element array.
    /// @see copy
    auto get() const noexcept -> span<const value_type> {
        return {data(), size()};
    }

    /// @brief Appends a key/value pair and returns a new extended list.
    constexpr auto
    append(const key_value_list_element<Traits>& key_val) const noexcept
      -> key_value_list<Traits, N + 2> {
        return {_base, key_val._key, key_val._value};
    }

private:
    key_value_list_base<Traits, N> _base;
};

/// @brief Concatenates two individual key/value elements into a key/value list.
/// @ingroup type_utils
/// @relates key_value_list
/// @see key_value_list_element
template <typename Traits>
static constexpr auto operator+(
  const key_value_list_element<Traits>& l,
  const key_value_list_element<Traits>& r) noexcept
  -> key_value_list<Traits, 4> {
    return key_value_list<Traits, 2>(l).append(r);
}

/// @brief Adds a key/value pair into a key/value list, returns a new list.
/// @ingroup type_utils
/// @relates key_value_list
/// @see key_value_list_element
template <typename Traits, std::size_t N>
static constexpr auto operator+(
  const key_value_list<Traits, N>& l,
  const key_value_list_element<Traits>& r) noexcept
  -> key_value_list<Traits, N + 2> {
    return l.append(r);
}

} // namespace eagine

#endif // EAGINE_KEY_VAL_LIST_HPP
