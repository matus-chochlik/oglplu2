/// @file eagine/memory/block.hpp
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
template <bool IsConst>
using basic_block = basic_span<std::conditional_t<IsConst, const byte, byte>>;
//------------------------------------------------------------------------------
using block = basic_block<false>;
using const_block = basic_block<true>;
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
static constexpr auto as_bytes(basic_span<T, P, S> spn) noexcept
  -> basic_block<std::is_const_v<T>> {
    return {spn.begin_addr(), spn.end_addr()};
}
//------------------------------------------------------------------------------
static constexpr auto as_chars(block blk) noexcept {
    return accomodate<char>(blk);
}
//------------------------------------------------------------------------------
static constexpr auto as_chars(const_block blk) noexcept {
    return accomodate<const char>(blk);
}
//------------------------------------------------------------------------------
class block_owner;
//------------------------------------------------------------------------------
class owned_block : public block {
private:
    friend class block_owner;

    owned_block(block b) noexcept
      : block(b) {}

public:
    constexpr owned_block() noexcept = default;

    owned_block(owned_block&& temp) noexcept
      : block(static_cast<const block&>(temp)) {
        temp.reset();
    }

    auto operator=(owned_block&& temp) noexcept -> owned_block& {
        if(this != std::addressof(temp)) {
            static_cast<block&>(*this) = static_cast<const block&>(temp);
            temp.reset();
        }
        return *this;
    }

    constexpr owned_block(const owned_block&) noexcept = delete;
    auto operator=(const owned_block&) noexcept = delete;

    ~owned_block() noexcept {
        EAGINE_ASSERT(empty());
    }
};
//------------------------------------------------------------------------------
class block_owner {
protected:
    [[nodiscard]] static auto acquire_block(block b) noexcept -> owned_block {
        return {b};
    }

    static void release_block(owned_block&& b) noexcept {
        b.reset();
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_BLOCK_HPP
