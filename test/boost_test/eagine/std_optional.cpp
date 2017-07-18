/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/std/optional.hpp>
#define BOOST_TEST_MODULE EAGINE_std_optional
#include "../unit_test_begin.inl"

#include <string>
#include <tuple>

BOOST_AUTO_TEST_SUITE(std_optional_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(optional_empty)
{
	const std::optional<std::string> oe1;
	const std::optional<std::string> oe2;
	const std::nullopt_t sno = std::nullopt;

	BOOST_CHECK_EQUAL(oe1.has_value(), false);
	BOOST_CHECK_EQUAL(oe2.has_value(), false);

	BOOST_CHECK_EQUAL(!oe1, true);
	BOOST_CHECK_EQUAL(!oe2, true);

	BOOST_CHECK_EQUAL(bool(oe1), false);
	BOOST_CHECK_EQUAL(bool(oe2), false);

	BOOST_CHECK_EQUAL(oe1 == oe2, true);
	BOOST_CHECK_EQUAL(oe1 != oe2, false);
	BOOST_CHECK_EQUAL(oe1 <  oe2, false);
	BOOST_CHECK_EQUAL(oe1 >  oe2, false);
	BOOST_CHECK_EQUAL(oe1 <= oe2, true);
	BOOST_CHECK_EQUAL(oe1 >= oe2, true);

	BOOST_CHECK_EQUAL(oe1 == sno, true);
	BOOST_CHECK_EQUAL(oe1 != sno, false);
	BOOST_CHECK_EQUAL(oe1 <  sno, false);
	BOOST_CHECK_EQUAL(oe1 >  sno, false);
	BOOST_CHECK_EQUAL(oe1 <= sno, true);
	BOOST_CHECK_EQUAL(oe1 >= sno, true);

	BOOST_CHECK_EQUAL(sno == oe2, true);
	BOOST_CHECK_EQUAL(sno != oe2, false);
	BOOST_CHECK_EQUAL(sno <  oe2, false);
	BOOST_CHECK_EQUAL(sno >  oe2, false);
	BOOST_CHECK_EQUAL(sno <= oe2, true);
	BOOST_CHECK_EQUAL(sno >= oe2, true);
}

BOOST_AUTO_TEST_CASE(optional_cmp_eq)
{
	const std::optional<std::string> o1("optional");
	const std::optional<std::string> o2("optional");
	const std::nullopt_t no = std::nullopt;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(!o1, false);
	BOOST_CHECK_EQUAL(!o2, false);

	BOOST_CHECK_EQUAL(bool(o1), true);
	BOOST_CHECK_EQUAL(bool(o2), true);

	BOOST_CHECK_EQUAL(o1 == o2, true);
	BOOST_CHECK_EQUAL(o1 != o2, false);
	BOOST_CHECK_EQUAL(o1 <  o2, false);
	BOOST_CHECK_EQUAL(o1 >  o2, false);
	BOOST_CHECK_EQUAL(o1 <= o2, true);
	BOOST_CHECK_EQUAL(o1 >= o2, true);

	BOOST_CHECK_EQUAL(o1 == no, false);
	BOOST_CHECK_EQUAL(o1 != no, true);
	BOOST_CHECK_EQUAL(o1 <  no, false);
	BOOST_CHECK_EQUAL(o1 >  no, true);
	BOOST_CHECK_EQUAL(o1 <= no, false);
	BOOST_CHECK_EQUAL(o1 >= no, true);

	BOOST_CHECK_EQUAL(no == o2, false);
	BOOST_CHECK_EQUAL(no != o2, true);
	BOOST_CHECK_EQUAL(no <  o2, true);
	BOOST_CHECK_EQUAL(no >  o2, false);
	BOOST_CHECK_EQUAL(no <= o2, true);
	BOOST_CHECK_EQUAL(no >= o2, false);
}

BOOST_AUTO_TEST_CASE(optional_cmp_1_2)
{
	const std::optional<int> o1{1};
	const std::optional<int> o2{2};
	const std::nullopt_t no = std::nullopt;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(!o1, false);
	BOOST_CHECK_EQUAL(!o2, false);

	BOOST_CHECK_EQUAL(bool(o1), true);
	BOOST_CHECK_EQUAL(bool(o2), true);

	BOOST_CHECK_EQUAL(o1 == o2, false);
	BOOST_CHECK_EQUAL(o1 != o2, true);
	BOOST_CHECK_EQUAL(o1 <  o2, true);
	BOOST_CHECK_EQUAL(o1 >  o2, false);
	BOOST_CHECK_EQUAL(o1 <= o2, true);
	BOOST_CHECK_EQUAL(o1 >= o2, false);

	BOOST_CHECK_EQUAL(o1 == no, false);
	BOOST_CHECK_EQUAL(o1 != no, true);
	BOOST_CHECK_EQUAL(o1 <  no, false);
	BOOST_CHECK_EQUAL(o1 >  no, true);
	BOOST_CHECK_EQUAL(o1 <= no, false);
	BOOST_CHECK_EQUAL(o1 >= no, true);

	BOOST_CHECK_EQUAL(no == o2, false);
	BOOST_CHECK_EQUAL(no != o2, true);
	BOOST_CHECK_EQUAL(no <  o2, true);
	BOOST_CHECK_EQUAL(no >  o2, false);
	BOOST_CHECK_EQUAL(no <= o2, true);
	BOOST_CHECK_EQUAL(no >= o2, false);
}

BOOST_AUTO_TEST_CASE(optional_cmp_4_3)
{
	const std::optional<int> o1(4);
	const std::optional<int> o2(3);
	const std::nullopt_t no = std::nullopt;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(!o1, false);
	BOOST_CHECK_EQUAL(!o2, false);

	BOOST_CHECK_EQUAL(bool(o1), true);
	BOOST_CHECK_EQUAL(bool(o2), true);

	BOOST_CHECK_EQUAL(o1 == o2, false);
	BOOST_CHECK_EQUAL(o1 != o2, true);
	BOOST_CHECK_EQUAL(o1 <  o2, false);
	BOOST_CHECK_EQUAL(o1 >  o2, true);
	BOOST_CHECK_EQUAL(o1 <= o2, false);
	BOOST_CHECK_EQUAL(o1 >= o2, true);

	BOOST_CHECK_EQUAL(o1 == no, false);
	BOOST_CHECK_EQUAL(o1 != no, true);
	BOOST_CHECK_EQUAL(o1 <  no, false);
	BOOST_CHECK_EQUAL(o1 >  no, true);
	BOOST_CHECK_EQUAL(o1 <= no, false);
	BOOST_CHECK_EQUAL(o1 >= no, true);

	BOOST_CHECK_EQUAL(no == o2, false);
	BOOST_CHECK_EQUAL(no != o2, true);
	BOOST_CHECK_EQUAL(no <  o2, true);
	BOOST_CHECK_EQUAL(no >  o2, false);
	BOOST_CHECK_EQUAL(no <= o2, true);
	BOOST_CHECK_EQUAL(no >= o2, false);
}

BOOST_AUTO_TEST_CASE(optional_cmp_1_v)
{
	for(int c=0; c<100; ++c) {
		const int v2 = rg.get_any<int>();
		const std::optional<int> o1;

		BOOST_CHECK_EQUAL(o1 == v2, false);
		BOOST_CHECK_EQUAL(o1 != v2, true);
		BOOST_CHECK_EQUAL(o1 <  v2, true);
		BOOST_CHECK_EQUAL(o1 >  v2, false);
		BOOST_CHECK_EQUAL(o1 <= v2, true);
		BOOST_CHECK_EQUAL(o1 >= v2, false);
	}

	for(int c=0; c<100; ++c) {
		const int v1 = rg.get_any<int>();
		const int v2 = rg.get_any<int>();
		const std::optional<int> o1{v1};

		BOOST_CHECK_EQUAL(o1 == v2, v1 == v2);
		BOOST_CHECK_EQUAL(o1 != v2, v1 != v2);
		BOOST_CHECK_EQUAL(o1 <  v2, v1 <  v2);
		BOOST_CHECK_EQUAL(o1 >  v2, v1 >  v2);
		BOOST_CHECK_EQUAL(o1 <= v2, v1 <= v2);
		BOOST_CHECK_EQUAL(o1 >= v2, v1 >= v2);
	}
}

BOOST_AUTO_TEST_CASE(optional_cmp_v_2)
{
	for(int c=0; c<100; ++c) {
		const int v1 = rg.get_any<int>();
		const std::optional<int> o2;

		BOOST_CHECK_EQUAL(v1 == o2, false);
		BOOST_CHECK_EQUAL(v1 != o2, true);
		BOOST_CHECK_EQUAL(v1 <  o2, false);
		BOOST_CHECK_EQUAL(v1 >  o2, true);
		BOOST_CHECK_EQUAL(v1 <= o2, false);
		BOOST_CHECK_EQUAL(v1 >= o2, true);
	}

	for(int c=0; c<100; ++c) {
		const int v1 = rg.get_any<int>();
		const int v2 = rg.get_any<int>();
		const std::optional<int> o2{v2};

		BOOST_CHECK_EQUAL(v1 == o2, v1 == v2);
		BOOST_CHECK_EQUAL(v1 != o2, v1 != v2);
		BOOST_CHECK_EQUAL(v1 <  o2, v1 <  v2);
		BOOST_CHECK_EQUAL(v1 >  o2, v1 >  v2);
		BOOST_CHECK_EQUAL(v1 <= o2, v1 <= v2);
		BOOST_CHECK_EQUAL(v1 >= o2, v1 >= v2);
	}
}

BOOST_AUTO_TEST_CASE(optional_cmp_1_n)
{
	const std::optional<int> o1{1};
	const std::optional<int> o2;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), false);

	BOOST_CHECK_EQUAL(o1 == o2, false);
	BOOST_CHECK_EQUAL(o1 != o2, true);
	BOOST_CHECK_EQUAL(o1 <  o2, false);
	BOOST_CHECK_EQUAL(o1 >  o2, true);
	BOOST_CHECK_EQUAL(o1 <= o2, false);
	BOOST_CHECK_EQUAL(o1 >= o2, true);
}

