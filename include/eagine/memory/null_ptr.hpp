/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_NULL_PTR_HPP
#define EAGINE_MEMORY_NULL_PTR_HPP

#include "../types.hpp"
#include <cstdint>

namespace eagine::memory {
//------------------------------------------------------------------------------
/// @brief Class for doing pointer arithmetic on null pointers.
/// @ingroup type_utils
/// @see typed_nullptr
template <typename T>
struct typed_nullptr_t {};
//------------------------------------------------------------------------------
/// @brief Template constant for doing pointer arithmetic on null pointers.
/// @ingroup type_utils
template <typename T>
constexpr typed_nullptr_t<T> typed_nullptr = {};
//------------------------------------------------------------------------------
/// @brief Pointer arithmetic addition operator for null pointers.
/// @ingroup type_utils
template <typename T, typename N>
static constexpr auto operator+(typed_nullptr_t<T>, N n) noexcept -> T* {
    return reinterpret_cast<T*>(std::uintptr_t(std_size(n) * sizeof(T)));
}
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_NULL_PTR_HPP
