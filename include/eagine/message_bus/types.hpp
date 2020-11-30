/**
 *  @file eagine/message_bus/types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_TYPES_HPP
#define EAGINE_MESSAGE_BUS_TYPES_HPP

#include "../identifier_t.hpp"
#include "../process.hpp"
#include "../reflect/map_data_members.hpp"
#include "../types.hpp"
#include "connection_kind.hpp"
#include <tuple>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
using message_sequence_t = std::uint32_t;
//------------------------------------------------------------------------------
struct router_topology_info {
    identifier_t router_id{0};
    identifier_t remote_id{0};
    process_instance_id_t instance_id{0U};
    connection_kind connect_kind{0U};
};

template <typename Selector>
constexpr auto
data_member_mapping(identity<router_topology_info>, Selector) noexcept {
    using S = router_topology_info;
    return make_data_member_mapping<
      S,
      identifier_t,
      identifier_t,
      process_instance_id_t,
      connection_kind>(
      {"router_id", &S::router_id},
      {"remote_id", &S::remote_id},
      {"instance_id", &S::instance_id},
      {"connect_kind", &S::connect_kind});
}
//------------------------------------------------------------------------------
struct bridge_topology_info {
    identifier_t bridge_id{0};
    identifier_t opposite_id{0};
    process_instance_id_t instance_id{0U};
};

template <typename Selector>
constexpr auto
data_member_mapping(identity<bridge_topology_info>, Selector) noexcept {
    using S = bridge_topology_info;
    return make_data_member_mapping<
      S,
      identifier_t,
      identifier_t,
      process_instance_id_t>(
      {"bridge_id", &S::bridge_id},
      {"opposite_id", &S::opposite_id},
      {"instance_id", &S::instance_id});
}
//------------------------------------------------------------------------------
struct endpoint_topology_info {
    identifier_t endpoint_id{0U};
    process_instance_id_t instance_id{0U};
};

template <typename Selector>
constexpr auto
data_member_mapping(identity<endpoint_topology_info>, Selector) noexcept {
    using S = endpoint_topology_info;
    return make_data_member_mapping<S, identifier_t, process_instance_id_t>(
      {"endpoint_id", &S::endpoint_id}, {"instance_id", &S::instance_id});
}
//------------------------------------------------------------------------------
struct endpoint_info {
    std::string display_name;
    std::string description;
    bool is_router_node{false};
    bool is_bridge_node{false};

    auto tie() const noexcept {
        return std::tie(
          display_name, description, is_router_node, is_bridge_node);
    }

    friend auto
    operator!=(const endpoint_info& l, const endpoint_info& r) noexcept
      -> bool {
        return l.tie() != r.tie();
    }
};

template <typename Selector>
constexpr auto data_member_mapping(identity<endpoint_info>, Selector) noexcept {
    using S = endpoint_info;
    return make_data_member_mapping<S, std::string, std::string, bool, bool>(
      {"display_name", &S::display_name},
      {"description", &S::description},
      {"is_router_node", &S::is_router_node},
      {"is_bridge_node", &S::is_bridge_node});
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_TYPES_HPP
