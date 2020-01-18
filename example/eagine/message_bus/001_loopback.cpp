/**
 *  @example eagine/message_bus/001_loopback.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
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

    str_utils_server(endpoint& ep)
      : base(
          ep, this, EAGINE_MSG_MAP(StrUtilReq, Reverse, this_class, reverse)) {
    }

    bool reverse(stored_message& msg) {
        auto str = as_chars(cover(msg.data));
        memory::reverse(str);
        bus().send(EAGINE_MSG_ID(StrUtilRes, Reverse), as_bytes(str));
        return true;
    }
};
//------------------------------------------------------------------------------
struct str_utils_client : subscriber<1> {
    using this_class = str_utils_client;
    using base = subscriber<1>;
    using base::bus;

    str_utils_client(endpoint& ep)
      : base(ep, this, EAGINE_MSG_MAP(StrUtilRes, Reverse, this_class, print)) {
    }

    void call_reverse(string_view str) {
        ++_remaining;
        bus().send(EAGINE_MSG_ID(StrUtilReq, Reverse), as_bytes(str));
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
} // namespace msgbus
} // namespace eagine

int main() {
    using namespace eagine;

    msgbus::endpoint bus;
    bus.set_id(EAGINE_ID(BusExample));
    bus.add_connection(std::make_unique<msgbus::loopback_connection>());

    msgbus::str_utils_server server(bus);
    msgbus::str_utils_client client(bus);

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
