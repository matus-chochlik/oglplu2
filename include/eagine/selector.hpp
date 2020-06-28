/**
 *  @file eagine/selector.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SELECTOR_HPP
#define EAGINE_SELECTOR_HPP

#include "identifier_t.hpp"

namespace eagine {

template <identifier_t>
struct selector {
    using type = selector;
};

} // namespace eagine

#endif // EAGINE_SELECTOR_HPP
