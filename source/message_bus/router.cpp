///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/logging/root_logger.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router.hpp>
#include <eagine/program_args.hpp>
#include <eagine/signal_switch.hpp>
//------------------------------------------------------------------------------
int main(int argc, const char** argv) {
    using namespace eagine;

    signal_switch done;

    program_args args(argc, argv);
    root_logger log(args);

    msgbus::connection_setup conn_setup;
    conn_setup.default_init(args);

    msgbus::router router;
    conn_setup.setup_acceptors(
      router,
      msgbus::connection_kind::in_process |
        msgbus::connection_kind::local_interprocess);

    while(!done) {
        router.update();
    }

    return 0;
}

