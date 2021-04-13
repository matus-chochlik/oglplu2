/// @example eagine/interleaved_call.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/interleaved_call.hpp>
#include <eagine/string_span.hpp>
#include <iostream>

auto main() -> int {
    using namespace eagine;
    using std::cout;
    using v = string_view;

    auto fn1 =
      interleaved_call([](int i) { cout << i; }, []() { cout << ", "; });

    for(int i = 0; i < 20; ++i) {
        fn1(i);
    }
    cout << std::endl;

    auto fn2 = interleaved_call(
      [](string_view s) { cout << s; }, []() { cout << "}{"; });

    cout << '{';
    for(auto name : view(
          {v("January"),
           v("February"),
           v("March"),
           v("April"),
           v("May"),
           v("June"),
           v("July"),
           v("August"),
           v("September"),
           v("October"),
           v("November"),
           v("December")})) {
        fn2(name);
    }
    cout << '}' << std::endl;

    return 0;
}
