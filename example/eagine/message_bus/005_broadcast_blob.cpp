/// @example eagine/message_bus/005_broadcast_blob.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/file_contents.hpp>
#include <eagine/main.hpp>
#include <eagine/message_bus.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/timeout.hpp>
#include <chrono>
#include <thread>

namespace eagine {

auto main(main_ctx& ctx) -> int {

    msgbus::endpoint bus{EAGINE_ID(Temporary), ctx};
    ctx.bus().setup_connectors(bus);

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

    timeout done{std::chrono::seconds{3}};
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
