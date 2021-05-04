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

    const string_view n{"N/A"};

    std::string line;
    while((std::cin >> line).good()) {
        url u{line};

        std::cout << "scheme:     " << either_or(u.scheme(), n) << std::endl;
        std::cout << "login:      " << either_or(u.login(), n) << std::endl;
        std::cout << "password:   " << either_or(u.password(), n) << std::endl;
        std::cout << "host:       " << either_or(u.host(), n) << std::endl;
        std::cout << "port:       " << either_or(u.port(), n) << std::endl;
        std::cout << "path:       " << either_or(u.path_str(), n) << std::endl;
        std::cout << "path entries:" << std::endl;
        for(auto& entry : u.path()) {
            std::cout << "  '" << entry << "'" << std::endl;
        }
        std::cout << "query:      " << either_or(u.query_str(), n) << std::endl;
        std::cout << "query arguments:" << std::endl;
        for(auto& [name, value] : u.query()) {
            std::cout << "  " << name << ": '" << value << "'" << std::endl;
        }
        std::cout << "fragment:   " << either_or(u.fragment(), n) << std::endl;
    }

    return 0;
}
