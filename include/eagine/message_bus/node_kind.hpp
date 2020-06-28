/**
 *  @file eagine/message_bus/node_kind.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_NODE_KIND_HPP
#define EAGINE_MESSAGE_BUS_NODE_KIND_HPP

#include "../reflect/map_enumerators.hpp"

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
enum class node_kind : std::uint8_t { endpoint, bridge, router };
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto enumerator_mapping(identity<node_kind>, Selector) noexcept {
    return enumerator_map_type<node_kind, 3>{
      {{"endpoint", node_kind::endpoint},
       {"bridge", node_kind::bridge},
       {"router", node_kind::router}}};
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_NODE_KIND_HPP

