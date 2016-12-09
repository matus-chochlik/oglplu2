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
std_align_t misalignment(std_align_t addr, std_align_t alignment)
noexcept { return addr % alignment; }

static constexpr inline
bool is_aligned_to(std_align_t addr, std_align_t algn)
noexcept { return misalignment(addr, algn) == 0; }

template <typename T>
static constexpr inline
bool is_aligned_as(std_align_t addr)
noexcept { return is_aligned_to(addr, alignof(T)); }

} // namespace memory
} // namespace eagine

#endif // include guard
