/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_SPLIT_BLOCK_HPP
#define EAGINE_MEMORY_SPLIT_BLOCK_HPP

#include "block.hpp"
#include "split_span.hpp"

namespace eagine::memory {
//------------------------------------------------------------------------------
/// @brief Alias for split span of bytes.
/// @ingroup type_utils
template <bool IsConst>
using basic_split_block =
  basic_split_span<std::conditional_t<IsConst, const byte, byte>>;

/// @brief Alias for non-const split blocks.
/// @ingroup memory
using split_block = basic_split_block<false>;

/// @brief Alias for const split blocks.
/// @ingroup memory
using const_split_block = basic_split_block<true>;
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_SPLIT_BLOCK_HPP
