/// @example eagine/message_bus/010_fib_futures.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/interop/valgrind.hpp>
#include <eagine/main.hpp>
#include <eagine/message_bus/acceptor.hpp>
#include <eagine/message_bus/direct.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/message_bus/router.hpp>
#include <eagine/message_bus/service.hpp>
#include <iostream>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class fibonacci_server_impl : public Base {
    using This = fibonacci_server_impl;

protected:
    using Base::Base;
    using Base::bus_node;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this, EAGINE_MSG_MAP(Fibonacci, Calculate, This, calculate));
    }

private:
    default_lazy_skeleton<std::int64_t(std::int64_t), 64> _calc_skeleton{
      std::chrono::minutes(1)};

    static auto fib(std::int64_t arg) -> std::int64_t {
        return arg <= 2 ? 1 : fib(arg - 2) + fib(arg - 1);
    }

    auto calculate(const message_context&, stored_message& msg_in) {
        _calc_skeleton.enqueue(
          msg_in, EAGINE_MSG_ID(Fibonacci, Result), {&fib});
        return true;
    }

public:
    auto update() -> work_done {
        some_true something_done{};
        something_done(Base::update());

        something_done(_calc_skeleton.handle_one(bus_node()));

        return something_done;
    }
};
using fibonacci_server = service_composition<fibonacci_server_impl<>>;
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class fibonacci_client_impl : public Base {
    using This = fibonacci_client_impl;

protected:
    using Base::Base;
    using Base::bus_node;

    void add_methods() {
        Base::add_methods();
        Base::add_method(_calc_invoker[EAGINE_MSG_ID(Fibonacci, Result)]);
    }

private:
    default_invoker<std::int64_t(std::int64_t), 64> _calc_invoker{};

public:
    auto fib(std::int64_t arg) -> future<std::int64_t> {
        return _calc_invoker.invoke(
          bus_node(), EAGINE_MSG_ID(Fibonacci, Calculate), arg);
    }

    auto is_done() const -> bool {
        return _calc_invoker.is_done();
    }
};
using fibonacci_client = service_composition<fibonacci_client_impl<>>;
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
        client.fib(i)
          .set_timeout(std::chrono::minutes(1))
          .then([i](std::int64_t fib) {
              std::cout << "fib(" << i << ") = " << fib << std::endl;
          })
          .otherwise([]() { std::cout << "failed" << std::endl; });
    }

    while(!client.is_done()) {
        router.update();
        client.update();
        server.update();
        client.process_one();
        server.process_one();
    }

    return 0;
}
} // namespace eagine
