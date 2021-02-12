/// @example eagine/identifier.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/value_with_history.hpp>
#include <iostream>
//------------------------------------------------------------------------------
using val_t = eagine::value_with_history<int, 3>;
using var_t = eagine::variable_with_history<int, 3>;
//------------------------------------------------------------------------------
static inline void print(val_t& h) {
    std::cout << h.old_value() << '|' << h.value() << '|' << h.delta() << '|'
              << h.distance() << '|' << h.deltas().delta() << std::endl;
}
//------------------------------------------------------------------------------
auto main() -> int {
    using namespace eagine;

    const int n = 20;
    var_t i2(n * n);
    i2.sync();

    for(int i = -n; i <= n; ++i) {
        i2.assign(i * i);
        print(i2);
    }

    return 0;
}
