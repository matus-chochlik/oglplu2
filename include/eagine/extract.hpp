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
static constexpr inline T& extract(std::shared_ptr<T>& ptr) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline const T& extract(
  std::shared_ptr<const T>& ptr) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T, typename D>
static constexpr inline T& extract(std::unique_ptr<T, D>& ptr) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T, typename D>
static constexpr inline const T& extract(
  std::unique_ptr<const T, D>& ptr) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_EXTRACT_HPP
