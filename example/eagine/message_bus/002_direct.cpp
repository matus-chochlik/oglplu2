/**
 *  @example eagine/message_bus/002_direct.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/logging/root_logger.hpp>
#include <eagine/memory/span_algo.hpp>
#include <eagine/message_bus/acceptor.hpp>
#include <eagine/message_bus/direct.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/message_bus/router.hpp>
#include <eagine/message_bus/subscriber.hpp>
#include <iostream>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
struct str_utils_server : subscriber<2> {
    using this_class = str_utils_server;
    using base = subscriber<2>;
    using base::bus;

    str_utils_server(logger& parent, endpoint& ep)
      : base(
          ep,
          this,
          EAGINE_MSG_MAP(StrUtilReq, UpperCase, this_class, uppercase),
          EAGINE_MSG_MAP(StrUtilReq, Reverse, this_class, reverse))
      , _log{EAGINE_ID(Server), parent} {
    }

    bool reverse(stored_message& msg) {
        auto str = as_chars(cover(msg.data));
        _log.trace("received request: ${content}").arg(EAGINE_ID(content), str);
        memory::reverse(str);
        bus().send(EAGINE_MSG_ID(StrUtilRes, Reverse), as_bytes(str));
        return true;
    }

    bool uppercase(stored_message& msg) {
        auto str = as_chars(cover(msg.data));
        transform(str, [](char x) { return char(std::toupper(x)); });
        bus().send(EAGINE_MSG_ID(StrUtilRes, UpperCase), as_bytes(str));
        return true;
    }

private:
    logger _log{};
};
//------------------------------------------------------------------------------
struct str_utils_client : subscriber<2> {
    using this_class = str_utils_client;
    using base = subscriber<2>;
    using base::bus;

    str_utils_client(logger& parent, endpoint& ep)
      : base(
          ep,
          this,
          EAGINE_MSG_MAP(StrUtilRes, UpperCase, this_class, print),
          EAGINE_MSG_MAP(StrUtilRes, Reverse, this_class, print))
      , _log{EAGINE_ID(Client), parent} {
    }

    void call_reverse(string_view str) {
        ++_remaining;
        bus().send(EAGINE_MSG_ID(StrUtilReq, Reverse), as_bytes(str));
    }

    void call_uppercase(string_view str) {
        ++_remaining;
        bus().send(EAGINE_MSG_ID(StrUtilReq, UpperCase), as_bytes(str));
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
} // namespace eagine

int main(int argc, const char** argv) {
    using namespace eagine;

    program_args args(argc, argv);
    root_logger log(args);

    auto acceptor = std::make_unique<msgbus::direct_acceptor>(log);

    msgbus::endpoint server_endpoint;
    msgbus::endpoint client_endpoint;

    server_endpoint.add_connection(acceptor->make_connection());
    client_endpoint.add_connection(acceptor->make_connection());

    msgbus::router router(log);
    router.add_acceptor(std::move(acceptor));

    msgbus::str_utils_server server(log, server_endpoint);
    msgbus::str_utils_client client(log, client_endpoint);

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
