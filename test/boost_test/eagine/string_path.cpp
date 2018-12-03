/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/string_path.hpp>
#define BOOST_TEST_MODULE EAGINE_string_path
#include "../unit_test_begin.inl"

#include <stack>
#include <string>

BOOST_AUTO_TEST_SUITE(string_path_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(string_path_1) {
    using namespace eagine;

    basic_string_path bsp;

    for(int i = 0; i < 100; ++i) {
        std::size_t s = 0;

        for(int j = 0, k = rg.get_int(10, 100); j < k; ++j) {
            std::string n(
              rg.get<std::string::size_type>(0, 8196), rg.get<char>('A', 'Z'));
            bsp.push_back(string_view(n));
            ++s;

            BOOST_CHECK_EQUAL(bsp.size(), s);
            BOOST_CHECK_EQUAL(bsp.back().size(), n.size());
            BOOST_CHECK(bsp.back() == string_view(n));

            if((rg.get_int(0, 9) == 0) && !bsp.empty()) {
                bsp.pop_back();
                --s;
            }
            BOOST_CHECK_EQUAL(bsp.size(), s);
        }

        bsp = bsp + bsp;

        BOOST_CHECK_EQUAL(bsp.size(), 2 * s);

        if(rg.get_bool()) {
            while(!bsp.empty()) {
                bsp.pop_back();
            }
        } else {
            bsp.clear();
        }

        BOOST_CHECK_EQUAL(bsp.size(), 0);
    }
}

BOOST_AUTO_TEST_CASE(string_path_2) {
    using namespace eagine;

    for(int i = 0; i < 200; ++i) {
        basic_string_path bsp;

        for(int j = 0, k = rg.get_int(0, 30); j < k; ++j) {
            auto n = rg.get<std::string::size_type>(0, 8196);
            char c = rg.get<char>('A', 'Z');
            std::string s(n, c);
            bsp.push_back(string_view(s));

            BOOST_CHECK(bsp.back() == string_view(s));
            BOOST_CHECK(!bsp.empty());
        }

        std::stack<std::string> stk;
        bsp.for_each([&stk](basic_string_path::value_type s) {
            stk.push(std::string(s.begin(), s.end()));
            BOOST_CHECK(s == string_view(stk.top()));
        });

        BOOST_CHECK_EQUAL(bsp.size(), stk.size());

        bsp.rev_for_each([&stk](basic_string_path::value_type s) {
            BOOST_ASSERT(!stk.empty());
            BOOST_CHECK(s == string_view(stk.top()));
            stk.pop();
        });

        BOOST_CHECK(stk.empty());
    }
}

BOOST_AUTO_TEST_CASE(string_path_3) {
    using namespace eagine;

    for(int i = 0; i < 200; ++i) {
        basic_string_path bsp;

        for(int j = 0, k = rg.get_int(0, 30); j < k; ++j) {
            auto n = rg.get<std::string::size_type>(0, 8196);
            char c = rg.get<char>('A', 'Z');
            std::string s(n, c);
            bsp.push_back(string_view(s));

            BOOST_CHECK(bsp.back() == string_view(s));
            BOOST_CHECK(!bsp.empty());
        }

        std::stack<std::string> stk;
        for(auto p = bsp.begin(); p != bsp.end(); ++p) {
            stk.push(std::string((*p).begin(), p->end()));
            BOOST_CHECK(*p == string_view(stk.top()));
        }

        BOOST_CHECK_EQUAL(bsp.size(), stk.size());

        for(auto p = bsp.rbegin(); p != bsp.rend(); ++p) {
            BOOST_ASSERT(!stk.empty());
            BOOST_CHECK(*p == string_view(stk.top()));
            stk.pop();
        }
        BOOST_CHECK(stk.empty());
    }
}

BOOST_AUTO_TEST_CASE(string_path_4) {
    using namespace eagine;

    basic_string_path bsp;
    bsp.push_back("");
    bsp.push_back("A");
    bsp.push_back("BC");
    bsp.push_back("DEF");
    bsp.push_back("GHIJ");
    bsp.push_back("KLMNO");

    BOOST_CHECK_EQUAL(bsp.as_string("", true), "ABCDEFGHIJKLMNO");
    BOOST_CHECK_EQUAL(bsp.as_string("", false), "ABCDEFGHIJKLMNO");

    BOOST_CHECK_EQUAL(bsp.as_string(":", true), ":A:BC:DEF:GHIJ:KLMNO:");
    BOOST_CHECK_EQUAL(bsp.as_string("|", false), "|A|BC|DEF|GHIJ|KLMNO");

    BOOST_CHECK_EQUAL(bsp.as_string("..", true), "..A..BC..DEF..GHIJ..KLMNO..");
    BOOST_CHECK_EQUAL(bsp.as_string("::", false), "::A::BC::DEF::GHIJ::KLMNO");
}

BOOST_AUTO_TEST_CASE(string_path_5) {
    using namespace eagine;

    basic_string_path bsp("/usr/local/bin", EAGINE_TAG(split_by), "/");

    BOOST_ASSERT(!bsp.empty());
    BOOST_CHECK_EQUAL(bsp.size(), 4);
    BOOST_CHECK(bsp.front() == "");
    BOOST_CHECK(bsp.back() == "bin");

    BOOST_CHECK_EQUAL(bsp.as_string("::", false), "::usr::local::bin");

    BOOST_CHECK_EQUAL(bsp.as_string(":", true), ":usr:local:bin:");
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
