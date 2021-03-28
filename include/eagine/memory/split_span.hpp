/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_SPLIT_SPAN_HPP
#define EAGINE_MEMORY_SPLIT_SPAN_HPP

#include "span_algo.hpp"

namespace eagine::memory {
//------------------------------------------------------------------------------
/// @brief Template for classes representing a memory span split in two parts.
/// @ingroup memory
/// @tparam ValueType the type of elements assumed in the covered memory range.
/// @tparam Pointer the pointer type used to point to the start of the span.
/// @tparam SizeType the integer type used to count the elements in the span.
/// @see basic_split_block
template <
  typename ValueType,
  typename Pointer = ValueType*,
  typename SizeType = span_size_t>
class basic_split_span {
public:
    /// @brief Default constructor.
    constexpr basic_split_span() noexcept = default;

    /// @brief Initializing constructor.
    constexpr basic_split_span(
      basic_span<ValueType, Pointer, SizeType> spn) noexcept
      : _span{spn} {}

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
        return head(_span, _split);
    }

    /// @brief Returns the part of the block starting at the split until the end.
    /// @see head
    /// @see split_position
    constexpr auto tail() const noexcept {
        return skip(_span, _split);
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
        _split = _span.size();
        return *this;
    }

private:
    basic_span<ValueType, Pointer, SizeType> _span{};
    span_size_t _split{0};
};
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_SPLIT_SPAN_HPP
