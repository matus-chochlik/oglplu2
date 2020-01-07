/**
 *  @example eagine/message_bus/fibonacci.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/span_algo.hpp>
#include <eagine/msg_bus/acceptor.hpp>
#include <eagine/msg_bus/direct.hpp>
#include <eagine/msg_bus/endpoint.hpp>
#include <eagine/msg_bus/router.hpp>
#include <eagine/msg_bus/subscriber.hpp>
#include <eagine/serialize/block_sink.hpp>
#include <eagine/serialize/block_source.hpp>
#include <eagine/serialize/fast_backend.hpp>
#include <eagine/serialize/read.hpp>
#include <eagine/serialize/write.hpp>
#include <iostream>
#include <queue>
#include <set>
#include <thread>

namespace eagine {
//------------------------------------------------------------------------------
class fibonacci_server : public message_bus_subscriber<3> {
public:
    using this_class = fibonacci_server;
    using base = message_bus_subscriber<3>;
    using base::endpoint;

    fibonacci_server(message_bus_endpoint& bus)
      : base(
          bus,
          this,
          EAGINE_MSG_MAP(Fibonacci, FindServer, this_class, is_ready),
          EAGINE_MSG_MAP(Fibonacci, Calculate, this_class, calculate),
          EAGINE_MSG_MAP(Fibonacci, Shutdown, this_class, shutdown)) {
    }

    bool shutdown(stored_message&) {
        _done = true;
        return true;
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

    bool is_done() const noexcept {
        return _done;
    }

private:
    bool _done{false};
};
//------------------------------------------------------------------------------
class fibonacci_client : public message_bus_subscriber<2> {
public:
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

    void shutdown() {
        endpoint().send(EAGINE_MSG_ID(Fibonacci, Shutdown));
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

    std::size_t thread_count{4};

    auto acceptor = std::make_unique<message_bus_direct_acceptor>();

    message_bus_endpoint client_endpoint;
    client_endpoint.add_connection(acceptor->make_connection());
    client_endpoint.send_not_a_router();
    fibonacci_client client(client_endpoint);

    std::vector<std::thread> workers;
    workers.reserve(thread_count);

    for(std::size_t i = 0; i < thread_count; ++i) {
        workers.emplace_back(
          [connection{acceptor->make_connection()}]() mutable {
              message_bus_endpoint server_endpoint;
              server_endpoint.add_connection(std::move(connection));
              server_endpoint.send_not_a_router();
              fibonacci_server server(server_endpoint);

              while(!server.is_done()) {
                  server_endpoint.update();
                  server.process_one();
              }
          });
    }

    message_bus_router router;
    router.add_acceptor(std::move(acceptor));

    for(std::int64_t i = 1; i <= 45; ++i) {
        client.enqueue(i);
    }

    while(!client.is_done()) {
        router.update();
        client_endpoint.update();
        client.update();
        client.process_one();
    }

    client.shutdown();
    router.update();

    for(auto& worker : workers) {
        worker.join();
    }

    return 0;
}
