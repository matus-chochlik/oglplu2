/**
 *  @example eagine/message_bus/001_loopback.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main.hpp>
#include <eagine/memory/span_algo.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/message_bus/loopback.hpp>
#include <eagine/message_bus/subscriber.hpp>
#include <iostream>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
struct str_utils_server : subscriber<1> {
    using this_class = str_utils_server;
    using base = subscriber<1>;
    using base::bus;

    str_utils_server(logger& parent, endpoint& ep)
      : base(ep, this, EAGINE_MSG_MAP(StrUtilReq, Reverse, this_class, reverse))
      , _log{EAGINE_ID(Server), parent} {
    }

    bool reverse(stored_message& msg) {
        auto str = as_chars(cover(msg.data));
        _log.trace("received request: ${content}").arg(EAGINE_ID(content), str);
        memory::reverse(str);
        bus().send(EAGINE_MSG_ID(StrUtilRes, Reverse), as_bytes(str));
        return true;
    }

private:
    logger _log{};
};
//------------------------------------------------------------------------------
struct str_utils_client : subscriber<1> {
    using this_class = str_utils_client;
    using base = subscriber<1>;
    using base::bus;

    str_utils_client(logger& parent, endpoint& ep)
      : base(ep, this, EAGINE_MSG_MAP(StrUtilRes, Reverse, this_class, print))
      , _log{EAGINE_ID(Client), parent} {
    }

    void call_reverse(string_view str) {
        ++_remaining;
        bus().send(EAGINE_MSG_ID(StrUtilReq, Reverse), as_bytes(str));
    }

    bool print(stored_message& msg) {
        _log.info("received response: ${content}")
          .arg(EAGINE_ID(content), as_chars(view(msg.data)));
        --_remaining;
        return true;
    }

    bool is_done() const {
        return _remaining <= 0;
    }

private:
    logger _log{};
    int _remaining{0};
};
//------------------------------------------------------------------------------
} // namespace msgbus

int main(main_ctx& ctx) {

    msgbus::endpoint bus(ctx.log());
    bus.set_id(EAGINE_ID(BusExample));
    bus.add_connection(std::make_unique<msgbus::loopback_connection>());

    msgbus::str_utils_server server(ctx.log(), bus);
    msgbus::str_utils_client client(ctx.log(), bus);

    client.call_reverse("foo");
    client.call_reverse("bar");
    client.call_reverse("baz");
    client.call_reverse("qux");

    while(!client.is_done()) {
        bus.update();
        server.process_one();
        client.process_one();
    }

    return 0;
}

} // namespace eagine

