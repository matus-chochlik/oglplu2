/**
 *  @file eagine/memory/null_ptr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_NULL_PTR_HPP
#define EAGINE_MEMORY_NULL_PTR_HPP

#include "../types.hpp"
#include <cstdint>

namespace eagine {
namespace memory {
//------------------------------------------------------------------------------
template <typename T>
struct typed_nullptr_t {};
//------------------------------------------------------------------------------
template <typename T>
constexpr typed_nullptr_t<T> typed_nullptr = {};
//------------------------------------------------------------------------------
template <typename T, typename N>
static constexpr inline T* operator+(typed_nullptr_t<T>, N n) noexcept {
    return reinterpret_cast<T*>(std::uintptr_t(std_size(n) * sizeof(T)));
}
//------------------------------------------------------------------------------
} // namespace memory
} // namespace eagine

#endif // EAGINE_MEMORY_NULL_PTR_HPP
