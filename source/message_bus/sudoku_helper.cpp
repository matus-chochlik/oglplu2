///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/main_ctx.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/direct.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/message_bus/router.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/build_info.hpp>
#include <eagine/message_bus/service/endpoint_info.hpp>
#include <eagine/message_bus/service/host_info.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/message_bus/service/sudoku.hpp>
#include <eagine/signal_switch.hpp>
#include <condition_variable>
#include <mutex>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
using sudoku_helper_base = service_composition<shutdown_target<sudoku_helper<
  build_info_provider<host_info_provider<endpoint_info_provider<>>>>>>;

class sudoku_helper_node
  : public main_ctx_object
  , public sudoku_helper_base {
public:
    sudoku_helper_node(endpoint& bus)
      : main_ctx_object{EAGINE_ID(SudokuNode), bus}
      , sudoku_helper_base{bus} {}

    auto is_shut_down() const noexcept -> bool {
        return _do_shutdown;
    }

private:
    void on_shutdown(
      std::chrono::milliseconds age,
      identifier_t source_id,
      verification_bits verified) final {
        log_info("received shutdown request from ${source}")
          .arg(EAGINE_ID(age), age)
          .arg(EAGINE_ID(source), source_id)
          .arg(EAGINE_ID(verified), verified);

        _do_shutdown = true;
    }

    auto provide_endpoint_info() -> endpoint_info final {
        endpoint_info result;
        result.display_name = "sudoku node";
        result.description = "helper node for the sudoku solver service";
        return result;
    }

    bool _do_shutdown{false};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {
    signal_switch interrupted;
    ctx.preinitialize();

    auto acceptor = std::make_unique<msgbus::direct_acceptor>(ctx);

    auto shutdown_when_idle = false;
    ctx.config().fetch(
      "msg_bus.sudoku.helper.shutdown_when_idle", shutdown_when_idle);

    auto max_idle_time = std::chrono::seconds(30);
    ctx.config().fetch("msg_bus.sudoku.helper.max_idle_time", max_idle_time);

    auto helper_count = extract_or(
      ctx.config().get<span_size_t>("msg_bus.sudoku.helper.count"),
      extract_or(ctx.system().cpu_concurrent_threads(), 4));

    std::mutex helper_mutex;
    std::condition_variable helper_cond;
    std::vector<std::thread> helpers;
    helpers.reserve(std_size(helper_count));

    volatile auto remaining = helper_count + 1;
    for(span_size_t i = 0; i < helper_count; ++i) {
        helpers.emplace_back([&]() {
            std::unique_lock init_lock{helper_mutex};
            msgbus::endpoint helper_endpoint{EAGINE_ID(SdkHlpEndp), ctx};
            helper_endpoint.add_connection(acceptor->make_connection());
            msgbus::sudoku_helper_node helper_node{helper_endpoint};
            remaining--;
            helper_cond.notify_all();
            init_lock.unlock();

            if(std::unique_lock latch_lock{helper_mutex}) {
                while(remaining > 0) {
                    helper_cond.wait(latch_lock);
                }
            }

            auto keep_running = [&]() {
                return !(
                  helper_node.is_shut_down() ||
                  (shutdown_when_idle &&
                   (helper_node.idle_time() > max_idle_time)));
            };

            int idle_streak = 0;
            while(keep_running()) {
                some_true something_done;
                something_done(helper_node.update());
                something_done(helper_node.process_all());

                if(something_done) {
                    idle_streak = 0;
                } else {
                    std::this_thread::sleep_for(std::chrono::milliseconds(
                      math::minimum(++idle_streak, 50)));
                }
            }

            std::unique_lock finish_lock{helper_mutex};
            helper_count--;
            helper_cond.notify_one();
        });
    }

    if(std::unique_lock latch_lock{helper_mutex}) {
        while(remaining > 1) {
            helper_cond.wait(latch_lock);
        }
    }

    std::unique_lock init_lock{helper_mutex};
    msgbus::router_address address{ctx};
    msgbus::connection_setup conn_setup(ctx);
    msgbus::router router(ctx);
    router.add_acceptor(std::move(acceptor));
    conn_setup.setup_connectors(router, address);
    router.update();
    remaining--;
    helper_cond.notify_all();
    init_lock.unlock();

    while(!(interrupted || router.is_done())) {
        if(!router.update(8)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        std::unique_lock break_lock{helper_mutex};
        if(helper_count <= 0) {
            break;
        }
    }

    for(auto& helper : helpers) {
        helper.join();
    }

    return 0;
}

} // namespace eagine
//------------------------------------------------------------------------------
auto main(int argc, const char** argv) -> int {
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(SudokuHlpr);
    return eagine::main_impl(argc, argv, options);
}
