/// @example eagine/string_path.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/string_path.hpp>
#include <iostream>

auto main() -> int {
    using namespace eagine;

    basic_string_path cxx("/usr/local/bin/c++", EAGINE_TAG(split_by), "/");

    std::cout << cxx.size() << std::endl;
    for(auto& entry : cxx) {
        std::cout << '"' << entry << '"' << std::endl;
    }

    std::cout << cxx.as_string("|", true) << std::endl;
    std::cout << cxx.as_string("/", false) << std::endl;

    return 0;
}
