///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "lib_common_pki.hpp"
#include <eagine/logging/root_logger.hpp>
#include <eagine/main_ctx.hpp>
#include <eagine/math/functions.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/signal_switch.hpp>
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
int main(main_ctx& ctx) {
    signal_switch interrupted;

    auto& args = ctx.args();
    auto& log = ctx.log();

    log.info("message bus router starting up");

    msgbus::router_address address(log, args);

    msgbus::connection_setup conn_setup(log);
    conn_setup.default_init(args);

    msgbus::router router(log, args);
    router.add_ca_certificate_pem(ca_certificate_pem(ctx));
    router.add_certificate_pem(msgbus_router_certificate_pem(ctx));
    conn_setup.setup_acceptors(router, address);

    std::uintmax_t cycles_work{0};
    std::uintmax_t cycles_idle{0};
    int idle_streak{0};
    int max_idle_streak{0};

    while(!(interrupted || router.is_done())) {
        if(router.update(8)) {
            ++cycles_work;
            idle_streak = 0;
        } else {
            ++cycles_idle;
            max_idle_streak = math::maximum(max_idle_streak, ++idle_streak);
            std::this_thread::sleep_for(
              std::chrono::milliseconds(math::minimum(idle_streak / 10, 10)));
        }
    }

    log.stat("message bus router finishing")
      .arg(EAGINE_ID(working), cycles_work)
      .arg(EAGINE_ID(idling), cycles_idle)
      .arg(
        EAGINE_ID(workRate),
        EAGINE_ID(Ratio),
        float(cycles_work) / (float(cycles_idle) + float(cycles_work)))
      .arg(
        EAGINE_ID(idleRate),
        EAGINE_ID(Ratio),
        float(cycles_idle) / (float(cycles_idle) + float(cycles_work)))
      .arg(EAGINE_ID(maxIdlStrk), max_idle_streak);

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine

int main(int argc, const char** argv) {
    eagine::main_ctx_options options;
    options.logger_id = EAGINE_ID(RouterExe);
    return eagine::main_impl(argc, argv, options);
}

