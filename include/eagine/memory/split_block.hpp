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
#include "span_algo.hpp"

namespace eagine::memory {
//------------------------------------------------------------------------------
/// @brief Template for classes representing a memory block split in two parts.
/// @ingroup memory
template <bool IsConst>
class basic_split_block {
public:
    /// @brief Default constructor.
    constexpr basic_split_block() noexcept = default;

    /// @brief Initializing constructor.
    constexpr basic_split_block(basic_block<IsConst> blk) noexcept
      : _block{blk} {}

    /// @brief Returns the position of split as count of bytes since beginning.
    /// @see head
    /// @see tail
    /// @see advance
    constexpr auto split_position() const noexcept -> span_size_t {
        return _split;
    }

    /// @brief Returns the part of the block before the split (split not included).
    /// @see tail
    /// @see split_position
    constexpr auto head() const noexcept {
        return head(_block, _split);
    }

    /// @brief Returns the part of the block starting at the split until the end.
    /// @see head
    /// @see split_position
    constexpr auto tail() const noexcept {
        return skip(_block, _split);
    }

    /// @brief Moves the split by the specified amout (number of bytes).
    /// @see split_position
    /// @see skip_to_end
    auto advance(span_size_t amount) noexcept -> auto& {
        _split += amount;
        return *this;
    }

    /// @brief Moves the split to the end of the block.
    /// @see advance
    /// @see split_position
    auto skip_to_end() noexcept -> auto& {
        _split = _block.size();
        return *this;
    }

private:
    basic_block<IsConst> _block{};
    span_size_t _split{0};
};
//------------------------------------------------------------------------------
/// @brief Alias for non-const split blocks.
/// @ingroup memory
using split_block = basic_split_block<false>;

/// @brief Alias for const split blocks.
/// @ingroup memory
using const_split_block = basic_split_block<true>;
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_SPLIT_BLOCK_HPP
