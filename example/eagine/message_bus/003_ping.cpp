/**
 *  @example eagine/message_bus/003_ping.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/interop/valgrind.hpp>
#include <eagine/logging/root_logger.hpp>
#include <eagine/message_bus/actor.hpp>
#include <eagine/message_bus/conn_setup.hpp>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class ping : public actor<1> {
public:
    using base = actor<1>;
    using base::bus;

    ping(logger& parent, connection_setup& conn_setup)
      : base(this, EAGINE_MSG_MAP(PingPong, Pong, ping, pong))
      , _log{EAGINE_ID(ExamplPing), parent}
      , _lmod{running_on_valgrind() ? 1000U : 10000U}
      , _max{running_on_valgrind() ? 100000U : 1000000U} {
        conn_setup.setup_connectors(*this, connection_kind::local_interprocess);
    }

    bool pong(stored_message&) {
        if(++_rcvd % _lmod == 0) {
            _log.info("received ${count} pongs").arg(EAGINE_ID(count), _rcvd);
        }
        return true;
    }

    void shutdown() {
        bus().send(EAGINE_MSG_ID(PingPong, Shutdown));
        _log.info("sent shutdown message");
    }

    void update() {
        if((_sent < _max) || (_rcvd > 0)) {
            bus().send(EAGINE_MSG_ID(PingPong, Ping));
            if(++_sent % _lmod == 0) {
                _log.info("sent ${count} pings").arg(EAGINE_ID(count), _sent);
            }
        }
    }

    bool is_done() const noexcept {
        return (_rcvd >= _max) || (_sent >= _max * 2);
    }

private:
    logger _log{};
    std::size_t _lmod{1};
    std::size_t _sent{0};
    std::size_t _rcvd{0};
    const std::size_t _max{1000000};
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

int main(int argc, const char** argv) {
    using namespace eagine;

    program_args args(argc, argv);
    root_logger log(args);

    msgbus::connection_setup conn_setup(log);
    conn_setup.default_init(args);

    msgbus::ping ping(log, conn_setup);

    while(!ping.is_done()) {
        ping.process_one();
        ping.update();
    }

    ping.shutdown();
    ping.update();

    return 0;
}
