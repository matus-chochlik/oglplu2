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
#include <eagine/message_bus/service/build_info.hpp>
#include <eagine/message_bus/service/ping_pong.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/message_bus/service/system_info.hpp>
#include <eagine/timeout.hpp>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
using pong_base = service_composition<
  pingable<build_info_provider<system_info_provider<shutdown_target<>>>>>;

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

    auto& ponger = the_reg.emplace<msgbus::pong_example>(EAGINE_ID(PongEndpt));

    while(!ponger.is_done()) {
        if(!the_reg.update_all()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
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
