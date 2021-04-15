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
#include <eagine/message_bus/service/endpoint_info.hpp>
#include <eagine/message_bus/service/host_info.hpp>
#include <eagine/message_bus/service/ping_pong.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/message_bus/service/system_info.hpp>
#include <eagine/signal_switch.hpp>
#include <eagine/watchdog.hpp>
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
namespace msgbus {
using router_node_base =
  service_composition<shutdown_target<pingable<build_info_provider<
    system_info_provider<host_info_provider<endpoint_info_provider<>>>>>>>;
//------------------------------------------------------------------------------
class router_node
  : public main_ctx_object
  , public router_node_base {
    using base = router_node_base;

public:
    router_node(endpoint& bus)
      : main_ctx_object{EAGINE_ID(RouterNode), bus}
      , base{bus} {
        if(_shutdown_ignore) {
            log_info("shutdown requests are ignored due to configuration");
        } else {
            if(_shutdown_verify) {
                log_info("shutdown verification is enabled");
            } else {
                log_info("shutdown verification is disabled");
            }
            log_info("shutdown delay is set to ${delay}")
              .arg(EAGINE_ID(delay), _shutdown_timeout.period());
            this->shutdown_requested.connect(
              {this, EAGINE_THIS_MEM_FUNC_C(on_shutdown)});
        }
    }

    auto update() -> bool {
        some_true something_done{};
        something_done(base::update_and_process_all());

        return something_done;
    }

    auto is_shut_down() const noexcept {
        return _do_shutdown && _shutdown_timeout;
    }

private:
    auto provide_endpoint_info() -> endpoint_info final {
        endpoint_info result;
        result.display_name = "router control node";
        result.description = "endpoint monitoring and controlling a router";
        result.is_router_node = true;
        return result;
    }

    timeout _shutdown_timeout{
      cfg_init("msg_bus.router.shutdown.delay", std::chrono::seconds(60))};
    const std::chrono::milliseconds _shutdown_max_age{cfg_init(
      "msg_bus.router.shutdown.max_age",
      std::chrono::milliseconds(2500))};
    const bool _shutdown_ignore{cfg_init("msg_bus.router.keep_running", false)};
    const bool _shutdown_verify{
      cfg_init("msg_bus.router.shutdown.verify", true)};
    bool _do_shutdown{false};

    auto _shutdown_verified(verification_bits v) const noexcept -> bool {
        return v.has_all(
          verification_bit::source_id,
          verification_bit::source_certificate,
          verification_bit::source_private_key,
          verification_bit::message_id);
    }

    void on_shutdown(
      std::chrono::milliseconds age,
      identifier_t source_id,
      verification_bits verified) {
        log_info("received ${age} old shutdown request from ${source}")
          .arg(EAGINE_ID(age), age)
          .arg(EAGINE_ID(source), source_id)
          .arg(EAGINE_ID(verified), verified);

        if(!_shutdown_ignore) {
            if(age <= _shutdown_max_age) {
                if(!_shutdown_verify || _shutdown_verified(verified)) {
                    log_info("request is valid, shutting down");
                    _do_shutdown = true;
                    _shutdown_timeout.reset();
                } else {
                    log_warning("shutdown verification failed");
                }
            } else {
                log_warning("shutdown request is too old");
            }
        } else {
            log_warning("ignoring shutdown request due to configuration");
        }
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
    auto node_connection{local_acceptor->make_connection()};

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

    msgbus::endpoint node_endpoint{EAGINE_ID(RutrNodeEp), ctx};
    node_endpoint.add_certificate_pem(msgbus_router_certificate_pem(ctx));
    node_endpoint.add_connection(std::move(node_connection));
    msgbus::router_node node{node_endpoint};

    auto& wd = ctx.watchdog();
    wd.declare_initialized();

    while(EAGINE_LIKELY(!(interrupted || node.is_shut_down()))) {
        some_true something_done{};
        something_done(router.update(8));
        something_done(node.update());

        if(something_done) {
            ++cycles_work;
            idle_streak = 0;
        } else {
            ++cycles_idle;
            max_idle_streak = math::maximum(max_idle_streak, ++idle_streak);
            std::this_thread::sleep_for(
              std::chrono::milliseconds(math::minimum(idle_streak / 8, 8)));
        }
        wd.notify_alive();
    }

    router.cleanup();
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
