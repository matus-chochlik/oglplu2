/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_BLOCK_HPP
#define EAGINE_MEMORY_BLOCK_HPP

#include "../assert.hpp"
#include "span.hpp"
#include <cstddef>
#include <utility>

namespace eagine::memory {
//------------------------------------------------------------------------------
/// @brief Alias for byte spans.
/// @ingroup type_utils
template <bool IsConst>
using basic_block = basic_span<std::conditional_t<IsConst, const byte, byte>>;
//------------------------------------------------------------------------------
/// @brief Alias for non-const byte memory span.
/// @ingroup memory
/// @see buffer
using block = basic_block<false>;

/// @brief Alias for const byte memory span.
/// @ingroup memory
/// @see buffer
using const_block = basic_block<true>;
//------------------------------------------------------------------------------
/// @brief Converts a span into a basic_block.
/// @ingroup memory
/// @see accomodate
/// @see as_chars
template <typename T, typename P, typename S>
static constexpr auto as_bytes(basic_span<T, P, S> spn) noexcept
  -> basic_block<std::is_const_v<T>> {
    return {spn.begin_addr(), spn.end_addr()};
}
//------------------------------------------------------------------------------
/// @brief Converts a block into a span of characters.
/// @ingroup memory
/// @see accomodate
/// @see as_bytes
static constexpr auto as_chars(block blk) noexcept {
    return accomodate<char>(blk);
}
//------------------------------------------------------------------------------
/// @brief Converts a block into a span of characters.
/// @ingroup memory
/// @see accomodate
/// @see as_bytes
static constexpr auto as_chars(const_block blk) noexcept {
    return accomodate<const char>(blk);
}
//------------------------------------------------------------------------------
class block_owner;
//------------------------------------------------------------------------------
/// @brief Specialization of block indicating byte span ownership.
/// @ingroup memory
/// @see block
/// @see block_owner
class owned_block : public block {
private:
    friend class block_owner;

    owned_block(block b) noexcept
      : block(b) {}

public:
    /// @brief Default constructor.
    /// @post is_empty()
    constexpr owned_block() noexcept = default;

    /// @brief Move constructor.
    owned_block(owned_block&& temp) noexcept
      : block(static_cast<const block&>(temp)) {
        temp.reset();
    }

    /// @brief Move assignment operator.
    auto operator=(owned_block&& temp) noexcept -> owned_block& {
        if(this != std::addressof(temp)) {
            static_cast<block&>(*this) = static_cast<const block&>(temp);
            temp.reset();
        }
        return *this;
    }

    /// @brief Not copy constructible.
    owned_block(const owned_block&) = delete;

    /// @brief Not copy assignable.
    auto operator=(const owned_block&) = delete;

    /// @brief Destructor.
    /// @pre is_empty()
    ~owned_block() noexcept {
        EAGINE_ASSERT(empty());
    }
};
//------------------------------------------------------------------------------
/// @brief Base class for classes that act as memory block owners.
/// @ingroup memory
/// @see owned_block
class block_owner {
protected:
    /// @brief Should be called to take the ownership of a memory block.
    [[nodiscard]] static auto acquire_block(block b) noexcept -> owned_block {
        return {b};
    }

    /// @brief Should be called to release the ownership of a memory block.
    static void release_block(owned_block&& b) noexcept {
        b.reset();
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_BLOCK_HPP
