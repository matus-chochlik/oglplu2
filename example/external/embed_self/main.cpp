/// @example external/embed_self.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/embed.hpp>
#include <eagine/hexdump.hpp>
#include <iostream>

auto main() -> int {
    using namespace eagine;
    std::cout << hexdump(embed(EAGINE_ID(self), __FILE__));

    return 0;
}
