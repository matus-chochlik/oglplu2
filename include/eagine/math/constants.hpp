/**
 *  @file eagine/math/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_CONSTANTS_1509260923_HPP
#define EAGINE_MATH_CONSTANTS_1509260923_HPP

#include <cmath>

namespace eagine {
namespace math {

#ifdef M_PI
static constexpr const auto pi = M_PI;
#else
static constexpr const auto pi = 3.14159265358979323846;
#endif

} // namespace math
} // namespace eagine

#endif //include guard

