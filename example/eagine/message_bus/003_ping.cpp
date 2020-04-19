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
#include <eagine/timeout.hpp>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class ping : public actor<1> {
public:
    using base = actor<1>;
    using base::bus;
    using base::log;

    ping(logger& parent, connection_setup& conn_setup)
      : base(
          {EAGINE_ID(ExamplPing), parent},
          this,
          EAGINE_MSG_MAP(PingPong, Pong, ping, pong))
      , _lmod{running_on_valgrind() ? 1000U : 10000U}
      , _max{running_on_valgrind() ? 10000U : 100000U} {
        conn_setup.setup_connectors(
          *this,
          connection_kind::local_interprocess |
            connection_kind::remote_interprocess);
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

    void shutdown() {
        bus().send(EAGINE_MSG_ID(PingPong, Shutdown));
        log().info("sent shutdown message");
    }

    void update() {
        if(_sent <= _max) {
            bus().send(EAGINE_MSG_ID(PingPong, Ping));
            if(++_sent % _lmod == 0) {
                log().info("sent ${count} pings").arg(EAGINE_ID(count), _sent);
            }
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
};
//------------------------------------------------------------------------------
} // namespace msgbus

int main(main_ctx& ctx) {
    msgbus::connection_setup conn_setup(ctx.log());
    conn_setup.default_init(ctx.args());

    msgbus::ping ping(ctx.log(), conn_setup);

    const time_measure run_time;

    while(!ping.is_done()) {
        for(int i = 0; i < 10; ++i) {
            ping.update();
        }
        ping.process_all();
    }

    const auto elapsed = run_time.seconds();

    ctx.log()
      .info("execution time ${time}, ${pps} per second")
      .arg(EAGINE_ID(time), elapsed)
      .arg(EAGINE_ID(pps), ping.pings_per_second(elapsed));

    ping.shutdown();
    ping.update();

    return 0;
}
} // namespace eagine

