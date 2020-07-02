/**
 *  @file eagine/unit/quantity.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_QUANTITY_HPP
#define EAGINE_UNITS_QUANTITY_HPP

#include "../tagged_quantity.hpp"

namespace eagine::units {

template <typename U, typename T>
static inline tagged_quantity<T, U> quantity(const T& value) {
    return tagged_quantity<T, U>(value);
}

} // namespace eagine::units

#endif // EAGINE_UNITS_QUANTITY_HPP
