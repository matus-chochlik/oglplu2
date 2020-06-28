/**
 *  @example eagine/from_string.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <iostream>

#include <eagine/from_string.hpp>
#include <eagine/main.hpp>
#include <eagine/program_args.hpp>
#include <chrono>
#include <iomanip>

namespace eagine {

int main(main_ctx& ctx) {
    using duration = std::chrono::duration<float, std::milli>;

    for(auto& arg : ctx.args()) {
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
        } else if(auto opt_dur = from_string<duration>(arg)) {
            std::cout << "duration: " << extract(opt_dur).count() << "ms"
                      << std::endl;
        } else {
            std::cout << "other: " << arg << std::endl;
        }
    }

    return 0;
}

} // namespace eagine
