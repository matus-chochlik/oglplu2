/**
 *  @example eagine/message_bus/003_pong.cpp
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
class pong : public actor<2> {
public:
    using base = actor<2>;
    using base::bus;

    pong(connection_setup& conn_setup)
      : base(
          this,
          EAGINE_MSG_MAP(PingPong, Ping, pong, ping),
          EAGINE_MSG_MAP(PingPong, Shutdown, pong, shutdown)) {
        conn_setup.setup_connectors(*this, connection_kind::local_interprocess);
    }

    bool ping(stored_message& msg_in) {
        bus().respond_to(msg_in, EAGINE_MSG_ID(PingPong, Pong));
        return true;
    }

    bool shutdown(stored_message&) {
        _done = true;
        return true;
    }

    bool is_done() const noexcept {
        return _done;
    }

private:
    bool _done{false};
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

    msgbus::pong pong(conn_setup);

    while(!pong.is_done()) {
        pong.process_one();
    }

    return 0;
}
