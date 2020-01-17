/**
 *  @example eagine/message_bus/002_direct.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/span_algo.hpp>
#include <eagine/message_bus/acceptor.hpp>
#include <eagine/message_bus/direct.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/message_bus/router.hpp>
#include <eagine/message_bus/subscriber.hpp>
#include <iostream>

namespace eagine {
//------------------------------------------------------------------------------
struct str_utils_server : message_bus_subscriber<2> {
    using this_class = str_utils_server;
    using base = message_bus_subscriber<2>;
    using base::endpoint;

    str_utils_server(message_bus_endpoint& bus)
      : base(
          bus,
          this,
          EAGINE_MSG_MAP(StrUtilReq, UpperCase, this_class, uppercase),
          EAGINE_MSG_MAP(StrUtilReq, Reverse, this_class, reverse)) {
    }

    bool reverse(stored_message& msg) {
        auto str = as_chars(cover(msg.data));
        memory::reverse(str);
        endpoint().send(EAGINE_MSG_ID(StrUtilRes, Reverse), as_bytes(str));
        return true;
    }

    bool uppercase(stored_message& msg) {
        auto str = as_chars(cover(msg.data));
        transform(str, [](char x) { return char(std::toupper(x)); });
        endpoint().send(EAGINE_MSG_ID(StrUtilRes, UpperCase), as_bytes(str));
        return true;
    }
};
//------------------------------------------------------------------------------
struct str_utils_client : message_bus_subscriber<2> {
    using this_class = str_utils_client;
    using base = message_bus_subscriber<2>;
    using base::endpoint;

    str_utils_client(message_bus_endpoint& bus)
      : base(
          bus,
          this,
          EAGINE_MSG_MAP(StrUtilRes, UpperCase, this_class, print),
          EAGINE_MSG_MAP(StrUtilRes, Reverse, this_class, print)) {
    }

    void call_reverse(string_view str) {
        ++_remaining;
        endpoint().send(EAGINE_MSG_ID(StrUtilReq, Reverse), as_bytes(str));
    }

    void call_uppercase(string_view str) {
        ++_remaining;
        endpoint().send(EAGINE_MSG_ID(StrUtilReq, UpperCase), as_bytes(str));
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

    auto acceptor = std::make_unique<message_bus_direct_acceptor>();

    message_bus_endpoint server_endpoint;
    message_bus_endpoint client_endpoint;

    server_endpoint.add_connection(acceptor->make_connection());
    client_endpoint.add_connection(acceptor->make_connection());

    message_bus_router router;
    router.add_acceptor(std::move(acceptor));

    str_utils_server server(server_endpoint);
    str_utils_client client(client_endpoint);

    client.call_reverse("foo");
    client.call_reverse("bar");
    client.call_reverse("baz");
    client.call_reverse("qux");

    client.call_uppercase("foo");
    client.call_uppercase("bar");
    client.call_uppercase("baz");
    client.call_uppercase("qux");

    while(!client.is_done()) {
        router.update();
        server_endpoint.update();
        client_endpoint.update();
        server.process_one();
        client.process_one();
    }

    return 0;
}
