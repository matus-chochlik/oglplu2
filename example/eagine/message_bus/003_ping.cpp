/**
 *  @example eagine/message_bus/003_ping.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/interop/valgrind.hpp>
#include <eagine/main.hpp>
#include <eagine/message_bus/actor.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/timeout.hpp>
#include <eagine/valid_if/positive.hpp>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class ping : public actor<2> {
public:
    using base = actor<2>;
    using base::bus;
    using base::log;

    ping(
      logger& parent,
      connection_setup& conn_setup,
      string_view address,
      valid_if_positive<std::size_t> max)
      : base(
          {EAGINE_ID(ExamplPing), parent},
          this,
          EAGINE_MSG_MAP(PingPong, Pong, ping, pong),
          EAGINE_MSG_MAP(PingPong, Ready, ping, ready))
      , _lmod{running_on_valgrind() ? 1000U : 10000U}
      , _max{extract_or(max, running_on_valgrind() ? 10000U : 100000U)} {
        this->allow_subscriptions();

        conn_setup.setup_connectors(
          *this,
          connection_kind::local_interprocess |
            connection_kind::remote_interprocess,
          address);
    }

    bool pong(stored_message&) {
        if(++_rcvd % _lmod == 0) {
            log().info("received ${count} pongs").arg(EAGINE_ID(count), _rcvd);
        }
        if(_rcvd < _max) {
            _timeout.reset();
        }
        return true;
    }

    bool ready(stored_message&) {
        _ready = true;
        log().info("received pong ready message");
        return true;
    }

    void shutdown() {
        bus().send(EAGINE_MSG_ID(PingPong, Shutdown));
        log().info("sent shutdown message");
    }

    void update() {
        if(_ready && (_sent <= _max * 2) && (_sent < _rcvd + _lmod)) {
            bus().send(EAGINE_MSG_ID(PingPong, Ping));
            if(++_sent % _lmod == 0) {
                log().info("sent ${count} pings").arg(EAGINE_ID(count), _sent);
            }
        } else {
            std::this_thread::yield();
        }
    }

    bool is_done() const noexcept {
        return (_rcvd >= _max) || _timeout;
    }

    auto pings_per_second(std::chrono::duration<float> s) const noexcept {
        return float(_rcvd) / s.count();
    }

private:
    std::size_t _lmod{1};
    std::size_t _sent{0};
    std::size_t _rcvd{0};
    const std::size_t _max{1000000};
    timeout _timeout{std::chrono::seconds(30)};
    bool _ready{false};
};
//------------------------------------------------------------------------------
} // namespace msgbus

int main(main_ctx& ctx) {
    msgbus::router_address address{ctx.log(), ctx.args()};
    msgbus::connection_setup conn_setup(ctx.log());
    conn_setup.default_init(ctx.args());

    valid_if_positive<std::size_t> ping_count{};
    if(auto arg{ctx.args().find("--ping-count")}) {
        arg.next().parse(ping_count, ctx.log().error_stream());
    }

    msgbus::ping ping(ctx.log(), conn_setup, address, ping_count);

    const time_measure run_time;

    while(!ping.is_done()) {
        ping.update();
        ping.process_all();
    }

    const auto elapsed = run_time.seconds();

    ctx.log()
      .info("execution time ${time}, ${pps} pings per second")
      .arg(EAGINE_ID(time), elapsed)
      .arg(EAGINE_ID(pps), ping.pings_per_second(elapsed));

    ping.shutdown();

    return 0;
}
} // namespace eagine

