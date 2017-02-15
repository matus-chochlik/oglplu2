/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/std/variant.hpp>
#define BOOST_TEST_MODULE EAGINE_std_variant
#include "../unit_test.inl"

#include <string>

BOOST_AUTO_TEST_SUITE(std_variant_tests)

static eagine::test_random_generator rg;

struct test_throw_on_copy
{
	test_throw_on_copy(void) = default;

	[[noreturn]]
	test_throw_on_copy(const test_throw_on_copy&) {
		throw 0;
	}
};

struct test_throw_on_move
{
	test_throw_on_move(void) = default;

	[[noreturn]]
	test_throw_on_move(test_throw_on_move&&) {
		throw 0;
	}
};

BOOST_AUTO_TEST_CASE(monostate_cmp)
{
	std::monostate ms1, ms2;

	BOOST_CHECK_EQUAL(ms1 != ms2, false);
	BOOST_CHECK_EQUAL(ms1 == ms2, true);
	BOOST_CHECK_EQUAL(ms1 <  ms2, false);
	BOOST_CHECK_EQUAL(ms1 <= ms2, true);
	BOOST_CHECK_EQUAL(ms1 >  ms2, false);
	BOOST_CHECK_EQUAL(ms1 >= ms2, true);
}

BOOST_AUTO_TEST_CASE(variant_1)
{
	std::variant<std::monostate> v1;
	std::monostate m1;

	BOOST_CHECK_EQUAL(std::variant_size_v<decltype(v1)>, 1);
	
	BOOST_CHECK_EQUAL(v1.index(), 0);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<std::monostate>(v1));
	BOOST_CHECK(std::get<0>(v1) == m1);
	BOOST_CHECK(std::get<std::monostate>(v1) == m1);
}

BOOST_AUTO_TEST_CASE(variant_2)
{
	std::variant<std::string> v1{"variant"};

	BOOST_CHECK_EQUAL(std::variant_size_v<decltype(v1)>, 1);
	
	BOOST_CHECK_EQUAL(v1.index(), 0);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<std::string>(v1));
	BOOST_CHECK_EQUAL(std::get<0>(v1), "variant");
	BOOST_CHECK_EQUAL(std::get<std::string>(v1), "variant");
}

BOOST_AUTO_TEST_CASE(variant_3)
{
	std::variant<int, std::string> v1{"variant"};
	std::variant<int, std::string> v2{v1};

	BOOST_CHECK_EQUAL(std::variant_size_v<decltype(v1)>, 2);
	BOOST_CHECK_EQUAL(std::variant_size_v<decltype(v2)>, 2);
	
	BOOST_CHECK_EQUAL(v1.index(), 1);
	BOOST_CHECK_EQUAL(v2.index(), 1);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<std::string>(v1));
	BOOST_CHECK(std::holds_alternative<std::string>(v2));
	BOOST_CHECK_EQUAL(std::get<1>(v1), "variant");
	BOOST_CHECK_EQUAL(std::get<1>(v2), "variant");
	BOOST_CHECK_EQUAL(std::get<std::string>(v1), "variant");
	BOOST_CHECK_EQUAL(std::get<std::string>(v2), "variant");
}

BOOST_AUTO_TEST_CASE(variant_4)
{
	std::variant<char, long, std::string> v1{"variant"};
	std::variant<char, long, std::string> v2;

	BOOST_CHECK_EQUAL(std::variant_size_v<decltype(v1)>, 3);
	BOOST_CHECK_EQUAL(std::variant_size_v<decltype(v2)>, 3);
	
	BOOST_CHECK_EQUAL(v1.index(), 2);
	BOOST_CHECK_EQUAL(v2.index(), 0);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<std::string>(v1));
	BOOST_CHECK(std::holds_alternative<char>(v2));
	BOOST_CHECK_EQUAL(std::get<2>(v1), "variant");
	BOOST_CHECK_EQUAL(std::get<std::string>(v1), "variant");

	v2 = v1;

	BOOST_CHECK_EQUAL(v1.index(), 2);
	BOOST_CHECK_EQUAL(v2.index(), 2);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<std::string>(v1));
	BOOST_CHECK(std::holds_alternative<std::string>(v2));
	BOOST_CHECK_EQUAL(std::get<2>(v1), "variant");
	BOOST_CHECK_EQUAL(std::get<2>(v2), "variant");
	BOOST_CHECK_EQUAL(std::get<std::string>(v1), "variant");
	BOOST_CHECK_EQUAL(std::get<std::string>(v2), "variant");
}

