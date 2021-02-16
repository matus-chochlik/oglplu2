/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_TYPES_HPP
#define EAGINE_TYPES_HPP

#include "is_within_limits.hpp"
#include "type_identity.hpp"
#include "valid_if/nonnegative.hpp"
#include <cassert>
#include <cstdint>
#include <limits>
#include <type_traits>

namespace eagine {

/// @brief Byte type alias.
/// @ingroup type_utils
using byte = unsigned char;

/// @brief Alignment type used by std.
/// @ingroup type_utils
using std_align_t = std::size_t;

/// @brief Size type used by std.
/// @ingroup type_utils
using std_size_t = std::size_t;

/// @brief Signed span size type used by eagine.
/// @ingroup type_utils
using span_size_t = std::ptrdiff_t;

/// @brief Valid size type.
/// @ingroup type_utils
using valid_span_size = valid_if_nonnegative<span_size_t>;

/// @brief Converts argument to std alignment type.
/// @ingroup type_utils
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
static constexpr auto std_align(T v) noexcept {
    return limit_cast<std_align_t>(v);
}

/// @brief Converts argument to std size type.
/// @ingroup type_utils
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
static constexpr auto std_size(T v) noexcept {
    return limit_cast<std_size_t>(v);
}

/// @brief Converts argument to span size type.
/// @ingroup type_utils
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
static constexpr auto span_size(T v) noexcept {
    return limit_cast<span_size_t>(v);
}

/// @brief Returns the byte alignment of type T as span_size_t.
/// @ingroup type_utils
template <typename T>
static constexpr auto span_align_of(type_identity<T> = {}) noexcept {
    return span_size(alignof(T));
}

/// @brief Returns the byte size of type T as span_size_t.
/// @ingroup type_utils
template <typename T>
static constexpr auto span_size_of(type_identity<T> = {}) noexcept {
    return span_size(sizeof(T));
}

/// @brief Returns the total byte size of n elements of type T as span_size_t.
/// @ingroup type_utils
template <typename T, typename S>
static constexpr auto span_size_of(S n, type_identity<T> = {}) noexcept {
    return span_size(sizeof(T)) * span_size(n);
}

} // namespace eagine

#endif // EAGINE_TYPES_HPP
