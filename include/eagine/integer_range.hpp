/**
 *  @file eagine/integer_range.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INTEGER_RANGE_HPP
#define EAGINE_INTEGER_RANGE_HPP

#include "iterator.hpp"

namespace eagine {

template <typename T>
class integer_range {
public:
    constexpr integer_range() noexcept = default;

    constexpr integer_range(T e) noexcept
      : _end{e} {}

    constexpr integer_range(T b, T e) noexcept
      : _begin{b}
      , _end{e} {}

    using iterator = selfref_iterator<T>;
    using size_type = decltype(std::declval<T>() - std::declval<T>());

    constexpr auto empty() const noexcept {
        return _end == _begin;
    }

    constexpr auto size() const noexcept {
        return _end - _begin;
    }

    constexpr auto begin() const noexcept -> iterator {
        return {_begin};
    }

    constexpr auto end() const noexcept -> iterator {
        return {_end};
    }

private:
    T _begin{0};
    T _end{0};
};

} // namespace eagine

#endif // EAGINE_INTEGER_RANGE_HPP
