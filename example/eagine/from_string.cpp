/**
 *  @example eagine/from_string.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/from_string.hpp>
#include <eagine/program_args.hpp>
#include <iomanip>
#include <iostream>

int main(int argc, const char** argv) {
    using namespace eagine;

    for(auto& arg : program_args(argc, argv)) {
        if(auto opt_int = from_string<int>(arg)) {
            std::cout << "integer: " << extract(opt_int) << std::endl;
        } else if(auto opt_float = from_string<float>(arg)) {
            std::cout << "float: " << extract(opt_float) << std::endl;
        } else if(auto opt_double = from_string<double>(arg)) {
            std::cout << "double: " << extract(opt_double) << std::endl;
        } else if(auto opt_char = from_string<char>(arg)) {
            std::cout << "character: " << extract(opt_char) << std::endl;
        } else if(auto opt_bool = from_string<bool>(arg)) {
            std::cout << "boolean: " << std::boolalpha << extract(opt_bool)
                      << std::endl;
        } else {
            std::cout << "other: " << arg << std::endl;
        }
    }

    return 0;
}
