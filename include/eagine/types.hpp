/**
 *  @file eagine/types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TYPES_1509260923_HPP
#define EAGINE_TYPES_1509260923_HPP

#include "span_fwd.hpp"
#include "std/type_traits.hpp"
#include "valid_if/nonnegative.hpp"
#include <cassert>
#include <cstdint>
#include <limits>

namespace eagine {

// byte type
typedef unsigned char byte;

// alignment type used by std
using std_align_t = std::size_t;
// size type used by std
using std_size_t = std::size_t;
// signed size type
using span_size_t = std::ptrdiff_t;
// valid size type
using valid_span_size = valid_if_nonnegative<span_size_t>;

template <typename T>
static constexpr inline T
safe_size_t_cast(T v) noexcept {
    return v;
}

template <typename T,
  typename F,
  typename = std::enable_if_t<std::is_integral_v<F> && !std::is_same_v<T, F>>>
static constexpr inline T
safe_size_t_cast(F v) noexcept {
    assert(T(v) >= std::numeric_limits<T>::min());
    assert(T(v) <= std::numeric_limits<T>::max());
    return static_cast<T>(v);
}

// convert to std alignment type
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
static constexpr inline std_align_t
std_align(T v) noexcept {
    return safe_size_t_cast<std_align_t>(v);
}

// convert to std size type
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
static constexpr inline std_size_t
std_size(T v) noexcept {
    return safe_size_t_cast<std_size_t>(v);
}

// convert to span size type
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
static constexpr inline span_size_t
span_size(T v) noexcept {
    return safe_size_t_cast<span_size_t>(v);
}

template <typename T>
static constexpr inline span_size_t
span_align_of(void) noexcept {
    return span_size(alignof(T));
}

template <typename T>
static constexpr inline span_size_t
span_size_of(void) noexcept {
    return span_size(sizeof(T));
}

template <typename T, typename S>
static constexpr inline span_size_t
span_size_of(S n) noexcept {
    return span_size(sizeof(T)) * span_size(n);
}

} // namespace eagine

#endif // include guard
