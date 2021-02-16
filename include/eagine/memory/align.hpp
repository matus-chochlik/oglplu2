/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_ALIGN_HPP
#define EAGINE_MEMORY_ALIGN_HPP

#include "../type_identity.hpp"
#include "../types.hpp"

namespace eagine::memory {
//------------------------------------------------------------------------------
/// @brief Calculates basic numeric address misalignment.
/// @ingroup memory
static constexpr auto
misalignment(span_size_t addr, span_size_t alignment) noexcept -> span_size_t {
    return addr % alignment;
}
//------------------------------------------------------------------------------
/// @brief Calculates basic numeric address misalignment.
/// @ingroup memory
static constexpr auto misalignment(std::nullptr_t, span_size_t) noexcept
  -> span_size_t {
    return 0;
}
//------------------------------------------------------------------------------
/// @brief Indicates if a basic numeric address is aligned.
/// @ingroup memory
static constexpr auto
is_aligned_to(span_size_t addr, span_size_t algn) noexcept {
    return misalignment(addr, algn) == 0;
}
//------------------------------------------------------------------------------
/// @brief Indicates if a basic numeric address is aligned.
/// @ingroup memory
static constexpr auto is_aligned_to(std::nullptr_t, span_size_t) noexcept {
    return true;
}
//------------------------------------------------------------------------------
/// @brief Indicates if a basic numeric address is aligned to alignment of type T.
/// @ingroup memory
template <typename T>
static constexpr auto
is_aligned_as(span_size_t addr, type_identity<T> = {}) noexcept {
    return is_aligned_to(addr, span_align_of<T>());
}
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_ALIGN_HPP
