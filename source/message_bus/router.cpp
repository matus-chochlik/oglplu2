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
#include <eagine/message_bus/direct.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/message_bus/router.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/message_bus/service/build_info.hpp>
#include <eagine/message_bus/service/host_info.hpp>
#include <eagine/message_bus/service/ping_pong.hpp>
#include <eagine/message_bus/service/system_info.hpp>
#include <eagine/signal_switch.hpp>
#include <eagine/watchdog.hpp>
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
namespace msgbus {
using router_node_base = service_composition<
  pingable<build_info_provider<system_info_provider<host_info_provider<>>>>>;
//------------------------------------------------------------------------------
class router_node
  : public main_ctx_object
  , public router_node_base {
    using base = router_node_base;

public:
    router_node(endpoint& bus)
      : main_ctx_object{EAGINE_ID(RouterNode), bus}
      , base{bus} {}

    auto update() -> bool {
        some_true something_done{};
        something_done(base::update_and_process_all());

        return something_done;
    }
};
} // namespace msgbus
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    signal_switch interrupted;

    auto& log = ctx.log();
    log.info("message bus router starting up");

    ctx.system().preinitialize();

    auto local_acceptor{std::make_unique<msgbus::direct_acceptor>(ctx)};
    msgbus::endpoint node_endpoint{EAGINE_ID(RutrNodeEp), ctx};
    node_endpoint.add_connection(local_acceptor->make_connection());
    msgbus::router_node node{node_endpoint};

    msgbus::router_address address(ctx);
    msgbus::connection_setup conn_setup(ctx);

    msgbus::router router(ctx);
    router.add_ca_certificate_pem(ca_certificate_pem(ctx));
    router.add_certificate_pem(msgbus_router_certificate_pem(ctx));
    conn_setup.setup_acceptors(router, address);
    router.add_acceptor(std::move(local_acceptor));

    std::uintmax_t cycles_work{0};
    std::uintmax_t cycles_idle{0};
    int idle_streak{0};
    int max_idle_streak{0};

    auto update_round = [&]() -> bool {
        some_true something_done{};
        something_done(router.update(8));
        something_done(node.update());

        if(EAGINE_LIKELY(something_done)) {
            ++cycles_work;
            idle_streak = 0;
            return true;
        } else {
            ++cycles_idle;
            max_idle_streak = math::maximum(max_idle_streak, ++idle_streak);
            std::this_thread::sleep_for(
              std::chrono::milliseconds(math::minimum(idle_streak / 8, 8)));
            return false;
        }
    };

    auto& wd = ctx.watchdog();
    wd.declare_initialized();

    if(ctx.config().is_set("msg_bus.keep_running")) {
        while(EAGINE_LIKELY(!interrupted)) {
            update_round();
            wd.notify_alive();
        }
    } else {
        std::chrono::duration<float> max_inactive{60};
        ctx.config().fetch("msg_bus.router.max_inactive", max_inactive);
        timeout inactive{max_inactive};
        while(EAGINE_LIKELY(!(interrupted || inactive))) {
            if(update_round()) {
                inactive.reset();
            }
            wd.notify_alive();
        }
    }

    wd.announce_shutdown();

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

auto main(int argc, const char** argv) -> int {
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(RouterExe);
    return eagine::main_impl(argc, argv, options);
}
