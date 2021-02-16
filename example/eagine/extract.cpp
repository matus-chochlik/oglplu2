/// @example eagine/extract.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/extract.hpp>
#include <iostream>
#include <memory>

auto main() -> int {
    using namespace eagine;

    if(auto optstr = std::make_unique<std::string>("a string")) {
        std::cout << extract(optstr) << std::endl;
    }

    return 0;
}
