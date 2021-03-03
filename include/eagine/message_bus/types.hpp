/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_TYPES_HPP
#define EAGINE_MESSAGE_BUS_TYPES_HPP

#include "../identifier_t.hpp"
#include "../reflect/map_data_members.hpp"
#include "../types.hpp"
#include "connection_kind.hpp"
#include <tuple>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Alias for message sequence number type.
/// @ingroup msgbus
using message_sequence_t = std::uint32_t;
//------------------------------------------------------------------------------
/// @brief Structure holding part of router connection topology information.
/// @ingroup msgbus
struct router_topology_info {
    /// @brief The router message bus id.
    identifier_t router_id{0};

    /// @brief The remote node message bus id.
    identifier_t remote_id{0};

    /// @brief The router process instance id.
    process_instance_id_t instance_id{0U};

    /// @brief The connection kind.
    connection_kind connect_kind{0U};
};

template <typename Selector>
constexpr auto
data_member_mapping(type_identity<router_topology_info>, Selector) noexcept {
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
/// @brief Structure holding part of bridge connection topology information.
/// @ingroup msgbus
struct bridge_topology_info {
    /// @brief The bridge message bus id.
    identifier_t bridge_id{0};

    /// @brief The remote node message bus id.
    identifier_t opposite_id{0};

    /// @brief The bridge process instance id.
    process_instance_id_t instance_id{0U};
};

template <typename Selector>
constexpr auto
data_member_mapping(type_identity<bridge_topology_info>, Selector) noexcept {
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
/// @brief Structure holding part of endpoint connection topology information.
/// @ingroup msgbus
struct endpoint_topology_info {
    /// @brief The endpoint message bus id.
    identifier_t endpoint_id{0U};

    /// @brief The endpoint process instance id.
    process_instance_id_t instance_id{0U};
};

template <typename Selector>
constexpr auto
data_member_mapping(type_identity<endpoint_topology_info>, Selector) noexcept {
    using S = endpoint_topology_info;
    return make_data_member_mapping<S, identifier_t, process_instance_id_t>(
      {"endpoint_id", &S::endpoint_id}, {"instance_id", &S::instance_id});
}
//------------------------------------------------------------------------------
/// @brief Message bus endpoint information.
struct endpoint_info {
    /// @brief The application name.
    std::string app_name;

    /// @brief User-readable display name of the endpoint.
    std::string display_name;

    /// @brief User-readable description of the endpoint.
    std::string description;

    /// @brief Indicates if the endpoint is a router control node.
    bool is_router_node{false};

    /// @brief Indicates if the endpoint is a bridge control node.
    bool is_bridge_node{false};

    auto tie() const noexcept {
        return std::tie(
          app_name, display_name, description, is_router_node, is_bridge_node);
    }

    friend auto
    operator!=(const endpoint_info& l, const endpoint_info& r) noexcept
      -> bool {
        return l.tie() != r.tie();
    }
};

template <typename Selector>
constexpr auto
data_member_mapping(type_identity<endpoint_info>, Selector) noexcept {
    using S = endpoint_info;
    return make_data_member_mapping<
      S,
      std::string,
      std::string,
      std::string,
      bool,
      bool>(
      {"app_name", &S::app_name},
      {"display_name", &S::display_name},
      {"description", &S::description},
      {"is_router_node", &S::is_router_node},
      {"is_bridge_node", &S::is_bridge_node});
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_TYPES_HPP
