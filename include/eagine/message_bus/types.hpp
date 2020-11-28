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
#include <tuple>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
using message_sequence_t = std::uint32_t;
//------------------------------------------------------------------------------
struct router_topology_info {
    identifier_t router_id{0};
    identifier_t remote_id{0};
    process_instance_id_t instance_id{0U};
};

template <typename Selector>
constexpr auto
data_member_mapping(identity<router_topology_info>, Selector) noexcept {
    using S = router_topology_info;
    return make_data_member_mapping<
      S,
      identifier_t,
      identifier_t,
      process_instance_id_t>(
      {"router_id", &S::router_id},
      {"remote_id", &S::remote_id},
      {"instance_id", &S::instance_id});
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
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_TYPES_HPP
