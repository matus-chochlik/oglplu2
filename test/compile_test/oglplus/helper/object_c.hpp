/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEST_OGLPLUS_HELPER_OBJECT_C_HPP
#define TEST_OGLPLUS_HELPER_OBJECT_C_HPP

#include "../../../compile_test/eagine/helper/object_c.hpp"

template <typename ObjectName>
void
oglplus_object_name_test(void) {
    eagine_object_name_test<ObjectName>();
}

template <typename Object>
void
oglplus_object_test(void) {
    eagine_object_test<Object>();
}

template <typename Object, typename ObjectType>
void
oglplus_object_test(ObjectType type) {
    eagine_object_test<Object>(type);
}

    // TODO

#endif // include guard
