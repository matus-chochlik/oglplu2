/**
 *  @file eagine/memory/block.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_BLOCK_1510290655_HPP
#define EAGINE_MEMORY_BLOCK_1510290655_HPP

#include "span.hpp"
#include <cstddef>
#include <utility>

namespace eagine {
namespace memory {
//------------------------------------------------------------------------------
template <bool IsConst>
using basic_block = basic_span<std::conditional_t<IsConst, const byte, byte>>;
//------------------------------------------------------------------------------
using block = basic_block<false>;
using const_block = basic_block<true>;
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
static constexpr inline basic_block<std::is_const_v<T>> as_bytes(
  basic_span<T, P, S> spn) noexcept {
    return {spn.begin_addr(), spn.end_addr()};
}
//------------------------------------------------------------------------------
class block_owner;
//------------------------------------------------------------------------------
class owned_block : public block {
private:
    friend class block_owner;

    owned_block(block b) noexcept
      : block(b) {
    }

public:
    constexpr owned_block() noexcept = default;

    owned_block(owned_block&& temp) noexcept
      : block(static_cast<const block&>(temp)) {
        temp.reset();
    }

    owned_block& operator=(owned_block&& temp) noexcept {
        if(this != std::addressof(temp)) {
            static_cast<block&>(*this) = static_cast<const block&>(temp);
            temp.reset();
        }
        return *this;
    }

    constexpr owned_block(const owned_block&) noexcept = delete;
    owned_block& operator=(const owned_block&) noexcept = delete;

    ~owned_block() noexcept {
        assert(empty());
    }
};
//------------------------------------------------------------------------------
class block_owner {
protected:
    [[nodiscard]] static inline owned_block acquire_block(block b) noexcept {
        return {b};
    }

    static inline void release_block(owned_block&& b) noexcept {
        b.reset();
    }
};
//------------------------------------------------------------------------------
} // namespace memory
} // namespace eagine

#endif // include guard
