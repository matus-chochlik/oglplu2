/**
 *  @example eagine/message_bus/003_pong.cpp
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
class pong : public actor<2> {
public:
    using base = actor<2>;
    using base::bus;

    pong(logger& parent, connection_setup& conn_setup)
      : base(
          {EAGINE_ID(ExamplPong), parent},
          this,
          EAGINE_MSG_MAP(PingPong, Ping, pong, ping),
          EAGINE_MSG_MAP(PingPong, Shutdown, pong, shutdown))
      , _lmod{running_on_valgrind() ? 1000U : 10000U} {
        conn_setup.setup_connectors(
          *this,
          connection_kind::local_interprocess |
            connection_kind::remote_interprocess);
    }

    bool ping(stored_message& msg_in) {
        bus().respond_to(msg_in, EAGINE_MSG_ID(PingPong, Pong));
        if(++_sent % _lmod == 0) {
            log().info("sent ${count} pongs").arg(EAGINE_ID(count), _sent);
        }
        return true;
    }

    bool shutdown(stored_message&) {
        _done = true;
        log().info("received shutdown message");
        return true;
    }

    bool is_done() const noexcept {
        return _done || _timeout;
    }

private:
    std::size_t _lmod{1};
    std::size_t _sent{0};
    timeout _timeout{std::chrono::seconds(30)};
    bool _done{false};
};
//------------------------------------------------------------------------------
} // namespace msgbus

int main(main_ctx& ctx) {
    msgbus::connection_setup conn_setup(ctx.log());
    conn_setup.default_init(ctx.args());

    msgbus::pong pong(ctx.log(), conn_setup);

    while(!pong.is_done()) {
        pong.process_one();
    }

    return 0;
}
} // namespace eagine

