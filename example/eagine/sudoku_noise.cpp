/// @example eagine/sudoku_noise.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/program_args.hpp>
#include <eagine/sudoku.hpp>
#include <iostream>
#include <stack>

#include <map>

template <unsigned S>
void sudoku_noise(
  eagine::basic_sudoku_board_traits<S> traits,
  const eagine::program_args& args) {
    using namespace eagine;

    auto initial = [&]() {
        if(args.find("--gen-one")) {
            return traits.make_generator().generate_one();
        } else if(args.find("--gen-few")) {
            return traits.make_generator().generate_few();
        } else if(args.find("--gen-medium")) {
            return traits.make_generator().generate_medium();
        } else if(args.find("--gen-many")) {
            return traits.make_generator().generate_many();
        } else {
            return traits.make_diagonal();
        }
    };

    basic_sudoku_tiling<S> bst{traits, initial()};
    bst.print(std::cout, -8, -2, 8, 2);
}

auto main(int argc, const char** argv) -> int {
    eagine::program_args args{argc, argv};

    if(args.find("--3")) {
        // clang-format off
		sudoku_noise<3>({
			{" ","▀","▄","▖","▗","▘","▝","▚","▞"},
			{"?","?","?"}, " "
		}, args);
        // clang-format on
    } else {
        // clang-format off
		sudoku_noise<4>({
			{" ","▀","▄","█","▌","▐","▖","▗","▘","▙","▚","▛","▜","▝","▞","▟"},
			{"?","?","?","?"}, " "
		}, args);
        // clang-format on
    }

    return 0;
}
