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

    ping(connection_setup& conn_setup)
      : base(this, EAGINE_MSG_MAP(PingPong, Pong, ping, pong)) {
        conn_setup.setup_connectors(*this, connection_kind::local_interprocess);
    }

    bool pong(stored_message&) {
        ++_rcvd;
        return true;
    }

    void shutdown() {
        bus().send(EAGINE_MSG_ID(PingPong, Shutdown));
    }

    void update() {
        if(_sent < _max) {
            bus().send(EAGINE_MSG_ID(PingPong, Ping));
            ++_sent;
        }
    }

    bool is_done() const noexcept {
        return _rcvd >= _max;
    }

private:
    std::size_t _sent{0};
    std::size_t _rcvd{0};
    const std::size_t _max{10};
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

    msgbus::ping ping(conn_setup);

    while(!ping.is_done()) {
        ping.process_one();
        ping.update();
    }

    ping.shutdown();
    ping.update();

    return 0;
}
