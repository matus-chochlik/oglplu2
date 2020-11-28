/**
 *  @example eagine/integer_hash.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/integer_hash.hpp>
#include <iostream>

auto main() -> int {
    using namespace eagine;

    std::cout << integer_hash<std::uint16_t>(0) << std::endl;
    std::cout << integer_hash<std::uint32_t>(1) << std::endl;
    std::cout << integer_hash<std::uint64_t>(2) << std::endl;

    std::cout << integer_hash<std::uint16_t>(sizeof(short)) << std::endl;
    std::cout << integer_hash<std::uint32_t>(sizeof(int)) << std::endl;
    std::cout << integer_hash<std::uint64_t>(sizeof(long)) << std::endl;

    return 0;
}
