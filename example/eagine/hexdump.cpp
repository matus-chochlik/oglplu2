/// @example eagine/bindump.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/file_contents.hpp>
#include <eagine/hexdump.hpp>
#include <eagine/main.hpp>
#include <eagine/program_args.hpp>
#include <iostream>

namespace eagine {

auto main(main_ctx& ctx) -> int {

    for(auto& arg : ctx.args()) {
        if(!arg.starts_with("-")) {
            if(arg.prev().is_tag("-f", "--file")) {
                file_contents fc(arg.get());
                std::cout << arg << '|' << hexdump(fc.block()) << std::endl;
            } else if(arg.prev().is_tag("-s", "--string")) {
                std::cout << arg << '|' << hexdump(arg.block()) << std::endl;
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
    hexdump::apply({construct_from, get}, {construct_from, put});

    return 0;
}
} // namespace eagine
