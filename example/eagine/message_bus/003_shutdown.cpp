/**
 *  @example eagine/message_bus/003_shutdown.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "lib_common_pki.hpp"
#include <eagine/main.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/discovery.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/timeout.hpp>
#include <set>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
using shutdown_trigger_base =
  service_composition<subscriber_discovery<shutdown_invoker<>>>;

class shutdown_trigger : public shutdown_trigger_base {
    using base = shutdown_trigger_base;

public:
    shutdown_trigger(endpoint& bus)
      : base{bus}
      , _log{EAGINE_ID(ShtdwnTrgr), bus.log()} {
    }

    void on_subscribed(identifier_t id, const message_id_tuple& sub_msg) final {
        if(EAGINE_MSG_ID(Shutdown, shutdown).matches(sub_msg)) {
            _log.info("target ${id} appeared").arg(EAGINE_ID(id), id);
            _targets.insert(id);
        }
    }

    void on_unsubscribed(
      identifier_t id, const message_id_tuple& sub_msg) final {
        if(EAGINE_MSG_ID(Shutdown, shutdown).matches(sub_msg)) {
            _log.info("target ${id} disappeared").arg(EAGINE_ID(id), id);
            _targets.erase(id);
        }
    }

    void shutdown_all() {
        for(auto id : _targets) {
            this->shutdown_one(id);
        }
    }

private:
    logger _log{};
    std::set<identifier_t> _targets{};
};
//------------------------------------------------------------------------------
} // namespace msgbus

int main(main_ctx& ctx) {

    msgbus::router_address address{ctx.log(), ctx.args()};
    msgbus::connection_setup conn_setup(ctx.log(), ctx.args());

    msgbus::endpoint bus{logger{EAGINE_ID(ShutdownEx), ctx.log()}};
    bus.add_ca_certificate_pem(ca_certificate_pem(ctx));
    bus.add_certificate_pem(msgbus_endpoint_certificate_pem(ctx));

    msgbus::shutdown_trigger trgr{bus};
    conn_setup.setup_connectors(trgr, address);

    timeout wait_done{std::chrono::seconds(10)};

    while(!wait_done) {
        trgr.update();
        if(!trgr.process_all()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    trgr.shutdown_all();
    wait_done.reset();

    while(!wait_done) {
        trgr.update();
        if(!trgr.process_all()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine

