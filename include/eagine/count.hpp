/**
 *  @file eagine/count.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_COUNT_1509260923_HPP
#define EAGINE_COUNT_1509260923_HPP

namespace eagine {

template <typename Int = unsigned>
class count_t {
private:
    Int _c;

public:
    typedef Int value_type;

    constexpr inline count_t() noexcept
      : _c(0) {
    }

    constexpr value_type value() const noexcept {
        return _c;
    }

    constexpr operator value_type() const noexcept {
        return _c;
    }

    template <typename... P>
    constexpr void operator()(const P&...) noexcept {
        ++_c;
    }
};

} // namespace eagine

#endif // include guard
