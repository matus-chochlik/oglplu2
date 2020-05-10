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
#include <eagine/message_bus/router_address.hpp>
#include <eagine/signal_switch.hpp>

namespace eagine {
//------------------------------------------------------------------------------
int main(main_ctx& ctx) {
    signal_switch interrupted;

    auto& args = ctx.args();
    auto& log = ctx.log();

    log.info("message bus bridge starting up");

    msgbus::router_address address(log, args);

    msgbus::connection_setup conn_setup(log);
    conn_setup.default_init(args);

    msgbus::bridge bridge(log, args);
    conn_setup.setup_connectors(bridge, address);

    std::uintmax_t cycles_work{0};
    std::uintmax_t cycles_idle{0};

    while(!(interrupted || bridge.is_done())) {
        if(bridge.update()) {
            ++cycles_work;
        } else {
            ++cycles_idle;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }

    log.debug("message bus bridge finishing")
      .arg(EAGINE_ID(working), cycles_work)
      .arg(EAGINE_ID(idling), cycles_idle)
      .arg(
        EAGINE_ID(workRate),
        EAGINE_ID(Ratio),
        float(cycles_work) / (float(cycles_idle) + float(cycles_work)))
      .arg(
        EAGINE_ID(idleRate),
        EAGINE_ID(Ratio),
        float(cycles_idle) / (float(cycles_idle) + float(cycles_work)));

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine
