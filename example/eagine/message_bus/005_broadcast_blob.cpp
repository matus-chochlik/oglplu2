/**
 *  @example eagine/message_bus/005_broadcast_blob.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/file_contents.hpp>
#include <eagine/main.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/timeout.hpp>
#include <chrono>
#include <thread>

namespace eagine {

int main(main_ctx& ctx) {

    msgbus::router_address address{ctx.log(), ctx.args()};
    msgbus::connection_setup conn_setup(ctx.log(), ctx.args());

    msgbus::endpoint bus{logger{EAGINE_ID(Temporary), ctx.log()}};
    conn_setup.setup_connectors(bus, address);

    if(ctx.args().none()) {
        file_contents data(ctx.exe_path());

        bus.broadcast_blob(
          EAGINE_MSG_ID(Example, Content), data, std::chrono::minutes(5));
    } else {
        for(auto& arg : ctx.args()) {
            if(file_contents data{arg}) {

                bus.broadcast_blob(
                  EAGINE_MSG_ID(Example, Content),
                  data,
                  std::chrono::minutes(5));
            }
        }
    }

    timeout done{std::chrono::seconds{30}};
    while(!done) {
        if(bus.update()) {
            done.reset();
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
    bus.finish();

    return 0;
}

} // namespace eagine
