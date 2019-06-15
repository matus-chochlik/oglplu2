/**
 *  @file texgen/main.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "input_stream.hpp"
#include <iostream>

int main() {
    oglplus::texgen::input_stream in(std::cin);

    while(const char c = in.peek()) {
        std::cout << c;
        in.pop();
    }

    return 0;
}
