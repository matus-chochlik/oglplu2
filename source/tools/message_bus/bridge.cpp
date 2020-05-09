///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/logging/root_logger.hpp>
#include <eagine/main.hpp>
#include <eagine/message_bus/bridge.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/signal_switch.hpp>

namespace eagine {
//------------------------------------------------------------------------------
int main(main_ctx& ctx) {
    signal_switch interrupted;

    auto& args = ctx.args();
    auto& log = ctx.log();

    log.info("message bus bridge starting up");

    msgbus::connection_setup conn_setup(log);
    conn_setup.default_init(args);

    msgbus::bridge bridge(log, args);
    conn_setup.setup_connectors(
      bridge,
      msgbus::connection_kind::in_process |
        msgbus::connection_kind::local_interprocess);

    while(!(interrupted || bridge.is_done())) {
        bridge.update();
    }

    log.debug("message bus bridge finishing");
    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine
