/**
 *  @example eagine/sudoku_solver.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/program_args.hpp>
#include <eagine/sudoku.hpp>
#include <iostream>
#include <stack>

template <unsigned S>
void solve_sudoku(
  eagine::basic_sudoku_board_traits<S> traits,
  const eagine::program_args& args) {
    using namespace eagine;

    const bool tight = args.find("--tight");
    std::stack<typename decltype(traits)::board_type> solutions;

    if(args.find("--gen-one")) {
        solutions.push(traits.make_generator().generate_one());
    } else if(args.find("--gen-few")) {
        solutions.push(traits.make_generator().generate_few());
    } else if(args.find("--gen-medium")) {
        solutions.push(traits.make_generator().generate_medium());
    } else if(args.find("--gen-many")) {
        solutions.push(traits.make_generator().generate_many());
    } else {
        solutions.push(traits.make_diagonal());
    }

    auto print = [&](const auto& b) {
        (tight ? std::cout << b.tight() : std::cout << b) << std::endl;
    };
    auto board = solutions.top();
    print(board);

    bool done = false;
    while(!solutions.empty() && !done) {
        print(board);
        board = solutions.top();
        solutions.pop();

        board.for_each_alternative(board.find_unsolved(), [&](auto candidate) {
            if(candidate.is_solved()) {
                print(board);
                done = true;
            } else {
                solutions.push(candidate);
            }
        });
    }
}

auto main(int argc, const char** argv) -> int {
    eagine::program_args args{argc, argv};

    if(args.find("--4")) {
        // clang-format off
		solve_sudoku<4>({
			{"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"},
			{"?","?","?","?"}, " "
		}, args);
        // clang-format on
    } else if(args.find("--2")) {
        // clang-format off
		solve_sudoku<2>({
			{"▟","▙","▜","▛"},
			{"▚","▞"}, " "
		}, args);
        // clang-format on
    } else {
        // clang-format off
		solve_sudoku<3>({
			{"1","2","3","4","5","6","7","8","9"},
			{"?","?","?"}, " "
		}, args);
        // clang-format on
    }

    return 0;
}
