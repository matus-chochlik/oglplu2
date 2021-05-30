///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/main_ctx.hpp>
#include <eagine/main_fwd.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/common_info.hpp>
#include <eagine/message_bus/service/resource_transfer.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/signal_switch.hpp>
#include <eagine/timeout.hpp>
#include <chrono>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
using file_server_node_base =
  service_composition<shutdown_target<resource_server<common_info_providers<>>>>;

class file_server_node
  : public main_ctx_object
  , public file_server_node_base {
    using base = file_server_node_base;

public:
    auto on_shutdown() noexcept {
        return EAGINE_THIS_MEM_FUNC_REF(_handle_shutdown);
    }

    file_server_node(endpoint& bus)
      : main_ctx_object{EAGINE_ID(FileServer), bus}
      , base{bus} {
        shutdown_requested.connect(on_shutdown());
        auto& info = provided_endpoint_info();
        info.display_name = "file server node";
        info.description = "message bus file server";
    }

    auto is_done() const noexcept -> bool {
        return _done;
    }

private:
    void _handle_shutdown(
      std::chrono::milliseconds age,
      identifier_t source_id,
      verification_bits verified) {
        log_info("received shutdown request from ${source}")
          .arg(EAGINE_ID(age), age)
          .arg(EAGINE_ID(source), source_id)
          .arg(EAGINE_ID(verified), verified);

        _done = true;
    }

    bool _done{false};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {
    signal_switch interrupted;
    ctx.preinitialize();

    msgbus::router_address address{ctx};
    msgbus::connection_setup conn_setup(ctx);

    msgbus::endpoint bus{main_ctx_object{EAGINE_ID(FilSvrEndp), ctx}};

    msgbus::file_server_node the_file_server{bus};
    conn_setup.setup_connectors(the_file_server, address);

    while(!(the_file_server.is_done() || interrupted)) {
        if(!the_file_server.update_and_process_all()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine

auto main(int argc, const char** argv) -> int {
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(FileServer);
    return eagine::main_impl(argc, argv, options);
}
