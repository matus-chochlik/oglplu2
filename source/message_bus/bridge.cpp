///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "lib_common_pki.hpp"
#include <eagine/config/platform.hpp>
#include <eagine/logging/root_logger.hpp>
#include <eagine/main_ctx.hpp>
#include <eagine/math/functions.hpp>
#include <eagine/maybe_unused.hpp>
#include <eagine/message_bus/bridge.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/message_bus/service/build_info.hpp>
#include <eagine/message_bus/service/endpoint_info.hpp>
#include <eagine/message_bus/service/host_info.hpp>
#include <eagine/message_bus/service/ping_pong.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/signal_switch.hpp>
#include <eagine/watchdog.hpp>

namespace eagine {
//------------------------------------------------------------------------------
namespace msgbus {
using bridge_node_base = service_composition<shutdown_target<
  pingable<build_info_provider<host_info_provider<endpoint_info_provider<>>>>>>;
//------------------------------------------------------------------------------
class bridge_node
  : public main_ctx_object
  , public bridge_node_base {
    using base = bridge_node_base;

public:
    bridge_node(endpoint& bus)
      : main_ctx_object{EAGINE_ID(BridgeNode), bus}
      , base{bus} {
        if(_shutdown_ignore) {
            log_info("shutdown requests are ignored due to configuration");
        } else {
            if(_shutdown_verify) {
                log_info("shutdown verification is enabled");
            } else {
                log_info("shutdown verification is disabled");
            }
            log_info("shutdown delay is set to ${delay}")
              .arg(EAGINE_ID(delay), _shutdown_timeout.period());

            shutdown_requested.connect(EAGINE_THIS_MEM_FUNC_REF(on_shutdown));
        }
    }

    auto update() -> bool {
        some_true something_done{};
        something_done(base::update_and_process_all());

        return something_done;
    }

    auto is_shut_down() const noexcept {
        return _do_shutdown && _shutdown_timeout;
    }

private:
    auto provide_endpoint_info() -> endpoint_info final {
        endpoint_info result;
        result.display_name = "bridge control node";
        result.description = "endpoint monitoring and controlling a bridge";
        result.is_bridge_node = true;
        return result;
    }

    timeout _shutdown_timeout{
      cfg_init("msg_bus.bridge.shutdown.delay", std::chrono::seconds(30))};
    const std::chrono::milliseconds _shutdown_max_age{cfg_init(
      "msg_bus.bridge.shutdown.max_age",
      std::chrono::milliseconds(2500))};
    const bool _shutdown_ignore{cfg_init("msg_bus.bridge.keep_running", false)};
    const bool _shutdown_verify{
      cfg_init("msg_bus.bridge.shutdown.verify", true)};
    bool _do_shutdown{false};

    auto _shutdown_verified(verification_bits v) const noexcept -> bool {
        return v.has_all(
          verification_bit::source_id,
          verification_bit::source_certificate,
          verification_bit::source_private_key,
          verification_bit::message_id);
    }

    void on_shutdown(
      std::chrono::milliseconds age,
      identifier_t source_id,
      verification_bits verified) {
        log_info("received ${age} old shutdown request from ${source}")
          .arg(EAGINE_ID(age), age)
          .arg(EAGINE_ID(source), source_id)
          .arg(EAGINE_ID(verified), verified);

        if(!_shutdown_ignore) {
            if(age <= _shutdown_max_age) {
                if(!_shutdown_verify || _shutdown_verified(verified)) {
                    log_info("request is valid, shutting down");
                    _do_shutdown = true;
                    _shutdown_timeout.reset();
                } else {
                    log_warning("shutdown verification failed");
                }
            } else {
                log_warning("shutdown request is too old");
            }
        } else {
            log_warning("ignoring shutdown request due to configuration");
        }
    }
};
} // namespace msgbus
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    signal_switch interrupted;

    auto& log = ctx.log();

    log.info("message bus bridge starting up");

    ctx.system().preinitialize();

    msgbus::router_address address(ctx);
    msgbus::connection_setup conn_setup(ctx);

    msgbus::bridge bridge(ctx);
    bridge.add_ca_certificate_pem(ca_certificate_pem(ctx));
    bridge.add_certificate_pem(msgbus_bridge_certificate_pem(ctx));
    conn_setup.setup_connectors(bridge, address);

    std::uintmax_t cycles_work{0};
    std::uintmax_t cycles_idle{0};
    int idle_streak{0};
    int max_idle_streak{0};

    msgbus::endpoint node_endpoint{EAGINE_ID(BrdgNodeEp), ctx};
    node_endpoint.add_ca_certificate_pem(ca_certificate_pem(ctx));
    conn_setup.setup_connectors(node_endpoint, address);
    msgbus::bridge_node node{node_endpoint};

