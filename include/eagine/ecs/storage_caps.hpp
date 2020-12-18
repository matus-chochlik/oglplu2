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
#include "../reflect/map_enumerators.hpp"

namespace eagine::ecs {
//------------------------------------------------------------------------------
enum class storage_cap_bit : unsigned short {
    hide = 1U << 0U,
    copy = 1U << 1U,
    swap = 1U << 2U,
    store = 1U << 3U,
    remove = 1U << 4U,
    modify = 1U << 5U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<storage_cap_bit>, Selector) noexcept {
    return enumerator_map_type<storage_cap_bit, 6>{
      {{"hide", storage_cap_bit::hide},
       {"copy", storage_cap_bit::copy},
       {"swap", storage_cap_bit::swap},
       {"store", storage_cap_bit::store},
       {"remove", storage_cap_bit::remove},
       {"modify", storage_cap_bit::modify}}};
}
//------------------------------------------------------------------------------
static inline auto operator|(storage_cap_bit a, storage_cap_bit b) noexcept
  -> bitfield<storage_cap_bit> {
    return {a, b};
}
//------------------------------------------------------------------------------
class storage_caps : public bitfield<storage_cap_bit> {
private:
    using _base = bitfield<storage_cap_bit>;

public:
    storage_caps() noexcept = default;

    storage_caps(bitfield<storage_cap_bit> base)
      : _base(base) {}

    auto can_hide() const noexcept -> bool {
        return has(storage_cap_bit::hide);
    }

    auto can_copy() const noexcept -> bool {
        return has(storage_cap_bit::hide);
    }

    auto can_swap() const noexcept -> bool {
        return has(storage_cap_bit::hide);
    }

    auto can_remove() const noexcept -> bool {
        return has(storage_cap_bit::remove);
    }

    auto can_store() const noexcept -> bool {
        return has(storage_cap_bit::store);
    }

    auto can_modify() const noexcept -> bool {
        return has(storage_cap_bit::modify);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::ecs

#endif // EAGINE_ECS_STORAGE_CAPS_HPP
