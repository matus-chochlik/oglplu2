/**
 *  @file eagine/array_size.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ARRAY_SIZE_1509260923_HPP
#define EAGINE_ARRAY_SIZE_1509260923_HPP

#include "types.hpp"

namespace eagine {

template <typename T, std::size_t N>
static constexpr inline span_size_t
array_size(const T (&)[N]) noexcept {
    return span_size(N);
}

} // namespace eagine

#endif // include guard
