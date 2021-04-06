/// @example eagine/sudoku_noise.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/application_config.hpp>
#include <eagine/main.hpp>
#include <eagine/main_ctx.hpp>
#include <eagine/sudoku.hpp>
#include <iostream>

namespace eagine {

template <unsigned S>
void sudoku_noise(
  eagine::basic_sudoku_board_traits<S> traits,
  application_config& cfg) {
    using namespace eagine;

    auto initial = [&]() {
        if(cfg.is_set("gen_one")) {
            return traits.make_generator().generate_one();
        } else if(cfg.is_set("gen_few")) {
            return traits.make_generator().generate_few();
        } else if(cfg.is_set("gen_medium")) {
            return traits.make_generator().generate_medium();
        } else if(cfg.is_set("gen_many")) {
            return traits.make_generator().generate_many();
        } else {
            return traits.make_diagonal();
        }
    };

    const auto width = extract_or(cfg.get<int>("width"), 16);
    const auto height = extract_or(cfg.get<int>("height"), 8);

    basic_sudoku_tiling<S> bst{traits, initial()};
    bst.print(std::cout, 0, 0, width, height);
}

auto main(main_ctx& ctx) -> int {
    auto& cfg = ctx.config();

    const auto rank = extract_or(cfg.get<int>("rank"), 4);

    switch(rank) {
        case 3: {
            // clang-format off
			sudoku_noise<3>({
				{" ","▀","▄","▖","▗","▘","▝","▚","▞"},
				{"?","?","?"}, " "
			}, cfg);
            // clang-format on
            break;
        }
        case 4: {
            // clang-format off
			sudoku_noise<4>({
				{" ","▀","▄","█","▌","▐","▖","▗","▘","▙","▚","▛","▜","▝","▞","▟"},
				{"?","?","?","?"}, " "
			}, cfg);
            // clang-format on
            break;
        }
        default:
            ctx.log()
              .error("invalid rank value: ${rank}")
              .arg(EAGINE_ID(rank), rank);
            break;
    }

    return 0;
}
} // namespace eagine
