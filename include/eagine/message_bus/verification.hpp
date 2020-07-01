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

namespace eagine::msgbus {
//------------------------------------------------------------------------------
enum class verification_bit : std::uint8_t {
    source_id = 1U << 0U,
    source_certificate = 1U << 1U,
    source_private_key = 1U << 2U,
    message_id = 1U << 3U,
    message_content = 1U << 4U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto enumerator_mapping(
  identity<verification_bit>, Selector) noexcept {
    return enumerator_map_type<verification_bit, 5>{
      {{"source_id", verification_bit::source_id},
       {"source_certificate", verification_bit::source_certificate},
       {"source_private_key", verification_bit::source_private_key},
       {"message_id", verification_bit::message_id},
       {"message_content", verification_bit::message_content}}};
}
//------------------------------------------------------------------------------
using verification_bits = bitfield<verification_bit>;
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_VERIFICATION_HPP