BOOST_AUTO_TEST_CASE(variant_5)
{
	std::variant<int, double, std::string> v1{"VArIAnt"};

	BOOST_CHECK_EQUAL(std::variant_size_v<decltype(v1)>, 3);
	
	BOOST_CHECK_EQUAL(v1.index(), 2);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<std::string>(v1));
	BOOST_CHECK_EQUAL(std::get<2>(v1), "VArIAnt");
	BOOST_CHECK_EQUAL(std::get<std::string>(v1), "VArIAnt");

	std::variant<int, double, std::string> v2{std::move(v1)};
	
	BOOST_CHECK_EQUAL(v1.index(), 2);
	BOOST_CHECK_EQUAL(v2.index(), 2);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<std::string>(v1));
	BOOST_CHECK(std::holds_alternative<std::string>(v2));
	BOOST_CHECK_EQUAL(std::get<2>(v1).empty(), true);
	BOOST_CHECK_EQUAL(std::get<2>(v2), "VArIAnt");
	BOOST_CHECK_EQUAL(std::get<std::string>(v1).empty(), true);
	BOOST_CHECK_EQUAL(std::get<std::string>(v2), "VArIAnt");
}

BOOST_AUTO_TEST_CASE(variant_6)
{
	std::variant<int, double, char, std::string> v1{"VaRiAnT"};
	std::variant<int, double, char, std::string> v2;

	BOOST_CHECK_EQUAL(std::variant_size_v<decltype(v1)>, 4);
	
	BOOST_CHECK_EQUAL(v1.index(), 3);
	BOOST_CHECK_EQUAL(v2.index(), 0);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<std::string>(v1));
	BOOST_CHECK(std::holds_alternative<int>(v2));
	BOOST_CHECK_EQUAL(std::get<3>(v1), "VaRiAnT");
	BOOST_CHECK_EQUAL(std::get<std::string>(v1), "VaRiAnT");

	v2 = std::move(v1);
	
	BOOST_CHECK_EQUAL(v1.index(), 3);
	BOOST_CHECK_EQUAL(v2.index(), 3);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<std::string>(v1));
	BOOST_CHECK(std::holds_alternative<std::string>(v2));
	BOOST_CHECK_EQUAL(std::get<3>(v1).empty(), true);
	BOOST_CHECK_EQUAL(std::get<3>(v2), "VaRiAnT");
	BOOST_CHECK_EQUAL(std::get<std::string>(v1).empty(), true);
	BOOST_CHECK_EQUAL(std::get<std::string>(v2), "VaRiAnT");
}

BOOST_AUTO_TEST_CASE(variant_7)
{
	std::variant<int, double, std::string, char> v1{"vArIaNt"};
	std::variant<int, double, std::string, char> v2;

	BOOST_CHECK_EQUAL(std::variant_size_v<decltype(v1)>, 4);
	
	BOOST_CHECK_EQUAL(v1.index(), 2);
	BOOST_CHECK_EQUAL(v2.index(), 0);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<std::string>(v1));
	BOOST_CHECK(std::holds_alternative<int>(v2));
	BOOST_CHECK_EQUAL(std::get<2>(v1), "vArIaNt");
	BOOST_CHECK_EQUAL(std::get<std::string>(v1), "vArIaNt");

	v1 = std::move(v2);
	
	BOOST_CHECK_EQUAL(v1.index(), 0);
	BOOST_CHECK_EQUAL(v2.index(), 0);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<int>(v1));
	BOOST_CHECK(std::holds_alternative<int>(v2));
}

