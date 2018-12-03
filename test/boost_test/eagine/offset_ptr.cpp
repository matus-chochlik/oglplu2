/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/offset_ptr.hpp>
#include <eagine/string_span.hpp>
#define BOOST_TEST_MODULE EAGINE_offset_ptr
#include "../unit_test_begin.inl"

#include <cstring>
#include <string>

BOOST_AUTO_TEST_SUITE(offset_ptr_tests)

BOOST_AUTO_TEST_CASE(offset_ptr_default_ctr) {
    using namespace eagine;

    offset_ptr<double> p0;

    BOOST_CHECK_EQUAL(bool(p0), false);
    BOOST_CHECK_EQUAL(!p0, true);
    BOOST_CHECK_EQUAL(!!p0, false);

    BOOST_CHECK(p0.get() == nullptr);
    BOOST_CHECK(p0.addr() == memory::const_address());
    BOOST_CHECK(p0.addr().value() == 0);
    BOOST_CHECK(static_cast<double*>(p0) == p0.get());
}

BOOST_AUTO_TEST_CASE(offset_ptr_2) {
    using namespace eagine;

    std::string str("blahbleh");

    offset_ptr<const std::string> ps(&str);

    BOOST_CHECK_EQUAL(bool(ps), true);
    BOOST_CHECK_EQUAL(!ps, false);
    BOOST_CHECK_EQUAL(!!ps, true);

    BOOST_ASSERT(ps.get() == &str);
    BOOST_CHECK(ps.addr() == memory::const_address(&str));
    BOOST_CHECK(static_cast<const std::string*>(ps) == ps.get());

    BOOST_CHECK_EQUAL(*ps, str);
    BOOST_CHECK_EQUAL(ps->size(), str.size());
}

BOOST_AUTO_TEST_CASE(offset_ptr_3) {
    using namespace eagine;

    std::string str("foobarbaz");
    offset_ptr<std::string> ops(&str);

    offset_ptr<std::string> ps(ops);

    BOOST_CHECK_EQUAL(bool(ps), true);
    BOOST_CHECK_EQUAL(!ps, false);
    BOOST_CHECK_EQUAL(!!ps, true);

    BOOST_CHECK(ps.addr() == ops.addr());
    BOOST_ASSERT(ps.get() == &str);
    BOOST_CHECK(ps.addr() == memory::const_address(&str));
    BOOST_CHECK(static_cast<const std::string*>(ps) == ps.get());

    BOOST_CHECK_EQUAL(*ps, str);
    BOOST_CHECK_EQUAL(ps->size(), str.size());
}

BOOST_AUTO_TEST_CASE(offset_ptr_4) {
    using namespace eagine;

    offset_ptr<std::string> ops;

    offset_ptr<std::string> ps(ops);

    BOOST_CHECK_EQUAL(bool(ps), false);
    BOOST_CHECK_EQUAL(!ps, true);
    BOOST_CHECK_EQUAL(!!ps, false);

    BOOST_CHECK(ps.addr() == ops.addr());
    BOOST_CHECK(ps.get() == nullptr);
    BOOST_CHECK(ps.addr() == memory::const_address());
    BOOST_CHECK(ps.addr().value() == 0);
}

// TODO
BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
