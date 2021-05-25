/// @example eagine/message_bus/001_loopback.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/main.hpp>
#include <eagine/memory/span_algo.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/message_bus/loopback.hpp>
#include <eagine/message_bus/subscriber.hpp>
#include <iostream>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
struct str_utils_server
  : main_ctx_object
  , static_subscriber<1> {
    using this_class = str_utils_server;
    using base = static_subscriber<1>;
    using base::bus_node;

    str_utils_server(endpoint& ep)
      : main_ctx_object{EAGINE_ID(Server), ep}
      , base(
          ep,
          this,
          EAGINE_MSG_MAP(StrUtilReq, Reverse, this_class, reverse)) {}

    auto reverse(const message_context&, stored_message& msg) -> bool {
        auto str = msg.text_content();
        log_trace("received request: ${content}").arg(EAGINE_ID(content), str);
        memory::reverse(str);
        bus_node().post(EAGINE_MSG_ID(StrUtilRes, Reverse), as_bytes(str));
        return true;
    }
};
//------------------------------------------------------------------------------
struct str_utils_client
  : main_ctx_object
  , static_subscriber<1> {
    using this_class = str_utils_client;
    using base = static_subscriber<1>;
    using base::bus_node;

    str_utils_client(endpoint& ep)
      : main_ctx_object{EAGINE_ID(Client), ep}
      , base{ep, this, EAGINE_MSG_MAP(StrUtilRes, Reverse, this_class, print)} {
    }

    void call_reverse(string_view str) {
        ++_remaining;
        bus_node().post(EAGINE_MSG_ID(StrUtilReq, Reverse), as_bytes(str));
    }

    auto print(const message_context&, stored_message& msg) -> bool {
        log_info("received response: ${content}")
          .arg(EAGINE_ID(content), msg.text_content());
        --_remaining;
        return true;
    }

    auto is_done() const -> bool {
        return _remaining <= 0;
    }

private:
    int _remaining{0};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {

    msgbus::endpoint bus{EAGINE_ID(Loopback), ctx};
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

} // namespace eagine
