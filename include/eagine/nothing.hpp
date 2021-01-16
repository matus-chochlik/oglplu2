/**
 *  @file eagine/nothing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_NOTHING_HPP
#define EAGINE_NOTHING_HPP

namespace eagine {

struct nothing_t {
    using type = nothing_t;

    template <typename... T>
    constexpr nothing_t(T...) noexcept {}
};

static constexpr nothing_t nothing = {};

} // namespace eagine

#endif // EAGINE_NOTHING_HPP
