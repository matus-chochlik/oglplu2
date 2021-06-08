/// @example eagine/message_bus/005_byte_histogram.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/file_contents.hpp>
#include <eagine/identifier_ctr.hpp>
#include <eagine/main.hpp>
#include <eagine/math/functions.hpp>
#include <eagine/memory/span_algo.hpp>
#include <eagine/message_bus.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/timeout.hpp>
#include <array>
#include <thread>

namespace eagine {

auto main(main_ctx& ctx) -> int {

    std::array<span_size_t, 256> byte_counts{};

    auto log_byte_hist = [&ctx, &byte_counts](
                           const msgbus::message_context& mc,
                           msgbus::stored_message& msg) {
        if(msg.data().size()) {
            zero(cover(byte_counts));

            span_size_t max_count{0};
            for(auto b : msg.content()) {
                max_count =
                  math::maximum(max_count, ++byte_counts[std_size(b)]);
            }

            ctx.log()
              .info("received blob message ${message}")
              .arg(EAGINE_ID(message), mc.msg_id())
              .arg_func([&byte_counts, max_count](logger_backend& backend) {
                  for(std::size_t i = 0; i < 256; ++i) {
                      backend.add_float(
                        byte_to_identifier(i),
                        EAGINE_ID(Histogram),
                        float(0),
                        float(byte_counts[i]),
                        float(max_count));
                  }
              });
        }

        return true;
    };

    msgbus::endpoint bus{main_ctx_object{EAGINE_ID(Temporary), ctx}};

    ctx.bus().setup_connectors(bus);

    timeout idle_too_long{std::chrono::seconds{30}};
    while(!idle_too_long) {
        if(
          bus.update() ||
          bus.process_everything({construct_from, log_byte_hist})) {
            idle_too_long.reset();
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
    bus.finish();

    return 0;
}

} // namespace eagine
