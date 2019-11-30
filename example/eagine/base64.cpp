/**
 *  @example eagine/base64.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/base64.hpp>
#include <eagine/memory/block.hpp>
#include <eagine/program_args.hpp>
#include <iostream>

int main(int argc, const char** argv) {
    using namespace eagine;

    program_args args(argc, argv);
    std::string temp;
    for(auto arg = args.first(); arg; arg = arg.next()) {
        std::cout << arg << '|'
                  << base64_encode(arg.get_block(), temp).value_or("-")
                  << std::endl;
    }
    return 0;
}
