/**
 *  @example eagine/random_bytes.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/hexdump.hpp>
#include <eagine/random_bytes.hpp>
#include <eagine/span.hpp>
#include <iostream>
#include <vector>

auto main() -> int {
    using namespace eagine;

    std::vector<byte> bytes(256);
    fill_with_random_bytes(cover(bytes));

    std::cout << hexdump(view(bytes)) << std::endl;

    return 0;
}
