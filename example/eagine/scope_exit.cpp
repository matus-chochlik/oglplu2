/**
 *  @example eagine/scope_exit.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/scope_exit.hpp>
#include <iostream>

int main() {
    using namespace eagine;
    using std::cout;

    auto x = finally([]() { cout << "done\n"; });
    auto c = finally([]() { cout << "should not see this\n"; });
    cout << "starting\n";
    try {
        auto y = finally([] { cout << "leaving try block\n"; });
        cout << "entering try block\n";
        {
            auto z = finally([] { cout << "leaving inner block\n"; });
            cout << "entering inner block\n";
            throw 0;
        }
    } catch(...) {
        auto e = finally([] { cout << "leaving catch block\n"; });
        cout << "entering catch block\n";
    }
    c.cancel();

    return 0;
}
