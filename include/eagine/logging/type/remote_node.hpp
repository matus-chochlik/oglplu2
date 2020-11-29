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
#include "../entry.hpp"

namespace eagine {
//------------------------------------------------------------------------------
static inline auto
adapt_log_entry_arg(identifier name, const msgbus::remote_node& value) {
    return [name, value](logger_backend& backend) {
        backend.add_unsigned(
          name, EAGINE_ID(uint64), extract_or(value.id(), 0U));

        backend.add_string(
          EAGINE_ID(nodeKind), EAGINE_ID(enum), enumerator_name(value.kind()));

        const auto is_router_endp{value.is_router_node()};
        backend.add_string(
          EAGINE_ID(isRutrNode),
          EAGINE_ID(YesNoMaybe),
          is_router_endp
            ? string_view("yes")
            : !is_router_endp ? string_view("no") : string_view("maybe"));

        const auto is_bridge_endp{value.is_bridge_node()};
        backend.add_string(
          EAGINE_ID(isBrdgNode),
          EAGINE_ID(YesNoMaybe),
          is_bridge_endp
            ? string_view("yes")
            : !is_bridge_endp ? string_view("no") : string_view("maybe"));

        const auto is_responsive{value.is_responsive()};
        backend.add_string(
          EAGINE_ID(isRespnsve),
          EAGINE_ID(YesNoMaybe),
          is_responsive
            ? string_view("yes")
            : !is_responsive ? string_view("no") : string_view("maybe"));

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

        if(const auto opt_rate{value.ping_success_rate()}) {
            backend.add_float(
              EAGINE_ID(pingSucces), EAGINE_ID(Ratio), extract(opt_rate));
        }
    };
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_TYPE_REMOTE_NODE_HPP
