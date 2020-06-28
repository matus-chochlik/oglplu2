/**
 *  @example eagine/zip_ranges.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/string_span.hpp>
#include <eagine/zip_iterator.hpp>
#include <array>
#include <iomanip>
#include <iostream>

int main() {
    using namespace eagine;

    std::array<int, 12> numbers{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}};
    std::array<string_view, 12> names{{"January",
                                       "February",
                                       "March",
                                       "April",
                                       "May",
                                       "June",
                                       "July",
                                       "August",
                                       "September",
                                       "October",
                                       "November",
                                       "December"}};

    for(auto [number, name] : zip_ranges(numbers, names)) {
        std::cout << std::setw(2) << std::setfill('0') << number << '|' << name
                  << std::endl;
    }

    return 0;
}
