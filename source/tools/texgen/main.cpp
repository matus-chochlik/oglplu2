/**
 *  @file texgen/main.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "tokenizer.hpp"
#include <fstream>
#include <iostream>

static void test(std::istream& input) {
    using namespace oglplus::texgen;

    tokenizer tzr{input_stream(input)};

    token_info token;
    while(tzr.get_next(token)) {
        std::cout << '|' << token.description() << '|' << token.spelling()
                  << '|' << std::endl;
        token.clear();
    }
}

int main(int argc, const char** argv) {
    if(argc == 1) {
        test(std::cin);
    } else {
        for(int i = 1; i < argc; ++i) {
            std::ifstream file(argv[i]);
            test(file);
        }
    }

    return 0;
}
