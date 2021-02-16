/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MATH_CONSTANTS_HPP
#define EAGINE_MATH_CONSTANTS_HPP

#include <cmath>

namespace eagine::math {

/// @var pi
/// @brief The pi constant.
/// @ingroup math
/// @see phi

#ifdef M_PI
static constexpr const auto pi = M_PI;
#else
static constexpr const auto pi = 3.14159265358979323846;
#endif

/// @var phi
/// @brief The phi constant.
/// @ingroup math
/// @see pi

static const auto phi = (1.0 + std::sqrt(5.0)) * 0.5;

} // namespace eagine::math

#endif // EAGINE_MATH_CONSTANTS_HPP