    auto& wd = ctx.watchdog();
    wd.declare_initialized();

    while(EAGINE_LIKELY(
      !(interrupted || node.is_shut_down() || bridge.is_done()))) {
        some_true something_done{};
        something_done(bridge.update());
        something_done(node.update());

        if(something_done) {
            ++cycles_work;
            idle_streak = 0;
        } else {
            ++cycles_idle;
            max_idle_streak = math::maximum(max_idle_streak, ++idle_streak);
            std::this_thread::sleep_for(
              std::chrono::milliseconds(math::minimum(idle_streak / 8, 8)));
        }
        wd.notify_alive();
    }

    bridge.cleanup();
    wd.announce_shutdown();

    log.stat("message bus bridge finishing")
      .arg(EAGINE_ID(working), cycles_work)
      .arg(EAGINE_ID(idling), cycles_idle)
      .arg(
        EAGINE_ID(workRate),
        EAGINE_ID(Ratio),
        float(cycles_work) / (float(cycles_idle) + float(cycles_work)))
      .arg(
        EAGINE_ID(idleRate),
        EAGINE_ID(Ratio),
        float(cycles_idle) / (float(cycles_idle) + float(cycles_work)))
      .arg(EAGINE_ID(maxIdlStrk), max_idle_streak);

    return 0;
}
//------------------------------------------------------------------------------
void maybe_start_coprocess(int& argc, const char**& argv);
auto maybe_cleanup(int result) -> int;
//------------------------------------------------------------------------------
} // namespace eagine

auto main(int argc, const char** argv) -> int {
    eagine::maybe_start_coprocess(argc, argv);
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(BridgeExe);
    return eagine::maybe_cleanup(eagine::main_impl(argc, argv, options));
}

#if EAGINE_POSIX
#include <csignal>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

namespace eagine {
//------------------------------------------------------------------------------
#if EAGINE_POSIX
static ::pid_t ssh_coprocess_pid = -1;
#endif
//------------------------------------------------------------------------------
void maybe_start_coprocess(int& argc, const char**& argv) {
#if EAGINE_POSIX
    for(int argi = 1; argi < argc; ++argi) {
        program_arg arg{argi, argc, argv};
        if(arg.is_tag("--ssh")) {
            int pipe_b2c[2] = {-1, -1};
            int pipe_c2b[2] = {-1, -1};
            const int pipe_res_b2c = ::pipe(static_cast<int*>(pipe_b2c));
            const int pipe_res_c2b = ::pipe(static_cast<int*>(pipe_c2b));
            EAGINE_ASSERT(pipe_res_b2c == 0 && pipe_res_c2b == 0);
            EAGINE_MAYBE_UNUSED(pipe_res_b2c);
            EAGINE_MAYBE_UNUSED(pipe_res_c2b);

            const int fork_res = ::fork();
            EAGINE_ASSERT(fork_res >= 0);
            if(fork_res == 0) {
                if(auto ssh_host{arg.next()}) {
                    ::close(pipe_b2c[1]);
                    ::close(0);
                    ::dup2(pipe_b2c[0], 0);

                    ::close(pipe_c2b[0]);
                    ::close(1);
                    ::dup2(pipe_c2b[1], 1);

                    const char* ssh_exe = std::getenv("EAGINE_SSH");
                    if(!ssh_exe) {
                        ssh_exe = "ssh";
                    }
                    ::execlp( // NOLINT(hicpp-vararg)
                      ssh_exe,
                      ssh_exe,
                      "-T",
                      "-e",
                      "none",
                      "-q",
                      "-o",
                      "BatchMode=yes",
                      c_str(ssh_host.get()).c_str(),
                      ".oglplus/ssh-bridge",
                      "service_bridge",
                      nullptr);
                }
            } else {
                ::close(pipe_c2b[1]);
                ::close(0);
                ::dup2(pipe_c2b[0], 0);

                ::close(pipe_b2c[0]);
                ::close(1);
                ::dup2(pipe_b2c[1], 1);

                ssh_coprocess_pid = fork_res;
            }
        }
    }
#endif
    EAGINE_MAYBE_UNUSED(argc);
    EAGINE_MAYBE_UNUSED(argv);
}
//------------------------------------------------------------------------------
auto maybe_cleanup(int result) -> int {
#if EAGINE_POSIX
    if(ssh_coprocess_pid > 0) {
        int status = 0;
        ::kill(ssh_coprocess_pid, SIGTERM);
        ::waitpid(ssh_coprocess_pid, &status, 0);
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        if(!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
            return status;
        }
    }
#endif
    return result;
}
//------------------------------------------------------------------------------
} // namespace eagine

