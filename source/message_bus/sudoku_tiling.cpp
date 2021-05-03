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
#include <eagine/message_bus/service/common_info.hpp>
#include <eagine/message_bus/service/ping_pong.hpp>
#include <eagine/message_bus/service/sudoku.hpp>
#include <eagine/signal_switch.hpp>
#include <iostream>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
using sudoku_tiling_base =
  service_composition<pingable<common_info_providers<sudoku_tiling<>>>>;

class sudoku_tiling_node
  : public main_ctx_object
  , public sudoku_tiling_base {
public:
    sudoku_tiling_node(endpoint& bus)
      : main_ctx_object{EAGINE_ID(TilingNode), bus}
      , sudoku_tiling_base{bus} {
        tiles_generated_3.connect(
          EAGINE_THIS_MEM_FUNC_REF(_handle_generated<3>));
        tiles_generated_4.connect(
          EAGINE_THIS_MEM_FUNC_REF(_handle_generated<4>));
        tiles_generated_5.connect(
          EAGINE_THIS_MEM_FUNC_REF(_handle_generated<5>));

        auto& info = provided_endpoint_info();
        info.display_name = "sudoku tiling generator";
        info.description = "helper node for the sudoku solver service";
    }

private:
    template <unsigned S>
    void _handle_generated(
      const sudoku_tiles<S>& tiles,
      const std::tuple<int, int>&) {
        if(_print_progress) {
            tiles.print_progress(std::cerr) << std::flush;
        }
        if(_print_incomplete || tiles.are_complete()) {
            if(_block_cells) {
                tiles.print(std::cout, block_sudoku_board_traits<S>{})
                  << std::endl;
            } else {
                tiles.print(std::cout) << std::endl;
            }
        }
    }

    bool _block_cells{cfg_init("msg_bus.sudoku.solver.block_cells", false)};
    bool _print_progress{
      cfg_init("msg_bus.sudoku.solver.print_progress", false)};
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

    const auto width =
      extract_or(ctx.config().get<int>("msg_bus.sudoku.solver.width"), 32);
    const auto height =
      extract_or(ctx.config().get<int>("msg_bus.sudoku.solver.height"), 32);

    const auto rank =
      extract_or(ctx.config().get<int>("msg_bus.sudoku.solver.rank"), 4);

    auto enqueue = [&](auto traits) {
        tiling_generator.reinitialize(
          {width, height}, traits.make_generator().generate_medium());
    };

    switch(rank) {
        case 3:
            enqueue(default_sudoku_board_traits<3>());
            break;
        case 4:
            enqueue(default_sudoku_board_traits<4>());
            break;
        case 5:
            enqueue(default_sudoku_board_traits<5>());
            break;
        default:
            ctx.log().error("invalid rank: ${rank}").arg(EAGINE_ID(rank), rank);
            return -1;
    }

    auto keep_running = [&] {
        return !(interrupted || tiling_generator.tiling_complete());
    };

    int idle_streak = 0;
    while(keep_running()) {
        tiling_generator.update();
        if(EAGINE_UNLIKELY(
             rank == 3 &&
             tiling_generator.solution_timeouted(unsigned_constant<3>{}))) {
            enqueue(default_sudoku_board_traits<3>());
        }
        if(EAGINE_UNLIKELY(
             rank == 4 &&
             tiling_generator.solution_timeouted(unsigned_constant<4>{}))) {
            enqueue(default_sudoku_board_traits<4>());
        }
        if(EAGINE_UNLIKELY(
             rank == 5 &&
             tiling_generator.solution_timeouted(unsigned_constant<5>{}))) {
            enqueue(default_sudoku_board_traits<5>());
        }
        if(tiling_generator.process_all()) {
            idle_streak = 0;
        } else {
            std::this_thread::sleep_for(
              std::chrono::milliseconds(math::minimum(++idle_streak, 50)));
        }
    }

    switch(rank) {
        case 3:
            tiling_generator.log_contribution_histogram(unsigned_constant<3>{});
            break;
        case 4:
            tiling_generator.log_contribution_histogram(unsigned_constant<4>{});
            break;
        case 5:
            tiling_generator.log_contribution_histogram(unsigned_constant<5>{});
            break;
        default:
            break;
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
