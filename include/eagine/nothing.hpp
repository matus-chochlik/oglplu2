/**
 *  @file eagine/nothing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_NOTHING_1509260923_HPP
#define EAGINE_NOTHING_1509260923_HPP

namespace eagine {

struct nothing_t {
    typedef nothing_t type;
};

static constexpr nothing_t nothing = {};

} // namespace eagine

#endif // include guard
