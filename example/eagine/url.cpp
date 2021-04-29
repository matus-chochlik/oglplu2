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

        std::cout << "scheme:     " << u.scheme() << std::endl;
        std::cout << "login:      " << u.login() << std::endl;
        std::cout << "password:   " << u.password() << std::endl;
        std::cout << "host:       " << u.host() << std::endl;
        std::cout << "port:       " << u.port() << std::endl;
        std::cout << "path:       " << u.path() << std::endl;
        std::cout << "query:      " << u.query() << std::endl;
        std::cout << "fragment:   " << u.fragment() << std::endl;
    }

    return 0;
}
