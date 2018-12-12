/**
 *  @file eagine/range_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_RANGE_TYPES_1509260923_HPP
#define EAGINE_RANGE_TYPES_1509260923_HPP

#include "types.hpp"
#include "valid_if/le_size_ge0.hpp"
#include "valid_if/lt_size_ge0.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <typename R>
struct range_index_type {
    using type = typename R::size_type;
};
//------------------------------------------------------------------------------
template <typename R>
using range_index_t = typename range_index_type<R>::type;
//------------------------------------------------------------------------------
template <typename R>
using any_range_position = valid_if_nonnegative<range_index_t<R>>;
//------------------------------------------------------------------------------
template <typename R>
using valid_range_index = valid_if_lt_size_ge0<R, range_index_t<R>>;
//------------------------------------------------------------------------------
template <typename R>
using valid_range_position = valid_if_le_size_ge0<R, range_index_t<R>>;
//------------------------------------------------------------------------------
template <typename R, typename T>
static constexpr inline range_index_t<R> range_index(T i) noexcept {
    return limit_cast<range_index_t<R>>(i);
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // include guard
