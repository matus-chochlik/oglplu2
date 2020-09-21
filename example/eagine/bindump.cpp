/**
 *  @example eagine/bindump.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bindump.hpp>
#include <eagine/file_contents.hpp>
#include <eagine/program_args.hpp>
#include <iostream>

auto main(int argc, const char** argv) -> int {
    using namespace eagine;

    program_args args(argc, argv);

    for(auto& arg : args) {
        if(!arg.starts_with("-")) {
            if(arg.prev().is_tag("-f", "--file")) {
                file_contents fc(arg.get());
                std::cout << arg << '|' << bindump(fc.block()) << std::endl;
            } else if(arg.prev().is_tag("-s", "--string")) {
                std::cout << arg << '|' << bindump(arg.block()) << std::endl;
            }
        }
    }

    span_size_t i = 0;
    auto get = [&]() -> optionally_valid<byte> {
        if(i < 256) {
            return {byte(i++), true};
        }
        return {};
    };
    auto put = [](char c) {
        std::cout << c;
        return true;
    };
    bindump::apply(bindump::byte_getter(get), bindump::char_putter(put));

    return 0;
}
