/**
 *  @file eagine/logging/type/remote_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_LOGGING_TYPE_REMOTE_NODE_HPP
#define EAGINE_LOGGING_TYPE_REMOTE_NODE_HPP

#include "../../message_bus/remote_node.hpp"
#include "build_info.hpp"
#include "yes_no_maybe.hpp"

namespace eagine {
//------------------------------------------------------------------------------
static inline auto
adapt_log_entry_arg(identifier name, const msgbus::remote_node& value) {
    return [name, value](logger_backend& backend) {
        backend.add_unsigned(
          name, EAGINE_ID(uint64), extract_or(value.id(), 0U));

        if(auto opt_id{value.instance_id()}) {
            backend.add_unsigned(
              EAGINE_ID(instanceId), EAGINE_ID(uint32), extract(opt_id));
        }

        backend.add_string(
          EAGINE_ID(nodeKind), EAGINE_ID(enum), enumerator_name(value.kind()));

        backend.add_adapted(
          EAGINE_ID(isRutrNode), yes_no_maybe(value.is_router_node()));
        backend.add_adapted(
          EAGINE_ID(isBrdgNode), yes_no_maybe(value.is_bridge_node()));
        backend.add_adapted(
          EAGINE_ID(isPingable), yes_no_maybe(value.is_pingable()));
        backend.add_adapted(
          EAGINE_ID(isRespnsve), yes_no_maybe(value.is_responsive()));

        if(const auto opt_rate{value.ping_success_rate()}) {
            backend.add_float(
              EAGINE_ID(pingSucces), EAGINE_ID(Ratio), extract(opt_rate));
        }
        if(const auto opt_bld{value.instance().build()}) {
            backend.add_adapted(EAGINE_ID(buildInfo), extract(opt_bld));
        }

        if(const auto opt_name{value.app_name()}) {
            backend.add_string(
              EAGINE_ID(applName), EAGINE_ID(string), extract(opt_name));
        }

        if(const auto opt_name{value.display_name()}) {
            backend.add_string(
              EAGINE_ID(dispName), EAGINE_ID(string), extract(opt_name));
        }

        if(const auto opt_desc{value.description()}) {
            backend.add_string(
              EAGINE_ID(descrption), EAGINE_ID(string), extract(opt_desc));
        }

        if(const auto opt_id{value.host_id()}) {
            backend.add_unsigned(
              EAGINE_ID(hostId), EAGINE_ID(uint64), extract(opt_id));
        }

        if(const auto opt_name{value.host().name()}) {
            backend.add_string(
              EAGINE_ID(hostname), EAGINE_ID(string), extract(opt_name));
        }
        if(const auto opt_val{value.host().cpu_concurrent_threads()}) {
            backend.add_integer(
              EAGINE_ID(cpuThreads), EAGINE_ID(int64), extract(opt_val));
        }
    };
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_TYPE_REMOTE_NODE_HPP