BOOST_AUTO_TEST_CASE(optional_cmp_n_2)
{
	const std::optional<int> o1;
	const std::optional<int> o2{2};

	BOOST_CHECK_EQUAL(o1.has_value(), false);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(o1 == o2, false);
	BOOST_CHECK_EQUAL(o1 != o2, true);
	BOOST_CHECK_EQUAL(o1 <  o2, true);
	BOOST_CHECK_EQUAL(o1 >  o2, false);
	BOOST_CHECK_EQUAL(o1 <= o2, true);
	BOOST_CHECK_EQUAL(o1 >= o2, false);
}

BOOST_AUTO_TEST_CASE(optional_copy_1)
{
	const std::optional<int> o1{1};
	const std::optional<int> o2{o1};

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(o1 == o2, true);
}

BOOST_AUTO_TEST_CASE(optional_copy_2)
{
	const std::optional<int> o1{1};
	const std::optional<long> o2{o1};

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(decltype(o2)(o1) == o2, true);
}

BOOST_AUTO_TEST_CASE(optional_copy_assign_1)
{
	const std::optional<int> o1{1};
	std::optional<int> o2;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), false);

	BOOST_CHECK_EQUAL(o1 != o2, true);

	o2 = o1;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(o1 == o2, true);
}

BOOST_AUTO_TEST_CASE(optional_copy_assign_2)
{
	const std::optional<int> o1{1};
	std::optional<long> o2;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), false);

	BOOST_CHECK_EQUAL(decltype(o2)(o1) != o2, true);

	o2 = o1;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(decltype(o2)(o1) == o2, true);
}

