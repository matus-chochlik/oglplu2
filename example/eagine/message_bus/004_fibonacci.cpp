/**
 *  @example eagine/message_bus/004_fibonacci.cpp
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
#include <eagine/serialize/block_sink.hpp>
#include <eagine/serialize/block_source.hpp>
#include <eagine/serialize/fast_backend.hpp>
#include <eagine/serialize/read.hpp>
#include <eagine/serialize/write.hpp>
#include <iostream>
#include <queue>
#include <set>

namespace eagine {
//------------------------------------------------------------------------------
struct fibonacci_server : message_bus_subscriber<2> {
    using this_class = fibonacci_server;
    using base = message_bus_subscriber<2>;
    using base::endpoint;

    fibonacci_server(message_bus_endpoint& bus)
      : base(
          bus,
          this,
          EAGINE_MSG_MAP(Fibonacci, FindServer, this_class, is_ready),
          EAGINE_MSG_MAP(Fibonacci, Calculate, this_class, calculate)) {
    }

    bool is_ready(stored_message& msg) {
        endpoint().respond_to(msg, EAGINE_MSG_ID(Fibonacci, IsReady));
        return true;
    }

    static std::int64_t fib(std::int64_t arg) noexcept {
        return arg <= 2 ? 1 : fib(arg - 2) + fib(arg - 1);
    }

    bool calculate(stored_message& msg) {
        std::int64_t arg{0};
        std::int64_t result{0};
        auto tup = std::tie(arg, result);
        // deserialize
        block_data_source source(msg.data);
        fast_deserializer_backend read_backend(source);
        deserialize(arg, read_backend);
        // call
        result = fib(arg);
        // serialize
        std::array<byte, 64> buffer{};
        block_data_sink sink(cover(buffer));
        fast_serializer_backend write_backend(sink);
        serialize(tup, write_backend);
        // send
        endpoint().respond_to(
          msg, EAGINE_MSG_ID(Fibonacci, Result), {sink.done()});
        return true;
    }
};
//------------------------------------------------------------------------------
struct fibonacci_client : message_bus_subscriber<2> {
    using this_class = fibonacci_client;
    using base = message_bus_subscriber<2>;
    using base::endpoint;

    fibonacci_client(message_bus_endpoint& bus)
      : base(
          bus,
          this,
          EAGINE_MSG_MAP(Fibonacci, IsReady, this_class, dispatch),
          EAGINE_MSG_MAP(Fibonacci, Result, this_class, print)) {
    }

    void enqueue(std::int64_t arg) {
        _remaining.push(arg);
    }

    void update() {
        if(!_remaining.empty()) {
            endpoint().send(EAGINE_MSG_ID(Fibonacci, FindServer));
        }
    }

    bool dispatch(stored_message& msg) {
        if(!_remaining.empty()) {
            auto arg = _remaining.front();
            _pending.insert(arg);
            _remaining.pop();
            // serialize
            std::array<byte, 32> buffer{};
            block_data_sink sink(cover(buffer));
            fast_serializer_backend write_backend(sink);
            serialize(arg, write_backend);
            endpoint().respond_to(
              msg, EAGINE_MSG_ID(Fibonacci, Calculate), {sink.done()});
        }
        return true;
    }

    bool print(stored_message& msg) {
        std::int64_t arg{0};
        std::int64_t result{0};
        auto tup = std::tie(arg, result);
        // deserialize
        block_data_source source(msg.data);
        fast_deserializer_backend read_backend(source);
        deserialize(tup, read_backend);
        // print
        std::cout << "fib(" << arg << ") = " << result << std::endl;
        // remove
        _pending.erase(arg);
        return true;
    }

    bool is_done() const {
        return _remaining.empty() && _pending.empty();
    }

private:
    std::queue<std::int64_t> _remaining{};
    std::set<std::int64_t> _pending{};
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

    fibonacci_server server(server_endpoint);
    fibonacci_client client(client_endpoint);

    for(std::int64_t i = 1; i <= 45; ++i) {
        client.enqueue(i);
    }

    while(!client.is_done()) {
        router.update();
        client_endpoint.update();
        server_endpoint.update();
        client.update();
        client.process_one();
        server.process_one();
    }

    return 0;
}
