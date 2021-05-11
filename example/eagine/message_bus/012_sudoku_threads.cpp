/// @example eagine/message_bus/012_sudoku_threads.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/main.hpp>
#include <eagine/message_bus/acceptor.hpp>
#include <eagine/message_bus/direct.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/message_bus/router.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/sudoku.hpp>
#include <eagine/system_info.hpp>
#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

namespace eagine {
namespace msgbus {

using example_helper = service_composition<sudoku_helper<>>;

class example_solver : public service_composition<sudoku_solver<>> {
public:
    using base = service_composition<sudoku_solver<>>;

    example_solver(endpoint& bus)
      : base{bus} {
        solved_3.connect(EAGINE_THIS_MEM_FUNC_REF(print<3>));
        solved_4.connect(EAGINE_THIS_MEM_FUNC_REF(print<4>));
        solved_5.connect(EAGINE_THIS_MEM_FUNC_REF(print<5>));
    }

    template <unsigned S>
    void print(identifier_t, const int& id, basic_sudoku_board<S>& board) {
        std::cout << "board: " << id << '\n' << board << std::endl;
    }
};

} // namespace msgbus

auto main(main_ctx& ctx) -> int {
    const auto worker_count =
      extract_or(ctx.system().cpu_concurrent_threads(), 4) + 1;

    auto acceptor = std::make_unique<msgbus::direct_acceptor>(ctx);

    msgbus::endpoint solver_endpoint(EAGINE_ID(Solver), ctx);
    solver_endpoint.add_connection(acceptor->make_connection());
    msgbus::example_solver solver(solver_endpoint);

    auto board_count = 5;
    ctx.args().find("--count").parse_next(board_count, std::cerr);

    auto enqueue = [&](auto generator) {
        for(int id = 0; id < board_count; ++id) {
            solver.enqueue(id, generator.generate_medium());
        }
    };

    if(ctx.args().find("--3")) {
        enqueue(default_sudoku_board_traits<3>().make_generator());
    }

    if(ctx.args().find("--4")) {
        enqueue(default_sudoku_board_traits<4>().make_generator());
    }

    if(ctx.args().find("--5")) {
        enqueue(default_sudoku_board_traits<5>().make_generator());
    }

    std::mutex worker_mutex;
    std::atomic<bool> start = false;
    std::atomic<bool> done = false;
    std::vector<std::thread> workers;
    workers.reserve(worker_count);

    for(span_size_t i = 0; i < worker_count; ++i) {
        workers.emplace_back(
          [&worker_mutex,
           &start,
           &done,
           helper_obj{main_ctx_object{EAGINE_ID(Helper), ctx}},
           connection{acceptor->make_connection()}]() mutable {
              worker_mutex.lock();
              msgbus::endpoint helper_endpoint{std::move(helper_obj)};
              helper_endpoint.add_connection(std::move(connection));
              msgbus::example_helper helper(helper_endpoint);
              helper.update();
              worker_mutex.unlock();

              while(!start) {
                  std::this_thread::sleep_for(std::chrono::milliseconds(100));
              }

              while(!done) {
                  helper.update();
                  if(!helper.process_all()) {
                      std::this_thread::sleep_for(std::chrono::milliseconds(1));
                  }
              }
          });
    }

    worker_mutex.lock();
    msgbus::router router(ctx);
    router.add_acceptor(std::move(acceptor));
    router.update();
    worker_mutex.unlock();

    start = true;
    while(!solver.is_done()) {
        router.update();
        solver.update();
        solver.process_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    done = true;
    for(auto& worker : workers) {
        worker.join();
    }

    return 0;
}
} // namespace eagine
