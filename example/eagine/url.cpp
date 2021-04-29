/// @example eagine/url.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/url.hpp>
#include <iostream>

namespace eagine {} // namespace eagine

auto main() -> int {
    using namespace eagine;

    std::string line;
    while((std::cin >> line).good()) {
        url u{line};

        std::cout << "scheme:   " << u.scheme() << std::endl;
    }

    return 0;
}
