/// @example eagine/array_size.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/array_size.hpp>
#include <iostream>

auto main() -> int {
    using namespace eagine;

    const char* strings[] = {"foo", "bar", "baz", "qux"};
    for(span_size_t i = 0; i < array_size(strings); ++i) {
        std::cout << i << '|' << strings[i] << std::endl;
    }

    return 0;
}