BOOST_AUTO_TEST_CASE(optional_move_1)
{
	std::optional<int> o1{1};
	const std::optional<int> o2{std::move(o1)};

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);
}

BOOST_AUTO_TEST_CASE(optional_move_2)
{
	std::optional<int> o1{2};
	const std::optional<long> o2{std::move(o1)};

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);
}

BOOST_AUTO_TEST_CASE(optional_move_assign_1)
{
	std::optional<int> o1{1};
	std::optional<int> o2;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), false);

	BOOST_CHECK_EQUAL(o1 != o2, true);

	o2 = std::move(o1);

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);
}

BOOST_AUTO_TEST_CASE(optional_move_assign_2)
{
	std::optional<int> o1{2};
	std::optional<long> o2;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), false);

	BOOST_CHECK_EQUAL(decltype(o2)(o1) != o2, true);

	o2 = std::move(o1);

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);
}

BOOST_AUTO_TEST_CASE(optional_value_n)
{
	std::optional<std::string> eo{std::nullopt};

	BOOST_CHECK_EQUAL(eo.value_or("empty"), "empty");

	int passed = 0;

	try {
		eo.value();
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	} 
	catch(std::bad_optional_access&) {
		++passed;
	}
	BOOST_CHECK_EQUAL(passed, 1);

	try {
		*eo;
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	} 
	catch(std::bad_optional_access&) {
		++passed;
	}
	BOOST_CHECK_EQUAL(passed, 2);

	try {
		eo->size();
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	} 
	catch(std::bad_optional_access&) {
		++passed;
	}
	BOOST_CHECK_EQUAL(passed, 3);
}

BOOST_AUTO_TEST_CASE(optional_value_s)
{
	std::optional<std::string> eo{"optional"};

	BOOST_CHECK_EQUAL(eo.value_or("empty"), "optional");

	int passed = 0;

	try {
		BOOST_CHECK_EQUAL(eo.value(), "optional");
		++passed;
	} 
	catch(std::bad_optional_access&) {
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	BOOST_CHECK_EQUAL(passed, 1);

	try {
		BOOST_CHECK_EQUAL(*eo, "optional");
		++passed;
	} 
	catch(std::bad_optional_access&) {
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	BOOST_CHECK_EQUAL(passed, 2);

	try {
		BOOST_CHECK_EQUAL(eo->size(), 8);
		++passed;
	} 
	catch(std::bad_optional_access&) {
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	BOOST_CHECK_EQUAL(passed, 3);
}

BOOST_AUTO_TEST_CASE(optional_construct_exp_conv)
{
	auto f = []()-> std::optional<double> { return {1}; };
	std::optional<double> od = f();
	BOOST_CHECK(od.has_value());
}

BOOST_AUTO_TEST_CASE(optional_make_1)
{
	std::optional<int> o1 = std::make_optional(1);
	BOOST_CHECK_EQUAL(o1.value_or(-1), 1);

	std::optional<std::tuple<bool, char, int>> o2
		= std::make_optional<std::tuple<bool, char, int>>(true,'2',345);
	try {
		BOOST_CHECK_EQUAL(std::get<0>(o2.value()), true);
		BOOST_CHECK_EQUAL(std::get<1>(o2.value()), '2');
		BOOST_CHECK_EQUAL(std::get<2>(o2.value()), 345);
	} catch(...) {
		BOOST_CHECK_MESSAGE(false, "Should not throw");
	}
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
