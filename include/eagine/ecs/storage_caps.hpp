/**
 *  @file eagine/ecs/storage_caps.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_STORAGE_CAPS_HPP
#define EAGINE_ECS_STORAGE_CAPS_HPP

#include "../bitfield.hpp"

namespace eagine {
namespace ecs {

enum class storage_cap_bit : unsigned short {
    hide = 1 << 0,
    copy = 1 << 1,
    swap = 1 << 2,
    store = 1 << 3,
    remove = 1 << 4,
    modify = 1 << 5
};

static inline bitfield<storage_cap_bit> operator|(
  storage_cap_bit a, storage_cap_bit b) noexcept {
    return {a, b};
}

class storage_caps : public bitfield<storage_cap_bit> {
private:
    using _base = bitfield<storage_cap_bit>;

public:
    storage_caps() = default;

    storage_caps(bitfield<storage_cap_bit> base)
      : _base(base) {
    }

    bool can_hide() const noexcept {
        return has(storage_cap_bit::hide);
    }

    bool can_copy() const noexcept {
        return has(storage_cap_bit::hide);
    }

    bool can_swap() const noexcept {
        return has(storage_cap_bit::hide);
    }

    bool can_remove() const noexcept {
        return has(storage_cap_bit::remove);
    }

    bool can_store() const noexcept {
        return has(storage_cap_bit::store);
    }

    bool can_modify() const noexcept {
        return has(storage_cap_bit::modify);
    }
};

} // namespace ecs
} // namespace eagine

#endif // EAGINE_ECS_STORAGE_CAPS_HPP
