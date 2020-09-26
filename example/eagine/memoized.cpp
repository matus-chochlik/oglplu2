/**
 *  @example eagine/memoized.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memoized.hpp>
#include <cstdint>
#include <iostream>

auto main() -> int {
    using namespace eagine;

    using N = std::int64_t;
    memoized<N(N)> fib_memo([](N i, auto& memo) -> N {
        if(i < 2) {
            return 1;
        }
        return memo(i, [](N n, auto& f) { return f(n - 2) + f(n - 1); });
    });

    for(N n = 1; n <= 91; ++n) {
        std::cout << "  fib(" << n << ") = " << fib_memo(n) << std::endl;
    }

    memoized<N(N)> fact_memo([](N i, auto& memo) -> N {
        if(i < 2) {
            return i;
        }
        return memo(i, [](N n, auto& f) { return n * f(n - 1); });
    });

    for(N n = 1; n <= 20; ++n) {
        std::cout << "  " << n << "! = " << fact_memo(n) << std::endl;
    }

    return 0;
}
