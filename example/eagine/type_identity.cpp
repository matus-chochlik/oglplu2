/**
 *  @example eagine/type_identity`.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/type_identity.hpp>
#include <iostream>
//------------------------------------------------------------------------------
static inline void func(eagine::type_identity<int>) {
    std::cout << "called int free func" << std::endl;
}

static inline void func(eagine::type_identity<float>) {
    std::cout << "called float free func" << std::endl;
}

static inline void func(eagine::type_identity<char>) {
    std::cout << "called char free func" << std::endl;
}

template <typename T>
static inline void func(eagine::type_identity<T>) {
    std::cout << "called other free func" << std::endl;
}
//------------------------------------------------------------------------------
auto main() -> int {
    using namespace eagine;

    func(make_identity(false));
    func(make_identity(123));
    func(make_identity(456.78F));
    func(make_identity('c'));

    return 0;
}
