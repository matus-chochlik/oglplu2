/**
 *  @file eagine/message_bus/verification.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_VERIFICATION_HPP
#define EAGINE_MESSAGE_BUS_VERIFICATION_HPP

#include "../bitfield.hpp"
#include "../reflect/map_enumerators.hpp"
#include <cstdint>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
enum class verification_bit : std::uint8_t {
    source_id = 1U << 0U,
    message_id = 1U << 1U,
    message_content = 1U << 2U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto enumerator_mapping(
  identity<verification_bit>, Selector) noexcept {
    return enumerator_map_type<verification_bit, 3>{
      {{"source_id", verification_bit::source_id},
       {"message_id", verification_bit::message_id},
       {"message_content", verification_bit::message_content}}};
}
//------------------------------------------------------------------------------
using verification_bits = bitfield<verification_bit>;
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_VERIFICATION_HPP
