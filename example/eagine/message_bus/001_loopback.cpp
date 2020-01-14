/**
 *  @example eagine/message_bus/001_loopback.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/span_algo.hpp>
#include <eagine/msg_bus/endpoint.hpp>
#include <eagine/msg_bus/loopback.hpp>
#include <eagine/msg_bus/subscriber.hpp>
#include <iostream>

namespace eagine {
//------------------------------------------------------------------------------
struct str_utils_server : message_bus_subscriber<1> {
    using this_class = str_utils_server;
    using base = message_bus_subscriber<1>;
    using base::endpoint;

    str_utils_server(message_bus_endpoint& bus)
      : base(
          bus, this, EAGINE_MSG_MAP(StrUtilReq, Reverse, this_class, reverse)) {
    }

    bool reverse(stored_message& msg) {
        auto str = as_chars(cover(msg.data));
        memory::reverse(str);
        endpoint().send(EAGINE_MSG_ID(StrUtilRes, Reverse), as_bytes(str));
        return true;
    }
};
//------------------------------------------------------------------------------
struct str_utils_client : message_bus_subscriber<1> {
    using this_class = str_utils_client;
    using base = message_bus_subscriber<1>;
    using base::endpoint;

    str_utils_client(message_bus_endpoint& bus)
      : base(
          bus, this, EAGINE_MSG_MAP(StrUtilRes, Reverse, this_class, print)) {
    }

    void call_reverse(string_view str) {
        ++_remaining;
        endpoint().send(EAGINE_MSG_ID(StrUtilReq, Reverse), as_bytes(str));
    }

    bool print(stored_message& msg) {
        std::cout << view(msg.data) << std::endl;
        --_remaining;
        return true;
    }

    bool is_done() const {
        return _remaining <= 0;
    }

private:
    int _remaining{0};
};
//------------------------------------------------------------------------------
} // namespace eagine

int main() {
    using namespace eagine;

    message_bus_endpoint bus;
    bus.add_connection(std::make_unique<message_bus_loopback_connection>());

    str_utils_server server(bus);
    str_utils_client client(bus);

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
