/**
 *  @file eagine/extract.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_EXTRACT_HPP
#define EAGINE_EXTRACT_HPP

#include "assert.hpp"
#include <memory>
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline T& extract(T* ptr) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline T& extract_or(
  T* ptr, std::remove_const_t<T>& fallback) noexcept {
    return bool(ptr) ? *ptr : fallback;
}
//------------------------------------------------------------------------------
template <typename T, typename F>
static constexpr inline std::enable_if_t<std::is_convertible_v<F, T>, T>
extract_or(T* ptr, F&& fallback) {
    return bool(ptr) ? *ptr : T{std::forward<F>(fallback)};
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline T& extract(std::shared_ptr<T>& ptr) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline T& extract_or(
  std::shared_ptr<T>& ptr, std::remove_const_t<T>& fallback) noexcept {
    return bool(ptr) ? *ptr : fallback;
}
//------------------------------------------------------------------------------
template <typename T, typename F>
static constexpr inline std::enable_if_t<std::is_convertible_v<F, T>, T>
extract_or(std::shared_ptr<T>& ptr, F&& fallback) {
    return bool(ptr) ? *ptr : T{std::forward<F>(fallback)};
}
//------------------------------------------------------------------------------
template <typename T, typename D>
static constexpr inline T& extract(std::unique_ptr<T, D>& ptr) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T, typename D>
static constexpr inline T& extract_or(
  std::unique_ptr<T, D>& ptr, std::remove_const_t<T>& fallback) noexcept {
    return bool(ptr) ? *ptr : fallback;
}
//------------------------------------------------------------------------------
template <typename T, typename D, typename F>
static constexpr inline std::enable_if_t<std::is_convertible_v<F, T>, T>
extract_or(std::unique_ptr<T, D>& ptr, F&& fallback) {
    return bool(ptr) ? *ptr : T{std::forward<F>(fallback)};
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_EXTRACT_HPP
