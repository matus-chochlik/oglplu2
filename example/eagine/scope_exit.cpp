/// @example eagine/scope_exit.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/maybe_unused.hpp>
#include <eagine/scope_exit.hpp>
#include <exception>
#include <iostream>

auto main() -> int {
    using namespace eagine;
    using std::cout;

    auto x = finally([]() { cout << "done\n"; });
    auto c = finally([]() { cout << "should not see this\n"; });
    cout << "starting\n";
    try {
        auto y{finally([] { cout << "leaving try block\n"; })};
        EAGINE_MAYBE_UNUSED(y);
        cout << "entering try block\n";
        {
            auto z{finally([] { cout << "leaving inner block\n"; })};
            EAGINE_MAYBE_UNUSED(z);
            cout << "entering inner block\n";
            throw std::exception();
        }
    } catch(...) {
        auto e{finally([] { cout << "leaving catch block\n"; })};
        EAGINE_MAYBE_UNUSED(e);
        cout << "entering catch block\n";
    }
    c.cancel();

    return 0;
}
