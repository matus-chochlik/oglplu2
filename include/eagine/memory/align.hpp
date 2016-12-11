/**
 *  @file eagine/memory/align.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_ALIGN_1510290655_HPP
#define EAGINE_MEMORY_ALIGN_1510290655_HPP

#include "../types.hpp"

namespace eagine {
namespace memory {

static constexpr inline
span_size_t misalignment(span_size_t addr, span_size_t alignment)
noexcept { return addr % alignment; }

static constexpr inline
span_size_t misalignment(std::nullptr_t, span_size_t)
noexcept { return 0; }

static constexpr inline
bool is_aligned_to(span_size_t addr, span_size_t algn)
noexcept { return misalignment(addr, algn) == 0; }

static constexpr inline
bool is_aligned_to(std::nullptr_t, span_size_t)
noexcept { return true; }

template <typename T>
static constexpr inline
bool is_aligned_as(span_size_t addr)
noexcept { return is_aligned_to(addr, span_align_of<T>()); }

} // namespace memory
} // namespace eagine

#endif // include guard