BOOST_AUTO_TEST_CASE(variant_8)
{
	std::variant<bool, char, int, double, std::string> v1;

	BOOST_CHECK_EQUAL(std::variant_size_v<decltype(v1)>, 5);

	BOOST_CHECK_EQUAL(v1.index(), 0);
	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<bool>(v1));

	for(int r=0; r<1000; ++r) {

		switch(rg.get_int(0, 4)) {
		case 0: {
			const bool b = rg.get_any<bool>();
			v1 = b;

			BOOST_CHECK_EQUAL(v1.index(), 0);
			BOOST_CHECK(!v1.valueless_by_exception());
			BOOST_CHECK( std::holds_alternative<bool>(v1));
			BOOST_CHECK(!std::holds_alternative<char>(v1));
			BOOST_CHECK(!std::holds_alternative<int>(v1));
			BOOST_CHECK(!std::holds_alternative<double>(v1));
			BOOST_CHECK(!std::holds_alternative<std::string>(v1));
			BOOST_CHECK_EQUAL(std::get<0>(v1), b);
			BOOST_CHECK_EQUAL(std::get<bool>(v1), b);
			break;

		} case 1: {
			const char c = rg.get_char('A','Z');
			v1 = c;

			BOOST_CHECK_EQUAL(v1.index(), 1);
			BOOST_CHECK(!v1.valueless_by_exception());
			BOOST_CHECK(!std::holds_alternative<bool>(v1));
			BOOST_CHECK( std::holds_alternative<char>(v1));
			BOOST_CHECK(!std::holds_alternative<int>(v1));
			BOOST_CHECK(!std::holds_alternative<double>(v1));
			BOOST_CHECK(!std::holds_alternative<std::string>(v1));
			BOOST_CHECK_EQUAL(std::get<1>(v1), c);
			BOOST_CHECK_EQUAL(std::get<char>(v1), c);
			break;

		} case 2: {
			const int i = rg.get_any<int>();
			v1 = i;

			BOOST_CHECK_EQUAL(v1.index(), 2);
			BOOST_CHECK(!v1.valueless_by_exception());
			BOOST_CHECK(!std::holds_alternative<bool>(v1));
			BOOST_CHECK(!std::holds_alternative<char>(v1));
			BOOST_CHECK( std::holds_alternative<int>(v1));
			BOOST_CHECK(!std::holds_alternative<double>(v1));
			BOOST_CHECK(!std::holds_alternative<std::string>(v1));
			BOOST_CHECK_EQUAL(std::get<2>(v1), i);
			BOOST_CHECK_EQUAL(std::get<int>(v1), i);
			break;

		} case 3: {
			const double d = rg.get_any<double>();
			v1 = d;

			BOOST_CHECK_EQUAL(v1.index(), 3);
			BOOST_CHECK(!v1.valueless_by_exception());
			BOOST_CHECK(!std::holds_alternative<bool>(v1));
			BOOST_CHECK(!std::holds_alternative<char>(v1));
			BOOST_CHECK(!std::holds_alternative<int>(v1));
			BOOST_CHECK( std::holds_alternative<double>(v1));
			BOOST_CHECK(!std::holds_alternative<std::string>(v1));
			BOOST_CHECK_EQUAL(std::get<3>(v1), d);
			BOOST_CHECK_EQUAL(std::get<double>(v1), d);
			break;

		} case 4: {
			const std::string s = rg.get_string(0, 10);
			v1 = s;

			BOOST_CHECK_EQUAL(v1.index(), 4);
			BOOST_CHECK(!v1.valueless_by_exception());
			BOOST_CHECK(!std::holds_alternative<bool>(v1));
			BOOST_CHECK(!std::holds_alternative<char>(v1));
			BOOST_CHECK(!std::holds_alternative<int>(v1));
			BOOST_CHECK(!std::holds_alternative<double>(v1));
			BOOST_CHECK( std::holds_alternative<std::string>(v1));
			BOOST_CHECK_EQUAL(std::get<4>(v1), s);
			BOOST_CHECK_EQUAL(std::get<std::string>(v1), s);
			break;
		}}
	}
}

