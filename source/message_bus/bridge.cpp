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
#include <eagine/signal_switch.hpp>

#if EAGINE_POSIX
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

namespace eagine {
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    signal_switch interrupted;

    auto& log = ctx.log();

    log.info("message bus bridge starting up");

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

    while(EAGINE_LIKELY(!(interrupted || bridge.is_done()))) {
        if(EAGINE_LIKELY(bridge.update())) {
            ++cycles_work;
            idle_streak = 0;
        } else {
            ++cycles_idle;
            max_idle_streak = math::maximum(max_idle_streak, ++idle_streak);
            std::this_thread::sleep_for(
              std::chrono::milliseconds(math::minimum(idle_streak / 8, 8)));
        }
    }

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

