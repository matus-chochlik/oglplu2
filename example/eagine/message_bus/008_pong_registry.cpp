/**
 *  @example eagine/message_bus/008_pong_registry.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main_ctx.hpp>
#include <eagine/message_bus/registry.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/ping_pong.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/message_bus/service/system_info.hpp>
#include <eagine/timeout.hpp>
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
using pong_base =
  service_composition<pingable<system_info_provider<shutdown_target<>>>>;

class pong_example : public pong_base {
    using base = pong_base;

public:
    pong_example(endpoint& bus)
      : base{bus}
      , _log{EAGINE_ID(PongExampl), bus.log()} {}

    auto respond_to_ping(identifier_t, message_sequence_t, verification_bits)
      -> bool final {
        if(EAGINE_UNLIKELY((++_sent % _mod) == 0)) {
            _log.info("sent ${sent} pongs").arg(EAGINE_ID(sent), _sent);
        }
        return true;
    }

    void on_shutdown(
      std::chrono::milliseconds age,
      identifier_t source_id,
      verification_bits verified) final {
        _log.info("received shutdown request from ${source}")
          .arg(EAGINE_ID(age), age)
          .arg(EAGINE_ID(source), source_id)
          .arg(EAGINE_ID(verified), verified);

        _done = true;
    }

    auto is_done() const noexcept -> bool {
        return _done;
    }

    auto update() -> bool {
        some_true something_done{};
        something_done(base::update());
        if(_sent < 1) {
            if(_announce_timeout) {
                this->announce_subscriptions();
                _announce_timeout.reset();
                something_done();
            }
        }
        return something_done;
    }

private:
    logger _log{};
    std::intmax_t _mod{10000};
    std::intmax_t _sent{0};
    timeout _announce_timeout{std::chrono::seconds(5)};
    bool _done{false};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {

    msgbus::registry the_reg{ctx.log(), ctx.config()};

    valid_if_positive<int> opt_ponger_count{};
    if(auto arg{ctx.args().find("--ponger-count")}) {
        arg.next().parse(opt_ponger_count, ctx.log().error_stream());
    }
    const auto ponger_count = extract_or(opt_ponger_count, 1);

    std::atomic<int> still_working(ponger_count);
    std::vector<std::thread> workers;
    workers.reserve(std_size(ponger_count));
    for(int p = 0; p < ponger_count; ++p) {
        auto& bus = the_reg.establish(EAGINE_ID(PongEndpt));
        workers.emplace_back([&still_working, &bus]() {
            msgbus::pong_example ponger(bus);
            while(!ponger.is_done()) {
                ponger.process_all();
                if(!ponger.update()) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                }
            }
            --still_working;
        });
    }

    while(still_working) {
        the_reg.update();
    }

    for(auto& worker : workers) {
        worker.join();
    }

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine

auto main(int argc, const char** argv) -> int {
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(PongRegExe);
    return eagine::main_impl(argc, argv, options);
}
