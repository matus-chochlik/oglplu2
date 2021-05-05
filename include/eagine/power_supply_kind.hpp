/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_POWER_SUPPLY_KIND_HPP
#define EAGINE_POWER_SUPPLY_KIND_HPP

#include "reflect/map_enumerators.hpp"
#include <cstdint>

namespace eagine {

/// @brief System power supply kind.
/// @ingroup msgbus
/// @see system_info
enum class power_supply_kind : std::uint8_t {
    /// @brief Unknown power supply.
    unknown,
    /// @brief Battery.
    battery,
    /// @brief AC power supply.
    ac_supply
};

template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<power_supply_kind>, Selector) noexcept {
    return enumerator_map_type<power_supply_kind, 3>{
      {{"unknown", power_supply_kind::unknown},
       {"battery", power_supply_kind::battery},
       {"ac_supply", power_supply_kind::ac_supply}}};
}

} // namespace eagine

#endif
