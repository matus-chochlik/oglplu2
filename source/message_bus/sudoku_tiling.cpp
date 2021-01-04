///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/main_ctx.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/endpoint.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/build_info.hpp>
#include <eagine/message_bus/service/endpoint_info.hpp>
#include <eagine/message_bus/service/host_info.hpp>
#include <eagine/message_bus/service/sudoku.hpp>
#include <eagine/signal_switch.hpp>
#include <iostream>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
using sudoku_tiling_base = service_composition<sudoku_tiling<
  build_info_provider<host_info_provider<endpoint_info_provider<>>>>>;

class sudoku_tiling_node
  : public main_ctx_object
  , public sudoku_tiling_base {
public:
    sudoku_tiling_node(endpoint& bus)
      : main_ctx_object{EAGINE_ID(TilingNode), bus}
      , sudoku_tiling_base{bus} {}

    template <unsigned S>
    void handle_generated(const sudoku_tiles<S>& tiles) {
        if(_print_incomplete || tiles.are_complete()) {
            tiles.print(std::cout) << std::endl;
        }
    }

    void on_tiles_generated(const sudoku_tiles<3>& tiles) final {
        handle_generated(tiles);
    }

    void on_tiles_generated(const sudoku_tiles<4>& tiles) final {
        handle_generated(tiles);
    }

    void on_tiles_generated(const sudoku_tiles<5>& tiles) final {
        handle_generated(tiles);
    }

    void on_tiles_generated(const sudoku_tiles<6>& tiles) final {
        handle_generated(tiles);
    }

private:
    auto provide_endpoint_info() -> endpoint_info final {
        endpoint_info result;
        result.display_name = "sudoku tiling generator";
        result.description = "node for generating sudoku block tiles";
        return result;
    }

    bool _print_incomplete{
      cfg_init("msg_bus.sudoku.solver.print_incomplete", false)};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {
    signal_switch interrupted;
    ctx.preinitialize();

    msgbus::router_address address{ctx};
    msgbus::connection_setup conn_setup(ctx);

    msgbus::endpoint tiling_endpoint(EAGINE_ID(TilingEpt), ctx);
    msgbus::sudoku_tiling_node tiling_generator(tiling_endpoint);
    conn_setup.setup_connectors(tiling_generator, address);

    valid_if_positive<int> width{0};
    valid_if_positive<int> height{0};

    ctx.args().find("--width").parse_next(width, ctx.log().error_stream());
    ctx.args().find("--height").parse_next(height, ctx.log().error_stream());

    auto enqueue = [&](auto traits) {
        tiling_generator.initialize(
          {extract_or(width, 32), extract_or(height, 32)},
          traits.make_generator().generate_medium());
    };

    if(ctx.args().find("--3")) {
        enqueue(default_sudoku_board_traits<3>());
    }

    if(ctx.args().find("--4")) {
        enqueue(default_sudoku_board_traits<4>());
    }

    if(ctx.args().find("--5")) {
        enqueue(default_sudoku_board_traits<5>());
    }

    if(ctx.args().find("--6")) {
        enqueue(default_sudoku_board_traits<6>());
    }

    auto keep_running = [&] {
        return !(interrupted || tiling_generator.tiling_complete());
    };

    int idle_streak = 0;
    while(keep_running()) {
        tiling_generator.update();
        if(tiling_generator.process_all()) {
            idle_streak = 0;
        } else {
            std::this_thread::sleep_for(
              std::chrono::milliseconds(math::minimum(++idle_streak, 50)));
        }
    }

    return 0;
}

} // namespace eagine
//------------------------------------------------------------------------------
auto main(int argc, const char** argv) -> int {
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(SudokuTlng);
    return eagine::main_impl(argc, argv, options);
}
