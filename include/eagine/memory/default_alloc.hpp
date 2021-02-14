/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_DEFAULT_ALLOC_HPP
#define EAGINE_MEMORY_DEFAULT_ALLOC_HPP

#include "c_realloc.hpp"

namespace eagine::memory {

using default_byte_allocator = c_byte_reallocator<>;

} // namespace eagine::memory

#endif // EAGINE_MEMORY_DEFAULT_ALLOC_HPP
