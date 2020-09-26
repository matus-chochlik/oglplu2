/**
 *  @example eagine/valgrind.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/interop/valgrind.hpp>
#include <iostream>

auto main() -> int {
    using namespace eagine;

    if(auto on_vg = running_on_valgrind()) {
        std::cout << "running on valgrind" << std::endl;
    } else if(!on_vg) {
        std::cout << "not running on valgrind" << std::endl;
    } else {
        std::cout << "maybe running on valgrind" << std::endl;
    }

    return 0;
}
