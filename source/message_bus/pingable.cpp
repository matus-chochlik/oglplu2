///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/main_ctx.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/build_info.hpp>
#include <eagine/message_bus/service/endpoint_info.hpp>
#include <eagine/message_bus/service/host_info.hpp>
#include <eagine/message_bus/service/ping_pong.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/timeout.hpp>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
using pingable_node_base = service_composition<shutdown_target<
  pingable<build_info_provider<host_info_provider<endpoint_info_provider<>>>>>>;

class pingable_node
  : public main_ctx_object
  , public pingable_node_base {
    using base = pingable_node_base;

public:
    pingable_node(endpoint& bus)
      : main_ctx_object{EAGINE_ID(PngablNode), bus}
      , base{bus} {}

    auto respond_to_ping(identifier_t, message_sequence_t, verification_bits)
      -> bool final {
        if(EAGINE_UNLIKELY((++_sent % _mod) == 0)) {
            log_info("sent ${sent} pongs").arg(EAGINE_ID(sent), _sent);
        }
        return true;
    }

    void on_shutdown(
      std::chrono::milliseconds age,
      identifier_t source_id,
      verification_bits verified) final {
        log_info("received shutdown request from ${source}")
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
    auto provide_endpoint_info() -> endpoint_info final {
        endpoint_info result;
        result.display_name = "pingable node";
        result.description = "simple generic pingable node";
        return result;
    }

    std::intmax_t _mod{10000};
    std::intmax_t _sent{0};
    timeout _announce_timeout{std::chrono::seconds(5)};
    bool _done{false};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {
    ctx.preinitialize();

    msgbus::router_address address{ctx};
    msgbus::connection_setup conn_setup(ctx);

    msgbus::endpoint bus{main_ctx_object{EAGINE_ID(PngablEndp), ctx}};

    if(auto id_arg{ctx.args().find("--pingable-id").next()}) {
        identifier_t id{0};
        if(id_arg.parse(id, ctx.log().error_stream())) {
            bus.preconfigure_id(id);
        }
    }

    msgbus::pingable_node the_pingable{bus};
    conn_setup.setup_connectors(the_pingable, address);

    while(!the_pingable.is_done()) {
        if(!the_pingable.update_and_process_all()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine

auto main(int argc, const char** argv) -> int {
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(PongExe);
    return eagine::main_impl(argc, argv, options);
}
