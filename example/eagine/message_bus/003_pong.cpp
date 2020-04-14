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

    pong(logger& parent, connection_setup& conn_setup)
      : base(
          this,
          EAGINE_MSG_MAP(PingPong, Ping, pong, ping),
          EAGINE_MSG_MAP(PingPong, Shutdown, pong, shutdown))
      , _log{EAGINE_ID(ExamplPong), parent}
      , _lmod{running_on_valgrind() ? 1000U : 10000U} {
        conn_setup.setup_connectors(*this, connection_kind::local_interprocess);
    }

    bool ping(stored_message& msg_in) {
        bus().respond_to(msg_in, EAGINE_MSG_ID(PingPong, Pong));
        if(++_sent % _lmod == 0) {
            _log.info("sent ${count} pongs").arg(EAGINE_ID(count), _sent);
        }
        return true;
    }

    bool shutdown(stored_message&) {
        _done = true;
        _log.info("received shutdown message");
        return true;
    }

    bool is_done() const noexcept {
        return _done;
    }

private:
    logger _log{};
    std::size_t _lmod{1};
    std::size_t _sent{0};
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

    msgbus::pong pong(log, conn_setup);

    while(!pong.is_done()) {
        pong.process_one();
    }

    return 0;
}
