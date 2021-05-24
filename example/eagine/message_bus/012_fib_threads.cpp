/// @example eagine/message_bus/012_fib_threads.cpp
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
#include <eagine/message_bus/actor.hpp>
#include <eagine/message_bus/direct.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/message_bus/router.hpp>
#include <eagine/serialize/block_sink.hpp>
#include <eagine/serialize/block_source.hpp>
#include <eagine/serialize/fast_backend.hpp>
#include <eagine/serialize/read.hpp>
#include <eagine/serialize/write.hpp>
#include <eagine/system_info.hpp>
#include <iostream>
#include <queue>
#include <set>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class fibonacci_server : public actor<3> {
public:
    using this_class = fibonacci_server;
    using base = actor<3>;
    using base::bus_node;

    fibonacci_server(main_ctx_object obj)
      : base(
          std::move(obj),
          this,
          EAGINE_MSG_MAP(Fibonacci, FindServer, this_class, is_ready),
          EAGINE_MSG_MAP(Fibonacci, Calculate, this_class, calculate),
          EAGINE_MSG_MAP(Fibonacci, Shutdown, this_class, shutdown)) {}

    auto shutdown(const message_context&, stored_message&) -> bool {
        _done = true;
        return true;
    }

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

    auto is_done() const noexcept {
        return _done;
    }

private:
    bool _done{false};
};
//------------------------------------------------------------------------------
class fibonacci_client : public actor<2> {
public:
    using this_class = fibonacci_client;
    using base = actor<2>;
    using base::bus_node;

    fibonacci_client(main_ctx_object obj)
      : base(
          std::move(obj),
          this,
          EAGINE_MSG_MAP(Fibonacci, IsReady, this_class, dispatch),
          EAGINE_MSG_MAP(Fibonacci, Result, this_class, print)) {}

    void enqueue(std::int64_t arg) {
        _remaining.push(arg);
    }

    void shutdown() {
        bus_node().broadcast(EAGINE_MSG_ID(Fibonacci, Shutdown));
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

    auto is_done() const -> bool {
        return _remaining.empty() && _pending.empty();
    }

private:
    std::queue<std::int64_t> _remaining{};
    std::set<std::int64_t> _pending{};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {

    const auto thread_count =
      extract_or(ctx.system().cpu_concurrent_threads(), 4);

    auto acceptor = std::make_unique<msgbus::direct_acceptor>(ctx);

    msgbus::fibonacci_client client({EAGINE_ID(FibClient), ctx});
    client.add_connection(acceptor->make_connection());

    std::vector<std::thread> workers;
    workers.reserve(thread_count);

    for(span_size_t i = 0; i < thread_count; ++i) {
        workers.emplace_back(
          [srv_obj{main_ctx_object{EAGINE_ID(FibServer), ctx}},
           connection{acceptor->make_connection()}]() mutable {
              msgbus::fibonacci_server server(std::move(srv_obj));
              server.add_connection(std::move(connection));

              while(!server.is_done()) {
                  if(!server.process_one()) {
                      std::this_thread::sleep_for(
                        std::chrono::milliseconds(10));
                  }
              }
          });
    }

    msgbus::router router(ctx);
    router.add_acceptor(std::move(acceptor));

    const std::int64_t n = running_on_valgrind() ? 34 : 46;

    for(std::int64_t i = 1; i <= n; ++i) {
        client.enqueue(i);
    }

    while(!client.is_done()) {
        router.update();
        client.update();
        if(!client.process_one()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    client.shutdown();
    router.update();

    for(auto& worker : workers) {
        worker.join();
    }

    return 0;
}
} // namespace eagine
