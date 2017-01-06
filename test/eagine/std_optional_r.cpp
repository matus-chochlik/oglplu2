/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_std_optional
#include <boost/test/unit_test.hpp>

#include <eagine/std/optional.hpp>
#include <string>

BOOST_AUTO_TEST_SUITE(std_optional_tests)

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

	BOOST_CHECK_EQUAL(o1 == o2, true);
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

	BOOST_CHECK_EQUAL(o1 != o2, true);

	o2 = o1;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(o1 == o2, true);
}

BOOST_AUTO_TEST_CASE(optional_move_1)
{
	std::optional<int> o1{1};
	const std::optional<int> o2{std::move(o1)};

	BOOST_CHECK_EQUAL(o1.has_value(), false);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(o1 == o2, false);
}

BOOST_AUTO_TEST_CASE(optional_move_2)
{
	std::optional<int> o1{2};
	const std::optional<long> o2{std::move(o1)};

	BOOST_CHECK_EQUAL(o1.has_value(), false);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(o1 == o2, false);
}

BOOST_AUTO_TEST_CASE(optional_move_assign_1)
{
	std::optional<int> o1{1};
	std::optional<int> o2;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), false);

	BOOST_CHECK_EQUAL(o1 != o2, true);

	o2 = std::move(o1);

	BOOST_CHECK_EQUAL(o1.has_value(), false);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(o1 == o2, false);
}

BOOST_AUTO_TEST_CASE(optional_move_assign_2)
{
	std::optional<int> o1{2};
	std::optional<long> o2;

	BOOST_CHECK_EQUAL(o1.has_value(), true);
	BOOST_CHECK_EQUAL(o2.has_value(), false);

	BOOST_CHECK_EQUAL(o1 != o2, true);

	o2 = std::move(o1);

	BOOST_CHECK_EQUAL(o1.has_value(), false);
	BOOST_CHECK_EQUAL(o2.has_value(), true);

	BOOST_CHECK_EQUAL(o1 == o2, false);
}

BOOST_AUTO_TEST_SUITE_END()
