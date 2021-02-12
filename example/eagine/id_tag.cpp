/// @example eagine/id_tag`.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/identifier.hpp>
#include <iostream>
//------------------------------------------------------------------------------
static inline void func(EAGINE_TAG_TYPE(foo)) {
    std::cout << "called foo free func" << std::endl;
}

static inline void func(EAGINE_TAG_TYPE(bar)) {
    std::cout << "called bar free func" << std::endl;
}

static inline void func(EAGINE_TAG_TYPE(baz)) {
    std::cout << "called baz free func" << std::endl;
}
//------------------------------------------------------------------------------
template <typename Tag>
struct test;

template <>
struct test<EAGINE_TAG_TYPE(foo)> {
    static inline void func() {
        std::cout << "called foo member func" << std::endl;
    }
};

template <>
struct test<EAGINE_TAG_TYPE(bar)> {
    static inline void func() {
        std::cout << "called bar member func" << std::endl;
    }
};
//------------------------------------------------------------------------------
auto main() -> int {
    using namespace eagine;

    func(EAGINE_TAG(foo));
    func(EAGINE_TAG(bar));
    func(EAGINE_TAG(baz));

    test<EAGINE_TAG_TYPE(foo)>::func();
    test<EAGINE_TAG_TYPE(bar)>::func();

    return 0;
}
