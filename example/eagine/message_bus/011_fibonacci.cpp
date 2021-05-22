/// @example eagine/message_bus/011_fibonacci.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/interop/valgrind.hpp>
#include <eagine/main.hpp>
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
namespace msgbus {
//------------------------------------------------------------------------------
struct fibonacci_server : static_subscriber<2> {
    using this_class = fibonacci_server;
    using base = static_subscriber<2>;
    using base::bus_node;

    fibonacci_server(endpoint& ep)
      : base(
          ep,
          this,
          EAGINE_MSG_MAP(Fibonacci, FindServer, this_class, is_ready),
          EAGINE_MSG_MAP(Fibonacci, Calculate, this_class, calculate)) {}

    auto is_ready(const message_context&, stored_message& msg_in) -> bool {
        bus_node().respond_to(msg_in, EAGINE_MSG_ID(Fibonacci, IsReady));
        return true;
    }

    static auto fib(std::int64_t arg) noexcept -> std::int64_t {
        return arg <= 2 ? 1 : fib(arg - 2) + fib(arg - 1);
    }

    auto calculate(const message_context&, stored_message& msg_in) -> bool {
        std::int64_t arg{0};
        std::int64_t result{0};
        auto tup = std::tie(arg, result);
        // deserialize
        block_data_source source(msg_in.content());
        fast_deserializer_backend read_backend(source);
        deserialize(arg, read_backend);
        // call
        result = fib(arg);
        EAGINE_MAYBE_UNUSED(result);
        // serialize
        std::array<byte, 64> buffer{};
        block_data_sink sink(cover(buffer));
        fast_serializer_backend write_backend(sink);
        serialize(tup, write_backend);
        // send
        message_view msg_out{sink.done()};
        msg_out.set_serializer_id(write_backend.type_id());
        bus_node().respond_to(
          msg_in, EAGINE_MSG_ID(Fibonacci, Result), msg_out);
        return true;
    }
};
//------------------------------------------------------------------------------
struct fibonacci_client : static_subscriber<2> {
    using this_class = fibonacci_client;
    using base = static_subscriber<2>;
    using base::bus_node;

    fibonacci_client(endpoint& ep)
      : base(
          ep,
          this,
          EAGINE_MSG_MAP(Fibonacci, IsReady, this_class, dispatch),
          EAGINE_MSG_MAP(Fibonacci, Result, this_class, print)) {}

    void enqueue(std::int64_t arg) {
        _remaining.push(arg);
    }

    void update() {
        if(!_remaining.empty()) {
            bus_node().broadcast(EAGINE_MSG_ID(Fibonacci, FindServer));
        }
    }

    auto dispatch(const message_context&, stored_message& msg_in) -> bool {
        if(!_remaining.empty()) {
            auto arg = _remaining.front();
            _pending.insert(arg);
            _remaining.pop();
            // serialize
            std::array<byte, 32> buffer{};
            block_data_sink sink(cover(buffer));
            fast_serializer_backend write_backend(sink);
            serialize(arg, write_backend);
            //
            message_view msg_out{sink.done()};
            msg_out.set_serializer_id(write_backend.type_id());
            bus_node().respond_to(
              msg_in, EAGINE_MSG_ID(Fibonacci, Calculate), msg_out);
        }
        return true;
    }

    auto print(const message_context&, stored_message& msg_in) -> bool {
        std::int64_t arg{0};
        std::int64_t result{0};
        auto tup = std::tie(arg, result);
        // deserialize
        block_data_source source(msg_in.content());
        fast_deserializer_backend read_backend(source);
        deserialize(tup, read_backend);
        // print
        std::cout << "fib(" << arg << ") = " << result << std::endl;
        // remove
        _pending.erase(arg);
        return true;
    }

    auto is_done() const {
        return _remaining.empty() && _pending.empty();
    }

private:
    std::queue<std::int64_t> _remaining{};
    std::set<std::int64_t> _pending{};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {

    auto acceptor = std::make_unique<msgbus::direct_acceptor>(ctx);

    msgbus::endpoint server_endpoint(EAGINE_ID(Server), ctx);
    msgbus::endpoint client_endpoint(EAGINE_ID(Client), ctx);

    server_endpoint.add_connection(acceptor->make_connection());
    client_endpoint.add_connection(acceptor->make_connection());

    msgbus::router router(ctx);
    router.add_acceptor(std::move(acceptor));

    msgbus::fibonacci_server server(server_endpoint);
    msgbus::fibonacci_client client(client_endpoint);

    const std::int64_t n = running_on_valgrind() ? 36 : 45;

    for(std::int64_t i = 1; i <= n; ++i) {
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
} // namespace eagine
