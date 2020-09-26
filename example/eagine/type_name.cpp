/**
 *  @example eagine/type_name.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/type_name.hpp>
#include <array>
#include <iostream>
#include <string>
#include <vector>

auto main() -> int {
    using namespace eagine;
    using std::cout;
    using std::endl;

    cout << type_name<int>() << endl;
    cout << type_name<double>() << endl;
    cout << type_name<std::vector<short>>() << endl;
    cout << type_name<std::array<char, 10>>() << endl;
    cout << type_name<std::string>() << endl;
    cout << type_name<std::vector<std::string>>() << endl;

    return 0;
}
