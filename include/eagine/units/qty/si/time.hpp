/**
 *  @file eagine/units/qty/si/time.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_QTY_SI_TIME_1512222148_HPP
#define EAGINE_UNITS_QTY_SI_TIME_1512222148_HPP

#include "../../quantity.hpp"
#include "../../unit/si/time.hpp"

namespace eagine {
namespace units {

template <typename T>
static inline auto
milliseconds(const T& v) {
    return quantity<millisecond>(v);
}

template <typename T>
static inline auto
seconds(const T& v) {
    return quantity<second>(v);
}

template <typename T>
static inline auto
minutes(const T& v) {
    return quantity<minute>(v);
}

template <typename T>
static inline auto
hours(const T& v) {
    return quantity<hour>(v);
}

template <typename T>
static inline auto
days(const T& v) {
    return quantity<day>(v);
}

} // namespace units
} // namespace eagine

#endif // include guard
