/// @example eagine/message_bus/003_shutdown.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include "lib_common_pki.hpp"
#include <eagine/main.hpp>
#include <eagine/message_bus.hpp>
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

class shutdown_trigger
  : public main_ctx_object
  , public shutdown_trigger_base {
    using base = shutdown_trigger_base;

public:
    shutdown_trigger(endpoint& bus)
      : main_ctx_object{EAGINE_ID(ShtdwnTrgr), bus}
      , base{bus} {
        subscribed.connect(EAGINE_THIS_MEM_FUNC_REF(on_subscribed));
        unsubscribed.connect(EAGINE_THIS_MEM_FUNC_REF(on_unsubscribed));
        not_subscribed.connect(EAGINE_THIS_MEM_FUNC_REF(on_not_subscribed));
    }

    void on_subscribed(const subscriber_info& info, message_id sub_msg) {
        if(sub_msg == EAGINE_MSG_ID(Shutdown, shutdown)) {
            log_info("target ${id} appeared")
              .arg(EAGINE_ID(id), info.endpoint_id);
            _targets.insert(info.endpoint_id);
            this->bus_node().post_certificate(info.endpoint_id, 0);
        }
    }

    void on_unsubscribed(const subscriber_info& info, message_id sub_msg) {
        if(sub_msg == EAGINE_MSG_ID(Shutdown, shutdown)) {
            log_info("target ${id} disappeared")
              .arg(EAGINE_ID(id), info.endpoint_id);
            _targets.erase(info.endpoint_id);
        }
    }

    void on_not_subscribed(const subscriber_info& info, message_id sub_msg) {
        if(sub_msg == EAGINE_MSG_ID(Shutdown, shutdown)) {
            log_info("target ${id} does not support shutdown")
              .arg(EAGINE_ID(id), info.endpoint_id);
            _targets.erase(info.endpoint_id);
        }
    }

    void shutdown_all() {
        for(auto id : _targets) {
            this->shutdown_one(id);
        }
    }

private:
    std::set<identifier_t> _targets{};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {

    msgbus::endpoint bus{EAGINE_ID(ShutdownEx), ctx};
    bus.add_ca_certificate_pem(ca_certificate_pem(ctx));
    bus.add_certificate_pem(msgbus_endpoint_certificate_pem(ctx));

    msgbus::shutdown_trigger trgr{bus};
    ctx.bus().setup_connectors(trgr);

    timeout wait_done{std::chrono::seconds(30)};

    while(!wait_done) {
        trgr.update();
        if(!trgr.process_all()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    trgr.shutdown_all();
    wait_done.reset();

    while(!wait_done) {
        trgr.update();
        if(!trgr.process_all()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine
