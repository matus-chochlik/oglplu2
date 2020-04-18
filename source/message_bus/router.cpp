///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/logging/root_logger.hpp>
#include <eagine/main.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router.hpp>
#include <eagine/program_args.hpp>
#include <eagine/signal_switch.hpp>
//------------------------------------------------------------------------------
namespace eagine {

int main(main_ctx& ctx) {
    signal_switch interrupted;

    auto& args = ctx.args();
    auto& log = ctx.log();

    log.info("message bus router starting up");

    msgbus::connection_setup conn_setup(log);
    conn_setup.default_init(args);

    msgbus::router router(log, args);
    conn_setup.setup_acceptors(
      router,
      msgbus::connection_kind::in_process |
        msgbus::connection_kind::local_interprocess |
        msgbus::connection_kind::remote_interprocess);

    while(!(interrupted || router.is_done())) {
        router.update();
    }

    log.debug("message bus router finishing");
    return 0;
}

} // namespace eagine
//------------------------------------------------------------------------------

