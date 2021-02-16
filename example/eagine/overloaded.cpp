/// @example eagine/overloaded.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/overloaded.hpp>
#include <eagine/string_span.hpp>
#include <iostream>

auto main() -> int {
    using namespace eagine;
    using std::cout;
    using std::endl;
    using v = string_view;

    auto func = overloaded(
      [](int x) { cout << "int: " << x << endl; },
      [](float x) { cout << "float: " << x << endl; },
      [](double x) { cout << "double: " << x << endl; },
      [](string_view x) { cout << "string: " << x << endl; },
      [](auto x) { cout << "other: " << x << endl; });

    func(v("zero"));
    func(123);
    func(45.F);
    func(67.8);
    func('9');

    return 0;
}