BOOST_AUTO_TEST_CASE(variant_9)
{
	std::variant<std::monostate, test_throw_on_copy> v1;

	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<std::monostate>(v1));
	BOOST_CHECK_EQUAL(v1.index(), 0);

	int passed = 0;

	try {
		BOOST_CHECK_EQUAL(passed, 0);
		v1 = test_throw_on_copy{};
		BOOST_CHECK_MESSAGE(false, "Copy should have thrown");
	}
	catch(int) { ++passed; }

	BOOST_CHECK_EQUAL(passed, 1);

	BOOST_CHECK(v1.valueless_by_exception());
	BOOST_CHECK(!std::holds_alternative<std::monostate>(v1));
	BOOST_CHECK(!std::holds_alternative<test_throw_on_copy>(v1));
	BOOST_CHECK_EQUAL(v1.index(), std::variant_npos);
}

BOOST_AUTO_TEST_CASE(variant_10)
{
	std::variant<test_throw_on_copy, int> v1{0};
	std::variant<test_throw_on_copy, int> v2;

	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<int>(v1));
	BOOST_CHECK_EQUAL(v1.index(), 1);
	BOOST_CHECK_EQUAL(v2.index(), 0);

	int passed = 0;

	try {
		BOOST_CHECK_EQUAL(passed, 0);
		v1 = v2;
		BOOST_CHECK_MESSAGE(false, "Copy should have thrown");
	}
	catch(int) { ++passed; }

	BOOST_CHECK_EQUAL(passed, 1);

	BOOST_CHECK( v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK( std::holds_alternative<test_throw_on_copy>(v2));
	BOOST_CHECK(!std::holds_alternative<test_throw_on_copy>(v1));
	BOOST_CHECK(!std::holds_alternative<int>(v1));
	BOOST_CHECK_EQUAL(v1.index(), std::variant_npos);
	BOOST_CHECK_EQUAL(v2.index(), 0);
}

BOOST_AUTO_TEST_CASE(variant_11)
{
	std::variant<test_throw_on_move, int> v1{0};
	std::variant<test_throw_on_move, int> v2;

	BOOST_CHECK(!v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK(std::holds_alternative<int>(v1));
	BOOST_CHECK_EQUAL(v1.index(), 1);
	BOOST_CHECK_EQUAL(v2.index(), 0);

	int passed = 0;

	try {
		BOOST_CHECK_EQUAL(passed, 0);
		v1 = std::move(v2);
		BOOST_CHECK_MESSAGE(false, "Move should have thrown");
	}
	catch(int) { ++passed; }

	BOOST_CHECK_EQUAL(passed, 1);

	BOOST_CHECK( v1.valueless_by_exception());
	BOOST_CHECK(!v2.valueless_by_exception());
	BOOST_CHECK( std::holds_alternative<test_throw_on_move>(v2));
	BOOST_CHECK(!std::holds_alternative<test_throw_on_move>(v1));
	BOOST_CHECK(!std::holds_alternative<int>(v1));
	BOOST_CHECK_EQUAL(v1.index(), std::variant_npos);
	BOOST_CHECK_EQUAL(v2.index(), 0);
}

BOOST_AUTO_TEST_CASE(variant_12)
{
	std::variant<bool, char, int, std::string> v1;

	v1.emplace<std::string>(8, 'X');
	BOOST_CHECK_EQUAL(v1.index(), 3);
	BOOST_CHECK_EQUAL(std::get<3>(v1), "XXXXXXXX");
	BOOST_CHECK_EQUAL(std::get<std::string>(v1), "XXXXXXXX");
}

BOOST_AUTO_TEST_CASE(variant_13)
{
	std::variant<wchar_t, short, std::string, float> v1;

	v1.emplace<2>(4, 'Y');
	BOOST_CHECK_EQUAL(v1.index(), 2);
	BOOST_CHECK_EQUAL(std::get<2>(v1), "YYYY");
	BOOST_CHECK_EQUAL(std::get<std::string>(v1), "YYYY");
}

BOOST_AUTO_TEST_SUITE_END()
