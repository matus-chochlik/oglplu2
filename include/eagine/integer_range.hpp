/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INTEGER_RANGE_HPP
#define EAGINE_INTEGER_RANGE_HPP

#include "iterator.hpp"

namespace eagine {

/// @brief Integer range type template usable in range-based loops.
/// @ingroup type_utils
///
/// Instances of this class can be used as the range in range-based for loops
/// instead of using, comparing and incrementing a for loop variable.
template <typename T>
class integer_range {
public:
    /// @brief Default constructor.
    /// @post empty()
    /// @post begin() == end()
    constexpr integer_range() noexcept = default;

    /// @brief Initialization specifying the past the end integer value.
    /// @post size() == e
    constexpr integer_range(T e) noexcept
      : _end{e} {}

    /// @brief Initialization specifying the begin and past the end integer values.
    /// @post size() == e - b
    constexpr integer_range(T b, T e) noexcept
      : _begin{b}
      , _end{e} {}

    /// @brief Iterator type alias.
    using iterator = selfref_iterator<T>;

    /// @brief Iteration count type alias.
    using size_type = decltype(std::declval<T>() - std::declval<T>());

    /// @brief Indicates that the range is empty.
    /// @see size
    constexpr auto empty() const noexcept {
        return _end == _begin;
    }

    /// @brief Returns the number of iteration steps in this range.
    /// @see empty
    constexpr auto size() const noexcept {
        return _end - _begin;
    }

    /// @brief Returns the iterator to the start of the range.
    constexpr auto begin() const noexcept -> iterator {
        return {_begin};
    }

    /// @brief Returns the iterator past the end of the range.
    constexpr auto end() const noexcept -> iterator {
        return {_end};
    }

private:
    T _begin{0};
    T _end{0};
};

/// @brief Deduction guide for integer_range.
/// @ingroup type_utils
template <typename B, typename E>
integer_range(B, E) -> integer_range<std::common_type_t<B, E>>;

} // namespace eagine

#endif // EAGINE_INTEGER_RANGE_HPP
