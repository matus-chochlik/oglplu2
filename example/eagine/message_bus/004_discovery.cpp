/**
 *  @example eagine/message_bus/004_discovery.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/discovery.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/signal_switch.hpp>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
using subscription_logger_base =
  service_composition<subscriber_discovery<shutdown_target<>>>;

class subscription_logger : public subscription_logger_base {
    using base = subscription_logger_base;

public:
    subscription_logger(endpoint& bus)
      : base{bus}
      , _log{EAGINE_ID(SubscrLog), bus.log()} {
    }

    void on_subscribed(
      identifier_t subscriber_id, const message_id_tuple& sub_msg) final {
        _log.info("endpoint ${subscrbr} subscribed to ${message}")
          .arg(EAGINE_ID(subscrbr), subscriber_id)
          .arg(EAGINE_ID(message), sub_msg);
    }

    void on_unsubscribed(
      identifier_t subscriber_id, const message_id_tuple& sub_msg) final {
        _log.info("endpoint ${subscrbr} unsubscribed from ${message}")
          .arg(EAGINE_ID(subscrbr), subscriber_id)
          .arg(EAGINE_ID(message), sub_msg);
    }

    void on_shutdown(
      std::chrono::milliseconds age,
      identifier_t subscriber_id,
      verification_bits verified) final {
        _log.info("received ${age} old shutdown request from ${subscrbr}")
          .arg(EAGINE_ID(age), age)
          .arg(EAGINE_ID(subscrbr), subscriber_id)
          .arg(EAGINE_ID(verified), verified);

        // TODO: verification
        if(age < std::chrono::seconds(2)) {
            _done = true;
        }
    }

    bool is_done() const noexcept {
        return _done;
    }

private:
    logger _log{};
    bool _done{false};
};
//------------------------------------------------------------------------------
} // namespace msgbus

int main(main_ctx& ctx) {

    signal_switch interrupted;

    msgbus::router_address address{ctx.log(), ctx.args()};
    msgbus::connection_setup conn_setup(ctx.log(), ctx.args());

    msgbus::endpoint bus{logger{EAGINE_ID(DiscoverEx), ctx.log()}};
    msgbus::subscription_logger sub_log{bus};

    conn_setup.setup_connectors(sub_log, address);

    while(!(interrupted || sub_log.is_done())) {
        sub_log.update();
        if(!sub_log.process_all()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        }
    }

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine

